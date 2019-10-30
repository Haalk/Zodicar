#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QWidget>
class Authorization;
class AddAccount;

class AccountManager : public QWidget
{
    Q_OBJECT
public:
    AccountManager(QWidget * parent = nullptr);
    ~AccountManager();

    void Init();
    void Show();
public:

private:
    Authorization * m_authorization;
    AddAccount  *   m_addAccount;
private:
    void checkInput(bool isCorrect);
signals:
    void SAuthorizationSuccess(bool);
private slots:
    void AuthorizedSuccess(bool flag);
};

#endif // ACCOUNTMANAGER_H
