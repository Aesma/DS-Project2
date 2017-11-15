/********************************************************************************
** Form generated from reading UI file 'mDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIALOG_H
#define UI_MDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mDialog
{
public:
    QTextBrowser *textBrowser;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *mcButton;
    QPushButton *mPlusButton;
    QPushButton *mRedButton;

    void setupUi(QDialog *mDialog)
    {
        if (mDialog->objectName().isEmpty())
            mDialog->setObjectName(QStringLiteral("mDialog"));
        mDialog->resize(296, 106);
        textBrowser = new QTextBrowser(mDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(12, 2, 256, 71));
        widget = new QWidget(mDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(5, 80, 286, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mcButton = new QPushButton(widget);
        mcButton->setObjectName(QStringLiteral("mcButton"));

        horizontalLayout->addWidget(mcButton);

        mPlusButton = new QPushButton(widget);
        mPlusButton->setObjectName(QStringLiteral("mPlusButton"));

        horizontalLayout->addWidget(mPlusButton);

        mRedButton = new QPushButton(widget);
        mRedButton->setObjectName(QStringLiteral("mRedButton"));

        horizontalLayout->addWidget(mRedButton);


        retranslateUi(mDialog);

        QMetaObject::connectSlotsByName(mDialog);
    } // setupUi

    void retranslateUi(QDialog *mDialog)
    {
        mDialog->setWindowTitle(QApplication::translate("mDialog", "M\342\226\274", 0));
        mcButton->setText(QApplication::translate("mDialog", "MC", 0));
        mPlusButton->setText(QApplication::translate("mDialog", "M+", 0));
        mRedButton->setText(QApplication::translate("mDialog", "M-", 0));
    } // retranslateUi

};

namespace Ui {
    class mDialog: public Ui_mDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIALOG_H
