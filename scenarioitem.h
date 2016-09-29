#ifndef SCENARIOITEM_H
#define SCENARIOITEM_H
#include <QDebug>
#include <QString>
#include <QDate>
#include <QDateTime>

class ScenarioItem
{
public:
    ScenarioItem();

    //QString title;
    //QString type;
    QString globalType;
    QDateTime startTime;
    QDateTime endTime;
};

#endif // SCENARIOITEM_H
