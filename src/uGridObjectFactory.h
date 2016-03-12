#ifndef UGRIDOBJECTFACTORY_H
#define UGRIDOBJECTFACTORY_H

#include "uGridObject.h"
#include "uGridClass.h"
#include "uGridSegment.h"

class uGridObjectFactory
{
public:
    static uGridObjectFactory &getInstance();
    static uGridObject * createObject(int mX, int mY, int mWidth, int mHeight, QString mName, uGridObjectType type);

private:
    //Singleton template
    uGridObjectFactory();
    uGridObjectFactory(uGridObjectFactory const&);
    void operator=(uGridObjectFactory const&);

    uGridClass * createClass(int mX, int mY, int mWidth, int mHeight, QString mName);
    uGridSegment * createSegment(int mX, int mY, int mWidth, int mHeight, QString mName);
    //TODO
    //uGridObject * createArrow();
};

#endif // UGRIDOBJECTFACTORY_H
