#include "main_window.h"

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
	// set properties
	this->resize(500,500);	
	this->container->setStyleSheet("background-color: #222222");	
	// add circular progress widget
	this->layout->addWidget(this->prog, Qt::AlignCenter, Qt::AlignCenter);
	this->container->setLayout(this->layout);
	this->setCentralWidget(this->container);
}
