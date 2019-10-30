#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <QWidget>

class Authorization;
class Splash;

class LoadManager : public QWidget
{
    Q_OBJECT
public:
    LoadManager(QWidget *parent = nullptr);
    ~LoadManager();
    void StartLoad();
private:
    void Init();
    void Show();
private:
    Authorization*   m_authorization;
    Splash*   m_splash;
private slots:
    void SlotFinished(bool);
signals:
    void SFinished(bool);
};

#endif // LOADMANAGER_H
