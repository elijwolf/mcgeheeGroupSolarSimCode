typedef unsigned char uint8;
typedef int int32;

typedef enum Scenario
{
	SceInstantAi    = 1,
	SceBufferedAi   = 2,
	SceWaveformAi   = 4,
	SceInstantAo    = 8,
	SceBufferedAo   = 16,
	SceInstantDi    = 32,
	SceInstantDo    = 64,
	SceEventCounter = 128,
	SceFreqMeter    = 256,
	SceOneShot      = 512,
	SceTimerPulse   = 1024,
	ScePwMeter      = 2048,
	ScePwModulator  = 4096,
	SceUdCounter    = 8192,
	SceBufferedEventCounter = 16384,
	SceBufferedPwMeter      = 32768,
	SceBufferedPwModulator  = 65536,
	SceBufferedUdCounter    = 131072,
} Scenario;

typedef enum AccessMode
{
	ModeRead = 0,
	ModeWrite,
	ModeWriteWithReset,
	ModeWriteShared,
	ModeUnknown = 0xffffffff,
} AccessMode;

typedef struct DeviceInformation
{
   int32      DeviceNumber;
   AccessMode DeviceMode;
   int32      ModuleIndex;
   wchar_t    Description[64]; 
} DeviceInformation;

typedef void ( * DAQ_FN)(void *);

typedef struct DaqNaviLib {
   int32 Version;
   int32 Revision;
   DAQ_FN const * Global;
   DAQ_FN const * Base;
   DAQ_FN const * Ai;
   DAQ_FN const * Ao;
   DAQ_FN const * Dio;
   DAQ_FN const * Cntr;
} DaqNaviLib;

typedef struct DaqCtrlBase DaqCtrlBase;

// static DaqNaviLib const ** DNL_PPtr()
// 	{
// 		static DaqNaviLib const * lib = NULL;
// 		return &lib;
// 	}

DaqNaviLib const * AdxDaqNaviLibInitialize();
// static int32 DNL_Initialize()
// {
//   if (*DNL_PPtr() == NULL) { *DNL_PPtr() = AdxDaqNaviLibInitialize(); }
//   return *DNL_PPtr() != NULL;
// }

// typedef int ErrorCode; 

typedef enum ErrorCode {
   /// <summary>
   /// The operation is completed successfully. 
   /// </summary>
   Success = 0, 

   ///************************************************************************
   /// warning                                                              
   ///************************************************************************
   /// <summary>
   /// The interrupt resource is not available. 
   /// </summary>
   WarningIntrNotAvailable = 0xA0000000,

   /// <summary>
   /// The parameter is out of the range. 
   /// </summary>
   WarningParamOutOfRange = 0xA0000001,

   /// <summary>
   /// The property value is out of range. 
   /// </summary>
   WarningPropValueOutOfRange = 0xA0000002,

   /// <summary>
   /// The property value is not supported. 
   /// </summary>
   WarningPropValueNotSpted = 0xA0000003,

   /// <summary>
   /// The property value conflicts with the current state.
   /// </summary>
   WarningPropValueConflict = 0xA0000004,

   /// <summary>
   /// The value range of all channels in a group should be same, 
   /// such as 4~20mA of PCI-1724.
   /// </summary>
   WarningVrgOfGroupNotSame = 0xA0000005,

   /// <summary>
   /// Some properties of a property set are failed to be written into device.
   /// 
   /// </summary>
   WarningPropPartialFailed = 0xA0000006,

   /// <summary>
   /// The operation had been stopped.
   /// 
   /// </summary>
   WarningFuncStopped = 0xA0000007,

   /// <summary>
   /// The operation is time-out.
   /// 
   /// </summary>
   WarningFuncTimeout = 0xA0000008,

   /// <summary>
   /// The cache is over-run.
   /// 
   /// </summary>
   WarningCacheOverflow = 0xA0000009,

   /// <summary>
   /// The channel is burn-out.
   /// 
   /// </summary>
   WarningBurnout = 0xA000000A,

   /// <summary>
   /// The current data record is end.
   /// 
   /// </summary>
   WarningRecordEnd = 0xA000000B,

   /// <summary>
   /// The specified profile is not valid. 
   /// 
   /// </summary>
   WarningProfileNotValid = 0xA000000C,


   ///***********************************************************************
   /// error                                                                
   ///***********************************************************************
   /// <summary>
   /// The handle is NULL or its type doesn't match the required operation. 
   /// </summary>
   ErrorHandleNotValid = 0xE0000000,

   /// <summary>
   /// The parameter value is out of range.
   /// </summary>
   ErrorParamOutOfRange = 0xE0000001,

   /// <summary>
   /// The parameter value is not supported.
   /// </summary>
   ErrorParamNotSpted = 0xE0000002,

   /// <summary>
   /// The parameter value format is not the expected. 
   /// </summary>
   ErrorParamFmtUnexpted = 0xE0000003,

   /// <summary>
   /// Not enough memory is available to complete the operation. 
   /// </summary>
   ErrorMemoryNotEnough = 0xE0000004,

   /// <summary>
   /// The data buffer is null. 
   /// </summary>
   ErrorBufferIsNull = 0xE0000005,

   /// <summary>
   /// The data buffer is too small for the operation. 
   /// </summary>
   ErrorBufferTooSmall = 0xE0000006,

   /// <summary>
   /// The data length exceeded the limitation. 
   /// </summary>
   ErrorDataLenExceedLimit = 0xE0000007,

   /// <summary>
   /// The required function is not supported. 
   /// </summary>
   ErrorFuncNotSpted = 0xE0000008,

   /// <summary>
   /// The required event is not supported. 
   /// </summary>
   ErrorEventNotSpted = 0xE0000009,

   /// <summary>
   /// The required property is not supported. 
   /// </summary>
   ErrorPropNotSpted = 0xE000000A, 

   /// <summary>
   /// The required property is read-only. 
   /// </summary>
   ErrorPropReadOnly = 0xE000000B,

   /// <summary>
   /// The specified property value conflicts with the current state.
   /// </summary>
   ErrorPropValueConflict = 0xE000000C,

   /// <summary>
   /// The specified property value is out of range.
   /// </summary>
   ErrorPropValueOutOfRange = 0xE000000D,

   /// <summary>
   /// The specified property value is not supported. 
   /// </summary>
   ErrorPropValueNotSpted = 0xE000000E,

   /// <summary>
   /// The handle hasn't own the privilege of the operation the user wanted. 
   /// </summary>
   ErrorPrivilegeNotHeld = 0xE000000F,

   /// <summary>
   /// The required privilege is not available because someone else had own it. 
   /// </summary>
   ErrorPrivilegeNotAvailable = 0xE0000010,

   /// <summary>
   /// The driver of specified device was not found. 
   /// </summary>
   ErrorDriverNotFound = 0xE0000011,

   /// <summary>
   /// The driver version of the specified device mismatched. 
   /// </summary>
   ErrorDriverVerMismatch = 0xE0000012,

   /// <summary>
   /// The loaded driver count exceeded the limitation. 
   /// </summary>
   ErrorDriverCountExceedLimit = 0xE0000013,

   /// <summary>
   /// The device is not opened. 
   /// </summary>
   ErrorDeviceNotOpened = 0xE0000014,      

   /// <summary>
   /// The required device does not exist. 
   /// </summary>
   ErrorDeviceNotExist = 0xE0000015,

   /// <summary>
   /// The required device is unrecognized by driver. 
   /// </summary>
   ErrorDeviceUnrecognized = 0xE0000016,

   /// <summary>
   /// The configuration data of the specified device is lost or unavailable. 
   /// </summary>
   ErrorConfigDataLost = 0xE0000017,

   /// <summary>
   /// The function is not initialized and can't be started. 
   /// </summary>
   ErrorFuncNotInited = 0xE0000018,

   /// <summary>
   /// The function is busy. 
   /// </summary>
   ErrorFuncBusy = 0xE0000019,

   /// <summary>
   /// The interrupt resource is not available. 
   /// </summary>
   ErrorIntrNotAvailable = 0xE000001A,

   /// <summary>
   /// The DMA channel is not available. 
   /// </summary>
   ErrorDmaNotAvailable = 0xE000001B,

   /// <summary>
   /// Time out when reading/writing the device. 
   /// </summary>
   ErrorDeviceIoTimeOut = 0xE000001C,

   /// <summary>
   /// The given signature does not match with the device current one.
   /// </summary>
   ErrorSignatureNotMatch = 0xE000001D,

   /// <summary>
   /// The function cannot be executed while the buffered AI is running.
   /// </summary>
   ErrorFuncConflictWithBfdAi = 0xE000001E,

   /// <summary>
   /// The value range is not available in single-ended mode.
   /// </summary>
   ErrorVrgNotAvailableInSeMode = 0xE000001F,

   /// <summary>
   /// The value range is not available in 50omh input impedance mode..
   /// </summary>
   ErrorVrgNotAvailableIn50ohmMode  = 0xE0000020,

   /// <summary>
   /// The coupling type is not available in 50omh input impedance mode..
   /// </summary>
   ErrorCouplingNotAvailableIn50ohmMode  = 0xE0000021,

   /// <summary>
   /// The coupling type is not available in IEPE mode.
   /// </summary>
   ErrorCouplingNotAvailableInIEPEMode  = 0xE0000022,

   /// <summary>
   /// The Communication is failed when reading/writing the device.
   /// </summary>
   ErrorDeviceCommunicationFailed  = 0xE0000023,

   /// <summary>
   /// The device's 'fix number' conflicted with other device's
   /// </summary>
   ErrorFixNumberConflict = 0xE0000024,

   /// <summary>
   /// The Trigger source conflicted with other trigger configuration
   /// </summary>
   ErrorTrigSrcConflict = 0xE0000025,
	
   /// <summary>
   /// All properties of a property set are failed to be written into device.
   /// </summary>
   ErrorPropAllFailed = 0xE0000026,

   /// <summary>
   /// Undefined error 
   /// </summary>
   ErrorUndefined = 0xE000FFFF,
} ErrorCode;

typedef int ControlState;
typedef int DeviceCtrl;
typedef void* HANDLE;
typedef struct DioFeatures DioFeatures;
typedef struct InstantDoCtrl InstantDoCtrl;
typedef struct IArray IArray;

// #define DNLAPI_GBL                                         (*DNL_PPtr())->Global
// #define DNLAPI_BASE                                        (*DNL_PPtr())->Base
// #define DNLAPI_AI                                          (*DNL_PPtr())->Ai
// #define DNLAPI_AO                                          (*DNL_PPtr())->Ao
// #define DNLAPI_DIO                                         (*DNL_PPtr())->Dio
// #define DNLAPI_CNTR                                        (*DNL_PPtr())->Cntr

// #define DAQFN_VV(Apis,   n)                                ((void      (WINAPI *)(void *))Apis[n])
// #define DAQFN_VT(Apis,   n, t1)                            ((void      (WINAPI *)(void *, t1))Apis[n])
// #define DAQFN_VTT(Apis,  n, t1, t2)                        ((void      (WINAPI *)(void *, t1, t2))Apis[n])
// #define DAQFN_VTTT(Apis, n, t1, t2, t3)                    ((void      (WINAPI *)(void *, t1, t2, t3))Apis[n])
// #define DAQFN_TV(Apis,   n, rt)                            ((rt        (WINAPI *)(void *))Apis[n])
// #define DAQFN_TT(Apis,   n, rt, t1)                        ((rt        (WINAPI *)(void *, t1))Apis[n])
// #define DAQFN_TTT(Apis,  n, rt, t1, t2)                    ((rt        (WINAPI *)(void *, t1, t2))Apis[n])
// #define DAQFN_TTTT(Apis, n, rt, t1, t2, t3)                ((rt        (WINAPI *)(void *, t1, t2, t3))Apis[n])
// #define DAQFN_EV(Apis,   n)                                ((ErrorCode (WINAPI *)(void *))Apis[n])
// #define DAQFN_ET(Apis, n, t1)                              ((ErrorCode (WINAPI *)(void *, t1))Apis[n])
// #define DAQFN_ETT(Apis, n, t1, t2)                         ((ErrorCode (WINAPI *)(void *, t1, t2))Apis[n])
// #define DAQFN_ETTT(Apis, n, t1, t2, t3)                    ((ErrorCode (WINAPI *)(void *, t1, t2, t3))Apis[n])
// #define DAQFN_ETTTT(Apis, n, t1, t2, t3, t4)               ((ErrorCode (WINAPI *)(void *, t1, t2, t3, t4))Apis[n])
// #define DAQFN_ETTTTT(Apis, n, t1, t2, t3, t4, t5)          ((ErrorCode (WINAPI *)(void *, t1, t2, t3, t4, t5))Apis[n])
// #define DAQFN_GBL_T(Apis, n, rt)                           ((rt        (WINAPI *)())Apis[n])
// #define DAQFN_GBL_TT(Apis, n, rt, t1)                      ((rt        (WINAPI *)(t1))Apis[n])
// #define DAQFN_GBL_TTT(Apis, n, rt, t1, t2)                 ((rt        (WINAPI *)(t1, t2))Apis[n])
// #define DAQFN_GBL_TTTT(Apis, n, rt, t1, t2, t3)            ((rt        (WINAPI *)(t1, t2, t3))Apis[n])
// #define DAQFN_GBL_ETTT(Apis, n, t1, t2, t3)                ((ErrorCode (WINAPI *)(t1, t2, t3))Apis[n])
// #define DAQFN_GBL_ETTTT(Apis, n, t1, t2, t3, t4)           ((ErrorCode (WINAPI *)(t1, t2, t3, t4))Apis[n])
// #define DAQFN_GBL_ETTTTT(Apis, n, t1, t2, t3, t4, t5)      ((ErrorCode (WINAPI *)(t1, t2, t3, t4, t5))Apis[n])
// #define DAQFN_GBL_ETTTTTT(Apis, n, t1, t2, t3, t4, t5, t6) ((ErrorCode (WINAPI *)(t1, t2, t3, t4, t5, t6))Apis[n])
// #define DAQFN_GBL_TT(Apis, n, rt, t1)                      ((rt        (WINAPI *)(t1))Apis[n])

static DaqCtrlBase *     DaqCtrlBase_Create(Scenario type);//														{ DNL_Initialize(); return DAQFN_GBL_TT(DNLAPI_BASE, 91, DaqCtrlBase *, Scenario)(type);}  
static IArray *          DeviceCtrl_getInstalledDevices();//															{ DNL_Initialize(); return DAQFN_GBL_T(DNLAPI_BASE, 100, IArray *)(); } 

// InstantDoCtrl base1
static ErrorCode		InstantDoCtrl_LoadProfile(InstantDoCtrl *obj, wchar_t const *fileName);//						{ return DAQFN_ET(DNLAPI_BASE, 98, wchar_t const *)(obj, fileName);   }  
static void			InstantDoCtrl_Cleanup(InstantDoCtrl *obj);//													{        DAQFN_VV(DNLAPI_BASE, 83)(obj);                              }
static void			InstantDoCtrl_Dispose(InstantDoCtrl *obj);//													{        DAQFN_VV(DNLAPI_BASE, 84)(obj);                              }
static void			InstantDoCtrl_getSelectedDevice(InstantDoCtrl *obj, DeviceInformation *x);//					{        DAQFN_VT(DNLAPI_BASE, 85, DeviceInformation*)(obj, x);       }
static ErrorCode		InstantDoCtrl_setSelectedDevice(InstantDoCtrl *obj, DeviceInformation const *x);//				{ return DAQFN_ET(DNLAPI_BASE, 86, DeviceInformation const*)(obj, x); }
static ControlState	InstantDoCtrl_getState(void *obj);//															{ return DAQFN_TV(DNLAPI_BASE, 87, ControlState)(obj); }
static DeviceCtrl*	InstantDoCtrl_getDevice(InstantDoCtrl *obj);//													{ return DAQFN_TV(DNLAPI_BASE, 88, DeviceCtrl *)(obj); }
static IArray*		InstantDoCtrl_getSupportedDevices(InstantDoCtrl *obj);//										{ return DAQFN_TV(DNLAPI_BASE, 89, IArray *)(obj);     }
static IArray*		InstantDoCtrl_getSupportedModes(InstantDoCtrl *obj);//											{ return DAQFN_TV(DNLAPI_BASE, 90, IArray *)(obj);     }
// InstantDoCtrl base2               
static DioFeatures*	InstantDoCtrl_getFeatures(InstantDoCtrl *obj);//												{ return DAQFN_TV(DNLAPI_DIO, 45, DioFeatures *)(obj); }
static int32			InstantDoCtrl_getPortCount(InstantDoCtrl *obj);//												{ return DAQFN_TV(DNLAPI_DIO, 46, int32)(obj);         }
static IArray*		InstantDoCtrl_getPorts(InstantDoCtrl *obj);//													{ return DAQFN_TV(DNLAPI_DIO, 47, IArray *)(obj);      }
// InstantDoCtrl methods
static ErrorCode		InstantDoCtrl_WriteAny(InstantDoCtrl *obj, int32 portStart, int32 portCount, uint8 data[]);//	{ return DAQFN_ETTT(DNLAPI_DIO, 58, int32, int32, uint8 *)(obj, portStart, portCount, data); }
static ErrorCode		InstantDoCtrl_ReadAny(InstantDoCtrl *obj, int32 portStart, int32 portCount, uint8 data[]);//	{ return DAQFN_ETTT(DNLAPI_DIO, 59, int32, int32, uint8 *)(obj, portStart, portCount, data); }
static ErrorCode		InstantDoCtrl_WriteBit(InstantDoCtrl *obj, int32 port, int32 bit, uint8 data);//				{ return DAQFN_ETTT(DNLAPI_DIO, 60, int32, int32, uint8  )(obj, port, bit, data);            }
static ErrorCode		InstantDoCtrl_ReadBit(InstantDoCtrl *obj, int32 port, int32 bit, uint8* data);//				{ return DAQFN_ETTT(DNLAPI_DIO, 61, int32, int32, uint8 *)(obj, port, bit, data);            }
// InstantDoCtrlcreator
static InstantDoCtrl *   AdxInstantDoCtrlCreate(void);//	{ return (InstantDoCtrl *)DaqCtrlBase_Create(SceInstantDo); } 