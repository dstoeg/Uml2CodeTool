#include "uGridSegment.h"
#include "uDebugPrinter.h"
#include <math.h>
#include <string>


uGridSegment::uGridSegment(int mX, int mY, int mX_to, int mY_to): uGridObject(mX, mY, mX_to, mY_to)
{

}

bool uGridSegment::selected(int x, int y) const
{
    //distance point-segment
    double epsilon = 5;

    double A = x - mX;
    double B = y - mY;
    double C = mX_to - mX;
    double D = mY_to - mY;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = dot / len_sq;

    double xx, yy;

    //if long segment == 0;
    if (param < 0 || (mX == mX_to && mY == mY_to)) {
        xx = mX;
        yy = mY;
    }
    else if (param > 1) {
        xx = mX_to;
        yy = mY_to;
    }
    else {
        xx = mX + param * C;
        yy = mY + param * D;
    }

    double dx = x - xx;
    double dy = y - yy;
    return sqrt(dx * dx + dy * dy) < epsilon;
}

bool uGridSegment::pivoteMovement(int oldX, int oldY, int newX, int newY)
{
    if(oldX == mX && oldY == mY){
        mX = newX;
        mY = newY;
        return true;
    }

    if(oldX == mX_to && oldY == mY_to){
        mX_to = newX;
        mY_to = newY;
        return true;
    }

    uDebugPrinter::printText("Pivote movement failed in (" + std::to_string(oldX) + "," + std::to_string(oldY) +
                             ") to (" + std::to_string(newX) + "," + std::to_string(newY) + ")");
    return false;
}
