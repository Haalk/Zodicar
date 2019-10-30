#include "accountmanager.h"

#include "authorization.h"
#include "Helper.h"
#include "addaccount.h"

void AccountManager::Init()
{
    m_authorization->Init();
    m_addAccount->Init();
    connect(m_authorization,&Authorization::SAuthorizationSuccess,this,&AccountManager::AuthorizedSuccess);
    connect(m_authorization,&Authorization::SAddNewAccount,m_addAccount,&AddAccount::Show);
}

void AccountManager::Show()
{
    qDebug("Account::Show()");
    m_authorization->Show();
}

void AccountManager::checkInput(bool isCorrect)
{
    if(isCorrect)
    {

    }
}

AccountManager::AccountManager(QWidget *parent): QWidget(parent)
{
    m_authorization = new Authorization;
    m_addAccount = new AddAccount;
}

AccountManager::~AccountManager()
{
    delete m_authorization;
    delete m_addAccount;
}

void AccountManager::AuthorizedSuccess(bool flag)
{
    if(flag)
    {
        emit SAuthorizationSuccess(true);
    }
}

