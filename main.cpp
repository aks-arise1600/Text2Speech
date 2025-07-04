#include "Text2Speech.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Text2Speech w;
    w.show();
    return a.exec();
}
