#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		explicit MainWindow(QMainWindow *parent = 0);
};

#endif // MAINWINDOW_H
