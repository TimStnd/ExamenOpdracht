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
    imageellipse.ClearImage();
    imageellipse.ClearColourImage();
    amountellipse=0;


    // get and initialize the variables from the ui
    int centerx1=ui->centerx1->value();
    int centery1=ui->centery1->value();
    int aaxis1=ui->aaxis1->value();
    int baxis1=ui->baxis1->value();
    double angle1=ui->angle1->value();
    int amount1=ui->amount1->value();
    std::cout << amount1 << std::endl;

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

        imageellipse.DrawEllipse(centerx1,centery1,aaxis1,baxis1,angle1,amount1, outpoints);
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


    ImageMat=imageellipse.GetColourImage();
    DataMat=imageellipse.GetImage();



    //check if ellipses were dran if not give error message
    if(amountellipse==0)
    {
        ui->logbox->append("No ellipses were drawn, check if the axes and amount of points are greater than zero");
    }





    cv::Mat img=ImageMat;
    ui->picture->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}




void MainWindow::on_clear_clicked()
{
    ui->logbox->setText("");
}


void MainWindow::on_pushButton_clicked()
{
    ui->resultsbox->setText("");
    ui->resultsbox->append("found ellipses | center x | center y | a-axis | b-axis | angle (rad)");
    std::vector<float> data;
    int threshold =ui->thresholdopencv->value();
    opencvfinder test(DataMat);
    data=test.getelips(threshold);

    for(size_t j=0; j<data.size()/5; j++)
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


void MainWindow::on_drawrandom_clicked()
{

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

    if (currentFile != "NotAFile" ){
        cv::imwrite(currentFile, ImageMat);
    }
    else {

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
    Finder.newImage(DataMat);
    double minA, minB, AccThresh;


    if (ui->MinA->value() > 128){
        ui->logbox->append("The maximum value of min half A cannot be larger than 128");
        minA = 120;
    }
    else {
        minA = ui->MinA->value();
    }

    if (ui->MinB->value() > 128) {
        ui->logbox->append("The maximum value of min half B cannot be larger than 128");
        minB = 120;
    }
    else {
        minB = ui->MinB->value();
    }

    if (minA < minB){
        ui->logbox->append("A should be larger than B. Since the minimums are switched, they will be switched again");

        minA += minB;
        minB = minA - minB;
        minA -= minB;

    }

    if (ui->AccThresh->value() == 0){
        ui->logbox->append("Accumulator Threshold must be a strictly positive number. Defaulting to 100.");
        AccThresh = 150;
    }
    else {
        AccThresh = ui->AccThresh->value();
    }

    //Ellipsfinder Finder.get(DataMat, minA, maxA, AccThresh);

    std::vector<cv::Point> Centers; std::vector<unsigned> HMA; std::vector<unsigned> HMI; std::vector<double> orientation;

    Finder.getEllipses(Centers, HMA, HMI, orientation, minA, minB, AccThresh);



    imageellipse.ReadImage(ImageMat);

    for (size_t counter = 0; counter < Centers.size(); ++counter){

        imageellipse.DrawColouredEllipse(Centers.at(counter).x, 256 - Centers.at(counter).y, HMA.at(counter), HMI.at(counter), orientation.at(counter));

    }


    ui->picture->setPixmap(QPixmap::fromImage(QImage(ImageMat.data, ImageMat.cols, ImageMat.rows, ImageMat.step, QImage::Format_RGB888)));

}




