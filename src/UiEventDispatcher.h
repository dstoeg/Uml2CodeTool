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


class UiEventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit UiEventDispatcher(QObject *parent = 0);
    Q_INVOKABLE void createClass(QString name);
    Q_INVOKABLE void createClass(QString name, QString parent, QString methods, QString attributes);

    Q_INVOKABLE void setClassState(int type);

    Q_INVOKABLE void setLanguage(QString language);
    Q_INVOKABLE void generateCode();

signals:

public slots:

private:

    // link application logic with GUI
    bool mCreateDoxyGenComments;
    std::string folderName;
    std::string projectFile;
    uClassType mSelectedClassState;
    uClassDiagram mClassDiagram;
    uCodeGenerationVisitor * mCodeGenerator;

};

#endif // UIEVENTDISPATCHER_H
