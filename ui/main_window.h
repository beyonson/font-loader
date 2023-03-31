#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// THIS IS SO NECESSARY ITS NOT EVEN FUNNY
#define QT_NO_OPENGL

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include <QColor>
#include "ui_typewriter.h"
#include "ui_splash_screen.h"
#include "circular_progress.h"

class SplashScreen : public QMainWindow
{
	Q_OBJECT

	public:
		explicit SplashScreen(QMainWindow *parent = 0);

	private:
		Ui_SplashScreen *splashScreen		= new Ui_SplashScreen();
		CircularProgress *circularProgress 	= new CircularProgress();

	// slots:
	// 	int setProgressValue(int newValue);
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QMainWindow *parent = 0);

	private:
		Ui_MainWindow *mainWindow= new Ui_MainWindow();
};

#endif // MAINWINDOW_H
