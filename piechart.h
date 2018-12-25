#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QtCharts>
#include <QPaintEvent>

class PieChart : public QWidget
{
	Q_OBJECT

public:
	explicit PieChart(QWidget *parent = Q_NULLPTR);
	~PieChart();
	void paintEvent(QPaintEvent*);
	void getModel(QStandardItemModel* mModel, QStringList mAllProvince);
	public slots:
	void changeStyle(int index);
private:
	QPieSeries* series;
	QChartView* chartView;
	QStandardItemModel* model;

	QStringList AllArea;
	QStringList modelArea;
};
