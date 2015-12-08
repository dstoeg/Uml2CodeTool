#include "uGridLayout.h"

using namespace std;

uGridLayout::uGridLayout(QObject *parent) : QObject(parent)
{

}

uGridLayout::uGridLayout(int width, int height) : QObject(0)
{
    mWidth = width;
    mHeight = height;

    for(size_t i=0; i<mWidth; ++i) {
        for (size_t j=0; j<mHeight; ++j) {
            mTable[i][j] = "";
        }
    }

}

bool uGridLayout::addClass(int i, int j, const string &name)
{
    if (!checkBounds(i,j)) return false;

    mTable[i][j] = name;
    return true;
}

bool uGridLayout::removeClass(const string &name)
{
    for(size_t i=0; i<mWidth; ++i) {
        for (size_t j=0; j<mHeight; ++j) {
            if (mTable[i][j] == name) {
                mTable[i][j] = "";
                return true;
            }
        }
    }
    return false;
}

bool uGridLayout::removeClass(int i, int j)
{
    if (!checkBounds(i,j)) return false;

    mTable[i][j] = "";
    return true;
}

bool uGridLayout::moveClass(const string &name, int newI, int newJ)
{
    if (!checkBounds(newI,newJ)) return false;

    if (removeClass(name)) {
        addClass(newI, newJ, name);
        return true;
    }
    return false;
}

bool uGridLayout::moveClass(int i, int j, int newI, int newJ)
{
    if (!checkBounds(newI,newJ) || isEmpty(i, j)) return false;

    bool ret = addClass(newI, newJ, getString(i, j));

    if (!removeClass(i, j)) return false;

    return ret;
}

const string &uGridLayout::getString(int i, int j) const
{
    if (!checkBounds(newI,newJ)) return "";

    return mTable[i][j];
}

int uGridLayout::getWidth() const
{
    return mWidth;
}

int uGridLayout::getHeight() const
{
    return mHeight;
}

bool uGridLayout::setWidth(int width)
{
    if (width < 0) return false;
    mWidth = width;
    return true;
}

bool uGridLayout::setHeight(int height)
{
    if (height < 0) return false;
    mHeight = height;
    return true;
}

int uGridLayout::getI(const string &name) const
{
    for(size_t i=0; i<mWidth; ++i) {
        for (size_t j=0; j<mHeight; ++j) {
            if (mTable[i][j] == name) {
                return i;
            }
        }
    }
    return -1;
}

int uGridLayout::getJ(const string &name) const
{
    for(size_t i=0; i<mWidth; ++i) {
        for (size_t j=0; j<mHeight; ++j) {
            if (mTable[i][j] == name) {
                return j;
            }
        }
    }
    return -1;
}

bool uGridLayout::isEmpty(int i, int j) const
{
    if (!checkBounds(newI,newJ)) return false;
    return mTable[i][j] == "";
}

bool uGridLayout::contains(const string &name) const
{
    for(size_t i=0; i<mWidth; ++i) {
        for (size_t j=0; j<mHeight; ++j) {
            if (mTable[i][j] == name) {
                return true;
            }
        }
    }
    return false;
}

bool uGridLayout::checkBounds(int i, int j) const
{
    return (i<mWidth && j<mHeight && i>=0 && j >= 0);
}

