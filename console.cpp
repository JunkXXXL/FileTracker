#include "console.h"

Console::Console()
{

}

Console::~Console()
{

}

Console& Console::Instance()
{
    static Console c;
    return c;
}


