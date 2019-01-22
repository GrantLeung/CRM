#include "barchart.h"
#include <QPainter>

BarChart::BarChart(QWidget *parent)
{
	Q_UNUSED(parent);
	model = new QStandardItemModel;
	customPlot = new QCustomPlot;
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(customPlot, 0, 0);
	setLayout(layout);
}
BarChart::~BarChart()
{
	if (model != nullptr)
	{
		model = nullptr;
		delete model;
	}
	if (customPlot != nullptr)
	{
		customPlot = nullptr;
		delete customPlot;
	}
}

void BarChart::getModel(QStandardItemModel* mModel, QStringList mAllProvince)
{
	this->model = mModel;
	this->AllProvince = mAllProvince;
	QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	fossil->setAntialiased(false);
	fossil->setStackingGap(1);
	fossil->setName("Customers");
	QVector<double> ticks;
	QVector<QString> labels;

	QVector<QString> modelProvince;
	QVector<double> modelTotal;
	for (int row = 0; row < model->rowCount(); row++)
	{
		QModelIndex index = model->index(row, 3);
		QString province = model->data(index).toString();
		if (!modelProvince.contains(province))
		{
			modelProvince.append(province);
		}
	}
	for (int i = 0; i < modelProvince.size(); i++)
	{
		QString province = modelProvince[i];
		int total(0);
		for (int row = 0; row < model->rowCount(); row++)
		{
			QModelIndex index = model->index(row, 3);
			if (model->data(index) == province)
				total++;
			modelTotal.append(total);
			
			/*QColor color = QColor(rand() % 256, rand() % 256, rand() % 256);*/
			/*painter.setBrush(QBrush(color, Qt::SolidPattern));*/
		}
		/*int width = 10;*/
		//QModelIndex colorIndex = model->index(i, 0);
		/*QColor color = QColor(model->data(colorIndex, Qt::DecorationRole).toString());
		painter.drawRect(QRect(pos, y0 - total * 10, width, total * 10));
		painter.drawText(pos, y0 + 20, modelProvince[i]);
		pos += 50;*/
		ticks.append(i+1);
	}

	//ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
	labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, modelProvince);
	customPlot->xAxis->setTicker(textTicker);
	customPlot->xAxis->setTickLabelRotation(60);
	customPlot->xAxis->setSubTicks(false);
	customPlot->xAxis->setTickLength(0, 4);
	customPlot->xAxis->setRange(0, 8);
	customPlot->xAxis->grid()->setVisible(true);
	customPlot->yAxis->setRange(0, 12.1);
	customPlot->yAxis->setPadding(5); // a bit more space to the left border
	customPlot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
	customPlot->yAxis->grid()->setSubGridVisible(true);
	QFont tickFont;
	tickFont.setPointSize(12);
	customPlot->xAxis->setTickLabelFont(tickFont);
	QVector<double> fossilData/*, nuclearData, regenData*/;
	fossilData << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
	fossil->setData(ticks, modelTotal);
	customPlot->legend->setVisible(true);
	customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);
	customPlot->legend->setBrush(QColor(255, 255, 255, 100));
	customPlot->legend->setBorderPen(Qt::NoPen);
	QFont legendFont = font();
	legendFont.setPointSize(20);
	customPlot->legend->setFont(legendFont);
	customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

//void BarChart::paintEvent(QPaintEvent*)
//{
//	QPainter painter(this);
//	painter.setPen(Qt::black);
//	int x0 = 40;
//	int y0 = 250;
//
//	QStringList modelProvince;
//	int pos = x0 + 20;
//	for (int row = 0; row < model->rowCount(); row++)
//	{
//		QModelIndex index = model->index(row, 3);
//		QString province = model->data(index).toString();
//		if (!modelProvince.contains(province))
//		{
//			modelProvince.append(province);
//		}
//	}
//	for (int i = 0; i < modelProvince.size(); i++)
//	{
//		QString province = modelProvince[i];
//		int total(0);
//		for (int row = 0; row < model->rowCount(); row++)
//		{
//			QModelIndex index = model->index(row, 3);
//			if (model->data(index) == province)
//				total++;
//
//			QColor color = QColor(rand() % 256, rand() % 256, rand() % 256);
//			painter.setBrush(QBrush(color, Qt::SolidPattern));
//		}
//		int width = 10;
//		QModelIndex colorIndex = model->index(i, 0);
//		QColor color = QColor(model->data(colorIndex, Qt::DecorationRole).toString());
//		painter.drawRect(QRect(pos, y0 - total * 10, width, total * 10));
//		painter.drawText(pos, y0 + 20, modelProvince[i]);
//		pos += 50;
//	}
//
//	// y÷·
//	painter.drawLine(x0, y0, 40, 30);
//	painter.drawLine(38, 32, 40, 30);
//	painter.drawLine(40, 30, 42, 32);
//	painter.drawText(20, 20, tr("client: "));
//	// x÷·
//	painter.drawLine(x0, y0, pos, 250);
//	painter.drawLine(pos - 2, 248, pos, 250);
//	painter.drawLine(pos, 250, pos - 2, 252);
//	painter.drawText(pos + 5, 250, tr("province: "));
//}