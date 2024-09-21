#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <model/database/columnmodel.h>
#include <model/connection/database/connectiondatabasemodel.h>

#include <control/querypanelcontrol.h>
#include <control/mainscreencontrol.h>
#include <control/database/databasecontrol.h>
#include <control/connectiondatabasecontrol.h>

#include <view/model/tabledatamodel.h>
#include <view/model/tablequeryresultmodel.h>
#include <view/model/text/textdocumenthandlermodel.h>

void registerTypes() {

    // Controls

    qmlRegisterType<DatabaseControl>( "Control.DatabaseControl", 1, 0, "DatabaseControl" );
    qmlRegisterType<MainScreenControl>( "Control.MainScreenControl", 1, 0, "MainScreenControl" );
    qmlRegisterType<QueryPanelControl>( "Control.QueryPanelControl", 1, 0, "QueryPanelControl" );
    qmlRegisterType<ConnectionDatabaseControl>( "Control.ConnectionDatabaseControl", 1, 0, "ConnectionDatabaseControl" );

    // Models Objects

    qmlRegisterType<ColumnModel>("View.Model.ColumnModel", 1, 0, "ColumnModel");
    qmlRegisterType<ConnectionDatabaseModel>( "Model.ConnectionDatabaseModel", 1, 0, "ConnectionDatabaseModel" );

    qmlRegisterType<TextDocumentHandlerModel>( "Model.TextDocumentHandlerModel", 1, 0, "TextDocumentHandlerModel" );

    // Models View

    qmlRegisterType<TableDataModel>("View.Model.TableDataModel", 1, 0, "TableDataModel");
    qmlRegisterType<TableQueryResultModel>("View.Model.TableQueryResultModel", 1, 0, "TableQueryResultModel");

}

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Angel");
    app.setOrganizationDomain("Angel.br");
    app.setApplicationName("Angel");

    registerTypes();

    QQmlApplicationEngine engine;
    engine.addImportPath(":/components");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
