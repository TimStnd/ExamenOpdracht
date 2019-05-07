#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <QMainWindow>
#include "ellipseimage.h"


#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>


#include <QImage>
#include <QImageReader>

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"




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

    void on_actionSave_Gray_As_triggered();

    void on_actionSave_Compound_As_triggered();

    void on_test_clicked();

    void on_clear_clicked();


private:


    void InitialProcessing();
    Ui::MainWindow *ui;
    std::string currentFile;
    cv::Mat ImageMat;
    cv::Mat DataMat;
    cv::Mat Compound;
    int amountellipse;

};

#endif // MAINWINDOW_H

//test
