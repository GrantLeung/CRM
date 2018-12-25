#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QStandardItemModel>

class BarChart : public QWidget
{
	Q_OBJECT

public:
	explicit BarChart(QWidget *parent = Q_NULLPTR);
	~BarChart();

	void paintEvent(QPaintEvent*);
private:
	QStandardItemModel* model;
	QStringList AllProvince;
	public slots:
	void getModel(QStandardItemModel* mModel, QStringList mAllProvince);
};
