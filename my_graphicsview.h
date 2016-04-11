#ifndef MY_GRAPHICSVIEW_H
#define MY_GRAPHICSVIEW_H
#include <QGraphicsView>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QString>

class my_GraphicsView : public QGraphicsView
{
    Q_OBJECT
	public:

		my_GraphicsView(QWidget *parent);
	public :
		QGraphicsScene *scene;
		QPixmap *pixmap;
	protected:
		void dragMoveEvent(QDragMoveEvent *event);
		void dragLeaveEvent(QDragLeaveEvent *event);
		void dragEnterEvent(QDragEnterEvent *event);
		void dropEvent(QDropEvent *event);
    signals:
        void transmitImage(QImage image);

};

#endif // MY_GRAPHICSVIEW_H
