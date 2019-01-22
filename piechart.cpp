#include "piechart.h"

PieChart::PieChart(QWidget *parent)
{
	Q_UNUSED(parent);
	model = new QStandardItemModel;
	QGridLayout* layout = new QGridLayout;
	
	chartView = new QChartView(show());
	chartView->setChart(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	layout->addWidget(chartView, 1, 1);
	setLayout(layout);
}

QChart* PieChart::show()
{
	chart = new DrilldownChart();
	chart->setTitle("DonutChart Example");
	chart->legend()->setAlignment(Qt::AlignBottom);
	chart->setTheme(QChart::ChartThemeBlueCerulean);
	chart->legend()->setFont(QFont("Arial", 10));
	chart->setAnimationOptions(QChart::AllAnimations);
	return chart;
}

void PieChart::changeStyle(int index)
{
	switch (index)
	{
	case 0: chart->setTheme(QChart::ChartThemeBlueCerulean); break;
	case 1: chart->setTheme(QChart::ChartThemeBrownSand); break;
	case 2: chart->setTheme(QChart::ChartThemeDark); break;
	case 3: chart->setTheme(QChart::ChartThemeLight); break;
	}
}

void PieChart::getModel(QStandardItemModel* mModel, QStringList mAllArea)
{
	this->model = mModel;
	this->AllArea = mAllArea;

	QPieSeries* series = new QPieSeries;
	series->setHoleSize(0.40);
	chart->addSeries(series);
	chart->changeSeries(series);
	connect(series, SIGNAL(clicked(QPieSlice*)), chart, SLOT(handleSliceClicked(QPieSlice*)));
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
		int total_area(0);
		
		QPieSeries* series_province = new QPieSeries;
		connect(series_province, SIGNAL(clicked(QPieSlice*)), chart, SLOT(handleSliceClicked(QPieSlice*)));
		QStringList area_province;
		for (int row = 0; row < model->rowCount(); row++)
		{
			int total_province(0);
			QString province = model->data(model->index(row, 3)).toString();
			QString area = model->data(model->index(row, 2)).toString();
			if (area == modelArea[i])
			{
				total_area++;
				if (!area_province.contains(province))
				{
					area_province.append(province);
					for (int j = row; j < model->rowCount(); j++)
					{
						if (model->data(model->index(j, 3)).toString() == province)
							total_province++;
					}
					*series_province << new DrilldownSlice(total_province, province, series);
				}
			}	
		}
		*series << new DrilldownSlice(total_area, modelArea[i], series_province);
	}
}

PieChart::~PieChart()
{
	chart->removeAllSeries();
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
}