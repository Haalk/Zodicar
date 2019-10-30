#ifndef HELPER_H
#define HELPER_H

#include <QDesktopWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QRegExpValidator>
#include <QKeyEvent>

namespace NButtonsName
{
    const QString NewClient =   "New Client";
    const QString Cancel =      "Cancel";
    const QString Edit =        "Edit";
    const QString Save =        "Save";
    const QString Delete =      "Delete";
    const QString Select =      "Select";
    const QString Scan =        "Scan";
    const QString ShowDatabase ="Show client";
};

namespace NDiscountLevel
{
// до 3000 це перший, до 10000 - другий
    const float LEVEL_1 = 3000.0;
    const float LEVEL_2 = 10000.0;
    const float LEVEL_3 = 20000.0;
    const float LEVEL_4 = 50000.0;
    const float LEVEL_5 = 100000.0;
    const float LEVEL_6 = 250000.0;
    const float LEVEL_7 = 500000.0;
    const float LEVEL_8 = 1000000.0;
}

namespace NDiscountPercent
{
    const float LEVEL_1 = 0.5;
    const float LEVEL_2 = 1.5;
    const float LEVEL_3 = 2.0;
    const float LEVEL_4 = 3.5;
    const float LEVEL_5 = 5.0;
    const float LEVEL_6 = 7.0;
    const float LEVEL_7 = 10.0;
    const float LEVEL_8 = 15.0;
}

const int CARD_SIZE = 10;
const int PHONE_SIZE = 10;
const QString NAME_TABLE = "CLIENT";


#endif // HELPER_H


//  Зробити щоб можна було виділяти декілька рядків і щось з ним робити, наприклад видаляти
