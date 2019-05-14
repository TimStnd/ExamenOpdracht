#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>
#include "opencvfinder.h"

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
    ui->logbox->setText("");
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

    int outpoints=0;


    //check if there are values added to draw the ellipse and then draw the ellipse
    if(aaxis1>0 && baxis1>0 && amount1>0)
    {
        imageellipse.DrawEllipse(centerx1,centery1,aaxis1,baxis1,angle1,amount1,outpoints);
        amountellipse++;
    } else if(aaxis1==0 && baxis1==0 && amount1==0){

    }else{
        //if they give one value but not the others give a error message
        ui->logbox->append("Ellipse 1: the axes and amount of points must be greater than zero");
    }

    //check if the a-axis is greater then the b-axis if otherwise give an error message
    if(baxis1>aaxis1)
    {
        ui->logbox->append("Ellipse 1: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    //if the ellipse is drawn for a part outside the window give an errormessage
    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 1: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }


    //do the same for the other ellipses
    if(aaxis2>0 && baxis2>0 && amount2>0)
    {
        imageellipse.DrawEllipse(centerx2,centery2,aaxis2,baxis2,angle2,amount2,outpoints);
        amountellipse++;
    } else if(aaxis2==0 && baxis2==0 && amount2==0){

    }else{
        ui->logbox->append("Ellipse 2: the axes and amount of points must be greater than zero");
    }

    if(baxis2>aaxis2)
    {
        ui->logbox->append("Ellipse 2: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 2: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }

    if(aaxis3>0 && baxis3>0 && amount3>0)
    {
        imageellipse.DrawEllipse(centerx3,centery3,aaxis3,baxis3,angle3,amount3,outpoints);
        amountellipse++;
    } else if(aaxis3==0 && baxis3==0 && amount3==0){

    }else{
        ui->logbox->append("Ellipse 3: the axes and amount of points must be greater than zero");
    }

    if(baxis3>aaxis3)
    {
        ui->logbox->append("Ellipse 3: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 3: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }

    if(aaxis4>0 && baxis4>0 && amount4>0)
    {
        imageellipse.DrawEllipse(centerx4,centery4,aaxis4,baxis4,angle4,amount4,outpoints);
        amountellipse++;
    } else if(aaxis4==0 && baxis4==0 && amount4==0){

    }else{
        ui->logbox->append("Ellipse 4: the axes and amount of points must be greater than zero");
    }

    if(baxis4>aaxis4)
    {
        ui->logbox->append("Ellipse 4: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 4: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }

    if(aaxis5>0 && baxis5>0 && amount5>0)
    {
        imageellipse.DrawEllipse(centerx5,centery5,aaxis5,baxis5,angle5,amount5,outpoints);
        amountellipse++;
    } else if(aaxis5==0 && baxis5==0 && amount5==0){

    }else{
        ui->logbox->append("Ellipse 5: the axes and amount of points must be greater than zero");
    }


    if(baxis5>aaxis5)
    {
        ui->logbox->append("Ellipse 5: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 5: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }


    if(aaxis6>0 && baxis6>0 && amount6>0)
    {
        imageellipse.DrawEllipse(centerx6,centery6,aaxis6,baxis6,angle6,amount6,outpoints);
        amountellipse++;
    } else if(aaxis6==0 && baxis6==0 && amount6==0){

    }else{
        ui->logbox->append("Ellipse 6: the axes and amount of points must be greater than zero");
    }


    if(baxis6>aaxis6)
    {
        ui->logbox->append("Ellipse 6: the a-axis is smaller then the b-axis, so the found axes and angle will differ from the inputed axes and angle ");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 6: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }



    //check if ellipses were dran if not give error message
    if(amountellipse==0)
    {
        ui->logbox->append("No ellipses were drawn, check if the axes and amount of points are greater than zero");
    }



    //get the image with the drawn images and draw it
    ImageMat=imageellipse.GetImage();

    cv::Mat img=ImageMat;
    cv::cvtColor(img, img, cv::COLOR_GRAY2BGR);
    ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}


void MainWindow::on_test_clicked()
{
    //ui->resultsboxangle->append("test");
    //ui->resultsboxcenterx->append("test");
}

void MainWindow::on_clear_clicked()
{
    ui->logbox->setText("");
}

void MainWindow::on_pushButton_clicked()
{

    ui->resultsbox->append("found ellipses | center x | center y | a-axis | b-axis | angle (rad)");
    std::vector<float> data;
    int threshold =ui->thresholdopencv->value();
    opencvfinder test(ImageMat);
    data=test.getelips(threshold);

    for(int j=0; j<data.size()/5; j++)
    {
        std::string numberstring= std::to_string(j+1);
        std::string centerxstring= std::to_string(data[0+j*5]);
        std::string centerystring= std::to_string(data[1+j*5]);
        std::string aaxisstring= std::to_string(data[2+j*5]);
        std::string baxisstring= std::to_string(data[3+j*5]);
        std::string anglestring= std::to_string(data[4+j*5]);

        std::string logstring=numberstring+" | "+centerxstring+" | "+centerystring+" | "+aaxisstring+" | "+baxisstring+" | "+anglestring;
        QString qstr = QString::fromStdString(logstring);
        ui->resultsbox->append(qstr);
    }
}
