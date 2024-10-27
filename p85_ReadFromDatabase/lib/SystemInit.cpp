#include <SystemInit.hpp>
#include <iostream>
#include <logging.hpp>

SystemInit::SystemInit()
{
}

SystemInit &SystemInit::getInstance()
{
    static SystemInit instance;
    return instance;
}


bool SystemInit::initializeSystem()
{
    // initialize logging system here
    logging_sys::init("../logconf.ini");
    LOG_info << "system initialized";
    systeminitialized = true;
    return systeminitialized;
}

SystemInit::~SystemInit()
{
}
