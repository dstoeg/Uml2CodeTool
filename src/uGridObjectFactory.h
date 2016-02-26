#ifndef UGRIDOBJECTFACTORY_H
#define UGRIDOBJECTFACTORY_H

#include "uGridObject.h"

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

    uGridObject * createClass(int mX, int mY, int mWidth, int mHeight, QString mName);
    //TODO
    //uGridObject * createSegment();
    //uGridObject * createArrow();
};

#endif // UGRIDOBJECTFACTORY_H
