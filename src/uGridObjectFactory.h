#ifndef UGRIDOBJECTFACTORY_H
#define UGRIDOBJECTFACTORY_H

#include "uGridObject.h"
#include "uGridClass.h"
#include "uGridSegment.h"

class uGridObjectFactory
{
public:
    static uGridObjectFactory &getInstance();
    static uGridClass * createClass(int mX, int mY, int mWidth, int mHeight, QString mName);
    static uGridSegment * createSegment(int mX, int mY, int mWidth, int mHeight);

    //TODO
    //uGridObject * createArrow();

private:
    //Singleton template
    uGridObjectFactory();
    uGridObjectFactory(uGridObjectFactory const&);
    void operator=(uGridObjectFactory const&);

};

#endif // UGRIDOBJECTFACTORY_H
