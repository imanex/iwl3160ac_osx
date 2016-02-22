/*
				
	Change History (most recent first):

            2.0			08/13/2008			Add Leopard user client API for supporting 64-bit user processes.
											Now requires Xcode 3.0 or later to build.
			
			1.1			05/22/2007			User client performs endian swapping when called from a user process 
											running using Rosetta. Updated to produce a universal binary.
											Now requires Xcode 2.2.1 or later to build.
			
			1.0d3	 	01/14/2003			New sample.

*/


#include <IOKit/IOLib.h>
#include "SimpleDriver.h"

#define super IOService

// Even though we are defining the convenience macro super for the superclass, you must use the actual class name
// in the OS*MetaClass macros. Note that the class name is different when supporting Mac OS X 10.4.

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
		// Publish ourselves so clients can find us
		registerService();
	}
    
    return success;
}


// We override stop only to log that it has been called to make it easier to follow the driver's lifecycle.
void SimpleDriverClassName::stop(IOService* provider)
{
	IOLog("%s[%p]::%s(%p)\n", getName(), this, __FUNCTION__, provider);
    
    super::stop(provider);
}


// We override init only to log that it has been called to make it easier to follow the driver's lifecycle.
// Production drivers would only need to override init if they want to initialize data members.
bool SimpleDriverClassName::init(OSDictionary* dictionary)
{
    if (!super::init(dictionary)) {
        return false;
	}

	// This IOLog must follow super::init because getName relies on the superclass initialization.
	IOLog("%s[%p]::%s(%p)\n", getName(), this, __FUNCTION__, dictionary);

    // This is where you could set the initial value of your driver's data members.
	
	return true;
}


// We override free only to log that it has been called to make it easier to follow the driver's lifecycle.
void SimpleDriverClassName::free(void)
{
	IOLog("%s[%p]::%s()\n", getName(), this, __FUNCTION__);
    
    super::free();
}


// We override probe only to log that it has been called to make it easier to follow the driver's lifecycle.
// Production drivers can override probe if they need to make an active decision whether the driver is appropriate for
// the provider.
IOService* SimpleDriverClassName::probe(IOService* provider, SInt32* score)
{
	IOLog("%s[%p]::%s(%p, %p)\n", getName(), this, __FUNCTION__, provider, score);
        
    IOService *res = super::probe(provider, score);

    return res;
}


// We override willTerminate only to log that it has been called to make it easier to follow the driver's lifecycle.
//
// willTerminate is called at the beginning of the termination process. It is a notification
// that a provider has been terminated, sent before recursing up the stack, in root-to-leaf order.
//
// This is where any pending I/O should be terminated. At this point the user client has been marked
// inactive and any further requests from the user process should be returned with an error.
bool SimpleDriverClassName::willTerminate(IOService* provider, IOOptionBits options)
{
	IOLog("%s[%p]::%s(%p, %ld)\n", getName(), this, __FUNCTION__, provider, options);
	
	return super::willTerminate(provider, options);
}


// We override didTerminate only to log that it has been called to make it easier to follow the driver's lifecycle.
//
// didTerminate is called at the end of the termination process. It is a notification
// that a provider has been terminated, sent after recursing up the stack, in leaf-to-root order.
bool SimpleDriverClassName::didTerminate(IOService* provider, IOOptionBits options, bool* defer)
{
	IOLog("%s[%p]::%s(%p, %ld, %p)\n", getName(), this, __FUNCTION__, provider, options, defer);
	
	return super::didTerminate(provider, options, defer);
}


// We override terminate only to log that it has been called to make it easier to follow the driver's lifecycle.
// Production drivers will rarely need to override terminate. Termination processing should be done in
// willTerminate or didTerminate instead.
bool SimpleDriverClassName::terminate(IOOptionBits options)
{
    bool	success;
    
	IOLog("%s[%p]::%s(%ld)\n", getName(), this, __FUNCTION__, options);

    success = super::terminate(options);
    
    return success;
}


// We override finalize only to log that it has been called to make it easier to follow the driver's lifecycle.
// Production drivers will rarely need to override finalize.
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
    
    // The scalars inNumber1 and inNumber2 are automatically endian-swapped by the user client mechanism.
	// The user client will swap the fields in outStruct if necessary.
	
	// The output is simply the two input scalars copied to the output struct.
	outStruct->field1 = inNumber1;
    outStruct->field2 = inNumber2;
    *outStructSize = sizeof(MySampleStruct);
    
    return kIOReturnSuccess;
}


IOReturn SimpleDriverClassName::ScalarIScalarO(uint32_t inNumber1, uint32_t inNumber2, uint32_t* outNumber)
{
	IOLog("%s[%p]::%s(inNumber1 = %d, inNumber2 = %d)\n", getName(), this, __FUNCTION__, inNumber1, inNumber2);
    
    // The output is the product of the two input scalars.
	*outNumber = inNumber1 * inNumber2;
    
    return kIOReturnSuccess;
}


IOReturn SimpleDriverClassName::StructIStructO(MySampleStruct* inStruct, MySampleStruct* outStruct, uint32_t inStructSize, uint32_t* outStructSize)
{
	IOLog("%s[%p]::%s(field1 = %lld, field2 = %lld, inStructSize = %d)\n", getName(), this, __FUNCTION__, 
		  inStruct->field1, inStruct->field2, inStructSize);
    
	// The output is simply the fields from the input struct copied to the output struct.
	outStruct->field1 = inStruct->field1;
    outStruct->field2 = inStruct->field2;
    *outStructSize = sizeof(MySampleStruct);
    
    return kIOReturnSuccess;
}

