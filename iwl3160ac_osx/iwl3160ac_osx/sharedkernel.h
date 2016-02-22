
#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
#define SimpleDriverClassName		com_apple_dts_driver_SimpleDriver_10_4
#else
#define SimpleDriverClassName		com_apple_dts_driver_SimpleDriver
#endif

#define kSimpleDriverClassName		"com_apple_dts_driver_SimpleDriver"
#define kSimpleDriverClassName_10_4	"com_apple_dts_driver_SimpleDriver_10_4"

typedef struct MySampleStruct {
    uint64_t field1;	
    uint64_t field2;
} MySampleStruct;

enum {
    kMyUserClientOpen,
    kMyUserClientClose,
    kMyScalarIStructIMethod,
    kMyScalarIStructOMethod,
    kMyScalarIScalarOMethod,
    kMyStructIStructOMethod,
    kNumberOfMethods 
};
