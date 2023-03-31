#include "main_window.h"

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
	// set properties
	//this->resize(500,500);	
	//this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setAttribute(Qt::WA_TranslucentBackground);

	// show main window
	this->mainWindow->setupUi(this);

	// this->frame->setStyleSheet("border: none; background: transparent;");
	// this->slider->setRange(0,100);	
	// //this->slider->valueChanged.connect(this->prog->setValue());
	// QObject::connect(this->slider, SIGNAL(valueChanged(int)), this->prog, SLOT(setValue(int)));

	// // progress values
	// this->prog->value = 0;
	// this->prog->setMinimumSize(this->prog->width, this->prog->height);
	// this->prog->addShadow(true);

	// // add circular progress widget
	// this->layout->addWidget(this->prog, Qt::AlignCenter, Qt::AlignCenter);
	// this->layout->addWidget(this->slider, Qt::AlignCenter, Qt::AlignCenter);
	// this->frame->setLayout(this->layout);
	// this->setCentralWidget(this->frame);
}
