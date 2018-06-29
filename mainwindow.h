#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>

#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_inputPushButton_clicked();

    void on_outputPushButton_pressed();

private:
    Ui::MainWindow *ui;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
