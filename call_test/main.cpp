/*
 * Copyright 2012, Ruediger Gad <r.c.g@gmx.de>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QtDeclarative>

#include "a.h"
#include "b.h"
#include "c.h"
#include "d.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    // Make C++ classes available to QML.
    qmlRegisterType<A>("test", 1, 0, "A");
    qmlRegisterType<B>("test", 1, 0, "B");
    qmlRegisterType<C>("test", 1, 0, "C");
    qmlRegisterType<D>("test", 1, 0, "D");

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/call_test/main.qml"));
    viewer->showExpanded();

    return app->exec();
}
