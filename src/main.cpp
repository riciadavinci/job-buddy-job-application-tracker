#include <QApplication>
#include <QQmlApplicationEngine>



int main(int argc, char** argv) {
    QApplication app(argc, argv);

    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));

    QQmlApplicationEngine engine;
    engine.load(url);

    return app.exec();
}