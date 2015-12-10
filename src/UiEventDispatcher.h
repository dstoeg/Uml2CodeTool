#ifndef UIEVENTDISPATCHER_H
#define UIEVENTDISPATCHER_H

#include <QObject>
#include <QString>
#include <string>
#include "uStringConverter.h"
#include "uClassType.h"
#include "uLanguageStrategy.h"
#include "uCodeGenerationVisitor.h"
#include "uClassDiagram.h"
#include "uCodeGenerationVisitor.h"
#include "uClassFactory.h"
#include "uButton.h"
#include "uInheritable.h"


class UiEventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit UiEventDispatcher(QObject *parent = 0);
    Q_INVOKABLE void createClass(QString name, QString parent, QString methods, QString attributes);
    Q_INVOKABLE void updateClass(QString oldName, QString newName, QString parent, QString methods, QString attributes);

    Q_INVOKABLE void setClassState(int type);

    Q_INVOKABLE void setLanguage(QString language);
    Q_INVOKABLE void generateCode();

    Q_INVOKABLE int getDiagramSize();
    Q_INVOKABLE uInheritable * getClass(int index);
    Q_INVOKABLE void removeClass(uInheritable * obj);
    Q_INVOKABLE void removeClass(QString name);

    Q_INVOKABLE QString getClassName(int index);
    Q_INVOKABLE QString getParentName(int index);
    Q_INVOKABLE QString getClassMethods(int index);
    Q_INVOKABLE QString getClassAttributes(int index);
    Q_INVOKABLE int getClassIndex(QString name);

signals:

public slots:

private:

    // link application logic with GUI
    bool mCreateDoxyGenComments;
    std::string folderName;
    std::string projectFile;
    uButton * mClassButton;
    uClassDiagram * mClassDiagram;
    uCodeGenerationVisitor * mCodeGenerator;

};

#endif // UIEVENTDISPATCHER_H
