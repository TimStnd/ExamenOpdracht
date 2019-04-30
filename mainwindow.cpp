#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->picture->setFixedWidth(256);
    ui->picture->setFixedWidth(256);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawbutton_clicked()
{
    // get and initialize the variables from the ui

    int centerx1=ui->centerx1->value();
    int centery1=ui->centery1->value();
    int aaxis1=ui->aaxis1->value();
    int baxis1=ui->baxis1->value();
    double angle1=ui->angle1->value();
    int amount1=ui->amount1->value();

    int centerx2=ui->centerx2->value();
    int centery2=ui->centery2->value();
    int aaxis2=ui->aaxis2->value();
    int baxis2=ui->baxis2->value();
    double angle2=ui->angle2->value();
    int amount2=ui->amount2->value();

    int centerx3=ui->centerx3->value();
    int centery3=ui->centery3->value();
    int aaxis3=ui->aaxis3->value();
    int baxis3=ui->baxis3->value();
    double angle3=ui->angle3->value();
    int amount3=ui->amount3->value();

    int centerx4=ui->centerx4->value();
    int centery4=ui->centery4->value();
    int aaxis4=ui->aaxis4->value();
    int baxis4=ui->baxis4->value();
    double angle4=ui->angle4->value();
    int amount4=ui->amount4->value();

    int centerx5=ui->centerx5->value();
    int centery5=ui->centery5->value();
    int aaxis5=ui->aaxis5->value();
    int baxis5=ui->baxis5->value();
    double angle5=ui->angle5->value();
    int amount5=ui->amount5->value();

    int centerx6=ui->centerx6->value();
    int centery6=ui->centery6->value();
    int aaxis6=ui->aaxis6->value();
    int baxis6=ui->baxis6->value();
    double angle6=ui->angle6->value();
    int amount6=ui->amount6->value();

    if(aaxis1>0 && baxis1>0 && amount1>0)
    {

    }

    if(aaxis2>0 && baxis2>0 && amount2>0)
    {

    }

    if(aaxis3>0 && baxis3>0 && amount3>0)
    {

    }

    if(aaxis4>0 && baxis4>0 && amount4>0)
    {

    }

    if(aaxis5>0 && baxis5>0 && amount5>0)
    {

    }

    if(aaxis6>0 && baxis6>0 && amount6>0)
    {

    }

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
