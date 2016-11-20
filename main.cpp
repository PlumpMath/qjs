#include <QCoreApplication>
#include <QFile>
#include <QJSEngine>
#include <QTextStream>
#include <QDebug>

#include "Console.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QJSEngine js;
    Console consoleObj;
    QJSValue console = js.newQObject(&consoleObj);
    js.globalObject().setProperty("window", js.globalObject());
    js.globalObject().setProperty("print", console.property("print"));

    int ret = 0;

    if (argc >= 2) {
        int i = 1;
        while (i < argc) {
            QString filename = argv[i++];
            QFile f(filename);
            if (!f.open(QFile::ReadOnly | QFile::Text)) return 1;
            QTextStream in(&f);
            QString source = in.readAll();
            QJSValue result = js.evaluate(source, filename);
            if (result.isError()) {
                QString line(result.property("lineNumber").toString());
                QString error(result.toString());
                consoleObj.print(filename + ":" + line + " " + error);
                ret = 1;
                break;
            }
        }
    }

    return ret;
}
