#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

class Database : public QWidget
{
    Q_OBJECT
public:

    void Init();

    bool isEnabled(const QString &id, const QString &phone);
    bool isAvailable(const QString &what, const QString &where, const QString &value);
    bool addToDatabase(const QString& name, const QString &surname, const QString &id, const QString &phone);

    const QString& lastError();

    static Database *Instance();

    QSqlTableModel  *getModel();

    void saveDatabase();
    const QString getRecordName(const int fieldNumber) const;
private:
    QSqlDatabase * m_database;

    QSqlTableModel * sqltablemodel;

    QString m_lastError;

protected:
    static Database * p_Database;
    Database(QWidget *parent = nullptr);
    Database(const Database&);

signals:
    void SSaveSuccess();
    void SSaveFailed();
    void SRequirementCorrect(bool isCorrect, const QString &value,const QModelIndex& modelIndex);
public slots:
    void SlotCheckRequirement(QString value,const QModelIndex& modelIndex);//const QString &columnName);
};

#endif // DATABASE_H
