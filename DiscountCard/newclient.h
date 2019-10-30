#ifndef NEWCLIENT_H
#define NEWCLIENT_H

#include <QWidget>
#include "Helper.h"

class NewClient : public QWidget
{
    Q_OBJECT
public:
    NewClient();
    ~NewClient();

    void Init();
    void Show();

private:
    QDialog *   m_dialog;
    QLabel  *   m_Lname;
    QLabel  *   m_Lphone;
    QLabel  *   m_Lsurname;
    QLabel  *   m_LidCard;
    QPushButton * m_Badd;
    QPushButton * m_Bcancel;
    QLineEdit   * m_lineName;
    QLineEdit   * m_linePhone;
    QLineEdit   * m_lineSurname;
    QLineEdit   * m_lineCard;
private:
    void buttonClickedCancel();
    void buttonClickedAdd();
    void checkLine();
    void dialogReject();
    void showSuccessAdd();
    void showNotAvailableAdd();
    const QString setCorrectCard(const QString& card);
signals:
    void SaddedNewClient();
};


#endif // NEWCLIENT_H
