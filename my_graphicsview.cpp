#include "my_graphicsview.h"

my_GraphicsView::my_GraphicsView(QWidget *parent)
	:QGraphicsView(parent)
{
	scene=new QGraphicsScene();
	pixmap=new QPixmap();

	this->setScene(scene);
}
void my_GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
	event->accept();
	qDebug()<<"my_graphicsview dragMoveEvent";
}
void my_GraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
	event->accept();
	qDebug()<<"my_graphicsview dragLeaveEvent";
}
void my_GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
	event->accept();
	qDebug()<<"my_graphicsview dragEnterEvent";

}
void my_GraphicsView::dropEvent(QDropEvent *event)
{
	//event->accept();
	if (event->mimeData()->hasUrls())
	{
		foreach (QUrl url, event->mimeData()->urls())
		{
			qDebug()<<pixmap->load(url.path());
			qDebug()<<url.path();
			scene->addPixmap(*pixmap);
            emit transmitImage(pixmap->toImage());
		}
	}
	qDebug()<<"my_graphicsview dropEvent";
}
