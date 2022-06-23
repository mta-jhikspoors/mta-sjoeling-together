/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.4 */

#ifndef PB_IOMODULE_IOMODULE_PB_H_INCLUDED
#define PB_IOMODULE_IOMODULE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _IOModule_Sensor {
    IOModule_Sensor_Gate1Front = 0,
    IOModule_Sensor_Gate2Front = 1,
    IOModule_Sensor_Gate3Front = 2,
    IOModule_Sensor_Gate4Front = 3,
    IOModule_Sensor_Gate1Back = 4,
    IOModule_Sensor_Gate2Back = 5,
    IOModule_Sensor_Gate3Back = 6,
    IOModule_Sensor_Gate4Back = 7,
    IOModule_Sensor_LeftButton = 8,
    IOModule_Sensor_RightButton = 9,
    IOModule_Sensor_AcceptButton = 10,
    IOModule_Sensor_CancelButton = 11,
    IOModule_Sensor_Bridge1Sensor = 12,
    IOModule_Sensor_Bridge2Sensor = 13
} IOModule_Sensor;

/* Struct definitions */
typedef struct _IOModule_AcceptButtonPressedMsg {
    char dummy_field;
} IOModule_AcceptButtonPressedMsg;

typedef struct _IOModule_CalibrateModeMsg {
    char dummy_field;
} IOModule_CalibrateModeMsg;

typedef struct _IOModule_CancelButtonPressedMsg {
    char dummy_field;
} IOModule_CancelButtonPressedMsg;

typedef struct _IOModule_IndicateErrorMsg {
    char dummy_field;
} IOModule_IndicateErrorMsg;

typedef struct _IOModule_LeftButtonPressedMsg {
    char dummy_field;
} IOModule_LeftButtonPressedMsg;

typedef struct _IOModule_NormalModeMsg {
    char dummy_field;
} IOModule_NormalModeMsg;

typedef struct _IOModule_RemovePuckMsg {
    char dummy_field;
} IOModule_RemovePuckMsg;

typedef struct _IOModule_RightButtonPressedMsg {
    char dummy_field;
} IOModule_RightButtonPressedMsg;

typedef struct _IOModule_RoundResetMsg {
    char dummy_field;
} IOModule_RoundResetMsg;

typedef struct _IOModule_SensorBlockedMsg {
    char dummy_field;
} IOModule_SensorBlockedMsg;

typedef struct _IOModule_SensorClearedMsg {
    char dummy_field;
} IOModule_SensorClearedMsg;

typedef struct _IOModule_GateScoreMsg {
    uint32_t Gate;
} IOModule_GateScoreMsg;

typedef struct _IOModule_PuckInGateMsg {
    uint32_t Gate;
} IOModule_PuckInGateMsg;

typedef struct _IOModule_SensorStateMsg {
    IOModule_Sensor Sensor;
    bool High;
} IOModule_SensorStateMsg;

typedef struct _IOModule_SetButtonLightsMsg {
    bool LeftButton;
    bool RightButton;
    bool AcceptButton;
    bool CancelButton;
} IOModule_SetButtonLightsMsg;

typedef struct _IOModule_SetButtonRepeatMsg {
    bool Enable;
} IOModule_SetButtonRepeatMsg;

typedef struct _IOModule_SettingsMsg {
    uint32_t SlideTimeoutMs;
    bool HardMode;
    uint32_t ButtonRepeatTimeout;
    uint32_t ButtonRepeatInterval;
    uint32_t PuckLostTimeout;
    uint32_t DebounceTimeout;
} IOModule_SettingsMsg;

typedef struct _IOModule_StartSlideMsg {
    uint32_t Speed;
} IOModule_StartSlideMsg;

typedef struct _IOModule_IOMessage {
    pb_size_t which_Content;
    union {
        IOModule_StartSlideMsg StartSlide;
        IOModule_GateScoreMsg GateScore;
        IOModule_PuckInGateMsg PuckInGate;
        IOModule_SensorStateMsg SensorState;
        IOModule_LeftButtonPressedMsg LeftButtonPressed;
        IOModule_RightButtonPressedMsg RightButtonPressed;
        IOModule_AcceptButtonPressedMsg AcceptButtonPressed;
        IOModule_CancelButtonPressedMsg CancelButtonPressed;
        IOModule_RemovePuckMsg RemovePuck;
        IOModule_SensorBlockedMsg SensorBlocked;
        IOModule_SensorClearedMsg SensorCleared;
    } Content;
} IOModule_IOMessage;

typedef struct _IOModule_PiMessage {
    pb_size_t which_Content;
    union {
        IOModule_NormalModeMsg NormalMode;
        IOModule_CalibrateModeMsg CalibrateMode;
        IOModule_IndicateErrorMsg IndicateError;
        IOModule_SettingsMsg Settings;
        IOModule_RoundResetMsg RoundReset;
        IOModule_SetButtonLightsMsg SetButtonLights;
        IOModule_SetButtonRepeatMsg SetButtonRepeat;
    } Content;
} IOModule_PiMessage;


/* Helper constants for enums */
#define _IOModule_Sensor_MIN IOModule_Sensor_Gate1Front
#define _IOModule_Sensor_MAX IOModule_Sensor_Bridge2Sensor
#define _IOModule_Sensor_ARRAYSIZE ((IOModule_Sensor)(IOModule_Sensor_Bridge2Sensor+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define IOModule_PiMessage_init_default          {0, {IOModule_NormalModeMsg_init_default}}
#define IOModule_IOMessage_init_default          {0, {IOModule_StartSlideMsg_init_default}}
#define IOModule_RoundResetMsg_init_default      {0}
#define IOModule_SetButtonLightsMsg_init_default {0, 0, 0, 0}
#define IOModule_SettingsMsg_init_default        {0, 0, 0, 0, 0, 0}
#define IOModule_NormalModeMsg_init_default      {0}
#define IOModule_CalibrateModeMsg_init_default   {0}
#define IOModule_IndicateErrorMsg_init_default   {0}
#define IOModule_StartSlideMsg_init_default      {0}
#define IOModule_RemovePuckMsg_init_default      {0}
#define IOModule_SensorBlockedMsg_init_default   {0}
#define IOModule_SensorClearedMsg_init_default   {0}
#define IOModule_LeftButtonPressedMsg_init_default {0}
#define IOModule_RightButtonPressedMsg_init_default {0}
#define IOModule_AcceptButtonPressedMsg_init_default {0}
#define IOModule_CancelButtonPressedMsg_init_default {0}
#define IOModule_GateScoreMsg_init_default       {0}
#define IOModule_PuckInGateMsg_init_default      {0}
#define IOModule_SensorStateMsg_init_default     {_IOModule_Sensor_MIN, 0}
#define IOModule_SetButtonRepeatMsg_init_default {0}
#define IOModule_PiMessage_init_zero             {0, {IOModule_NormalModeMsg_init_zero}}
#define IOModule_IOMessage_init_zero             {0, {IOModule_StartSlideMsg_init_zero}}
#define IOModule_RoundResetMsg_init_zero         {0}
#define IOModule_SetButtonLightsMsg_init_zero    {0, 0, 0, 0}
#define IOModule_SettingsMsg_init_zero           {0, 0, 0, 0, 0, 0}
#define IOModule_NormalModeMsg_init_zero         {0}
#define IOModule_CalibrateModeMsg_init_zero      {0}
#define IOModule_IndicateErrorMsg_init_zero      {0}
#define IOModule_StartSlideMsg_init_zero         {0}
#define IOModule_RemovePuckMsg_init_zero         {0}
#define IOModule_SensorBlockedMsg_init_zero      {0}
#define IOModule_SensorClearedMsg_init_zero      {0}
#define IOModule_LeftButtonPressedMsg_init_zero  {0}
#define IOModule_RightButtonPressedMsg_init_zero {0}
#define IOModule_AcceptButtonPressedMsg_init_zero {0}
#define IOModule_CancelButtonPressedMsg_init_zero {0}
#define IOModule_GateScoreMsg_init_zero          {0}
#define IOModule_PuckInGateMsg_init_zero         {0}
#define IOModule_SensorStateMsg_init_zero        {_IOModule_Sensor_MIN, 0}
#define IOModule_SetButtonRepeatMsg_init_zero    {0}

/* Field tags (for use in manual encoding/decoding) */
#define IOModule_GateScoreMsg_Gate_tag           1
#define IOModule_PuckInGateMsg_Gate_tag          1
#define IOModule_SensorStateMsg_Sensor_tag       1
#define IOModule_SensorStateMsg_High_tag         2
#define IOModule_SetButtonLightsMsg_LeftButton_tag 1
#define IOModule_SetButtonLightsMsg_RightButton_tag 2
#define IOModule_SetButtonLightsMsg_AcceptButton_tag 3
#define IOModule_SetButtonLightsMsg_CancelButton_tag 4
#define IOModule_SetButtonRepeatMsg_Enable_tag   1
#define IOModule_SettingsMsg_SlideTimeoutMs_tag  1
#define IOModule_SettingsMsg_HardMode_tag        2
#define IOModule_SettingsMsg_ButtonRepeatTimeout_tag 3
#define IOModule_SettingsMsg_ButtonRepeatInterval_tag 4
#define IOModule_SettingsMsg_PuckLostTimeout_tag 5
#define IOModule_SettingsMsg_DebounceTimeout_tag 6
#define IOModule_StartSlideMsg_Speed_tag         1
#define IOModule_IOMessage_StartSlide_tag        100
#define IOModule_IOMessage_GateScore_tag         101
#define IOModule_IOMessage_PuckInGate_tag        102
#define IOModule_IOMessage_SensorState_tag       103
#define IOModule_IOMessage_LeftButtonPressed_tag 104
#define IOModule_IOMessage_RightButtonPressed_tag 105
#define IOModule_IOMessage_AcceptButtonPressed_tag 106
#define IOModule_IOMessage_CancelButtonPressed_tag 107
#define IOModule_IOMessage_RemovePuck_tag        108
#define IOModule_IOMessage_SensorBlocked_tag     109
#define IOModule_IOMessage_SensorCleared_tag     110
#define IOModule_PiMessage_NormalMode_tag        100
#define IOModule_PiMessage_CalibrateMode_tag     101
#define IOModule_PiMessage_IndicateError_tag     102
#define IOModule_PiMessage_Settings_tag          103
#define IOModule_PiMessage_RoundReset_tag        104
#define IOModule_PiMessage_SetButtonLights_tag   105
#define IOModule_PiMessage_SetButtonRepeat_tag   106

/* Struct field encoding specification for nanopb */
#define IOModule_PiMessage_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,NormalMode,Content.NormalMode), 100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,CalibrateMode,Content.CalibrateMode), 101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,IndicateError,Content.IndicateError), 102) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,Settings,Content.Settings), 103) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,RoundReset,Content.RoundReset), 104) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,SetButtonLights,Content.SetButtonLights), 105) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,SetButtonRepeat,Content.SetButtonRepeat), 106)
#define IOModule_PiMessage_CALLBACK NULL
#define IOModule_PiMessage_DEFAULT NULL
#define IOModule_PiMessage_Content_NormalMode_MSGTYPE IOModule_NormalModeMsg
#define IOModule_PiMessage_Content_CalibrateMode_MSGTYPE IOModule_CalibrateModeMsg
#define IOModule_PiMessage_Content_IndicateError_MSGTYPE IOModule_IndicateErrorMsg
#define IOModule_PiMessage_Content_Settings_MSGTYPE IOModule_SettingsMsg
#define IOModule_PiMessage_Content_RoundReset_MSGTYPE IOModule_RoundResetMsg
#define IOModule_PiMessage_Content_SetButtonLights_MSGTYPE IOModule_SetButtonLightsMsg
#define IOModule_PiMessage_Content_SetButtonRepeat_MSGTYPE IOModule_SetButtonRepeatMsg

#define IOModule_IOMessage_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,StartSlide,Content.StartSlide), 100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,GateScore,Content.GateScore), 101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,PuckInGate,Content.PuckInGate), 102) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,SensorState,Content.SensorState), 103) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,LeftButtonPressed,Content.LeftButtonPressed), 104) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,RightButtonPressed,Content.RightButtonPressed), 105) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,AcceptButtonPressed,Content.AcceptButtonPressed), 106) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,CancelButtonPressed,Content.CancelButtonPressed), 107) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,RemovePuck,Content.RemovePuck), 108) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,SensorBlocked,Content.SensorBlocked), 109) \
X(a, STATIC,   ONEOF,    MESSAGE,  (Content,SensorCleared,Content.SensorCleared), 110)
#define IOModule_IOMessage_CALLBACK NULL
#define IOModule_IOMessage_DEFAULT NULL
#define IOModule_IOMessage_Content_StartSlide_MSGTYPE IOModule_StartSlideMsg
#define IOModule_IOMessage_Content_GateScore_MSGTYPE IOModule_GateScoreMsg
#define IOModule_IOMessage_Content_PuckInGate_MSGTYPE IOModule_PuckInGateMsg
#define IOModule_IOMessage_Content_SensorState_MSGTYPE IOModule_SensorStateMsg
#define IOModule_IOMessage_Content_LeftButtonPressed_MSGTYPE IOModule_LeftButtonPressedMsg
#define IOModule_IOMessage_Content_RightButtonPressed_MSGTYPE IOModule_RightButtonPressedMsg
#define IOModule_IOMessage_Content_AcceptButtonPressed_MSGTYPE IOModule_AcceptButtonPressedMsg
#define IOModule_IOMessage_Content_CancelButtonPressed_MSGTYPE IOModule_CancelButtonPressedMsg
#define IOModule_IOMessage_Content_RemovePuck_MSGTYPE IOModule_RemovePuckMsg
#define IOModule_IOMessage_Content_SensorBlocked_MSGTYPE IOModule_SensorBlockedMsg
#define IOModule_IOMessage_Content_SensorCleared_MSGTYPE IOModule_SensorClearedMsg

#define IOModule_RoundResetMsg_FIELDLIST(X, a) \

#define IOModule_RoundResetMsg_CALLBACK NULL
#define IOModule_RoundResetMsg_DEFAULT NULL

#define IOModule_SetButtonLightsMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     LeftButton,        1) \
X(a, STATIC,   SINGULAR, BOOL,     RightButton,       2) \
X(a, STATIC,   SINGULAR, BOOL,     AcceptButton,      3) \
X(a, STATIC,   SINGULAR, BOOL,     CancelButton,      4)
#define IOModule_SetButtonLightsMsg_CALLBACK NULL
#define IOModule_SetButtonLightsMsg_DEFAULT NULL

#define IOModule_SettingsMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   SlideTimeoutMs,    1) \
X(a, STATIC,   SINGULAR, BOOL,     HardMode,          2) \
X(a, STATIC,   SINGULAR, UINT32,   ButtonRepeatTimeout,   3) \
X(a, STATIC,   SINGULAR, UINT32,   ButtonRepeatInterval,   4) \
X(a, STATIC,   SINGULAR, UINT32,   PuckLostTimeout,   5) \
X(a, STATIC,   SINGULAR, UINT32,   DebounceTimeout,   6)
#define IOModule_SettingsMsg_CALLBACK NULL
#define IOModule_SettingsMsg_DEFAULT NULL

#define IOModule_NormalModeMsg_FIELDLIST(X, a) \

#define IOModule_NormalModeMsg_CALLBACK NULL
#define IOModule_NormalModeMsg_DEFAULT NULL

#define IOModule_CalibrateModeMsg_FIELDLIST(X, a) \

#define IOModule_CalibrateModeMsg_CALLBACK NULL
#define IOModule_CalibrateModeMsg_DEFAULT NULL

#define IOModule_IndicateErrorMsg_FIELDLIST(X, a) \

#define IOModule_IndicateErrorMsg_CALLBACK NULL
#define IOModule_IndicateErrorMsg_DEFAULT NULL

#define IOModule_StartSlideMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   Speed,             1)
#define IOModule_StartSlideMsg_CALLBACK NULL
#define IOModule_StartSlideMsg_DEFAULT NULL

#define IOModule_RemovePuckMsg_FIELDLIST(X, a) \

#define IOModule_RemovePuckMsg_CALLBACK NULL
#define IOModule_RemovePuckMsg_DEFAULT NULL

#define IOModule_SensorBlockedMsg_FIELDLIST(X, a) \

#define IOModule_SensorBlockedMsg_CALLBACK NULL
#define IOModule_SensorBlockedMsg_DEFAULT NULL

#define IOModule_SensorClearedMsg_FIELDLIST(X, a) \

#define IOModule_SensorClearedMsg_CALLBACK NULL
#define IOModule_SensorClearedMsg_DEFAULT NULL

#define IOModule_LeftButtonPressedMsg_FIELDLIST(X, a) \

#define IOModule_LeftButtonPressedMsg_CALLBACK NULL
#define IOModule_LeftButtonPressedMsg_DEFAULT NULL

#define IOModule_RightButtonPressedMsg_FIELDLIST(X, a) \

#define IOModule_RightButtonPressedMsg_CALLBACK NULL
#define IOModule_RightButtonPressedMsg_DEFAULT NULL

#define IOModule_AcceptButtonPressedMsg_FIELDLIST(X, a) \

#define IOModule_AcceptButtonPressedMsg_CALLBACK NULL
#define IOModule_AcceptButtonPressedMsg_DEFAULT NULL

#define IOModule_CancelButtonPressedMsg_FIELDLIST(X, a) \

#define IOModule_CancelButtonPressedMsg_CALLBACK NULL
#define IOModule_CancelButtonPressedMsg_DEFAULT NULL

#define IOModule_GateScoreMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   Gate,              1)
#define IOModule_GateScoreMsg_CALLBACK NULL
#define IOModule_GateScoreMsg_DEFAULT NULL

#define IOModule_PuckInGateMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   Gate,              1)
#define IOModule_PuckInGateMsg_CALLBACK NULL
#define IOModule_PuckInGateMsg_DEFAULT NULL

#define IOModule_SensorStateMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    Sensor,            1) \
X(a, STATIC,   SINGULAR, BOOL,     High,              2)
#define IOModule_SensorStateMsg_CALLBACK NULL
#define IOModule_SensorStateMsg_DEFAULT NULL

#define IOModule_SetButtonRepeatMsg_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     Enable,            1)
#define IOModule_SetButtonRepeatMsg_CALLBACK NULL
#define IOModule_SetButtonRepeatMsg_DEFAULT NULL

extern const pb_msgdesc_t IOModule_PiMessage_msg;
extern const pb_msgdesc_t IOModule_IOMessage_msg;
extern const pb_msgdesc_t IOModule_RoundResetMsg_msg;
extern const pb_msgdesc_t IOModule_SetButtonLightsMsg_msg;
extern const pb_msgdesc_t IOModule_SettingsMsg_msg;
extern const pb_msgdesc_t IOModule_NormalModeMsg_msg;
extern const pb_msgdesc_t IOModule_CalibrateModeMsg_msg;
extern const pb_msgdesc_t IOModule_IndicateErrorMsg_msg;
extern const pb_msgdesc_t IOModule_StartSlideMsg_msg;
extern const pb_msgdesc_t IOModule_RemovePuckMsg_msg;
extern const pb_msgdesc_t IOModule_SensorBlockedMsg_msg;
extern const pb_msgdesc_t IOModule_SensorClearedMsg_msg;
extern const pb_msgdesc_t IOModule_LeftButtonPressedMsg_msg;
extern const pb_msgdesc_t IOModule_RightButtonPressedMsg_msg;
extern const pb_msgdesc_t IOModule_AcceptButtonPressedMsg_msg;
extern const pb_msgdesc_t IOModule_CancelButtonPressedMsg_msg;
extern const pb_msgdesc_t IOModule_GateScoreMsg_msg;
extern const pb_msgdesc_t IOModule_PuckInGateMsg_msg;
extern const pb_msgdesc_t IOModule_SensorStateMsg_msg;
extern const pb_msgdesc_t IOModule_SetButtonRepeatMsg_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define IOModule_PiMessage_fields &IOModule_PiMessage_msg
#define IOModule_IOMessage_fields &IOModule_IOMessage_msg
#define IOModule_RoundResetMsg_fields &IOModule_RoundResetMsg_msg
#define IOModule_SetButtonLightsMsg_fields &IOModule_SetButtonLightsMsg_msg
#define IOModule_SettingsMsg_fields &IOModule_SettingsMsg_msg
#define IOModule_NormalModeMsg_fields &IOModule_NormalModeMsg_msg
#define IOModule_CalibrateModeMsg_fields &IOModule_CalibrateModeMsg_msg
#define IOModule_IndicateErrorMsg_fields &IOModule_IndicateErrorMsg_msg
#define IOModule_StartSlideMsg_fields &IOModule_StartSlideMsg_msg
#define IOModule_RemovePuckMsg_fields &IOModule_RemovePuckMsg_msg
#define IOModule_SensorBlockedMsg_fields &IOModule_SensorBlockedMsg_msg
#define IOModule_SensorClearedMsg_fields &IOModule_SensorClearedMsg_msg
#define IOModule_LeftButtonPressedMsg_fields &IOModule_LeftButtonPressedMsg_msg
#define IOModule_RightButtonPressedMsg_fields &IOModule_RightButtonPressedMsg_msg
#define IOModule_AcceptButtonPressedMsg_fields &IOModule_AcceptButtonPressedMsg_msg
#define IOModule_CancelButtonPressedMsg_fields &IOModule_CancelButtonPressedMsg_msg
#define IOModule_GateScoreMsg_fields &IOModule_GateScoreMsg_msg
#define IOModule_PuckInGateMsg_fields &IOModule_PuckInGateMsg_msg
#define IOModule_SensorStateMsg_fields &IOModule_SensorStateMsg_msg
#define IOModule_SetButtonRepeatMsg_fields &IOModule_SetButtonRepeatMsg_msg

/* Maximum encoded size of messages (where known) */
#define IOModule_PiMessage_size                  35
#define IOModule_IOMessage_size                  9
#define IOModule_RoundResetMsg_size              0
#define IOModule_SetButtonLightsMsg_size         8
#define IOModule_SettingsMsg_size                32
#define IOModule_NormalModeMsg_size              0
#define IOModule_CalibrateModeMsg_size           0
#define IOModule_IndicateErrorMsg_size           0
#define IOModule_StartSlideMsg_size              6
#define IOModule_RemovePuckMsg_size              0
#define IOModule_SensorBlockedMsg_size           0
#define IOModule_SensorClearedMsg_size           0
#define IOModule_LeftButtonPressedMsg_size       0
#define IOModule_RightButtonPressedMsg_size      0
#define IOModule_AcceptButtonPressedMsg_size     0
#define IOModule_CancelButtonPressedMsg_size     0
#define IOModule_GateScoreMsg_size               6
#define IOModule_PuckInGateMsg_size              6
#define IOModule_SensorStateMsg_size             4
#define IOModule_SetButtonRepeatMsg_size         2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
