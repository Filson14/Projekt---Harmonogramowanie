#-------------------------------------------------
#
# Project created by QtCreator 2014-05-22T12:04:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Projekt-Harmonogramowanie
TEMPLATE = app


SOURCES += main.cpp\
    Algorithm/Algorithm.cpp \
    Algorithm/Chromosom.cpp \
    GeneticOperators/CrossoverOperators/CrossoverOnePoint.cpp \
    GeneticOperators/CrossoverOperators/CrossoverOperator.cpp \
    GeneticOperators/CrossoverOperators/CrossoverTwoPoint.cpp \
    GeneticOperators/MutationOperators/MutationInversion.cpp \
    GeneticOperators/MutationOperators/MutationOperator.cpp \
    GeneticOperators/MutationOperators/MutationReverse.cpp \
    GeneticOperators/MutationOperators/MutationSwapping.cpp \
    GeneticOperators/MutationOperators/MutationSwappingPoint.cpp \
    GeneticOperators/MutationOperators/MutationSwappingSegment.cpp \
    GeneticOperators/SelectionOperators/SelectionOperator.cpp \
    GeneticOperators/SelectionOperators/SelectionRoulette.cpp \
    GeneticOperators/SelectionOperators/SelectionTournament.cpp \
    GUI/blockplot.cpp \
    GUI/extqcpstatisticalbox.cpp \
    GUI/mainwindow.cpp \
    GUI/qcustomplot.cpp \
    GUI/qspinboxenhenced.cpp \
    GUI/settingswidget.cpp \
    GUI/statisticsplotwidget.cpp \
    GUI/statisticswidget.cpp \
    main.cpp \
    DataModification/Database.cpp \
    DataModification/Job.cpp \
    DataModification/Machine.cpp \
    DataModification/Task.cpp \
    DataModificationWidgets/AddingWidget.cpp \
    DataModificationWidgets/DataWidget.cpp \
    DataModificationWidgets/DeletingWidget.cpp \
    DataModificationWidgets/EditingWidget.cpp \
    Controller/controller.cpp

HEADERS  += DataModification/Machine.h \
    DataModification/Database.h \
    DataModification/Job.h \
    DataModification/Task.h \
    Algorithm/Algorithm.h \
    Algorithm/Chromosom.h \
    Algorithm/SettingsStructures.h \
    Algorithm/StatisticsStructure.h \
    GeneticOperators/CrossoverOperators/CrossoverOnePoint.h \
    GeneticOperators/CrossoverOperators/CrossoverOperator.h \
    GeneticOperators/CrossoverOperators/CrossoverTwoPoint.h \
    GeneticOperators/MutationOperators/MutationInversion.h \
    GeneticOperators/MutationOperators/MutationOperator.h \
    GeneticOperators/MutationOperators/MutationReverse.h \
    GeneticOperators/MutationOperators/MutationSwapping.h \
    GeneticOperators/MutationOperators/MutationSwappingPoint.h \
    GeneticOperators/MutationOperators/MutationSwappingSegment.h \
    GeneticOperators/SelectionOperators/SelectionOperator.h \
    GeneticOperators/SelectionOperators/SelectionRoulette.h \
    GeneticOperators/SelectionOperators/SelectionTournament.h \
    GUI/blockplot.h \
    GUI/extqcpstatisticalbox.h \
    GUI/mainwindow.h \
    GUI/qcustomplot.h \
    GUI/qspinboxenhenced.h \
    GUI/settingswidget.h \
    GUI/statisticsplotwidget.h \
    GUI/statisticswidget.h \
    DataModificationWidgets/AddingWidget.h \
    DataModificationWidgets/DataWidget.h \
    DataModificationWidgets/DeletingWidget.h \
    DataModificationWidgets/EditingWidget.h \
    Controller/controller.h \
    DataModificationWidgets/DataStructure.h

FORMS    += mainwindow.ui

UI_DIR = ../Projekt-Harmonogramowanie/GUI
