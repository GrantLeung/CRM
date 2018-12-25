#include "barchart.h"
#include <QPainter>

BarChart::BarChart(QWidget *parent)
{
	Q_UNUSED(parent);
	model = new QStandardItemModel;
}
BarChart::~BarChart()
{
	if (model != nullptr)
	{
		model = nullptr;
		delete model;
	}
}

void BarChart::getModel(QStandardItemModel* mModel, QStringList mAllProvince)
{
	this->model = mModel;
	this->AllProvince = mAllProvince;
}

void BarChart::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setPen(Qt::black);
	int x0 = 40;
	int y0 = 250;

	QStringList modelProvince;
	int pos = x0 + 20;
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

			QColor color = QColor(rand() % 256, rand() % 256, rand() % 256);
			painter.setBrush(QBrush(color, Qt::SolidPattern));
		}
		int width = 10;
		QModelIndex colorIndex = model->index(i, 0);
		QColor color = QColor(model->data(colorIndex, Qt::DecorationRole).toString());
		painter.drawRect(QRect(pos, y0 - total * 10, width, total * 10));
		painter.drawText(pos, y0 + 20, modelProvince[i]);
		pos += 50;
	}

	// y÷·
	painter.drawLine(x0, y0, 40, 30);
	painter.drawLine(38, 32, 40, 30);
	painter.drawLine(40, 30, 42, 32);
	painter.drawText(20, 20, tr("client: "));
	// x÷·
	painter.drawLine(x0, y0, pos, 250);
	painter.drawLine(pos - 2, 248, pos, 250);
	painter.drawLine(pos, 250, pos - 2, 252);
	painter.drawText(pos + 5, 250, tr("province: "));
}