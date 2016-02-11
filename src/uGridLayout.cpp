#include "uGridLayout.h"
#include "uDebugPrinter.h"

#include <string>

using namespace std;

uGridLayout::uGridLayout(QObject *parent) : QObject(0)
{

}

uGridLayout::uGridLayout(int width, int height) : QObject(0)
{
    mWidth = width;
    mHeight = height;

    for(size_t i=0; i<mWidth; ++i) {
        std::vector<QString> vec;
        for (size_t j=0; j<mHeight; ++j) {
            vec.push_back("");
        }
        mTable.push_back(vec);
    }

}

bool uGridLayout::addClass(int i, int j, const QString &name)
{
    //uDebugPrinter::printText("adding class: " + name.toStdString() + " index i: " + to_string(i) + " index j: " + to_string(j));
    if (!checkBounds(i,j)) return false;

    mTable[i][j] = name;
    return true;
}


bool uGridLayout::removeClass(const QString &name)
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

bool uGridLayout::moveClass(const QString &name, const QString &newName, int newI, int newJ)
{
    if (!checkBounds(newI,newJ)) return false;

    if (removeClass(name)) {
        addClass(newI, newJ, newName);
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

QString uGridLayout::getString(int i, int j) const
{
    if (!checkBounds(i,j)) return "";
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

int uGridLayout::getI(const QString &name) const
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

int uGridLayout::getJ(const QString &name) const
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
    if (!checkBounds(i,j)) return false;
    return mTable[i][j] == "";
}

bool uGridLayout::contains(const QString &name) const
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

