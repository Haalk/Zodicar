#ifndef CURRENTCLIENT_H
#define CURRENTCLIENT_H
#include "Helper.h"
#include <QWidget>

class CurrentClient : public QWidget
{
    Q_OBJECT
public:
    explicit CurrentClient(QWidget *parent = nullptr);
    void showClient(const QString &what,const QString &value);
    void Init();

    QVBoxLayout * getLayout();
private:
    QVBoxLayout *m_layout;
    QMap<QString,QString> mv_label;
    QVector<QString> m_fieldNames;
    QHBoxLayout *labelsLayout;
    int m_countField;
private:
    void fillFieldValue(const QString &what,const QString &value);
signals:

public slots:
};

#endif // CURRENTCLIENT_H
