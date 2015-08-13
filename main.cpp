#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include "mandelbrot.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Mandelbrot>("Fractals", 1, 0, "Mandelbrot");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();
    return app.exec();
}
