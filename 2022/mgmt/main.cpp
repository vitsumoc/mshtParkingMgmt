#include "mgmtpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MgmtPage w;
    w.show();
    return a.exec();
}
