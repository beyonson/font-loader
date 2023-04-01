#include "main_window.h"

SplashScreen::SplashScreen(QMainWindow *parent) : QMainWindow(parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->splashScreen->setupUi(this);
	this->timer->start(25);
	QTimer::singleShot(150, this, SLOT(runFontLoader()));
	QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(setProgressValue()));

	// configure progress
	this->circularProgress->setParent(this->splashScreen->centralwidget);
	this->circularProgress->setFixedSize(this->circularProgress->width, this->circularProgress->height);
	this->circularProgress->addShadow(true);
	this->circularProgress->move(15,15);
}

void SplashScreen::setProgressValue()
{
	this->circularProgress->setValue(counter);
	counter++;
	std::cout << counter << std::endl;

	if (counter > 100) 
	{
		this->timer->stop();
	}
}

void SplashScreen::runFontLoader()
{
	loadFont("../fonts/DroidSansMono.ttf");
}

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
	// show main window
	this->mainWindow->setupUi(this);
}
