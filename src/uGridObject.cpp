#include "uGridObject.h"
#include "uDebugPrinter.h"

#include <string>

using namespace std;

uGridObject::uGridObject(int mX, int mY, int mWidth, int mHeight)
{
    //uDebugPrinter::printText("Creating object: " + mName.toStdString() + ", size (" + to_string(mWidth) + "," + to_string(mHeight) + "), position:(" + to_string(mX) + "," + to_string(mY)+")");
    this->mX = mX;
    this->mY = mY;
    this->mHeight = mHeight;
    this->mWidth = mWidth;
}

uGridObject::~uGridObject()
{

}

bool uGridObject::selected(int x, int y) const
{
    return ((this->mX + this->mWidth) >= x ) && ((mY + mHeight) >= y)
            && mX <=x && mY <= y;
}

int uGridObject::getX() const
{
    return mX;
}

int uGridObject::getY() const
{
    return mY;
}

int uGridObject::getWidth() const
{
    return mWidth;
}

int uGridObject::getHeight() const
{
    return mHeight;
}


bool uGridObject::setX(int newX)
{
    //TODO add comparison >= with GridLayout max width
    if(newX < 0) return false;
    this->mX = newX;
    return true;
}

bool uGridObject::setY(int newY)
{
    //TODO add comparison >= with GridLayout max height
    if(newY < 0) return false;
    this->mY = newY;
    return true;
}

bool uGridObject::setWidth(int newWidth)
{
    //TODO add comparison with GridLayout limits
    if(newWidth < 0) return false;
    this->mWidth = newWidth;
    return true;
}

bool uGridObject::setHeight(int newHeight)
{
    //TODO add comparison with GridLayout limits
    if (newHeight < 0) return false;
    this->mHeight = newHeight;
    return true;
}

