#include "Console.h"

Console::Console()
    : out(stdout)
{
}

Console::~Console()
{
}

QJSValue Console::print(QString s)
{
    out << s + "\n";
    return QJSValue();
}

