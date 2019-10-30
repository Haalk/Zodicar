#include "newclient.h"
#include "database.h"

NewClient::NewClient()
{

}

NewClient::~NewClient()
{
    delete m_Lname;
    delete m_Lsurname;
    delete m_Lphone;
    delete m_LidCard;
    delete m_Badd;
    delete m_Bcancel;
    delete m_lineName;
    delete m_linePhone;
    delete m_lineSurname;
    delete m_lineCard;
    delete m_dialog;
}

void NewClient::Init()
{
    m_Lname = new QLabel("Name: ");
    m_Lsurname = new QLabel("Surname: ");
    m_Lphone = new QLabel("Phone :");
    m_LidCard = new QLabel("Card: ");
    m_Badd = new QPushButton("Add");
    m_Bcancel = new QPushButton("Cancel");
    m_lineName = new QLineEdit;
    m_linePhone = new QLineEdit;
    m_lineSurname = new QLineEdit;
    m_lineCard = new QLineEdit;
    m_dialog = new QDialog;

    m_Badd->setEnabled(false);

    m_lineName->setValidator(new QRegExpValidator   ( QRegExp("[a-zA-Z]{5,20}"),this));
    m_lineSurname->setValidator(new QRegExpValidator( QRegExp("[a-zA-Z]{5,20}"),this));
    m_linePhone->setValidator(new QRegExpValidator  ( QRegExp("[0-9]{10}"),this));
    m_lineCard->setValidator(new QRegExpValidator  ( QRegExp("[0-9]{10}"),this));


    QHBoxLayout *layoutName = new QHBoxLayout;
    layoutName->addWidget(m_Lname);
    layoutName->addWidget(m_lineName);

    QHBoxLayout *layoutSurname = new QHBoxLayout;
    layoutSurname->addWidget(m_Lsurname);
    layoutSurname->addWidget(m_lineSurname);

    QHBoxLayout *layoutPhone = new QHBoxLayout;
    layoutPhone->addWidget(m_Lphone);
    layoutPhone->addWidget(m_linePhone);

    QHBoxLayout *layoutCard = new QHBoxLayout;
    layoutCard->addWidget(m_LidCard);
    layoutCard->addWidget(m_lineCard);

    QHBoxLayout *layoutButton = new QHBoxLayout;
    layoutButton->addWidget(m_Badd);
    layoutButton->addWidget(m_Bcancel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addItem(layoutName);
    layout->addItem(layoutSurname);
    layout->addItem(layoutPhone);
    layout->addItem(layoutCard);
    layout->addItem(layoutButton);

    m_dialog->setLayout(layout);

    connect(m_Bcancel,&QPushButton::clicked,this,&NewClient::buttonClickedCancel);
    connect(m_Badd,&QPushButton::clicked,this,&NewClient::buttonClickedAdd);
    connect(m_lineCard,&QLineEdit::textChanged,this,&NewClient::checkLine);
    connect(m_lineName,&QLineEdit::textChanged,this,&NewClient::checkLine);
    connect(m_lineSurname,&QLineEdit::textChanged,this,&NewClient::checkLine);
    connect(m_linePhone,&QLineEdit::textChanged,this,&NewClient::checkLine);
}

void NewClient::Show()
{
    m_dialog->exec();
}

void NewClient::buttonClickedAdd()
{
    const QString& card = m_lineCard->text();
    const QString& phone = m_linePhone->text();
    if(card.length() < CARD_SIZE || phone.length() < PHONE_SIZE)
    {
        showNotAvailableAdd();
        return;
    }
    qDebug () << "buttonClickedAdd card = " + card + " , phone = " + phone;
    if(Database::Instance()->isEnabled(card,phone))
    {
        if(Database::Instance()->addToDatabase(m_lineName->text(),m_lineSurname->text(),m_lineCard->text(),m_linePhone->text()))
        {
            qDebug() << "showSuccessAdd()";
            this->showSuccessAdd();
            emit SaddedNewClient() ;
        }
        else
        {
            qDebug() << "addToDatabase() return false";
        }
    }
    else
    {
        showNotAvailableAdd();
    }
}

void NewClient::checkLine()
{
    if(m_lineCard->hasAcceptableInput() && m_linePhone->hasAcceptableInput()
            && m_lineSurname->hasAcceptableInput() && m_lineName->hasAcceptableInput() && m_lineCard->hasAcceptableInput())
    {
        m_Badd->setEnabled(true);
    }
    else
    {
        m_Badd->setEnabled(false);
    }
}

void NewClient::dialogReject()
{
    m_lineName->clear();
    m_lineSurname->clear();
    m_linePhone->clear();
    m_lineCard->clear();
    m_dialog->close();
}

void NewClient::showSuccessAdd()
{
    QDialog * success = new QDialog(this);
    QLabel *label = new QLabel("Success new card");
    QVBoxLayout * layout = new QVBoxLayout(this);
    QPushButton * m_buttonOk = new QPushButton("OK",this);
    connect(m_buttonOk,&QPushButton::clicked,success,&QDialog::close);
    m_buttonOk->setShortcut(QKeySequence(Qt::Key::Key_Return));
    m_buttonOk->setDefault(true);
    layout->addWidget(label);
    layout->addWidget(m_buttonOk);
    success->setLayout(layout);
    success->resize(128,128);

    int isDialog = success->exec();

    if(isDialog == QDialog::Rejected)
    {
        dialogReject();
    }
}

void NewClient::showNotAvailableAdd()
{
    QDialog * success = new QDialog(this);
    QLabel *label = new QLabel("Impossible to add new client!\nUncorrect data. Last error\n" + Database::Instance()->lastError() + "\nCheck and try again!");
    QVBoxLayout * layout = new QVBoxLayout(this);
    QPushButton * m_buttonOk = new QPushButton("OK",this);
    connect(m_buttonOk,&QPushButton::clicked,success,&QDialog::close);
    m_buttonOk->setShortcut(QKeySequence(Qt::Key::Key_Return));
    m_buttonOk->setDefault(true);
    layout->addWidget(label);
    layout->addWidget(m_buttonOk);
    success->setLayout(layout);
    success->resize(128,128);

    success->exec();
}

const QString NewClient::setCorrectCard(const QString &card)
{
    return card;
    QString id = card;
    if(id.size() > CARD_SIZE)
    {
        return id;
    }

}

void NewClient::buttonClickedCancel()
{
     m_lineName->clear();
     m_lineSurname->clear();
     m_linePhone->clear();
     m_lineCard->clear();
     m_dialog->close();
}


