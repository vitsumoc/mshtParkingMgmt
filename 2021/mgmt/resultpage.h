#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QWidget>

namespace Ui {
class ResultPage;
}

class ResultPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResultPage(QWidget *parent = nullptr);
    ~ResultPage();

private slots:
    void on_btn_parking_clicked();

    void on_btn_owner_clicked();

private:
    Ui::ResultPage *ui;
};

#endif // RESULTPAGE_H
