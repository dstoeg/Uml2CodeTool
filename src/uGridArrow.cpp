#include "uGridArrow.h"
#include "uDebugPrinter.h"
#include <math.h>

uGridArrow::uGridArrow(QString const& origin, QString const& destination, int type, TGridSegment segments)
{
    mOrigin = origin;
    mDestination = destination;
    mSegments = segments;
    mType = uDependency;
    mDeleted = false;
    mSegmentSelected = -1;

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
    mSegmentSelected = -1;

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
    mSegments.push_back(segment);
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
        (*iter2)->setX_to((*iter)->getX());
//        uDebugPrinter::printText("new width " + std::to_string((*iter2)->getWidth()));
        iter2++;
    }

    //mSegments[mSegments.size()-1]->setX_to(destinationX -  mSegments[mSegments.size()-1]->getX());

}

void uGridArrow::resizeY(double ratio, int destinationY, int destHeight)
{
    for(TGridSegmentConstIter iter = mSegments.begin(); iter != mSegments.end(); iter++)
        (*iter)->resizeY(ratio);

    //correction of size
    TGridSegmentConstIter iter2 = mSegments.begin();
    for(TGridSegmentConstIter iter = ++mSegments.begin(); iter != mSegments.end(); iter++)
    {
        (*iter2)->setY_to((*iter)->getY());
       // uDebugPrinter::printText("new height " + std::to_string((*iter2)->getHeight()));
        iter2++;
    }

    //mSegments[mSegments.size()-1]->setHeight(destinationY -  mSegments[mSegments.size()-1]->getY());
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
    double epsilon = 5;

    //If a segment was already selected, first I check that one
    if(mSegmentSelected != -1){

        //if that segment was not the last, then was in a joint of two segments
        if(mSegmentSelected != mSegments.size()-1){
            if(distancePointToPoint(mSegments[mSegmentSelected]->getX_to(),
                                    mSegments[mSegmentSelected]->getY_to(), oldX, oldY) < epsilon
                    && distancePointToPoint(mSegments[mSegmentSelected+1]->getX(),
                                            mSegments[mSegmentSelected+1]->getY(), oldX, oldY) < epsilon)
            {
//                uDebugPrinter::printText("Joint found in (" + std::to_string(oldX) + "," + std::to_string(oldY) + ")");
                mSegments[mSegmentSelected]->setX_to(newX);
                mSegments[mSegmentSelected]->setY_to(newY);
                mSegments[mSegmentSelected+1]->setX(newX);
                mSegments[mSegmentSelected+1]->setY(newY);
                return;
            }
            else //if it was not in a joint, then is unselected
            {
                mSegmentSelected = -1;
            }
        }
    }

    TGridSegmentConstIter iter2 = mSegments.begin();
    TGridSegmentConstIter iter;
    mSegmentSelected = -1;
    for(iter = mSegments.begin() + 1; iter != mSegments.end(); iter++)
    {
        mSegmentSelected++;
        //Check segments joints
        if(distancePointToPoint((*iter2)->getX_to(),(*iter2)->getY_to(), oldX, oldY) < epsilon
                && distancePointToPoint((*iter)->getX(),(*iter)->getY(), oldX, oldY) < epsilon)
        {
            uDebugPrinter::printText("Join found in (" + std::to_string(oldX) + "," + std::to_string(oldY) + ")");
            (*iter2)->setX_to(newX);
            (*iter2)->setY_to(newY);
            (*iter)->setX(newX);
            (*iter)->setY(newY);
            return;
        }

        //Check middle segments
        if((*iter2)->selected(oldX, oldY))
        {
            int x_to = (*iter2)->getX_to();
            int y_to = (*iter2)->getY_to();
            (*iter2)->setX_to(newX);
            (*iter2)->setY_to(newY);

            uDebugPrinter::printText("New segment created in (" + std::to_string(oldX) + "," + std::to_string(oldY) + ")");
            //create a new segment in the middle
            mSegments.insert(iter, new uGridSegment(newX, newY, x_to, y_to));
            return;
        }

        iter2++;
    }


    //Check last point
    if((*iter2)->selected(oldX, oldY))
    {
        int x_to = (*iter2)->getX_to();
        int y_to = (*iter2)->getY_to();
        (*iter2)->setX_to(newX);
        (*iter2)->setY_to(newY);

        uDebugPrinter::printText("New segment created in (" + std::to_string(oldX) + "," + std::to_string(oldY) + ")");
        //create a new segment in the middle
        mSegments.insert(iter, new uGridSegment(newX, newY, x_to, y_to));
        return;
    }

    mSegmentSelected = -1;
}

bool uGridArrow::notifyMovement(const QString &name, int movX, int movY)
{
    //If class moved was the origin class
    if(name == mOrigin){
        mSegments[0]->setX(mSegments[0]->getX() + movX);
        mSegments[0]->setY(mSegments[0]->getY() + movY);
    }

    //If class moved was the destination class
    if (name == mDestination)
    {
        int index = mSegments.size()-1;
        mSegments[index]->setX_to(mSegments[index]->getX_to() + movX);
        mSegments[index]->setY_to(mSegments[index]->getY_to() + movY);
    }

    if(name != mOrigin && name != mDestination)
        return false;

    return true;
}

void uGridArrow::mergeSegments()
{
    //Check for flat joints to merge them in one segment

    TGridSegmentConstIter iter2 = mSegments.begin();
    TGridSegmentConstIter iter;
    for(iter = mSegments.begin() + 1; iter != mSegments.end(); iter++, iter2++)
    {
//        double inclination1 = (*iter2)->getInclination();
//        double inclination2 =
        uDebugPrinter::printText("Trying segments merge");
        if(similarInclination((*iter2), (*iter)))
        {
            uDebugPrinter::printText("Detected segments merge");
            (*iter2)->setX_to((*iter)->getX_to());
            (*iter2)->setY_to((*iter)->getY_to());
            mSegments.erase(iter);
            mergeSegments();
            return;
        }
        //iter2++;
    }
}

bool uGridArrow::similarInclination(const uGridSegment * const seg1, const uGridSegment * const seg2)
{
    double epsilon = 0.05;

    int Ax = seg1->getX();
    int Ay = seg1->getY();
    int Bx = seg1->getX_to();
    int By = seg1->getY_to();
    int Cx = seg2->getX_to();
    int Cy = seg2->getY_to();

    double dev1, dev2;
    if(Bx == Ax)
        dev1 = 0.00000001;
    else
        dev1 = Bx - Ax;

    if(Cx == Ax)
        dev2 = 0.00000001;
    else
        dev2 = Cx - Ax;

    double atan1 = atan((By - Ay)/(dev1));
    double atan2 = atan((Cy - Ay)/(dev2));

    return fabs(atan1 - atan2) < epsilon;
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

