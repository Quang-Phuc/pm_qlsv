#ifndef QUANLYLOPHOC_H
#define QUANLYLOPHOC_H

#include <QDialog>

namespace Ui {
class quanlylophoc;
}

class quanlylophoc : public QDialog
{
    Q_OBJECT

public:
    explicit quanlylophoc(QWidget *parent = 0);
    ~quanlylophoc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::quanlylophoc *ui;
};

#endif // QUANLYLOPHOC_H
