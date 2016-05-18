#ifndef QTCTT_H
#define QTCTT_H

#include <QtGui/QMainWindow>
#include "ui_qtctt.h"

class QtCTT : public QMainWindow
{
	Q_OBJECT

public:
	QtCTT(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtCTT();

private:
	Ui::QtCTTClass ui;

	private slots:
		void slot_transfer();
};

#endif // QTCTT_H
