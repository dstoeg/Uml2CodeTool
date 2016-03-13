#ifndef UGRIDOBJECT_H
#define UGRIDOBJECT_H

#include <QString>



/**
 * @brief The uGridObjectType enum specifies the kind of objevt in the grid
 */

enum uGridObjectType {
    gClass,
    gSegment,
    gArrow
};

//static uGridObjectType intToGridType(int n)
//{
//    if(n == 1)
//        return gSegment;

//    if(n == 2)
//        return gArrow;

//    return gClass;
//}

class uGridObject
{
public:
    //Constructors
    uGridObject(int mX, int mY, int mWidth, int mHeight);
    virtual ~uGridObject();

    virtual bool selected(int x, int y) const;

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    bool setX(int newX);
    bool setY(int newY);
    bool setWidth(int newWidth);
    bool setHeight(int newHeight);

protected:
    int mX;
    int mY;
    int mWidth;
    int mHeight;

};

//Redefinition of collections and iterators
typedef std::vector<uGridObject*> TGridObject;
typedef std::vector<uGridObject*>::iterator TGridObjectIter;
typedef std::vector<uGridObject*>::const_iterator TGridObjectConstIter;

#endif // UGRIDOBJECT_H
