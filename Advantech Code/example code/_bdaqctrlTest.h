#line 1 "bdaqctrlTest.h"





#line 7 "bdaqctrlTest.h"



#line 11 "bdaqctrlTest.h"
#line 12 "bdaqctrlTest.h"




















typedef signed char    int8;
typedef signed short   int16;

typedef unsigned char  uint8;
typedef unsigned short uint16;


   typedef signed int         int32;
   typedef unsigned int       uint32;
   typedef signed long long   int64;
   typedef unsigned long long uint64;
   typedef void *             HANDLE;





#line 50 "bdaqctrlTest.h"

typedef enum TerminalBoard {
   WiringBoard = 0,
   PCLD8710,
   PCLD789,
   PCLD8115,

   
   
   BoardUnknown = 0xffffffff,
} TerminalBoard;

typedef enum ModuleType {
   DaqGroup = 1,
   DaqDevice,
   DaqAi,
   DaqAo,
   DaqDio,
   DaqCounter,
   
   
   DaqAny = 0xffffffff,
} ModuleType;

typedef enum AccessMode {
   ModeRead = 0,
   ModeWrite,
   ModeWriteWithReset,
   ModeWriteShared,

   
   
   ModeUnknown = 0xffffffff,
} AccessMode;

typedef enum Depository {
   DepositoryNone = 0,
   DepositoryOnSystem,
   DepositoryOnDevice,

   
   
   DepositoryUnknown = 0xffffffff,
} Depository;

typedef enum MathIntervalType {
   
   RightOpenSet        = 0x0, 
   RightClosedBoundary = 0x1,   
   RightOpenBoundary   = 0x2, 

   
   LeftOpenSet        = 0x0,   
   LeftClosedBoundary = 0x4,    
   LeftOpenBoundary   = 0x8,   

   
   Boundless          = 0x0,  

   
   LOSROS = 0x0,    
   LOSRCB = 0x1,    
   LOSROB = 0x2,    

   LCBROS = 0x4,    
   LCBRCB = 0x5,    
   LCBROB = 0x6,    

   LOBROS = 0x8,    
   LOBRCB = 0x9,    
   LOBROB = 0xA,    

   
   
   IntervalUnknown = 0xffffffff,
} MathIntervalType;

typedef enum AiChannelType {
   AllSingleEnded = 0,
   AllDifferential,
   AllSeDiffAdj,
   MixedSeDiffAdj,

   
   
   ChannelUnknown = 0xffffffff,
} AiChannelType;

typedef enum AiSignalType {
   SingleEnded = 0,
   Differential,
   PseudoDifferential,

   
   
   AiSignalUnknown = 0xffffffff,
} AiSignalType;

typedef enum CouplingType {
   DCCoupling = 0,
   ACCoupling,

   
   
   CouplingUnknown = 0xffffffff,
} CouplingType;

typedef enum ImpedanceType  {
   Ipd1Momh = 0,
   Ipd50omh,

   
   
   ImpedanceUnknown = 0xffffffff,
} ImpedanceType;

typedef enum IepeType  {
   IEPENone = 0,
   IEPE4mA = 1,
   IEPE10mA = 2,
   IEPE2mA = 3,

   
   
   IepeUnknown = 0xffffffff,
} IepeType;

typedef enum MeasureType  {
   VoltageType = 0,
   CurrentType = 1,
   FullBridge = 2,
   HalfBridge = 3,
   QuadBridge = 4,

   
   
   MeasureUnknown = 0xffffffff,
} MeasureType;

typedef enum SensorType  {
   StrainGage = 0,
   ForceCell = 1,

   
   
   SensorUnknown = 0xffffffff,
} SensorType;

typedef enum FilterType {
   FilterNone = 0,
   LowPass,
   HighPass,
   BandPass,
   BandStop,

   
   
   FilterUnknown = 0xffffffff,
} FilterType;

typedef enum DioPortType {
   PortDi = 0,        
   PortDo,            
   PortDio,           
   Port8255A,         
   Port8255C,         
   PortIndvdlDio,     

   
   
   PortUnknown = 0xffffffff,
} DioPortType;

typedef enum DioPortDir {
   Input   = 0x00,
   LoutHin = 0x0F,
   LinHout = 0xF0,
   Output  = 0xFF,

   
   
   DirUnknown = 0xffffffff,
} DioPortDir;

typedef enum DiOpenState {
   pullHighAllPort = 0x00,
   pullLowAllPort = 0x11,

   
   
   OpenStateUnknown = 0xffffffff,
} DiOpenState;

typedef enum DoCircuitType {
   TTL    = 0,
   Sink   = 1,
   Source = 2,
   Relay  = 3,

   
   
   TypeUnknown = 0xffffffff,
} DoCircuitType;

typedef enum SamplingMethod {
   EqualTimeSwitch = 0,
   Simultaneous,

   
   
   SamplingUnknown = 0xffffffff,
} SamplingMethod;

typedef enum TemperatureDegree {
   Celsius = 0,
   Fahrenheit,
   Rankine,
   Kelvin,

   
   
   DegreeUnknown = 0xffffffff,
} TemperatureDegree;

typedef enum BurnoutRetType {
   Current = 0,
   ParticularValue,
   UpLimit,
   LowLimit,
   LastCorrectValue,

   
   
   ReturnUnknown = 0xffffffff,
} BurnoutRetType;

typedef enum ValueUnit {
   Kilovolt,      
   Volt,          
   Millivolt,     
   Microvolt,     
   Kiloampere,    
   Ampere,        
   Milliampere,   
   Microampere,   
   CelsiusUnit,   

   
   
   UnitUnknown = 0xffffffff,
} ValueUnit;

typedef enum ValueRange {
   V_Neg15To15 = 0,        
   V_Neg10To10,            
   V_Neg5To5,              
   V_Neg2pt5To2pt5,        
   V_Neg1pt25To1pt25,      
   V_Neg1To1,              

   V_0To15,                
   V_0To10,                
   V_0To5,                 
   V_0To2pt5,              
   V_0To1pt25,             
   V_0To1,                 

   mV_Neg625To625,         
   mV_Neg500To500,         
   mV_Neg312pt5To312pt5,   
   mV_Neg200To200,         
   mV_Neg150To150,         
   mV_Neg100To100,         
   mV_Neg50To50,           
   mV_Neg30To30,           
   mV_Neg20To20,           
   mV_Neg15To15,           
   mV_Neg10To10,           
   mV_Neg5To5,             

   mV_0To625,              
   mV_0To500,              
   mV_0To150,              
   mV_0To100,              
   mV_0To50,               
   mV_0To20,               
   mV_0To15,               
   mV_0To10,               

   mA_Neg20To20,           
   mA_0To20,               
   mA_4To20,               
   mA_0To24,               

   
   V_Neg2To2,              
   V_Neg4To4,              
   V_Neg20To20,            

   Jtype_0To760C = 0x8000, 
   Ktype_0To1370C,         
   Ttype_Neg100To400C,     
   Etype_0To1000C,         
   Rtype_500To1750C,       
   Stype_500To1750C,       
   Btype_500To1800C,       

   Pt392_Neg50To150,       
   Pt385_Neg200To200,      
   Pt385_0To400,           
   Pt385_Neg50To150,       
   Pt385_Neg100To100,      
   Pt385_0To100,           
   Pt385_0To200,           
   Pt385_0To600,           
   Pt392_Neg100To100,      
   Pt392_0To100,           
   Pt392_0To200,           
   Pt392_0To600,           
   Pt392_0To400,           
   Pt392_Neg200To200,      
   Pt1000_Neg40To160,      

   Balcon500_Neg30To120,   

   Ni518_Neg80To100,       
   Ni518_0To100,           
   Ni508_0To100,           
   Ni508_Neg50To200,       

   Thermistor_3K_0To100,   
   Thermistor_10K_0To100,  

   Jtype_Neg210To1200C,    
   Ktype_Neg270To1372C,    
   Ttype_Neg270To400C,     
   Etype_Neg270To1000C,    
   Rtype_Neg50To1768C,     
   Stype_Neg50To1768C,     
   Btype_40To1820C,        

   Jtype_Neg210To870C,     
   Rtype_0To1768C,         
   Stype_0To1768C,         
   Ttype_Neg20To135C,      

   V_0To30,                
   A_0To3,                 

   
   UserCustomizedVrgStart = 0xC000,
   UserCustomizedVrgEnd = 0xF000,

   
   V_ExternalRefBipolar = 0xF001, 
   V_ExternalRefUnipolar = 0xF002, 

   
   
   V_OMIT = 0xffffffff,            
} ValueRange;

typedef enum SignalPolarity {
   Negative = 0,
   Positive,

   
   
   PolarityUnknown = 0xffffffff,
} SignalPolarity;

typedef enum CountingType {
   CountingNone = 0,
   DownCount,      
   UpCount,        
   PulseDirection, 
   TwoPulse,       
   AbPhaseX1,      
   AbPhaseX2,      
   AbPhaseX4,      

   
   
   CountingUnknown = 0xffffffff,
} CountingType;

typedef CountingType SignalCountingType; 

typedef enum OutSignalType{
   SignalOutNone = 0,  
   ChipDefined,        
   NegChipDefined,     
   PositivePulse,      
   NegativePulse,      
   ToggledFromLow,     
   ToggledFromHigh,    

   
   
   OutSignalUnknown = 0xffffffff,
} OutSignalType;

typedef enum CounterCapability {
   Primary = 1,
   InstantEventCount,
   OneShot,
   TimerPulse,
   InstantFreqMeter,
   InstantPwmIn,
   InstantPwmOut,
   UpDownCount,

   BufferedEventCount,
   BufferedPwmIn,
   BufferedPwmOut,
   BufferedUpDownCount,

   InstantEdgeSeparation,

   
   
   CapabilityUnknown = 0xffffffff,
} CounterCapability;

typedef enum CounterOperationMode {
   C8254_M0 = 0, 
   C8254_M1,     
   C8254_M2,     
   C8254_M3,     
   C8254_M4,     
   C8254_M5,     

   C1780_MA,   
   C1780_MB,   
   C1780_MC,   
   C1780_MD,   
   C1780_ME,   
   C1780_MF,   
   C1780_MG,   
   C1780_MH,   
   C1780_MI,   
   C1780_MJ,   
   C1780_MK,   
   C1780_ML,   
   C1780_MO,   
   C1780_MR,   
   C1780_MU,   
   C1780_MX,   

   
   
   OpModeUnknown = 0xffffffff,
} CounterOperationMode;

typedef enum CounterValueRegister {
   CntLoad,
   CntPreset = CntLoad,
   CntHold,
   CntOverCompare,
   CntUnderCompare,

   
   
  RegisterUnknown = 0xffffffff,
} CounterValueRegister;

typedef enum CounterCascadeGroup {
   GroupNone = 0,    
   Cnt0Cnt1,         
   Cnt2Cnt3,         
   Cnt4Cnt5,         
   Cnt6Cnt7,         

   
   
   CascadeUnknown = 0xffffffff,
} CounterCascadeGroup;

typedef enum FreqMeasureMethod {
   AutoAdaptive = 0,          
   CountingPulseBySysTime,    
   CountingPulseByDevTime,      
   PeriodInverse,               

   
   
   MethodUnknown = 0xffffffff,
} FreqMeasureMethod;

typedef enum ActiveSignal {
   ActiveNone = 0,
   RisingEdge,
   FallingEdge,
   BothEdge,
   HighLevel,
   LowLevel,

   
   
   ActSignalUnknown = 0xffffffff,
} ActiveSignal;

typedef enum TriggerAction {
   ActionNone = 0,   
   DelayToStart,     
   DelayToStop,      
   Mark,             

   
   
   ActionUnknown = 0xffffffff,
} TriggerAction;

typedef enum SignalPosition {
   InternalSig = 0,
   OnConnector,
   OnAmsi,

   
   
   PositionUnknown = 0xffffffff,
} SignalPosition;

typedef enum SignalDrop {
   SignalNone = 0,          

   
   SigInternalClock,        
   SigInternal1KHz,         
   SigInternal10KHz,        
   SigInternal100KHz,       
   SigInternal1MHz,         
   SigInternal10MHz,        
   SigInternal20MHz,        
   SigInternal30MHz,        
   SigInternal40MHz,        
   SigInternal50MHz,        
   SigInternal60MHz,        

   SigDiPatternMatch,       
   SigDiStatusChange,       

   
   SigExtAnaClock,          
   SigExtAnaScanClock,      
   SigExtAnaTrigger,        
   SigExtAnaTrigger0 = SigExtAnaTrigger, 
   SigExtDigClock,          
   SigExtDigTrigger0,       
   SigExtDigTrigger1,       
   SigExtDigTrigger2,       
   SigExtDigTrigger3,       
   SigCHFrzDo,              

   
   
   SigAi0,  SigAi1,  SigAi2,  SigAi3,  SigAi4,  SigAi5,  SigAi6,  SigAi7, 
   SigAi8,  SigAi9,  SigAi10, SigAi11, SigAi12, SigAi13, SigAi14, SigAi15,
   SigAi16, SigAi17, SigAi18, SigAi19, SigAi20, SigAi21, SigAi22, SigAi23,
   SigAi24, SigAi25, SigAi26, SigAi27, SigAi28, SigAi29, SigAi30, SigAi31, 
   SigAi32, SigAi33, SigAi34, SigAi35, SigAi36, SigAi37, SigAi38, SigAi39,
   SigAi40, SigAi41, SigAi42, SigAi43, SigAi44, SigAi45, SigAi46, SigAi47,
   SigAi48, SigAi49, SigAi50, SigAi51, SigAi52, SigAi53, SigAi54, SigAi55, 
   SigAi56, SigAi57, SigAi58, SigAi59, SigAi60, SigAi61, SigAi62, SigAi63,

   
   SigAo0,  SigAo1,  SigAo2,  SigAo3,  SigAo4,  SigAo5,  SigAo6,  SigAo7,
   SigAo8,  SigAo9,  SigAo10, SigAo11, SigAo12, SigAo13, SigAo14, SigAo15,
   SigAo16, SigAo17, SigAo18, SigAo19, SigAo20, SigAo21, SigAo22, SigAo23,
   SigAo24, SigAo25, SigAo26, SigAo27, SigAo28, SigAo29, SigAo30, SigAo31,

   
   SigDi0,   SigDi1,   SigDi2,   SigDi3,   SigDi4,   SigDi5,   SigDi6,   SigDi7,
   SigDi8,   SigDi9,   SigDi10,  SigDi11,  SigDi12,  SigDi13,  SigDi14,  SigDi15,
   SigDi16,  SigDi17,  SigDi18,  SigDi19,  SigDi20,  SigDi21,  SigDi22,  SigDi23,
   SigDi24,  SigDi25,  SigDi26,  SigDi27,  SigDi28,  SigDi29,  SigDi30,  SigDi31,
   SigDi32,  SigDi33,  SigDi34,  SigDi35,  SigDi36,  SigDi37,  SigDi38,  SigDi39,
   SigDi40,  SigDi41,  SigDi42,  SigDi43,  SigDi44,  SigDi45,  SigDi46,  SigDi47,
   SigDi48,  SigDi49,  SigDi50,  SigDi51,  SigDi52,  SigDi53,  SigDi54,  SigDi55,
   SigDi56,  SigDi57,  SigDi58,  SigDi59,  SigDi60,  SigDi61,  SigDi62,  SigDi63,
   SigDi64,  SigDi65,  SigDi66,  SigDi67,  SigDi68,  SigDi69,  SigDi70,  SigDi71,
   SigDi72,  SigDi73,  SigDi74,  SigDi75,  SigDi76,  SigDi77,  SigDi78,  SigDi79,
   SigDi80,  SigDi81,  SigDi82,  SigDi83,  SigDi84,  SigDi85,  SigDi86,  SigDi87,
   SigDi88,  SigDi89,  SigDi90,  SigDi91,  SigDi92,  SigDi93,  SigDi94,  SigDi95,
   SigDi96,  SigDi97,  SigDi98,  SigDi99,  SigDi100, SigDi101, SigDi102, SigDi103,
   SigDi104, SigDi105, SigDi106, SigDi107, SigDi108, SigDi109, SigDi110, SigDi111,
   SigDi112, SigDi113, SigDi114, SigDi115, SigDi116, SigDi117, SigDi118, SigDi119,
   SigDi120, SigDi121, SigDi122, SigDi123, SigDi124, SigDi125, SigDi126, SigDi127,
   SigDi128, SigDi129, SigDi130, SigDi131, SigDi132, SigDi133, SigDi134, SigDi135,
   SigDi136, SigDi137, SigDi138, SigDi139, SigDi140, SigDi141, SigDi142, SigDi143,
   SigDi144, SigDi145, SigDi146, SigDi147, SigDi148, SigDi149, SigDi150, SigDi151,
   SigDi152, SigDi153, SigDi154, SigDi155, SigDi156, SigDi157, SigDi158, SigDi159,
   SigDi160, SigDi161, SigDi162, SigDi163, SigDi164, SigDi165, SigDi166, SigDi167,
   SigDi168, SigDi169, SigDi170, SigDi171, SigDi172, SigDi173, SigDi174, SigDi175,
   SigDi176, SigDi177, SigDi178, SigDi179, SigDi180, SigDi181, SigDi182, SigDi183,
   SigDi184, SigDi185, SigDi186, SigDi187, SigDi188, SigDi189, SigDi190, SigDi191,
   SigDi192, SigDi193, SigDi194, SigDi195, SigDi196, SigDi197, SigDi198, SigDi199,
   SigDi200, SigDi201, SigDi202, SigDi203, SigDi204, SigDi205, SigDi206, SigDi207,
   SigDi208, SigDi209, SigDi210, SigDi211, SigDi212, SigDi213, SigDi214, SigDi215,
   SigDi216, SigDi217, SigDi218, SigDi219, SigDi220, SigDi221, SigDi222, SigDi223,
   SigDi224, SigDi225, SigDi226, SigDi227, SigDi228, SigDi229, SigDi230, SigDi231,
   SigDi232, SigDi233, SigDi234, SigDi235, SigDi236, SigDi237, SigDi238, SigDi239,
   SigDi240, SigDi241, SigDi242, SigDi243, SigDi244, SigDi245, SigDi246, SigDi247,
   SigDi248, SigDi249, SigDi250, SigDi251, SigDi252, SigDi253, SigDi254, SigDi255,

   
   SigDio0,   SigDio1,   SigDio2,   SigDio3,   SigDio4,   SigDio5,   SigDio6,   SigDio7,
   SigDio8,   SigDio9,   SigDio10,  SigDio11,  SigDio12,  SigDio13,  SigDio14,  SigDio15,
   SigDio16,  SigDio17,  SigDio18,  SigDio19,  SigDio20,  SigDio21,  SigDio22,  SigDio23,
   SigDio24,  SigDio25,  SigDio26,  SigDio27,  SigDio28,  SigDio29,  SigDio30,  SigDio31,
   SigDio32,  SigDio33,  SigDio34,  SigDio35,  SigDio36,  SigDio37,  SigDio38,  SigDio39,
   SigDio40,  SigDio41,  SigDio42,  SigDio43,  SigDio44,  SigDio45,  SigDio46,  SigDio47,
   SigDio48,  SigDio49,  SigDio50,  SigDio51,  SigDio52,  SigDio53,  SigDio54,  SigDio55,
   SigDio56,  SigDio57,  SigDio58,  SigDio59,  SigDio60,  SigDio61,  SigDio62,  SigDio63,
   SigDio64,  SigDio65,  SigDio66,  SigDio67,  SigDio68,  SigDio69,  SigDio70,  SigDio71,
   SigDio72,  SigDio73,  SigDio74,  SigDio75,  SigDio76,  SigDio77,  SigDio78,  SigDio79,
   SigDio80,  SigDio81,  SigDio82,  SigDio83,  SigDio84,  SigDio85,  SigDio86,  SigDio87,
   SigDio88,  SigDio89,  SigDio90,  SigDio91,  SigDio92,  SigDio93,  SigDio94,  SigDio95,
   SigDio96,  SigDio97,  SigDio98,  SigDio99,  SigDio100, SigDio101, SigDio102, SigDio103,
   SigDio104, SigDio105, SigDio106, SigDio107, SigDio108, SigDio109, SigDio110, SigDio111,
   SigDio112, SigDio113, SigDio114, SigDio115, SigDio116, SigDio117, SigDio118, SigDio119,
   SigDio120, SigDio121, SigDio122, SigDio123, SigDio124, SigDio125, SigDio126, SigDio127,
   SigDio128, SigDio129, SigDio130, SigDio131, SigDio132, SigDio133, SigDio134, SigDio135,
   SigDio136, SigDio137, SigDio138, SigDio139, SigDio140, SigDio141, SigDio142, SigDio143,
   SigDio144, SigDio145, SigDio146, SigDio147, SigDio148, SigDio149, SigDio150, SigDio151,
   SigDio152, SigDio153, SigDio154, SigDio155, SigDio156, SigDio157, SigDio158, SigDio159,
   SigDio160, SigDio161, SigDio162, SigDio163, SigDio164, SigDio165, SigDio166, SigDio167,
   SigDio168, SigDio169, SigDio170, SigDio171, SigDio172, SigDio173, SigDio174, SigDio175,
   SigDio176, SigDio177, SigDio178, SigDio179, SigDio180, SigDio181, SigDio182, SigDio183,
   SigDio184, SigDio185, SigDio186, SigDio187, SigDio188, SigDio189, SigDio190, SigDio191,
   SigDio192, SigDio193, SigDio194, SigDio195, SigDio196, SigDio197, SigDio198, SigDio199,
   SigDio200, SigDio201, SigDio202, SigDio203, SigDio204, SigDio205, SigDio206, SigDio207,
   SigDio208, SigDio209, SigDio210, SigDio211, SigDio212, SigDio213, SigDio214, SigDio215,
   SigDio216, SigDio217, SigDio218, SigDio219, SigDio220, SigDio221, SigDio222, SigDio223,
   SigDio224, SigDio225, SigDio226, SigDio227, SigDio228, SigDio229, SigDio230, SigDio231,
   SigDio232, SigDio233, SigDio234, SigDio235, SigDio236, SigDio237, SigDio238, SigDio239,
   SigDio240, SigDio241, SigDio242, SigDio243, SigDio244, SigDio245, SigDio246, SigDio247,
   SigDio248, SigDio249, SigDio250, SigDio251, SigDio252, SigDio253, SigDio254, SigDio255,

   
   SigCntClk0, SigCntClk1, SigCntClk2, SigCntClk3, SigCntClk4, SigCntClk5, SigCntClk6, SigCntClk7,

   
   SigCntGate0, SigCntGate1, SigCntGate2, SigCntGate3, SigCntGate4, SigCntGate5, SigCntGate6, SigCntGate7,

   
   SigCntOut0,  SigCntOut1,  SigCntOut2,  SigCntOut3,  SigCntOut4,  SigCntOut5,  SigCntOut6,  SigCntOut7,

   
   SigCntFout0, SigCntFout1, SigCntFout2, SigCntFout3, SigCntFout4, SigCntFout5, SigCntFout6, SigCntFout7,

   
   SigAmsiPin0,  SigAmsiPin1,  SigAmsiPin2,  SigAmsiPin3,  SigAmsiPin4,  SigAmsiPin5,  SigAmsiPin6,  SigAmsiPin7,
   SigAmsiPin8,  SigAmsiPin9,  SigAmsiPin10, SigAmsiPin11, SigAmsiPin12, SigAmsiPin13, SigAmsiPin14, SigAmsiPin15,
   SigAmsiPin16, SigAmsiPin17, SigAmsiPin18, SigAmsiPin19,

   
   SigInternal2Hz,         
   SigInternal20Hz,        
   SigInternal200Hz,       
   SigInternal2KHz,        
   SigInternal20KHz,       
   SigInternal200KHz,      
   SigInternal2MHz,        

   
   SigExtAnaTrigger1,      

   
   SigExtDigRefClock,      
   SigInternal100MHz,
   SigAiConvClock,

   
   SigExtDigTrgAdcLatency,
   SigExtDigTrg0AdcLatency = SigExtDigTrgAdcLatency,
   SigExtDigTrg1AdcLatency,

   
   SigMDSITrg0,
   SigMDSITrg1,

   SigMDSITrg0AdcLatency,
   SigMDSITrg1AdcLatency,

   
   SigMDSIRefClock,

   
   
   SigDropUnknown = 0xffffffff,
} SignalDrop;




typedef enum EventId {
   EvtDeviceRemoved = 0,  
   EvtDeviceReconnected,  
   EvtPropertyChanged,    
   


   EvtBufferedAiDataReady, 
   EvtBufferedAiOverrun,
   EvtBufferedAiCacheOverflow,
   EvtBufferedAiStopped,

   


   EvtBufferedAoDataTransmitted,
   EvtBufferedAoUnderrun,
   EvtBufferedAoCacheEmptied,
   EvtBufferedAoTransStopped,
   EvtBufferedAoStopped,

   


   EvtDiInterrupt,     EvtDiintChannel000 = EvtDiInterrupt, 
                       EvtDiintChannel001, EvtDiintChannel002, EvtDiintChannel003,
   EvtDiintChannel004, EvtDiintChannel005, EvtDiintChannel006, EvtDiintChannel007,
   EvtDiintChannel008, EvtDiintChannel009, EvtDiintChannel010, EvtDiintChannel011,
   EvtDiintChannel012, EvtDiintChannel013, EvtDiintChannel014, EvtDiintChannel015,
   EvtDiintChannel016, EvtDiintChannel017, EvtDiintChannel018, EvtDiintChannel019,
   EvtDiintChannel020, EvtDiintChannel021, EvtDiintChannel022, EvtDiintChannel023,
   EvtDiintChannel024, EvtDiintChannel025, EvtDiintChannel026, EvtDiintChannel027,
   EvtDiintChannel028, EvtDiintChannel029, EvtDiintChannel030, EvtDiintChannel031,
   EvtDiintChannel032, EvtDiintChannel033, EvtDiintChannel034, EvtDiintChannel035,
   EvtDiintChannel036, EvtDiintChannel037, EvtDiintChannel038, EvtDiintChannel039,
   EvtDiintChannel040, EvtDiintChannel041, EvtDiintChannel042, EvtDiintChannel043,
   EvtDiintChannel044, EvtDiintChannel045, EvtDiintChannel046, EvtDiintChannel047,
   EvtDiintChannel048, EvtDiintChannel049, EvtDiintChannel050, EvtDiintChannel051,
   EvtDiintChannel052, EvtDiintChannel053, EvtDiintChannel054, EvtDiintChannel055,
   EvtDiintChannel056, EvtDiintChannel057, EvtDiintChannel058, EvtDiintChannel059,
   EvtDiintChannel060, EvtDiintChannel061, EvtDiintChannel062, EvtDiintChannel063,
   EvtDiintChannel064, EvtDiintChannel065, EvtDiintChannel066, EvtDiintChannel067,
   EvtDiintChannel068, EvtDiintChannel069, EvtDiintChannel070, EvtDiintChannel071,
   EvtDiintChannel072, EvtDiintChannel073, EvtDiintChannel074, EvtDiintChannel075,
   EvtDiintChannel076, EvtDiintChannel077, EvtDiintChannel078, EvtDiintChannel079,
   EvtDiintChannel080, EvtDiintChannel081, EvtDiintChannel082, EvtDiintChannel083,
   EvtDiintChannel084, EvtDiintChannel085, EvtDiintChannel086, EvtDiintChannel087,
   EvtDiintChannel088, EvtDiintChannel089, EvtDiintChannel090, EvtDiintChannel091,
   EvtDiintChannel092, EvtDiintChannel093, EvtDiintChannel094, EvtDiintChannel095,
   EvtDiintChannel096, EvtDiintChannel097, EvtDiintChannel098, EvtDiintChannel099,
   EvtDiintChannel100, EvtDiintChannel101, EvtDiintChannel102, EvtDiintChannel103,
   EvtDiintChannel104, EvtDiintChannel105, EvtDiintChannel106, EvtDiintChannel107,
   EvtDiintChannel108, EvtDiintChannel109, EvtDiintChannel110, EvtDiintChannel111,
   EvtDiintChannel112, EvtDiintChannel113, EvtDiintChannel114, EvtDiintChannel115,
   EvtDiintChannel116, EvtDiintChannel117, EvtDiintChannel118, EvtDiintChannel119,
   EvtDiintChannel120, EvtDiintChannel121, EvtDiintChannel122, EvtDiintChannel123,
   EvtDiintChannel124, EvtDiintChannel125, EvtDiintChannel126, EvtDiintChannel127,
   EvtDiintChannel128, EvtDiintChannel129, EvtDiintChannel130, EvtDiintChannel131,
   EvtDiintChannel132, EvtDiintChannel133, EvtDiintChannel134, EvtDiintChannel135,
   EvtDiintChannel136, EvtDiintChannel137, EvtDiintChannel138, EvtDiintChannel139,
   EvtDiintChannel140, EvtDiintChannel141, EvtDiintChannel142, EvtDiintChannel143,
   EvtDiintChannel144, EvtDiintChannel145, EvtDiintChannel146, EvtDiintChannel147,
   EvtDiintChannel148, EvtDiintChannel149, EvtDiintChannel150, EvtDiintChannel151,
   EvtDiintChannel152, EvtDiintChannel153, EvtDiintChannel154, EvtDiintChannel155,
   EvtDiintChannel156, EvtDiintChannel157, EvtDiintChannel158, EvtDiintChannel159,
   EvtDiintChannel160, EvtDiintChannel161, EvtDiintChannel162, EvtDiintChannel163,
   EvtDiintChannel164, EvtDiintChannel165, EvtDiintChannel166, EvtDiintChannel167,
   EvtDiintChannel168, EvtDiintChannel169, EvtDiintChannel170, EvtDiintChannel171,
   EvtDiintChannel172, EvtDiintChannel173, EvtDiintChannel174, EvtDiintChannel175,
   EvtDiintChannel176, EvtDiintChannel177, EvtDiintChannel178, EvtDiintChannel179,
   EvtDiintChannel180, EvtDiintChannel181, EvtDiintChannel182, EvtDiintChannel183,
   EvtDiintChannel184, EvtDiintChannel185, EvtDiintChannel186, EvtDiintChannel187,
   EvtDiintChannel188, EvtDiintChannel189, EvtDiintChannel190, EvtDiintChannel191,
   EvtDiintChannel192, EvtDiintChannel193, EvtDiintChannel194, EvtDiintChannel195,
   EvtDiintChannel196, EvtDiintChannel197, EvtDiintChannel198, EvtDiintChannel199,
   EvtDiintChannel200, EvtDiintChannel201, EvtDiintChannel202, EvtDiintChannel203,
   EvtDiintChannel204, EvtDiintChannel205, EvtDiintChannel206, EvtDiintChannel207,
   EvtDiintChannel208, EvtDiintChannel209, EvtDiintChannel210, EvtDiintChannel211,
   EvtDiintChannel212, EvtDiintChannel213, EvtDiintChannel214, EvtDiintChannel215,
   EvtDiintChannel216, EvtDiintChannel217, EvtDiintChannel218, EvtDiintChannel219,
   EvtDiintChannel220, EvtDiintChannel221, EvtDiintChannel222, EvtDiintChannel223,
   EvtDiintChannel224, EvtDiintChannel225, EvtDiintChannel226, EvtDiintChannel227,
   EvtDiintChannel228, EvtDiintChannel229, EvtDiintChannel230, EvtDiintChannel231,
   EvtDiintChannel232, EvtDiintChannel233, EvtDiintChannel234, EvtDiintChannel235,
   EvtDiintChannel236, EvtDiintChannel237, EvtDiintChannel238, EvtDiintChannel239,
   EvtDiintChannel240, EvtDiintChannel241, EvtDiintChannel242, EvtDiintChannel243,
   EvtDiintChannel244, EvtDiintChannel245, EvtDiintChannel246, EvtDiintChannel247,
   EvtDiintChannel248, EvtDiintChannel249, EvtDiintChannel250, EvtDiintChannel251,
   EvtDiintChannel252, EvtDiintChannel253, EvtDiintChannel254, EvtDiintChannel255,

   EvtDiStatusChange,  EvtDiCosintPort000 = EvtDiStatusChange, 
                       EvtDiCosintPort001, EvtDiCosintPort002, EvtDiCosintPort003,
   EvtDiCosintPort004, EvtDiCosintPort005, EvtDiCosintPort006, EvtDiCosintPort007,
   EvtDiCosintPort008, EvtDiCosintPort009, EvtDiCosintPort010, EvtDiCosintPort011,
   EvtDiCosintPort012, EvtDiCosintPort013, EvtDiCosintPort014, EvtDiCosintPort015,
   EvtDiCosintPort016, EvtDiCosintPort017, EvtDiCosintPort018, EvtDiCosintPort019,
   EvtDiCosintPort020, EvtDiCosintPort021, EvtDiCosintPort022, EvtDiCosintPort023,
   EvtDiCosintPort024, EvtDiCosintPort025, EvtDiCosintPort026, EvtDiCosintPort027,
   EvtDiCosintPort028, EvtDiCosintPort029, EvtDiCosintPort030, EvtDiCosintPort031,

   EvtDiPatternMatch,  EvtDiPmintPort000 = EvtDiPatternMatch,  
                       EvtDiPmintPort001,  EvtDiPmintPort002,  EvtDiPmintPort003,
   EvtDiPmintPort004,  EvtDiPmintPort005,  EvtDiPmintPort006,  EvtDiPmintPort007,
   EvtDiPmintPort008,  EvtDiPmintPort009,  EvtDiPmintPort010,  EvtDiPmintPort011,
   EvtDiPmintPort012,  EvtDiPmintPort013,  EvtDiPmintPort014,  EvtDiPmintPort015,
   EvtDiPmintPort016,  EvtDiPmintPort017,  EvtDiPmintPort018,  EvtDiPmintPort019,
   EvtDiPmintPort020,  EvtDiPmintPort021,  EvtDiPmintPort022,  EvtDiPmintPort023,
   EvtDiPmintPort024,  EvtDiPmintPort025,  EvtDiPmintPort026,  EvtDiPmintPort027,
   EvtDiPmintPort028,  EvtDiPmintPort029,  EvtDiPmintPort030,  EvtDiPmintPort031,

   EvtBufferedDiDataReady,
   EvtBufferedDiOverrun,
   EvtBufferedDiCacheOverflow,
   EvtBufferedDiStopped,

   EvtBufferedDoDataTransmitted,
   EvtBufferedDoUnderrun,
   EvtBufferedDoCacheEmptied,
   EvtBufferedDoTransStopped,
   EvtBufferedDoStopped,

   EvtReflectWdtOccured,
   


   EvtCntTerminalCount0, EvtCntTerminalCount1, EvtCntTerminalCount2, EvtCntTerminalCount3,
   EvtCntTerminalCount4, EvtCntTerminalCount5, EvtCntTerminalCount6, EvtCntTerminalCount7,

   EvtCntOverCompare0,   EvtCntOverCompare1,   EvtCntOverCompare2,   EvtCntOverCompare3,
   EvtCntOverCompare4,   EvtCntOverCompare5,   EvtCntOverCompare6,   EvtCntOverCompare7,

   EvtCntUnderCompare0,  EvtCntUnderCompare1,  EvtCntUnderCompare2,  EvtCntUnderCompare3,
   EvtCntUnderCompare4,  EvtCntUnderCompare5,  EvtCntUnderCompare6,  EvtCntUnderCompare7,

   EvtCntEcOverCompare0, EvtCntEcOverCompare1, EvtCntEcOverCompare2, EvtCntEcOverCompare3,
   EvtCntEcOverCompare4, EvtCntEcOverCompare5, EvtCntEcOverCompare6, EvtCntEcOverCompare7,

   EvtCntEcUnderCompare0, EvtCntEcUnderCompare1, EvtCntEcUnderCompare2, EvtCntEcUnderCompare3,
   EvtCntEcUnderCompare4, EvtCntEcUnderCompare5, EvtCntEcUnderCompare6, EvtCntEcUnderCompare7,

   EvtCntOneShot0,       EvtCntOneShot1,       EvtCntOneShot2,       EvtCntOneShot3,
   EvtCntOneShot4,       EvtCntOneShot5,       EvtCntOneShot6,       EvtCntOneShot7,

   EvtCntTimer0,         EvtCntTimer1,         EvtCntTimer2,         EvtCntTimer3,
   EvtCntTimer4,         EvtCntTimer5,         EvtCntTimer6,         EvtCntTimer7,

   EvtCntPwmInOverflow0, EvtCntPwmInOverflow1, EvtCntPwmInOverflow2, EvtCntPwmInOverflow3,
   EvtCntPwmInOverflow4, EvtCntPwmInOverflow5, EvtCntPwmInOverflow6, EvtCntPwmInOverflow7,

   EvtUdIndex0, EvtUdIndex1, EvtUdIndex2, EvtUdIndex3,
   EvtUdIndex4, EvtUdIndex5, EvtUdIndex6, EvtUdIndex7,

   EvtCntPatternMatch0, EvtCntPatternMatch1, EvtCntPatternMatch2, EvtCntPatternMatch3,
   EvtCntPatternMatch4, EvtCntPatternMatch5, EvtCntPatternMatch6, EvtCntPatternMatch7,

   EvtCntCompareTableEnd0, EvtCntCompareTableEnd1, EvtCntCompareTableEnd2, EvtCntCompareTableEnd3,
   EvtCntCompareTableEnd4, EvtCntCompareTableEnd5, EvtCntCompareTableEnd6, EvtCntCompareTableEnd7,

   
   
   
   EvtBufferedAiBurnOut,
   EvtBufferedAiTimeStampOverrun,
   EvtBufferedAiTimeStampCacheOverflow,
   EvtBufferedAiMarkOverrun,
   EvtBufferedAiConvStopped,                          

   
   
   
   EvtCiDataReady,  EvtCiDataReady0 = EvtCiDataReady, EvtCiDataReady1, EvtCiDataReady2, 
   EvtCiDataReady3, EvtCiDataReady4, EvtCiDataReady5, EvtCiDataReady6, EvtCiDataReady7,

   EvtCiOverrun,  EvtCiOverrun0 = EvtCiOverrun, EvtCiOverrun1, EvtCiOverrun2,
   EvtCiOverrun3, EvtCiOverrun4, EvtCiOverrun5, EvtCiOverrun6, EvtCiOverrun7,

   EvtCiCacheOverflow,  EvtCiCacheOverflow0 = EvtCiCacheOverflow, EvtCiCacheOverflow1, EvtCiCacheOverflow2, 
   EvtCiCacheOverflow3, EvtCiCacheOverflow4, EvtCiCacheOverflow5, EvtCiCacheOverflow6, EvtCiCacheOverflow7,

   EvtCoDataTransmitted,  EvtCoDataTransmitted0 = EvtCoDataTransmitted, EvtCoDataTransmitted1, EvtCoDataTransmitted2, 
   EvtCoDataTransmitted3, EvtCoDataTransmitted4, EvtCoDataTransmitted5, EvtCoDataTransmitted6, EvtCoDataTransmitted7,

   EvtCoUnderrun,  EvtCoUnderrun0 = EvtCoUnderrun, EvtCoUnderrun1, EvtCoUnderrun2, 
   EvtCoUnderrun3, EvtCoUnderrun4, EvtCoUnderrun5, EvtCoUnderrun6, EvtCoUnderrun7,

   EvtCoCacheEmptied,  EvtCoCacheEmptied0 = EvtCoCacheEmptied, EvtCoCacheEmptied1, EvtCoCacheEmptied2, 
   EvtCoCacheEmptied3, EvtCoCacheEmptied4, EvtCoCacheEmptied5, EvtCoCacheEmptied6, EvtCoCacheEmptied7,

   EvtCoTransStopped,  EvtCoTransStopped0 = EvtCoTransStopped, EvtCoTransStopped1, EvtCoTransStopped2, 
   EvtCoTransStopped3, EvtCoTransStopped4, EvtCoTransStopped5, EvtCoTransStopped6, EvtCoTransStopped7,

   EvtCntrStopped,  EvtCntrStopped0 = EvtCntrStopped, EvtCntrStopped1, EvtCntrStopped2, 
   EvtCntrStopped3, EvtCntrStopped4, EvtCntrStopped5, EvtCntrStopped6, EvtCntrStopped7,

   
   
   EventUnknown = 0xffffffff,
} EventId ;



typedef enum ErrorCode {
   
   
   
   Success = 0, 

   
   
   
   
   
   
   WarningIntrNotAvailable = 0xA0000000,

   
   
   
   WarningParamOutOfRange = 0xA0000001,

   
   
   
   WarningPropValueOutOfRange = 0xA0000002,

   
   
   
   WarningPropValueNotSpted = 0xA0000003,

   
   
   
   WarningPropValueConflict = 0xA0000004,

   
   
   
   
   WarningVrgOfGroupNotSame = 0xA0000005,

   
   
   
   
   WarningPropPartialFailed = 0xA0000006,

   
   
   
   
   WarningFuncStopped = 0xA0000007,

   
   
   
   
   WarningFuncTimeout = 0xA0000008,

   
   
   
   
   WarningCacheOverflow = 0xA0000009,

   
   
   
   
   WarningBurnout = 0xA000000A,

   
   
   
   
   WarningRecordEnd = 0xA000000B,

   
   
   
   
   WarningProfileNotValid = 0xA000000C,


   
   
   
   
   
   
   ErrorHandleNotValid = 0xE0000000,

   
   
   
   ErrorParamOutOfRange = 0xE0000001,

   
   
   
   ErrorParamNotSpted = 0xE0000002,

   
   
   
   ErrorParamFmtUnexpted = 0xE0000003,

   
   
   
   ErrorMemoryNotEnough = 0xE0000004,

   
   
   
   ErrorBufferIsNull = 0xE0000005,

   
   
   
   ErrorBufferTooSmall = 0xE0000006,

   
   
   
   ErrorDataLenExceedLimit = 0xE0000007,

   
   
   
   ErrorFuncNotSpted = 0xE0000008,

   
   
   
   ErrorEventNotSpted = 0xE0000009,

   
   
   
   ErrorPropNotSpted = 0xE000000A, 

   
   
   
   ErrorPropReadOnly = 0xE000000B,

   
   
   
   ErrorPropValueConflict = 0xE000000C,

   
   
   
   ErrorPropValueOutOfRange = 0xE000000D,

   
   
   
   ErrorPropValueNotSpted = 0xE000000E,

   
   
   
   ErrorPrivilegeNotHeld = 0xE000000F,

   
   
   
   ErrorPrivilegeNotAvailable = 0xE0000010,

   
   
   
   ErrorDriverNotFound = 0xE0000011,

   
   
   
   ErrorDriverVerMismatch = 0xE0000012,

   
   
   
   ErrorDriverCountExceedLimit = 0xE0000013,

   
   
   
   ErrorDeviceNotOpened = 0xE0000014,      

   
   
   
   ErrorDeviceNotExist = 0xE0000015,

   
   
   
   ErrorDeviceUnrecognized = 0xE0000016,

   
   
   
   ErrorConfigDataLost = 0xE0000017,

   
   
   
   ErrorFuncNotInited = 0xE0000018,

   
   
   
   ErrorFuncBusy = 0xE0000019,

   
   
   
   ErrorIntrNotAvailable = 0xE000001A,

   
   
   
   ErrorDmaNotAvailable = 0xE000001B,

   
   
   
   ErrorDeviceIoTimeOut = 0xE000001C,

   
   
   
   ErrorSignatureNotMatch = 0xE000001D,

   
   
   
   ErrorFuncConflictWithBfdAi = 0xE000001E,

   
   
   
   ErrorVrgNotAvailableInSeMode = 0xE000001F,

   
   
   
   ErrorVrgNotAvailableIn50ohmMode  = 0xE0000020,

   
   
   
   ErrorCouplingNotAvailableIn50ohmMode  = 0xE0000021,

   
   
   
   ErrorCouplingNotAvailableInIEPEMode  = 0xE0000022,

   
   
   
   ErrorDeviceCommunicationFailed  = 0xE0000023,

   
   
   
   ErrorFixNumberConflict = 0xE0000024,

   
   
   
   ErrorTrigSrcConflict = 0xE0000025,
	
   
   
   
   ErrorPropAllFailed = 0xE0000026,

   
   
   
   ErrorUndefined = 0xE000FFFF,
} ErrorCode;


typedef enum ProductId {
   BD_DEMO   = 0x00,       
   BD_PCL818 = 0x05,       
   BD_PCL818H = 0x11,      
   BD_PCL818L = 0x21,      
   BD_PCL818HG = 0x22,     
   BD_PCL818HD = 0x2b,     
   BD_PCM3718 = 0x37,      
   BD_PCM3724 = 0x38,      
   BD_PCM3730 = 0x5a,      
   BD_PCI1750 = 0x5e,      
   BD_PCI1751 = 0x5f,      
   BD_PCI1710 = 0x60,      
   BD_PCI1712 = 0x61,      
   BD_PCI1710HG = 0x67,    
   BD_PCI1711 = 0x73,      
   BD_PCI1711L = 0x75,     
   BD_PCI1713 = 0x68,      
   BD_PCI1753 = 0x69,      
   BD_PCI1760 = 0x6a,      
   BD_PCI1720 = 0x6b,      
   BD_PCM3718H = 0x6d,     
   BD_PCM3718HG = 0x6e,    
   BD_PCI1716 = 0x74,      
   BD_PCI1731 = 0x75,      
   BD_PCI1754 = 0x7b,      
   BD_PCI1752 = 0x7c,      
   BD_PCI1756 = 0x7d,      
   BD_PCM3725 = 0x7f,      
   BD_PCI1762 = 0x80,      
   BD_PCI1721 = 0x81,      
   BD_PCI1761 = 0x82,      
   BD_PCI1723 = 0x83,      
   BD_PCI1730 = 0x87,      
   BD_PCI1733 = 0x88,      
   BD_PCI1734 = 0x89,      
   BD_PCI1710L = 0x90,     
   BD_PCI1710HGL = 0x91,   
   BD_PCM3712 = 0x93,      
   BD_PCM3723 = 0x94,      
   BD_PCI1780 = 0x95,      
   BD_MIC3756 = 0x96,      
   BD_PCI1755 = 0x97,      
   BD_PCI1714 = 0x98,      
   BD_PCI1757 = 0x99,      
   BD_MIC3716 = 0x9A,      
   BD_MIC3761 = 0x9B,      
   BD_MIC3753 = 0x9C,      
   BD_MIC3780 = 0x9D,      
   BD_PCI1724 = 0x9E,      
   BD_PCI1758UDI = 0xA3,   
   BD_PCI1758UDO = 0xA4,   
   BD_PCI1747 = 0xA5,      
   BD_PCM3780 = 0xA6,      
   BD_MIC3747 = 0xA7,      
   BD_PCI1758UDIO = 0xA8,  
   BD_PCI1712L = 0xA9,     
   BD_PCI1763UP = 0xAC,    
   BD_PCI1736UP = 0xAD,    
   BD_PCI1714UL = 0xAE,    
   BD_MIC3714 = 0xAF,      
   BD_PCM3718HO = 0xB1,    
   BD_PCI1741U = 0xB3,     
   BD_MIC3723 = 0xB4,      
   BD_PCI1718HDU = 0xB5,   
   BD_MIC3758DIO = 0xB6,   
   BD_PCI1727U = 0xB7,     
   BD_PCI1718HGU = 0xB8,   
   BD_PCI1715U = 0xB9,     
   BD_PCI1716L = 0xBA,     
   BD_PCI1735U = 0xBB,     
   BD_USB4711 = 0xBC,      
   BD_PCI1737U = 0xBD,     
   BD_PCI1739U = 0xBE,     
   BD_PCI1742U = 0xC0,     
   BD_USB4718 = 0xC6,      
   BD_MIC3755 = 0xC7,      
   BD_USB4761 = 0xC8,      
   BD_PCI1784 = 0XCC,      
   BD_USB4716 = 0xCD,      
   BD_PCI1752U = 0xCE,     
   BD_PCI1752USO = 0xCF,   
   BD_USB4751 = 0xD0,      
   BD_USB4751L = 0xD1,     
   BD_USB4750 = 0xD2,      
   BD_MIC3713 = 0xD3,      
   BD_USB4711A = 0xD8,     
   BD_PCM3753P = 0xD9,     
   BD_PCM3784  = 0xDA,     
   BD_PCM3761I = 0xDB,     
   BD_MIC3751  = 0xDC,     
   BD_PCM3730I = 0xDD,     
   BD_PCM3813I = 0xE0,     
   BD_PCIE1744   = 0xE1,   
   BD_PCI1730U   = 0xE2,   
   BD_PCI1760U   = 0xE3,   
   BD_MIC3720   = 0xE4,    
   BD_PCM3810I = 0xE9,     
   BD_USB4702  = 0xEA,     
   BD_USB4704  = 0xEB,     
   BD_PCM3810I_HG = 0xEC,  
   BD_PCI1713U = 0xED,     

   
   BD_PCI1706U   = 0x800,
   BD_PCI1706MSU = 0x801,
   BD_PCI1706UL  = 0x802,
   BD_PCIE1752   = 0x803,
   BD_PCIE1754   = 0x804,
   BD_PCIE1756   = 0x805,
   BD_MIC1911    = 0x806,
   BD_MIC3750    = 0x807,
   BD_MIC3711    = 0x808,
   BD_PCIE1730   = 0x809,
   BD_PCI1710_ECU = 0x80A,
   BD_PCI1720_ECU = 0x80B,
   BD_PCIE1760   = 0x80C,
   BD_PCIE1751   = 0x80D,
   BD_ECUP1706   = 0x80E,
   BD_PCIE1753   = 0x80F,
   BD_PCIE1810   = 0x810,
   BD_ECUP1702L  = 0x811,
   BD_PCIE1816   = 0x812,
   BD_PCM27D24DI = 0x813,
   BD_PCIE1816H  = 0x814,
   BD_PCIE1840   = 0x815,
   BD_PCL725     = 0x816,
   BD_PCI176E    = 0x817,
   BD_PCIE1802   = 0x818,
   BD_AIISE730   = 0x819,
   BD_PCIE1812   = 0x81A,
   BD_MIC1810    = 0x81B,
   BD_PCIE1802L  = 0x81C,
   BD_PCIE1813   = 0x81D,
   BD_PCIE1840L  = 0x81E,
   BD_PCIE1730H  = 0x81F,
   BD_PCIE1756H  = 0x820,
   BD_PCIERXM01  = 0x821,          
   BD_MIC1816    = 0x822,
   BD_USB5830    = 0x823,
   BD_USB5850    = 0x824,
   BD_USB5860    = 0x825,
   BD_VPX1172    = 0x826,
   BD_USB5855    = 0x827,
   BD_USB5856    = 0x828,
   BD_USB5862    = 0x829,
   BD_PCIE1840T  = 0x82A,
   BD_AudioCard  = 0x82B,
   BD_AIIS1750   = 0x82C,
   BD_PCIE1840HL = 0x82D,
   BD_PCIE1765   = 0x82E,
   BD_PCIE1761H  = 0x82F,
   BD_PCIE1762H  = 0x830,
   BD_PCIE1884   = 0x831,
   BD_PCIE1758DIO = 0x832,
   BD_PCIE1758DI  = 0x833,
   BD_PCIE1758DO  = 0x834,

   
   BD_USB5817     = 0x835,
   BD_USB5801     = 0x836, 
   BD_PCM2731     = 0x837, 
   BD_MOS1110     = 0x838, 
   BD_PCIE1750UH  = 0x839,
   BD_PCIE1750U   = 0x83A,
   BD_USB5820     = 0x83B,
   
   
   BD_THK1710R    = 0x83C,
   BD_PCIE1803    = 0x83D,
   BD_PCIE1824    = 0x83E,
   BD_PCIE1805    = 0x83F,

   
   BD_MIOE1747    = 0x840, 
   BD_ECUP1710    = 0x841,
	BD_PCIE1824L	= 0x842,

   
   BD_PCIE1763AH  = 0x843,
   BD_PCIE1763DH  = 0x844,

   
   BD_WISE5051   = 0x901,
   BD_WISE5056   = 0x902,
   BD_WISE5056SO = 0x903,
   BD_WISE5015   = 0x904,
   BD_WISE5017   = 0x905,
   BD_WISE5018   = 0x906,
   BD_WISE5024   = 0x907,
   BD_WISE5080   = 0x908,
   BD_WISE5074   = 0x909,
   BD_WISE5001   = 0x90A,
   BD_WISE5052   = 0x90B,
   BD_WISE5057   = 0x90C,
   BD_WISE5057SO = 0x90D,
   BD_WISE5017C  = 0x90E,
   BD_WISE5017V  = 0x90F,
   BD_WISE5079   = 0x910,   

} ProductId;

typedef struct MathInterval {
   int32  Type; 
   double Min;
   double Max;
} MathInterval, * PMathInterval;
typedef MathInterval const *PCMathInterval;

typedef struct MapFuncPiece {
   int32  Size;         
   int32  Degree;       
   double UpperLimit;   
   double Coef[2];      
} MapFuncPiece, * PMapFuncPiece;
typedef MapFuncPiece const *PCMapFuncPiece;

typedef struct DataMark {
   int64 DataIndex;
   int32 SrcId;
   int32 _reserved_;
} DataMark;

typedef struct CalibrationData {
   int32 Size;
   int32 ShuntResistance;
}CalibrationData;










#line 1473 "bdaqctrlTest.h"

















typedef enum ControlState {
   Idle = 0,
   Ready,
   Running,
   Stopped,
   Uninited = -1,
} ControlState;

typedef enum Scenario {
   SceInstantAi    = 1,
   SceBufferedAi   = 2,
   SceWaveformAi   = 4,
   SceInstantAo    = 8,
   SceBufferedAo   = 16,
   SceInstantDi    = 32,
   SceInstantDo    = 64,
   SceEventCounter = 128,
   SceFreqMeter    = 256,
   SceOneShot      = 1024,
   SceTimerPulse   = 2048,
   ScePwMeter      = 4096,
   ScePwModulator  = 8192,
   SceUdCounter    = 16384,
   SceBufferedEventCounter = 32768,
   SceBufferedPwMeter      = 65536,
   SceBufferedPwModulator  = 131072,
   SceBufferedUdCounter    = 262144,
   SceEdgeSeparation       = 524288,
   SceBufferedDi   = 1048576,
   SceBufferedDo   = 2097152,
} Scenario;

typedef struct DeviceInformation{
   int32      DeviceNumber;
   AccessMode DeviceMode;
   int32      ModuleIndex;
   wchar_t    Description[64]; 





















#line 1549 "bdaqctrlTest.h"
} DeviceInformation;

typedef struct DeviceTreeNode {
   int32      DeviceNumber;
   int32      ModulesIndex[8];
   wchar_t    Description[64];
} DeviceTreeNode;

typedef struct DeviceEventArgs {
   EventId Id;
} DeviceEventArgs; 

typedef struct BfdAiEventArgs {
   EventId Id;
   int32   Offset;    
   int32   Count;     
   int32   MarkCount; 
} BfdAiEventArgs;

typedef struct BfdAoEventArgs {
   EventId Id;
   int32   Offset; 
   int32   Count;  
} BfdAoEventArgs;

typedef struct DiSnapEventArgs {
   EventId Id;
   int32   SrcNum;
   int32   Length;
   uint8   PortData[32];
} DiSnapEventArgs;

typedef struct BfdDiEventArgs {
   EventId Id;
   int32   Offset;    
   int32   Count;     
   int32   MarkCount; 
} BfdDiEventArgs;

typedef struct BfdDoEventArgs {
   EventId Id;
   int32   Offset; 
   int32   Count;  
} BfdDoEventArgs;

typedef struct CntrEventArgs {
   EventId Id;
   int32   Channel;
} CntrEventArgs;

typedef struct UdCntrEventArgs {
   EventId Id;
   int32   Length;
   int32   Data[8];
} UdCntrEventArgs;

typedef struct BfdCntrEventArgs {
   EventId Id;
   int32   Channel;
   int32   Offset;    
   int32   Count;     
} BfdCntrEventArgs;

typedef struct PulseWidth {
   double HiPeriod;
   double LoPeriod;
} PulseWidth;

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

typedef struct IArray IArray;
typedef struct ICounterIndexer ICounterIndexer;


typedef struct ScanChannel       ScanChannel;
typedef struct ConvertClock      ConvertClock;
typedef struct ScanClock         ScanClock;
typedef struct Trigger           Trigger;
typedef struct Conversion        Conversion;
typedef struct Record            Record;
typedef struct NosFltChannel     NosFltChannel;
typedef struct DeviceCtrl        DeviceCtrl;
typedef struct DaqCtrlBase       DaqCtrlBase;

typedef struct CjcSetting        CjcSetting;
typedef struct AiChannel         AiChannel;
typedef struct AiFeatures        AiFeatures;
typedef struct AiCtrlBase        AiCtrlBase;
typedef struct InstantAiCtrl     InstantAiCtrl;
typedef struct BufferedAiCtrl    BufferedAiCtrl;
typedef struct WaveformAiCtrl    WaveformAiCtrl;

typedef struct AoChannel         AoChannel;
typedef struct AoFeatures        AoFeatures;
typedef struct AoCtrlBase        AoCtrlBase;
typedef struct InstantAoCtrl     InstantAoCtrl;
typedef struct BufferedAoCtrl    BufferedAoCtrl;

typedef struct DioPort           DioPort;
typedef struct ScanPort          ScanPort;
typedef struct DiintChannel      DiintChannel;
typedef struct DiCosintPort      DiCosintPort;
typedef struct DiPmintPort       DiPmintPort;
typedef struct DioFeatures       DioFeatures;
typedef struct DioCtrlBase       DioCtrlBase;
typedef struct InstantDiCtrl     InstantDiCtrl;
typedef struct InstantDoCtrl     InstantDoCtrl;
typedef struct BufferedDiCtrl    BufferedDiCtrl;
typedef struct BufferedDoCtrl    BufferedDoCtrl;

typedef struct CntrFeatures      CntrFeatures;
typedef struct CntrCtrlBase      CntrCtrlBase;
typedef struct EcChannel         EcChannel;
typedef struct EventCounterCtrl  EventCounterCtrl;
typedef struct FmChannel         FmChannel;
typedef struct FreqMeterCtrl     FreqMeterCtrl;
typedef struct OsChannel         OsChannel;
typedef struct OneShotCtrl       OneShotCtrl;
typedef struct TmrChannel        TmrChannel;
typedef struct TimerPulseCtrl    TimerPulseCtrl;
typedef struct PiChannel         PiChannel;
typedef struct PwMeterCtrl       PwMeterCtrl;
typedef struct PoChannel         PoChannel;
typedef struct PwModulatorCtrl   PwModulatorCtrl;
typedef struct UdChannel         UdChannel;
typedef struct UdCounterCtrl     UdCounterCtrl;
typedef struct EsChannel                 EsChannel;
typedef struct EdgeSeparationCtrl        EdgeSeparationCtrl;
typedef struct BufferedEventCounterCtrl  BufferedEventCounterCtrl;
typedef struct BufferedPwMeterCtrl       BufferedPwMeterCtrl;
typedef struct BufferedUdCounterCtrl     BufferedUdCounterCtrl;
typedef struct BufferedPwModulatorCtrl   BufferedPwModulatorCtrl;





























































#line 1754 "bdaqctrlTest.h"


typedef void ( * DeviceEventProc)(void  *sender, DeviceEventArgs *args, void *userParam);
typedef void ( * BfdAiEventProc )(void  *sender, BfdAiEventArgs  *args, void *userParam);
typedef void ( * BfdAoEventProc )(void  *sender, BfdAoEventArgs  *args, void *userParam);
typedef void ( * DiSnapEventProc)(void  *sender, DiSnapEventArgs *args, void *userParam);
typedef void ( * CntrEventProc  )(void  *sender, CntrEventArgs   *args, void *userParam);
typedef void ( * UdCntrEventProc)(void  *sender, UdCntrEventArgs *args, void *userParam);
typedef void ( * BfdCntrEventProc)(void *sender, BfdCntrEventArgs *args, void *userParam);
typedef void ( * BfdDiEventProc )(void  *sender, BfdDiEventArgs  *args, void *userParam);
typedef void ( * BfdDoEventProc )(void  *sender, BfdDoEventArgs  *args, void *userParam);










   static DaqNaviLib const ** DNL_PPtr()
   {
      static DaqNaviLib const * lib = NULL;
      return &lib;
   }

   


      DaqNaviLib const * AdxDaqNaviLibInitialize();
   



   static int32 DNL_Initialize()
   {
      if (*DNL_PPtr() == NULL) { *DNL_PPtr() = AdxDaqNaviLibInitialize(); }
      return *DNL_PPtr() != NULL;
   }


































static ErrorCode AdxGetValueRangeInformation(ValueRange vrg, int32 sizeofDesc, wchar_t *description, MathInterval *range, ValueUnit *unit)
{
   DNL_Initialize(); 
   return ((ErrorCode ( *)(ValueRange, int32, wchar_t *, MathInterval *, ValueUnit *))(*DNL_PPtr())->Global[0])(vrg, sizeofDesc, description, range, unit);
}
static ErrorCode AdxGetSignalConnectionInformation(SignalDrop signalType, int32 sizeofDesc, wchar_t *description, SignalPosition *position)
{
   DNL_Initialize(); 
   return ((ErrorCode ( *)(SignalDrop, int32, wchar_t *, SignalPosition *))(*DNL_PPtr())->Global[1])(signalType, sizeofDesc, description, position);
}
static double AdxTranslateTemperatureScale(TemperatureDegree degreeType, double degreeCelsius )
{
   DNL_Initialize(); 
   return ((double ( *)(TemperatureDegree, double))(*DNL_PPtr())->Global[2])(degreeType, degreeCelsius);
}
static ErrorCode AdxEnumToString(wchar_t const *enumName, int32 enumValue, int32 strLength, wchar_t *strBuffer)
{
   DNL_Initialize(); 
   return ((ErrorCode ( *)(wchar_t const *, int32, int32, wchar_t *))(*DNL_PPtr())->Global[3])(enumName, enumValue, strLength, strBuffer);
}

static ErrorCode AdxStringToEnum(wchar_t const *enumName, wchar_t const *enumString, int32 *enumValue)
{
   DNL_Initialize(); 
   return ((ErrorCode ( *)(wchar_t const *, wchar_t const *, int32 *))(*DNL_PPtr())->Global[4])(enumName, enumString, enumValue);
}
static ErrorCode AdxDeviceGetLinkageInfo(int32 parent, int32 index, int32 *devNumber, wchar_t *description, int32 *subCount)
{
   DNL_Initialize(); 
   return ((ErrorCode ( *)(int32, int32, int32 *, wchar_t *, int32 *))(*DNL_PPtr())->Global[5])(parent, index, devNumber, description, subCount);
}
static ErrorCode AdxEventClearFlag(HANDLE handle, int32 id, int32 flagLParam, int32 flagRParam)
{  
   return ((ErrorCode ( *)(HANDLE, int32, int32, int32))(*DNL_PPtr())->Global[6])(handle, id, flagLParam, flagRParam);
}



static void              Array_Dispose(IArray * obj)                                                                                    {        ((void ( *)(void *))(*DNL_PPtr())->Base[0])(obj);                       }
static int32             Array_getLength(IArray * obj)                                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[1])(obj);                }
static void*             Array_getItem(IArray * obj, int32 index)                                                                       { return ((void * ( *)(void *, int32))(*DNL_PPtr())->Base[2])(obj, index); }




static int32             ScanChannel_getChannelStart(ScanChannel *obj)                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[3])(obj);         }
static ErrorCode         ScanChannel_setChannelStart(ScanChannel *obj, int32 value)                                                     { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[4])(obj, value);  }
static int32             ScanChannel_getChannelCount(ScanChannel *obj)                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[5])(obj);         }
static ErrorCode         ScanChannel_setChannelCount(ScanChannel *obj, int32 value)                                                     { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[6])(obj, value);  }
static int32             ScanChannel_getIntervalCount(ScanChannel *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[7])(obj);         }
static ErrorCode         ScanChannel_setIntervalCount(ScanChannel *obj, int32 value)                                                    { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[8])(obj, value);  }
static int32             ScanChannel_getSamples(ScanChannel *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[9])(obj);         }
static ErrorCode         ScanChannel_setSamples(ScanChannel *obj, int32 value)                                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[10])(obj, value); }




static SignalDrop        ConvertClock_getSource(ConvertClock *obj)                                                                      { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Base[11])(obj);       }
static ErrorCode         ConvertClock_setSource(ConvertClock *obj, SignalDrop value)                                                    { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Base[12])(obj, value);}
static double            ConvertClock_getRate(ConvertClock *obj)                                                                        { return ((double ( *)(void *))(*DNL_PPtr())->Base[13])(obj);           }
static ErrorCode         ConvertClock_setRate(ConvertClock *obj, double value)                                                          { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[14])(obj, value);    }

                                                                              
                                                                              
                                                                              
static SignalDrop        ScanClock_getSource(ScanClock *obj)                                                                            { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Base[15])(obj);        }
static ErrorCode         ScanClock_setSource(ScanClock *obj, SignalDrop value)                                                          { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Base[16])(obj, value); }
static double            ScanClock_getRate(ScanClock *obj)                                                                              { return ((double ( *)(void *))(*DNL_PPtr())->Base[17])(obj);            }
static ErrorCode         ScanClock_setRate(ScanClock *obj, double value)                                                                { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[18])(obj, value);     }
static int32             ScanClock_getScanCount(ScanClock *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[19])(obj);             }
static ErrorCode         ScanClock_setScanCount(ScanClock *obj, int32 value)                                                            { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[20])(obj, value);      }




static SignalDrop        Trigger_getSource(Trigger *obj)                                                                                { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Base[21])(obj);           }
static ErrorCode         Trigger_setSource(Trigger *obj, SignalDrop value)                                                              { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Base[22])(obj, value);    }
static ActiveSignal      Trigger_getEdge(Trigger *obj)                                                                                  { return ((ActiveSignal ( *)(void *))(*DNL_PPtr())->Base[23])(obj);         }
static ErrorCode         Trigger_setEdge(Trigger *obj, ActiveSignal value)                                                              { return ((ErrorCode ( *)(void *, ActiveSignal))(*DNL_PPtr())->Base[24])(obj, value);  }
static double            Trigger_getLevel(Trigger *obj)                                                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Base[25])(obj);               }
static ErrorCode         Trigger_setLevel(Trigger *obj, double value)                                                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[26])(obj, value);        }
static TriggerAction     Trigger_getAction(Trigger *obj)                                                                                { return ((TriggerAction ( *)(void *))(*DNL_PPtr())->Base[27])(obj);        }
static ErrorCode         Trigger_setAction(Trigger *obj, TriggerAction value)                                                           { return ((ErrorCode ( *)(void *, TriggerAction))(*DNL_PPtr())->Base[28])(obj, value); }
static int32             Trigger_getDelayCount(Trigger *obj)                                                                            { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[29])(obj);                }
static ErrorCode         Trigger_setDelayCount(Trigger *obj, int32 value)                                                               { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[30])(obj, value);         }
static double            Trigger_getHysteresisIndex(Trigger *obj)                                                                       { return ((double ( *)(void *))(*DNL_PPtr())->Base[31])(obj);               }
static ErrorCode         Trigger_setHysteresisIndex(Trigger *obj, double value)                                                         { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[32])(obj, value);        }
static FilterType        Trigger_getFilterType(Trigger *obj)                                                                            { return ((FilterType ( *)(void *))(*DNL_PPtr())->Base[94])(obj);           }
static ErrorCode         Trigger_setFilterType(Trigger *obj, FilterType value)                                                          { return ((ErrorCode ( *)(void *, FilterType))(*DNL_PPtr())->Base[95])(obj, value);    }
static double            Trigger_getFilterCutoffFreq(Trigger *obj)                                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Base[96])(obj);               }
static ErrorCode         Trigger_setFilterCutoffFreq(Trigger *obj, double value)                                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[97])(obj, value);        }




static SignalDrop        Conversion_getClockSource(Conversion *obj)                                                                     { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Base[33])(obj);            }
static ErrorCode         Conversion_setClockSource(Conversion *obj, SignalDrop value)                                                   { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Base[34])(obj, value);     }
static double            Conversion_getClockRate(Conversion *obj)                                                                       { return ((double ( *)(void *))(*DNL_PPtr())->Base[35])(obj);                }
static ErrorCode         Conversion_setClockRate(Conversion *obj, double value)                                                         { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Base[36])(obj, value);         }
static int32             Conversion_getChannelStart(Conversion *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[37])(obj);                 }
static ErrorCode         Conversion_setChannelStart(Conversion *obj, int32 value)                                                       { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[38])(obj, value);          }
static int32             Conversion_getChannelCount(Conversion *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[39])(obj);                 }
static ErrorCode         Conversion_setChannelCount(Conversion *obj, int32 value)                                                       { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[40])(obj, value);          }
static void              Conversion_getChannelMap(Conversion *obj, int32 count, int8 *chMap)                                            {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Base[41])(obj, count, chMap); }
static ErrorCode         Conversion_setChannelMap(Conversion *obj, int32 count, int8 *chMap)                                            { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Base[42])(obj, count, chMap); }




static int32             Record_getSectionLength(Record *obj)                                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[43])(obj);        }
static ErrorCode         Record_setSectionLength(Record *obj, int32 value)                                                              { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[44])(obj, value); }
static int32             Record_getSectionCount(Record *obj)                                                                            { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[45])(obj);        }
static ErrorCode         Record_setSectionCount(Record *obj, int32 value)                                                               { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[46])(obj, value); }
static int32             Record_getCycles(Record *obj)                                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[47])(obj);        }
static ErrorCode         Record_setCycles(Record *obj, int32 value)                                                                     { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[48])(obj, value); }
                                                                                                                                



static int32             NosFltChannel_getChannel(NosFltChannel *obj)                                                                   { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[49])(obj);      }
static int8              NosFltChannel_getEnabled(NosFltChannel *obj)                                                                   { return ((int8 ( *)(void *))(*DNL_PPtr())->Base[50])(obj);       }
static ErrorCode         NosFltChannel_setEnabled(NosFltChannel *obj, int8 value)                                                       { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Base[51])(obj, value);}





static void              DeviceCtrl_addEventHandler(DeviceCtrl *obj, EventId id, DeviceEventProc proc, void *userParam)                 { ((void ( *)(void *, EventId, DeviceEventProc, void *))(*DNL_PPtr())->Base[52])(obj, id, proc, userParam);} 
static void              DeviceCtrl_removeEventHandler(DeviceCtrl *obj, EventId id, DeviceEventProc proc, void *userParam)              { ((void ( *)(void *, EventId, DeviceEventProc, void *))(*DNL_PPtr())->Base[53])(obj, id, proc, userParam);}
                                                                                                                                 
static ErrorCode         DeviceCtrl_Refresh(DeviceCtrl *obj)                                                                            { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Base[54])(obj); }
static ErrorCode         DeviceCtrl_ReadRegister(DeviceCtrl *obj, int32 space, int32 offset, int32 length, void *data)                  { return ((ErrorCode ( *)(void *, int32, int32, int32, void *))(*DNL_PPtr())->Base[55])(obj, space, offset, length, data); }
static ErrorCode         DeviceCtrl_WriteRegister(DeviceCtrl *obj, int32 space, int32 offset, int32 length, void *data)                 { return ((ErrorCode ( *)(void *, int32, int32, int32, void *))(*DNL_PPtr())->Base[56])(obj, space, offset, length, data); }
static ErrorCode         DeviceCtrl_ReadPrivateRegion(DeviceCtrl *obj, int32 signature, int32 length, uint8 *data)                      { return ((ErrorCode ( *)(void *, int32, int32, uint8*))(*DNL_PPtr())->Base[57])(obj, signature, length, data);    } 
static ErrorCode         DeviceCtrl_WritePrivateRegion(DeviceCtrl *obj, int32 signature, int32 length, uint8 *data)                     { return ((ErrorCode ( *)(void *, int32, int32, uint8*))(*DNL_PPtr())->Base[58])(obj, signature, length, data);    }
static ErrorCode         DeviceCtrl_SynchronizeTimebase(DeviceCtrl *obj)                                                                { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Base[101])(obj);                               } 
static double            DeviceCtrl_CalculateAbsoluteTime(DeviceCtrl *obj, double relativeTime)                                         { return ((double ( *)(void *, double))(*DNL_PPtr())->Base[102])(obj, relativeTime); } 
static void              DeviceCtrl_Dispose(DeviceCtrl *obj)                                                                            { ((void ( *)(void *))(*DNL_PPtr())->Base[79])(obj);                                       }

                                                                                                                                                                                                                             
static int32             DeviceCtrl_getDeviceNumber(DeviceCtrl *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[59])(obj);                          }                                            
static ErrorCode         DeviceCtrl_getDescription(DeviceCtrl *obj, int32 length, wchar_t *desc)                                        { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[60])(obj, length, desc);}
static ErrorCode         DeviceCtrl_setDescription(DeviceCtrl *obj, int32 length, wchar_t *desc)                                        { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[76])(obj, length, desc);}
static AccessMode        DeviceCtrl_getAccessMode(DeviceCtrl *obj)                                                                      { return ((AccessMode ( *)(void *))(*DNL_PPtr())->Base[61])(obj);                     }
static ProductId         DeviceCtrl_getProductId(DeviceCtrl *obj)                                                                       { return ((ProductId ( *)(void *))(*DNL_PPtr())->Base[62])(obj);                      }
static int32             DeviceCtrl_getBoardId(DeviceCtrl *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[63])(obj);                          }
static ErrorCode         DeviceCtrl_setBoardId(DeviceCtrl *obj, int32 value)                                                            { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[77])(obj, value);                   }
static ErrorCode         DeviceCtrl_getBoardVersion(DeviceCtrl *obj, int32 length, wchar_t *ver)                                        { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[64])(obj, length, ver); }
static ErrorCode         DeviceCtrl_getDriverVersion(DeviceCtrl *obj, int32 length, wchar_t *ver)                                       { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[65])(obj, length, ver); }
static ErrorCode         DeviceCtrl_getDllVersion(DeviceCtrl *obj, int32 length, wchar_t *ver)                                          { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[66])(obj, length, ver); }
static ErrorCode         DeviceCtrl_getLocation(DeviceCtrl *obj, int32 length, wchar_t *loc)                                            { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Base[67])(obj, length, loc); }
static int32             DeviceCtrl_getPrivateRegionLength(DeviceCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[68])(obj);                          }
static int32             DeviceCtrl_getHotResetPreventable(DeviceCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[69])(obj);                          }
static IArray *          DeviceCtrl_getBaseAddresses(DeviceCtrl *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[70])(obj);                       }
static IArray *          DeviceCtrl_getInterrupts(DeviceCtrl *obj)                                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[71])(obj);                       }
static IArray *          DeviceCtrl_getSupportedTerminalBoard(DeviceCtrl *obj)                                                          { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[72])(obj);                       }
static IArray *          DeviceCtrl_getSupportedEvents(DeviceCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[73])(obj);                       } 
static TerminalBoard     DeviceCtrl_getTerminalBoard(DeviceCtrl *obj)                                                                   { return ((TerminalBoard ( *)(void *))(*DNL_PPtr())->Base[74])(obj);                  }
static ErrorCode         DeviceCtrl_setTerminalBoard(DeviceCtrl *obj, TerminalBoard value)                                              { return ((ErrorCode ( *)(void *, TerminalBoard))(*DNL_PPtr())->Base[75])(obj, value);           }
static ErrorCode         DeviceCtrl_setLocateEnabled(DeviceCtrl *obj, int32 value)                                                      { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Base[99])(obj, value);                   }
static int32             DeviceCtrl_getSupportedScenarios(DeviceCtrl *obj)                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Base[78])(obj);                          }
static HANDLE            DeviceCtrl_getDevice(DeviceCtrl *obj)                                                                          { return ((HANDLE ( *)(void *))(*DNL_PPtr())->Base[92])(obj);                         }   
static ErrorCode         DeviceCtrl_getHwSpecific(DeviceCtrl *obj, wchar_t *name, int32 *size, void *buffer)                            { return ((ErrorCode ( *)(void *, wchar_t *, int32 *, void*))(*DNL_PPtr())->Base[103])(obj, name, size, buffer); }   
static ErrorCode         DeviceCtrl_setHwSpecific(DeviceCtrl *obj, wchar_t *name, int32 size, void *buffer)                             { return ((ErrorCode ( *)(void *, wchar_t *, int32, void*))(*DNL_PPtr())->Base[104])(obj, name, size, buffer); }   


static DeviceCtrl *      DeviceCtrl_Create(int32 devNumber, wchar_t const *desc, AccessMode mode)                                       { DNL_Initialize(); return ((DeviceCtrl * ( *)(int32, wchar_t const *, AccessMode))(*DNL_PPtr())->Base[80])(devNumber, desc, mode); } 
static IArray *          DeviceCtrl_getInstalledDevices()                                                                               { DNL_Initialize(); return ((IArray * ( *)())(*DNL_PPtr())->Base[100])(); } 


static void              DeviceCtrl_addRemovedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                           { DeviceCtrl_addEventHandler   (obj, EvtDeviceRemoved,     proc, userParam); }
static void              DeviceCtrl_removeRemovedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                        { DeviceCtrl_removeEventHandler(obj, EvtDeviceRemoved,     proc, userParam); }
static void              DeviceCtrl_addReconnectedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                       { DeviceCtrl_addEventHandler   (obj, EvtDeviceReconnected, proc, userParam); }
static void              DeviceCtrl_removeReconnectedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                    { DeviceCtrl_removeEventHandler(obj, EvtDeviceReconnected, proc, userParam); }
static void              DeviceCtrl_addPropertyChangedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                   { DeviceCtrl_addEventHandler   (obj, EvtPropertyChanged,   proc, userParam); }
static void              DeviceCtrl_removePropertyChangedHandler(DeviceCtrl *obj, DeviceEventProc proc, void *userParam)                { DeviceCtrl_removeEventHandler(obj, EvtPropertyChanged,   proc, userParam); }





typedef void ( * DaqEventProc)(void *sender, void *args, void *userParam);
static void              DaqCtrlBase_addEventHandler(DaqCtrlBase *obj, EventId id, DaqEventProc proc, void *userParam)                  { ((void ( *)(void *, EventId, DaqEventProc, void *))(*DNL_PPtr())->Base[81])(obj, id, proc, userParam); } 
static void              DaqCtrlBase_removeEventHandler(DaqCtrlBase *obj, EventId id, DaqEventProc proc, void *userParam)               { ((void ( *)(void *, EventId, DaqEventProc, void *))(*DNL_PPtr())->Base[82])(obj, id, proc, userParam); }
static DaqCtrlBase *     DaqCtrlBase_Create(Scenario type)                                                                              { DNL_Initialize(); return ((DaqCtrlBase * ( *)(Scenario))(*DNL_PPtr())->Base[91])(type);}  






static int32             CjcSetting_getChannel(CjcSetting *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[0]) (obj);       }
static ErrorCode         CjcSetting_setChannel(CjcSetting *obj, int32 ch)                                                               { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Ai[1]) (obj, ch);   }
static double            CjcSetting_getValue(CjcSetting *obj)                                                                           { return ((double ( *)(void *))(*DNL_PPtr())->Ai[2])(obj);       }
static ErrorCode         CjcSetting_setValue(CjcSetting *obj, double value)                                                             { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[3])(obj, value);}
static double            CjcSetting_getUpdateFreq(CjcSetting *obj)                                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Ai[4])(obj);       }
static ErrorCode         CjcSetting_setUpdateFreq(CjcSetting *obj, double value)                                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[5])(obj, value);}




static int32             AiChannel_getChannel(AiChannel *obj)                                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[6])(obj);                 }
static ValueRange        AiChannel_getValueRange(AiChannel *obj)                                                                        { return ((ValueRange ( *)(void *))(*DNL_PPtr())->Ai[7])(obj);            }
static ErrorCode         AiChannel_setValueRange(AiChannel *obj, ValueRange value)                                                      { return ((ErrorCode ( *)(void *, ValueRange))(*DNL_PPtr())->Ai[8])(obj, value);     }
static AiSignalType      AiChannel_getSignalType(AiChannel *obj)                                                                        { return ((AiSignalType ( *)(void *))(*DNL_PPtr())->Ai[9])(obj);         }
static ErrorCode         AiChannel_setSignalType(AiChannel *obj, AiSignalType value)                                                    { return ((ErrorCode ( *)(void *, AiSignalType))(*DNL_PPtr())->Ai[10])(obj, value);  }
static BurnoutRetType    AiChannel_getBurnoutRetType(AiChannel *obj)                                                                    { return ((BurnoutRetType ( *)(void *))(*DNL_PPtr())->Ai[11])(obj);       }
static ErrorCode         AiChannel_setBurnoutRetType(AiChannel *obj, BurnoutRetType value)                                              { return ((ErrorCode ( *)(void *, BurnoutRetType))(*DNL_PPtr())->Ai[12])(obj, value);}
static double            AiChannel_getBurnoutRetValue(AiChannel *obj)                                                                   { return ((double ( *)(void *))(*DNL_PPtr())->Ai[13])(obj);               }
static ErrorCode         AiChannel_setBurnoutRetValue(AiChannel *obj, double value)                                                     { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[14])(obj, value);        }
static double            AiChannel_getBurnShortRetValue(AiChannel *obj)                                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Ai[115])(obj);              }
static ErrorCode         AiChannel_setBurnShortRetValue(AiChannel *obj, double value)                                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[116])(obj, value);       }
static FilterType        AiChannel_getFilterType(AiChannel *obj)                                                                        { return ((FilterType ( *)(void *))(*DNL_PPtr())->Ai[15]) (obj);          }
static ErrorCode         AiChannel_setFilterType(AiChannel *obj, FilterType value)                                                      { return ((ErrorCode ( *)(void *, FilterType))(*DNL_PPtr())->Ai[16]) (obj, value);   }
static double            AiChannel_getFilterCutoffFreq(AiChannel *obj)                                                                  { return ((double ( *)(void *))(*DNL_PPtr())->Ai[17])(obj);               }
static ErrorCode         AiChannel_setFilterCutoffFreq(AiChannel *obj, double value)                                                    { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[18])(obj, value);        }
static double            AiChannel_getFilterCutoffFreq1(AiChannel *obj)                                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Ai[19])(obj);               }
static ErrorCode         AiChannel_setFilterCutoffFreq1(AiChannel *obj, double value)                                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[20])(obj, value);        }
static int32             AiChannel_getLogicalNumber(AiChannel *obj)                                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[21])(obj);                }

static CouplingType      AiChannel_getCouplingType(AiChannel *obj)                                                                      { return ((CouplingType ( *)(void *))(*DNL_PPtr())->Ai[95])(obj);         }
static ErrorCode         AiChannel_setCouplingType(AiChannel *obj, CouplingType value)                                                  { return ((ErrorCode ( *)(void *, CouplingType))(*DNL_PPtr())->Ai[96])(obj, value);  }
static IepeType          AiChannel_getIepeType(AiChannel *obj)                                                                          { return ((IepeType ( *)(void *))(*DNL_PPtr())->Ai[97])(obj);             }
static ErrorCode         AiChannel_setIepeType(AiChannel *obj, IepeType value)                                                          { return ((ErrorCode ( *)(void *, IepeType))(*DNL_PPtr())->Ai[98])(obj, value);      }
static ImpedanceType     AiChannel_getImpedanceType(AiChannel *obj)                                                                     { return ((ImpedanceType ( *)(void *))(*DNL_PPtr())->Ai[99])(obj);        }
static ErrorCode         AiChannel_setImpedanceType(AiChannel *obj, ImpedanceType value)                                                { return ((ErrorCode ( *)(void *, ImpedanceType))(*DNL_PPtr())->Ai[100])(obj, value);}

static ErrorCode         AiChannel_getSensorDescription(AiChannel *obj, int32 *size, wchar_t desc[])                                    { return ((ErrorCode ( *)(void *, int32 *, wchar_t *))(*DNL_PPtr())->Ai[109])(obj, size, desc); }
static ErrorCode         AiChannel_setSensorDescription(AiChannel *obj, int32 size, wchar_t desc[])                                     { return ((ErrorCode ( *)(void *, int32, wchar_t *))(*DNL_PPtr())->Ai[110])(obj, size, desc); }

static ErrorCode         AiChannel_getScaleTable(AiChannel *obj, int32 *size, MapFuncPiece table[])                                     { return ((ErrorCode ( *)(void *, int32 *, MapFuncPiece *))(*DNL_PPtr())->Ai[53])(obj, size, table); }
static ErrorCode         AiChannel_setScaleTable(AiChannel *obj, int32 size, MapFuncPiece table[])                                      { return ((ErrorCode ( *)(void *, int32, MapFuncPiece *))(*DNL_PPtr())->Ai[54])(obj, size, table); }

                                                                                                
                                                                                                                                                      


static int32             AiFeatures_getResolution(AiFeatures *obj)                                                                      { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[22])(obj); }
static int32             AiFeatures_getDataSize(AiFeatures *obj)                                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[23])(obj); }
static int32             AiFeatures_getDataMask(AiFeatures *obj)                                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[24])(obj); }
static double            AiFeatures_getTimestampResolution(AiFeatures *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[108])(obj); }

                                                         
static int32             AiFeatures_getChannelCountMax(AiFeatures *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[25])(obj);         }
static AiChannelType     AiFeatures_getChannelType(AiFeatures *obj)                                                                     { return ((AiChannelType ( *)(void *))(*DNL_PPtr())->Ai[26])(obj); }
static int8              AiFeatures_getOverallValueRange(AiFeatures *obj)                                                               { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[27])(obj);          }
static IArray *          AiFeatures_getValueRanges(AiFeatures *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[28])(obj);      }
static IArray *          AiFeatures_getBurnoutReturnTypes(AiFeatures *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[29])(obj);      }
static IArray *          AiFeatures_getConnectionTypes(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[106])(obj);     }
static int8              AiFeatures_getOverallConnection(AiFeatures *obj)                                                               { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[107])(obj);         }
static IArray *          AiFeatures_getCouplingTypes(AiFeatures *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[101])(obj);    }
static IArray *          AiFeatures_getIepeTypes(AiFeatures *obj)                                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[102])(obj);    }
static IArray *          AiFeatures_getImpedanceTypes(AiFeatures *obj)                                                                  { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[103])(obj);    }

             
static IArray *          AiFeatures_getFilterTypes(AiFeatures *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[30])(obj);         }
static void              AiFeatures_getFilterCutoffFreqRange(AiFeatures *obj, MathInterval *x)                                          {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ai[31])(obj, x);}
static void              AiFeatures_getFilterCutoffFreq1Range(AiFeatures *obj, MathInterval *x)                                         {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ai[32])(obj, x);}

                                                                                                                             
static int8              AiFeatures_getThermoSupported(AiFeatures *obj)                                                                 { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[33])(obj);    }    
static IArray *          AiFeatures_getCjcChannels(AiFeatures *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[34])(obj);}


static int8              AiFeatures_getBufferedAiSupported(AiFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[35])(obj);           }
static SamplingMethod    AiFeatures_getSamplingMethod(AiFeatures *obj)                                                                  { return ((SamplingMethod ( *)(void *))(*DNL_PPtr())->Ai[36])(obj); }
static int32             AiFeatures_getChannelStartBase(AiFeatures *obj)                                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[37])(obj);    }
static int32             AiFeatures_getChannelCountBase(AiFeatures *obj)                                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[38])(obj);    }


static IArray *          AiFeatures_getConvertClockSources(AiFeatures *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[39])(obj);         }
static void              AiFeatures_getConvertClockRange(AiFeatures *obj, MathInterval *x)                                              {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ai[40])(obj, x);}


static int8              AiFeatures_getBurstScanSupported(AiFeatures *obj)                                                              { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[41])(obj);        }
static IArray *          AiFeatures_getScanClockSources(AiFeatures *obj)                                                                { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[42])(obj);    }
static void              AiFeatures_getScanClockRange(AiFeatures *obj, MathInterval *x)                                                 {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ai[43])(obj, x); }
static int32             AiFeatures_getScanCountMax(AiFeatures *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[44])(obj);             }


static int8              AiFeatures_getRetriggerable(AiFeatures *obj)                                                                   { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[45])(obj);  }
static int32             AiFeatures_getTriggerCount(AiFeatures *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[46])(obj); }
static IArray *          AiFeatures_getTriggerFilterTypes(AiFeatures *obj)                                                              { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[104])(obj, 0);         }
static void              AiFeatures_getTriggerFilterCutoffFreq(AiFeatures *obj, MathInterval *x)                                        {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ai[105])(obj, 0, x);}


static IArray *          AiFeatures_getTriggerActions(AiFeatures *obj)                                                                  { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[47])(obj, 0);         }
static void              AiFeatures_getTriggerDelayRange(AiFeatures *obj, MathInterval *x)                                              {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ai[48])(obj, 0, x);}
static IArray *          AiFeatures_getTriggerSources(AiFeatures *obj)                                                                  { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[49])(obj, 0);         }
static ValueRange        AiFeatures_getTriggerSourceVrg(AiFeatures *obj)                                                                { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Ai[50])(obj, 0);       }
static double            AiFeatures_getTriggerHysteresisIndexMax(AiFeatures *obj)                                                       { return ((double ( *)(void *, int32))(*DNL_PPtr())->Ai[51])(obj, 0);           }
static int32             AiFeatures_getTriggerHysteresisIndexStep(AiFeatures *obj)                                                      { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Ai[52])(obj, 0);            }
                                                                  
static IArray *          AiFeatures_getTrigger1Actions(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[47])(obj, 1);         }
static void              AiFeatures_getTrigger1DelayRange(AiFeatures *obj, MathInterval *x)                                             {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ai[48])(obj, 1, x);}
static IArray *          AiFeatures_getTrigger1Sources(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[49])(obj, 1);         }
static ValueRange        AiFeatures_getTrigger1SourceVrg(AiFeatures *obj)                                                               { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Ai[50])(obj, 1);       }
static double            AiFeatures_getTrigger1HysteresisIndexMax(AiFeatures *obj)                                                      { return ((double ( *)(void *, int32))(*DNL_PPtr())->Ai[51])(obj, 1);           }
static int32             AiFeatures_getTrigger1HysteresisIndexStep(AiFeatures *obj)                                                     { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Ai[52])(obj, 1);            }
                                                                  
static IArray *          AiFeatures_getTrigger2Actions(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[47])(obj, 2);         }
static void              AiFeatures_getTrigger2DelayRange(AiFeatures *obj, MathInterval *x)                                             {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ai[48])(obj, 2, x);}
static IArray *          AiFeatures_getTrigger2Sources(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[49])(obj, 2);         }
static ValueRange        AiFeatures_getTrigger2SourceVrg(AiFeatures *obj)                                                               { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Ai[50])(obj, 2);       }
static double            AiFeatures_getTrigger2HysteresisIndexMax(AiFeatures *obj)                                                      { return ((double ( *)(void *, int32))(*DNL_PPtr())->Ai[51])(obj, 2);           }
static int32             AiFeatures_getTrigger2HysteresisIndexStep(AiFeatures *obj)                                                     { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Ai[52])(obj, 2);            }
                                                                  
static IArray *          AiFeatures_getTrigger3Actions(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[47])(obj, 3);         }
static void              AiFeatures_getTrigger3DelayRange(AiFeatures *obj, MathInterval *x)                                             {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ai[48])(obj, 3, x);}
static IArray *          AiFeatures_getTrigger3Sources(AiFeatures *obj)                                                                 { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ai[49])(obj, 3);         }
static ValueRange        AiFeatures_getTrigger3SourceVrg(AiFeatures *obj)                                                               { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Ai[50])(obj, 3);       }
static double            AiFeatures_getTrigger3HysteresisIndexMax(AiFeatures *obj)                                                      { return ((double ( *)(void *, int32))(*DNL_PPtr())->Ai[51])(obj, 3);           }
static int32             AiFeatures_getTrigger3HysteresisIndexStep(AiFeatures *obj)                                                     { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Ai[52])(obj, 3);            }

static IArray *          AiFeatures_getMeasureTypes(AiFeatures *obj)                                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[112])(obj);                  }
static IArray *          AiFeatures_getBridgeResistances(AiFeatures *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[113])(obj);                  }
static void              AiFeatures_getExcitingVoltageRange(AiFeatures *obj, MathInterval *x)                                           {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ai[114])(obj, x);         }





static ErrorCode         InstantAiCtrl_LoadProfile(InstantAiCtrl *obj, wchar_t const *fileName)                                          { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              InstantAiCtrl_Cleanup(InstantAiCtrl *obj)                                                                       {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              InstantAiCtrl_Dispose(InstantAiCtrl *obj)                                                                       {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              InstantAiCtrl_getSelectedDevice(InstantAiCtrl *obj, DeviceInformation *x)                                       {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         InstantAiCtrl_setSelectedDevice(InstantAiCtrl *obj, DeviceInformation const *x)                                 { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      InstantAiCtrl_getState(void *obj)                                                                               { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);  }
static DeviceCtrl *      InstantAiCtrl_getDevice(InstantAiCtrl *obj)                                                                     { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);  }
static IArray *          InstantAiCtrl_getSupportedDevices(InstantAiCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);      }
static IArray *          InstantAiCtrl_getSupportedModes(InstantAiCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);      }
                                                                                                                                    
static AiFeatures *      InstantAiCtrl_getFeatures(InstantAiCtrl *obj)                                                                   { return ((AiFeatures * ( *)(void *))(*DNL_PPtr())->Ai[58])(obj); }
static IArray *          InstantAiCtrl_getChannels(InstantAiCtrl *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[59])(obj); }
static int32             InstantAiCtrl_getChannelCount(InstantAiCtrl *obj)                                                               { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[60])(obj); }
static ErrorCode         InstantAiCtrl_runSensorCalibration(InstantAiCtrl *obj, int32 ch, CalibrationData const *data)                   { return ((ErrorCode ( *)(void *, int32, CalibrationData const*))(*DNL_PPtr())->Ai[111])(obj, ch, data);   }
                                                                                                      
static ErrorCode         InstantAiCtrl_ReadAny(InstantAiCtrl *obj, int32 chStart, int32 chCount, void *dataRaw, double *dataScaled)      { return ((ErrorCode ( *)(void *, int32, int32, void *, double *))(*DNL_PPtr())->Ai[61])(obj, chStart, chCount, dataRaw, dataScaled); }
static CjcSetting *      InstantAiCtrl_getCjc(InstantAiCtrl *obj)                                                                        { return ((CjcSetting * ( *)(void *))(*DNL_PPtr())->Ai[62])(obj);  }
static double            InstantAiCtrl_getAutoConvertClockRate(InstantAiCtrl *obj)                                                       { return ((double ( *)(void *))(*DNL_PPtr())->Ai[63])(obj);        }
static ErrorCode         InstantAiCtrl_setAutoConvertClockRate(InstantAiCtrl *obj, double value)                                         { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ai[64])(obj, value); }
static int32             InstantAiCtrl_getAutoConvertChannelStart(InstantAiCtrl *obj)                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[65])(obj);         }
static ErrorCode         InstantAiCtrl_setAutoConvertChannelStart(InstantAiCtrl *obj, int32 value)                                       { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Ai[66])(obj, value);  }
static int32             InstantAiCtrl_getAutoConvertChannelCount(InstantAiCtrl *obj)                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[67])(obj);         }
static ErrorCode         InstantAiCtrl_setAutoConvertChannelCount(InstantAiCtrl *obj, int32 value)                                       { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Ai[68])(obj, value);  }

static InstantAiCtrl *   InstantAiCtrl_Create(void)                                                                                      { return (InstantAiCtrl*)DaqCtrlBase_Create(SceInstantAi); } 





static ErrorCode         BufferedAiCtrl_LoadProfile(BufferedAiCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedAiCtrl_Cleanup(BufferedAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedAiCtrl_Dispose(BufferedAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedAiCtrl_getSelectedDevice(BufferedAiCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedAiCtrl_setSelectedDevice(BufferedAiCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedAiCtrl_getState(void *obj)                                                                              { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      BufferedAiCtrl_getDevice(BufferedAiCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          BufferedAiCtrl_getSupportedDevices(BufferedAiCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          BufferedAiCtrl_getSupportedModes(BufferedAiCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }
                
static AiFeatures *      BufferedAiCtrl_getFeatures(BufferedAiCtrl *obj)                                                                 { return ((AiFeatures * ( *)(void *))(*DNL_PPtr())->Ai[58])(obj);}
static IArray *          BufferedAiCtrl_getChannels(BufferedAiCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[59])(obj);    }
static int32             BufferedAiCtrl_getChannelCount(BufferedAiCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[60])(obj);      }
static ErrorCode         BufferedAiCtrl_runSensorCalibration(BufferedAiCtrl *obj, int32 ch, CalibrationData const *data)                 { return ((ErrorCode ( *)(void *, int32, CalibrationData const*))(*DNL_PPtr())->Ai[111])(obj, ch, data);  }

static ErrorCode         BufferedAiCtrl_Prepare(BufferedAiCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[69])(obj);   }
static ErrorCode         BufferedAiCtrl_RunOnce(BufferedAiCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[70])(obj);   }
static ErrorCode         BufferedAiCtrl_Start(BufferedAiCtrl *obj)                                                                       { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[71])(obj);   }
static ErrorCode         BufferedAiCtrl_Stop(BufferedAiCtrl *obj)                                                                        { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[72])(obj);   }
static void              BufferedAiCtrl_Release(BufferedAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Ai[73])(obj);   }
static int8              BufferedAiCtrl_GetBufferStatus(BufferedAiCtrl *obj, int32 *count, int32 *offset)                                { return ((int8 ( *)(void *, int32 *, int32 *))(*DNL_PPtr())->Ai[74])(obj, count, offset);    }  
static ErrorCode         BufferedAiCtrl_GetDataI16(BufferedAiCtrl *obj, int32 count, int16 rawData[])                                    { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ai[75])(obj, sizeof(int16), count, rawData);    }
static ErrorCode         BufferedAiCtrl_GetDataI32(BufferedAiCtrl *obj, int32 count, int32 rawData[])                                    { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ai[75])(obj, sizeof(int32), count, rawData);    }
static ErrorCode         BufferedAiCtrl_GetDataF64(BufferedAiCtrl *obj, int32 count, double scaledData[])                                { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ai[75])(obj, sizeof(double),count, scaledData); }
static void*             BufferedAiCtrl_getBuffer(BufferedAiCtrl *obj)                                                                   { return ((void* ( *)(void *))(*DNL_PPtr())->Ai[76])(obj);               }
static int32             BufferedAiCtrl_getBufferCapacity(BufferedAiCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[77])(obj);               }
static ScanChannel *     BufferedAiCtrl_getScanChannel(BufferedAiCtrl *obj)                                                              { return ((ScanChannel * ( *)(void *))(*DNL_PPtr())->Ai[78])(obj);       }
static ConvertClock *    BufferedAiCtrl_getConvertClock(BufferedAiCtrl *obj)                                                             { return ((ConvertClock * ( *)(void *))(*DNL_PPtr())->Ai[79])(obj);      }
static ScanClock *       BufferedAiCtrl_getScanClock(BufferedAiCtrl *obj)                                                                { return ((ScanClock * ( *)(void *))(*DNL_PPtr())->Ai[80])(obj);         }
static Trigger *         BufferedAiCtrl_getTrigger(BufferedAiCtrl *obj)                                                                  { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[81])(obj, 0); }
static Trigger *         BufferedAiCtrl_getTrigger1(BufferedAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[81])(obj, 1); }
static Trigger *         BufferedAiCtrl_getTrigger2(BufferedAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[81])(obj, 2); }
static Trigger *         BufferedAiCtrl_getTrigger3(BufferedAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[81])(obj, 3); }
static int8              BufferedAiCtrl_getStreaming(BufferedAiCtrl *obj)                                                                { return ((int8 ( *)(void *))(*DNL_PPtr())->Ai[82])(obj);                }
static ErrorCode         BufferedAiCtrl_setStreaming(BufferedAiCtrl *obj, int8 value)                                                    { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Ai[83])(obj, value);         }

static BufferedAiCtrl *  BufferedAiCtrl_Create(void)                                                                                     { return (BufferedAiCtrl *)DaqCtrlBase_Create(SceBufferedAi); } 


static void              BufferedAiCtrl_addDataReadyHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_removeDataReadyHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_addOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_removeOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_addCacheOverflowHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_removeCacheOverflowHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_addStoppedHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiStopped,       (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_removeStoppedHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiStopped,       (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_addBurnOutHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiBurnOut,       (DaqEventProc)proc, userParam);}
static void              BufferedAiCtrl_removeBurnOutHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiBurnOut,       (DaqEventProc)proc, userParam);}





static ErrorCode         WaveformAiCtrl_LoadProfile(WaveformAiCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              WaveformAiCtrl_Cleanup(WaveformAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              WaveformAiCtrl_Dispose(WaveformAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              WaveformAiCtrl_getSelectedDevice(WaveformAiCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         WaveformAiCtrl_setSelectedDevice(WaveformAiCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      WaveformAiCtrl_getState(void *obj)                                                                              { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      WaveformAiCtrl_getDevice(WaveformAiCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          WaveformAiCtrl_getSupportedDevices(WaveformAiCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          WaveformAiCtrl_getSupportedModes(WaveformAiCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }
                
static AiFeatures *      WaveformAiCtrl_getFeatures(WaveformAiCtrl *obj)                                                                 { return ((AiFeatures * ( *)(void *))(*DNL_PPtr())->Ai[58])(obj);}
static IArray *          WaveformAiCtrl_getChannels(WaveformAiCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ai[59])(obj);    }
static int32             WaveformAiCtrl_getChannelCount(WaveformAiCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[60])(obj);      }
static ErrorCode         WaveformAiCtrl_runSensorCalibration(WaveformAiCtrl *obj, int32 ch, CalibrationData const *data)                 { return ((ErrorCode ( *)(void *, int32, CalibrationData const*))(*DNL_PPtr())->Ai[111])(obj, ch, data);  }

static ErrorCode         WaveformAiCtrl_Prepare(WaveformAiCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[84])(obj);   }
static ErrorCode         WaveformAiCtrl_Start(WaveformAiCtrl *obj)                                                                       { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[85])(obj);   }
static ErrorCode         WaveformAiCtrl_Stop(WaveformAiCtrl *obj)                                                                        { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ai[86])(obj);   }
static void              WaveformAiCtrl_Release(WaveformAiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Ai[87])(obj);   }
static int8              WaveformAiCtrl_GetBufferStatus(WaveformAiCtrl *obj, int32 *count, int32 *offset)                                { return ((int8 ( *)(void *, int32 *, int32 *))(*DNL_PPtr())->Ai[88])(obj, count, offset); }  

static ErrorCode WaveformAiCtrl_GetDataI16(WaveformAiCtrl *obj, int32 count, int16 dataBuf[], 
   int32 timeout, int32 *returned, double * startTime, int32 *markCount, DataMark *markBuf)
{ 
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void *, int32, int32 *, double *, int32 *, DataMark *);
   return ((FNGETDATA)(*DNL_PPtr())->Ai[89])(obj, sizeof(int16), count, dataBuf, timeout, returned, startTime, markCount, markBuf);        
}
static ErrorCode WaveformAiCtrl_GetDataI32(WaveformAiCtrl *obj, int32 count, int32 dataBuf[], 
   int32 timeout, int32 *returned, double * startTime, int32 *markCount, DataMark *markBuf)
{ 
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void *, int32, int32 *, double *, int32 *, DataMark *);
   return ((FNGETDATA)(*DNL_PPtr())->Ai[89])(obj, sizeof(int32), count, dataBuf, timeout, returned, startTime, markCount, markBuf);        
}
static ErrorCode WaveformAiCtrl_GetDataF64(WaveformAiCtrl *obj, int32 count, double dataBuf[], 
   int32 timeout, int32 *returned, double * startTime, int32 *markCount, DataMark *markBuf) 
{ 
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void *, int32, int32 *, double *, int32 *, DataMark *);
   return ((FNGETDATA)(*DNL_PPtr())->Ai[89])(obj, sizeof(double), count, dataBuf, timeout, returned, startTime, markCount, markBuf);        
}

static void*             WaveformAiCtrl_getBuffer(WaveformAiCtrl *obj)                                                                   { return ((void* ( *)(void *))(*DNL_PPtr())->Ai[90])(obj);        }
static int32             WaveformAiCtrl_getBufferCapacity(WaveformAiCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Ai[91])(obj);        }
static Conversion *      WaveformAiCtrl_getConversion(WaveformAiCtrl *obj)                                                               { return ((Conversion * ( *)(void *))(*DNL_PPtr())->Ai[92])(obj); }
static Record *          WaveformAiCtrl_getRecord(WaveformAiCtrl *obj)                                                                   { return ((Record * ( *)(void *))(*DNL_PPtr())->Ai[93])(obj);     }
static Trigger *         WaveformAiCtrl_getTrigger(WaveformAiCtrl *obj)                                                                  { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[94])(obj, 0); }
static Trigger *         WaveformAiCtrl_getTrigger1(WaveformAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[94])(obj, 1); }
static Trigger *         WaveformAiCtrl_getTrigger2(WaveformAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[94])(obj, 2); }
static Trigger *         WaveformAiCtrl_getTrigger3(WaveformAiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ai[94])(obj, 3); }

static WaveformAiCtrl *  WaveformAiCtrl_Create(void)                                                                                     { return (WaveformAiCtrl *)DaqCtrlBase_Create(SceWaveformAi); } 


static void              WaveformAiCtrl_addDataReadyHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiDataReady,     (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeDataReadyHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiDataReady,     (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addOverrunHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiOverrun,       (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeOverrunHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiOverrun,       (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addCacheOverflowHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeCacheOverflowHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addStoppedHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiStopped,       (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeStoppedHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiStopped,       (DaqEventProc)proc, userParam);}

static void              WaveformAiCtrl_addBurnOutHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiBurnOut,       (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeBurnOutHandler(WaveformAiCtrl *obj, BfdAiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiBurnOut,       (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addTimeStampOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)            { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiTimeStampOverrun, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeTimeStampOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)         { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiTimeStampOverrun, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addTimeStampCacheOverflowHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)      { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiTimeStampCacheOverflow, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeTimeStampCacheOverflowHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)   { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiTimeStampCacheOverflow, (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_addMarkOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)                 { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAiMarkOverrun,      (DaqEventProc)proc, userParam);}
static void              WaveformAiCtrl_removeMarkOverrunHandler(BufferedAiCtrl *obj, BfdAiEventProc proc, void *userParam)              { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAiMarkOverrun,      (DaqEventProc)proc, userParam);}






static int32             AoChannel_getChannel(AoChannel *obj)                                                                            { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[0])(obj);            }
static ValueRange        AoChannel_getValueRange(AoChannel *obj)                                                                         { return ((ValueRange ( *)(void *))(*DNL_PPtr())->Ao[1])(obj);       }
static ErrorCode         AoChannel_setValueRange(AoChannel *obj, ValueRange value)                                                       { return ((ErrorCode ( *)(void *, ValueRange))(*DNL_PPtr())->Ao[2])(obj, value);}
static double            AoChannel_getExtRefBipolar(AoChannel *obj)                                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Ao[47])(obj);           }
static ErrorCode         AoChannel_setExtRefBipolar(AoChannel *obj, double value)                                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[48])(obj, value);    }
static double            AoChannel_getExtRefUnipolar(AoChannel *obj)                                                                     { return ((double ( *)(void *))(*DNL_PPtr())->Ao[49])(obj);           }
static ErrorCode         AoChannel_setExtRefUnipolar(AoChannel *obj, double value)                                                       { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[50])(obj, value);    }

static ErrorCode         AoChannel_getScaleTable(AoChannel *obj, int32 *size, MapFuncPiece table[])                                      { return ((ErrorCode ( *)(void *, int32 *, MapFuncPiece *))(*DNL_PPtr())->Ao[22])(obj, size, table); }
static ErrorCode         AoChannel_setScaleTable(AoChannel *obj, int32 size, MapFuncPiece table[])                                       { return ((ErrorCode ( *)(void *, int32, MapFuncPiece *))(*DNL_PPtr())->Ao[23])(obj, size, table); }

                                          

                                          

static int32             AoFeatures_getResolution(AoFeatures *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[5])(obj); }
static int32             AoFeatures_getDataSize(AoFeatures *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[6])(obj); }
static int32             AoFeatures_getDataMask(AoFeatures *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[7])(obj); }

   
static int32             AoFeatures_getChannelCountMax(AoFeatures *obj)                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[8])(obj);   }
static IArray *          AoFeatures_getValueRanges(AoFeatures *obj)                                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ao[9])(obj);}
static int8              AoFeatures_getExternalRefAntiPolar(AoFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Ao[10])(obj);   }
static void              AoFeatures_getExternalRefRange(AoFeatures *obj, MathInterval *x)                                                {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ao[11])(obj, x); }


static int8              AoFeatures_getBufferedAoSupported(AoFeatures *obj)                                                              { return ((int8 ( *)(void *))(*DNL_PPtr())->Ao[12])(obj); }
static SamplingMethod    AoFeatures_getSamplingMethod(AoFeatures *obj)                                                                   { return ((SamplingMethod ( *)(void *))(*DNL_PPtr())->Ao[13])(obj); }
static int32             AoFeatures_getChannelStartBase(AoFeatures *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[14])(obj); }
static int32             AoFeatures_getChannelCountBase(AoFeatures *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[15])(obj); }


static IArray *          AoFeatures_getConvertClockSources(AoFeatures *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ao[16])(obj); }
static void              AoFeatures_getConvertClockRange(AoFeatures *obj, MathInterval *x)                                               {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Ao[17])(obj, x);}


static int32             AoFeatures_getTriggerCount(AoFeatures *obj)                                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[18])(obj); }
static int8              AoFeatures_getRetriggerable(AoFeatures *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Ao[51])(obj);  }


static IArray *          AoFeatures_getTriggerSources(AoFeatures *obj)                                                                   { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ao[19])(obj, 0); }
static IArray *          AoFeatures_getTriggerActions(AoFeatures *obj)                                                                   { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ao[20])(obj, 0); }
static void              AoFeatures_getTriggerDelayRange(AoFeatures *obj, MathInterval *x)                                               {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ao[21])(obj, 0, x); }


static IArray *          AoFeatures_getTrigger1Sources(AoFeatures *obj)                                                                  { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ao[19])(obj, 1); }
static IArray *          AoFeatures_getTrigger1Actions(AoFeatures *obj)                                                                  { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Ao[20])(obj, 1); }
static void              AoFeatures_getTrigger1DelayRange(AoFeatures *obj, MathInterval *x)                                              {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Ao[21])(obj, 1, x); }





static ErrorCode         InstantAoCtrl_LoadProfile(InstantAoCtrl *obj, wchar_t const *fileName)                                          { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              InstantAoCtrl_Cleanup(InstantAoCtrl *obj)                                                                       {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              InstantAoCtrl_Dispose(InstantAoCtrl *obj)                                                                       {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              InstantAoCtrl_getSelectedDevice(InstantAoCtrl *obj, DeviceInformation *x)                                       {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         InstantAoCtrl_setSelectedDevice(InstantAoCtrl *obj, DeviceInformation const *x)                                 { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      InstantAoCtrl_getState(void *obj)                                                                               { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      InstantAoCtrl_getDevice(InstantAoCtrl *obj)                                                                     { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          InstantAoCtrl_getSupportedDevices(InstantAoCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          InstantAoCtrl_getSupportedModes(InstantAoCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }
                                                                                                                                    
static AoFeatures *      InstantAoCtrl_getFeatures(InstantAoCtrl *obj)                                                                   { return ((AoFeatures * ( *)(void *))(*DNL_PPtr())->Ao[25])(obj); }
static IArray *          InstantAoCtrl_getChannels(InstantAoCtrl *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ao[26])(obj);     }
static int32             InstantAoCtrl_getChannelCount(InstantAoCtrl *obj)                                                               { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[27])(obj);       }
static double            InstantAoCtrl_getExtRefValueForUnipolar(InstantAoCtrl *obj)                                                     { return ((double ( *)(void *))(*DNL_PPtr())->Ao[28])(obj);       }
static ErrorCode         InstantAoCtrl_setExtRefValueForUnipolar(InstantAoCtrl *obj, double value)                                       { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[29])(obj, value);}
static double            InstantAoCtrl_getExtRefValueForBipolar(InstantAoCtrl *obj)                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Ao[30])(obj);       }
static ErrorCode         InstantAoCtrl_setExtRefValueForBipolar(InstantAoCtrl *obj, double value)                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[31])(obj, value);}
                                                                                                                 
static ErrorCode         InstantAoCtrl_WriteAny(InstantAoCtrl *obj, int32 chStart, int32 chCount, void *dataRaw, double *dataScaled)     { return ((ErrorCode ( *)(void *, int32, int32, void *, double *))(*DNL_PPtr())->Ao[32])(obj, chStart, chCount, dataRaw, dataScaled); }

static InstantAoCtrl *   InstantAoCtrl_Create(void)                                                                                      { return (InstantAoCtrl *)DaqCtrlBase_Create(SceInstantAo); } 





static ErrorCode         BufferedAoCtrl_LoadProfile(BufferedAoCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedAoCtrl_Cleanup(BufferedAoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedAoCtrl_Dispose(BufferedAoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedAoCtrl_getSelectedDevice(BufferedAoCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedAoCtrl_setSelectedDevice(BufferedAoCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedAoCtrl_getState(void *obj)                                                                              { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      BufferedAoCtrl_getDevice(BufferedAoCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          BufferedAoCtrl_getSupportedDevices(BufferedAoCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          BufferedAoCtrl_getSupportedModes(BufferedAoCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }
                                                                                                                                  
static AoFeatures *      BufferedAoCtrl_getFeatures(BufferedAoCtrl *obj)                                                                 { return ((AoFeatures * ( *)(void *))(*DNL_PPtr())->Ao[25])(obj); }
static IArray *          BufferedAoCtrl_getChannels(BufferedAoCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Ao[26])(obj);     }
static int32             BufferedAoCtrl_getChannelCount(BufferedAoCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[27])(obj);       }
static double            BufferedAoCtrl_getExtRefValueForUnipolar(BufferedAoCtrl *obj)                                                   { return ((double ( *)(void *))(*DNL_PPtr())->Ao[28])(obj);       }
static ErrorCode         BufferedAoCtrl_setExtRefValueForUnipolar(BufferedAoCtrl *obj, double value)                                     { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[29])(obj, value);}
static double            BufferedAoCtrl_getExtRefValueForBipolar(BufferedAoCtrl *obj)                                                    { return ((double ( *)(void *))(*DNL_PPtr())->Ao[30])(obj);       }
static ErrorCode         BufferedAoCtrl_setExtRefValueForBipolar(BufferedAoCtrl *obj, double value)                                      { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Ao[31])(obj, value);}
                                                                                                   
static ErrorCode         BufferedAoCtrl_Prepare(BufferedAoCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ao[33])(obj);   }
static ErrorCode         BufferedAoCtrl_RunOnce(BufferedAoCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ao[34])(obj);   }
static ErrorCode         BufferedAoCtrl_Start(BufferedAoCtrl *obj)                                                                       { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Ao[35])(obj);   }
static ErrorCode         BufferedAoCtrl_Stop(BufferedAoCtrl *obj, int32 action)                                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Ao[36])(obj, action); }
static void              BufferedAoCtrl_Release(BufferedAoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Ao[37])(obj);                }
static int8              BufferedAoCtrl_GetBufferStatus(BufferedAoCtrl *obj, int32 *count, int32 *offset)                                { return ((int8 ( *)(void *, int32 *, int32 *))(*DNL_PPtr())->Ao[38])(obj, count, offset);    }  
static ErrorCode         BufferedAoCtrl_SetDataI16(BufferedAoCtrl *obj, int32 count, int16 rawData[])                                    { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ao[39])(obj, sizeof(int16), count, rawData);     }
static ErrorCode         BufferedAoCtrl_SetDataI32(BufferedAoCtrl *obj, int32 count, int32 rawData[])                                    { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ao[39])(obj, sizeof(int32), count, rawData);     }
static ErrorCode         BufferedAoCtrl_SetDataF64(BufferedAoCtrl *obj, int32 count, double scaledData[])                                { return ((ErrorCode ( *)(void *, int32, int32, void*))(*DNL_PPtr())->Ao[39])(obj, sizeof(double), count, scaledData); }
static void*             BufferedAoCtrl_getBuffer(BufferedAoCtrl *obj)                                                                   { return ((void* ( *)(void *))(*DNL_PPtr())->Ao[40])(obj);               }
static int32             BufferedAoCtrl_getBufferCapacity(BufferedAoCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Ao[41])(obj);               }
static ScanChannel *     BufferedAoCtrl_getScanChannel(BufferedAoCtrl *obj)                                                              { return ((ScanChannel * ( *)(void *))(*DNL_PPtr())->Ao[42])(obj);       }
static ConvertClock *    BufferedAoCtrl_getConvertClock(BufferedAoCtrl *obj)                                                             { return ((ConvertClock * ( *)(void *))(*DNL_PPtr())->Ao[43])(obj);      }
static Trigger *         BufferedAoCtrl_getTrigger(BufferedAoCtrl *obj)                                                                  { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ao[44])(obj, 0); }
static Trigger *         BufferedAoCtrl_getTrigger1(BufferedAoCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Ao[44])(obj, 1); }
static int8              BufferedAoCtrl_getStreaming(BufferedAoCtrl *obj)                                                                { return ((int8 ( *)(void *))(*DNL_PPtr())->Ao[45])(obj);                }
static ErrorCode         BufferedAoCtrl_setStreaming(BufferedAoCtrl *obj, int8 value)                                                    { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Ao[46])(obj, value);         }

static BufferedAoCtrl *  BufferedAoCtrl_Create(void)                                                                                     { return (BufferedAoCtrl *)DaqCtrlBase_Create(SceBufferedAo); } 


static void              BufferedAoCtrl_addDataTransmittedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)             { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_removeDataTransmittedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)          { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_addUnderrunHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)                    { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_removeUnderrunHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)                 { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_addCacheEmptiedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)                { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_removeCacheEmptiedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)             { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_addTransitStoppedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)              { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_removeTransitStoppedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)           { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_addStoppedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedAoStopped,         (DaqEventProc)proc, userParam); }
static void              BufferedAoCtrl_removeStoppedHandler(BufferedAoCtrl *obj, BfdAoEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedAoStopped,         (DaqEventProc)proc, userParam); }

                                                                              




static int32             DioPort_getPort(DioPort *obj)                                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[0])(obj);        }
static uint8             DioPort_getDirectionMask(DioPort *obj)                                                                        { return (uint8)((int32 ( *)(void *))(*DNL_PPtr())->Dio[1])(obj); }
static ErrorCode         DioPort_setDirectionMask(DioPort *obj, uint8 value)                                                           { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[2])(obj, value); }
     
static uint8             DioPort_getDiInversePort(DioPort *obj)                                                                        { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[3])(obj);        }
static ErrorCode         DioPort_setDiInversePort(DioPort *obj, uint8 value)                                                           { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[4])(obj, value); }
static uint8             DioPort_getDiOpenState(DioPort *obj)                                                                          { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[133])(obj);        }
static ErrorCode         DioPort_setDiOpenState(DioPort *obj, uint8 value)                                                             { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[134])(obj, value); }
     
static uint8             DioPort_getDoPresetValue(DioPort *obj)                                                                        { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[64])(obj);       }
static ErrorCode         DioPort_setDoPresetValue(DioPort *obj, uint8 value)                                                           { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[65])(obj, value);}
static DoCircuitType     DioPort_getDoCircuitType(DioPort *obj)                                                                        { return ((DoCircuitType ( *)(void *))(*DNL_PPtr())->Dio[67])(obj);       }
static ErrorCode         DioPort_setDoCircuitType(DioPort *obj, DoCircuitType value)                                                   { return ((ErrorCode ( *)(void *, DoCircuitType))(*DNL_PPtr())->Dio[68])(obj, value);}





                                          

                                          
static int32             DiintChannel_getChannel(DiintChannel *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[7])(obj);       }
static int8              DiintChannel_getEnabled(DiintChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[8])(obj);        }
static ErrorCode         DiintChannel_setEnabled(DiintChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Dio[9])(obj, value); }
static int8              DiintChannel_getGated(DiintChannel *obj)                                                                      { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[10])(obj);        }
static ErrorCode         DiintChannel_setGated(DiintChannel *obj, int8 value)                                                          { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Dio[11])(obj, value); }
static ActiveSignal      DiintChannel_getTrigEdge(DiintChannel *obj)                                                                   { return ((ActiveSignal ( *)(void *))(*DNL_PPtr())->Dio[12])(obj);}
static ErrorCode         DiintChannel_setTrigEdge(DiintChannel *obj, ActiveSignal value)                                               { return ((ErrorCode ( *)(void *, ActiveSignal))(*DNL_PPtr())->Dio[13])(obj, value);}

                                          
                                          
                                          
static int32             DiCosintPort_getPort(DiCosintPort *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[14])(obj);       }
static uint8             DiCosintPort_getMask(DiCosintPort *obj)                                                                       { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[15])(obj);       }
static ErrorCode         DiCosintPort_setMask(DiCosintPort *obj, uint8 value)                                                          { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[16])(obj, value);}

                                          

                                          
static int32             DiPmintPort_getPort(DiPmintPort *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[17])(obj);       }
static uint8             DiPmintPort_getMask(DiPmintPort *obj)                                                                         { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[18])(obj);       }
static ErrorCode         DiPmintPort_setMask(DiPmintPort *obj, uint8 value)                                                            { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[19])(obj, value);}
static uint8             DiPmintPort_getPattern(DiPmintPort *obj)                                                                      { return ((uint8 ( *)(void *))(*DNL_PPtr())->Dio[20])(obj);       }
static ErrorCode         DiPmintPort_setPattern(DiPmintPort *obj, uint8 value)                                                         { return ((ErrorCode ( *)(void *, uint8))(*DNL_PPtr())->Dio[21])(obj, value);}

                                          



static int8              DioFeatures_getPortProgrammable(DioFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[22])(obj);   }
static int32             DioFeatures_getChannelCountMax(DioFeatures *obj)                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[23])(obj);  }
static int32             DioFeatures_getPortCount(DioFeatures *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[24])(obj);  }
static IArray *          DioFeatures_getPortsType(DioFeatures *obj)                                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[25])(obj); }
static int8              DioFeatures_getDiSupported(DioFeatures *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[26])(obj);   }
static int8              DioFeatures_getDoSupported(DioFeatures *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[27])(obj);   }

          
static IArray *          DioFeatures_getDiDataMask(DioFeatures *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[28])(obj); }


static int8              DioFeatures_getDiNoiseFilterSupported(DioFeatures *obj)                                                       { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[29])(obj);     }
static IArray *          DioFeatures_getDiNoiseFilterOfChannels(DioFeatures *obj)                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[30])(obj); }
static void              DioFeatures_getDiNoiseFilterBlockTimeRange(DioFeatures *obj, MathInterval *x)                                 {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Dio[31])(obj, x); }


static int8              DioFeatures_getDiintSupported(DioFeatures *obj)                                                               { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[32])(obj);     }
static int8              DioFeatures_getDiintGateSupported(DioFeatures *obj)                                                           { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[33])(obj);     }
static int8              DioFeatures_getDiCosintSupported(DioFeatures *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[34])(obj);     }
static int8              DioFeatures_getDiPmintSupported(DioFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[35])(obj);     }
static IArray *          DioFeatures_getDiintTriggerEdges(DioFeatures *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[36])(obj); }
static IArray *          DioFeatures_getDiintOfChannels(DioFeatures *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[37])(obj); }
static IArray *          DioFeatures_getDiintGateOfChannels(DioFeatures *obj)                                                          { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[38])(obj); }
static IArray *          DioFeatures_getDiCosintOfPorts(DioFeatures *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[39])(obj); }
static IArray *          DioFeatures_getDiPmintOfPorts(DioFeatures *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[40])(obj); }
static IArray *          DioFeatures_getDiSnapEventSources(DioFeatures *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[41])(obj); }

     
static IArray *          DioFeatures_getDoDataMask(DioFeatures *obj)                                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[42])(obj);         }
static IArray *          DioFeatures_getDoFreezeSignalSources(DioFeatures *obj)                                                        { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[43])(obj);         }
static void              DioFeatures_getDoReflectWdtFeedIntervalRange(DioFeatures *obj, MathInterval *x)                               {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Dio[44])(obj, x);}
static Depository        DioFeatures_getDoPresetValueDepository(DioFeatures *obj)                                                      { return ((Depository ( *)(void *))(*DNL_PPtr())->Dio[63])(obj);       }
static IArray *          DioFeatures_getDoCircuitSelectableTypes(DioFeatures *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[66])(obj);         } 


static IArray *          DioFeatures_getDataMask(DioFeatures *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[62])(obj); }


static int8              DioFeatures_getBufferedDiSupported(DioFeatures *obj)                                                          { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[69])(obj);           }
static SamplingMethod    DioFeatures_getDiSamplingMethod(DioFeatures *obj)                                                             { return ((SamplingMethod ( *)(void *))(*DNL_PPtr())->Dio[70])(obj); }


static IArray *          DioFeatures_getDiConvertClockSources(DioFeatures *obj)                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[71])(obj);         }
static void              DioFeatures_getDiConvertClockRange(DioFeatures *obj, MathInterval *x)                                        {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Dio[72])(obj, x);}


static int8              DioFeatures_getDiRetriggerable(DioFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[73])(obj);  }
static int32             DioFeatures_getDiTriggerCount(DioFeatures *obj)                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[74])(obj); }


static IArray *          DioFeatures_getDiTriggerActions(DioFeatures *obj)                                                            { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[75])(obj, 0);         }
static void              DioFeatures_getDiTriggerDelayRange(DioFeatures *obj, MathInterval *x)                                        {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Dio[76])(obj, 0, x);}
static IArray *          DioFeatures_getDiTriggerSources(DioFeatures *obj)                                                            { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[77])(obj, 0);         }
static ValueRange        DioFeatures_getDiTriggerSourceVrg(DioFeatures *obj)                                                          { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Dio[78])(obj, 0);       }
static double            DioFeatures_getDiTriggerHysteresisIndexMax(DioFeatures *obj)                                                 { return ((double ( *)(void *, int32))(*DNL_PPtr())->Dio[79])(obj, 0);           }
static int32             DioFeatures_getDiTriggerHysteresisIndexStep(DioFeatures *obj)                                                { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Dio[80])(obj, 0);            }
                                                                  
static IArray *          DioFeatures_getDiTrigger1Actions(DioFeatures *obj)                                                           { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[75])(obj, 1);         }
static void              DioFeatures_getDiTrigger1DelayRange(DioFeatures *obj, MathInterval *x)                                       {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Dio[76])(obj, 1, x);}
static IArray *          DioFeatures_getDiTrigger1Sources(DioFeatures *obj)                                                           { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[77])(obj, 1);         }
static ValueRange        DioFeatures_getDiTrigger1SourceVrg(DioFeatures *obj)                                                         { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Dio[78])(obj, 1);       }
static double            DioFeatures_getDiTrigger1HysteresisIndexMax(DioFeatures *obj)                                                { return ((double ( *)(void *, int32))(*DNL_PPtr())->Dio[79])(obj, 1);           }
static int32             DioFeatures_getDiTrigger1HysteresisIndexStep(DioFeatures *obj)                                               { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Dio[80])(obj, 1);            }


static int32             DioFeatures_getDataSize(DioFeatures *obj)                                                                    { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[92])(obj); }
static int32             DioFeatures_getResolution(DioFeatures *obj)                                                                  { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[93])(obj); }


static int8              DioFeatures_getBufferedDoSupported(DioFeatures *obj)                                                         { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[94])(obj);           }
static SamplingMethod    DioFeatures_getDoSamplingMethod(DioFeatures *obj)                                                            { return ((SamplingMethod ( *)(void *))(*DNL_PPtr())->Dio[95])(obj); }


static IArray *          DioFeatures_getDoConvertClockSources(DioFeatures *obj)                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[96])(obj);         }
static void              DioFeatures_getDoConvertClockRange(DioFeatures *obj, MathInterval *x)                                        {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Dio[97])(obj, x);}


static int8              DioFeatures_getDoRetriggerable(DioFeatures *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[98])(obj);  }
static int32             DioFeatures_getDoTriggerCount(DioFeatures *obj)                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[99])(obj); }


static IArray *          DioFeatures_getDoTriggerActions(DioFeatures *obj)                                                            { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[100])(obj, 0);         }
static void              DioFeatures_getDoTriggerDelayRange(DioFeatures *obj, MathInterval *x)                                        {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Dio[101])(obj, 0, x);}
static IArray *          DioFeatures_getDoTriggerSources(DioFeatures *obj)                                                            { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[102])(obj, 0);         }
static ValueRange        DioFeatures_getDoTriggerSourceVrg(DioFeatures *obj)                                                          { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Dio[103])(obj, 0);       }
static double            DioFeatures_getDoTriggerHysteresisIndexMax(DioFeatures *obj)                                                 { return ((double ( *)(void *, int32))(*DNL_PPtr())->Dio[104])(obj, 0);           }
static int32             DioFeatures_getDoTriggerHysteresisIndexStep(DioFeatures *obj)                                                { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Dio[105])(obj, 0);            }
                                                                  
static IArray *          DioFeatures_getDoTrigger1Actions(DioFeatures *obj)                                                           { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[100])(obj, 1);         }
static void              DioFeatures_getDoTrigger1DelayRange(DioFeatures *obj, MathInterval *x)                                       {        ((void ( *)(void *, int32, MathInterval *))(*DNL_PPtr())->Dio[101])(obj, 1, x);}
static IArray *          DioFeatures_getDoTrigger1Sources(DioFeatures *obj)                                                           { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Dio[102])(obj, 1);         }
static ValueRange        DioFeatures_getDoTrigger1SourceVrg(DioFeatures *obj)                                                         { return ((ValueRange ( *)(void *, int32))(*DNL_PPtr())->Dio[103])(obj, 1);       }
static double            DioFeatures_getDoTrigger1HysteresisIndexMax(DioFeatures *obj)                                                { return ((double ( *)(void *, int32))(*DNL_PPtr())->Dio[104])(obj, 1);           }
static int32             DioFeatures_getDoTrigger1HysteresisIndexStep(DioFeatures *obj)                                               { return ((int32 ( *)(void *, int32))(*DNL_PPtr())->Dio[105])(obj, 1);            }





static ErrorCode         InstantDiCtrl_LoadProfile(InstantDiCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              InstantDiCtrl_Cleanup(InstantDiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              InstantDiCtrl_Dispose(InstantDiCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              InstantDiCtrl_getSelectedDevice(InstantDiCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         InstantDiCtrl_setSelectedDevice(InstantDiCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      InstantDiCtrl_getState(void *obj)                                                                             { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj); }
static DeviceCtrl *      InstantDiCtrl_getDevice(InstantDiCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj); }
static IArray *          InstantDiCtrl_getSupportedDevices(InstantDiCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);     }
static IArray *          InstantDiCtrl_getSupportedModes(InstantDiCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);     }
                
static DioFeatures *     InstantDiCtrl_getFeatures(InstantDiCtrl *obj)                                                                 { return ((DioFeatures * ( *)(void *))(*DNL_PPtr())->Dio[45])(obj); }
static int32             InstantDiCtrl_getPortCount(InstantDiCtrl *obj)                                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[46])(obj);         }
static IArray *          InstantDiCtrl_getPorts(InstantDiCtrl *obj)                                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[47])(obj);      }

static ErrorCode         InstantDiCtrl_ReadAny(InstantDiCtrl *obj, int32 portStart, int32 portCount, uint8 data[])                     { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[48])(obj, portStart, portCount, data);}
static ErrorCode         InstantDiCtrl_ReadBit(InstantDiCtrl *obj, int32 port, int32 bit, uint8* data)                                 { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[49])(obj, port, bit, data);           }
static ErrorCode         InstantDiCtrl_SnapStart(InstantDiCtrl *obj)                                                                   { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[50])(obj);                }
static ErrorCode         InstantDiCtrl_SnapStop(InstantDiCtrl *obj)                                                                    { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[51])(obj);                }
static double            InstantDiCtrl_getNoiseFilterBlockTime(InstantDiCtrl *obj)                                                     { return ((double ( *)(void *))(*DNL_PPtr())->Dio[52])(obj);        }
static ErrorCode         InstantDiCtrl_setNoiseFilterBlockTime(InstantDiCtrl *obj, double value)                                       { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Dio[53])(obj, value); }
static IArray *          InstantDiCtrl_getNoiseFilter(InstantDiCtrl *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[54])(obj);      }
static IArray *          InstantDiCtrl_getDiintChannels(InstantDiCtrl *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[55])(obj);      }
static IArray *          InstantDiCtrl_getDiCosintPorts(InstantDiCtrl *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[56])(obj);      }
static IArray *          InstantDiCtrl_getDiPmintPorts(InstantDiCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[57])(obj);      }

static InstantDiCtrl *   InstantDiCtrl_Create(void)                                                                                    { return (InstantDiCtrl *)DaqCtrlBase_Create(SceInstantDi); } 


static void              InstantDiCtrl_addInterruptHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtDiInterrupt,    (DaqEventProc)proc, userParam);}
static void              InstantDiCtrl_removeInterruptHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtDiInterrupt,    (DaqEventProc)proc, userParam);}
static void              InstantDiCtrl_addChangeOfStateHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtDiStatusChange, (DaqEventProc)proc, userParam);}
static void              InstantDiCtrl_removeChangeOfStateHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtDiStatusChange, (DaqEventProc)proc, userParam);}
static void              InstantDiCtrl_addPatternMatchHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)                { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtDiPatternMatch, (DaqEventProc)proc, userParam);}
static void              InstantDiCtrl_removePatternMatchHandler(InstantDiCtrl *obj,DiSnapEventProc proc, void *userParam)             { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtDiPatternMatch, (DaqEventProc)proc, userParam);}





static ErrorCode         BufferedDiCtrl_LoadProfile(BufferedDiCtrl *obj, wchar_t const *fileName)                                     { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedDiCtrl_Cleanup(BufferedDiCtrl *obj)                                                                  {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedDiCtrl_Dispose(BufferedDiCtrl *obj)                                                                  {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedDiCtrl_getSelectedDevice(BufferedDiCtrl *obj, DeviceInformation *x)                                  {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedDiCtrl_setSelectedDevice(BufferedDiCtrl *obj, DeviceInformation const *x)                            { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedDiCtrl_getState(void *obj)                                                                           { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      BufferedDiCtrl_getDevice(BufferedDiCtrl *obj)                                                                { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          BufferedDiCtrl_getSupportedDevices(BufferedDiCtrl *obj)                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          BufferedDiCtrl_getSupportedModes(BufferedDiCtrl *obj)                                                        { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }

                
static DioFeatures *     BufferedDiCtrl_getFeatures(BufferedDiCtrl *obj)                                                              { return ((DioFeatures * ( *)(void *))(*DNL_PPtr())->Dio[45])(obj); }
static int32             BufferedDiCtrl_getPortCount(BufferedDiCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[46])(obj);         }
static IArray *          BufferedDiCtrl_getPorts(BufferedDiCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[47])(obj);      }


static ErrorCode         BufferedDiCtrl_Prepare(BufferedDiCtrl *obj)                                                                  { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[81])(obj);   }
static ErrorCode         BufferedDiCtrl_Start(BufferedDiCtrl *obj)                                                                    { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[82])(obj);   }
static ErrorCode         BufferedDiCtrl_Stop(BufferedDiCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[83])(obj);   }
static void              BufferedDiCtrl_Release(BufferedDiCtrl *obj)                                                                  {        ((void ( *)(void *))(*DNL_PPtr())->Dio[84])(obj);   }
static int8              BufferedDiCtrl_GetBufferStatus(BufferedDiCtrl *obj, int32 *count, int32 *offset)                             { return ((int8 ( *)(void *, int32 *, int32 *))(*DNL_PPtr())->Dio[85])(obj, count, offset); }  

static ErrorCode BufferedDiCtrl_GetData(BufferedDiCtrl *obj, int32 count, int8 dataBuf[], 
                                            int32 timeout, int32 *returned, double * startTime, int32 *markCount, DataMark *markBuf)
{ 
   typedef ErrorCode ( *FNGETDATA)(void *, int32, void *, int32, int32 *, double *, int32 *, DataMark *);
   return ((FNGETDATA)(*DNL_PPtr())->Dio[86])(obj, count, dataBuf, timeout, returned, startTime, markCount, markBuf);        
}

static void*             BufferedDiCtrl_getBuffer(BufferedDiCtrl *obj)                                                                   { return ((void* ( *)(void *))(*DNL_PPtr())->Dio[87])(obj);               }
static int32             BufferedDiCtrl_getBufferCapacity(BufferedDiCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[88])(obj);               }
static ScanPort *        BufferedDiCtrl_getScanPort(BufferedDiCtrl *obj)                                                                 { return ((ScanPort * ( *)(void *))(*DNL_PPtr())->Dio[89])(obj);          }
static ConvertClock*     BufferedDiCtrl_getConvertClock(BufferedDiCtrl *obj)                                                             { return ((ConvertClock * ( *)(void *))(*DNL_PPtr())->Dio[90])(obj);   }
static Trigger *         BufferedDiCtrl_getTrigger(BufferedDiCtrl *obj)                                                                  { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Dio[91])(obj, 0); }
static Trigger *         BufferedDiCtrl_getTrigger1(BufferedDiCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Dio[91])(obj, 1); }

static BufferedDiCtrl *  BufferedDiCtrl_Create(void)                                                                                     { return (BufferedDiCtrl *)DaqCtrlBase_Create(SceBufferedDi); } 


static void              BufferedDiCtrl_addDataReadyHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_removeDataReadyHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_addOverrunHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_removeOverrunHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_addCacheOverflowHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_removeCacheOverflowHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_addStoppedHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDiStopped,       (DaqEventProc)proc, userParam);}
static void              BufferedDiCtrl_removeStoppedHandler(BufferedDiCtrl *obj, BfdDiEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDiStopped,       (DaqEventProc)proc, userParam);}





static ErrorCode         InstantDoCtrl_LoadProfile(InstantDoCtrl *obj, wchar_t const *fileName)                                           { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              InstantDoCtrl_Cleanup(InstantDoCtrl *obj)                                                                        {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              InstantDoCtrl_Dispose(InstantDoCtrl *obj)                                                                        {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              InstantDoCtrl_getSelectedDevice(InstantDoCtrl *obj, DeviceInformation *x)                                        {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         InstantDoCtrl_setSelectedDevice(InstantDoCtrl *obj, DeviceInformation const *x)                                  { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      InstantDoCtrl_getState(void *obj)                                                                                { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj); }
static DeviceCtrl *      InstantDoCtrl_getDevice(InstantDoCtrl *obj)                                                                      { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj); }
static IArray *          InstantDoCtrl_getSupportedDevices(InstantDoCtrl *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);     }
static IArray *          InstantDoCtrl_getSupportedModes(InstantDoCtrl *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);     }
                
static DioFeatures *     InstantDoCtrl_getFeatures(InstantDoCtrl *obj)                                                                    { return ((DioFeatures * ( *)(void *))(*DNL_PPtr())->Dio[45])(obj); }
static int32             InstantDoCtrl_getPortCount(InstantDoCtrl *obj)                                                                   { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[46])(obj);         }
static IArray *          InstantDoCtrl_getPorts(InstantDoCtrl *obj)                                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[47])(obj);      }
 
static ErrorCode         InstantDoCtrl_WriteAny(InstantDoCtrl *obj, int32 portStart, int32 portCount, uint8 data[])                       { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[58])(obj, portStart, portCount, data); }
static ErrorCode         InstantDoCtrl_ReadAny(InstantDoCtrl *obj, int32 portStart, int32 portCount, uint8 data[])                        { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[59])(obj, portStart, portCount, data); }
static ErrorCode         InstantDoCtrl_WriteBit(InstantDoCtrl *obj, int32 port, int32 bit, uint8 data)                                    { return ((ErrorCode ( *)(void *, int32, int32, uint8))(*DNL_PPtr())->Dio[60])(obj, port, bit, data);            }
static ErrorCode         InstantDoCtrl_ReadBit(InstantDoCtrl *obj, int32 port, int32 bit, uint8* data)                                    { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[61])(obj, port, bit, data);            }

static InstantDoCtrl *   InstantDoCtrl_Create(void)                                                                                       { return (InstantDoCtrl *)DaqCtrlBase_Create(SceInstantDo); } 






static ErrorCode         BufferedDoCtrl_LoadProfile(BufferedDoCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedDoCtrl_Cleanup(BufferedDoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedDoCtrl_Dispose(BufferedDoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedDoCtrl_getSelectedDevice(BufferedDoCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedDoCtrl_setSelectedDevice(BufferedDoCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedDoCtrl_getState(void *obj)                                                                              { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);}
static DeviceCtrl *      BufferedDoCtrl_getDevice(BufferedDoCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);}
static IArray *          BufferedDoCtrl_getSupportedDevices(BufferedDoCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);    }
static IArray *          BufferedDoCtrl_getSupportedModes(BufferedDoCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);    }
                                                                                                                                  
static DioFeatures *     BufferedDoCtrl_getFeatures(BufferedDoCtrl *obj)                                                                 { return ((DioFeatures * ( *)(void *))(*DNL_PPtr())->Dio[45])(obj); }
static int32             BufferedDoCtrl_getPortCount(BufferedDoCtrl *obj)                                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[46])(obj);         }
static IArray *          BufferedDoCtrl_getPorts(BufferedDoCtrl *obj)                                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Dio[47])(obj);      }

                                                                                                   
static ErrorCode         BufferedDoCtrl_Prepare(BufferedDoCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[106])(obj);   }
static ErrorCode         BufferedDoCtrl_RunOnce(BufferedDoCtrl *obj)                                                                     { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[107])(obj);   }
static ErrorCode         BufferedDoCtrl_Start(BufferedDoCtrl *obj)                                                                       { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Dio[108])(obj);   }
static ErrorCode         BufferedDoCtrl_Stop(BufferedDoCtrl *obj, int32 action)                                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[109])(obj, action); }
static void              BufferedDoCtrl_Release(BufferedDoCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Dio[110])(obj);                }
static int8              BufferedDoCtrl_GetBufferStatus(BufferedDoCtrl *obj, int32 *count, int32 *offset)                                { return ((int8 ( *)(void *, int32 *, int32 *))(*DNL_PPtr())->Dio[111])(obj, count, offset);    }  
static ErrorCode         BufferedDoCtrl_SetData(BufferedDoCtrl *obj, int32 count, int8 rawData[])                                        { return ((ErrorCode ( *)(void *, int32, void*))(*DNL_PPtr())->Dio[112])(obj, count, rawData);     }
static void*             BufferedDoCtrl_getBuffer(BufferedDoCtrl *obj)                                                                   { return ((void* ( *)(void *))(*DNL_PPtr())->Dio[113])(obj);               }
static int32             BufferedDoCtrl_getBufferCapacity(BufferedDoCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[114])(obj);               }
static ScanPort *        BufferedDoCtrl_getScanPort(BufferedDoCtrl *obj)                                                                 { return ((ScanPort * ( *)(void *))(*DNL_PPtr())->Dio[115])(obj);          }
static ConvertClock*     BufferedDoCtrl_getConvertClock(BufferedDoCtrl *obj)                                                             { return ((ConvertClock * ( *)(void *))(*DNL_PPtr())->Dio[116])(obj);   }
static Trigger *         BufferedDoCtrl_getTrigger(BufferedDoCtrl *obj)                                                                  { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Dio[117])(obj, 0); }
static Trigger *         BufferedDoCtrl_getTrigger1(BufferedDoCtrl *obj)                                                                 { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Dio[117])(obj, 1); }
static int8              BufferedDoCtrl_getStreaming(BufferedDoCtrl *obj)                                                                { return ((int8 ( *)(void *))(*DNL_PPtr())->Dio[118])(obj);                }
static ErrorCode         BufferedDoCtrl_setStreaming(BufferedDoCtrl *obj, int8 value)                                                    { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Dio[119])(obj, value);         }
static ErrorCode         BufferedDoCtrl_ReadPort(BufferedDoCtrl *obj, int32 portStart, int32 portCount, uint8 data[])                    { return ((ErrorCode ( *)(void *, int32, int32, uint8 *))(*DNL_PPtr())->Dio[120])(obj, portStart, portCount, data); }




static int32             ScanPort_getPortStart(ScanPort *obj)                                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[121])(obj);         }
static ErrorCode         ScanPort_setPortStart(ScanPort *obj, int32 value)                                                              { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[122])(obj, value);  }
static int32             ScanPort_getPortCount(ScanPort *obj)                                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[123])(obj);         }
static ErrorCode         ScanPort_setPortCount(ScanPort *obj, int32 value)                                                              { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[124])(obj, value);  }
static void              ScanPort_getPortMap(ScanPort *obj, int32 count, int8 *portMap)                                                 {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Dio[125])(obj, count, portMap); }
static ErrorCode         ScanPort_setPortMap(ScanPort *obj, int32 count, int8 *portMap)                                                 { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Dio[126])(obj, count, portMap); }
static int32             ScanPort_getSectionLength(ScanPort *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[127])(obj);        }
static ErrorCode         ScanPort_setSectionLength(ScanPort *obj, int32 value)                                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[128])(obj, value); }
static int32             ScanPort_getSectionCount(ScanPort *obj)                                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[129])(obj);        }
static ErrorCode         ScanPort_setSectionCount(ScanPort *obj, int32 value)                                                           { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[130])(obj, value); }
static int32             ScanPort_getCycles(ScanPort *obj)                                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Dio[131])(obj);        }
static ErrorCode         ScanPort_setCycles(ScanPort *obj, int32 value)                                                                 { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Dio[132])(obj, value); }




static BufferedDoCtrl *  BufferedDoCtrl_Create(void)                                                                                     { return (BufferedDoCtrl *)DaqCtrlBase_Create(SceBufferedDo); } 


static void              BufferedDoCtrl_addDataTransmittedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)             { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_removeDataTransmittedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)          { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_addUnderrunHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)                    { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_removeUnderrunHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)                 { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_addCacheEmptiedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)                { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_removeCacheEmptiedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)             { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_addTransitStoppedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)              { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_removeTransitStoppedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)           { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_addStoppedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtBufferedDoStopped,         (DaqEventProc)proc, userParam); }
static void              BufferedDoCtrl_removeStoppedHandler(BufferedDoCtrl *obj, BfdDoEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtBufferedDoStopped,         (DaqEventProc)proc, userParam); }







static void              CounterIndexer_Dispose(ICounterIndexer *obj)                                                                         {        ((void ( *)(void *))(*DNL_PPtr())->Cntr[0])(obj);         }
static int32             CounterIndexer_getLength(ICounterIndexer *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[1])(obj);  }
static IArray *          CounterIndexer_getItem(ICounterIndexer *obj, int32 channel)                                                          { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Cntr[2])(obj, channel); }





static int32             CntrFeatures_getChannelCountMax(CntrFeatures *obj)                                                            { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[3])(obj);        }
static int32             CntrFeatures_getResolution(CntrFeatures *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[4])(obj);        }
static int32             CntrFeatures_getDataSize(CntrFeatures *obj)                                                                   { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[5])(obj);        }
static ICounterIndexer * CntrFeatures_getCapabilities(CntrFeatures *obj)                                                               { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[6])(obj); }


static int8              CntrFeatures_getNoiseFilterSupported(CntrFeatures *obj)                                                       { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[7])(obj);     }
static IArray *          CntrFeatures_getNoiseFilterOfChannels(CntrFeatures *obj)                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[8])(obj); }
static void              CntrFeatures_getNoiseFilterBlockTimeRange(CntrFeatures *obj, MathInterval *x)                                 {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[9])(obj, x); } 


static ICounterIndexer * CntrFeatures_getEcClockSources(CntrFeatures *obj)                                                             { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[193])(obj);}
static IArray *          CntrFeatures_getEcClockPolarities(CntrFeatures *obj)                                                          { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[10])(obj); }
static IArray *          CntrFeatures_getEcGatePolarities(CntrFeatures *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[11])(obj); }
static IArray *          CntrFeatures_getEcGateControlOfChannels(CntrFeatures *obj)                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[12])(obj); }

                                                                      
static IArray *          CntrFeatures_getFmMethods(CntrFeatures *obj)                                                                  { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[13])(obj); }

                                                                                   
static ICounterIndexer * CntrFeatures_getOsClockSources(CntrFeatures *obj)                                                             { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[14])(obj);}
static IArray *          CntrFeatures_getOsClockPolarities(CntrFeatures *obj)                                                          { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[15])(obj);      }
static ICounterIndexer * CntrFeatures_getOsGateSources(CntrFeatures *obj)                                                              { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[16])(obj);}
static IArray *          CntrFeatures_getOsGatePolarities(CntrFeatures *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[17])(obj);      }
static IArray *          CntrFeatures_getOsOutSignals(CntrFeatures *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[18])(obj);      }
static void              CntrFeatures_getOsDelayCountRange(CntrFeatures *obj, MathInterval *x)                                         {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[19])(obj, x); }

                                                                               
static IArray *          CntrFeatures_getTmrGateControlOfChannels(CntrFeatures *obj)                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[20])(obj); }
static IArray *          CntrFeatures_getTmrGatePolarities(CntrFeatures *obj)                                                          { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[21])(obj); }
static IArray *          CntrFeatures_getTmrOutSignals(CntrFeatures *obj)                                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[22])(obj); }
static void              CntrFeatures_getTmrFrequencyRange(CntrFeatures *obj, MathInterval *x)                                         {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[23])(obj, x); }

                                                                    
static IArray *          CntrFeatures_getPiCascadeGroup(CntrFeatures *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[24])(obj); }

                                                                     
static IArray *          CntrFeatures_getPoGateControlOfChannels(CntrFeatures *obj)                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[25])(obj); }
static IArray *          CntrFeatures_getPoGatePolarities(CntrFeatures *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[26])(obj); }
static IArray *          CntrFeatures_getPoOutSignals(CntrFeatures *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[27])(obj); }
static void              CntrFeatures_getPoHiPeriodRange(CntrFeatures *obj, MathInterval *x)                                           {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[28])(obj, x); } 
static void              CntrFeatures_getPoLoPeriodRange(CntrFeatures *obj, MathInterval *x)                                           {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[29])(obj, x); } 
static void              CntrFeatures_getPoOutCountRange(CntrFeatures *obj, MathInterval *x)                                           {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[30])(obj, x); }


static IArray *          CntrFeatures_getUdCountingTypes(CntrFeatures *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[31])(obj); }
static IArray *          CntrFeatures_getUdInitialValues(CntrFeatures *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[32])(obj); }
static IArray *          CntrFeatures_getUdSnapEventSources(CntrFeatures *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[33])(obj); }


static void              CntrFeatures_getMeasurementTimeoutRange(CntrFeatures *obj, MathInterval *x)                                   {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[129])(obj, x); }
static void              CntrFeatures_getUdValueResetTimes(CntrFeatures *obj, MathInterval *x)                                         {        ((void ( *)(void *, MathInterval *))(*DNL_PPtr())->Cntr[192])(obj, x); }
 
 
static int32             CntrFeatures_getTriggerCount(CntrFeatures *obj)                                                               { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[132])(obj);              }
static IArray *          CntrFeatures_getTriggerSources(CntrFeatures *obj)                                                             { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Cntr[133])(obj, 0); }
static IArray *          CntrFeatures_getTriggerActions(CntrFeatures *obj)                                                             { return ((IArray * ( *)(void *, int32))(*DNL_PPtr())->Cntr[134])(obj, 0); }
static ICounterIndexer * CntrFeatures_getEcSampleClockSources(CntrFeatures *obj)                                                       { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[135])(obj);  }
static ICounterIndexer * CntrFeatures_getPiSampleClockSources(CntrFeatures *obj)                                                       { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[136])(obj);  }
static ICounterIndexer * CntrFeatures_getPoSampleClockSources(CntrFeatures *obj)                                                       { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[137])(obj);  }
static ICounterIndexer * CntrFeatures_getUdSampleClockSources(CntrFeatures *obj)                                                       { return ((ICounterIndexer * ( *)(void *))(*DNL_PPtr())->Cntr[138])(obj);  }



static int32             EcChannel_getChannel(EcChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[45])(obj);                 }
static int8              EcChannel_getNoiseFiltered(EcChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[46])(obj);                  }
static ErrorCode         EcChannel_setNoiseFiltered(EcChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[47])(obj, value);           }
static SignalDrop        EcChannel_getClockSource(EcChannel *obj)                                                                      { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[194])(obj);           }
static ErrorCode         EcChannel_setClockSource(EcChannel *obj, SignalDrop value)                                                    { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[195])(obj, value);    }
static SignalPolarity    EcChannel_getClockPolarity(EcChannel *obj)                                                                    { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[48])(obj);        }
static ErrorCode         EcChannel_setClockPolarity(EcChannel *obj, SignalPolarity value)                                              { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[49])(obj, value); }
static SignalPolarity    EcChannel_getGatePolarity(EcChannel *obj)                                                                     { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[50])(obj);        }
static ErrorCode         EcChannel_setGatePolarity(EcChannel *obj, SignalPolarity value)                                               { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[51])(obj, value); }
static int8              EcChannel_getGated(EcChannel *obj)                                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[52])(obj);                  }
static ErrorCode         EcChannel_setGated(EcChannel *obj, int8 value)                                                                { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[53])(obj, value);           }

                                          



static ErrorCode         EventCounterCtrl_LoadProfile(EventCounterCtrl *obj, wchar_t const *fileName)                                  { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              EventCounterCtrl_Cleanup(EventCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              EventCounterCtrl_Dispose(EventCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              EventCounterCtrl_getSelectedDevice(EventCounterCtrl *obj, DeviceInformation *x)                               {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         EventCounterCtrl_setSelectedDevice(EventCounterCtrl *obj, DeviceInformation const *x)                         { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      EventCounterCtrl_getState(void *obj)                                                                          { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      EventCounterCtrl_getDevice(EventCounterCtrl *obj)                                                             { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          EventCounterCtrl_getSupportedDevices(EventCounterCtrl *obj)                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          EventCounterCtrl_getSupportedModes(EventCounterCtrl *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                 
static CntrFeatures *    EventCounterCtrl_getFeatures(EventCounterCtrl *obj)                                                           { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             EventCounterCtrl_getChannelStart(EventCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         EventCounterCtrl_setChannelStart(EventCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             EventCounterCtrl_getChannelCount(EventCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         EventCounterCtrl_setChannelCount(EventCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              EventCounterCtrl_getEnabled(EventCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         EventCounterCtrl_setEnabled(EventCounterCtrl *obj, int8 enabled)                                              { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              EventCounterCtrl_getRunning(EventCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            EventCounterCtrl_getNoiseFilterBlockTime(EventCounterCtrl *obj)                                               { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         EventCounterCtrl_setNoiseFilterBlockTime(EventCounterCtrl *obj, double value)                                 { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   EventCounterCtrl_getNoiseFilter(EventCounterCtrl *obj)                                                        { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
static double            EventCounterCtrl_getMeasurementTimeout(EventCounterCtrl *obj)                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[130])(obj);        }
static ErrorCode         EventCounterCtrl_setMeasurementTimeout(EventCounterCtrl *obj, double value)                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[131])(obj, value); }

static ErrorCode         EventCounterCtrl_Read(EventCounterCtrl *obj, int32 count, int32 *buffer)                                      { return ((ErrorCode ( *)(void *, int32, int32 *))(*DNL_PPtr())->Cntr[54])(obj, count, buffer); }
static IArray *          EventCounterCtrl_getChannels(EventCounterCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[55])(obj);                       }

static EventCounterCtrl* EventCounterCtrl_Create(void)                                                                                 { return (EventCounterCtrl *)DaqCtrlBase_Create(SceEventCounter); } 




static ErrorCode         BufferedEventCounterCtrl_LoadProfile(BufferedEventCounterCtrl *obj, wchar_t const *fileName)                                  { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedEventCounterCtrl_Cleanup(BufferedEventCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedEventCounterCtrl_Dispose(BufferedEventCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedEventCounterCtrl_getSelectedDevice(BufferedEventCounterCtrl *obj, DeviceInformation *x)                               {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedEventCounterCtrl_setSelectedDevice(BufferedEventCounterCtrl *obj, DeviceInformation const *x)                         { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedEventCounterCtrl_getState(void *obj)                                                                                  { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      BufferedEventCounterCtrl_getDevice(BufferedEventCounterCtrl *obj)                                                             { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          BufferedEventCounterCtrl_getSupportedDevices(BufferedEventCounterCtrl *obj)                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          BufferedEventCounterCtrl_getSupportedModes(BufferedEventCounterCtrl *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }

static CntrFeatures    * BufferedEventCounterCtrl_getFeatures(BufferedEventCounterCtrl *obj)                                                           { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             BufferedEventCounterCtrl_getChannelStart(BufferedEventCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         BufferedEventCounterCtrl_setChannelStart(BufferedEventCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             BufferedEventCounterCtrl_getChannelCount(BufferedEventCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         BufferedEventCounterCtrl_setChannelCount(BufferedEventCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              BufferedEventCounterCtrl_getEnabled(BufferedEventCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         BufferedEventCounterCtrl_setEnabled(BufferedEventCounterCtrl *obj, int8 enable)                                               { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enable);  }
static int8              BufferedEventCounterCtrl_getRunning(BufferedEventCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            BufferedEventCounterCtrl_getNoiseFilterBlockTime(BufferedEventCounterCtrl *obj)                                               { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         BufferedEventCounterCtrl_setNoiseFilterBlockTime(BufferedEventCounterCtrl *obj, double value)                                 { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   BufferedEventCounterCtrl_getNoiseFilter(BufferedEventCounterCtrl *obj)                                                        { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
static double            BufferedEventCounterCtrl_getMeasurementTimeout(BufferedEventCounterCtrl *obj)                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[130])(obj);        }
static ErrorCode         BufferedEventCounterCtrl_setMeasurementTimeout(BufferedEventCounterCtrl *obj, double value)                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[131])(obj, value); }


static int32             BufferedEventCounterCtrl_getBufferCapacity(BufferedEventCounterCtrl *obj)                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[183])(obj);              }
static int8              BufferedEventCounterCtrl_getBufferStatus(BufferedEventCounterCtrl *obj, int32 ch, int32 *count, int32 *offset)                { return ((int8 ( *)(void *, int32, int32 *, int32 *))(*DNL_PPtr())->Cntr[188])(obj, ch, count, offset); }
static Trigger*          BufferedEventCounterCtrl_getTrigger(BufferedEventCounterCtrl *obj)                                                            { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Cntr[141])(obj, 0); }
static Record*           BufferedEventCounterCtrl_getRecord(BufferedEventCounterCtrl *obj)                                                             { return ((Record * ( *)(void *))(*DNL_PPtr())->Cntr[142])(obj);            }
static ErrorCode         BufferedEventCounterCtrl_setSampleClkSrc(BufferedEventCounterCtrl *obj, SignalDrop drop)                                      { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[143])(obj, drop);    }
static SignalDrop        BufferedEventCounterCtrl_getSampleClkSrc(BufferedEventCounterCtrl *obj)                                                       { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[144])(obj);          }
static void              BufferedEventCounterCtrl_getChannelMap(BufferedEventCounterCtrl *obj, int32 count, int8 *chMap)                               {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[139])(obj, count, chMap); }
static ErrorCode         BufferedEventCounterCtrl_setChannelMap(BufferedEventCounterCtrl *obj, int32 count, int8 *chMap)                               { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[140])(obj, count, chMap); }
static ErrorCode         BufferedEventCounterCtrl_Prepare(BufferedEventCounterCtrl *obj)                                                               { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Cntr[146])(obj);                      }
static void              BufferedEventCounterCtrl_Release(BufferedEventCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Cntr[147])(obj);                      }
static IArray *          BufferedEventCounterCtrl_getChannels(BufferedEventCounterCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[145])(obj);            }
static ErrorCode         BufferedEventCounterCtrl_GetDataI32(BufferedEventCounterCtrl *obj, int32 cntr, int32 count, int32 dataBuf[], int32 timeout, int32 *returned, double *startTime)
{
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void*, int32, int32*, double*);
   return ((FNGETDATA)(*DNL_PPtr())->Cntr[148])(obj, cntr, count, dataBuf, timeout, returned, startTime);
}


static BufferedEventCounterCtrl* BufferedEventCounterCtrl_Create(void)                                                                                 { return (BufferedEventCounterCtrl *)DaqCtrlBase_Create(SceBufferedEventCounter); } 


static void              BufferedEventCounterCtrl_addDataReadyHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_removeDataReadyHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_addOverrunHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_removeOverrunHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_addCacheOverflowHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_removeCacheOverflowHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_addStoppedHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}
static void              BufferedEventCounterCtrl_removeStoppedHandler(BufferedEventCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}

                                          
                                          

                                          
static int32             FmChannel_getChannel(FmChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[56])(obj);                   }
static int8              FmChannel_getNoiseFiltered(FmChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[57])(obj);                    }
static ErrorCode         FmChannel_setNoiseFiltered(FmChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[58])(obj, value);             }
static FreqMeasureMethod FmChannel_getFmMethod(FmChannel *obj)                                                                         { return ((FreqMeasureMethod ( *)(void *))(*DNL_PPtr())->Cntr[59])(obj);       }
static ErrorCode         FmChannel_setFmMethod(FmChannel *obj, FreqMeasureMethod value)                                                { return ((ErrorCode ( *)(void *, FreqMeasureMethod))(*DNL_PPtr())->Cntr[60])(obj, value);}
static double            FmChannel_getCollectionPeriod(FmChannel *obj)                                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[61])(obj);                  }
static ErrorCode         FmChannel_setCollectionPeriod(FmChannel *obj, double value)                                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[62])(obj, value);           }

                                        

   

static ErrorCode         FreqMeterCtrl_LoadProfile(FreqMeterCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              FreqMeterCtrl_Cleanup(FreqMeterCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              FreqMeterCtrl_Dispose(FreqMeterCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              FreqMeterCtrl_getSelectedDevice(FreqMeterCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         FreqMeterCtrl_setSelectedDevice(FreqMeterCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      FreqMeterCtrl_getState(void *obj)                                                                             { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      FreqMeterCtrl_getDevice(FreqMeterCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          FreqMeterCtrl_getSupportedDevices(FreqMeterCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          FreqMeterCtrl_getSupportedModes(FreqMeterCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                        
static CntrFeatures *    FreqMeterCtrl_getFeatures(FreqMeterCtrl *obj)                                                                 { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             FreqMeterCtrl_getChannelStart(FreqMeterCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         FreqMeterCtrl_setChannelStart(FreqMeterCtrl *obj, int32 value)                                                { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             FreqMeterCtrl_getChannelCount(FreqMeterCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         FreqMeterCtrl_setChannelCount(FreqMeterCtrl *obj, int32 value)                                                { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              FreqMeterCtrl_getEnabled(FreqMeterCtrl *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         FreqMeterCtrl_setEnabled(FreqMeterCtrl *obj, int8 enabled)                                                    { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              FreqMeterCtrl_getRunning(FreqMeterCtrl *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            FreqMeterCtrl_getNoiseFilterBlockTime(FreqMeterCtrl *obj)                                                     { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         FreqMeterCtrl_setNoiseFilterBlockTime(FreqMeterCtrl *obj, double value)                                       { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   FreqMeterCtrl_getNoiseFilter(FreqMeterCtrl *obj)                                                              { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
static double            FreqMeterCtrl_getMeasurementTimeout(EventCounterCtrl *obj)                                                    { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[130])(obj);        }
static ErrorCode         FreqMeterCtrl_setMeasurementTimeout(EventCounterCtrl *obj, double value)                                      { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[131])(obj, value); }
                                                                                    
static ErrorCode         FreqMeterCtrl_Read(FreqMeterCtrl *obj, int32 count, double *buffer)                                           { return ((ErrorCode ( *)(void *, int32, double *))(*DNL_PPtr())->Cntr[63])(obj, count, buffer); }
static IArray *          FreqMeterCtrl_getChannels(FreqMeterCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[64])(obj);                        }

static FreqMeterCtrl*    FreqMeterCtrl_Create(void)                                                                                    { return (FreqMeterCtrl *)DaqCtrlBase_Create(SceFreqMeter); } 




static int32             OsChannel_getChannel(OsChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[65])(obj);                 }
static int8              OsChannel_getNoiseFiltered(OsChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[66])(obj);                  }
static ErrorCode         OsChannel_setNoiseFiltered(OsChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[67])(obj, value);           }
static int32             OsChannel_getDelayCount(OsChannel *obj)                                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[68])(obj);                 }
static ErrorCode         OsChannel_setDelayCount(OsChannel *obj, int32 value)                                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[69])(obj, value);          }
static SignalDrop        OsChannel_getClockSource(OsChannel *obj)                                                                      { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[70])(obj);            }
static ErrorCode         OsChannel_setClockSource(OsChannel *obj, SignalDrop value)                                                    { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[71])(obj, value);     }
static SignalPolarity    OsChannel_getClockPolarity(OsChannel *obj)                                                                    { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[72])(obj);        }
static ErrorCode         OsChannel_setClockPolarity(OsChannel *obj, SignalPolarity value)                                              { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[73])(obj, value); }
static SignalDrop        OsChannel_getGateSource(OsChannel *obj)                                                                       { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[74])(obj);            }
static ErrorCode         OsChannel_setGateSource(OsChannel *obj, SignalDrop value)                                                     { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[75])(obj, value);     }
static SignalPolarity    OsChannel_getGatePolarity(OsChannel *obj)                                                                     { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[76])(obj);        }
static ErrorCode         OsChannel_setGatePolarity(OsChannel *obj, SignalPolarity value)                                               { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[77])(obj, value); }
static OutSignalType     OsChannel_getOutSignal(OsChannel *obj)                                                                        { return ((OutSignalType ( *)(void *))(*DNL_PPtr())->Cntr[78])(obj);         }
static ErrorCode         OsChannel_setOutSignal(OsChannel *obj, OutSignalType value)                                                   { return ((ErrorCode ( *)(void *, OutSignalType))(*DNL_PPtr())->Cntr[79])(obj, value);  }

                                                                          
                                                                          
                                                                          
                                                                                                                                
static ErrorCode         OneShotCtrl_LoadProfile(OneShotCtrl *obj, wchar_t const *fileName)                                            { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              OneShotCtrl_Cleanup(OneShotCtrl *obj)                                                                         {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              OneShotCtrl_Dispose(OneShotCtrl *obj)                                                                         {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              OneShotCtrl_getSelectedDevice(OneShotCtrl *obj, DeviceInformation *x)                                         {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         OneShotCtrl_setSelectedDevice(OneShotCtrl *obj, DeviceInformation const *x)                                   { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      OneShotCtrl_getState(void *obj)                                                                               { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      OneShotCtrl_getDevice(OneShotCtrl *obj)                                                                       { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          OneShotCtrl_getSupportedDevices(OneShotCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          OneShotCtrl_getSupportedModes(OneShotCtrl *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                                   
static CntrFeatures *    OneShotCtrl_getFeatures(OneShotCtrl *obj)                                                                     { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             OneShotCtrl_getChannelStart(OneShotCtrl *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         OneShotCtrl_setChannelStart(OneShotCtrl *obj, int32 value)                                                    { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             OneShotCtrl_getChannelCount(OneShotCtrl *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         OneShotCtrl_setChannelCount(OneShotCtrl *obj, int32 value)                                                    { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              OneShotCtrl_getEnabled(OneShotCtrl *obj)                                                                      { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         OneShotCtrl_setEnabled(OneShotCtrl *obj, int8 enabled)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              OneShotCtrl_getRunning(OneShotCtrl *obj)                                                                      { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            OneShotCtrl_getNoiseFilterBlockTime(OneShotCtrl *obj)                                                         { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         OneShotCtrl_setNoiseFilterBlockTime(OneShotCtrl *obj, double value)                                           { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   OneShotCtrl_getNoiseFilter(OneShotCtrl *obj)                                                                  { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
                                                                                                                      
static IArray *          OneShotCtrl_getChannels(OneShotCtrl *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[80])(obj); }

static OneShotCtrl*      OneShotCtrl_Create(void)                                                                                      { return (OneShotCtrl *)DaqCtrlBase_Create(SceOneShot); } 


static void              OneShotCtrl_addOneShotHandler(OneShotCtrl *obj, CntrEventProc proc, void *userParam)                          { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntOneShot0, (DaqEventProc)proc, userParam);}
static void              OneShotCtrl_removeOneShotHandler(OneShotCtrl *obj, CntrEventProc proc, void *userParam)                       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntOneShot0, (DaqEventProc)proc, userParam);}




static int32             TmrChannel_getChannel(TmrChannel *obj)                                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[81])(obj);                 }
static int8              TmrChannel_getNoiseFiltered(TmrChannel *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[82])(obj);                  }
static ErrorCode         TmrChannel_setNoiseFiltered(TmrChannel *obj, int8 value)                                                      { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[83])(obj, value);           }
static double            TmrChannel_getFrequency(TmrChannel *obj)                                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[84])(obj);                }
static ErrorCode         TmrChannel_setFrequency(TmrChannel *obj, double value)                                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[85])(obj, value);         }
static int8              TmrChannel_getGated(TmrChannel *obj)                                                                          { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[86])(obj);                  }
static ErrorCode         TmrChannel_setGated(TmrChannel *obj, int8 value)                                                              { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[87])(obj, value);           }
static SignalPolarity    TmrChannel_getGatePolarity(TmrChannel *obj)                                                                   { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[88])(obj);        }
static ErrorCode         TmrChannel_setGatePolarity(TmrChannel *obj, SignalPolarity value)                                             { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[89])(obj, value); }
static OutSignalType     TmrChannel_getOutSignal(TmrChannel *obj)                                                                      { return ((OutSignalType ( *)(void *))(*DNL_PPtr())->Cntr[90])(obj);         }
static ErrorCode         TmrChannel_setOutSignal(TmrChannel *obj, OutSignalType value)                                                 { return ((ErrorCode ( *)(void *, OutSignalType))(*DNL_PPtr())->Cntr[91])(obj, value);  }

                                                                             
                                                                             
                                                                             
                                                                                                                                      
static ErrorCode         TimerPulseCtrl_LoadProfile(TimerPulseCtrl *obj, wchar_t const *fileName)                                      { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              TimerPulseCtrl_Cleanup(TimerPulseCtrl *obj)                                                                   {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              TimerPulseCtrl_Dispose(TimerPulseCtrl *obj)                                                                   {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              TimerPulseCtrl_getSelectedDevice(TimerPulseCtrl *obj, DeviceInformation *x)                                   {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         TimerPulseCtrl_setSelectedDevice(TimerPulseCtrl *obj, DeviceInformation const *x)                             { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      TimerPulseCtrl_getState(void *obj)                                                                            { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      TimerPulseCtrl_getDevice(TimerPulseCtrl *obj)                                                                 { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          TimerPulseCtrl_getSupportedDevices(TimerPulseCtrl *obj)                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          TimerPulseCtrl_getSupportedModes(TimerPulseCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                                   
static CntrFeatures *    TimerPulseCtrl_getFeatures(TimerPulseCtrl *obj)                                                               { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             TimerPulseCtrl_getChannelStart(TimerPulseCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         TimerPulseCtrl_setChannelStart(TimerPulseCtrl *obj, int32 value)                                              { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             TimerPulseCtrl_getChannelCount(TimerPulseCtrl *obj)                                                           { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         TimerPulseCtrl_setChannelCount(TimerPulseCtrl *obj, int32 value)                                              { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              TimerPulseCtrl_getEnabled(TimerPulseCtrl *obj)                                                                { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         TimerPulseCtrl_setEnabled(TimerPulseCtrl *obj, int8 enabled)                                                  { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              TimerPulseCtrl_getRunning(TimerPulseCtrl *obj)                                                                { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            TimerPulseCtrl_getNoiseFilterBlockTime(TimerPulseCtrl *obj)                                                   { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         TimerPulseCtrl_setNoiseFilterBlockTime(TimerPulseCtrl *obj, double value)                                     { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   TimerPulseCtrl_getNoiseFilter(TimerPulseCtrl *obj)                                                            { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
                                                                                                                   
static IArray *          TimerPulseCtrl_getChannels(TimerPulseCtrl *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[92])(obj);       }

static TimerPulseCtrl*   TimerPulseCtrl_Create(void)                                                                                   { return (TimerPulseCtrl *)DaqCtrlBase_Create(SceTimerPulse); } 


static void              TimerPulseCtrl_addTimerTickHandler(TimerPulseCtrl *obj, CntrEventProc proc, void *userParam)                  { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntTimer0, (DaqEventProc)proc, userParam); }
static void              TimerPulseCtrl_removeTimerTickHandler(TimerPulseCtrl *obj, CntrEventProc proc, void *userParam)               { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntTimer0, (DaqEventProc)proc, userParam); }

                                            

                                          
static int32             PiChannel_getChannel(PiChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[93])(obj);      }
static int8              PiChannel_getNoiseFiltered(PiChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[94])(obj);       }
static ErrorCode         PiChannel_setNoiseFiltered(PiChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[95])(obj, value);}

                                                                              
                                                                              
                                                                              
                                                                                                                                      
static ErrorCode         PwMeterCtrl_LoadProfile(PwMeterCtrl *obj, wchar_t const *fileName)                                            { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              PwMeterCtrl_Cleanup(PwMeterCtrl *obj)                                                                         {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              PwMeterCtrl_Dispose(PwMeterCtrl *obj)                                                                         {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              PwMeterCtrl_getSelectedDevice(PwMeterCtrl *obj, DeviceInformation *x)                                         {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         PwMeterCtrl_setSelectedDevice(PwMeterCtrl *obj, DeviceInformation const *x)                                   { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      PwMeterCtrl_getState(void *obj)                                                                               { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      PwMeterCtrl_getDevice(PwMeterCtrl *obj)                                                                       { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          PwMeterCtrl_getSupportedDevices(PwMeterCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          PwMeterCtrl_getSupportedModes(PwMeterCtrl *obj)                                                               { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                                     
static CntrFeatures *    PwMeterCtrl_getFeatures(PwMeterCtrl *obj)                                                                     { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             PwMeterCtrl_getChannelStart(PwMeterCtrl *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         PwMeterCtrl_setChannelStart(PwMeterCtrl *obj, int32 value)                                                    { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             PwMeterCtrl_getChannelCount(PwMeterCtrl *obj)                                                                 { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         PwMeterCtrl_setChannelCount(PwMeterCtrl *obj, int32 value)                                                    { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              PwMeterCtrl_getEnabled(PwMeterCtrl *obj)                                                                      { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         PwMeterCtrl_setEnabled(PwMeterCtrl *obj, int8 enabled)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              PwMeterCtrl_getRunning(PwMeterCtrl *obj)                                                                      { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            PwMeterCtrl_getNoiseFilterBlockTime(PwMeterCtrl *obj)                                                         { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         PwMeterCtrl_setNoiseFilterBlockTime(PwMeterCtrl *obj, double value)                                           { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   PwMeterCtrl_getNoiseFilter(PwMeterCtrl *obj)                                                                  { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
static double            PwMeterCtrl_getMeasurementTimeout(EventCounterCtrl *obj)                                                      { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[130])(obj);        }
static ErrorCode         PwMeterCtrl_setMeasurementTimeout(EventCounterCtrl *obj, double value)                                        { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[131])(obj, value); }
                                                                                                                     
static IArray *          PwMeterCtrl_getChannels(PwMeterCtrl *obj)                                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[96])(obj);                            }
static ErrorCode         PwMeterCtrl_Read(PwMeterCtrl *obj, int32 count, PulseWidth *buffer)                                           { return ((ErrorCode ( *)(void *, int32, PulseWidth *))(*DNL_PPtr())->Cntr[97])(obj, count, buffer); }

static PwMeterCtrl*      PwMeterCtrl_Create(void)                                                                                      { return (PwMeterCtrl *)DaqCtrlBase_Create(ScePwMeter); } 


static void              PwMeterCtrl_addOverflowHandler(PwMeterCtrl *obj, CntrEventProc proc, void *userParam)                         { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntPwmInOverflow0, (DaqEventProc)proc, userParam);}
static void              PwMeterCtrl_removeOverflowHandler(PwMeterCtrl *obj, CntrEventProc proc, void *userParam)                      { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntPwmInOverflow0, (DaqEventProc)proc, userParam);}   

                                                                              
                                                                              
                                                                              
                                                                                                                                      
static ErrorCode         BufferedPwMeterCtrl_LoadProfile(BufferedPwMeterCtrl *obj, wchar_t const *fileName)                           { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedPwMeterCtrl_Cleanup(BufferedPwMeterCtrl *obj)                                                        {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedPwMeterCtrl_Dispose(BufferedPwMeterCtrl *obj)                                                        {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedPwMeterCtrl_getSelectedDevice(BufferedPwMeterCtrl *obj, DeviceInformation *x)                        {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedPwMeterCtrl_setSelectedDevice(BufferedPwMeterCtrl *obj, DeviceInformation const *x)                  { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedPwMeterCtrl_getState(void *obj)                                                                      { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      BufferedPwMeterCtrl_getDevice(BufferedPwMeterCtrl *obj)                                                      { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          BufferedPwMeterCtrl_getSupportedDevices(BufferedPwMeterCtrl *obj)                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          BufferedPwMeterCtrl_getSupportedModes(BufferedPwMeterCtrl *obj)                                              { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                                     
static CntrFeatures *    BufferedPwMeterCtrl_getFeatures(BufferedPwMeterCtrl *obj)                                                    { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             BufferedPwMeterCtrl_getChannelStart(BufferedPwMeterCtrl *obj)                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         BufferedPwMeterCtrl_setChannelStart(BufferedPwMeterCtrl *obj, int32 value)                                   { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             BufferedPwMeterCtrl_getChannelCount(BufferedPwMeterCtrl *obj)                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         BufferedPwMeterCtrl_setChannelCount(BufferedPwMeterCtrl *obj, int32 value)                                   { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              BufferedPwMeterCtrl_getEnabled(BufferedPwMeterCtrl *obj)                                                     { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         BufferedPwMeterCtrl_setEnabled(BufferedPwMeterCtrl *obj, int8 enabled)                                       { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              BufferedPwMeterCtrl_getRunning(BufferedPwMeterCtrl *obj)                                                     { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            BufferedPwMeterCtrl_getNoiseFilterBlockTime(BufferedPwMeterCtrl *obj)                                        { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         BufferedPwMeterCtrl_setNoiseFilterBlockTime(BufferedPwMeterCtrl *obj, double value)                          { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   BufferedPwMeterCtrl_getNoiseFilter(BufferedPwMeterCtrl *obj)                                                 { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
static double            BufferedPwMeterCtrl_getMeasurementTimeout(EventCounterCtrl *obj)                                             { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[130])(obj);        }
static ErrorCode         BufferedPwMeterCtrl_setMeasurementTimeout(EventCounterCtrl *obj, double value)                               { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[131])(obj, value); }

     
static int32             BufferedPwMeterCtrl_getBufferCapacity(BufferedPwMeterCtrl *obj)                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[184])(obj);              }
static int8              BufferedPwMeterCtrl_getBufferStatus(BufferedPwMeterCtrl *obj, int32 ch, int32 *count, int32 *offset)         { return ((int8 ( *)(void *, int32, int32 *, int32 *))(*DNL_PPtr())->Cntr[189])(obj, ch, count, offset); }
static Trigger*          BufferedPwMeterCtrl_getTrigger(BufferedPwMeterCtrl *obj)                                                     { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Cntr[151])(obj, 0); }
static Record*           BufferedPwMeterCtrl_getRecord(BufferedPwMeterCtrl *obj)                                                      { return ((Record * ( *)(void *))(*DNL_PPtr())->Cntr[152])(obj);            }
static ErrorCode         BufferedPwMeterCtrl_setSampleClkSrc(BufferedPwMeterCtrl *obj, SignalDrop drop)                               { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[153])(obj, drop);    }
static SignalDrop        BufferedPwMeterCtrl_getSampleClkSrc(BufferedPwMeterCtrl *obj)                                                { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[154])(obj);          }
static void              BufferedPwMeterCtrl_getChannelMap(BufferedPwMeterCtrl *obj, int32 count, int8 *chMap)                        {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[149])(obj, count, chMap); }
static ErrorCode         BufferedPwMeterCtrl_setChannelMap(BufferedPwMeterCtrl *obj, int32 count, int8 *chMap)                        { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[150])(obj, count, chMap); }
static ErrorCode         BufferedPwMeterCtrl_Prepare(BufferedPwMeterCtrl *obj)                                                        { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Cntr[156])(obj);                      }
static void              BufferedPwMeterCtrl_Release(BufferedPwMeterCtrl *obj)                                                        {        ((void ( *)(void *))(*DNL_PPtr())->Cntr[157])(obj);                      }
static IArray *          BufferedPwMeterCtrl_getChannels(BufferedPwMeterCtrl *obj)                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[155])(obj);            }
static ErrorCode         BufferedPwMeterCtrl_GetData(BufferedPwMeterCtrl *obj, int32 cntr, int32 count, PulseWidth *buffer, int32 timeout, int32 *returned, double *startTime)
{
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void*, int32, int32*, double*);
   return ((FNGETDATA)(*DNL_PPtr())->Cntr[158])(obj, cntr, count, buffer, timeout, returned, startTime);
}


static BufferedPwMeterCtrl*      BufferedPwMeterCtrl_Create(void)                                                                     { return (BufferedPwMeterCtrl *)DaqCtrlBase_Create(SceBufferedPwMeter); } 


static void              BufferedPwMeterCtrl_addDataReadyHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)             { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_removeDataReadyHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)          { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_addOverrunHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_removeOverrunHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_addCacheOverflowHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)         { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_removeCacheOverflowHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)      { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_addStoppedHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}
static void              BufferedPwMeterCtrl_removeStoppedHandler(BufferedPwMeterCtrl *obj, BfdCntrEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}

                                                                              
                                                                              
                                                                       
static int32             PoChannel_getChannel(PoChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[98])(obj);                  }
static int8              PoChannel_getNoiseFiltered(PoChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[99])(obj);                   }
static ErrorCode         PoChannel_setNoiseFiltered(PoChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[100])(obj, value);           }
static void              PoChannel_getPulseWidth(PoChannel *obj, PulseWidth *x)                                                        {        ((void ( *)(void *, PulseWidth *))(*DNL_PPtr())->Cntr[101])(obj, x);       }
static ErrorCode         PoChannel_setPulseWidth(PoChannel *obj, PulseWidth const *x)                                                  { return ((ErrorCode ( *)(void *, PulseWidth const*))(*DNL_PPtr())->Cntr[102])(obj, x);  }
static int8              PoChannel_getGated(PoChannel *obj)                                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[103])(obj);                  }
static ErrorCode         PoChannel_setGated(PoChannel *obj, int8 value)                                                                { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[104])(obj, value);           }
static SignalPolarity    PoChannel_getGatePolarity(PoChannel *obj)                                                                     { return ((SignalPolarity ( *)(void *))(*DNL_PPtr())->Cntr[105])(obj);        }
static ErrorCode         PoChannel_setGatePolarity(PoChannel *obj, SignalPolarity value)                                               { return ((ErrorCode ( *)(void *, SignalPolarity))(*DNL_PPtr())->Cntr[106])(obj, value); }
static OutSignalType     PoChannel_getOutSignal(PoChannel *obj)                                                                        { return ((OutSignalType ( *)(void *))(*DNL_PPtr())->Cntr[107])(obj);         }
static ErrorCode         PoChannel_setOutSignal(PoChannel *obj, OutSignalType value)                                                   { return ((ErrorCode ( *)(void *, OutSignalType))(*DNL_PPtr())->Cntr[108])(obj, value);  }
static int32             PoChannel_getOutCount(PoChannel *obj)                                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[109])(obj);                 }
static ErrorCode         PoChannel_setOutCount(PoChannel *obj, int32 value)                                                            { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[110])(obj, value);          }

                                         

  
                                                                                                                                      
static ErrorCode         PwModulatorCtrl_LoadProfile(PwModulatorCtrl *obj, wchar_t const *fileName)                                    { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              PwModulatorCtrl_Cleanup(PwModulatorCtrl *obj)                                                                 {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              PwModulatorCtrl_Dispose(PwModulatorCtrl *obj)                                                                 {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              PwModulatorCtrl_getSelectedDevice(PwModulatorCtrl *obj, DeviceInformation *x)                                 {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         PwModulatorCtrl_setSelectedDevice(PwModulatorCtrl *obj, DeviceInformation const *x)                           { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      PwModulatorCtrl_getState(void *obj)                                                                           { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      PwModulatorCtrl_getDevice(PwModulatorCtrl *obj)                                                               { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          PwModulatorCtrl_getSupportedDevices(PwModulatorCtrl *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          PwModulatorCtrl_getSupportedModes(PwModulatorCtrl *obj)                                                       { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                            
static CntrFeatures *    PwModulatorCtrl_getFeatures(PwModulatorCtrl *obj)                                                             { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             PwModulatorCtrl_getChannelStart(PwModulatorCtrl *obj)                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         PwModulatorCtrl_setChannelStart(PwModulatorCtrl *obj, int32 value)                                            { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             PwModulatorCtrl_getChannelCount(PwModulatorCtrl *obj)                                                         { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         PwModulatorCtrl_setChannelCount(PwModulatorCtrl *obj, int32 value)                                            { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              PwModulatorCtrl_getEnabled(PwModulatorCtrl *obj)                                                              { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         PwModulatorCtrl_setEnabled(PwModulatorCtrl *obj, int8 enabled)                                                { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              PwModulatorCtrl_getRunning(PwModulatorCtrl *obj)                                                              { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            PwModulatorCtrl_getNoiseFilterBlockTime(PwModulatorCtrl *obj)                                                 { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         PwModulatorCtrl_setNoiseFilterBlockTime(PwModulatorCtrl *obj, double value)                                   { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   PwModulatorCtrl_getNoiseFilter(PwModulatorCtrl *obj)                                                          { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
                                                                   
static IArray *          PwModulatorCtrl_getChannels(PwModulatorCtrl *obj)                                                             { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[111])(obj); }

static PwModulatorCtrl*  PwModulatorCtrl_Create(void)                                                                                  { return (PwModulatorCtrl *)DaqCtrlBase_Create(ScePwModulator); } 

                                         

  
                                                                                                                                      
static ErrorCode         BufferedPwModulatorCtrl_LoadProfile(BufferedPwModulatorCtrl *obj, wchar_t const *fileName)                                  { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedPwModulatorCtrl_Cleanup(BufferedPwModulatorCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedPwModulatorCtrl_Dispose(BufferedPwModulatorCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedPwModulatorCtrl_getSelectedDevice(BufferedPwModulatorCtrl *obj, DeviceInformation *x)                               {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedPwModulatorCtrl_setSelectedDevice(BufferedPwModulatorCtrl *obj, DeviceInformation const *x)                         { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedPwModulatorCtrl_getState(void *obj)                                                                                 { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      BufferedPwModulatorCtrl_getDevice(BufferedPwModulatorCtrl *obj)                                                             { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          BufferedPwModulatorCtrl_getSupportedDevices(BufferedPwModulatorCtrl *obj)                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          BufferedPwModulatorCtrl_getSupportedModes(BufferedPwModulatorCtrl *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                            
static CntrFeatures *    BufferedPwModulatorCtrl_getFeatures(BufferedPwModulatorCtrl *obj)                                                           { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             BufferedPwModulatorCtrl_getChannelStart(BufferedPwModulatorCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         BufferedPwModulatorCtrl_setChannelStart(BufferedPwModulatorCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             BufferedPwModulatorCtrl_getChannelCount(BufferedPwModulatorCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         BufferedPwModulatorCtrl_setChannelCount(BufferedPwModulatorCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              BufferedPwModulatorCtrl_getEnabled(BufferedPwModulatorCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         BufferedPwModulatorCtrl_setEnabled(BufferedPwModulatorCtrl *obj, int8 enabled)                                              { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              BufferedPwModulatorCtrl_getRunning(BufferedPwModulatorCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            BufferedPwModulatorCtrl_getNoiseFilterBlockTime(BufferedPwModulatorCtrl *obj)                                               { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         BufferedPwModulatorCtrl_setNoiseFilterBlockTime(BufferedPwModulatorCtrl *obj, double value)                                 { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   BufferedPwModulatorCtrl_getNoiseFilter(BufferedPwModulatorCtrl *obj)                                                        { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}

 
static int32             BufferedPwModulatorCtrl_getBufferCapacity(BufferedPwModulatorCtrl *obj)                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[186])(obj);              }
static int8              BufferedPwModulatorCtrl_getBufferStatus(BufferedPwModulatorCtrl *obj, int32 ch, int32 *count, int32 *offset)                { return ((int8 ( *)(void *, int32, int32 *, int32 *))(*DNL_PPtr())->Cntr[191])(obj, ch, count, offset); }
static Trigger*          BufferedPwModulatorCtrl_getTrigger(BufferedPwModulatorCtrl *obj)                                                            { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Cntr[171])(obj, 0); }
static int32             BufferedPwModulatorCtrl_getSamples(BufferedPwModulatorCtrl *obj)                                                            { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[172])(obj);               } 
static ErrorCode         BufferedPwModulatorCtrl_setSamples(BufferedPwModulatorCtrl *obj, int32 value)                                               { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[173])(obj, value);        }
static int32             BufferedPwModulatorCtrl_getIntervalCount(BufferedPwModulatorCtrl *obj)                                                      { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[174])(obj);               }
static ErrorCode         BufferedPwModulatorCtrl_setIntervalCount(BufferedPwModulatorCtrl *obj, int32 value)                                         { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[175])(obj, value);        }
static int8              BufferedPwModulatorCtrl_getStreaming(BufferedPwModulatorCtrl *obj)                                                          { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[187])(obj);                }
static ErrorCode         BufferedPwModulatorCtrl_setStreaming(BufferedPwModulatorCtrl *obj, int8 value)                                              { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[176])(obj, value);         }

static ErrorCode         BufferedPwModulatorCtrl_setSampleClkSrc(BufferedPwModulatorCtrl *obj, SignalDrop drop)                                      { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[177])(obj, drop);    }
static SignalDrop        BufferedPwModulatorCtrl_getSampleClkSrc(BufferedPwModulatorCtrl *obj)                                                       { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[178])(obj);          }
static void              BufferedPwModulatorCtrl_getChannelMap(BufferedPwModulatorCtrl *obj, int32 count, int8 *chMap)                               {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[169])(obj, count, chMap); }
static ErrorCode         BufferedPwModulatorCtrl_setChannelMap(BufferedPwModulatorCtrl *obj, int32 count, int8 *chMap)                               { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[170])(obj, count, chMap); }
static ErrorCode         BufferedPwModulatorCtrl_Prepare(BufferedPwModulatorCtrl *obj)                                                               { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Cntr[180])(obj);                      }
static void              BufferedPwModulatorCtrl_Release(BufferedPwModulatorCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Cntr[181])(obj);                      }
static IArray *          BufferedPwModulatorCtrl_getChannels(BufferedPwModulatorCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[179])(obj);            }
static ErrorCode         BufferedPwModulatorCtrl_SetData(BufferedPwModulatorCtrl *obj, int32 cntr, int32 count, PulseWidth *buffer)
{
   typedef ErrorCode ( *FNSETDATA)(void *, int32, int32, void*);
   return ((FNSETDATA)(*DNL_PPtr())->Cntr[182])(obj, cntr, count, buffer);
}


static BufferedPwModulatorCtrl*  BufferedPwModulatorCtrl_Create(void)                                                                                { return (BufferedPwModulatorCtrl *)DaqCtrlBase_Create(SceBufferedPwModulator); } 



static void              BufferedPwModulatorCtrl_addDataTransmittedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)             { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_removeDataTransmittedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)          { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCoDataTransmitted, (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_addUnderrunHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)                    { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_removeUnderrunHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)                 { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCoUnderrun,        (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_addCacheEmptiedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)                { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_removeCacheEmptiedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)             { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCoCacheEmptied,    (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_addTransitStoppedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)              { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_removeTransitStoppedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)           { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCoTransStopped,    (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_addStoppedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntrStopped,       (DaqEventProc)proc, userParam); }
static void              BufferedPwModulatorCtrl_removeStoppedHandler(BufferedPwModulatorCtrl *obj, BfdCntrEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntrStopped,       (DaqEventProc)proc, userParam); }




static int32             UdChannel_getChannel(UdChannel *obj)                                                                          { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[112])(obj);              }
static int8              UdChannel_getNoiseFiltered(UdChannel *obj)                                                                    { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[113])(obj);               }
static ErrorCode         UdChannel_setNoiseFiltered(UdChannel *obj, int8 value)                                                        { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[114])(obj, value);        }
static CountingType      UdChannel_getCountingType(UdChannel *obj)                                                                     { return ((CountingType ( *)(void *))(*DNL_PPtr())->Cntr[115])(obj);       }
static ErrorCode         UdChannel_setCountingType(UdChannel *obj, CountingType value)                                                 { return ((ErrorCode ( *)(void *, CountingType))(*DNL_PPtr())->Cntr[116])(obj, value);}
static int32             UdChannel_getInitialValue(UdChannel *obj)                                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[117])(obj);              }
static ErrorCode         UdChannel_setInitialValue(UdChannel *obj, int32 value)                                                        { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[118])(obj, value);       }
static int32             UdChannel_getResetTimesByIndex(UdChannel *obj)                                                                { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[119])(obj);              }
static ErrorCode         UdChannel_setResetTimesByIndex(UdChannel *obj, int32 value)                                                   { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[120])(obj, value);       }




                                                                                                                               
static ErrorCode         UdCounterCtrl_LoadProfile(UdCounterCtrl *obj, wchar_t const *fileName)                                        { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              UdCounterCtrl_Cleanup(UdCounterCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              UdCounterCtrl_Dispose(UdCounterCtrl *obj)                                                                     {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              UdCounterCtrl_getSelectedDevice(UdCounterCtrl *obj, DeviceInformation *x)                                     {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         UdCounterCtrl_setSelectedDevice(UdCounterCtrl *obj, DeviceInformation const *x)                               { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      UdCounterCtrl_getState(void *obj)                                                                             { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      UdCounterCtrl_getDevice(UdCounterCtrl *obj)                                                                   { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          UdCounterCtrl_getSupportedDevices(UdCounterCtrl *obj)                                                         { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          UdCounterCtrl_getSupportedModes(UdCounterCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                              
static CntrFeatures *    UdCounterCtrl_getFeatures(UdCounterCtrl *obj)                                                                 { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             UdCounterCtrl_getChannelStart(UdCounterCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         UdCounterCtrl_setChannelStart(UdCounterCtrl *obj, int32 value)                                                { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             UdCounterCtrl_getChannelCount(UdCounterCtrl *obj)                                                             { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         UdCounterCtrl_setChannelCount(UdCounterCtrl *obj, int32 value)                                                { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              UdCounterCtrl_getEnabled(UdCounterCtrl *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         UdCounterCtrl_setEnabled(UdCounterCtrl *obj, int8 enabled)                                                    { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              UdCounterCtrl_getRunning(UdCounterCtrl *obj)                                                                  { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            UdCounterCtrl_getNoiseFilterBlockTime(UdCounterCtrl *obj)                                                     { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         UdCounterCtrl_setNoiseFilterBlockTime(UdCounterCtrl *obj, double value)                                       { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   UdCounterCtrl_getNoiseFilter(UdCounterCtrl *obj)                                                              { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}

static ErrorCode         UdCounterCtrl_SnapStart(UdCounterCtrl *obj, EventId srcId)                                                    { return ((ErrorCode ( *)(void *, EventId))(*DNL_PPtr())->Cntr[121])(obj, srcId);                                 }
static ErrorCode         UdCounterCtrl_SnapStop(UdCounterCtrl *obj, EventId srcId)                                                     { return ((ErrorCode ( *)(void *, EventId))(*DNL_PPtr())->Cntr[122])(obj, srcId);                                 }
static ErrorCode         UdCounterCtrl_CompareSetTable(UdCounterCtrl *obj, int32 channel, int32 count, int32 *table)                   { return ((ErrorCode ( *)(void *, int32, int32, int32 *))(*DNL_PPtr())->Cntr[123])(obj, channel, count, table); }
static ErrorCode         UdCounterCtrl_CompareSetInterval(UdCounterCtrl *obj, int32 channel, int32 start, int32 increment,int32 count) { return ((ErrorCode ( *)(void *, int32, int32, int32, int32))(*DNL_PPtr())->Cntr[124])(obj, channel, start, increment, count); }
static ErrorCode         UdCounterCtrl_CompareClear(UdCounterCtrl *obj, int32 channel)                                                 { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[125])(obj, channel);                 }
static ErrorCode         UdCounterCtrl_ValueReset(UdCounterCtrl *obj)                                                                  { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Cntr[126])(obj);                                 }
static ErrorCode         UdCounterCtrl_Read(UdCounterCtrl *obj, int32 count, int32 *buffer)                                            { return ((ErrorCode ( *)(void *, int32, int32 *))(*DNL_PPtr())->Cntr[127])(obj, count, buffer); }
static IArray *          UdCounterCtrl_getChannels(UdCounterCtrl *obj)                                                                 { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[128])(obj);                       }

static UdCounterCtrl*    UdCounterCtrl_Create(void)                                                                                    { return (UdCounterCtrl *)DaqCtrlBase_Create(SceUdCounter); } 


static void              UdCounterCtrl_addUdCntrEventHandler(UdCounterCtrl *obj, UdCntrEventProc proc, void *userParam)                { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtUdIndex0, (DaqEventProc)proc, userParam);}
static void              UdCounterCtrl_removeUdCntrEventHandler(UdCounterCtrl *obj, UdCntrEventProc proc, void *userParam)             { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtUdIndex0, (DaqEventProc)proc, userParam);}




                                                                                                                               
static ErrorCode         BufferedUdCounterCtrl_LoadProfile(BufferedUdCounterCtrl *obj, wchar_t const *fileName)                                  { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void              BufferedUdCounterCtrl_Cleanup(BufferedUdCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void              BufferedUdCounterCtrl_Dispose(BufferedUdCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void              BufferedUdCounterCtrl_getSelectedDevice(BufferedUdCounterCtrl *obj, DeviceInformation *x)                               {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode         BufferedUdCounterCtrl_setSelectedDevice(BufferedUdCounterCtrl *obj, DeviceInformation const *x)                         { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState      BufferedUdCounterCtrl_getState(void *obj)                                                                               { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *      BufferedUdCounterCtrl_getDevice(BufferedUdCounterCtrl *obj)                                                             { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *          BufferedUdCounterCtrl_getSupportedDevices(BufferedUdCounterCtrl *obj)                                                   { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *          BufferedUdCounterCtrl_getSupportedModes(BufferedUdCounterCtrl *obj)                                                     { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                                              
static CntrFeatures *    BufferedUdCounterCtrl_getFeatures(BufferedUdCounterCtrl *obj)                                                           { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32             BufferedUdCounterCtrl_getChannelStart(BufferedUdCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode         BufferedUdCounterCtrl_setChannelStart(BufferedUdCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32             BufferedUdCounterCtrl_getChannelCount(BufferedUdCounterCtrl *obj)                                                       { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode         BufferedUdCounterCtrl_setChannelCount(BufferedUdCounterCtrl *obj, int32 value)                                          { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8              BufferedUdCounterCtrl_getEnabled(BufferedUdCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode         BufferedUdCounterCtrl_setEnabled(BufferedUdCounterCtrl *obj, int8 enabled)                                              { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8              BufferedUdCounterCtrl_getRunning(BufferedUdCounterCtrl *obj)                                                            { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double            BufferedUdCounterCtrl_getNoiseFilterBlockTime(BufferedUdCounterCtrl *obj)                                               { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode         BufferedUdCounterCtrl_setNoiseFilterBlockTime(BufferedUdCounterCtrl *obj, double value)                                 { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *   BufferedUdCounterCtrl_getNoiseFilter(BufferedUdCounterCtrl *obj)                                                        { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}

static int32             BufferedUdCounterCtrl_getBufferCapacity(BufferedUdCounterCtrl *obj)                                                     { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[185])(obj);              }
static int8              BufferedUdCounterCtrl_getBufferStatus(BufferedUdCounterCtrl *obj, int32 ch, int32 *count, int32 *offset)                { return ((int8 ( *)(void *, int32, int32 *, int32 *))(*DNL_PPtr())->Cntr[190])(obj, ch, count, offset); }  
static Trigger*          BufferedUdCounterCtrl_getTrigger(BufferedUdCounterCtrl *obj)                                                            { return ((Trigger * ( *)(void *, int32))(*DNL_PPtr())->Cntr[161])(obj, 0); }
static Record*           BufferedUdCounterCtrl_getRecord(BufferedUdCounterCtrl *obj)                                                             { return ((Record * ( *)(void *))(*DNL_PPtr())->Cntr[162])(obj);            }
static ErrorCode         BufferedUdCounterCtrl_setSampleClkSrc(BufferedUdCounterCtrl *obj, SignalDrop drop)                                      { return ((ErrorCode ( *)(void *, SignalDrop))(*DNL_PPtr())->Cntr[163])(obj, drop);    }
static SignalDrop        BufferedUdCounterCtrl_getSampleClkSrc(BufferedUdCounterCtrl *obj)                                                       { return ((SignalDrop ( *)(void *))(*DNL_PPtr())->Cntr[164])(obj);          }
static void              BufferedUdCounterCtrl_getChannelMap(BufferedUdCounterCtrl *obj, int32 count, int8 *chMap)                               {        ((void ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[159])(obj, count, chMap); }
static ErrorCode         BufferedUdCounterCtrl_setChannelMap(BufferedUdCounterCtrl *obj, int32 count, int8 *chMap)                               { return ((ErrorCode ( *)(void *, int32, int8 *))(*DNL_PPtr())->Cntr[160])(obj, count, chMap); }
static ErrorCode         BufferedUdCounterCtrl_Prepare(BufferedUdCounterCtrl *obj)                                                               { return ((ErrorCode ( *)(void *))(*DNL_PPtr())->Cntr[166])(obj);                      }
static void              BufferedUdCounterCtrl_Release(BufferedUdCounterCtrl *obj)                                                               {        ((void ( *)(void *))(*DNL_PPtr())->Cntr[167])(obj);                      }
static IArray *          BufferedUdCounterCtrl_getChannels(BufferedUdCounterCtrl *obj)                                                           { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[165])(obj);            }
static ErrorCode         BufferedUdCounterCtrl_GetDataI32(BufferedUdCounterCtrl *obj, int32 cntr, int32 count, int32 dataBuf[], int32 timeout, int32 *returned, double *startTime)
{
   typedef ErrorCode ( *FNGETDATA)(void *, int32, int32, void*, int32, int32*, double*);
   return ((FNGETDATA)(*DNL_PPtr())->Cntr[168])(obj, cntr, count, dataBuf, timeout, returned, startTime);
}


static BufferedUdCounterCtrl*    BufferedUdCounterCtrl_Create(void)                                                                              { return (BufferedUdCounterCtrl *)DaqCtrlBase_Create(SceBufferedUdCounter); } 


static void              BufferedUdCounterCtrl_addDataReadyHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                   { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_removeDataReadyHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiDataReady,     (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_addOverrunHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_removeOverrunHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiOverrun,       (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_addCacheOverflowHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)               { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_removeCacheOverflowHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)            { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCiCacheOverflow, (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_addStoppedHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                     { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}
static void              BufferedUdCounterCtrl_removeStoppedHandler(BufferedUdCounterCtrl *obj, BfdCntrEventProc proc, void *userParam)                  { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, EvtCntrStopped,     (DaqEventProc)proc, userParam);}




static int32             EsChannel_getChannel(EsChannel *obj)                                                                              { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[192])(obj);              }
static int8              EsChannel_getNoiseFiltered(EsChannel *obj)                                                                        { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[193])(obj);               }
static ErrorCode         EsChannel_setNoiseFiltered(EsChannel *obj, int8 value)                                                            { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[194])(obj, value);        }
static ActiveSignal      EsChannel_getStartCountingEdge(EsChannel *obj)                                                                    { return ((ActiveSignal ( *)(void *))(*DNL_PPtr())->Cntr[195])(obj);       }
static ErrorCode         EsChannel_setStartCountingEdge(EsChannel *obj, ActiveSignal value)                                                { return ((ErrorCode ( *)(void *, ActiveSignal))(*DNL_PPtr())->Cntr[196])(obj, value);}
static ActiveSignal      EsChannel_getStopCountingEdge(EsChannel *obj)                                                                     { return ((ActiveSignal ( *)(void *))(*DNL_PPtr())->Cntr[197])(obj);       }
static ErrorCode         EsChannel_setStopCountingEdge(EsChannel *obj, ActiveSignal value)                                                 { return ((ErrorCode ( *)(void *, ActiveSignal))(*DNL_PPtr())->Cntr[198])(obj, value);}

                                        

   

static ErrorCode              EdgeSeparationCtrl_LoadProfile(EdgeSeparationCtrl *obj, wchar_t const *fileName)                                   { return ((ErrorCode ( *)(void *, wchar_t const *))(*DNL_PPtr())->Base[98])(obj, fileName);   }  
static void                   EdgeSeparationCtrl_Cleanup(EdgeSeparationCtrl *obj)                                                                {        ((void ( *)(void *))(*DNL_PPtr())->Base[83])(obj);                              }
static void                   EdgeSeparationCtrl_Dispose(EdgeSeparationCtrl *obj)                                                                {        ((void ( *)(void *))(*DNL_PPtr())->Base[84])(obj);                              }
static void                   EdgeSeparationCtrl_getSelectedDevice(EdgeSeparationCtrl *obj, DeviceInformation *x)                                {        ((void ( *)(void *, DeviceInformation*))(*DNL_PPtr())->Base[85])(obj, x);       }
static ErrorCode              EdgeSeparationCtrl_setSelectedDevice(EdgeSeparationCtrl *obj, DeviceInformation const *x)                          { return ((ErrorCode ( *)(void *, DeviceInformation const*))(*DNL_PPtr())->Base[86])(obj, x); }
static ControlState           EdgeSeparationCtrl_getState(void *obj)                                                                             { return ((ControlState ( *)(void *))(*DNL_PPtr())->Base[87])(obj);   }
static DeviceCtrl *           EdgeSeparationCtrl_getDevice(EdgeSeparationCtrl *obj)                                                              { return ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);   }
static IArray *               EdgeSeparationCtrl_getSupportedDevices(EdgeSeparationCtrl *obj)                                                    { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[89])(obj);       }
static IArray *               EdgeSeparationCtrl_getSupportedModes(EdgeSeparationCtrl *obj)                                                      { return ((IArray * ( *)(void *))(*DNL_PPtr())->Base[90])(obj);       }
                                                                                                        
static CntrFeatures *         EdgeSeparationCtrl_getFeatures(EdgeSeparationCtrl *obj)                                                            { return ((CntrFeatures * ( *)(void *))(*DNL_PPtr())->Cntr[34])(obj); }
static int32                  EdgeSeparationCtrl_getChannelStart(EdgeSeparationCtrl *obj)                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);          }
static ErrorCode              EdgeSeparationCtrl_setChannelStart(EdgeSeparationCtrl *obj, int32 value)                                           { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, value);   }
static int32                  EdgeSeparationCtrl_getChannelCount(EdgeSeparationCtrl *obj)                                                        { return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[37])(obj);          }
static ErrorCode              EdgeSeparationCtrl_setChannelCount(EdgeSeparationCtrl *obj, int32 value)                                           { return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, value);   }
static int8                   EdgeSeparationCtrl_getEnabled(EdgeSeparationCtrl *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[39])(obj);           }
static ErrorCode              EdgeSeparationCtrl_setEnabled(EdgeSeparationCtrl *obj, int8 enabled)                                               { return ((ErrorCode ( *)(void *, int8))(*DNL_PPtr())->Cntr[40])(obj, enabled);  }
static int8                   EdgeSeparationCtrl_getRunning(EdgeSeparationCtrl *obj)                                                             { return ((int8 ( *)(void *))(*DNL_PPtr())->Cntr[41])(obj);           }
static double                 EdgeSeparationCtrl_getNoiseFilterBlockTime(EdgeSeparationCtrl *obj)                                                { return ((double ( *)(void *))(*DNL_PPtr())->Cntr[42])(obj);         }
static ErrorCode              EdgeSeparationCtrl_setNoiseFilterBlockTime(EdgeSeparationCtrl *obj, double value)                                  { return ((ErrorCode ( *)(void *, double))(*DNL_PPtr())->Cntr[43])(obj, value);  }
static NosFltChannel *        EdgeSeparationCtrl_getNoiseFilter_getNoiseFilter(EdgeSeparationCtrl *obj)                                          { return ((NosFltChannel * ( *)(void *))(*DNL_PPtr())->Cntr[44])(obj);}
                                                                                    
static ErrorCode              EdgeSeparationCtrl_Read(EdgeSeparationCtrl *obj, int32 count, double *buffer)                                      { return ((ErrorCode ( *)(void *, int32, double *))(*DNL_PPtr())->Cntr[199])(obj, count, buffer); }
static IArray *               EdgeSeparationCtrl_getChannels(EdgeSeparationCtrl *obj)                                                            { return ((IArray * ( *)(void *))(*DNL_PPtr())->Cntr[200])(obj);                        }

static EdgeSeparationCtrl*    EdgeSeparationCtrl_Create(void)                                                                                    { return (EdgeSeparationCtrl *)DaqCtrlBase_Create(SceEdgeSeparation);     } 






   typedef IArray        ICollection;
   typedef ICounterIndexer  CounterCapabilityIndexer;
   typedef AiChannel     AnalogInputChannel;
   typedef AoChannel     AnalogChannel;
   typedef NosFltChannel NoiseFilterChannel;
   typedef DioFeatures   DiFeatures;
   typedef DioFeatures   DoFeatures;
   typedef CntrFeatures  EventCounterFeatures;
   typedef CntrFeatures  FreqMeterFeatures;
   typedef CntrFeatures  OneShotFeatures;
   typedef CntrFeatures  TimerPulseFeatures;
   typedef CntrFeatures  PwMeterFeatures;
   typedef CntrFeatures  PwModulatorFeatures;
   typedef CntrFeatures  UdCounterFeatures;

   typedef struct DeviceEventHandler {
      void ( *DeviceEvent)(void *obj, void *sender, DeviceEventArgs *args);
   } DeviceEventHandler;
   typedef struct DeviceEventListener {
      DeviceEventHandler const *vtbl;
   }DeviceEventListener;

   typedef struct BfdAiEventHandler {
      void ( *BfdAiEvent)(void *obj, void *sender, BfdAiEventArgs *args);
   } BfdAiEventHandler;
   typedef struct BfdAiEventListener {
      BfdAiEventHandler const *vtbl;
   } BfdAiEventListener;

   typedef struct BfdAoEventHandler {
      void ( *BfdAoEvent)(void *obj, void *sender, BfdAoEventArgs *args);
   } BfdAoEventHandler;
   typedef struct BfdAoEventListener {
      BfdAoEventHandler const *vtbl;
   } BfdAoEventListener;

   typedef struct DiSnapEventHandler {
      void ( *DiSnapEvent)(void *obj, void *sender, DiSnapEventArgs *args);
   } DiSnapEventHandler;
   typedef struct DiSnapEventListener {
      DiSnapEventHandler const *vtbl;
   } DiSnapEventListener;

   typedef struct CntrEventHandler {
      void ( *CntrEvent)(void *obj, void *sender, CntrEventArgs *args);
   } CntrEventHandler;
   typedef struct CntrEventListener {
      CntrEventHandler const *vtbl;
   } CntrEventListener;

   typedef struct UdCntrEventHandler {
      void ( *UdCntrEvent)(void *obj, void *sender, UdCntrEventArgs *args);
   } UdCntrEventHandler;
   typedef struct UdCntrEventListener {
      UdCntrEventHandler const *vtbl;
   } UdCntrEventListener;

   static void  xxxCtrl_OnDeviceEvent(void *sender, DeviceEventArgs *args, void *userParam)
   {
      ((DeviceEventListener *)userParam)->vtbl->DeviceEvent(userParam, sender, args);
   }
   static void  xxxCtrl_OnBfdAiEvent(void *sender, BfdAiEventArgs *args, void *userParam)
   {
      ((BfdAiEventListener *)userParam)->vtbl->BfdAiEvent(userParam, sender, args);
   }
   static void  xxxCtrl_OnBfdAoEvent(void *sender, BfdAoEventArgs *args, void *userParam)
   {
      ((BfdAoEventListener *)userParam)->vtbl->BfdAoEvent(userParam, sender, args);
   }
   static void  xxxCtrl_OnDiSnapEvent(void *sender, DiSnapEventArgs *args, void *userParam)
   {
      ((DiSnapEventListener *)userParam)->vtbl->DiSnapEvent(userParam, sender, args);
   }
   static void  xxxCtrl_OnCntrEvent(void *sender, CntrEventArgs *args, void *userParam)
   {
      ((CntrEventListener *)userParam)->vtbl->CntrEvent(userParam, sender, args);
   }
   static void  xxxCtrl_OnUdCntrEvent(void *sender, UdCntrEventArgs *args, void *userParam)
   {
      ((UdCntrEventListener *)userParam)->vtbl->UdCntrEvent(userParam, sender, args);
   }
























































#line 3612 "bdaqctrlTest.h"




static void xxxCtrl_addDeviceEventListener   (void *obj, EventId id, DeviceEventListener *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnDeviceEvent, listener); }
static void xxxCtrl_removeDeviceEventListener(void *obj, EventId id, DeviceEventListener *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnDeviceEvent, listener); }
static void xxxCtrl_addBfdAiEventListener    (void *obj, EventId id, BfdAiEventListener  *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnBfdAiEvent,  listener); }
static void xxxCtrl_removeBfdAiEventListener (void *obj, EventId id, BfdAiEventListener  *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnBfdAiEvent,  listener); }
static void xxxCtrl_addBfdAoEventListener    (void *obj, EventId id, BfdAoEventListener  *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnBfdAoEvent,  listener); }
static void xxxCtrl_removeBfdAoEventListener (void *obj, EventId id, BfdAoEventListener  *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnBfdAoEvent,  listener); }
static void xxxCtrl_addDiSnapEventListener   (void *obj, EventId id, DiSnapEventListener *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnDiSnapEvent, listener); }
static void xxxCtrl_removeDiSnapEventListener(void *obj, EventId id, DiSnapEventListener *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnDiSnapEvent, listener); }
static void xxxCtrl_addCntrEventListener     (void *obj, EventId id, CntrEventListener   *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnCntrEvent,   listener); }
static void xxxCtrl_removeCntrEventListener  (void *obj, EventId id, CntrEventListener   *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnCntrEvent,   listener); }
static void xxxCtrl_addUdCntrEventListener   (void *obj, EventId id, UdCntrEventListener *listener)       { DaqCtrlBase_addEventHandler   ((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnUdCntrEvent, listener); }
static void xxxCtrl_removeUdCntrEventListener(void *obj, EventId id, UdCntrEventListener *listener)       { DaqCtrlBase_removeEventHandler((DaqCtrlBase*)obj, id, (DaqEventProc)xxxCtrl_OnUdCntrEvent, listener); }

static ErrorCode xxxCtrl_UpdateProperties(void *obj)
{
   DeviceCtrl *dev = ((DeviceCtrl * ( *)(void *))(*DNL_PPtr())->Base[88])(obj);
   return dev ? DeviceCtrl_Refresh(dev) : ErrorFuncNotInited;
}

static int32 xxxCntrCtrl_getChannel(void *obj) 
{
   return ((int32 ( *)(void *))(*DNL_PPtr())->Cntr[35])(obj);
}
static int32 xxxCntrCtrl_setChannel(void *obj, int32 ch)
{
   ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[38])(obj, 1); 
   return ((ErrorCode ( *)(void *, int32))(*DNL_PPtr())->Cntr[36])(obj, ch); 
}

static int32 EventCounterCtrl_getValue(EventCounterCtrl *obj)
{
   int32 value = 0; 
   EventCounterCtrl_Read(obj, 1, &value); 
   return value;
}

static FmChannel * FreqMeterCtrl_getCHPtr(FreqMeterCtrl *obj)
{
   IArray *chs = FreqMeterCtrl_getChannels(obj);
   return chs ? (FmChannel *)Array_getItem(chs, xxxCntrCtrl_getChannel(obj)) : NULL;
}
static FreqMeasureMethod FreqMeterCtrl_getMethod(FreqMeterCtrl *obj)  
{
   FmChannel *ch = FreqMeterCtrl_getCHPtr(obj);
   return ch ? FmChannel_getFmMethod(ch) : AutoAdaptive;
}
static ErrorCode FreqMeterCtrl_setMethod(FreqMeterCtrl *obj, FreqMeasureMethod value) 
{
   FmChannel *ch = FreqMeterCtrl_getCHPtr(obj);
   return ch ? FmChannel_setFmMethod(ch, value) : ErrorFuncNotInited;
}
static double FreqMeterCtrl_getCollectionPeriod(FreqMeterCtrl *obj)
{
   FmChannel *ch = FreqMeterCtrl_getCHPtr(obj);
   return ch ? FmChannel_getCollectionPeriod(ch) : 0;
}
static ErrorCode FreqMeterCtrl_setCollectionPeriod(FreqMeterCtrl *obj, double value)  
{
   FmChannel *ch = FreqMeterCtrl_getCHPtr(obj);
   return ch ? FmChannel_setCollectionPeriod(ch, value) : ErrorFuncNotInited;
}
static double FreqMeterCtrl_getValue(FreqMeterCtrl *obj)
{
   double value = 0.0;
   FreqMeterCtrl_Read(obj, 1, &value);
   return value;
}

static OsChannel * OneShotCtrl_getCHPtr(OneShotCtrl *obj)
{
   IArray *chs = OneShotCtrl_getChannels(obj);
   return chs ? (OsChannel *)Array_getItem(chs, xxxCntrCtrl_getChannel(obj)) : NULL;
}
static int32 OneShotCtrl_getDelayCount(OneShotCtrl *obj) 
{
   OsChannel *ch = OneShotCtrl_getCHPtr(obj);
   return ch ? OsChannel_getDelayCount(ch) : 0;
}
static ErrorCode OneShotCtrl_setDelayCount(OneShotCtrl *obj, int32 value)
{
   OsChannel *ch = OneShotCtrl_getCHPtr(obj);
   return ch ? OsChannel_setDelayCount(ch, value) : ErrorFuncNotInited;
}

static TmrChannel * TimerPulseCtrl_getCHPtr(TimerPulseCtrl *obj)
{
   IArray *chs = TimerPulseCtrl_getChannels(obj);
   return chs ? (TmrChannel *)Array_getItem(chs, xxxCntrCtrl_getChannel(obj)) : NULL;
}
static double TimerPulseCtrl_getFrequency(TimerPulseCtrl *obj)
{
   TmrChannel *ch = TimerPulseCtrl_getCHPtr(obj);
   return ch ? TmrChannel_getFrequency(ch) : 0;
}
static ErrorCode TimerPulseCtrl_setFrequency(TimerPulseCtrl *obj, double value)
{
   TmrChannel *ch = TimerPulseCtrl_getCHPtr(obj);
   return ch ? TmrChannel_setFrequency(ch, value) : ErrorFuncNotInited;
}

static void PwMeterCtrl_getValue(PwMeterCtrl *obj, PulseWidth *width)
{
   PwMeterCtrl_Read(obj, 1, width);
}

static PoChannel * PwModulatorCtrl_getCHPtr(PwModulatorCtrl *obj)
{
   IArray *chs = PwModulatorCtrl_getChannels(obj);
   return chs ? (PoChannel *)Array_getItem(chs, xxxCntrCtrl_getChannel(obj)) : NULL;
}
static void PwModulatorCtrl_getPulseWidth(PwModulatorCtrl *obj, PulseWidth *width)
{
   PoChannel *ch = PwModulatorCtrl_getCHPtr(obj);
   if (ch) { PoChannel_getPulseWidth(ch, width);      }
   else    { width->HiPeriod = width->LoPeriod = 0.0; }
}
static ErrorCode PwModulatorCtrl_setPulseWidth(PwModulatorCtrl *obj, PulseWidth const *width) 
{
   PoChannel *ch = PwModulatorCtrl_getCHPtr(obj);
   return ch ? PoChannel_setPulseWidth(ch, width) : ErrorFuncNotInited;
}

static UdChannel * UdCounterCtrl_getCHPtr(UdCounterCtrl *obj)
{
   int32 ch = xxxCntrCtrl_getChannel(obj);
   IArray *chs = UdCounterCtrl_getChannels(obj);
   
   if (ch < 0) { return NULL; }
   return chs ? (UdChannel *)Array_getItem(chs, ch) : NULL;
}
static SignalCountingType  UdCounterCtrl_getCountingType(UdCounterCtrl *obj)
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_getCountingType(ch) : CountingNone;
}
static ErrorCode UdCounterCtrl_setCountingType(UdCounterCtrl *obj, SignalCountingType value) 
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_setCountingType(ch, value) : ErrorFuncNotInited;
}
static int32 UdCounterCtrl_getInitialValue(UdCounterCtrl *obj)
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_getInitialValue(ch) : 0;
}
static ErrorCode UdCounterCtrl_setInitialValue(UdCounterCtrl *obj, int32 value)  
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_setInitialValue(ch, value) : ErrorFuncNotInited;
}
static int32 UdCounterCtrl_getResetTimesByIndex(UdCounterCtrl *obj)
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_getResetTimesByIndex(ch) : 0;
}
static ErrorCode UdCounterCtrl_setResetTimesByIndex(UdCounterCtrl *obj, int32 value)
{
   UdChannel *ch = UdCounterCtrl_getCHPtr(obj);
   return ch ? UdChannel_setResetTimesByIndex(ch, value) : ErrorFuncNotInited;
}
static int32 UdCounterCtrl_getValue(UdCounterCtrl *obj)
{
   int32 value = 0;
   UdCounterCtrl_Read(obj, 1, &value);
   return value;
}









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 6192 "bdaqctrlTest.h"

#line 6194 "bdaqctrlTest.h"



#line 6198 "bdaqctrlTest.h"

