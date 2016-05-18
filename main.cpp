#include "qtctt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtCTT w;
	w.show();
	return a.exec();
}
