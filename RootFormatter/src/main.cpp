#include "Logger/Logger.h"

#include "TS/tsexp.h"

int main()
try
{
    Logging::Logger::Init();

    tsexp();
    
    return 0;
}
catch (...)
{
    return 1;
}
