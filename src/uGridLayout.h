#ifndef UGRIDLAYOUT_H
#define UGRIDLAYOUT_H

#include <QObject>
#include <QString>
#include <vector>

class uGridLayout : public QObject
{
    Q_OBJECT
public:
    explicit uGridLayout(QObject *parent = 0);
    uGridLayout(int width, int height);

    Q_INVOKABLE bool addClass(int i, int j, QString const& name);
    Q_INVOKABLE bool removeClass(QString const& name);
    Q_INVOKABLE bool removeClass(int i, int j);
    Q_INVOKABLE bool moveClass(QString const& name, int newI, int newJ);
    Q_INVOKABLE bool moveClass(int i, int j, int newI, int newJ);

    Q_INVOKABLE QString const& getString(int i, int j) const;

    Q_INVOKABLE int getWidth() const;
    Q_INVOKABLE int getHeight() const;

    bool setWidth(int width);
    bool setHeight(int height);

    Q_INVOKABLE int getI(QString const& name) const;
    Q_INVOKABLE int getJ(QString const& name) const;

    Q_INVOKABLE bool isEmpty(int i, int j) const;
    Q_INVOKABLE bool contains(QString const& name) const;

signals:

public slots:

private:
    int mWidth;
    int mHeight;
    std::vector<std::vector<QString>> mTable;
    bool checkBounds(int i, int j) const;

};

#endif // UGRIDLAYOUT_H
