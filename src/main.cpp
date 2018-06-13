#include <QtWidgets/QApplication>
#include "include/RobotSensesControl.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RobotSensesControl robotsensescontrol;
    robotsensescontrol.show();
    return app.exec();
}
