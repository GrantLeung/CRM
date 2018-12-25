/********************************************************************************
** Form generated from reading UI file 'statitem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATITEM_H
#define UI_STATITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "barchart.h"
#include "linechart.h"
#include "piechart.h"

QT_BEGIN_NAMESPACE

class Ui_StatItem
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    BarChart *tab;
    PieChart *tab_2;
    QComboBox *comboBox;
    LineChart *tab_3;

    void setupUi(QWidget *StatItem)
    {
        if (StatItem->objectName().isEmpty())
            StatItem->setObjectName(QStringLiteral("StatItem"));
        StatItem->resize(864, 598);
        gridLayout = new QGridLayout(StatItem);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(StatItem);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new BarChart();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new PieChart();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 20, 101, 22));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new LineChart();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(StatItem);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StatItem);
    } // setupUi

    void retranslateUi(QWidget *StatItem)
    {
        StatItem->setWindowTitle(QApplication::translate("StatItem", "Form", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StatItem", "Province", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("StatItem", "Area", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("StatItem", "\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatItem: public Ui_StatItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATITEM_H
