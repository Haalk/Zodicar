#include "authorization.h"
#include "Helper.h"
#include "accountmanager.h"

Authorization::Authorization(QWidget *parent) : QWidget(parent), m_AuthorizationSuccess(false),accountName("none")
{
    setWindowIcon(QIcon(QPixmap(":/img/discountCard.png")));
}

Authorization::~Authorization()
{
    delete buttonLogin;
    delete buttonExit;
    delete buttonAdd;
}

void Authorization::Show()
{
    qDebug("Authorization::Show()");
    show();
}

void Authorization::Init()
{
    QLabel *login = new QLabel("Login");
    QLabel *pass = new QLabel("Password");

    buttonLogin = new QPushButton("Login");
    buttonExit = new QPushButton("Exit");
    buttonAdd = new QPushButton("Add new account");

    QHBoxLayout *layoutLogin = new QHBoxLayout;
    QHBoxLayout *layoutPass = new QHBoxLayout;
    QHBoxLayout *layoutButton = new QHBoxLayout;

    layoutLogin->addWidget(login);
    layoutLogin->addWidget(&lineEditLogin);
    layoutLogin->setSpacing(30);

    layoutPass->addWidget(pass);
    layoutPass->addWidget(&lineEditPass);
    layoutPass->setSpacing(9);

    layoutButton->addWidget(buttonLogin);
    layoutButton->addWidget(buttonExit);
    layoutButton->addWidget(buttonAdd);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addItem(layoutLogin);
    layout->addItem(layoutPass);
    layout->addItem(layoutButton);

    setLayout(layout);
    connect(buttonLogin,&QPushButton::clicked,this,&Authorization::Check);
    connect(buttonExit, &QPushButton::clicked,this,&QApplication::exit);
    connect(buttonAdd,  &QPushButton::clicked,this,&Authorization::SNewAccount);

    connect(&lineEditPass,&QLineEdit::returnPressed,buttonLogin,&QPushButton::click);
    connect(&lineEditLogin,&QLineEdit::returnPressed,buttonLogin,&QPushButton::click);

    connect(&lineEditPass,&QLineEdit::textChanged,this,&Authorization::checkLineEdit);
    connect(&lineEditLogin,&QLineEdit::textChanged,this,&Authorization::checkLineEdit);

    QRegExp exp("[a-zA-Z]{5,20}");
    lineEditLogin.setValidator(new QRegExpValidator(exp,this));

    lineEditPass.setMaxLength(20);

    buttonLogin->setShortcut(QKeySequence(Qt::Key::Key_Enter));

    buttonLogin->setEnabled(false);

    QRect size = QApplication::desktop()->screenGeometry();
    resize(size.width()/4,size.height()/3);

    lineEditPass.setEchoMode(QLineEdit::Password);
}
void Authorization::Check()
{
    bool isSuccess = false;
    accountName = lineEditLogin.text();
    isSuccess = JsonAuthorized(lineEditPass.text());

    close();                            //
    emit SAuthorizationSuccess(true);   //for fast test
    return;                             //

    if(isSuccess)
    {
        close();
        emit SAuthorizationSuccess(true);
    }
    else
    {
        QMessageBox *messageBox = new QMessageBox(QMessageBox::Critical,"Authorication FAILURE!","Not correct login or password\n"
            "          Try again!");
        messageBox->show();
        QIcon icon;
        icon.fromTheme("call-stop");
        messageBox->setWindowIcon(QIcon(QPixmap(":/img/iconExit.ico")));
    }
}

void Authorization::checkLineEdit()
{
    if(lineEditLogin.hasAcceptableInput())
    {
        buttonLogin->setEnabled(true);
    }
    else
    {
        buttonLogin->setEnabled(false);
    }
}

void Authorization::SNewAccount()
{
    qDebug("Authorization::SAddNewAccount()");
    emit SAddNewAccount();
}

void Authorization::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
    {
        if(buttonLogin->hasFocus())
        {
            qDebug("focus buttonLogin");
            buttonLogin->click();
            return;
        }
        if(buttonExit->hasFocus())
        {
            qDebug("focus buttonExit");
            buttonExit->click();
            return;
        }
        if(buttonAdd->hasFocus())
        {
            buttonAdd->click();
            return;
        }
    }
}

bool Authorization::findValueFromJsonArray(QJsonArray array,const QString & key, const QString & val)
{
    for(const auto obj : array)
    {
        //qDebug("val = %i",val.toStdString().c_str());
        if(obj.toObject().value(key).toString() == val && obj.toObject().value("login").toString() == accountName)
        {
            qDebug("SUCCESS ACCOUNT");
            return true;
        }
    }
    return false;
}

bool Authorization::JsonAuthorized(const QString& pass )
{
    QFile file(":/src/accounts.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"ERROR!","ERROR ACCOUNTS!");
        return false;
    }
    QByteArray saveData = file.readAll();
    QJsonDocument document(QJsonDocument::fromJson(saveData));
    QJsonObject obj = document.object();

    QJsonArray array = obj["accounts"].toArray();

    qDebug("arraySize = %i , accountName = %s , pass = %s ", array.size(),accountName.toStdString().c_str(),pass.toStdString().c_str());

    if(!array.size())
    {
        return false;
    }

    return findValueFromJsonArray(array,"password",pass);
}
