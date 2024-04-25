#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CReadFile.h"
#include "CFantasyMovies.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CReadFile readFile;
    CFantasyMovies fantasyMovies;

    engine.rootContext()->setContextProperty("readFile", &readFile);
    engine.rootContext()->setContextProperty("fantasyMovies", &fantasyMovies);
    qmlRegisterType<CFantasyMovies>("MyCompany", 1, 0, "CFantasyMovies");

    // Connect the moviesLoaded signal to the CFantasyMovies slot
    QObject::connect(&readFile, &CReadFile::moviesLoaded, &fantasyMovies, [&engine](QStack<QString> stackOdd, QStack<QString> stackEven){
        engine.rootContext()->setContextProperty("stackOdd", QVariant::fromValue(stackOdd));
        engine.rootContext()->setContextProperty("stackEven", QVariant::fromValue(stackEven));
    });

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    // Load and organize the movies from the input file
    readFile.readAndOrganizeMovies();

    return app.exec();
}
