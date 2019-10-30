#include "scanmanager.h"
#include "Helper.h"
#include <QRadioButton>

ScanManager::ScanManager(QWidget *parent) : QWidget(parent)
{

}

ScanManager::~ScanManager()
{
    delete m_dialog;
//    delete m_numberLabel;
//    delete m_lineInput;
//    delete m_inputLayout;
//    delete m_radioLayout;
//    delete m_radioButtonCard;
//    delete m_radioButtonPhone;
//    delete m_buttonScan;
//    delete m_choiceLayout;
//    delete m_mainLayout;
}

void ScanManager::showScanWindow()
{
    m_dialog->exec();

}

void ScanManager::Init()
{
    m_dialog = new QDialog;

    m_numberLabel  = new QLabel("Enter identificator:");
    m_lineInput = new QLineEdit;
    m_lineInput->setValidator(new QRegExpValidator  ( QRegExp("[0-9]{10}"),this));

    m_inputLayout = new QHBoxLayout;
    m_inputLayout->addWidget(m_numberLabel);
    m_inputLayout->addWidget(m_lineInput);

    m_radioLayout = new QVBoxLayout;
    m_radioButtonCard = new QRadioButton("Card number");
    m_radioButtonPhone = new QRadioButton("Phone number");
    m_radioLayout->addWidget(m_radioButtonCard);
    m_radioLayout->addWidget(m_radioButtonPhone);
    m_radioButtonCard->setChecked(true);

    m_buttonScan = new QPushButton("Scan");
    m_buttonScan->setEnabled(false);

    m_choiceLayout = new QHBoxLayout;
    m_choiceLayout->addItem(m_inputLayout);
    m_choiceLayout->addItem(m_radioLayout);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addItem(m_choiceLayout);
    m_mainLayout->addWidget(m_buttonScan);

    m_dialog->setLayout(m_mainLayout);

    connection();

}

void ScanManager::connection()
{
    connect(m_buttonScan,&QPushButton::clicked,this,&ScanManager::checkScan);
    connect(m_lineInput,&QLineEdit::textChanged,this,&ScanManager::checkCorrectInput);
}

bool ScanManager::checkCorrectInput()
{
    if(m_lineInput->hasAcceptableInput())
    {
        m_buttonScan->setEnabled(true);
    }
    else
    {
        m_buttonScan->setEnabled(false);
    }

    return true;    //
}
#include "database.h"
bool ScanManager::checkScan()
{
    QString what = m_radioButtonCard->isChecked() ? "ID" : m_radioButtonPhone ? "PHONE" : "ERROR";
    if(what == "ERROR")
    {
        return false;
    }
    bool isFound = !Database::Instance()->isAvailable(what,what,m_lineInput->text());
    qDebug() << "ScanManager::checkScan()" + QString::number(isFound);
    return isFound;
}
