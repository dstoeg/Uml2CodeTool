#ifndef UGRIDCLASS_H
#define UGRIDCLASS_H

#include "uGridObject.h"
#include <QString>

class uGridClass: public uGridObject
{
public:
    uGridClass(int mX, int mY, int mWidth, int mHeight, QString mName);
    virtual ~uGridClass(){}

    virtual bool selected(int x, int y) const;
};

#endif // UGRIDCLASS_H
