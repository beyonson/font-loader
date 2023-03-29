#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QPaintEvent>

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

	signals:

	public slots:
};

#endif // CIRCULARPROGRESS_H
