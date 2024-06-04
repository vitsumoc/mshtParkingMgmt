/********************************************************************************
** Form generated from reading UI file 'mgmtpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MGMTPAGE_H
#define UI_MGMTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MgmtPage
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_password;
    QPushButton *btn_lock;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *btn_reset;
    QPushButton *btn_export;
    QPushButton *btn_parking;
    QPushButton *btn_owner;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout;
    QLineEdit *line_r2;
    QPushButton *btn_r1;
    QPushButton *btn_r2;
    QLineEdit *line_r3;
    QPushButton *btn_r3;
    QLineEdit *line_r1;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *line_owner_active;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_activation;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_lottery;
    QPushButton *btn_result;

    void setupUi(QWidget *MgmtPage)
    {
        if (MgmtPage->objectName().isEmpty())
            MgmtPage->setObjectName(QString::fromUtf8("MgmtPage"));
        MgmtPage->resize(580, 247);
        verticalLayout = new QVBoxLayout(MgmtPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MgmtPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        line_password = new QLineEdit(tab);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(line_password);

        btn_lock = new QPushButton(tab);
        btn_lock->setObjectName(QString::fromUtf8("btn_lock"));

        horizontalLayout->addWidget(btn_lock);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_reset = new QPushButton(groupBox);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));
        btn_reset->setEnabled(false);

        gridLayout_2->addWidget(btn_reset, 0, 0, 1, 1);

        btn_export = new QPushButton(groupBox);
        btn_export->setObjectName(QString::fromUtf8("btn_export"));
        btn_export->setEnabled(false);

        gridLayout_2->addWidget(btn_export, 0, 1, 1, 1);

        btn_parking = new QPushButton(groupBox);
        btn_parking->setObjectName(QString::fromUtf8("btn_parking"));
        btn_parking->setEnabled(false);

        gridLayout_2->addWidget(btn_parking, 1, 0, 1, 1);

        btn_owner = new QPushButton(groupBox);
        btn_owner->setObjectName(QString::fromUtf8("btn_owner"));
        btn_owner->setEnabled(false);

        gridLayout_2->addWidget(btn_owner, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_7 = new QVBoxLayout(tab_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_r2 = new QLineEdit(tab_5);
        line_r2->setObjectName(QString::fromUtf8("line_r2"));
        line_r2->setEnabled(false);

        gridLayout->addWidget(line_r2, 1, 1, 1, 1);

        btn_r1 = new QPushButton(tab_5);
        btn_r1->setObjectName(QString::fromUtf8("btn_r1"));

        gridLayout->addWidget(btn_r1, 2, 0, 1, 1);

        btn_r2 = new QPushButton(tab_5);
        btn_r2->setObjectName(QString::fromUtf8("btn_r2"));
        btn_r2->setEnabled(false);

        gridLayout->addWidget(btn_r2, 2, 1, 1, 1);

        line_r3 = new QLineEdit(tab_5);
        line_r3->setObjectName(QString::fromUtf8("line_r3"));
        line_r3->setEnabled(false);

        gridLayout->addWidget(line_r3, 1, 2, 1, 1);

        btn_r3 = new QPushButton(tab_5);
        btn_r3->setObjectName(QString::fromUtf8("btn_r3"));
        btn_r3->setEnabled(false);

        gridLayout->addWidget(btn_r3, 2, 2, 1, 1);

        line_r1 = new QLineEdit(tab_5);
        line_r1->setObjectName(QString::fromUtf8("line_r1"));

        gridLayout->addWidget(line_r1, 1, 0, 1, 1);

        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        line_owner_active = new QLineEdit(tab_2);
        line_owner_active->setObjectName(QString::fromUtf8("line_owner_active"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_owner_active->sizePolicy().hasHeightForWidth());
        line_owner_active->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(22);
        line_owner_active->setFont(font);
        line_owner_active->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(line_owner_active);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_activation = new QPushButton(tab_2);
        btn_activation->setObjectName(QString::fromUtf8("btn_activation"));
        btn_activation->setMinimumSize(QSize(0, 32));
        QFont font1;
        font1.setPointSize(14);
        btn_activation->setFont(font1);

        horizontalLayout_2->addWidget(btn_activation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btn_lottery = new QPushButton(tab_4);
        btn_lottery->setObjectName(QString::fromUtf8("btn_lottery"));

        verticalLayout_6->addWidget(btn_lottery);

        btn_result = new QPushButton(tab_4);
        btn_result->setObjectName(QString::fromUtf8("btn_result"));

        verticalLayout_6->addWidget(btn_result);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MgmtPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MgmtPage);
    } // setupUi

    void retranslateUi(QWidget *MgmtPage)
    {
        MgmtPage->setWindowTitle(QApplication::translate("MgmtPage", "MgmtPage", nullptr));
        label->setText(QApplication::translate("MgmtPage", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201:", nullptr));
        btn_lock->setText(QApplication::translate("MgmtPage", "\350\247\243\351\224\201", nullptr));
        groupBox->setTitle(QString());
        btn_reset->setText(QApplication::translate("MgmtPage", "\346\225\260\346\215\256\351\207\215\347\275\256", nullptr));
        btn_export->setText(QApplication::translate("MgmtPage", "\347\273\223\346\236\234\345\257\274\345\207\272", nullptr));
        btn_parking->setText(QApplication::translate("MgmtPage", "\350\275\246\344\275\215\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        btn_owner->setText(QApplication::translate("MgmtPage", "\344\270\232\344\270\273\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MgmtPage", "\346\225\260\346\215\256\347\273\264\346\212\244", nullptr));
        btn_r1->setText(QApplication::translate("MgmtPage", "\345\274\200\345\247\213\347\254\254\344\270\200\350\275\256", nullptr));
        btn_r2->setText(QApplication::translate("MgmtPage", "\345\274\200\345\247\213\347\254\254\344\272\214\350\275\256", nullptr));
        btn_r3->setText(QApplication::translate("MgmtPage", "\345\274\200\345\247\213\347\254\254\344\270\211\350\275\256", nullptr));
        label_4->setText(QApplication::translate("MgmtPage", "\347\254\254\344\270\200\350\275\256", nullptr));
        label_5->setText(QApplication::translate("MgmtPage", "\347\254\254\344\272\214\350\275\256", nullptr));
        label_6->setText(QApplication::translate("MgmtPage", "\347\254\254\344\270\211\350\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MgmtPage", "\350\275\256\346\254\241\347\256\241\347\220\206", nullptr));
        line_owner_active->setPlaceholderText(QApplication::translate("MgmtPage", "\350\257\267\350\276\223\345\205\245\345\272\217\345\217\267", nullptr));
        btn_activation->setText(QApplication::translate("MgmtPage", "\346\277\200\346\264\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MgmtPage", "\347\216\260\345\234\272\346\277\200\346\264\273", nullptr));
        btn_lottery->setText(QApplication::translate("MgmtPage", "\346\221\207\345\217\267\345\212\237\350\203\275\351\241\265\351\235\242", nullptr));
        btn_result->setText(QApplication::translate("MgmtPage", "\347\273\223\346\236\234\345\210\227\350\241\250\351\241\265\351\235\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MgmtPage", "\351\241\265\351\235\242\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MgmtPage: public Ui_MgmtPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MGMTPAGE_H
