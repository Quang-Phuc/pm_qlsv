#include "khoacntt.h"
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setStyle("fusion");
    KhoaCNTT w;
    w.show();

    return a.exec();
}
