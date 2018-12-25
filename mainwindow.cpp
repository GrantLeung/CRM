﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListView>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>
#include <QDebug>
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/myapp.ico"));

    mDefaultDB = QCoreApplication::applicationDirPath() + "\\customers.txt";
    mAllType<< QStringLiteral("企业")<< QStringLiteral("高校")<< QStringLiteral("研究所")<< QStringLiteral("代理")<< QStringLiteral("外")<< QStringLiteral("政府机构")<< QStringLiteral("部队")<< QStringLiteral("第三方");
    mAllArea<< QStringLiteral("华东")<< QStringLiteral("华南")<< QStringLiteral("华中")<< QStringLiteral("华北")<< QStringLiteral("其他")<< QStringLiteral("国外");
    mAllProvince<< QStringLiteral("山东")<< QStringLiteral("浙江")<< QStringLiteral("江苏")<< QStringLiteral("安徽")<< QStringLiteral("上海")<< QStringLiteral("福建")
                << QStringLiteral("广东")<< QStringLiteral("广西")<< QStringLiteral("海南")
                << QStringLiteral("湖北")<< QStringLiteral("湖南")<< QStringLiteral("河南")<< QStringLiteral("江西")
                << QStringLiteral("北京")<< QStringLiteral("天津")<< QStringLiteral("河北")<< QStringLiteral("山西")<< QStringLiteral("内蒙")
                << QStringLiteral("宁夏")<< QStringLiteral("新疆")<< QStringLiteral("青海")<< QStringLiteral("陕西")<< QStringLiteral("甘肃")<< QStringLiteral("四川")<< QStringLiteral("云南")<< QStringLiteral("贵州")<< QStringLiteral("西藏")<< QStringLiteral("重庆")<< QStringLiteral("辽宁")<< QStringLiteral("吉林")<< QStringLiteral("黑龙江");
    mFilterType = "";
    mFilterArea = "";
    mFilterProvince = "";
    mFilterKey = "";

    InitMenu();

    OpenDb(mDefaultDB);
    InitTable();

    ui->treeWidget->expandAll();
    ui->treeWidget->setCurrentItem(ui->treeWidget->itemAt(0,0));

    ui->comboBox->setView(new QListView());
}

MainWindow::~MainWindow()
{
    ClearData();
	if (mModel != nullptr)
	{
		delete mModel;
		mModel = nullptr;
	}
    delete ui;
}

void MainWindow::InitMenu()
{
	connect(ui->action, SIGNAL(triggered(bool)), this, SLOT(onMenuOpen(bool)));
	connect(ui->action_2, SIGNAL(triggered(bool)), this, SLOT(onMenuSave(bool)));
	connect(ui->action_3, SIGNAL(triggered(bool)), this, SLOT(onMenuStat(bool)));
}

void MainWindow::InitModel()
{
    mModel->removeRows(0,mModel->rowCount());
    for(int i=0;i<mItems.size();i++)
    {
        Customer* p = mItems[i];
        QString sArea = Area2String(p->area);
        QString sProvince = Province2String(p->province);
        QString sType = Type2String(p->type);

        //区域过滤
        if(!mFilterArea.isEmpty())
        {
           if(mFilterArea != sArea)
           {
               continue;
           }
        }
        //省份过滤
        if(!mFilterProvince.isEmpty())
        {
           if(mFilterProvince != sProvince)
           {
               continue;
           }
        }
        //单位类别过滤
        if(!mFilterType.isEmpty())
        {
           if(mFilterType != sType)
           {
               continue;
           }
        }
        //关键字过滤
        if(!mFilterKey.isEmpty())
        {
            QStringList strs;
            strs<<p->name<<sType<<sArea<<sProvince<<p->city<<p->site<<p->contact<<p->buy<<p->research<<p->remark;
            bool bFind = false;
            foreach (QString s, strs)
            {
                if(s.indexOf(mFilterKey) != -1)
                {
                    bFind = true;
                    break;
                }
            }
            if(!bFind)
            {
                continue;
            }
        }

        QList<QStandardItem*> items;
        QStandardItem* item1 = new QStandardItem(p->name);
        QStandardItem* item2 = new QStandardItem(Type2String(p->type));
        QStandardItem* item3 = new QStandardItem(Area2String(p->area));
        QStandardItem* item4 = new QStandardItem(Province2String(p->province) );
        QStandardItem* item5 = new QStandardItem(p->city);
        QStandardItem* item6 = new QStandardItem(p->address);
        QStandardItem* item7 = new QStandardItem(p->site);
        QStandardItem* item8 = new QStandardItem(p->research);
        QStandardItem* item9 = new QStandardItem(p->remark);
        items.append(item1);
        items.append(item2);
        items.append(item3);
        items.append(item4);
        items.append(item5);
        items.append(item6);
        items.append(item7);
        items.append(item8);
        items.append(item9);
        mModel->appendRow(items);
    }
}

void MainWindow::InitTable()
{
    QTableView* t = ui->tableView;
    t->setEditTriggers(QTreeView::NoEditTriggers);			//不能编辑
    t->setSelectionBehavior(QTreeView::SelectRows);			//一次选中整行
    t->setAlternatingRowColors(true);

    QString strTreeStyle = "QTableView::item {height: 25px}";
    t->setStyleSheet(strTreeStyle);

    QStringList headers;
    headers<< QStringLiteral("单位名称")<<QStringLiteral("单位类型")
            << QStringLiteral("区域")<<QStringLiteral("省份")
            << QStringLiteral("城市")<<QStringLiteral("地址")
            << QStringLiteral("网址")<<QStringLiteral("研究方向")
            << QStringLiteral("备注");
    mModel = new QStandardItemModel(t);
    mModel->setHorizontalHeaderLabels( headers );

    InitModel();
    t->setModel(mModel);
    for(int i=0;i<headers.size();i++)
    {
        if(i==0)
        {
            t->horizontalHeader()->resizeSection(i,200);
        }
        else if(i==1)
        {
            t->horizontalHeader()->resizeSection(i,80);
        }
        else if(i>=2 && i<=4)
        {
            t->horizontalHeader()->resizeSection(i,60);
        }
        else
        {
            t->horizontalHeader()->resizeSection(i,150);
        }
    }

    QModelIndex rootIndex = t->rootIndex();
    QModelIndex selIndex = mModel->index(0,0,rootIndex);
    t->setCurrentIndex(selIndex);
//    t->expandAll();
}

void MainWindow::AddItem(Customer *item)
{
    mItems.push_back(item);
}

void MainWindow::ClearData()
{
    for(int i=0;i<mItems.size();i++)
    {
        Customer* p = mItems[i];
        if(p)
        {
            delete p;
            p = NULL;
        }
    }
    mItems.clear();
}

void MainWindow::OpenDb(QString fileName)
{
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName(fileName);
    //if(db.open())
    //{
    //    qDebug()<<"Database Opened";

    //    mDefaultDB = fileName;

    //    QSqlQuery sql_query;
    //    QString select_all_sql = "select * from Customer";
    //    //查询所有记录
    //    sql_query.prepare(select_all_sql);
    //    if(!sql_query.exec())
    //    {
    //        qDebug()<<sql_query.lastError();
    //    }
    //    else
    //    {
    //        while(sql_query.next())
    //        {
    //            Customer* p = new Customer;
    //            p->name = sql_query.value(0).toString();
    //            p->type = sql_query.value(1).toInt();
    //            p->area = sql_query.value(2).toInt();
    //            p->province = sql_query.value(3).toInt();
    //            p->city = sql_query.value(4).toString();
    //            p->address = sql_query.value(5).toString();
    //            p->site = sql_query.value(6).toString();
    //            p->contact = sql_query.value(7).toString();
    //            p->buy = sql_query.value(8).toString();
    //            p->research = sql_query.value(9).toString();
    //            p->remark = sql_query.value(10).toString();
    //            mItems.push_back(p);
    //        }
    //    }
    //}
    //db.close();
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
		return;
	QTextStream out(&file);
	QString line;
	do {
		line = out.readLine();
		if (line == "") break;
		QStringList pieces = line.split(",", QString::SkipEmptyParts);
		Customer* p = new Customer;
		p->name = pieces.value(0);
		p->type = pieces.value(1).toInt();
		p->area = pieces.value(2).toInt();
		p->province = pieces.value(3).toInt();
		p->city = pieces.value(4);
		p->address = pieces.value(5);
		p->site = pieces.value(6);
		p->contact = pieces.value(7);
		p->buy = pieces.value(8);
		p->research = pieces.value(9);
		p->remark = pieces.value(10);
		mItems.push_back(p);
	} while (!line.isEmpty());
	file.close();

}

void MainWindow::SaveToDb(QString fileName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);
    if(db.open())
    {
        QSqlQuery sql_query;
        QString create_sql = "create table if not exists Customer (name varchar(100) primary key, \
                                                    type int ,\
                                                    area int,\
                                                    province int,\
                                                    city varchar(20),\
                                                    address varchar(100),\
                                                    site varchar(200),\
                                                    contact varchar(500),\
                                                    buy varchar(200),\
                                                    research varchar(100),\
                                                    remark varchar(200))"; //创建数据表
//        QString insert_sql = "insert into Customer values(\"公司1\",1,1,1,\"武汉\",\"武汉洪山区XXX\",\"www.xxx.com\",\"aaaaa\",\"bbbbb\",\"ccccc\",\"ddddd\")";    //插入数据
        QString insert_sql = "insert into Customer values(\"%1\",%2,%3,%4,\"%5\",\"%6\",\"%7\",\"%8\",\"%9\",\"%10\",\"%11\")";    //插入数据
        QString select_all_sql = "select * from Customer";

        sql_query.prepare(create_sql); //创建表
        if(!sql_query.exec()) //查看创建表是否成功
        {
            qDebug()<<QObject::tr("Table Create failed");
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<< "Table Created" ;

            for(int i=0;i<mItems.size();i++)
            {
                Customer* p = mItems[i];
                QString sql = insert_sql;
                sql.replace("%10",p->research);
                sql.replace("%11",p->remark);
                sql = sql.arg(p->name).arg(p->type).arg(p->area).arg(p->province).arg(p->city).arg(p->address).arg(p->site).arg(p->contact).arg(p->buy);
                sql_query.prepare(sql);
                if(!sql_query.exec())
                {
                    qDebug()<<sql_query.lastError();
                }
                else
                {
                    qDebug()<<"插入记录成功";
                }
            }
        }
    }
    db.close();



}

void MainWindow::InsertToDb(Customer *p)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mDefaultDB);
    if(db.open())
    {
        qDebug()<<"Database Opened";

        QSqlQuery sql_query;
        QString create_sql = "create table if not exists Customer (name varchar(100) primary key, \
                                                    type int ,\
                                                    area int,\
                                                    province int,\
                                                    city varchar(20),\
                                                    address varchar(100),\
                                                    site varchar(200),\
                                                    contact varchar(500),\
                                                    buy varchar(200),\
                                                    research varchar(100),\
                                                    remark varchar(200))"; //创建数据表
        sql_query.prepare(create_sql);
        sql_query.exec();                   //创建表

        QString sql = "insert into Customer values(\"%1\",%2,%3,%4,\"%5\",\"%6\",\"%7\",\"%8\",\"%9\",\"%10\",\"%11\")";    //插入数据
        sql.replace("%10",p->research);
        sql.replace("%11",p->remark);
        sql = sql.arg(p->name).arg(p->type).arg(p->area).arg(p->province).arg(p->city).arg(p->address).arg(p->site).arg(p->contact).arg(p->buy);
        sql_query.prepare(sql);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"插入记录成功";
        }
    }
    db.close();
}

void MainWindow::DeleteFromDb(QString name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mDefaultDB);
    if(db.open())
    {
        qDebug()<<"Database Opened";

        QSqlQuery sql_query;
        QString sql = QString("delete from Customer where name='%1'").arg(name);
        sql_query.prepare(sql);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"删除记录成功";
        }
    }
    db.close();
}

void MainWindow::onMenuOpen(bool checked)
{
	Q_UNUSED(checked);
    QString fileName = QFileDialog::getOpenFileName(this,"打开文件","","Text Files(*.txt)");
    if (fileName.isNull())
    {
        return;
    }
    if(fileName.indexOf(".txt") != -1)
    {
        ClearData();
        OpenDb(fileName);
        InitTable();
    }
}

void MainWindow::onMenuSave(bool checked)
{
	Q_UNUSED(checked);
    QString fileName = QFileDialog::getSaveFileName(this,"保存到文件","","Database Files(*.db)");
    if (fileName.isNull())
    {
        return;
    }
    if(QFile::exists(fileName))
    {
        QFile::remove(fileName);
    }
    SaveToDb(fileName);
}

void MainWindow::onMenuStat(bool checked)
{
	Q_UNUSED(checked);
	StatItem stat;
	stat.getModel(mModel, mAllProvince, mAllArea, mAllType);
	stat.exec();
}

void MainWindow::on_btnSearch_clicked()
{
    QString s = ui->lineEdit->text();
    mFilterKey = s;
    InitModel();
}

void MainWindow::on_btnAdd_clicked()
{
    DlgItem dlg(NULL);
    connect(&dlg,SIGNAL(sigAddItem(Customer*)),this,SLOT(slotAddItem(Customer*)));
    dlg.exec();
}

void MainWindow::on_btnDelete_clicked()
{
//    int row = ui->treeView->currentIndex().row();
    int row = ui->tableView->currentIndex().row();
    QString name = mModel->item(row,0)->text();
    DeleteItem(name);

    mModel->removeRow(row);

    DeleteFromDb(name);
}

void MainWindow::slotAddItem(Customer *p)
{
    mItems.push_back(p);

    QList<QStandardItem*> items;
    QStandardItem* item1 = new QStandardItem(p->name);
    QStandardItem* item2 = new QStandardItem(Type2String(p->type));
    QStandardItem* item3 = new QStandardItem(Area2String(p->area));
    QStandardItem* item4 = new QStandardItem(Province2String(p->province) );
    QStandardItem* item5 = new QStandardItem(p->city);
    QStandardItem* item6 = new QStandardItem(p->address);
    QStandardItem* item7 = new QStandardItem(p->site);
    QStandardItem* item8 = new QStandardItem(p->research);
    QStandardItem* item9 = new QStandardItem(p->remark);
    items.append(item1);
    items.append(item2);
    items.append(item3);
    items.append(item4);
    items.append(item5);
    items.append(item6);
    items.append(item7);
    items.append(item8);
    items.append(item9);
    mModel->appendRow(items);

    InsertToDb(p);
}

QString MainWindow::Type2String(int n)
{
    return mAllType[n];
}

QString MainWindow::Area2String(int n)
{
    return mAllArea[n];
}

QString MainWindow::Province2String(int n)
{
    if(n>=0 && n<mAllProvince.size() )
    {
        return mAllProvince[n];
    }
    return "";
}

Customer *MainWindow::FindItem(QString name)
{
    for(int i=0;i<mItems.size();i++)
    {
        if(mItems[i]->name == name)
        {
            return mItems[i];
        }
    }
    return NULL;
}

void MainWindow::DeleteItem(QString name)
{
    for(int i=0;i<mItems.size();i++)
    {
        if(mItems[i]->name == name)
        {
            mItems.removeAt(i);
            return;
        }
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &text)
{
    if(text == QStringLiteral("所有类型"))
    {
        mFilterType = "";
    }
    else
    {
        mFilterType = text;
    }
    InitModel();
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
	Q_UNUSED(previous);
    QString s = current->text(0);
    if(s == QStringLiteral("全部"))
    {
        mFilterArea = "";
        mFilterProvince = "";
    }
    else if(mAllArea.contains(s))
    {
        //区域
        mFilterArea = s;
        mFilterProvince = "";
    }
    else if(mAllProvince.contains(s))
    {
        //省份
        mFilterArea = "";
        mFilterProvince = s;
    }
    InitModel();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString name = mModel->item(index.row(),0)->text();
    Customer *p = FindItem(name);
    if(p)
    {
        DlgItem dlg(p);
        if(QDialog::Accepted == dlg.exec())
        {
            mModel->item(index.row(),0)->setText(p->name);
            mModel->item(index.row(),1)->setText(Type2String(p->type));
            mModel->item(index.row(),2)->setText(Area2String(p->area));
            mModel->item(index.row(),3)->setText(Province2String(p->province));
            mModel->item(index.row(),4)->setText(p->city);
            mModel->item(index.row(),5)->setText(p->address);
            mModel->item(index.row(),6)->setText(p->site);
            mModel->item(index.row(),7)->setText(p->research);
            mModel->item(index.row(),8)->setText(p->remark);

            DeleteFromDb(name);
            InsertToDb(p);
        }
    }
}
