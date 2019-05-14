#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include <QMainWindow>
#include "ellipseimage.h"

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


    void on_test_clicked();

    void on_clear_clicked();

    void on_pushButton_clicked();

    void on_drawrandom_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat ImageMat;
    int amountellipse;
    EllipseImage imageellipse;
};

#endif // MAINWINDOW_H

//test
