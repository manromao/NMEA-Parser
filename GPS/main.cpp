#include <QCoreApplication>
#include <gps.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    GPS myGps;


    return a.exec();
}
