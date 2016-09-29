#ifndef VMIXITEM_H
#define VMIXITEM_H
#include "scenarioitem.h"
#include <QDateTime>

class VmixItem : public ScenarioItem
{
public:
    VmixItem();

    QString vmixTitle;
    QString title;
    QString camera;
    QString cameraInput;
    QString resolution;
    QString frameRate;
    QString audioDevice;
    int layer;
    QString url;
    QString filePath;
    QString transitionType;
    QString vmixType;

};

#endif // VMIXITEM_H
