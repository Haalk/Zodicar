#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loadmanager.h"
#include "accountmanager.h"
#include "menubar.h"
#include "newclient.h"
#include <QMainWindow>
#include "database.h"
#include "buttons.h"
#include "databaseview.h"
#include "editmode.h"
#include "scanmanager.h"

class Authorization;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void show();

    int Init();

private:
    LoadManager *m_loadManager;
    AccountManager *m_accountManager;
    MenuBar *m_menuBar;
    NewClient *m_newClient;
    DatabaseView *m_databaseView;
    Buttons *m_buttons;
    EditMode *m_editMode;
    ScanManager *m_scanManager;
private:
    int init();

    void connecting();
    void initLayout();

public slots:
    void loadFinished(bool isFinished);
};
#endif // MAINWINDOW_H
