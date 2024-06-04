/********************************************************************************
** Form generated from reading UI file 'lotterypage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTTERYPAGE_H
#define UI_LOTTERYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LotteryPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_round;
    QTableWidget *table_round;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *line_code;
    QPushButton *btn_lottery;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *table_result;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LotteryPage)
    {
        if (LotteryPage->objectName().isEmpty())
            LotteryPage->setObjectName(QString::fromUtf8("LotteryPage"));
        LotteryPage->resize(1003, 626);
        LotteryPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(LotteryPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        label = new QLabel(LotteryPage);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(44);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_6 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        label_round = new QLabel(LotteryPage);
        label_round->setObjectName(QString::fromUtf8("label_round"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(26);
        label_round->setFont(font1);
        label_round->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_round);

        table_round = new QTableWidget(LotteryPage);
        if (table_round->columnCount() < 2)
            table_round->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_round->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_round->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (table_round->rowCount() < 3)
            table_round->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_round->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_round->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_round->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_round->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_round->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_round->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_round->setItem(1, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_round->setItem(2, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_round->setItem(2, 1, __qtablewidgetitem10);
        table_round->setObjectName(QString::fromUtf8("table_round"));

        verticalLayout_2->addWidget(table_round);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_code = new QLineEdit(LotteryPage);
        line_code->setObjectName(QString::fromUtf8("line_code"));
        QFont font2;
        font2.setPointSize(28);
        line_code->setFont(font2);
        line_code->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(line_code);

        btn_lottery = new QPushButton(LotteryPage);
        btn_lottery->setObjectName(QString::fromUtf8("btn_lottery"));
        QFont font3;
        font3.setPointSize(18);
        btn_lottery->setFont(font3);

        horizontalLayout->addWidget(btn_lottery);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget = new QWidget(LotteryPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 6, -1, 6);
        table_result = new QTableWidget(widget);
        if (table_result->columnCount() < 4)
            table_result->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_result->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_result->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_result->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_result->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        if (table_result->rowCount() < 1)
            table_result->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_result->setVerticalHeaderItem(0, __qtablewidgetitem15);
        table_result->setObjectName(QString::fromUtf8("table_result"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table_result->sizePolicy().hasHeightForWidth());
        table_result->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush4(QColor(255, 255, 255, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(240, 240, 240, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        table_result->setPalette(palette1);
        table_result->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(table_result);


        verticalLayout_2->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(LotteryPage);

        QMetaObject::connectSlotsByName(LotteryPage);
    } // setupUi

    void retranslateUi(QWidget *LotteryPage)
    {
        LotteryPage->setWindowTitle(QApplication::translate("LotteryPage", "Form", nullptr));
        label->setText(QApplication::translate("LotteryPage", "\345\220\215\344\273\225\350\261\252\345\272\255\350\275\246\344\275\215\346\221\207\345\217\267\350\275\257\344\273\266", nullptr));
        label_round->setText(QApplication::translate("LotteryPage", "\345\275\223\345\211\215\350\275\256\346\254\241:\347\254\2540\350\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_round->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LotteryPage", "\347\254\254\344\270\200\350\275\256 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_round->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LotteryPage", "\347\254\254\344\272\214\350\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_round->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("LotteryPage", "\350\275\246\344\275\215\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_round->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("LotteryPage", "\345\217\202\344\270\216\344\270\232\344\270\273\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_round->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("LotteryPage", "\344\270\255\347\255\276\347\216\207", nullptr));

        const bool __sortingEnabled = table_round->isSortingEnabled();
        table_round->setSortingEnabled(false);
        table_round->setSortingEnabled(__sortingEnabled);

        line_code->setPlaceholderText(QApplication::translate("LotteryPage", "\350\257\267\350\276\223\345\205\245\345\272\217\345\210\227\345\217\267", nullptr));
        btn_lottery->setText(QApplication::translate("LotteryPage", "\345\274\200\345\247\213\346\221\207\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_result->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("LotteryPage", "\344\270\232\344\270\273\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_result->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("LotteryPage", "\344\270\255\347\255\276\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_result->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("LotteryPage", "\350\275\246\344\275\215\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_result->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("LotteryPage", "\350\275\246\344\275\215\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LotteryPage: public Ui_LotteryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTTERYPAGE_H
