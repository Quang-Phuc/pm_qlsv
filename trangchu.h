#ifndef TRANGCHU_H
#define TRANGCHU_H

#include <QDialog>

namespace Ui {
class trangchu;
}

class trangchu : public QDialog
{
    Q_OBJECT

public:
    explicit trangchu(QWidget *parent = 0);
    ~trangchu();

private:
    Ui::trangchu *ui;
};

#endif // TRANGCHU_H
