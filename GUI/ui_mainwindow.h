/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../Projekt-Harmonogramowanie/GUI/DataModificationWidgets/DataWidget.h"
#include "../Projekt-Harmonogramowanie/GUI/blockplot.h"
#include "../Projekt-Harmonogramowanie/GUI/settingswidget.h"
#include "../Projekt-Harmonogramowanie/GUI/statisticswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *cWidgetverticalLayout;
    BlockPlot *mBlockPlot;
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *dataTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *dataTVLayout;
    DataWidget *mDataWidget;
    QWidget *algorithmTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *algorithTVLayout;
    SettingsWidget *mAlgorithmWidget;
    QWidget *statisticTab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *statisticTVLayout;
    StatisticsWidget *mStatisticWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 750);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1100, 750));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1104, 926));
        cWidgetverticalLayout = new QVBoxLayout(layoutWidget);
        cWidgetverticalLayout->setSpacing(6);
        cWidgetverticalLayout->setContentsMargins(11, 11, 11, 11);
        cWidgetverticalLayout->setObjectName(QStringLiteral("cWidgetverticalLayout"));
        cWidgetverticalLayout->setContentsMargins(0, 0, 0, 0);
        mBlockPlot = new BlockPlot(layoutWidget);
        mBlockPlot->setObjectName(QStringLiteral("mBlockPlot"));
        mBlockPlot->setMinimumSize(QSize(1100, 500));
        mBlockPlot->setMaximumSize(QSize(16777215, 540));
        frame = new QFrame(mBlockPlot);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(0, 0, 1100, 500));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(1000, 500));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        frame->setMidLineWidth(0);

        cWidgetverticalLayout->addWidget(mBlockPlot);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(1100, 240));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        dataTab = new QWidget();
        dataTab->setObjectName(QStringLiteral("dataTab"));
        verticalLayoutWidget = new QWidget(dataTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1102, 212));
        dataTVLayout = new QVBoxLayout(verticalLayoutWidget);
        dataTVLayout->setSpacing(6);
        dataTVLayout->setContentsMargins(11, 11, 11, 11);
        dataTVLayout->setObjectName(QStringLiteral("dataTVLayout"));
        dataTVLayout->setContentsMargins(0, 0, 0, 0);
        mDataWidget = new DataWidget(verticalLayoutWidget);
        mDataWidget->setObjectName(QStringLiteral("mDataWidget"));
        mDataWidget->setMinimumSize(QSize(1096, 210));

        dataTVLayout->addWidget(mDataWidget);

        tabWidget->addTab(dataTab, QString());
        algorithmTab = new QWidget();
        algorithmTab->setObjectName(QStringLiteral("algorithmTab"));
        verticalLayoutWidget_2 = new QWidget(algorithmTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 1102, 212));
        algorithTVLayout = new QVBoxLayout(verticalLayoutWidget_2);
        algorithTVLayout->setSpacing(6);
        algorithTVLayout->setContentsMargins(11, 11, 11, 11);
        algorithTVLayout->setObjectName(QStringLiteral("algorithTVLayout"));
        algorithTVLayout->setContentsMargins(0, 0, 0, 0);
        mAlgorithmWidget = new SettingsWidget(verticalLayoutWidget_2);
        mAlgorithmWidget->setObjectName(QStringLiteral("mAlgorithmWidget"));
        mAlgorithmWidget->setMinimumSize(QSize(1096, 210));

        algorithTVLayout->addWidget(mAlgorithmWidget);

        tabWidget->addTab(algorithmTab, QString());
        statisticTab = new QWidget();
        statisticTab->setObjectName(QStringLiteral("statisticTab"));
        verticalLayoutWidget_3 = new QWidget(statisticTab);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 1102, 212));
        statisticTVLayout = new QVBoxLayout(verticalLayoutWidget_3);
        statisticTVLayout->setSpacing(6);
        statisticTVLayout->setContentsMargins(11, 11, 11, 11);
        statisticTVLayout->setObjectName(QStringLiteral("statisticTVLayout"));
        statisticTVLayout->setContentsMargins(0, 0, 0, 0);
        mStatisticWidget = new StatisticsWidget(verticalLayoutWidget_3);
        mStatisticWidget->setObjectName(QStringLiteral("mStatisticWidget"));
        mStatisticWidget->setMinimumSize(QSize(1096, 210));

        statisticTVLayout->addWidget(mStatisticWidget);

        tabWidget->addTab(statisticTab, QString());

        cWidgetverticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Job Shop", 0));
        tabWidget->setTabText(tabWidget->indexOf(dataTab), QApplication::translate("MainWindow", "Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(algorithmTab), QApplication::translate("MainWindow", "Algorithm", 0));
        tabWidget->setTabText(tabWidget->indexOf(statisticTab), QApplication::translate("MainWindow", "Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
