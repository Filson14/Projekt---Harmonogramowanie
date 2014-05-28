#include "blockplot.h"



BlockPlot::BlockPlot(QWidget *parent,Chromosom* best) :
    QCustomPlot(parent)
{
    setAutoAddPlottableToLegend(false);
    Database& mydt=Chromosom::getJobDatabase();
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom|QCP::iSelectPlottables);

    //initialize vector of colors
    cVect.push_back(Qt::black);
    cVect.push_back(Qt::red);
    cVect.push_back(Qt::green);
    cVect.push_back(Qt::blue);
    cVect.push_back(Qt::cyan);
    cVect.push_back(Qt::magenta);
    cVect.push_back(Qt::yellow);
    cVect.push_back(Qt::gray);
    cVect.push_back(Qt::darkRed);
    cVect.push_back(Qt::darkGreen);
    cVect.push_back(Qt::darkBlue);
    cVect.push_back(Qt::black);
    cVect.push_back(Qt::darkYellow);

    for(int i=13;i<mydt.getMachinesAmount()+1;i++)
    {
        QColor cq;
        cq.setCmyk(qrand()%255,qrand()%255,qrand()%255,qrand()%255);
        cVect.push_back(cq);
    }


    //Setting Y axis

    QVector<double> qticks;

    for(int i=0;i<mydt.getJobsAmount();i++)
        qticks<<i;

       yAxis->setRange(-1, mydt.getJobsAmount());
     yAxis->setAutoTicks(false);
     yAxis->setAutoSubTicks(false);
     yAxis->setSubTickLength(0,0);
     yAxis->setTickVector(qticks);
     yAxis->setLabel("Jobs");



    //Setting X axis
     xAxis->setLabel("Time");
     xAxis->setAutoTicks(true);
     if(best!=0)
         xAxis->setRange(0,best->getFitness());




    //Setting up the block widgets


    QVector<ExtQCPStatisticalBox*> sbExamples(mydt.getMachinesAmount(),NULL);
    for(vector<Job>::iterator jit=mydt.getJobs().begin();jit!=mydt.getJobs().end();jit++)
    {
        for(vector<Task>::iterator tit=(*jit).getTaskList().begin();tit!=(*jit).getTaskList().end();tit++)
        {
            allSP.push_back(new ExtQCPStatisticalBox(yAxis,xAxis));
            QBrush boxBrush(cVect[(*tit).getMachine()->getId()]);
            allSP.last()->setBrush(boxBrush);
            allSP.last()->setKey(jit-(mydt.getJobs().begin()));
            allSP.last()->setWhiskerWidth(0);
            allSP.last()->setMinimum(tit->getStart());
            allSP.last()->setLowerQuartile(tit->getStart());
            allSP.last()->setUpperQuartile(tit->getStart()+tit->getTime());
            allSP.last()->setMaximum(tit->getStart()+tit->getTime());
            allSP.last()->setName("Machine "+QString::number((*tit).getMachine()->getId()));
            allSP.last()->setSelectable(true);
            connect(allSP.last(),SIGNAL(selectionChanged (bool )),allSP.last(),SLOT(blockinfo(bool)));
            addPlottable(allSP.last());
            if(sbExamples[(*tit).getMachine()->getId()]==NULL)
            {
                sbExamples[(*tit).getMachine()->getId()]=allSP.last();
            }

        }

    }


    //Setting up the legend
    for(int i=0;i<mydt.getMachinesAmount();i++)
    {
        legend->addItem(new QCPPlottableLegendItem(legend,( QCPAbstractPlottable *)sbExamples[i]));
    }
    legend->setVisible(true);

    replot();
}

