#include "uGridSegment.h"
#include <math.h>

uGridSegment::uGridSegment(int mX, int mY, int mWidth, int mHeight, QString mName): uGridObject(mX, mY, mWidth, mHeight, mName)
{
    this->mPrinted = true;
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
