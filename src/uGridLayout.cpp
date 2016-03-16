#include "uGridLayout.h"
#include "uDebugPrinter.h"
#include "uGridObjectFactory.h"

#include <string>

using namespace std;

uGridLayout::uGridLayout(QObject *parent) : QObject(0)
{

}

uGridLayout::uGridLayout(int width, int height) : QObject(0)
{
    mWidth = width;
    mHeight = height;
}

bool uGridLayout::addClass(int i, int j, int width, int height, const QString &name)
{
    uDebugPrinter::printText("adding class: " + name.toStdString() + " index i: " + to_string(i) + " index j: " + to_string(j));
    if (!checkBounds(i,j,width, height)) return false;

    mTable.push_back(uGridObjectFactory::createClass(i ,j ,width ,height ,name));

    return true;
}


bool uGridLayout::removeObject(const QString &name)
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            mTable.erase(iter);
            return true;
        }
    }
    return false;
}

bool uGridLayout::removeObject(int x, int y)
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->selected(x,y)) {
            mTable.erase(iter);
            return true;
        }
    }
    return false;
}

bool uGridLayout::changeObjectName(const QString &name, const QString &newName)
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            (*iter)->setName(newName);
            return true;
        }
    }
    return false;
}

bool uGridLayout::moveObject(const QString &name, int movX, int movY)
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            if(checkBounds((*iter)->getX() + movX, (*iter)->getY() + movY, (*iter)->getWidth(), (*iter)->getHeight())){
                (*iter)->setY((*iter)->getY() + movY);
                (*iter)->setX((*iter)->getX() + movX);
                (*iter)->setY_to((*iter)->getY_to() + movY);
                (*iter)->setX_to((*iter)->getX_to() + movX);
                (*iter)->notifyMovement(movX, movY); //notifies the arrows that it is moving
                return true;
            }
        }
    }

    return false;
}

bool uGridLayout::createAggregation(const QString &aggregationName, const QString &name)
{

    //First If it is created already. If it is, I check it as created
    for(TGridArrowConstIter iter=mArrows.begin(); iter != mArrows.end(); iter++)
    {
        if((*iter)->equals(aggregationName, name, uAggregation)){
            (*iter)->setDeleted(false);
            return false;
        }
    }

    uGridArrow * arrow = new uGridArrow(aggregationName, name, uAggregation);
    mArrows.push_back(arrow);

    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name || (*iter)->getName() == aggregationName) {
            (*iter)->addReference(arrow);
        }
    }

    return true;
}

bool uGridLayout::createInheritance(const QString &name, const QString &parent)
{
    for(TGridArrowConstIter iter=mArrows.begin(); iter != mArrows.end(); iter++)
    {
        if((*iter)->equals(name, parent, uInheritance)){
            (*iter)->setDeleted(false);
            return false;
        }
    }

    uGridArrow * arrow = new uGridArrow(name, parent, uInheritance);
    mArrows.push_back(arrow);

    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name || (*iter)->getName() == parent) {
            (*iter)->addReference(arrow);
        }
    }

    return true;
}

int uGridLayout::getAggregationIndex(const QString &name, const QString &reference) const
{
    for(unsigned int i = 0; i < mArrows.size(); i++)
    {
        if(mArrows[i]->equals(name, reference, uAggregation))
            return i;
    }

    return -1;
}

int uGridLayout::getInheritanceIndex(const QString &name, const QString &reference) const
{
    for(unsigned int i = 0; i < mArrows.size(); i++)
    {
        if(mArrows[i]->equals(name, reference, uInheritance))
            return i;
    }

    return -1;
}

void uGridLayout::addSegmentToArrow(int arrowIndex, int mX, int mY, int mWidth, int mHeight) const
{
    mArrows[arrowIndex]->addSegment(uGridObjectFactory::createSegment(mX, mY, mX + mWidth, mY + mHeight));
    uDebugPrinter::printText("added segment ("+to_string(mX)+","+ to_string(mY) +"), size("+ to_string(mWidth) +","+ to_string(mHeight) +") "
                              "to arrow: " + to_string(arrowIndex));
}

void uGridLayout::deleteNonExistentArrows()
{
    for(TGridArrowConstIter iter = mArrows.begin(); iter != mArrows.end(); iter++)
        if((*iter)->getDeleted()){
            mArrows.erase(iter);
            deleteNonExistentArrows();
            return;
        }
}

void uGridLayout::setArrowsDeleted()
{
    for(TGridArrowConstIter iter = mArrows.begin(); iter != mArrows.end(); iter++)
        (*iter)->setDeleted(true);
}

QString uGridLayout::getString(int x, int y) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->selected(x, y)) {
            return (*iter)->getName();
        }
    }
    return "";
}

int uGridLayout::getArrowSelected(int x, int y) const
{
    for(int i = 0; i < mArrows.size(); i++)
    {
        if(mArrows[i]->selected(x,y) >= 0)
            return i;
    }
    return -1;
}

void uGridLayout::modifyArrow(int index, int oldX, int oldY, int newX, int newY)
{
    mArrows[index]->moveSegments(oldX, oldY, newX, newY);
}

int uGridLayout::getWidth() const
{
    return mWidth;
}

int uGridLayout::getHeight() const
{
    return mHeight;
}

int uGridLayout::getArrowsSize() const
{
    return mArrows.size();
}

int uGridLayout::getArrowSize(int index) const
{
    return mArrows[index]->getSize();
}

int uGridLayout::getArrowType(int index) const
{
    return mArrows[index]->getType();
}

bool uGridLayout::setWidth(int width)
{
    if (width < 0) return false;

    double ratio = (double)width/(double)mWidth;

    mWidth = width;

    //resize elements in grid
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++)
        (*iter)->resizeX(ratio);

    for(TGridArrowConstIter iter=mArrows.begin(); iter != mArrows.end(); iter++){
        int destX = getClassX((*iter)->getDestination());
        int destWidth = getClassWidth((*iter)->getDestination());
        (*iter)->resizeX(ratio, destX, destWidth);
    }

    //uDebugPrinter::printText("Set grid width: " + to_string(width));
    return true;
}

bool uGridLayout::setHeight(int height)
{
    if (height < 0) return false;

    double ratio = (double)height/(double)mHeight;

    mHeight = height;

    //resize elements in grid
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++)
        (*iter)->resizeY(ratio);

    for(TGridArrowConstIter iter=mArrows.begin(); iter != mArrows.end(); iter++){
        int destY = getClassY((*iter)->getDestination());
        int destHeight = getClassHeight((*iter)->getDestination());
        (*iter)->resizeY(ratio, destY, destHeight);
    }

    //uDebugPrinter::printText("Set grid height: " + to_string(height));
    return true;
}

int uGridLayout::getClassWidth(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getWidth();
        }
    }
    return -1;
}

int uGridLayout::getClassHeight(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getHeight();
        }
    }
    return -1;
}

int uGridLayout::getClassX(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getX();
        }
    }
    return -1;
}

int uGridLayout::getClassY(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getY();
        }
    }
    return -1;
}

int uGridLayout::getClassX_to(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getX_to();
        }
    }
    return -1;
}

int uGridLayout::getClassY_to(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return (*iter)->getY_to();
        }
    }
    return -1;
}

int uGridLayout::getSegmentX(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getX();
}

int uGridLayout::getSegmentY(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getY();
}

int uGridLayout::getSegmentX_to(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getX_to();
}

int uGridLayout::getSegmentY_to(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getY_to();
}

int uGridLayout::getSegmentWidth(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getWidth();
}

int uGridLayout::getSegmentHeight(int arrowIndex, int segIndex) const
{
    return mArrows[arrowIndex]->getSegment(segIndex)->getHeight();
}

bool uGridLayout::isEmpty(int x, int y) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->selected(x, y)) {
            return false;
        }
    }
    return true;
}

bool uGridLayout::contains(const QString &name) const
{
    for(TGridClassConstIter iter=mTable.begin(); iter != mTable.end(); iter++) {
        if ((*iter)->getName() == name) {
            return true;
        }
    }
    return false;
}

bool uGridLayout::checkBounds(int i, int j, int width, int height) const
{
    return (i + width <mWidth && j + height <mHeight && i>=0 && j >= 0);
}

bool uGridLayout::checkBounds(int i, int j) const
{
    return (i <mWidth && j <mHeight && i>=0 && j >= 0);
}


