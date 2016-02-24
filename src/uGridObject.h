#ifndef UGRIDOBJECT_H
#define UGRIDOBJECT_H

#include <QString>

class uGridObject
{
public:

    //Constructors
    //explicit uGridObject();
    uGridObject(int mX, int mY, int mWidth, int mHeight, const QString &mName);
    virtual ~uGridObject();

    virtual bool selected(int x, int y) const;

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    QString getName() const;

    bool setX(int newX);
    bool setY(int newY);
    bool setWidth(int newWidth);
    bool setHeight(int newHeight);
    bool setName(const QString &newName);

protected:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    QString mName;

};

//Redefinition of collections and iterators
typedef std::vector<uGridObject*> TGridObject;
typedef std::vector<uGridObject*>::iterator TGridObjectIter;
typedef std::vector<uGridObject*>::const_iterator TGridObjectConstIter;

#endif // UGRIDOBJECT_H
