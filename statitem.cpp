#include "statitem.h"
#include "ui_statitem.h"
#include <QPainter>
#include <QDebug>

StatItem::StatItem(QWidget *parent)
	: QDialog(parent),
	ui(new Ui::StatItem)
{
	ui->setupUi(this);
	ui->comboBox->addItem("BlueCerulean");
	ui->comboBox->addItem("BrownSand");
	ui->comboBox->addItem("Dark");
	ui->comboBox->addItem("Light");
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), ui->tab_2, SLOT(changeStyle(int)));
}

void StatItem::getModel(QStandardItemModel* mModel, QStringList mAllProvince, QStringList mAllArea, QStringList mAllType)
{
	ui->tab->getModel(mModel, mAllProvince);
	ui->tab_2->getModel(mModel, mAllArea);
	ui->tab_3->getModel(mModel, mAllType);
}

StatItem::~StatItem()
{
	delete ui;
}
