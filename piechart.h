#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QtCharts>
#include <QPaintEvent>
#include "DrillDown\drilldownchart.h"
#include "DrillDown\drilldownslice.h"


class PieChart : public QWidget
{
	Q_OBJECT

public:
	explicit PieChart(QWidget *parent = Q_NULLPTR);
	~PieChart();
	
	// �õ���Ӧ����������
	void getModel(QStandardItemModel* mModel, QStringList mAllProvince);
	QChart* show();
public:
	// chart�ı�����
	QChartView* chartView;
	
	public slots:
	void changeStyle(int index);
private:
	
	QStandardItemModel* model;
	DrilldownChart* chart;

	QStringList AllArea;
	QStringList modelArea;
};
