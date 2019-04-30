#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include <QMainWindow>

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


<<<<<<< HEAD
    
=======
>>>>>>> dc6af5140278b3845673859c111ce1f0c80666a2
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

//test
