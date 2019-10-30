#ifndef BUTTONS_H
#define BUTTONS_H
#include <QPushButton>


class Buttons : public QWidget
{
    Q_OBJECT
public:
    Buttons(QWidget * parent = nullptr);
    ~Buttons();

public:
    QPushButton * getButton(const QString& nameButton);
    void Init();

    void setEnableButton(/*QPushButton &button ,*/const bool isEnable);
public slots:
    void setEnableButtonShow(const bool isEnable);
private:
    QPushButton *m_addNewClientButton;
    QPushButton *m_cancelClientButton;
    QPushButton *m_editButton;
    QPushButton *m_saveButton;
    QPushButton *m_deleteButton;
    QPushButton *m_selectButton;
    QPushButton *m_scanButton;
    QPushButton *m_showDatabaseButton;
private:
    void connecting();

};

#endif // BUTTONS_H
