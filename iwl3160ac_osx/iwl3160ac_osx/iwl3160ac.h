
#ifndef MAC_OS_X_VERSION_MIN_REQUIRED

#ifndef MAC_OS_X_VERSION_10_4
#define MAC_OS_X_VERSION_10_4 1040
#endif

#ifdef __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
#define MAC_OS_X_VERSION_MIN_REQUIRED __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
#else
#define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_4
#endif

#endif

#include <IOKit/IOService.h>
#include "sharedkernel.h"

struct MySampleStruct;

class SimpleDriverClassName : public IOService
{
    
#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
    OSDeclareDefaultStructors(com_apple_dts_driver_SimpleDriver_10_4)
#else
    OSDeclareDefaultStructors(com_apple_dts_driver_SimpleDriver)
#endif
    
public:

    virtual bool init(OSDictionary* dictionary = 0);
    virtual void free(void);
    
    virtual IOService* probe(IOService* provider, SInt32* score);
    
    virtual bool start(IOService* provider);
    virtual void stop(IOService* provider);
    
    virtual bool willTerminate(IOService* provider, IOOptionBits options);
    virtual bool didTerminate(IOService* provider, IOOptionBits options, bool* defer);
    
    virtual bool terminate(IOOptionBits options = 0);
    virtual bool finalize(IOOptionBits options);
    
    virtual IOReturn ScalarIStructI(uint32_t inNumber, MySampleStruct* inStruct, uint32_t inStructSize);
    virtual IOReturn ScalarIStructO(uint32_t inNumber1, uint32_t inNumber2, MySampleStruct* outStruct, uint32_t* outStructSize);
    virtual IOReturn ScalarIScalarO(uint32_t inNumber1, uint32_t inNumber2, uint32_t* outNumber);
    virtual IOReturn StructIStructO(MySampleStruct* inStruct, MySampleStruct* outStruct, uint32_t inStructSize, uint32_t* outStructSize);
};