#ifndef DANGKY_H
#define DANGKY_H

#include <QDialog>

namespace Ui {
class Dangky;
}

class Dangky : public QDialog
{
    Q_OBJECT

public:
    explicit Dangky(QWidget *parent = 0);
    ~Dangky();

private slots:
    void on_pushButton_2_clicked();

    void on_dangky_clicked();

    void on_huybo_clicked();

private:
    Ui::Dangky *ui;
};

#endif // DANGKY_H
