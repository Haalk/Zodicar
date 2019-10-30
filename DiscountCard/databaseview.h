#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QTableView>
#include <QModelIndex>

class DatabaseView :public QWidget
{
    Q_OBJECT
public:
    DatabaseView(QWidget*parent = nullptr);
    ~DatabaseView();

    void Init();

    QTableView * getDatabaseTableView();

    void Update();
    void discardChanges(bool isDiscard);
    void EnableChange(bool isEnable);

    const QAbstractItemModel * getModel();

    bool ApplyChanged(bool isCorrect,const QString &value,const QModelIndex& modelIndex);

    void showDatabase(bool isShow  = true);
private:
    QTableView *m_tableView;
    bool m_isShow;

signals:
    void SButtonShow(bool);
};

#endif // DATABASEVIEW_H
