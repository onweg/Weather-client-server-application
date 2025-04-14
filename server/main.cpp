#include "httpserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::addLibraryPath("/opt/homebrew/Cellar/qt/6.9.0/share/qt/plugins");
    // qDebug() << "Доступные драйверы SQL:" << QSqlDatabase::drivers();

    HttpServer server;
    if (!server.start(33333)) {
        return -1;
    }

    return a.exec();
}
