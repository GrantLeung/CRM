#include "piechart.h"

PieChart::PieChart(QWidget *parent)
{
	Q_UNUSED(parent);
	model = new QStandardItemModel;
	series = new QPieSeries;
	series->setHoleSize(0.40);
	QGridLayout* layout = new QGridLayout;
	chartView = new QChartView;
	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->chart()->setTitle("DonutChart Example");
	chartView->chart()->addSeries(series);
	chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
	chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
	chartView->chart()->legend()->setFont(QFont("Arial", 10));
	chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
	layout->addWidget(chartView, 0, 0);
	setLayout(layout);
}

void PieChart::changeStyle(int index)
{
	switch (index)
	{
	case 0: chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean); break;
	case 1: chartView->chart()->setTheme(QChart::ChartThemeBlueIcy); break;
	case 2: chartView->chart()->setTheme(QChart::ChartThemeBrownSand); break;
	case 3: chartView->chart()->setTheme(QChart::ChartThemeDark); break;
	}
}

void PieChart::getModel(QStandardItemModel* mModel, QStringList mAllArea)
{
	this->model = mModel;
	this->AllArea = mAllArea;
	for (int row = 0; row < model->rowCount(); row++)
	{
		QModelIndex index = model->index(row, 2);
		QString area = model->data(index).toString();
		if (!modelArea.contains(area))
		{
			modelArea.append(area);
		}
	}
	for (int i = 0; i < modelArea.size(); i++)
	{
		QString area = modelArea[i];
		int total(0);
		for (int row = 0; row < model->rowCount(); row++)
		{
			QModelIndex index = model->index(row, 2);
			if (model->data(index) == area)
				total++;

		}
		series->append(area, total);
	}
}


void PieChart::paintEvent(QPaintEvent*)
{
	
}

PieChart::~PieChart()
{
	chartView->chart()->removeAllSeries();
	if (chartView != nullptr)
	{
		chartView = nullptr;
		delete chartView;
	}
	if (model != nullptr)
	{
		model = nullptr;
		delete model;
	}
	if (series != nullptr)
	{
		series = nullptr;
		delete series;
	}
}