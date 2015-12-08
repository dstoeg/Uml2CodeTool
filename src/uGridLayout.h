#ifndef UGRIDLAYOUT_H
#define UGRIDLAYOUT_H

#include <QObject>
#include <vector>
#include <string>

class uGridLayout : public QObject
{
    Q_OBJECT
public:
    explicit uGridLayout(QObject *parent = 0);
    uGridLayout(int width, int height);

    bool addClass(int i, int j, std::string const& name);
    bool removeClass(std::string const& name);
    bool removeClass(int i, int j);
    bool moveClass(std::string const& name, int newI, int newJ);
    bool moveClass(int i, int j, int newI, int newJ);

    std::string const& getString(int i, int j) const;

    int getWidth() const;
    int getHeight() const;

    bool setWidth(int width);
    bool setHeight(int height);

    int getI(std::string const& name) const;
    int getJ(std::string const& name) const;

    bool isEmpty(int i, int j) const;
    bool contains(std::string const& name) const;

signals:

public slots:

private:
    int mWidth;
    int mHeight;
    std::vector<std::vector<std::string>> mTable;
    bool checkBounds(int i, int j) const;

};

#endif // UGRIDLAYOUT_H
