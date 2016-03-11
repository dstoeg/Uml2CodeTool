#ifndef UGRIDSEGMENT_H
#define UGRIDSEGMENT_H

#include "uGridObject.h"
#include <QString>

class uGridSegment: public uGridObject
{
public:
    uGridSegment(int mX, int mY, int mWidth, int mHeight, QString mName);
    virtual ~uGridSegment(){}

    virtual bool selected(int x, int y) const;
};

#endif // UGRIDSEGMENT_H
