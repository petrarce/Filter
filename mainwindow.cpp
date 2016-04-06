#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//ui->graphicsView->setDragMode(Qt::AA_AttributeCount);
	QBrush redBrush(Qt::red);
	QBrush blueBrush(Qt::blue);
	QPen blackDotDotPen(Qt::DashDotDotLine);
	blackDotDotPen.setColor(Qt::black);
	QPen yellowDashPen(Qt::DashLine);
	yellowDashPen.setColor(Qt::yellow);
	yellowDashPen.setWidth(3);

	elips = ui->graphicsView->scene->addEllipse(50,50,100,30,yellowDashPen,blueBrush);
	rectangle= ui->graphicsView->scene->addRect(20,20,50,40,blackDotDotPen,redBrush);
	elips->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
	rectangle->setFlags(QGraphicsItem::ItemIsMovable);
	this->setAcceptDrops(true);
	ui->graphicsView->setAcceptDrops(true);
	//ui->actionOpen_NN;

}

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

MainWindow::~MainWindow()
{
	delete ui;
}
