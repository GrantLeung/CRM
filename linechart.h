#pragma once

#include <QWidget>
#include <QtCharts>
#include <QChartView>

class LineChart : public QWidget
{
	Q_OBJECT

public:
	explicit LineChart(QWidget *parent = Q_NULLPTR);
	~LineChart();
	void getModel(QStandardItemModel* , QStringList);
	QChart* showChart();
private:
	QChartView* chartView;
	QStandardItemModel* Model;
	QStringList AllType;
};
