#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include <QColor>
#include "circular_progress.h"
#include "ui_typewriter.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QMainWindow *parent = 0);

	private:
		Ui_MainWindow *mainWindow= new Ui_MainWindow();
		QFrame *frame			= new QFrame();
		QVBoxLayout *layout 	= new QVBoxLayout();
		CircularProgress *prog	= new CircularProgress(); 
		QSlider *slider			= new QSlider(Qt::Horizontal);
};

#endif // MAINWINDOW_H
