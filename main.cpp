#include <QCoreApplication>
#include "functions.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Functions func;
    func.GenerateFile("test.json");
    return a.exec();


}
