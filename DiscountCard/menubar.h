#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
//#include "newclient.h"

class MenuBar : public QMenuBar
{
    Q_OBJECT;
public:
    MenuBar(QMenuBar *parent = nullptr);
    ~MenuBar();
    //void Show();
    QMenuBar * getMenuBar() {return m_menuBar;}
    void Init();
private:
    QMenuBar *m_menuBar;
    QMenu   *m_menu;

    //NewClient *newClient;
private:
    void createActions();
    void createMenus();
    void createActios();
};

#endif // MENUBAR_H
