#include "D3D11Window.hpp"
#include <QGuiApplication>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    D3D11Window window;
    window.show();

    return app.exec();
}
