#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Authorization : public QWidget
{
    Q_OBJECT
public:
    Authorization(QWidget *parent = nullptr);
    ~Authorization();
    void Show();
    void Init();
signals :
    void SAuthorizationSuccess(bool);
    void SAddNewAccount();
private slots:
    void Check();
    void checkLineEdit();
    void SNewAccount();
private:
    QLineEdit lineEditLogin;
    QLineEdit lineEditPass;
    QPushButton *buttonLogin;
    QPushButton *buttonExit;
    QPushButton *buttonAdd;
    bool m_AuthorizationSuccess;
    QString accountName;
private:
    void keyPressEvent(QKeyEvent *keyEvent);
    bool JsonAuthorized(const QString& pass);
    bool findValueFromJsonArray(QJsonArray array,const QString & key, const QString & val);
};

#endif // AUTHORIZATION_H
