#include <AvailabilityMacros.h>
#include <IOKit/IOKitLib.h>
#include "SimpleUserClientInterface.h"

kern_return_t MyOpenUserClient(io_connect_t connect)
{
    
	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallScalarMethod != NULL) {

#endif
		kernResult = IOConnectCallScalarMethod(connect, kMyUserClientOpen, NULL, 0, NULL, NULL);
#if !defined(__LP64__)
	}
	else {

		kernResult = IOConnectMethodScalarIScalarO(connect, kMyUserClientOpen, 0, 0);
	}    
#endif
    
	return kernResult;
}


kern_return_t MyCloseUserClient(io_connect_t connect)
{
    
	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallScalarMethod != NULL) {

#endif
		kernResult = IOConnectCallScalarMethod(connect, kMyUserClientClose, NULL, 0, NULL, NULL);
#if !defined(__LP64__)
	}
	else {

		kernResult = IOConnectMethodScalarIScalarO(connect, kMyUserClientClose, 0, 0);
	}    
#endif

    return kernResult;
}


kern_return_t MyScalarIStructureI(io_connect_t connect, const uint32_t scalarI, 
								  const size_t structISize, const MySampleStruct* structI)
{
    
	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallMethod != NULL) {

#endif
		uint64_t scalarI_64 = scalarI;

        kernResult = IOConnectCallMethod(connect, kMyScalarIStructIMethod, &scalarI_64,	1, structI,				structISize, NULL, NULL, NULL, NULL ); // may need an extra null here, unsure of the number of args.

#if !defined(__LP64__)
	}
	else {

		kernResult =
        IOConnectMethodScalarIStructureI(connect, kMyScalarIStructIMethod, 1, structISize, scalarI, structI);
	}
    
#endif
    
    return kernResult;
}


kern_return_t MyScalarIStructureO(io_connect_t connect, const uint32_t scalarI_1, const uint32_t scalarI_2,
								  size_t* structOSize, MySampleStruct* structO)
{


	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallMethod != NULL) {

#endif
		uint64_t	scalarI_64[2];
		
		scalarI_64[0] = scalarI_1;
		scalarI_64[1] = scalarI_2;
		
		kernResult = IOConnectCallMethod(connect, kMyScalarIStructOMethod, scalarI_64, 2, NULL, 0,
                NULL, NULL, structO, structOSize);
        
#if !defined(__LP64__)
	}
	else {

		kernResult =
			IOConnectMethodScalarIStructureO(connect, kMyScalarIStructOMethod, 2, structOSize, scalarI_1, scalarI_2, structO);
	}
    
#endif
        
    return kernResult;
}


kern_return_t MyScalarIScalarO(io_connect_t connect, const uint32_t scalarI_1, const uint32_t scalarI_2, uint32_t* scalarO)
{

    
	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallScalarMethod != NULL) {

#endif
		uint64_t	scalarI_64[2];
		uint64_t	scalarO_64;
		uint32_t	outputCount = 1; 
		
		scalarI_64[0] = scalarI_1;
		scalarI_64[1] = scalarI_2;
		
		kernResult = IOConnectCallScalarMethod(connect, kMyScalarIScalarOMethod, scalarI_64, 2, &scalarO_64,		&outputCount);
											   
		*scalarO = (uint32_t) scalarO_64;
#if !defined(__LP64__)
	}
	else {

		kernResult =
			IOConnectMethodScalarIScalarO(connect, kMyScalarIScalarOMethod, 2, 1, scalarI_1, scalarI_2,				scalarO);
	}
    
#endif

    return kernResult;
}


kern_return_t MyStructureIStructureO(io_connect_t connect, const size_t structISize, const MySampleStruct* structI,
									 size_t* structOSize, MySampleStruct* structO)
{
    
	kern_return_t	kernResult;
	
#if !defined(__LP64__)

	if (IOConnectCallStructMethod != NULL) {

#endif
		kernResult = IOConnectCallStructMethod(connect, kMyStructIStructOMethod, structI, structISize,				structO, structOSize);
        
#if !defined(__LP64__)
	}
	else {

		kernResult =
			IOConnectMethodStructureIStructureO(connect, kMyStructIStructOMethod, structISize, structOSize,			(MySampleStruct*) structI, structO);
	}
    
#endif

    return kernResult;
}
