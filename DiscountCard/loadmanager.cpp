#include "loadmanager.h"
#include "authorization.h"
#include "splash.h"
#include "Helper.h"

LoadManager::~LoadManager()
{
    //delete m_authorization;
    delete m_splash;
}

LoadManager::LoadManager(QWidget *parent) : QWidget(parent)
{

}

void LoadManager::StartLoad()
{
    qDebug("LoadManager::StartLoad()");
    //m_authorization = new Authorization;
    m_splash = new Splash;

    //m_authorization->Init();
    //m_authorization->Show();
    connect(m_splash,&Splash::SFinished,this,&LoadManager::SlotFinished);
    m_splash->Init();

    m_splash->Show();
    //connect(m_authorization,&Authorization::SAuthorizationSuccess,m_splash,&Splash::slotShow);


    qDebug("LoadManager::StartLoad() end");
}

void LoadManager::SlotFinished(bool isFinished)
{
    qDebug("LoadManager::SlotFinished");
    if(isFinished)
    {
        emit SFinished(true);
    }
}
