#include "main_window.h"
#include "font_loader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SplashScreen window;
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();
}