#ifndef MGMTPAGE_H
#define MGMTPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MgmtPage; }
QT_END_NAMESPACE

class LotteryPage;
class ResultPage;

class MgmtPage : public QWidget
{
    Q_OBJECT

public:
    MgmtPage(QWidget *parent = nullptr);
    ~MgmtPage();

private slots:
    void on_btn_lock_clicked();

    void on_btn_reset_clicked();

    void on_btn_parking_clicked();

    void on_btn_owner_clicked();

    void on_btn_activation_clicked();

    void on_btn_export_clicked();

    void on_btn_lottery_clicked();

    void on_btn_result_clicked();

    void on_btn_r1_clicked();

    void on_btn_r2_clicked();

    void on_btn_r3_clicked();

private:
    Ui::MgmtPage *ui;

    // 摇奖页面和结果页面
    LotteryPage *_lotteryPage;
    ResultPage *_resultPage;

    // 管理权限使能状态
    bool _enable = false;

    // 正在工作，防误触
    bool _isWorking = false;

    void init();
    void initStyle();
};
#endif // MGMTPAGE_H
