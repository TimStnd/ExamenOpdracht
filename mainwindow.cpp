#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), ImageMat(256, 256, CV_8UC1, cv::Scalar(0)), amountellipse(0)
{
    ui->setupUi(this);

    ui->picture->setFixedWidth(256);
    ui->picture->setFixedWidth(256);

    cv::Mat img=ImageMat;
    cv::cvtColor(img, img, cv::COLOR_GRAY2BGR);
    ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_drawbutton_clicked()
{
    EllipseImage imageellipse(256,256);
    amountellipse=0;
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
        imageellipse.DrawEllipse(centerx1,centery1,aaxis1,baxis1,angle1,amount1);
        amountellipse++;
    }

    if(aaxis2>0 && baxis2>0 && amount2>0)
    {
        imageellipse.DrawEllipse(centerx2,centery2,aaxis2,baxis2,angle2,amount2);
        amountellipse++;
    }

    if(aaxis3>0 && baxis3>0 && amount3>0)
    {
        imageellipse.DrawEllipse(centerx3,centery3,aaxis3,baxis3,angle3,amount3);
        amountellipse++;
    }

    if(aaxis4>0 && baxis4>0 && amount4>0)
    {
        imageellipse.DrawEllipse(centerx4,centery4,aaxis4,baxis4,angle4,amount4);
        amountellipse++;
    }

    if(aaxis5>0 && baxis5>0 && amount5>0)
    {
        imageellipse.DrawEllipse(centerx5,centery5,aaxis5,baxis5,angle5,amount5);
        amountellipse++;
    }

    if(aaxis6>0 && baxis6>0 && amount6>0)
    {
        imageellipse.DrawEllipse(centerx6,centery6,aaxis6,baxis6,angle6,amount6);
        amountellipse++;
    }

    ImageMat=imageellipse.GetImage();

    if(amountellipse==0)
    {
        ui->errorbox->setText("No ellipse was drawn check if the axes and amount of points are greater than zero");
    }

    cv::Mat img=ImageMat;
    cv::cvtColor(img, img, cv::COLOR_GRAY2BGR);
    ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

