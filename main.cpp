#include "mainwindow.h"
#include "piechart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	QFile qss("Resources/style.qss");
	qss.open(QFile::ReadOnly);
	QString style = qss.readAll();
	//qApp->setStyleSheet(style);
    w.show();
	qss.close();
    return a.exec();
}
