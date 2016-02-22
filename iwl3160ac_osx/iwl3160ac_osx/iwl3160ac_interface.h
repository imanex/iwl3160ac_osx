#include <stdint.h>
#include <stdlib.h>
#include "UserKernelShared.h"

kern_return_t MyOpenUserClient(io_connect_t connect);
kern_return_t MyCloseUserClient(io_connect_t connect);
kern_return_t MyScalarIStructureI(io_connect_t connect, const uint32_t scalarI, const size_t structISize, 
								  const MySampleStruct* structI);
kern_return_t MyScalarIStructureO(io_connect_t connect, const uint32_t scalarI_1, const uint32_t scalarI_2,
								  size_t* structOSize, MySampleStruct* structO);
kern_return_t MyScalarIScalarO(io_connect_t connect, const uint32_t scalarI_1, const uint32_t scalarI_2, uint32_t* scalarO);
kern_return_t MyStructureIStructureO(io_connect_t connect, const size_t structISize, const MySampleStruct* structI,
									 size_t* structOSize, MySampleStruct* structO);