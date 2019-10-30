#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QWidget>
#include "Helper.h"

class AddAccount : public QWidget
{
    Q_OBJECT
public:
    AddAccount(QWidget *parent = nullptr);
    ~AddAccount();

    void Show();
    void Init();
private:
    QDialog * m_dialogAddAccount;
    QPushButton *m_BCreate;
    QPushButton *m_BClose;
    QLabel      *m_Llogin;
    QLabel      *m_Lpass;
    QLineEdit   *m_lineLogin;
    QLineEdit   *m_linePass;
private:
    bool addNewAccount();
    void keyPressEvent(QKeyEvent *keyEvent);
    bool checkConditiontoAdd();
    bool findValueFromJsonArray(QJsonArray array,const QString & key, const QString & val);
    bool JsonAuthorized(const QString& key, const QString& val);
private slots:
    void checkButton();
};

#endif // ADDACCOUNT_H
