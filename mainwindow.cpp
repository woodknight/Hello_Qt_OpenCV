#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputPushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Input Image",
                                                    QDir::currentPath(),
                                                    "*.png;;*.jpg;;*.bmp");
    if(QFile::exists(fileName))
    {
        ui->inputLineEdit->setText(fileName);
    }
}

void MainWindow::on_outputPushButton_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Select Output Image",
                                                    QDir::currentPath(),
                                                    "*.png;;*.jpg;;*.bmp");
    if(!fileName.isEmpty())
    {
        ui->outputLineEdit->setText(fileName);

        using namespace cv;
        Mat inImg, outImg;
        inImg = imread(ui->inputLineEdit->text().toStdString());

        if(ui->medianBlurRadioButton->isChecked())
            medianBlur(inImg, outImg, 5);
        else if(ui->gaussianBlurRadioButton->isChecked())
            GaussianBlur(inImg, outImg, Size(5,5), 1.25);

        imwrite(fileName.toStdString(), outImg);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this,
                                      "Exit",
                                      "Are you sure you want to close this program?",
                                      QMessageBox::Yes,
                                      QMessageBox::No);
    if(result == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}
