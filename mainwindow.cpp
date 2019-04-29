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




void MainWindow::on_actionOpen_triggered()
{


    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    std::string tempstring = fileName.toStdString();
    //Finding only name of image
    unsigned startDelimiter = tempstring.find_last_of("/");
    unsigned stopDelimiter = tempstring.find_last_of(".");
    //QString::fromStdString(tempstring.substr(startDelimiter, stopDelimiter-startDelimiter));  //Only keeps name of image, not path

        //Loading image into QImage format
        QImage image(fileName);
        currentFile = fileName;
        //Changing window title to name of Image
        setWindowTitle(QString::fromStdString(tempstring.substr(startDelimiter + 1 , stopDelimiter-startDelimiter - 1)));
        //Saving QImage as temporary .png image
        image.save("Temp.png", "PNG");
        //Opening temporary image as a opencv Mat object
        ImageMat = cv::imread("Temp.png");
        //removing temporary image
        std::remove("Temp.png");

}

void MainWindow::on_actionSave_triggered()
{



}

void MainWindow::on_actionSave_as_triggered()
{




    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    //Saving OpenCV Mat object as temporary .png image
    cv::imwrite("Temp.png", ImageMat);

    //Getting only name instead of path
    std::string tempstring = fileName.toStdString();
    unsigned startDelimiter = tempstring.find_last_of("/");
    unsigned stopDelimiter = tempstring.find_last_of(".");
    setWindowTitle(QString::fromStdString(tempstring.substr(startDelimiter + 1 , stopDelimiter-startDelimiter - 1)));

        currentFile = fileName;


        QImage Image("Temp.png");

        //Getting the requested Extension
        std::string temp = fileName.toStdString();
        std::string extString = temp.substr(temp.find_last_of(".") + 1);

        //Saving the image to its requested name
        Image.save(fileName, extString.c_str());


        //Removing temporary image
        std::remove("Temp.png");


}
