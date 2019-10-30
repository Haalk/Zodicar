#include "menubar.h"
#include "Helper.h"
#include <QMenuBar>
#include <QMenu>

MenuBar::MenuBar(QMenuBar *parent):QMenuBar(parent)
{
    m_menuBar = new QMenuBar;
    //newClient = new NewClient;
}

MenuBar::~MenuBar()
{
    delete m_menuBar;
}

void MenuBar::Init()
{
    QMenu *menuFile = new QMenu("File");
    menuFile->addAction("Action");
    menuFile->addSeparator();
    menuFile->addMenu("SubMenu");

    QMenu *menuAbout = new QMenu("About");
    QAction *about = new QAction("About2");
    menuAbout->addAction(about);


    m_menuBar->addMenu(menuFile);
    m_menuBar->addMenu(menuAbout);
    m_menuBar->addAction(about);

    //newClient->Init();
    //connect(about,&QAction::triggered,newClient,&NewClient::Show);
}
