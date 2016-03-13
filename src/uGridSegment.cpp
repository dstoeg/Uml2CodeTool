#include "uGridSegment.h"
#include "uDebugPrinter.h"
#include <math.h>
#include <string>


uGridSegment::uGridSegment(int mX, int mY, int mWidth, int mHeight): uGridObject(mX, mY, mWidth, mHeight)
{
    this->mPrinted = false;
}

bool uGridSegment::selected(int x, int y) const
{
    //general line ecuation r: Ax + By + C = 0
    // mP = (mX, mY), mVector = (mWidth,mHeight)
    // A = mHeight, B = -mWidth, C = mWidth*mY - mHeight*mX
    // d((x,y), r) = |Ax + By + C|/sqrt(A*A + B*B)

    float epsilon = 3;
    float distance = (float)abs(mHeight*x - mWidth*y + (mWidth*mY - mHeight*mX))
            /sqrt((float)mHeight*mHeight + mWidth*mWidth);
    return distance < epsilon;
}

void uGridSegment::setPrinted(bool printed)
{
    mPrinted = printed;
}

bool uGridSegment::pivoteMovement(int oldX, int oldY, int newX, int newY)
{
    if(oldX == mX && oldY == mY){
        mX = newX;
        mY = newY;
        return true;
    }

    if(oldX == mX + mWidth && oldY == mY + mHeight){
        mWidth = newX - mX;
        mHeight = newY - mY;
        return true;
    }

//    uDebugPrinter::printText("Pivote movement failed in (" + to_string(oldX) + "," + to_string(oldY) +
//                             ") to (" + to_string(newX) + "," + to_string(newY) + ")");
    return false;
}
