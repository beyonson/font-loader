#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include "circular_progress.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		explicit MainWindow(QMainWindow *parent = 0);
	private:
		QFrame *container	= new QFrame();
		QVBoxLayout *layout 	= new QVBoxLayout();
		CircularProgress *prog	= new CircularProgress(); 
};

#endif // MAINWINDOW_H
