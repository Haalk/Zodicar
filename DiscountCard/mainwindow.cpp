#include "mainwindow.h"

#include "Helper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_loadManager(new LoadManager),m_accountManager(new AccountManager),
      m_menuBar(new MenuBar), m_newClient(new NewClient),m_buttons(new Buttons),m_databaseView(new DatabaseView),
      m_editMode(new EditMode(*m_buttons)),m_scanManager(new ScanManager)
{
    setWindowIcon(QIcon(QPixmap(":/img/discountCard.png")));
}

MainWindow::~MainWindow()
{
    delete m_loadManager;
    delete m_accountManager;
    delete m_menuBar;
    delete m_newClient;
    delete m_buttons;
    delete m_databaseView;
    delete m_editMode;
    delete m_scanManager;
}

void MainWindow::show()
{
   setMenuBar(m_menuBar->getMenuBar());
   this->QMainWindow::show();
}

int MainWindow::Init()
{
    qDebug("MainWindow::Init()");



    m_menuBar->Init();
    m_newClient->Init();
    Database::Instance()->Init();
    m_databaseView->Init();
    m_buttons->Init();
    m_scanManager->Init();
    init();
    m_accountManager->Init();
    m_accountManager->Show();     //delete after comment

    //show();                         //delete this call


    qDebug("MainWindow::Init() end");

    return 1;
}


#include <QSqlRecord>
int MainWindow::init()
{
   qDebug("MainWindow::init()");

   QRect rect = (QApplication::desktop()->screenGeometry());
   resize(rect.width(),rect.height());

   //m_BaddClient = new QPushButton("New Client");


   initLayout();
   connecting();

   qDebug("MainWindow::Init() end");
   return 1;
}

void MainWindow::connecting()
{
    connect(m_loadManager,&LoadManager::SFinished,this,&MainWindow::loadFinished);
    connect(m_accountManager,&AccountManager::SAuthorizationSuccess,m_loadManager,&LoadManager::StartLoad);
    connect(m_buttons->getButton(NButtonsName::NewClient),&QPushButton::clicked,m_newClient,&NewClient::Show);
    connect(m_newClient,&NewClient::SaddedNewClient,m_databaseView,&DatabaseView::Update);
    connect(m_buttons->getButton(NButtonsName::Save),&QPushButton::clicked,Database::Instance(),&Database::saveDatabase);
    connect(m_editMode,&EditMode::SEditMode,m_databaseView,&DatabaseView::EnableChange);
    connect(m_buttons->getButton(NButtonsName::Edit),&QPushButton::clicked,m_editMode,&EditMode::setEditMode);
    connect(m_editMode,&EditMode::SEditMode,m_databaseView,&DatabaseView::discardChanges);
    connect(m_databaseView->getModel(),&QAbstractItemModel::dataChanged,m_editMode,&EditMode::SlotDataChanged);
    connect(Database::Instance(),&Database::SSaveSuccess,m_editMode,&EditMode::SlotCancel);
    connect(Database::Instance(),&Database::SSaveFailed,m_editMode,&EditMode::saveFailed);
    connect(m_databaseView->getDatabaseTableView(),&QAbstractItemView::doubleClicked,m_editMode,&EditMode::SlotEditBox);
    connect(m_editMode,&EditMode::SCheckRequirements,Database::Instance(),&Database::SlotCheckRequirement);
    connect(Database::Instance(),&Database::SRequirementCorrect,m_databaseView,&DatabaseView::ApplyChanged);
    //connect(m_databaseView,&DatabaseView::SButtonShow,m_buttons,&Buttons::setEnableButton);//setEnableButtonShow);
    connect(m_buttons->getButton(NButtonsName::ShowDatabase),&QPushButton::clicked,m_databaseView,&DatabaseView::showDatabase);
    //connect(m_buttons->getButton(NButtonsName::Edit),&QPushButton::clicked,m_buttons,&Buttons::setEnableButton);
    connect(m_buttons->getButton(NButtonsName::Scan),&QPushButton::clicked,m_scanManager,&ScanManager::showScanWindow);
}

void MainWindow::initLayout()
{
    QHBoxLayout * hlayout1 = new QHBoxLayout;
    QHBoxLayout * hlayout2 = new QHBoxLayout;
    QHBoxLayout * hlayout3 = new QHBoxLayout;
    QHBoxLayout * hlayout4 = new QHBoxLayout;
    QVBoxLayout * vlayout1 = new QVBoxLayout;
    QVBoxLayout * vlayout2 = new QVBoxLayout;

    hlayout1->addWidget(m_buttons->getButton(NButtonsName::NewClient));
    hlayout1->addWidget(m_buttons->getButton(NButtonsName::Scan));
    hlayout2->addWidget(m_buttons->getButton(NButtonsName::Edit));
    hlayout2->addWidget(m_buttons->getButton(NButtonsName::Cancel));
    hlayout2->addWidget(m_buttons->getButton(NButtonsName::Save));
    hlayout3->addWidget(m_buttons->getButton(NButtonsName::Delete));
    hlayout3->addWidget(m_buttons->getButton(NButtonsName::Select));
    hlayout4->addWidget(m_buttons->getButton(NButtonsName::ShowDatabase));

    vlayout2->addItem(hlayout1);
    vlayout2->addItem(hlayout2);
    vlayout2->addItem(hlayout3);
    vlayout2->addItem(hlayout4);

    vlayout1->addWidget(m_databaseView->getDatabaseTableView());

    QWidget *central = new QWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addItem(vlayout2);
    mainLayout->addItem(vlayout1);

    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void MainWindow::loadFinished(bool isFinished)
{
    qDebug("loadFinished");
    if(!isFinished)
    {
        return;
    }

    show();
}
