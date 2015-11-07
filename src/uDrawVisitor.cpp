#include "uDrawVisitor.h"

uDrawVisitor *uDrawVisitor::getInstance()
{
    if(mInstance == 0)
        mInstance = new uDrawVisitor();

    return mInstance;
}

uDrawVisitor::uDrawVisitor()
{

}

