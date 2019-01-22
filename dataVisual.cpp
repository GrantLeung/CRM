#include "dataVisual.h"
#include "piechart.h"

dataVisual::dataVisual(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	ComBox = new QComboBox;
	ComBox->addItem("NO-legen");
	ComBox->addItem("left");
	ComBox->addItem("right");
	ComBox->addItem("buttom");
	QHBoxLayout* hb = new QHBoxLayout;
	QLabel* label1 = new QLabel("Theme: ");
	ComBox1 = new QComboBox;
	ComBox1->addItem("BlueCerulean");
	ComBox1->addItem("BlueIcy");
	ComBox1->addItem("BrownSand");
	ComBox1->addItem("Dark");
	QLabel *label = new QLabel("Legend:");
	hb->addWidget(label1);
	hb->addWidget(ComBox1);
	hb->addWidget(label);
	hb->addWidget(ComBox);
	hb->addStretch();
	connect(ComBox, SIGNAL(currentTextChanged(QString)), this, SLOT(change()));
	connect(ComBox1, SIGNAL(currentTextChanged(QString)), this, SLOT(change1()));
	grid = new QGridLayout;
	view = new QChartView(show());
	view->setRenderHint(QPainter::Antialiasing);
	viewlist << view;
	grid->addWidget(view, 1, 0);
	//往画布中添加扇形图
	view = new QChartView(show1());
	view->setRenderHint(QPainter::Antialiasing);
	viewlist << view;
	
	grid->addWidget(view, 1, 1);
	//往画布中添加曲线图
	view = new QChartView(show2());
	view->setRenderHint(QPainter::Antialiasing);
	grid->addWidget(view, 2, 0);
	viewlist << view;
	//往画布中添加圆饼图
	view = new QChartView(showdcout());
	view->setRenderHint(QPainter::Antialiasing);
	grid->addWidget(view, 2, 1);
	viewlist << view;
	//grid->addLayout(hb, 0, 0, 1, 2);
	setLayout(grid);
}

void dataVisual::getModel(QStandardItemModel* mModel, QStringList mAllProvince)
{
	piechart = new PieChart();
	piechart->getModel(mModel, mAllProvince);
	grid->addWidget(piechart->chartView, 1, 1);
}

QChart* dataVisual::show()
{
	QLineSeries *series = new QLineSeries;
	*series << QPointF(0, 6) << QPointF(2, 5) << QPointF(4, 3) << QPointF(5, 5) << QPointF(8, 8) << QPointF(9, 5);
	QChart *ch = new QChart;
	ch->addSeries(series);
	ch->createDefaultAxes();
	ch->legend()->setAlignment(Qt::AlignBottom);
	ch->setTitle("Qt");
	ch->setAnimationOptions(QChart::SeriesAnimations);
	return ch;
}
QChart* dataVisual::show1()
{
	QPieSeries  *pieSeries = new QPieSeries();
	pieSeries->append("Java", 40);
	pieSeries->append("C#", 20);
	pieSeries->append("JS", 10);
	pieSeries->append("C/C++", 30);
	QChart *ch = new QChart;
	ch->addSeries(pieSeries);
	ch->createDefaultAxes();
	ch->setTitle("Qt");
	ch->setAnimationOptions(QChart::SeriesAnimations);
	ch->legend()->setAlignment(Qt::AlignBottom);
	return ch;
}
void dataVisual::change()
{
	QChartView *chartView;
	if (ComBox->currentIndex() != 0)
	{
		foreach(chartView, viewlist) {
			switch (ComBox->currentIndex())
			{
			case 1: chartView->chart()->legend()->setAlignment(Qt::AlignTop); break;
			case 2: chartView->chart()->legend()->setAlignment(Qt::AlignBottom); break;
			case 3: chartView->chart()->legend()->setAlignment(Qt::AlignLeft); break;
			case 4: chartView->chart()->legend()->setAlignment(Qt::AlignRight); break;
			}
			chartView->chart()->legend()->show();
		}
	}
	else {
		viewlist.at(0)->chart()->legend()->hide();
		viewlist.at(1)->chart()->legend()->hide();
		viewlist.at(2)->chart()->legend()->hide();
		viewlist.at(3)->chart()->legend()->hide();
	}
}
QChart* dataVisual::show2()
{
	QSplineSeries *serial = new QSplineSeries;
	*serial << QPointF(0, 1) << QPointF(2, 2) << QPointF(3, 4) << QPointF(5, 2) << QPointF(8, 1.5) << QPointF(9, 3);
	QChart *ch = new QChart;
	ch->addSeries(serial);
	ch->createDefaultAxes();
	ch->legend()->setAlignment(Qt::AlignBottom);
	ch->setTitle("Qt");
	ch->setAnimationOptions(QChart::SeriesAnimations);
	return ch;
}
QChart* dataVisual::showdcout()
{
	QPieSeries *pie = new QPieSeries;
	pie->append("C# 20%", 20);
	QPieSlice *slice = pie->append("JS 10%", 10);
	slice->setExploded();
	slice->setLabelVisible();
	pie->append("Java 40%", 40);
	pie->setHoleSize(0.4);
	pie->append("C/C++ 30%", 30);
	QChart *ch = new QChart;
	ch->addSeries(pie);
	ch->createDefaultAxes();
	ch->legend()->setAlignment(Qt::AlignBottom);
	ch->setTitle("Qt");
	ch->setAnimationOptions(QChart::SeriesAnimations);
	return ch;
}
void dataVisual::change1()
{
	QChartView *view;
	//创建调色板
	QPalette pal = window()->palette();
	foreach(view, viewlist)
	{
		switch (ComBox1->currentIndex())
		{
		case 0:view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
			pal.setColor(QPalette::Window, QRgb(0x40434a));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));  
			break;
		case 1:view->chart()->setTheme(QChart::ChartThemeBlueIcy);
			pal.setColor(QPalette::Window, QRgb(0xcee7f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044)); 
			break;
		case 2:view->chart()->setTheme(QChart::ChartThemeBrownSand);
			pal.setColor(QPalette::Window, QRgb(0x9e8965));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
			break;
		case 3:view->chart()->setTheme(QChart::ChartThemeDark);
			pal.setColor(QPalette::Window, QRgb(0x121218));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6)); 
			break;
		}
	}
	window()->setPalette(pal);
}
dataVisual::~dataVisual()
{
}