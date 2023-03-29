#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QPaintEvent>
#include <string>

class CircularProgress : public QWidget
{
	Q_OBJECT
	public:
		explicit CircularProgress(QWidget *parent = 0);
	protected:
		void paintEvent(QPaintEvent *);
	private:
		int value 		= 0;
		int width 		= 200;
		int height 		= 200;
		int progressWidth 	= 200;
		bool progressRoundedCap	= true;
		unsigned int progColor	= 0x498BD1;
		int maxValue		= 100;
		std::string fontFamily	= "Segoe UI";
		int fontSize		= 12;
		char suffix		= '%';
		unsigned int textColor	= 0x498BD1;
		bool enableShadow	= true;

	signals:

	public slots:
};

#endif // CIRCULARPROGRESS_H
