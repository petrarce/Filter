#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QString>
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

		QGraphicsRectItem *rectangle;
		QGraphicsEllipseItem *elips;
		QGraphicsPixmapItem *pixmapItemn;
	protected:
		void resizeEvent(QResizeEvent *event);
		void dragEnterEvent(QDragEnterEvent * event);
		void dragLeaveEvent(QDragLeaveEvent * event);
		void dragMoveEvent(QDragMoveEvent * event);
		void dropEvent(QDropEvent * event);
};



#endif // MAINWINDOW_H