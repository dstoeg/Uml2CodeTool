#include "uGridArrow.h"
#include "uDebugPrinter.h"

uGridArrow::uGridArrow(QString const& origin, QString const& destination, int type, TGridSegment segments)
{
    mOrigin = origin;
    mDestination = destination;
    mSegments = segments;
    mType = uDependency;
    mDeleted = false;

    if(type == 0){
        mType = uInheritance;
        mRatioXdest = 0.5;
        mRatioXorigin = 0.5;
        mRatioYdest = 1;
        mRatioYorigin = 0;
    }

    if(type == 1){
        mType = uAggregation;
        //depends on arriving by the left or the right
//        mRatioXdest = 0.5;
//        mRatioXorigin = 0.5;
//        mRatioYdest = 1;
//        mRatioYorigin = 0;
    }

}

uGridArrow::uGridArrow(QString const& origin, QString const& destination, uArrowType type)
{
    mOrigin = origin;
    mDestination = destination;
    mType = type;

    if(type == uInheritance){
        mRatioXdest = 0.5;
        mRatioXorigin = 0.5;
        mRatioYdest = 1;
        mRatioYorigin = 0;
    }

    if(type == uAggregation){
        //depends on arriving by the left or the right
//        mRatioXdest = 0.5;
//        mRatioXorigin = 0.5;
//        mRatioYdest = 1;
//        mRatioYorigin = 0;
    }

    mDeleted = false;
}

QString uGridArrow::getOrigin() const
{
    return mOrigin;
}

QString uGridArrow::getDestination() const
{
    return mDestination;
}

int uGridArrow::getSize() const
{
    return mSegments.size();
}

uGridSegment *uGridArrow::getSegment(int index) const
{
    return mSegments[index];
}

TGridSegment uGridArrow::getSegments() const
{
    return mSegments;
}

bool uGridArrow::getDeleted() const
{
    return mDeleted;
}

int uGridArrow::getType() const
{
    if(mType == uInheritance)
        return 0;

    if(mType == uAggregation)
        return 1;

    return 2;
}

void uGridArrow::addSegment(uGridSegment *segment)
{
    return mSegments.push_back(segment);
}

void uGridArrow::setDeleted(bool del)
{
    mDeleted = del;
}

void uGridArrow::resizeX(double ratio, int destinationX, int destWidth)
{
    for(TGridSegmentConstIter iter = mSegments.begin(); iter != mSegments.end(); iter++)
        (*iter)->resizeX(ratio);

    //correction of size
    TGridSegmentConstIter iter2 = mSegments.begin();
    for(TGridSegmentConstIter iter = ++mSegments.begin(); iter != mSegments.end(); iter++)
    {
        (*iter2)->setWidth((*iter)->getX()-(*iter2)->getX());
        uDebugPrinter::printText("new width " + std::to_string((*iter2)->getWidth()));
        iter2++;
    }

    mSegments[mSegments.size()-1]->setWidth(destinationX -  mSegments[mSegments.size()-1]->getX());

}

void uGridArrow::resizeY(double ratio, int destinationY, int destHeight)
{
    for(TGridSegmentConstIter iter = mSegments.begin(); iter != mSegments.end(); iter++)
        (*iter)->resizeY(ratio);

    //correction of size
    TGridSegmentConstIter iter2 = mSegments.begin();
    for(TGridSegmentConstIter iter = ++mSegments.begin(); iter != mSegments.end(); iter++)
    {
        (*iter2)->setHeight((*iter)->getY()-(*iter2)->getY());
        uDebugPrinter::printText("new height " + std::to_string((*iter2)->getHeight()));
        iter2++;
    }

    mSegments[mSegments.size()-1]->setHeight(destinationY -  mSegments[mSegments.size()-1]->getY());
}

bool uGridArrow::equals(uGridArrow *arrow) const
{
    return arrow->mType == mType && arrow->mOrigin == mOrigin && arrow->mDestination == mDestination;
}

bool uGridArrow::equals(const QString &origin, const QString &destination, uArrowType type) const
{
    return mOrigin == origin && mDestination == destination && mType == type;
}

int uGridArrow::selected(int x, int y) const
{
    for(int i = 0; i < mSegments.size(); i++)
    {
        if(mSegments[i]->selected(x,y))
            return i;
    }
    return -1;
}

void uGridArrow::moveSegments(int oldX, int oldY, int newX, int newY)
{
    //Check if the movement is close to the join of two segments
    double epsilon = 3;
    bool join = false;
    TGridSegmentConstIter iter2 = mSegments.begin();
    TGridSegmentConstIter iter;
    for(iter = ++mSegments.begin(); iter != mSegments.end(); iter++)
    {
        if(distancePointToPoint((*iter2)->getX() + (*iter2)->getWidth(),(*iter2)->getY() + (*iter2)->getHeight(), oldX, oldY) < epsilon
                && distancePointToPoint((*iter)->getX(),(*iter)->getY(), oldX, oldY) < epsilon)
        {
            join = true;
            break;
        }
        iter2++;
    }

    if(join)
    {
        (*iter2)->setWidth(newX - (*iter2)->getX());
        (*iter2)->setHeight(newY - (*iter2)->getY());
        (*iter)->setX(newX);
        (*iter)->setY(newY);
    }

}

double uGridArrow::distancePointToPoint(int x, int y, int i, int j) const
{
    return sqrt((double)((x-i)*(x-i) + (y-j)*(y-j)));
}

//uGridArrow::~uGridArrow()
//{
//    for(TGridObjectConstIter iter=mSegments.begin(); iter != m.end(); iter++)
//    {
//        ~(*iter);
//    }
//}

