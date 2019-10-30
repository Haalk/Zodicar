#include "database.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QStringList>
#include <QString>
#include "Helper.h"

Database *Database::p_Database = nullptr;

Database::Database(QWidget *parent) : QWidget(parent)
{

}

void Database::SlotCheckRequirement(QString value,const QModelIndex& modelIndex)
{
    QVariant var = sqltablemodel->headerData(modelIndex.column(),Qt::Orientation::Horizontal);
    qDebug() << "SlotCheckRequirement";
    QString columnName = var.toString();
    if(columnName == "ID")
    {
        qDebug() << "SlotCheckRequirement columnName == ID";
        if(value.length() > CARD_SIZE || !isAvailable(columnName,columnName,value))
        {
            qDebug() << "SlotCheckRequirement  if(value.length() > CARD_SIZE && !isAvailable(columnName,columnName,value))";
            SRequirementCorrect(false,value,modelIndex);
            return;
        }

        if(value.length() < CARD_SIZE)
        {
            while(value.length() != CARD_SIZE)
            {
                QString temp = QString::number(0) + value;
                value = temp;
            }
            qDebug() << "SlotCheckRequirement value = " + value;
        }
    }
    qDebug() << "SlotCheckRequirement value = SRequirementCorrect(true,value,modelIndex);";
    SRequirementCorrect(true,value,modelIndex);
}
#include <QSqlRecord>
#include <QSqlField>
void Database::Init()
{
    m_database = new QSqlDatabase;
    *m_database = QSqlDatabase::addDatabase("QMYSQL");
    m_database->setHostName("localhost");
    m_database->setDatabaseName("card");
    m_database->setUserName("root");
    m_database->setPassword("1111");
    if(!m_database->open())
    {
        qDebug("FAILURE Database::Init()");
        qDebug() << QSqlDatabase::drivers();
        qDebug() << m_database->lastError();
    }

    QStringList listtables = m_database->tables();
    qDebug() << "listtables size " << QString::number(listtables.size());
    for(int i = 0;i<listtables.size();++i)
    {
        qDebug() << listtables[i];
    }

    //qDebug() << "QSqlRecord: " << m_database->record("client");

    QStringList list = QStringList() << ("id") << ("name")<< ("surname") << ("phone") << ("discount") << ("Purchase");


    sqltablemodel = new QSqlTableModel;
    sqltablemodel->setTable("client");
    sqltablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(!sqltablemodel->select())
    {
        qDebug() << sqltablemodel->lastError();
    }
    for(int i = 0;i<sqltablemodel->columnCount();i++)
    {
        //sqltablemodel->setHeaderData(i,Qt::Horizontal,list[i]);

        sqltablemodel->setHeaderData(i,Qt::Horizontal,m_database->record("client").field(i).name());
    }

    if(sqltablemodel == nullptr)
    {
        qDebug() << " Database::Init() = sqltablemodel == nullptr";
    }
}

bool Database::isEnabled(const QString &id, const QString &phone)
{
    QSqlQuery query;
    query.exec("SELECT ID FROM client WHERE ID = " + id);
    query.next();
    if(!(query.value(0).toString() == ""))
    {
        qDebug() << "INVALID! This ID already exists";
        m_lastError = /*"SELECT PHONE FROM client WHERE ID = " +*/ id + " is exist";
        return false;
    }

    query.exec("SELECT PHONE FROM client WHERE PHONE = " + phone);
    query.next();
     qDebug() << "PHONE = " + query.value(0).toString();

    if(!(query.value(0).toString() == ""))
    {
        qDebug() << "INVALID! This PHONE already exists";
        m_lastError = /*"SELECT PHONE FROM client WHERE PHONE = " + */ phone + " is exist";
        return false;
    }
}

bool Database::isAvailable(const QString &what, const QString &where, const QString &value)
{
    QSqlQuery query;
    query.exec("SELECT " + what + " FROM client WHERE " + what + " = " + value);
    query.next();
    if(!(query.value(0).toString() == ""))
    {
            qDebug() << "isAvailable true";
            return false;
    }
    return true;
}

bool Database::addToDatabase(const QString &name, const QString &surname, const QString &id, const QString &phone)
{
    QSqlQuery query;

    QString command = ("INSERT INTO client (id,name,surname,phone) values (\"" + id + "\",\"" + name + "\",\"" + surname + "\",\"" + phone + "\")");

    if(query.exec(command))
    {
        qDebug() << "Successfull add to databases new entry = " + id + ", "+ name + ", " + surname + ", "+ phone;
        sqltablemodel->select();
        return  true;
    }
    m_lastError = QString("Failure command: " + command);
    return false;
}

const QString &Database::lastError()
{
    return m_lastError;
}

Database *Database::Instance()
{
    if(p_Database == nullptr)
    {
        p_Database = new Database;
        qDebug() << " Database::  p_Database = new Database";
    }

    return p_Database;
}

QSqlTableModel *Database::getModel()
{
    if(sqltablemodel == nullptr)
    {
        qDebug() << " getModel = sqltablemodel == nullptr";
        return nullptr;
    }
    return sqltablemodel;
}
void Database::saveDatabase()
{
    if(sqltablemodel->submitAll())
    {
        qDebug() << "Database::saveDatabase() true";
        emit SSaveSuccess();
    }
    else
    {
        qDebug() << "Database::saveDatabase() false ";
        emit SSaveFailed();
    }
}


// close bd
