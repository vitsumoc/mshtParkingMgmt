/********************************************************************************
** Form generated from reading UI file 'resultpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTPAGE_H
#define UI_RESULTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultPage
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_parking;
    QPushButton *btn_parking;
    QTableWidget *table_parking;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_owner;
    QPushButton *btn_owner;
    QTableWidget *table_owner;

    void setupUi(QWidget *ResultPage)
    {
        if (ResultPage->objectName().isEmpty())
            ResultPage->setObjectName(QString::fromUtf8("ResultPage"));
        ResultPage->resize(702, 425);
        verticalLayout = new QVBoxLayout(ResultPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ResultPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_parking = new QLabel(tab);
        label_parking->setObjectName(QString::fromUtf8("label_parking"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_parking->sizePolicy().hasHeightForWidth());
        label_parking->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_parking);

        btn_parking = new QPushButton(tab);
        btn_parking->setObjectName(QString::fromUtf8("btn_parking"));

        horizontalLayout->addWidget(btn_parking);


        verticalLayout_2->addLayout(horizontalLayout);

        table_parking = new QTableWidget(tab);
        if (table_parking->columnCount() < 7)
            table_parking->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_parking->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table_parking->setObjectName(QString::fromUtf8("table_parking"));

        verticalLayout_2->addWidget(table_parking);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_owner = new QLabel(tab_2);
        label_owner->setObjectName(QString::fromUtf8("label_owner"));
        sizePolicy.setHeightForWidth(label_owner->sizePolicy().hasHeightForWidth());
        label_owner->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_owner);

        btn_owner = new QPushButton(tab_2);
        btn_owner->setObjectName(QString::fromUtf8("btn_owner"));

        horizontalLayout_2->addWidget(btn_owner);


        verticalLayout_3->addLayout(horizontalLayout_2);

        table_owner = new QTableWidget(tab_2);
        if (table_owner->columnCount() < 7)
            table_owner->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_owner->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        table_owner->setObjectName(QString::fromUtf8("table_owner"));

        verticalLayout_3->addWidget(table_owner);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ResultPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ResultPage);
    } // setupUi

    void retranslateUi(QWidget *ResultPage)
    {
        ResultPage->setWindowTitle(QApplication::translate("ResultPage", "Form", nullptr));
        label_parking->setText(QApplication::translate("ResultPage", "\350\275\246\344\275\215\344\277\241\346\201\257:", nullptr));
        btn_parking->setText(QApplication::translate("ResultPage", "\345\210\267\346\226\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_parking->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ResultPage", "\350\275\246\344\275\215\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_parking->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ResultPage", "\350\275\246\344\275\215\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_parking->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ResultPage", "\346\257\215\345\255\220\350\275\246\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_parking->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ResultPage", "\350\275\246\344\275\215\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_parking->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_parking->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\346\210\277\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_parking->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\345\220\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ResultPage", "\350\275\246\344\275\215\344\277\241\346\201\257\350\241\250", nullptr));
        label_owner->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\344\277\241\346\201\257\357\274\232", nullptr));
        btn_owner->setText(QApplication::translate("ResultPage", "\345\210\267\346\226\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_owner->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_owner->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\346\210\277\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_owner->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("ResultPage", "\344\270\232\344\270\273\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_owner->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("ResultPage", "\350\275\246\347\211\214\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_owner->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("ResultPage", "\350\275\246\347\211\214\345\217\2672", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_owner->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("ResultPage", "\346\221\207\345\217\267\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_owner->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("ResultPage", "\346\221\207\345\217\267\347\273\223\346\236\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ResultPage", "\344\270\232\344\270\273\344\277\241\346\201\257\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultPage: public Ui_ResultPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTPAGE_H
