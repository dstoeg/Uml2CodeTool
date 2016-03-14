#include "uGridClass.h"

uGridClass::uGridClass(int mX, int mY, int mX_to, int mY_to, QString mName): uGridObject(mX, mY, mX_to, mY_to)
{
    this->mName = mName;
}

bool uGridClass::selected(int x, int y) const
{
    return ((this->mX_to) >= x ) && ((mY_to) >= y)
            && mX <=x && mY <= y;
}

bool uGridClass::notifyMovement(int movX, int movY)
{
    for(TGridArrowConstIter iter = mArrows.begin(); iter != mArrows.end(); iter++)
    {
        if(!(*iter)->notifyMovement(mName, movX, movY))
            return false;
    }

    return true;
}

bool uGridClass::setName(const QString &newName)
{
    if( newName.toStdString() == "") return false;
    this->mName = newName;
    return true;
}

QString uGridClass::getName() const
{
    return mName;
}

bool uGridClass::addReference(uGridArrow *arrow)
{
    mArrows.push_back(arrow);
}

