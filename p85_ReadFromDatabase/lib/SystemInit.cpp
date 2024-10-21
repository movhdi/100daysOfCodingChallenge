#include <SystemInit.hpp>
#include <iostream>
#include <logging.hpp>

SystemInit::SystemInit()
{
    std::cout << "SystemInit constructor called";
}

SystemInit &SystemInit::getInstance()
{
    // TODO: insert return statement here
    static SystemInit instance;
    return instance;
}


bool SystemInit::initializeSystem()
{
    // TODO: initialize logging system here
    std::cout << "system initialized from out stream!\n";
    LOG_info << "system initialized from LogInfo\n";
    systeminitialized = true;
    return systeminitialized;
}

SystemInit::~SystemInit()
{
}
