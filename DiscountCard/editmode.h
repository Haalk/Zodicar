#ifndef EDITMODE_H
#define EDITMODE_H

#include <QWidget>
#include "buttons.h"
#include <QModelIndex>

class EditMode : public QWidget
{
    Q_OBJECT
public:
    EditMode(Buttons& buttons,QWidget *parent = nullptr);

    void setEditMode();
    void saveFailed();
    bool ApplyChanged(bool isApply);
private:
    Buttons & r_buttons;
    bool isEditMode;
private:
    void connecting();
public slots:
    void SlotCancel();
    void SlotDataChanged();
    void SlotEditBox(const QModelIndex &index);
signals:
    void SEditMode(bool isEditMode);
    void SCheckRequirements(QString value,const QModelIndex& modelIndex);//const QString &columnName);
};

#endif // EDITMODE_H
