//
//  ZPZAppAdapter.h
//  zVideoUI
//
//  Created by TOTTI on 9/8/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define ZoomAppsWindowNamePrefix @"Zoom Apps - "
#define ZoomAppsCollaborateWindowNameSuffix @" - Collaboration"
#define kZoomAppShareIdentity @"Zoom App Share Identity"
#define kZoomAppCollaborateMainWindowName @"Zoom Apps Collaboration Main Window"

typedef NS_ENUM(NSInteger, ZMAppType) {
    ZMAppType_Default = -1,
    ZMAppType_Apps_PT = 0,
    ZMAppType_Apps_MT,
    ZMAppType_Phone,
    ZMAppType_OnZoom,
    ZMAppType_CCI,
    ZMAppType_SideCar,
    ZMAppType_Chat_DM,
    ZMAppType_Chat_Channel,
    ZMAppType_Mail,
    ZMAppType_Simulive,
    ZMAppType_Labs,
    ZMAppType_VCard,
};
typedef NS_ENUM(NSInteger, ZMZAppViewCtrlActionType) {
    ACTION_DEFAULT = -1,
    ACTION_MORE = 0,
    ACTION_BACK, // Back Action
    ACTION_DROPDOWN, // Click DropDown
    ACTION_POP_OUT, // Click Pop Out
    ACTION_MERGE_BACK, // Click Merge back
    ACTION_REFRESH, // Refresh App
    ACTION_CLOSE, // Close App
    ACTION_CLOSE_ATTENDEE_PUSHED, // Close ATTENDEE Push
    ACTION_CLOSE_ALL_PUSHED, // Close All Pushed App
    ACTION_CLOSE_ALL_EXCEPT_ME_PUSHED, // Close all except me Pushed App
    ACTION_SEND, // Click Send
    ACTION_SEND_IN_CONTROLLERMODE, // Click Send In Layer Controller Mode
    ACTION_SHARE_WITH_AUDIO, // Click Share With Audio
    ACTION_SHARE_NO_AUDIO, // Click Share Whth No Audio
    ACTION_EXPAND, // Click Expand
    ACTION_COLLABORATE, // Click Collaborate
    ACTION_START_MEETTING, // Click Start Meeting
    ACTION_INVITE, // Click invite
    ACTION_OPEN_IN_MEETTING, // Click Open in Meeting
    ACTION_OPEN_NEW_WINDOW, // Click Open in New Window
    ACTION_OPEN_IN_DOCK,
    ACTION_REMOVE_FROM_DOCK,
    ACTION_ADD_TO_DOCK,
};

typedef NS_ENUM(NSUInteger, ZAppRenderType) {
    ZAppRenderType_None,
    ZAppRenderType_Immersive,
    ZAppRenderType_CameraMode,
    ZAppRenderType_AppShare,
};

typedef NS_ENUM(NSInteger, ZMZappLayersCutoutType) {
    ZMZappLayersCutoutType_Default = 0,
    ZMZappLayersCutoutType_Person, // remove the background
    ZMZappLayersCutoutType_Rectangle, // rounded corners
    ZMZappLayersCutoutType_Circle,
    ZMZappLayersCutoutType_Square, // rounded corners
    ZMZappLayersCutoutType_VerticalRectangle, // rounded corners
    ZMZappLayersCutoutType_Standard, // sharp corners (full video)
};

typedef NS_ENUM(NSUInteger, ZAppContentType) {
    ZAppContent_None,
    ZAppContent_List,
    ZAppContent_Detail,
    ZAppContent_App,
    ZAppContent_Error,
    ZAppContent_Authentication,
    ZAppContent_ControllerMode,
};

typedef NS_ENUM(NSUInteger, ZAppWebViewStatus) {
    ZAppWebView_Support = 0,
    ZAppWebView_Uninstall,
    ZAppWebView_Unsupport,
    ZAppWebView_Disable,
};

typedef NS_ENUM(NSUInteger, ZMZAppSetVBStatus) { // ZOOM-249560
    ZMZAppSetVB_Failed = 0,
    ZMZAppSetVB_Success,
    ZMZAppSetVB_Ignored,
};

typedef NS_ENUM(NSInteger, ZMAomhostDownloadErrorCode) {
    ZMAomhostDownloadSuccess,
    ZMAomhostDownloadFailed,
    ZMAomhostDownloadIgnored,
};

typedef NS_ENUM(NSUInteger, zappEnableState) {
    zappEnableState_Enable = 0,
    zappEnableState_Disable_By_Unknow_Error,
    zappEnableState_Disable_By_GPO,
    zappEnableState_Disable_By_Setting,
    zappEnableState_Disable_By_UserId_Mismatch,
    zappEnableState_Disable_By_Client_Not_Login,
    zappEnableState_Disable_By_Anonymous,
    zappEnableState_Disable_By_E2EE_ShowZapp,
    zappEnableState_Disable_By_Unknown_ShowZapp,
    zappEnableState_Disable_By_Different_Meeting,
    zappEnableState_Enable_Guest_Mode_For_Apps_Disabled_User,
    zappEnableState_Enable_Guest_Mode_For_Mismatched_User,
    zappEnableState_Disable_By_GPO_GuestMode,
    zappEnableState_Disable_By_Test_GuestMode,
    zappEnableState_Disable_By_Unsupport = 9999, // start for UI add state
    zappEnableState_Disable_By_macOSVersion = 10000,
};

typedef NS_ENUM(NSUInteger, ZAppMarketPlaceErrorCode) {
    ZAppMarketPlaceErrorCode_None = 0,
    ZAppMarketPlaceErrorCode_DISABLE_UNINSTALL = 4034,
    ZAppMarketPlaceErrorCode_DISABLE_BY_ACCOUNT_ADMIN = 4037,
    ZAppMarketPlaceErrorCode_DISABLE_BY_MARKETPLACE_OP = 4038,
    ZAppMarketPlaceErrorCode_DISABLE_SUBSCRIPTION_BY_ACCOUNT_ADMIN = 4039,
    ZAppMarketPlaceErrorCode_DISABLE_APP_DELETED = 4041,
    ZAppMarketPlaceErrorCode_ENABLE_APP_INSTALL = 4042,
    ZAppMarketPlaceErrorCode_ENABLE_APP = 4043,
    ZAppMarketPlaceErrorCode_DISABLE_PREAPPROVAL_SETTING = 4044,
    ZAppMarketPlaceErrorCode_PREAPPROVAL = 4045,
    ZAppMarketPlaceErrorCode_CANCEL_PREAPPROVAL = 4046,
    ZAPPMarketPlaceErrorCode_INVALID_FOR_ANONYMOUS = 40325,
    ZAPPMarketPlaceErrorCode_INVALID_APP_OFF_GUEST_MODE = 40332,
    ZAPPMarketPlaceErrorCode_COLLABORATE_END_FAIL_OF_AUTH = 40340,
    ZAPPMarketPlaceErrorCode_COLLABORATE_START_FAIL_OF_RATE_LIMIT = 40341,
};

typedef NS_ENUM(NSUInteger, ZAppOpenAppPurpose) {
    ZAppOpenAppBy_NativeUI = 0,
    ZAppOpenAppBy_WebLaucher,
    ZAppOpenAppBy_DeepLink,
    ZAppOpenAppBy_Lobby,
    ZAppOpenAppBy_Connect,
    ZAppOpenAppBy_OpenZappInvitation,
    ZAppOpenAppBy_OtherModule,
    ZAppOpenAppBy_RefreshAppToken,
    ZAppOpenAppBy_CollaborateMode,
    ZAppOpenApp_By_AuthorizeDone,
    ZAppOpenApp_By_PushApp,
    ZAppOpenApp_By_Faxsipit,
    ZAppOpenApp_By_ReLaunch,
    ZAppOpenApp_By_Web,
    ZAppOpenApp_By_RefreshAppForUI,
    ZAppOpenApp_By_Sidecar,
    ZAppOpenApp_By_Guest,
    ZAppOpenApp_By_Workspace,
    ZAppOpenApp_By_DigitalSignage,
};

typedef NS_ENUM(NSInteger, ZAppCloudRecordCmd) {
    ZAppCloudRecordCmd_None = -1,
    ZAppCloudRecordCmd_START = 0,
    ZAppCloudRecordCmd_STOP,
    ZAppCloudRecordCmd_PAUSE,
    ZAppCloudRecordCmd_RESUME
};

typedef NS_ENUM(NSInteger, ZAppRefreshSettingType) {
    ZAppRefreshSetting_None = -1,
    ZAppRefreshSetting_RemoveVB,
    ZAppRefreshSetting_SetBlur,
    ZAppRefreshSetting_SetMirror,
    ZAppRefreshSetting_SelectCamera,
    ZAppRefreshSetting_SetHDVideo,
    ZAppRefreshSetting_SetDisplayUsernames,
    ZAppRefreshSetting_SetAudioSettings
};

typedef NS_ENUM(NSInteger, ZAppShareCmd) {
    ZAppShareCmd_None = -1,
    ZAppShareCmd_START = 0,
    ZAppShareCmd_STOP,
};

typedef NS_ENUM(NSInteger, ZAppShareSourceType) {
    ZAppShareSource_None = -1,
    ZAppShareSource_App = 0,
    ZAppShareSource_Pure_Audio,
};

typedef NS_ENUM(NSInteger, ZMZAppSendMenuType) {
    SendMenu_None = 0,
    SendMenu_All = 1 << 0,
    SendMenu_Participants = 1 << 1,
    SendMenu_Host = 1 << 2,
    SendMenu_Panelist = 1 << 3,
    SendMenu_Select_Panelist = 1 << 4,
    SendMenu_Select_Attendee = 1 << 5
};

typedef NS_ENUM(NSInteger, ZAppOpenAppAction) {
    ZAppOpenAppAction_NONE = 0,
    ZAppOpenAppAction_OPEN_APP,
    ZAppOpenAppAction_CLOSE_APP,
    ZAppOpenAppAction_CLOSE_ALL_APP,
    ZAppOpenAppAction_ADD_APP,
    ZAppOpenAppAction_OPEN_APP_DETAIL,
    ZAppOpenAppAction_OPEN_LABAPP,
    ZAppOpenAppAction_CLOSE_LABAPP,
};

typedef NS_ENUM(NSInteger, ZAppJsCallErrorType) {
    ZAppJsCallError_Success = 0,
    ZAppJsCallError_General = 10001,
    ZAppJsCallError_Para_Format = 10002, //when parse paras from jscall
    ZAppJsCallError_Config_Denied = 10003, //when execute config
    ZAppJsCallError_Not_Authed = 10004, //when execute other jscall
    ZAppJsCallError_Auth_Info_Expired = 10005, //when execute other jscall
    ZAppJsCallError_Access_Server_Fail = 10006, //send req to web fail
    ZAppJsCallError_Not_In_A_Meeting = 10007,
    ZAppJsCallError_API_NOT_Exist = 10008,
    ZAppJsCallError_JSSDK_Verify_Fail = 10009,
    ZAppJsCallError_Get_Download_Path_Fail = 10010,
    ZAppJsCallError_DownLoad_File_Fail = 10011,
    ZAppJsCallError_Update_VirtualBackground_Fail = 10012,
    ZAppJsCallError_GetSupportedJsApis_Req_Fail = 10013,
    ZAppJsCallError_VB_DownLoad_Cancel_For_Timeout = 10014,
    ZAppJsCallError_OpenUrl_Req_Fail = 10015,
    ZAppJsCallError_Too_Many_Call_Pending = 10016,
    ZAppJsCallError_User_Not_Allow = 10017,
    ZAppJsCallError_Share_App_Fail = 10018,
    ZAppJsCallError_No_Such_Camera = 10019,
    ZAppJsCallError_Video_Status_Off = 10020,
    ZAppJsCallError_CloudRecording_Not_Allowed = 10021,
    ZAppJsCallError_Share_App_Disabled = 10022,
    ZAppJsCallError_Share_App_Started = 10023,
    ZAppJsCallError_Share_App_Not_Start = 10024,
    ZAppJsCallError_Invalid_CloudRecording_Action = 10025,
    ZAppJsCallError_Send_App_Invitation_Fail = 10026,
    ZAppJsCallError_Send_App_Invitation_NotAllowed = 10027,
    ZAppJsCallError_Send_App_Invitation_Over_Limit = 10028,
    ZAppJsCallError_Unsurppoted_VB_Format = 10029,
    ZAppJsCallError_Device_Not_Support_Set_VB = 10030,
    ZAppJsCallError_VB_Feature_Not_Enable = 10031,
    ZAppJsCallError_Cannot_Set_VB_In_Cur_Immersive_Scene = 10032,
    ZAppJsCallError_Client_Rate_Limit = 10033,
    ZAppJsCallError_Client_Api_Not_Config = 10034,
    ZAppJsCallError_Server_Rate_Limit = 10035,
    ZAppJsCallError_DownloadUrl_Not_In_WhiteDomainList = 10036,
    ZAppJsCallError_OpenCloseApp_Fail = 10037,
    ZAppJsCallError_PostMessageToConnectApp_Fail = 10038,
    ZAppJsCallError_ConnectApp_In_PT = 10039,
    ZAppJsCallError_LocalRecording_In_Progress = 10040,
    ZAppJsCallError_Not_ConnectedApp = 10041,
    ZAppJsCallError_Not_ShowNotification_For_DND = 10042,
    ZAppJsCallError_Current_Url_Not_Valid = 10043,
    ZAppJsCallError_VirtualBackground_Decode_Fail = 10044,
    ZAppJsCallError_Smart_VB_Package_NeedDownload = 10045,
    ZAppJsCallError_OnZoom_Screenshot_OverMaxSize = 10046,
    ZAppJsCallError_Client_Api_No_Permission = 10047,
    ZAppJsCallError_Allow_Participant_To_Record_Fail = 10048,
    ZAppJsCallError_Not_Get_Participant_Info = 10049,
    ZAppJsCallError_Has_Record_Permission_Already = 10050,
    ZAppJsCallError_Invalid_User = 10051,
    ZAppJsCallError_No_Need_Revoke_Permission = 10052,
    ZAppJsCallError_API_Only_Can_Use_After_Meeting_End = 10053,
    ZAppJsCallError_Client_Only_UseInPt = 10054,
    ZAppJsCallError_Local_Record_Feature_Disabled = 10055,
    ZAppJsCallError_Cannot_Set_VB_Video_Merged_On_Share = 10056,
    ZAppJsCallError_Can_Not_Remove_VB_In_ForceVB_mode = 10057,
    ZAppJsCallError_Client_StartOrJoinMeeting_Faild = 10058,
    ZAppJsCallError_HasOtherShareObj = 10059,
    ZAppJsCallError_Client_User_Confirmation_Dialog_Cancel = 10060,
    ZAppJsCallError_Need_Host_Permission = 10061,
    ZAppJsCallError_Action_Flushed_By_New_Action = 10064,
    ZAppJsCallError_Toggle_My_Audio_Fail = 10073,
    ZAppJsCallError_Toggle_My_Video_Fail = 10074,
    ZAppJsCallError_App_In_Collaborate = 10084,
    ZAppJsCallError_App_Not_In_Collaborate = 10085,
    ZAppJsCallError_User_Already_Join_Collaborate = 10086,
    ZAppJsCallError_User_Not_Join_In_Collaborate = 10087,
    ZAppJsCallError_User_Start_Collaborate_Can_Not_Leave = 10088,
    ZAppJsCallError_App_Cannot_Support_Collaborate = 10089,
    ZAppJsCallError_Share_Computer_Audio_Fail = 10131,
    ZAppJsCallError_Need_Stop_Other_Share_To_Start_Share = 10137,
    ZAppJsCallError_Meeting_Cannot_Invite = 10152,
};

typedef NS_ENUM(NSInteger, ZAppVBAction) {
    ZAppVBAction_None = -1,
    ZAppVBAction_RemoveVB = 0,
    ZAppVBAction_SetBlur,
};

typedef NS_ENUM(NSInteger, ZAppUserActionType) {
    ZAppUserAction_Undefined = -1,
    ZAppUserAction_BackToMyApps = 0,
    ZAppUserAction_BackToDiscover,
};

typedef NS_ENUM(NSInteger, ZAppConsentAction) {
    ZAppConsentAction_None = 0,
    ZAppConsentAction_Grant_Record,
    ZAppConsentAction_Revoke_Record,
    ZAppConsentAction_SendApp_All,
    ZAppConsentAction_Start_Meeting,
    ZAppConsentAction_Join_Meeting,
    ZAppConsentAction_Set_Camera,
    ZAppConsentAction_List_Cameras,
    ZAppConsentAction_Set_Mirror,
    ZAppConsentAction_Remove_VB,
    ZAppConsentAction_Set_Blur,
    ZAppConsentAction_Set_VB,
    ZAppConsentAction_Start_Share,
    ZAppConsentAction_Stop_Share,
    ZAppConsentAction_OpenURL,
    ZAppConsentAction_Mute_Audio,
    ZAppConsentAction_Unmute_Audio,
    ZAppConsentAction_Open_Video,
    ZAppConsentAction_Close_Video,
    ZAppConsentAction_Start_Collaborate,
    ZAppConsentAction_End_Collaborate,
    ZAppConsentAction_Join_Collaborate,
    ZAppConsentAction_Leave_Collaborate,
    ZAppConsentAction_Mute_Participants,
    ZAppConsentAction_UnMute_Participants,
    ZAppConsentAction_Mute_Incoming_Participants,
    ZAppConsentAction_Unmute_Incoming_Participants,
    ZAppConsentAction_Switch_View,
    ZAppConsentAction_Start_Share_Audio,
    ZAppContentAction_Stop_Share_Audio,
    ZAppConsentAction_Handle_BO,
    ZAppConsentAction_Set_Video_Settings,
    ZAppConsentAction_Set_Audio_Settings,
};

typedef NS_ENUM(NSInteger, ZAppVideoSettingsType) {
    ZAppVideoSettingsType_None = 0,
    ZAppVideoSettingsType_Turn_On_HD_Video,
    ZAppVideoSettingsType_Turn_Off_HD_Video,
    ZAppVideoSettingsType_Hide_Non_Video_Participants,
    ZAppVideoSettingsType_Show_Non_Video_Participants,
    ZAppVideoSettingsType_Hide_Participant_Names,
    ZAppVideoSettingsType_Show_Participant_Names,
};

typedef NS_ENUM(NSInteger, ZAppAudioSettingsType) {
    ZAppAudioSettingsType_None = 0,
    ZAppAudioSettingsType_Change_Speaker_Device,
    ZAppAudioSettingsType_Change_Output_Volume,
    ZAppAudioSettingsType_Change_Microphone_Device,
    ZAppAudioSettingsType_Zoom_Optimized_Audio,
    ZAppAudioSettingsType_Original_Sound,
    ZAppAudioSettingsType_Turn_On_Original_Sound,
    ZAppAudioSettingsType_Turn_Off_Original_Sound,
    ZAppAudioSettingsType_Background_Suppression_Auto,
    ZAppAudioSettingsType_Background_Suppression_Low,
    ZAppAudioSettingsType_Background_Suppression_Medium,
    ZAppAudioSettingsType_Background_Suppression_High,
};

typedef NS_ENUM(NSInteger, ZAppClosePushAppType) {
    ZAppClosePushApp_All = 0,
    ZAppClosePushApp_All_ExceptMe,
    ZAppClosePushApp_Attendee,
};

typedef NS_ENUM(NSInteger, ZAppMeetingAttrType) {
    ZAppMeetingAttr_None = 0,
    ZAppMeetingAttr_Collaboration,
    ZAppMeetingAttr_Close_Collaboration,
    ZAppMeetingAttr_PushApp,
    ZAppMeetingAttr_Close_All_PushApp,
    ZAppMeetingAttr_Close_Attendee_PushApp,
    ZappMeetingAttr_Close_ExceptMe_PushApp,
};

typedef NS_ENUM(NSInteger, ZAppConsentState) {
    ZAppConsentState_None = -1,
    ZAppConsentState_Not_Allow = 0,
    ZAppConsentState_Allow = 1,
};

typedef NS_ENUM(NSInteger, ZAppMeetingViewType) {
    ZAppMeetingView_None = 0,
    ZAppMeetingView_Speaker,
    ZAppMeetingView_Gallery,
    ZAppMeetingView_ToggleFullScreen,
    ZAppMeetingView_EnterFullScreen,
    ZAppMeetingView_ExitFullScreen,
    ZAppMeetingView_FullScreen,
    ZAppMeetingView_NotFullScreen,
    ZAppMeetingView_Standard,
    ZAppMeetingView_SidebysideSpeaker,
    ZAppMeetingView_SidebysideGallery,
    ZAppMeetingView_SharingHighlight,
    ZAppMeetingView_VideoHighlight,
    ZAppMeetingView_Sharing_No_View,
    ZAppMeetingView_Immersive,
    ZAppMeetingView_Minimize,
    ZAppMeetingView_Webinar,
    ZAppMeetingView_DriveMode,
    ZAppMeetingView_ZappLayers,
    ZAppMeetingView_Presenting,
};

typedef NS_ENUM(NSInteger, ZAppOpenAppMode) {
    ZAppOpen_Undefine = -1,
    ZAppOpen_Default = 0,
    ZAppOpen_Basic,
    ZAppOpen_Install,
    ZAppOpen_In_Client_Install,
    ZAppOpen_Auth_Code_Ready,
};

typedef NS_ENUM(NSInteger, ZAppOpenAppSource) {
    ZAppOpenAppSource_Launcher,
    ZAppOpenAppSource_Dock,
};

typedef NS_ENUM(NSInteger, ZAppZoomLevelTag) {
    kLevel_FitToWindow = 0,
    kLevel_50p,
    kLevel_100p,
    kLevel_150p,
    kLevel_200p,
    kLevel_300p,
};

typedef NS_ENUM(NSInteger, ZAppGetMeetingTokenPurpose) {
    ZAppMeetingToken_For_Undefine = 0,
    ZAppMeetingToken_For_OpenApp = 1,
    ZAppMeetingToken_For_LauncherToken = 2,
    ZAppMeetingToken_For_JoinPushApp = 3,
    ZAppMeetingToken_For_JoinCollaborate = 4,
    ZAppMeetingToken_For_RefreshAppToken = 5,
    ZAppMeetingToken_For_StartPushApp = 6,
    ZAppMeetingToken_For_EndPushApp = 7,
    ZAppMeetingToken_For_StartOrEndCollaborate = 8,
};

typedef NS_ENUM(NSInteger, ZAppCollaborateAction) {
    ZAppCollaborateAction_JsEvent_StartCollaborate,
    ZAppCollaborateAction_JsEvent_EndCollaborate,
    ZAppCollaborateAction_JsEvent_JoinCollaborate,
    ZAppCollaborateAction_JsEvent_LeaveCollaborate,
};

typedef NS_OPTIONS(NSUInteger, ZMZappExitCollaborateModeOptions) {
    ZMZappExitCollaborateModeOption_None = 0,
    ZMZappExitCollaborateModeOption_ExitCollaborateMode = 1 << 0,
    ZMZappExitCollaborateModeOption_SendEndRequest = 1 << 1,
    ZMZappExitCollaborateModeOption_StopCollaborateShare = 1 << 2,
    ZMZappExitCollaborateModeOption_RestoreZappView = 1 << 3,
    ZMZappExitCollaborateModeOption_ResetContentValue = 1 << 4,
    ZMZappExitCollaborateModeOption_All = ZMZappExitCollaborateModeOption_ExitCollaborateMode | ZMZappExitCollaborateModeOption_SendEndRequest
                                          | ZMZappExitCollaborateModeOption_StopCollaborateShare | ZMZappExitCollaborateModeOption_RestoreZappView
                                          | ZMZappExitCollaborateModeOption_ResetContentValue,
};

typedef NS_ENUM(NSUInteger, ZMZappCollaborateViewType) {
    ViewType_Button_Collaborate,
    ViewType_Popover_NewFeature,
    ViewType_Alert_Start_New_Collaboration,
    ViewType_Alert_Start_Collaboration_Failed_Of_Unknown_Reason,
    ViewType_Alert_Start_Collaboration_Failed_Of_Launch_Policy,
    ViewType_Alert_Start_Collaboration_Failed_Of_Change_Policy,
    ViewType_Tip_Conf_Join_Collaborate,
    ViewType_Toast_Join_Collaborate,
    ViewType_Tip_Conf_Join_Collaborate_BO_Master,
    ViewType_Toast_Join_Collaborate_BO_Master,
    ViewType_Alert_Collaborate_Ended,
    ViewType_Alert_Collaborate_Ended_BO_Master,
    ViewType_Button_End_Collaborate,
    ViewType_Button_Leave_Collaborate,
    ViewType_Label_Collaborating,
    ViewType_Alert_Ask_Host_Start_Collaborate,
    ViewType_Alert_End_Collaboration,
    ViewType_Alert_Change_2_Share_From_Collaborate,
    ViewType_Alert_End_Collaborate_2_Revoke_Cohost,
    ViewType_Alert_End_Collaborate_2_Make_Host,
    ViewType_Alert_End_Collaborate_For_Everyone,
    ViewType_Toast_Or_Alert_Collaborate_App_Not_Found,
    ViewType_Toast_Or_Alert_Start_Collaboration_Failed_Of_Rate_Limit,
    ViewType_Toast_Or_Alert_End_Collaborate_Fail_Of_Auth,
    ViewType_Alert_Collaborate_Could_Not_Be_Started,
    ViewType_Alert_Collaborate_Could_Not_Be_Ended,
    ViewType_Cosent_Dialog_Start_Collaborate,
    ViewType_Cosent_Dialog_End_Collaborate,
    ViewType_Cosent_Dialog_Join_Collaborate,
    ViewType_Cosent_Dialog_Leave_Collaborate,
    ViewType_Toast_Get_Meeting_Token_Fail_Join_Collaborate,
    ViewType_Toast_Get_Meeting_Token_Fail_Start_Or_End_Collaborate,
    ViewType_Alert_Change_2_Share_PureAudio_From_Collaborate,
};

typedef NS_ENUM(NSInteger, ZMZappDockAppAction) {
    ZMZappDockAppAction_None = 0,
    ZMZappDockAppAction_Remove,
    ZMZappDockAppAction_Add,
    ZMZappDockAppAction_Close,
    ZMZappDockAppAction_Open,
    ZMZappDockAppAction_Install,
    ZMZappDockAppAction_AutoOpen
};

typedef NS_OPTIONS(NSUInteger, ZMZAppCacheDataModule) {
    ZMZAppCacheDataModuleNone = 0,
    ZMZAppCacheDataModuleKeepApps = 1 << 0,
    ZMZAppCacheDataModuleTakeSnap = 1 << 1,
};

extern NSString *const kCollaborateViewTitle;
extern NSString *const kCollaborateViewInformation;
extern NSString *const kCollaborateViewInformation_optional;
extern NSString *const kCollaborateViewDefaultButtonTitle;
extern NSString *const kCollaborateViewSecondaryButtonTitle;
extern NSString *const kCollaborateViewToolTip;
extern NSString *const kCollaborateViewToolTip_Disable;
extern NSString *const kMail_ZMDFScheme;
extern NSString *const kMail_ZMDFSchemeQueryMailID;
extern NSString *const kMail_ZMDFSchemeAttachID;

typedef NS_ENUM(NSInteger, ZAppToastLinkType) {
    ZappToastLink_Undefine = -1,
    ZappToastLink_Detail = 0,
    ZappToastLink_Permission,
    ZappToastLink_Terms,
    ZappToastLink_Privacy,
    ZappToastLink_GuestModeLimit,
    ZappToastLink_LearnMoreLimitedApp,
    ZappToastLink_HelpDisableApp,
};

typedef NS_ENUM(NSInteger, ZAppPreapprovalState) {
    ZappApprovalState_None,
    ZappApprovalState_Approval,
    ZappApprovalState_Not_Approval,
};

typedef NS_ENUM(NSInteger, ZAppErrorWebViewType) {
    ZappErrorWebViewType_None,
    ZappErrorWebViewType_App,
    ZappErrorWebViewType_Auth,
};

typedef NS_ENUM(NSUInteger, ZMZAppInstallState) {
    ZappInstallState_Unknown = 0,
    ZappInstallState_Installed,
    ZappInstallState_Not_Installed,
    ZappInstallState_Disable,
};

typedef NS_ENUM(NSUInteger, ZMZAppOpenedState) {
    ZappOpenedState_None = 0,
    ZappOpenedState_Opened = 1,
    ZappOpenedState_Used = 2,
};

typedef NS_ENUM(NSUInteger, ZMZappStartCollaborateErrorCodeType) {
    ZMZappStartCollaborateErrorCode_Unknown = 0,
    ZMZappStartCollaborateErrorCode_Block_By_Launch_Policy,
    ZMZappStartCollaborateErrorCode_Block_By_Change_Policy,
};

typedef NS_ENUM(NSUInteger, ZMZAppCollaborateLaunchPolicyType) {
    ZMZAppCollaborateLaunchPolicy_Anyone = 0, //the default policy
    ZMZAppCollaborateLaunchPolicy_Host_Only = 1,
};
typedef NS_ENUM(NSUInteger, ZMZAppCollaborateChangePolicyType) {
    ZMZAppCollaborateChangePolicy_Host_Only = 0, //the default policy
    ZMZAppCollaborateChangePolicy_Anyone = 1,
};
//how to clean the running collaboration when the owner leave meeting
typedef NS_ENUM(NSUInteger, ZMZAppCollaborateCleanPolicyType) {
    ZMZAppCollaborateCleanPolicy_Clean_Content_Only = 0, //the default policy
    ZMZAppCollaborateCleanPolicy_Clean_All = 1,
    ZMZAppCollaborateCleanPolicy_Not_Clean = 2,
};

typedef NS_ENUM(NSUInteger, ZMZappConfSessionType) {
    ZMZappConfSession_Default = 0,
    ZMZappConfSession_BoMaster,
};

typedef NS_ENUM(NSUInteger, ZMZappCollaborateInvitationStyle) {
    ZMZappCollaborateInvitation_Toast = 0,
    ZMZappCollaborateInvitation_Conf_Tip,
};

typedef NS_ENUM(NSUInteger, ZMZAppSupportBasicState) {
    ZappInvitationToast_Unknown = 0,
    ZappInvitationToast_Basic,
    ZappInvitationToast_Not_Support_Basic,
    ZappInvitationToast_Installed,
    ZappInvitationToast_Op_Disable,
};

typedef NS_ENUM(NSInteger, ZMZAppPromptShareStatusCode) {
    ZMZAppPromptShareSuccess = 0,
    ZMZAppPromptShare_Stop_Other_Share,
    ZMZAppPromptShare_Failed,
};

@interface ZPZAppHeader : NSObject
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *iconPath;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) BOOL isBetaApp;
@property (nonatomic, copy) NSString *appCompanyName;
@property (nonatomic, assign) BOOL isInstall;
@end

@interface ZMZappContext : NSObject
@property (nonatomic, copy) NSString *installUrl;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *homeUrl;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, retain) NSDictionary *headerDict;
@property (nonatomic, assign) BOOL isDraftApp;
@property (nonatomic, assign) BOOL isAppDisabled;
@property (nonatomic, assign) ZAppOpenAppPurpose openAppPurpose;
@property (nonatomic, assign) BOOL showHomePage;
@property (nonatomic, assign) BOOL shareCookie;
@property (nonatomic, copy) NSString *launchTrackingId;
@property (nonatomic, copy) NSString *refreshUrl;
@property (nonatomic, assign) ZAppOpenAppMode openAppMode;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy) NSString *invitationUUID;
@property (nonatomic, assign) BOOL isBetaApp;
@property (nonatomic, assign) ZAppPreapprovalState approvalState;
@property (nonatomic, copy) NSString *trackingId;
@property (nonatomic, assign) NSInteger httpRetCode;
@end

@interface ZMZAppConsentInfo : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *targetUserName;
@property (nonatomic, copy) NSString *cameraName;
@property (nonatomic, copy) NSString *redirectURL;
@property (nonatomic, copy) NSString *vbFilePath;
@property (nonatomic, assign) BOOL sharedSound;
@property (nonatomic, assign) BOOL needUIActionAfterConsent;
@property (nonatomic, assign) BOOL rememberState;
@property (nonatomic, assign) ZAppConsentAction actionType;
@property (nonatomic, assign) ZAppConsentState state;
@property (nonatomic, retain) NSArray *participantsList;
@property (nonatomic, assign) ZAppMeetingViewType meetingViewType;
@property (nonatomic, retain) NSArray *videoSettingsList;
@property (nonatomic, retain) NSArray *audioSettingsList;
@property (nonatomic, assign) BOOL isMonoAudio;
@property (nonatomic, copy) NSString *speakerDevice;
@property (nonatomic, copy) NSString *micDevice;
@property (nonatomic, assign) double outputVolume;
@property (nonatomic, assign) BOOL isAsyncAction;
@end

@interface ZMZAppAuthInfo : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, assign) ZAppOpenAppMode launchMode;
@property (nonatomic, copy) NSString *installUrl;
@end

@interface ZMZAppAuthorizeResult : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *reason;
@property (nonatomic, copy) NSString *authCode;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, assign) BOOL result;
@end

@interface ZMZAppParticipantInfo : NSObject
@property (nonatomic, assign) NSUInteger userId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, retain) NSImage *avatarImage;
@end

@interface ZMZappConfShareConfigure : NSObject

@property (nonatomic, copy) NSString *messageText;
@property (nonatomic, copy) NSString *primaryButtonText;
@property (nonatomic, copy) NSString *secondaryButtonText;
@property (nonatomic, copy) NSString *htmlPageTitle;
@property (nonatomic, copy) NSString *deeplinkURL;
@property (nonatomic, assign) BOOL isValid;

@end

@interface ZMZAppConfShareInfo : NSObject

@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *shareURL;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, copy) NSString *invitationUUID;
@property (nonatomic, assign) BOOL isFromJs;
@property (nonatomic, assign) BOOL isInImmersiveMode;
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;
@property (nonatomic, retain) ZMZappConfShareConfigure *configure;

- (BOOL)isVaild;

@end

@interface ZMZAppToastInfo : NSObject

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, retain) NSImage *appIcon;
@property (nonatomic, copy) NSString *sentFrom;
@property (nonatomic, retain) ZMZAppConfShareInfo *shareInfo;
@property (nonatomic, copy) NSString *appCompanyName;
@property (nonatomic, retain) NSImage *betaIcon;
@property (nonatomic, assign) BOOL needUpdateIfNeed;
@property (nonatomic, assign) BOOL isSender;
- (BOOL)isNeedCustomUI;

@end

@interface ZMZAppInstallInfo : NSObject

@property (nonatomic, assign) ZMZAppSupportBasicState supportBasicState;
@property (nonatomic, assign) ZMZAppInstallState installState;

@end

@interface ZMZAppCollaborateData : NSObject
@property (nonatomic, assign) ZMZAppCollaborateLaunchPolicyType launchPolicy;
@property (nonatomic, assign) ZMZAppCollaborateChangePolicyType changePolicy;
@property (nonatomic, assign) ZMZAppCollaborateCleanPolicyType cleanPolicy;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, assign) NSUInteger actorId; // who update the content or policy latest
@property (nonatomic, assign) NSUInteger contentActorId; // who update the content latest
@property (nonatomic, assign) NSUInteger appFeature;
@property (nonatomic, assign) ZMZappConfSessionType sessionType;
@end

@protocol ZMZappNotificationDelegate <NSObject>
@optional
- (void)onDefaultButtonClicked;
- (void)onSecondaryButtonClicked;
@end

@interface ZMZAppCollaborateInvitation : NSObject <ZMZappNotificationDelegate>

@property (nonatomic, assign) BOOL isInvitationClicked;
@property (nonatomic, assign) ZMZappCollaborateInvitationStyle style;
@property (nonatomic, copy, nullable) NSString *collaborateAppId;
@property (nonatomic, assign) NSUInteger contentActorId;
@property (nonatomic, assign) ZMZappConfSessionType sessionType;

- (void)resetInvitation;
- (BOOL)isSameCollaboration:(nullable ZMZAppCollaborateData *)collaborateData;

@end

@interface ZMZAppsInteractInfo : NSObject

@property (nonatomic, assign) NSUInteger eventSource;
@property (nonatomic, assign) NSUInteger eventLocation;
@property (nonatomic, assign) NSUInteger eventType;
@property (nonatomic, assign) NSUInteger eventName;
@property (nonatomic, copy, nullable) NSString *eventContext;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *launchTrackingId;
@property (nonatomic, copy, nullable) NSString *appCategory;

@end

@interface ZMZAppVideoSettingsTypes : NSObject

@property (nonatomic, assign) ZAppVideoSettingsType videoSettingsType;

@end

@interface ZMZAppAudioSettingsTypes : NSObject

@property (nonatomic, assign) ZAppAudioSettingsType audioSettingsType;

@end

@interface ZMZAppDrawParticipantInfo : NSObject

@property (nonatomic, assign) UInt32 participantId;
@property (nonatomic, assign) NSRect rect;
@property (nonatomic, assign) NSInteger zIndex;
@property (nonatomic, assign) BOOL mirrorVideo;
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;

@end

@interface ZMZAppOpenActionInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, assign) BOOL supportTransferZR;

@property (nonatomic, assign) ZAppOpenAppPurpose openPurpose;
@property (nonatomic, assign) ZAppOpenAppAction openAction;
@property (nonatomic, assign) ZAppOpenAppSource openSource;

@end

@interface ZMZAppDockAppTooltipInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *appDescription;
@property (nonatomic, assign) BOOL isShowTip;
@property (nonatomic, assign) NSInteger posY;

@end

@interface ZMZAppDynamicIndicatorInfo : NSObject

@property (nonatomic, copy, nullable) NSString *text;
@property (nonatomic, copy, nullable) NSString *textColor;
@property (nonatomic, copy, nullable) NSString *borderColor;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *appIconPath;
@property (nonatomic, assign) NSUInteger timeSync;
@property (nonatomic, assign) NSUInteger senderTime;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, assign) NSUInteger senderNodeId;
@property (nonatomic, assign) NSUInteger pauseTime;

@end

@interface ZMZAppShareScreenInfo : NSObject

@property (nonatomic, assign) BOOL zappEnableAudioShare;
@property (nonatomic, assign) BOOL zappEnableVideoShare;
@property (nonatomic, assign) BOOL zappEnableBoShare;

@end
