#include "uGridClass.h"

uGridClass::uGridClass(int mX, int mY, int mWidth, int mHeight, QString mName): uGridObject(mX, mY, mWidth, mHeight)
{
    this->mName = mName;
    this->mPrinted = false;
}

bool uGridClass::selected(int x, int y) const
{
    return ((this->mX + this->mWidth) >= x ) && ((mY + mHeight) >= y)
            && mX <=x && mY <= y;
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

