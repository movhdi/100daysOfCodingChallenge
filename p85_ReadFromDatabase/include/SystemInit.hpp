#ifndef SYSTEMINIT_HPP
#define SYSTEMINIT_HPP



class SystemInit
{
private:
    bool systeminitialized = false;
    bool logInitialize();
    SystemInit();
public:
    static SystemInit& getInstance();
    bool initializeSystem();
    
    // delete copy constructor and assingment operator avoiding multiple instances
    SystemInit(SystemInit&) = delete;
    SystemInit& operator=(const SystemInit&) = delete;
    ~SystemInit();
};

#endif