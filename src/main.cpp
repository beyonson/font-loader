#include "main_window.h"
#include "font_loader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SplashScreen splashScreen;
    splashScreen.show();
    
    return app.exec();
}