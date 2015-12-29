#include "relic_banner_parser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    relic_banner_parser w;
    w.show();

    return a.exec();
}
