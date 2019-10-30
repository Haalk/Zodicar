#include "addaccount.h"
#include <QDir>

AddAccount::AddAccount(QWidget *parent):QWidget(parent),m_dialogAddAccount(new QDialog(this))
{

}

AddAccount::~AddAccount()
{
    delete m_BCreate;
    delete m_BClose;
    delete m_Llogin;
    delete m_Lpass;
    delete m_lineLogin;
    delete m_linePass;
}

void AddAccount::Show()
{
    connect(m_BClose,&QPushButton::clicked,m_dialogAddAccount,&QDialog::close);
    m_dialogAddAccount->exec();
}

void AddAccount::Init()
{
    m_BCreate = new QPushButton("Create",this);
    m_BClose = new QPushButton("Close",this);

    m_Llogin = new QLabel("Login:",this);
    m_Lpass = new QLabel("Password:",this);

    m_lineLogin = new QLineEdit;
    m_linePass = new QLineEdit;

    QRegExp exp("[a-zA-Z]{5,20}");
    m_lineLogin->setValidator(new QRegExpValidator(exp,this));

    m_linePass->setMaxLength(20);
//  m_linePass->setValidator(new QRegExpValidator(QRegExp("{5-20}"),this));

    m_dialogAddAccount->resize(QApplication::desktop()->screenGeometry().width()/9,QApplication::desktop()->screenGeometry().width()/16);
    m_dialogAddAccount->setWindowIcon(QIcon(QPixmap(":/img/discountCard.png")));

    QHBoxLayout *layLogin = new QHBoxLayout;
    layLogin->addWidget(m_Llogin);
    layLogin->addWidget(m_lineLogin);

    QHBoxLayout *layPass = new QHBoxLayout;
    layPass->addWidget(m_Lpass);
    layPass->addWidget(m_linePass);

    QVBoxLayout *layData = new QVBoxLayout;
    layData->addItem(layLogin);
    layData->addItem(layPass);

    QVBoxLayout *layButton = new QVBoxLayout;
    layButton->addWidget(m_BCreate);
    layButton->addWidget(m_BClose);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addItem(layData);
    layout->addItem(layButton);

    m_dialogAddAccount->setLayout(layout);

    m_BCreate->setShortcut(Qt::Key::Key_Return);

    connect(m_lineLogin,&QLineEdit::textChanged,this,&AddAccount::checkButton);
    connect(m_linePass,&QLineEdit::textChanged,this,&AddAccount::checkButton);
    connect(m_lineLogin,&QLineEdit::returnPressed,m_BCreate,&QPushButton::click);
    connect(m_linePass,&QLineEdit::returnPressed,m_BCreate,&QPushButton::click);

    m_BCreate->setEnabled(false);

    connect(m_BCreate,&QPushButton::clicked,this,&AddAccount::checkConditiontoAdd);
}


bool AddAccount::addNewAccount()
{
    qDebug("AddAccount::addNewAccount");
    QCoreApplication::applicationDirPath();
    QString str = QCoreApplication::applicationDirPath();
    QString fileName = "/accounts.json";
    QString pathFile = QDir::toNativeSeparators(QString(str + fileName));
    qDebug(pathFile.toStdString().c_str());
    QFile file(pathFile);
    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this,"ERROR!","ERROR ACCOUNTS!");
        return false;
    }
    QByteArray saveData = file.readAll();
    QJsonDocument document(QJsonDocument::fromJson(saveData));
    QJsonObject root = document.object();
    qDebug("AddAccount::JsonAuthorized 1");

//    QJsonValueRef ArrayRef = root.find("accounts").value();
//    QJsonArray Array = ArrayRef.toArray();

//    QJsonArray::iterator ArrayIterator = Array.begin();
//    QJsonValueRef ElementsOneValueRef = ArrayIterator[0];

//    QJsonObject ElementOneObject = ElementsOneValueRef.toObject();

//    ElementOneObject["login"] = m_lineLogin->text();
//    ElementOneObject["password"] = m_linePass->text();

//    ElementsOneValueRef = ElementOneObject;
//    ArrayRef = Array;
//    document.setObject(root);

//    if(file.write(document.toJson(QJsonDocument::Indented)))
//    {
//        m_lineLogin->clear();
//        m_linePass->clear();
//        close();
//        return true;
//    }
//-------------------------------

//    QJsonArray array = root["accounts"].toArray();

//    if(!array.size())
//    {
//        return false;
//    }

//    QJsonObject object;
//    object["login"] = m_lineLogin->text();
//    object["password"] = m_linePass->text();

//    array.append(object);

//    root["accounts"] = array;
//    qDebug("HERE ?");
//    file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));

    qDebug("AddAccount::addNewAccount end");

    return true;
}

void AddAccount::keyPressEvent(QKeyEvent *keyEvent)         // TO DO. DOES NOT WORK
{
    qDebug("AddAccount::keyEvent");
    if(keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
    {
        if(m_BClose->hasFocus())
        {
            qDebug("AddAccount focus buttonLogin");
            m_BClose->click();
            return;
        }
        if(m_BCreate->hasFocus())
        {
            qDebug("AddAccount focus buttonExit");

            return;
        }
    }
}

bool AddAccount::checkConditiontoAdd()
{
    if(!JsonAuthorized("login",m_lineLogin->text()))
    {
        addNewAccount();
    }
    return false;
}

void AddAccount::checkButton()
{
    if(m_lineLogin->hasAcceptableInput() && m_linePass->text().size() >= 5)
    {
        m_BCreate->setEnabled(true);
    }
    else
    {
        m_BCreate->setEnabled(false);
    }
}

bool AddAccount::findValueFromJsonArray(QJsonArray array,const QString & key, const QString & val)
{
    qDebug("AddAccount::findValueFromJsonArray");
    for(const auto obj : array)
    {
        //qDebug("val = %i",val.toStdString().c_str());
        if(obj.toObject().value(key).toString() == val)
        {
            qDebug("SUCCESS ACCOUNT");
            return true;
        }
    }
    return false;
}

bool AddAccount::JsonAuthorized(const QString& key, const QString& val )
{
    qDebug("AddAccount::JsonAuthorized");
    QFile file(":/src/accounts.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"ERROR!","ERROR ACCOUNTS!");
        return false;
    }
    QByteArray saveData = file.readAll();
    QJsonDocument document(QJsonDocument::fromJson(saveData));
    QJsonObject obj = document.object();
    qDebug("AddAccount::JsonAuthorized 1");
    QJsonArray array = obj["accounts"].toArray();

    if(!array.size())
    {
        return false;
    }

    return findValueFromJsonArray(array,key,val);
}
