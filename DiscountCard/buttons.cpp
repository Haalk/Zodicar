#include "buttons.h"
#include "newclient.h"
#include "Helper.h"
Buttons::Buttons(QWidget * parent) : QWidget(parent)
{
    m_addNewClientButton = new QPushButton;
    m_cancelClientButton = new QPushButton;
    m_editButton = new QPushButton;
    m_saveButton = new QPushButton;
    m_deleteButton = new QPushButton;
    m_selectButton = new QPushButton;
    m_scanButton = new QPushButton;
    m_showDatabaseButton = new QPushButton;
}

Buttons::~Buttons()
{
    delete m_addNewClientButton;
    delete m_cancelClientButton;
    delete m_editButton;
    delete m_saveButton;
    delete m_deleteButton;
    delete m_selectButton;
    delete m_scanButton;
    delete m_showDatabaseButton;
}

QPushButton *Buttons::getButton(const QString &nameButton)
{
    if(nameButton == NButtonsName::NewClient)
    {
        return m_addNewClientButton;
    }
    if(nameButton == NButtonsName::Cancel)
    {
        return m_cancelClientButton;
    }
    if(nameButton == NButtonsName::Edit)
    {
        return m_editButton;
    }
    if(nameButton == NButtonsName::Save)
    {
        return m_saveButton;
    }
    if(nameButton == NButtonsName::Delete)
    {
        return m_deleteButton;
    }
    if(nameButton == NButtonsName::Select)
    {
        return m_selectButton;
    }
    if(nameButton == NButtonsName::Scan)
    {
        return m_scanButton;
    }
    if(nameButton == NButtonsName::ShowDatabase)
    {
        return m_showDatabaseButton;
    }

    return nullptr;
}

void Buttons::Init()
{
    m_addNewClientButton->setText("New Client");
    m_cancelClientButton->setText("Cancel");
    m_editButton->setText("Edit");
    m_saveButton->setText("Save");
    m_deleteButton->setText("TO DO Delete");
    m_selectButton->setText("TO DO Select");
    m_scanButton->setText("TO DOD Scan");
    m_showDatabaseButton->setText("TO DO Show Database");

    m_editButton->setEnabled(false);
    m_saveButton->setEnabled(false);
    m_cancelClientButton->setEnabled(false);
    m_deleteButton->setEnabled(false);
    m_selectButton->setEnabled(false);
    m_scanButton->setEnabled(true);
    m_showDatabaseButton->setEnabled(true);

    connecting();
}

void Buttons::setEnableButton(/*QPushButton &button ,*/const bool isEnable)
{
    QPushButton *button_t = qobject_cast<QPushButton*>(sender());
    if(button_t == m_showDatabaseButton)
    {
        qDebug() << "DatabaseView::setEnableButton m_editButton and isEnable = " + QString::number(isEnable);
        m_editButton->setEnabled(!m_editButton->isEnabled());
        if(m_editButton->isEnabled())
        {
             m_showDatabaseButton->setText("Hide Database");
        }
        else
        {
             m_showDatabaseButton->setText("Show Database");
        }
    }
//    qDebug() << "DatabaseView::setEnableButton " + QString::number(isEnable);
//    if(isEnable)
//    {
//        button.setEnabled(true);
//    }
//    else
//    {
//        button.setEnabled(false);
//    }
}

void Buttons::setEnableButtonShow(const bool isEnable)
{
//    qDebug() << "DatabaseView::showDatabase " + QString::number(isEnable);
//    if(isEnable)
//    {
//         m_showDatabaseButton->setText("Hide Database");
//    }
//    else
//    {
//         m_showDatabaseButton->setText("Show Database");
//    }
}

void Buttons::connecting()
{
    connect(m_showDatabaseButton,&QPushButton::clicked,this,&Buttons::setEnableButton);
}
