#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <string>
#include <iostream>

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QPaintEvent>

class CircularProgress : public QWidget
{
	Q_OBJECT
	public:
		explicit CircularProgress(QWidget *parent = 0);
		int width 				= 200;
		int height 				= 200;
		friend class MainWindow;

	protected:
		void paintEvent(QPaintEvent *);
		void addShadow(bool enable);
		
	private:
		int value 				= 0;
		int progWidth 			= 10;
		int maxValue			= 100;
		int fontSize			= 30;
		unsigned int progColor	= 0x498BD1;
		unsigned int textColor	= 0x498BD1;
		bool progRoundedCap		= true;
		bool enableShadow		= true;
		std::string suffix		= "%";
		std::string fontFamily	= "Segoe UI";

		// Qt objects
		QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();

	signals:

	public slots:
		void setValue(int newValue);

};

#endif // CIRCULARPROGRESS_H
