#include "duplot.h"
#include "qcustomplot.h"

DuPlot::DuPlot(QCustomPlot *parent)
{
    mParent= parent;
}
void DuPlot::drawGraph()
{
    mGraph = mParent->addGraph();
    mGraph->setData(mX,mY);

}
