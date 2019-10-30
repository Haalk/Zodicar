#include "currentclient.h"
#include "database.h"

CurrentClient::CurrentClient(QWidget *parent) : QWidget(parent)
{

}



void CurrentClient::showClient(const QString &what,const QString &value)
{
   fillFieldValue(what,value);

   for(int i = 0;i < m_countField; ++i)
   {
       labelsLayout[i].addWidget(new QLabel(mv_label[m_fieldNames[i]],this));
   }
}

void CurrentClient::Init()
{
    qDebug() << "CurrentClient::Init()";
    m_countField = Database::Instance()->getModel()->columnCount();
    m_layout = new QVBoxLayout;
    m_fieldNames.clear();
    m_fieldNames.resize(0);
    labelsLayout = new QHBoxLayout[m_countField];
    QVBoxLayout *temp_lay = new QVBoxLayout;
    QWidget * temp_widget = new QWidget;
    for(int i = 0; i < m_countField; ++i)
    {
        m_fieldNames.push_back(Database::Instance()->getRecordName(i));
        mv_label[m_fieldNames.last()] = "";
        labelsLayout[i].addWidget(new QLabel(m_fieldNames.last()));
        temp_lay->addItem(&labelsLayout[i]);
    }
    temp_widget->setFixedWidth(300);
    temp_widget->setLayout(temp_lay);
    m_layout->addWidget(temp_widget);


}

QVBoxLayout *CurrentClient::getLayout()
{
    return m_layout;
}

void CurrentClient::fillFieldValue(const QString &what, const QString &value)
{
    qDebug() << "fillFieldValue what = " + what + " and value = " + value;
    QSqlQuery query;
    query.exec("SELECT * FROM " + NAME_TABLE + " WHERE " + what + " = " + value);
    query.next();
    qDebug() << "SELECT * FROM " + NAME_TABLE + " WHERE " + what + " = " + value;

    for(int i = 0;i<m_countField;++i)
    {
         qDebug() << mv_label[Database::Instance()->getRecordName(i)] + " " + query.value(i).toString();
         mv_label[Database::Instance()->getRecordName(i)] = query.value(i).toString();
    }

    qDebug() << "CurrentClient::fillFieldValue simu" + mv_label["SURNAME"];
}
