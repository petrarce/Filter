#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//------------------------QT includes
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QString>
//------------------------NeuralNet includes
#include "MyOwnFramework/BackPropagation-master/src/Backpropagation.h"
#include <vector>
struct sRGBrepr
{
    short *Red;
    short *Green;
    short *Blue;
};

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		Ui::MainWindow *ui;

        //first and second images
        QImage firstImage;
        QImage secondImage;
        QImage resultImage;
        //rgb representations of images
        sRGBrepr *firstImageRGB;
        sRGBrepr *secondImageRGB;
        sRGBrepr *resultImageRGB;

        double *inputData;
        double *outputData;

        Backpropagation *MyNet;
        const vector<int> netDiscription={5,3};


        void getRGBrepresentation(sRGBrepr *RGBrepr,QImage *image);

	protected:
		void resizeEvent(QResizeEvent *event);
		void dragEnterEvent(QDragEnterEvent * event);
		void dragLeaveEvent(QDragLeaveEvent * event);
		void dragMoveEvent(QDragMoveEvent * event);
		void dropEvent(QDropEvent * event);
    private slots:
        void reciveFirstImage(QImage image);
        void reciveSecondImage(QImage image);
        void on_buttonTrain_clicked();
};



#endif // MAINWINDOW_H
