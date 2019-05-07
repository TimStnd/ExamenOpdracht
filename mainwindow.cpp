#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>

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

//Test

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

    if(aaxis1>0 && baxis1>0 && amount1>0)
    {
        imageellipse.DrawEllipse(centerx1,centery1,aaxis1,baxis1,angle1,amount1,outpoints);
        amountellipse++;
    } else if(aaxis1==0 && baxis1==0 && amount1==0){

    }else{
        ui->logbox->append("Ellipse 1: the axes and amount of points must be greater than zero");
    }

    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 1: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }

    if(aaxis2>0 && baxis2>0 && amount2>0)
    {
        imageellipse.DrawEllipse(centerx2,centery2,aaxis2,baxis2,angle2,amount2,outpoints);
        amountellipse++;
    } else if(aaxis2==0 && baxis2==0 && amount2==0){

    }else{
        ui->logbox->append("Ellipse 2: the axes and amount of points must be greater than zero");
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


    if(outpoints>0)
    {
        std::string outpointsstring= std::to_string(outpoints);
        std::string logstring="Ellipse 6: "+outpointsstring+" points lay outside of the window";
        QString qstr = QString::fromStdString(logstring);
        ui->logbox->append(qstr);
        outpoints=0;
    }

    ImageMat=imageellipse.GetColourImage();
    DataMat=imageellipse.GetImage();

    if(amountellipse==0)
    {
        ui->logbox->append("No ellipses were drawn, check if the axes and amount of points are greater than zero");
    }

    //std::cout<<*outpoints<<std::endl;

    cv::Mat img=ImageMat;
    ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}


void MainWindow::on_test_clicked()
{
    ui->logbox->append("test");
}

void MainWindow::on_clear_clicked()
{
    ui->logbox->setText("");
}


void MainWindow::InitialProcessing(){


    const int thresh = 100;
    cv::resize(ImageMat, ImageMat, cv::Size(256, 256));
    cv::cvtColor(ImageMat, DataMat, CV_BGR2GRAY);
    cv::blur(DataMat, DataMat, cv::Size(3,3));

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::Canny(DataMat, DataMat, thresh, thresh*2, 3);
}


void MainWindow::on_actionOpen_triggered()
{

    //Nog het edge detection en blurring doen
    //Functie nog lichtjes opkuisen, er kunnen nog wat variabelen weggelaten worden denk ik

    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");



    std::string fileNameString = fileName.toStdString();
    ImageMat = cv::imread(fileNameString);
    cv::cvtColor(ImageMat, ImageMat, CV_RGB2BGR);
    if (! ImageMat.empty()){


        InitialProcessing();

        currentFile = fileNameString;

        const unsigned startDelimiter = fileNameString.find_last_of("/");
        const unsigned stopDelimiter = fileNameString.find_last_of(".");

        std::string NameString = fileNameString.substr(startDelimiter + 1, stopDelimiter - startDelimiter - 1);

        setWindowTitle(QString::fromStdString(NameString));

        cv::Mat img=ImageMat;
        ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
    }
    else {
        std::cerr << "This image format is not supported." << std::endl;
    }


}

void MainWindow::on_actionSave_as_triggered()
{
    //Nog een default naam instellen voor de saveas dialoog
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    std::string fileNameString = fileName.toStdString();
    std::string extension = fileNameString.substr(fileNameString.find_last_of(".") + 1);
    std::vector<std::string> ExtensionList = {"bmp", "dib", "jpeg", "jpg", "jpe", "jp2", "png", "pbm", "pgm", "ppm", "sr", "ras", "tiff", "tif"};

    if (fileNameString.find(".") == std::string::npos){
        std::cout << "Standard image format is .png" << std::endl;
        cv::imwrite(fileNameString + ".png", ImageMat);
    }

    else if (std::find (ExtensionList.begin(), ExtensionList.end(), extension) != ExtensionList.end()){

        cv::imwrite(fileNameString, ImageMat);
    }

    else {
        std::cout << "This Extension is not supported" << std::endl;
    }






}

void MainWindow::on_actionSave_triggered()
{

    cv::imwrite(currentFile, ImageMat);
}

void MainWindow::on_actionSave_Gray_As_triggered()
{


    //Nog een default naam instellen voor de saveas dialoog
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    std::string fileNameString = fileName.toStdString();
    std::string extension = fileNameString.substr(fileNameString.find_last_of(".") + 1);
    std::vector<std::string> ExtensionList = {"bmp", "dib", "jpeg", "jpg", "jpe", "jp2", "png", "pbm", "pgm", "ppm", "sr", "ras", "tiff", "tif"};



    if (fileNameString.find(".") == std::string::npos){
        std::cout << "Standard image format is .png" << std::endl;
        cv::imwrite(fileNameString + ".png", DataMat);
    }

    else if (std::find (ExtensionList.begin(), ExtensionList.end(), extension) != ExtensionList.end()){


        cv::imwrite(fileNameString, DataMat);
    }

    else {
        std::cout << "This Extension is not supported" << std::endl;
    }



}

void MainWindow::on_actionSave_Compound_As_triggered()
{
    cv::Mat DataColor;
    cv::cvtColor(DataMat, DataColor, CV_GRAY2BGR);
    Compound = ImageMat + DataColor;


    //Nog een default naam instellen voor de saveas dialoog
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    std::string fileNameString = fileName.toStdString();
    std::string extension = fileNameString.substr(fileNameString.find_last_of(".") + 1);
    std::vector<std::string> ExtensionList = {"bmp", "dib", "jpeg", "jpg", "jpe", "jp2", "png", "pbm", "pgm", "ppm", "sr", "ras", "tiff", "tif"};


    if (fileNameString.find(".") == std::string::npos){
        std::cout << "Standard image format is .png" << std::endl;
        cv::imwrite(fileNameString + ".png", Compound);
    }

    else if (std::find (ExtensionList.begin(), ExtensionList.end(), extension) != ExtensionList.end()){


        cv::imwrite(fileNameString, Compound);
    }

    else {
        std::cout << "This Extension is not supported" << std::endl;
    }

}






void MainWindow::on_OwnAlgorithm_clicked()
{
    //Maak van de variabelen nog veranderlijk via QT
    Ellipsfinder Finder(DataMat, 50, 30, 100);

    std::vector<cv::Point> Centers; std::vector<unsigned> HMA; std::vector<unsigned> HMI; std::vector<double> orientation;

    Finder.getEllipses(Centers, HMA, HMI, orientation);

    if (Centers.size() >= 1){

        ui->centerx1_2->setValue((Centers.at(0)).x);
        ui->centery1_2->setValue((Centers.at(0)).y);
        ui->aaxis1_2->setValue(HMA.at(0));
        ui->baxis1_2->setValue(HMI.at(0));
        ui->angle1_2->setValue(orientation.at(0));
    }

    if (Centers.size() >= 2){

        ui->centerx2_2->setValue((Centers.at(1)).x);
        ui->centery2_2->setValue((Centers.at(1)).y);
        ui->aaxis2_2->setValue(HMA.at(1));
        ui->baxis2_2->setValue(HMI.at(1));
        ui->angle2_2->setValue(orientation.at(1));
    }


}
