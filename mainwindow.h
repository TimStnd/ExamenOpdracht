#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include <stdio.h>
#include <string>
#include <QMainWindow>


#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>


#include <QImage>
#include <QImageReader>

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
    void on_drawbutton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    std::string currentFile;
    cv::Mat ImageMat;
    cv::Mat DataMat;
};

#endif // MAINWINDOW_H

//test
