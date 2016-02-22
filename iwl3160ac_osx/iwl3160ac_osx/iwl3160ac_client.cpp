#include <IOKit/IOLib.h>
#include "SimpleDriver.h"

#define super IOService

#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
OSDefineMetaClassAndStructors(com_apple_dts_driver_SimpleDriver_10_4, IOService)
#else
OSDefineMetaClassAndStructors(com_apple_dts_driver_SimpleDriver, IOService)
#endif

bool SimpleDriverClassName::start(IOService* provider)
{
    bool	success;
    
    IOLog("%s[%p]::%s(%p)\n", getName(), this, __FUNCTION__, provider);
    
    success = super::start(provider);
    
    if (success) {

        registerService();
    }
    
    return success;
}

void SimpleDriverClassName::stop(IOService* provider)
{
    IOLog("%s[%p]::%s(%p)\n", getName(), this, __FUNCTION__, provider);
    
    super::stop(provider);
}

bool SimpleDriverClassName::init(OSDictionary* dictionary)
{
    if (!super::init(dictionary)) {
        return false;
    }
    
    IOLog("%s[%p]::%s(%p)\n", getName(), this, __FUNCTION__, dictionary);
    
    return true;
}

void SimpleDriverClassName::free(void)
{
    IOLog("%s[%p]::%s()\n", getName(), this, __FUNCTION__);
    
    super::free();
}

IOService* SimpleDriverClassName::probe(IOService* provider, SInt32* score)
{
    IOLog("%s[%p]::%s(%p, %p)\n", getName(), this, __FUNCTION__, provider, score);
    
    IOService *res = super::probe(provider, score);
    
    return res;
}

bool SimpleDriverClassName::willTerminate(IOService* provider, IOOptionBits options)
{
    IOLog("%s[%p]::%s(%p, %ld)\n", getName(), this, __FUNCTION__, provider, options);
    
    return super::willTerminate(provider, options);
}

bool SimpleDriverClassName::didTerminate(IOService* provider, IOOptionBits options, bool* defer)
{
    IOLog("%s[%p]::%s(%p, %ld, %p)\n", getName(), this, __FUNCTION__, provider, options, defer);
    
    return super::didTerminate(provider, options, defer);
}

bool SimpleDriverClassName::terminate(IOOptionBits options)
{
    bool	success;
    
    IOLog("%s[%p]::%s(%ld)\n", getName(), this, __FUNCTION__, options);
    
    success = super::terminate(options);
    
    return success;
}

bool SimpleDriverClassName::finalize(IOOptionBits options)
{
    bool	success;
    
    IOLog("%s[%p]::%s(%ld)\n", getName(), this, __FUNCTION__, options);
    
    success = super::finalize(options);
    
    return success;
}


IOReturn SimpleDriverClassName::ScalarIStructI(uint32_t inNumber, MySampleStruct* inStruct, uint32_t inStructSize)
{
    IOLog("%s[%p]::%s(inNumber = %d, field1 = %lld, field1 = %lld, inStructSize = %d)\n", getName(), this, __FUNCTION__,
          inNumber, inStruct->field1, inStruct->field2, inStructSize);
    
    return kIOReturnSuccess;
}


IOReturn SimpleDriverClassName::ScalarIStructO(uint32_t inNumber1, uint32_t inNumber2, MySampleStruct* outStruct, uint32_t* outStructSize)
{
    IOLog("%s[%p]::%s(inNumber1 = %d, inNumber2 = %d)\n", getName(), this, __FUNCTION__, inNumber1, inNumber2);
    
    outStruct->field1 = inNumber1;
    outStruct->field2 = inNumber2;
    *outStructSize = sizeof(MySampleStruct);
    
    return kIOReturnSuccess;
}


IOReturn SimpleDriverClassName::ScalarIScalarO(uint32_t inNumber1, uint32_t inNumber2, uint32_t* outNumber)
{
    IOLog("%s[%p]::%s(inNumber1 = %d, inNumber2 = %d)\n", getName(), this, __FUNCTION__, inNumber1, inNumber2);
    
    *outNumber = inNumber1 * inNumber2;
    
    return kIOReturnSuccess;
}


IOReturn SimpleDriverClassName::StructIStructO(MySampleStruct* inStruct, MySampleStruct* outStruct, uint32_t inStructSize, uint32_t* outStructSize)
{
    IOLog("%s[%p]::%s(field1 = %lld, field2 = %lld, inStructSize = %d)\n", getName(), this, __FUNCTION__,
          inStruct->field1, inStruct->field2, inStructSize);
 
    outStruct->field1 = inStruct->field1;
    outStruct->field2 = inStruct->field2;
    *outStructSize = sizeof(MySampleStruct);
    
    return kIOReturnSuccess;
}