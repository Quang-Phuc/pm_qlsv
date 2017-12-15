#ifndef PHUC1_H
#define PHUC1_H

#include <QTabWidget>

namespace Ui {
class phuc1;
}

class phuc1 : public QTabWidget
{
    Q_OBJECT

public:
    explicit phuc1(QWidget *parent = 0);
    ~phuc1();

private:
    Ui::phuc1 *ui;
};

#endif // PHUC1_H
