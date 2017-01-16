#include "blockplot.h"



BlockPlot::BlockPlot(QWidget *parent) :
    QCustomPlot(parent)
{
    setAutoAddPlottableToLegend(false);
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

}


void BlockPlot::onDataChanged(Database* mydt)
{
    this->clearPlottables();
    this->clearGraphs();
    int maxid=mydt->getMaxMachineID();

    if(maxid+1>cVect.size())
    {
        for(int i=cVect.size();i<maxid+2;i++)
        {
            QColor cq;
            cq.setCmyk(qrand()%255,qrand()%255,qrand()%255,qrand()%255);
            cVect.push_back(cq);
        }
    }


    //Setting Y axis

    QVector<double> qticks;

    for(int i=0;i<mydt->getJobsAmount();i++)
        qticks<<i;

     yAxis->setRange(-1, mydt->getJobsAmount());
     yAxis->setAutoTicks(false);
     yAxis->setAutoSubTicks(false);
     yAxis->setSubTickLength(0,0);
     yAxis->setTickVector(qticks);
     yAxis->setLabel("Jobs");

//     QSharedPointer<QCPAxisTicker> textTicker(new QCPAxisTicker);
//     vector<Job> jobs = mydt->getJobs();

//     for(int i=0;i<jobs->size();i++) {
//         textTicker->addTick(i, jobs->at(i).getLabel());
//     }
//     yAxis->setTicker(textTicker);


    //Setting X axis
     xAxis->setLabel("Time");
     xAxis->setAutoTicks(true);
     //xAxis->setRange(0,2000); //do wywalenia
     xAxis->setRange(0,mydt->getLongestJobDuration()+XINT);




    //Setting up the block widgets
    legend->clearItems();
    ExtQCPStatisticalBox* lastPItem=NULL;
    QBrush boxBrush;
    QVector<ExtQCPStatisticalBox*> sbExamples(maxid+1,NULL);
    for(vector<Job>::iterator jit=mydt->getJobs().begin();jit!=mydt->getJobs().end();jit++)
    {
        for(vector<Task>::iterator tit=(*jit).getTaskList().begin();tit!=(*jit).getTaskList().end();tit++)
        {
            if(tit->getTime()==0)
                continue;
            lastPItem=new ExtQCPStatisticalBox(yAxis,xAxis);
            boxBrush=QBrush(cVect[(*tit).getMachine()->getId()]);
            boxBrush.setStyle(Qt::Dense4Pattern);

            lastPItem->setBrush(boxBrush);
            lastPItem->setKey(jit-(mydt->getJobs().begin()));
            lastPItem->setWhiskerWidth(0);
            lastPItem->setMinimum(tit->getStart());
            lastPItem->setLowerQuartile(tit->getStart());
            lastPItem->setUpperQuartile(tit->getStart()+tit->getTime());
            lastPItem->setMaximum(tit->getStart()+tit->getTime());
            lastPItem->setName(QString::fromStdString((*jit).getLabel()) + " - " + QString::fromStdString((*tit).getMachine()->getLabel()));
            lastPItem->setSelectable(true);
           // connect(allSP.last(),SIGNAL(selectionChanged (bool )),allSP.last(),SLOT(blockinfo(bool)));
            connect(lastPItem,SIGNAL(selectionChanged (bool )),this,SLOT(onBlockSelected(bool)));
            addPlottable(lastPItem);
            if(sbExamples[(*tit).getMachine()->getId()]==NULL) {
                ExtQCPStatisticalBox *legendBox = new ExtQCPStatisticalBox(yAxis, xAxis);
                legendBox->setBrush(boxBrush);
                legendBox->setName(QString::fromStdString((*tit).getMachine()->getLabel()));
                legendBox->setBrush(boxBrush);
                legendBox->setWhiskerWidth(0);
                sbExamples[(*tit).getMachine()->getId()] = legendBox;
//                sbExamples[(*tit).getMachine()->getId()] = lastPItem;
            }

        }

    }


    //Setting up the legend
    for(int i=0;i<maxid+1;i++)
    {
        if(sbExamples[i]!=NULL)
            legend->addItem(new QCPPlottableLegendItem(legend,( QCPAbstractPlottable *)sbExamples[i]));
    }
    legend->setVisible(true);

    replot();

}

void BlockPlot::onBlockSelected(bool on)
{
    if(!on)
        return;
    ((ExtQCPStatisticalBox*)sender())->setSelected(false);
    setToolTip(((ExtQCPStatisticalBox*)sender())->name() + "\nTask start: "+QString::number(((ExtQCPStatisticalBox*)sender())->minimum())+"\nTask time: "+QString::number(((ExtQCPStatisticalBox*)sender())->maximum()-((ExtQCPStatisticalBox*)sender())->minimum()));

}


BlockPlot::~BlockPlot()
{

}


