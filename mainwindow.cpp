#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    //connect signals and slots
    this->connect(ui->graphicsView,SIGNAL(transmitImage(QImage)),this,SLOT(reciveFirstImage(QImage)));
    this->connect(ui->graphicsView_2,SIGNAL(transmitImage(QImage)),this,SLOT(reciveSecondImage(QImage)));

    //
    firstImageRGB=new sRGBrepr;
    firstImageRGB->Red=NULL;
    firstImageRGB->Green=NULL;
    firstImageRGB->Blue=NULL;

    secondImageRGB=new sRGBrepr;
    secondImageRGB->Red=NULL;
    secondImageRGB->Green=NULL;
    secondImageRGB->Blue=NULL;

    resultImageRGB=new sRGBrepr;
    resultImageRGB->Red=NULL;
    resultImageRGB->Green=NULL;
    resultImageRGB->Blue=NULL;

}
//--------------------event definition
void MainWindow::resizeEvent(QResizeEvent *event)
{
	qDebug()<<"resize event generated";
}
void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
	event->accept();
	qDebug()<<"dragMoveEvent";
}
void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
	event->accept();
	qDebug()<<"dragLeaveEvent";
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
	event->accept();
	qDebug()<<"dragEnterEvent";
}
void MainWindow::dropEvent(QDropEvent *event)
{
	qDebug()<<"dropEvent";
}
//-----------------------functions definition
void MainWindow::getRGBrepresentation(sRGBrepr *RGBrepr, QImage *image)
{
    QColor tempColor;

    //delete RGBrepresentations
    if(RGBrepr->Blue!=NULL){
        delete RGBrepr->Blue;
        qDebug()<<"delete rgbBLUE";
    }
    if(RGBrepr->Green!=NULL)
        delete RGBrepr->Green;
    if(RGBrepr->Red!=NULL)
        delete RGBrepr->Red;


    RGBrepr->Blue=new short[image->width()*image->height()];
    RGBrepr->Green=new short[image->width()*image->height()];
    RGBrepr->Red=new short[image->width()*image->height()];

    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            tempColor=image->pixel(i,j);
            RGBrepr->Red[i*image->width()+j]=tempColor.red();
            RGBrepr->Green[i*image->width()+j]=tempColor.green();
            RGBrepr->Blue[i*image->width()+j]=tempColor.blue();
        }
    }
}

//-----------------------slots definition
void MainWindow::reciveFirstImage(QImage image)
{
    this->firstImage=image;
}
void MainWindow::reciveSecondImage(QImage image)
{
    this->secondImage=image;
}
void MainWindow::on_buttonTrain_clicked()
{
    getRGBrepresentation(firstImageRGB,&firstImage);
    getRGBrepresentation(secondImageRGB,&secondImage);
    //getRGBrepresentation(resultImageRGB,&resultImage);
}


MainWindow::~MainWindow()
{
	delete ui;


}

