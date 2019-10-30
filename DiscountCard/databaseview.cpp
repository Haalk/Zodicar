#include "databaseview.h"
#include <QDebug>
#include "database.h"
#include <QHeaderView>
#include <QSqlTableModel>

DatabaseView::DatabaseView(QWidget *parent) : QWidget(parent)
{

}

DatabaseView::~DatabaseView()
{
    delete m_tableView;
}

void DatabaseView::Init()
{
    m_tableView = new QTableView;
    m_tableView->setModel(Database::Instance()->getModel());
    m_tableView->verticalHeader()->setVisible(false);
    m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_isShow = false;
    showDatabase(m_isShow);

    //connect(m_tableView,&QTableView::editTriggers,this,&DatabaseView::changedTable);
}

QTableView *DatabaseView::getDatabaseTableView()
{
    if(m_tableView == nullptr)
    {
        qDebug() << "QTableView *DatabaseView::getDatabaseTableView() is nullptr";
        return  nullptr;
    }
    return m_tableView;
}

void DatabaseView::Update()
{
     //qDebug() << "DatabaseView::Update()";
    if(!m_isShow)
    {
        m_tableView->setModel(Database::Instance()->getModel());
    }
}

void DatabaseView::discardChanges(bool isDiscard)
{
    if(isDiscard == false)
    {
        //qDebug() << "DatabaseView::discardChanges()";
        Database::Instance()->getModel()->select();
        //Update();
    }
}

void DatabaseView::EnableChange(bool isEnable)
{
    bool isAllowEdit = false;
    if(isEnable)
    {
        //qDebug() << "DatabaseView::EnableChange() DoubleClicked";
        m_tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    else
    {
        //qDebug() << "DatabaseView::EnableChange() NoEditTriggers";
        m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

const QAbstractItemModel *DatabaseView::getModel()
{
    return m_tableView->model();
}

bool DatabaseView::ApplyChanged(bool isCorrect,const QString &value, const QModelIndex &modelIndex)
{
    qDebug() << "ApplyChanged";
    if(isCorrect)
    {
        qDebug() << "ApplyChanged isCorrect";
        m_tableView->model()->setData(modelIndex,value);
    }

    return false;
}

void DatabaseView::showDatabase(bool isShow)
{
    if(m_isShow)
    {
        m_tableView->setModel(Database::Instance()->getModel());
        m_tableView->show();
    }
    else
    {
        //m_tableView->hide();
        m_tableView->setModel(new QSqlTableModel() );
    }
    m_isShow = !m_isShow;
    qDebug() << "DatabaseView::showDatabase " + QString::number(m_isShow);
    emit SButtonShow(m_isShow);
}
