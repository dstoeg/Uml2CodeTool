#include "uDrawVisitor.h"

uDrawVisitor &uDrawVisitor::getInstance()
{
    static uDrawVisitor mInstance;
    return mInstance;
}
