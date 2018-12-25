#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "dlgitem.h"
namespace Ui {
	class StatItem;
}

class StatItem : public QDialog
{
	Q_OBJECT

public:
	StatItem(QWidget *parent = 0);
	~StatItem();
	
private:
	Ui::StatItem* ui;
	public slots:
	void getModel(QStandardItemModel* mModel, QStringList mAllProvince, QStringList mAllArea, QStringList mAllType);

};
