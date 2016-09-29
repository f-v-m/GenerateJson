#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>
#include <QJsonArray>
#include <QDateTime>
#include <vector>
#include "scenarioitem.h"
#include "vmixitem.h"
using namespace std;
class Functions
{
public:
    Functions();

    void GenerateFile(QString title);
    void GenerateJson(QString title);


    //CREATING JSON FOR SCENARIO FILE:
    QString saveJsonToFile(QString title);
    QString generateMainInfo(QString ttl, QDateTime startTime, QDateTime endTime);
    //QString addItemToScenario(QString ttl, QString type, QDateTime startTime, QDateTime endTime);
    QString addVmixInputToJson(QString scenarioFile, VmixItem itm);

    QJsonObject object;
    QJsonDocument document;
    QJsonArray inputArr;

    vector<ScenarioItem> scenarioVector;
};

#endif // FUNCTIONS_H
