#pragma once

#include <QtWidgets/QWidget>
#include <QGridLayout>
#include <QtCharts>
#include <QtCharts\QChartView>
#include <QChartView>
#include <QtCharts\QLineSeries>
#include <QDebug>
#include <QPieSeries>
#include <QComboBox>
#include "piechart.h"

class dataVisual : public QWidget
{
	Q_OBJECT

public:
	explicit dataVisual(QWidget *parent = Q_NULLPTR);
	~dataVisual();
	public slots:
	void change();
	void change1();
	// 得到相应的数据内容
	void getModel(QStandardItemModel* mModel, QStringList mAllProvince);
public:
	QGridLayout* grid;
	QChartView* view;
	QChart* show();
	QChart* show1();
	QChart* show2();
	QChart* showdcout();
	QComboBox* ComBox;
	QComboBox* ComBox1;
	QVector<QChartView*> viewlist;
private:
	PieChart* piechart;
};
