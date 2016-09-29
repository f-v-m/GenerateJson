#include "functions.h"

Functions::Functions()
{

}

void Functions::GenerateFile(QString title){
    VmixItem vmixItm;
    vmixItm.startTime = QDateTime::currentDateTime();
    vmixItm.endTime = QDateTime::currentDateTime();
    scenarioVector.insert(scenarioVector.end(),vmixItm);



    generateMainInfo("DOTA2 season4", QDateTime::currentDateTime(), QDateTime::currentDateTime());
    addVmixInputToJson("dota2scenario.json", vmixItm);
    addVmixInputToJson("dota2scenario.json", vmixItm);
    saveJsonToFile("dota2scenario.json");
}


void Functions::GenerateJson(QString title){
    QVariantMap map;
    map.insert("integer", 1);
    map.insert("double", 2.34);
    map.insert("bool", QVariant(true));
    map.insert("string", "word");

    QJsonObject object2 = QJsonObject::fromVariantMap(map);


    QJsonArray array = { 1, 2.2, QString() };
    object2.insert("test", array);
    object2.insert("ololo", object2);


    document.setObject(object2);



    QString strJsn(document.toJson());
    qDebug() << "test string: " << strJsn;

    QFile file;
    file.setFileName(title);

    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << "can't open file for write";
    }
    file.write(strJsn.toStdString().c_str());
    file.close();
}


QString Functions::saveJsonToFile(QString title){
    QFile file;
    file.setFileName(title);

    if(!file.open(QIODevice::WriteOnly)){
        qDebug() << "CAN'T OPEN FILE FOR WRITE";
        return "CAN'T OPEN FILE FOR WRITE";
    }

    if (object.isEmpty()){
        file.close();
        qDebug() << "json is not ready";
        return "json is not ready";
    }

    document.setObject(object);
    QString jsnString(document.toJson());
    file.write(jsnString.toStdString().c_str());

    file.close();
    qDebug() << "saving json to file is completed";
    return "saving json to file is completed";
}

QString Functions::generateMainInfo(QString ttl, QDateTime startTime, QDateTime endTime){
    QVariantMap map;
    map.insert("title", ttl);
    map.insert("startTime", QVariant(startTime));
    map.insert("endTime", QVariant(endTime));

    object = QJsonObject::fromVariantMap(map);

    return "ok";
}

QString Functions::addVmixInputToJson(QString scenarioFile, VmixItem itm){
    //camera opt:
    QJsonObject cameraObj;
    QVariantMap cameraMap;
    cameraMap.insert("camera", itm.camera);
    cameraMap.insert("input", itm.cameraInput);
    cameraMap.insert("resolution", itm.resolution);
    cameraMap.insert("frame_rate", itm.frameRate);
    cameraMap.insert("audio_device", itm.audioDevice);
    cameraObj = QJsonObject::fromVariantMap(cameraMap);

    //all options:
    QJsonObject inputOptions;
    QVariantMap optionsMap;
    optionsMap.insert("title", itm.vmixTitle);
    optionsMap.insert("global_type", itm.globalType);
    optionsMap.insert("vmix_type", itm.vmixType);
    optionsMap.insert("camera", cameraObj);
    optionsMap.insert("layer", itm.layer);
    optionsMap.insert("url", itm.url);
    optionsMap.insert("file_path", itm.filePath);
    optionsMap.insert("start_time", itm.startTime);
    optionsMap.insert("end_time", itm.endTime);
    inputOptions = QJsonObject::fromVariantMap(optionsMap);

    inputArr.insert(inputArr.end(), inputOptions);
    object.insert("input_list", inputArr);

    qDebug() << "input added to json";
    return "ok";
}
