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
    uGridObject(int mX, int mY, int mX_to, int mY_to);
    virtual ~uGridObject();

    virtual bool selected(int x, int y) const;

    //Getters
    int getX() const;
    int getY() const;
    int getX_to() const;
    int getY_to() const;
    int getWidth() const;
    int getHeight() const;

    //Setters
    bool setX(int newX);
    bool setY(int newY);
    bool setX_to(int newX);
    bool setY_to(int newY);
    void resizeX(double ratio);
    void resizeY(double ratio);

protected:
    int mX;
    int mY;
    int mX_to;
    int mY_to;

};

//Redefinition of collections and iterators
typedef std::vector<uGridObject*> TGridObject;
typedef std::vector<uGridObject*>::iterator TGridObjectIter;
typedef std::vector<uGridObject*>::const_iterator TGridObjectConstIter;

#endif // UGRIDOBJECT_H
