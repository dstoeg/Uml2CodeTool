#include "uGridClass.h"

uGridClass::uGridClass(int mX, int mY, int mWidth, int mHeight, QString mName): uGridObject(mX, mY, mWidth, mHeight, mName)
{
    this->mPrinted = false;
}

bool uGridClass::selected(int x, int y) const
{
    return ((this->mX + this->mWidth) >= x ) && ((mY + mHeight) >= y)
            && mX <=x && mY <= y;
}

