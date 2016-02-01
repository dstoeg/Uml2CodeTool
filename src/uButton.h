#ifndef UBUTTON_H
#define UBUTTON_H

#include "uInheritable.h"
#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

#include <vector>

#include <QObject>

/**
 * @brief The uButton class is the abstract class that defines the structure of every button (uChildButton, uClassButton and uInterfaceButton).
 * It is a Q_OBJECT so the QML types in the user interface can interact with it.
 * It is also a Singleton because we only need one.
 */

class uButton : public QObject
{
    Q_OBJECT
public:

    Q_INVOKABLE virtual void update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable* base) {}
    Q_INVOKABLE virtual void create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base = NULL) {}
    static uButton &getInstance();

protected:
    uButton(QObject * parent = 0);
    uButton(uButton const&);
    void operator=(uButton const&);
};

#endif // UBUTTON_H
