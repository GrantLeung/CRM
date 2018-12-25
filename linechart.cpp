#include "linechart.h"
#include <QDebug>

LineChart::LineChart(QWidget *parent)
	: QWidget(parent)
{
	chartView = new QChartView;
	chartView->setRenderHint(QPainter::Antialiasing);
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(chartView, 0, 0);
	setLayout(layout);
}
QChart* LineChart::showChart()
{
	QBarSeries *series = new QBarSeries();
	QBarCategoryAxis *axis = new QBarCategoryAxis();
	QStringList Model_AllType;
	QStringList Model_AllProvince;
	QBarSet* set;
	for (int row = 0; row < Model->rowCount(); row++)
	{

		QString Type = Model->data(Model->index(row, 1)).toString();
		if (!Model_AllType.contains(Type))
			Model_AllType << Type;

	}
	for (int row = 0; row < Model->rowCount(); row++)
	{
		QString Province = Model->data(Model->index(row, 3)).toString();
		if (!Model_AllProvince.contains(Province))
		{
			Model_AllProvince << Province;
			set = new QBarSet(Province);
			for (int i = 0; i < Model_AllType.size(); i++)
			{
				int num = 0;
				for (int row = 0; row < Model->rowCount(); row++)
				{
					if (Model_AllType.value(i) == Model->data(Model->index(row, 1)).toString() && Province == Model->data(Model->index(row, 3)).toString())
						num++;
				}
				set->append(num);
			}
		}

		series->append(set);
	}
	axis->append(Model_AllType);

	QChart* chart = new QChart;
	chart->addSeries(series);
	chart->setTitle("Simple barchart example");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chart->createDefaultAxes();//����Ĭ�ϵ����������ᣨ���� QBarSet ���õ�ֵ��
	chart->setAxisX(axis, series);//����������

	chart->legend()->setVisible(true); //����ͼ��Ϊ��ʾ״̬
	chart->legend()->setAlignment(Qt::AlignBottom);//����ͼ������ʾλ���ڵײ�
	return chart;
}

void LineChart::getModel(QStandardItemModel* mModel, QStringList mAllType)
{
	Model = mModel;
	AllType = mAllType;
	chartView->setChart(showChart());
}

LineChart::~LineChart()
{
}
