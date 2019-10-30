#include "editmode.h"
#include "Helper.h"

EditMode::EditMode(Buttons &buttons, QWidget *parent) : QWidget(parent), r_buttons(buttons),isEditMode(false)
{
    connecting();
}

void EditMode::setEditMode()
{
    r_buttons.getButton(NButtonsName::NewClient)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Edit)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Save)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Cancel)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Delete)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Select)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Scan)->setEnabled(false);
    isEditMode = true;
    emit SEditMode(true);
}

void EditMode::SlotDataChanged()
{
    r_buttons.getButton(NButtonsName::Save)->setEnabled(true);
}

void EditMode::SlotEditBox(const QModelIndex &index)
{
    if(!isEditMode)
    {
        return;
    }
    const QAbstractItemModel *model = index.model();
    QString value = index.model()->data(model->index(index.row(),index.column())).toString();
    qDebug() << value;// (model->index(i, index.column()).toString());

    QDialog *dialog = new QDialog;
    QLineEdit lineEdit;// = new QLineEdit;
    QVBoxLayout *layout_t = new QVBoxLayout;
    QPushButton buttonOk("Ok");
    QPushButton buttonCancel("Cancel");

    layout_t->addWidget(&lineEdit);
    dialog->setLayout(layout_t);
    lineEdit.setText(value);
    dialog->exec();
    emit SCheckRequirements(lineEdit.text(),index);
}

void EditMode::connecting()
{
    connect(r_buttons.getButton(NButtonsName::Cancel),&QPushButton::clicked,this,&EditMode::SlotCancel);
}

bool EditMode::ApplyChanged(bool isApply)
{
    if(isApply)
    {

    }

    return false;
}

void EditMode::SlotCancel()
{
    qDebug() << "EditMode::SlotCancel()";
    r_buttons.getButton(NButtonsName::NewClient)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Edit)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Save)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Cancel)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Scan)->setEnabled(true);
    r_buttons.getButton(NButtonsName::Delete)->setEnabled(false);
    r_buttons.getButton(NButtonsName::Select)->setEnabled(false);
    isEditMode = false;
    emit SEditMode(false);
}

void EditMode::saveFailed()
{
    QMessageBox msgBox(QMessageBox::Warning,"Error to save data","Failed to save.\nIncorrect data entered",
                       QMessageBox::StandardButton::Close|QMessageBox::StandardButton::Discard|QMessageBox::StandardButton::Cancel);
    int button = msgBox.exec();
    switch (button)
    {
        case QMessageBox::StandardButton::Cancel:   SlotCancel() ;                                break;
        case QMessageBox::StandardButton::Discard:  emit SEditMode(false); emit SEditMode(true);
                                  r_buttons.getButton(NButtonsName::Save)->setEnabled(false);     break;
        case QMessageBox::StandardButton::Close:
        default:    ;
    }
}
