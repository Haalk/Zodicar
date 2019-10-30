#ifndef SCANMANAGER_H
#define SCANMANAGER_H
#include <QWidget>
#include "Helper.h"
#include <QRadioButton>

class ScanManager : public QWidget
{
    Q_OBJECT
public:
    explicit ScanManager(QWidget *parent = nullptr);
    ~ScanManager();

    void showScanWindow();
    void Init();
private:
    QDialog *m_dialog;
    QLabel *m_numberLabel;
    QLineEdit *m_lineInput;
    QHBoxLayout * m_inputLayout;
    QVBoxLayout *m_radioLayout;
    QRadioButton *m_radioButtonCard;
    QRadioButton *m_radioButtonPhone;
    QPushButton *m_buttonScan;
    QHBoxLayout *m_choiceLayout;
    QVBoxLayout *m_mainLayout;

private:
    void connection();
    void checkCorrectInput();
    void checkScan();

signals:
    void SScanSuccessful(const QString &what,const QString &value);
public slots:
};

#endif // SCANMANAGER_H
