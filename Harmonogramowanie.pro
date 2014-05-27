#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T13:48:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Harmonogramowanie
TEMPLATE = app


SOURCES +=\
    Algorithm/Algorithm.cpp \
    Algorithm/Chromosom.cpp \
    DataModification/Database.cpp \
    DataModification/Job.cpp \
    DataModification/Machine.cpp \
    DataModification/Task.cpp \
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
    GUI/main2.cpp \
    GUI/mainwindow.cpp \
    GUI/qcustomplot.cpp \
    GUI/qspinboxenhenced.cpp \
    GUI/settingswidget.cpp \
    GUI/statisticsplotwidget.cpp \
    GUI/statisticswidget.cpp \
    Main1.cpp

HEADERS  += \
    Algorithm/Algorithm.h \
    Algorithm/Chromosom.h \
    Algorithm/SettingsStructures.h \
    Algorithm/StatisticsStructure.h \
    DataModification/Database.h \
    DataModification/Job.h \
    DataModification/Machine.h \
    DataModification/Task.h \
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
    GUI/mainwindow.h \
    GUI/qcustomplot.h \
    GUI/qspinboxenhenced.h \
    GUI/settingswidget.h \
    GUI/statisticsplotwidget.h \
    GUI/statisticswidget.h
