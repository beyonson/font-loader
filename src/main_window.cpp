#include "main_window.h"

SplashScreen::SplashScreen(QMainWindow *parent) : QMainWindow(parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->splashScreen->setupUi(this);
	this->splashScreen->pushButton->clicked();

	// configure progress
	this->circularProgress->setParent(this->splashScreen->centralwidget);
	this->circularProgress->setFixedSize(this->circularProgress->width, this->circularProgress->height);
	this->circularProgress->addShadow(true);
	this->circularProgress->move(15,15);
}

// int SplashScreen::setProgressValue(int newValue)
// {
// 	return loadFont("../fonts/DroidSansMono.ttf");
// }

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
	// show main window
	this->mainWindow->setupUi(this);

	// this->frame->setStyleSheet("border: none; background: transparent;");
	// this->slider->setRange(0,100);	
	// //this->slider->valueChanged.connect(this->prog->setValue());
	// QObject::connect(this->slider, SIGNAL(valueChanged(int)), this->prog, SLOT(setValue(int)));

}
