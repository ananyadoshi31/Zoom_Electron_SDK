/**
 * @alias ZOOM_TYPE_OS_TYPE
 * @readonly
 * @enum {Number}
 */
const ZOOM_TYPE_OS_TYPE = {
  WIN_OS: 0,
  MAC_OS: 1
};

/**
 * @alias ZoomSDK_LANGUAGE_ID
 * @readonly
 * @enum {Number}
 */
const ZoomSDK_LANGUAGE_ID = {
  /** 0, For initialization */
  LANGUAGE_Unknow: 0,
  /** 1, In English */
  LANGUAGE_English: 1,
  /** 2, In simplified Chinese */
  LANGUAGE_Chinese_Simplified: 2,
  /** 3, In traditional Chinese */
  LANGUAGE_Chinese_Traditional: 3,
  /** 4, In Japanese */
  LANGUAGE_Japanese: 4,
  /** 5, In Spanish */
  LANGUAGE_Spanish: 5,
  /** 6, In German */
  LANGUAGE_German: 6,
  /** 7, In French */
  LANGUAGE_French: 7,
  /** 8, In Portuguese */
  LANGUAGE_Portuguese: 8,
  /** 9, In Russian */
  LANGUAGE_Russian: 9,
  /** 10, In Korean */
  LANGUAGE_Korean: 10,
  /** 11, In Vietnamese */
  LANGUAGE_Vietnamese: 11,
  /** 12, In Vietnamese */
  LANGUAGE_Italian: 12,
  /** 13, In Polish */
  LANGUAGE_Polish: 13,
  /** 14, In Turkish */
  LANGUAGE_Turkish: 14,
  /** 15, In Indonesian */
  LANGUAGE_Indonesian: 15,
  /** 16, In Dutch */
  LANGUAGE_Dutch:16
};

/**
 * @alias ZoomSDKError
 * @readonly
 * @enum {Number}
 */
const ZoomSDKError = {
  /** 0, Success Result */
  SDKERR_SUCCESS: 0,
  /** 1, Not support this feature now */
  SDKERR_NO_IMPL: 1,
  /** 2, Wrong useage about this feature */
  SDKERR_WRONG_USEAGE: 2, //
  /** 3, Wrong parameter */
  SDKERR_INVALID_PARAMETER: 3,
  /** 4, Load module failed */
  SDKERR_MODULE_LOAD_FAILED: 4,
  /** 5, No memory allocated */
  SDKERR_MEMORY_FAILED: 5,
  /** 6, Internal service error */
  SDKERR_SERVICE_FAILED: 6,
  /** 7, Not initialize before use */
  SDKERR_UNINITIALIZE: 7,
  /** 8, Not Authentication before use */
  SDKERR_UNAUTHENTICATION: 8,
  /** 9, No recording in process */
  SDKERR_NORECORDINGINPROCESS: 9,
  /** 10, can't find transcoder module */
  SDKERR_TRANSCODER_NOFOUND: 10,
  /** 11, Video service not ready */
  SDKERR_VIDEO_NOTREADY: 11,
  /** 12, No premission to do this */
  SDKERR_NO_PERMISSION: 12,
  /** 13, Unknown error */
  SDKERR_UNKNOWN: 13,
  /** 14, The other instance of the SDK is in process. */
  SDKERR_OTHER_SDK_INSTANCE_RUNNING: 14,
  /** 15, SDK internal error. */
  SDKERR_INTELNAL_ERROR: 15,
  /** 16, No audio device found. */
  SDKERR_NO_AUDIODEVICE_ISFOUND: 16,
  /** 17, No video device found. */
  SDKERR_NO_VIDEODEVICE_ISFOUND: 17,
  /** 18, API calls too frequently. */
  SDKERR_TOO_FREQUENT_CALL: 18,
  /** 19, User can't be assigned with new privilege. */
  SDKERR_FAIL_ASSIGN_USER_PRIVILEGE: 19,
  /** 20, The current meeting doesn't support the feature. */
  SDKERR_MEETING_DONT_SUPPORT_FEATURE: 20,
  /** 21, The current user is not the presenter. */
  SDKERR_MEETING_NOT_SHARE_SENDER: 21,
  /** 22, There is no sharing. */
  SDKERR_MEETING_YOU_HAVE_NO_SHARE: 22,
  /** 23, Incorrect ViewType parameters. */
  SDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG: 23,
  /** 24, Annotation is disabled. */
  SDKERR_MEETING_ANNOTATION_IS_OFF: 24,
  /** 25, Current OS doesn't support the setting. */
  SDKERR_SETTING_OS_DONT_SUPPORT: 25,
  /** 26, Email login is disable */
  SDKERR_EMAIL_LOGIN_IS_DISABLED: 26,
  /** 27, Computer doesn't meet the minimum requirements to use virtual background feature.*/
  SDKERR_HARDWARE_NOT_MEET_FOR_VB: 27,
  /** 28, Need process disclaimer. */
	SDKERR_NEED_USER_CONFIRM_RECORD_DISCLAIMER: 28,
  /** 29, There is no raw data of sharing. */
	SDKERR_NO_SHARE_DATA: 29,
	SDKERR_SHARE_CANNOT_SUBSCRIBE_MYSELF: 30
};

/**
 * @alias ZoomAPPLocale
 * @readonly
 * @enum {Number}
 */
const ZoomAPPLocale = {
  SDK_APP_Locale_Default: 0,
  SDK_APP_Locale_CN: 1,
};

/**
 * @alias ZoomAuthResult
 * @readonly
 * @enum {Number}
 */
const ZoomAuthResult = {
  /** 0, Authentication is successful */
  AUTHRET_SUCCESS: 0,
  /** 1, The key or secret to authenticate is empty */
  AUTHRET_KEYORSECRETEMPTY: 1,
  /** 2, The key or secret to authenticate is wrong */
  AUTHRET_KEYORSECRETWRONG: 2,
  /** 3, The user account does not support */
  AUTHRET_ACCOUNTNOTSUPPORT: 3,
  /** 4, The user account is not enabled for SDK */
  AUTHRET_ACCOUNTNOTENABLESDK: 4,
  /** 5, Unknown error */
  AUTHRET_UNKNOWN: 5,
  /** 6, Service is busy */
  AUTHRET_SERVICE_BUSY: 6,
  /** 7, Initial status */
  AUTHRET_NONE: 7,
  /** 8, Time out */
  AUTHRET_OVERTIME: 8,
  /** 9, Network issues */
  AUTHRET_NETWORKISSUE: 9,
  /** 10, Account does not support this SDK version */
  AUTHRET_CLIENT_INCOMPATIBLE: 10,
  /** 11, The jwt token to authenticate is wrong */
  AUTHRET_JWTTOKENWRONG: 11
};

/**
 * @alias ZoomLanguageType
 * @readonly
 * @enum {Number}
 */
const ZoomLanguageType = {
  /** 0, No use of the custom resource. */
  CustomizedLanguage_None: 0,
  /** 1, Use the specified file path to assign the custom resource. */
  CustomizedLanguage_FilePath: 1,
  /** 2, Use the specified content to assign the custom resource. */
  CustomizedLanguage_Content: 2
};

/**
 * @alias ZoomLoginStatus
 * @readonly
 * @enum {Number}
 */
const ZoomLoginStatus = {
  /** 0, Not login */
  LOGIN_IDLE: 0,
  /** 1, Login in processing */
  LOGIN_PROCESSING: 1,
  /** 2, Login success */
  LOGIN_SUCCESS: 2,
  /** 3, Login failed */
  LOGIN_FAILED: 3
};

/**
 * @alias ZoomLoginType
 * @readonly
 * @enum {Number}
 */
const ZoomLoginType = {
  /** 0, Unknown type. */
  LoginType_Unknown: 0,
  /** 1, Login with work mailbox. */
  LoginType_Email: 1,
  /** 2, Login with SSO token. */
  LoginType_SSO: 2
};

/**
 * @alias ZoomMeetingStatus
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingStatus = {
  /** 0, Idle status, no meeting running */
  MEETING_STATUS_IDLE: 0,
  /** 1, Connecting meeting server status */
  MEETING_STATUS_CONNECTING: 1,
  /** 2, Waiting for host to start meeting */
  MEETING_STATUS_WAITINGFORHOST: 2, //
  /** 3, Meeting is ready, in meeting status */
  MEETING_STATUS_INMEETING: 3,
  /** 4, Disconnecting meeting server status */
  MEETING_STATUS_DISCONNECTING: 4,
  /** 5, Reconnecting meeting server status */
  MEETING_STATUS_RECONNECTING: 5,
  /** 6, Meeting connection error */
  MEETING_STATUS_FAILED: 6,
  /** 7, Meeting is ended */
  MEETING_STATUS_ENDED: 7,
  /** 8, Unknown status. */
  MEETING_STATUS_UNKNOW: 8,
  /** 9, Meeting is locked to prevent the further participants to join the meeting. */
  MEETING_STATUS_LOCKED: 9,
  /** 10, Meeting is open and participants can join the meeting. */
  MEETING_STATUS_UNLOCKED: 10,
  /** 11, Participants who join the meeting before the start are in the waiting room. */
  MEETING_STATUS_IN_WAITING_ROOM: 11,
  /** 12, Upgrade the attendees to panelist in webinar. */
  MEETING_STATUS_WEBINAR_PROMOTE: 12,
  /** 13, Downgrade the attendees from the panelist. */
  MEETING_STATUS_WEBINAR_DEPROMOTE: 13,
  /** 14, Join the breakout room. */
  MEETING_STATUS_JOIN_BREAKOUT_ROOM: 14,
  /** 15, Leave the breakout room. */
  MEETING_STATUS_LEAVE_BREAKOUT_ROOM: 15,
  /** 16, Audio is ready. */
  MEETING_STATUS_AUDIO_READY: 16,
  /** 17, Other meeting is in progress. */
  MEETING_STATUS_OTHER_MEETING_INPROGRESS: 17
};

/**
 * @alias ZoomSDKUserType
 * @readonly
 * @enum {Number}
 */
const ZoomSDKUserType = {
  /** 100, Type of ordinary user who needs to login. */
  SDK_UT_NORMALUSER: 100, // Type of ordinary user who needs to login.
  /** 101, Start meeting without login. */
  SDK_UT_WITHOUT_LOGIN: 101
};

/**
 * @alias ZoomUserType
 * @readonly
 * @enum {Number}
 */
const ZoomUserType = {
  /** 0, API user. */
  ZoomUserType_APIUSER: 0,
  /** 1, User logged in with email. */
  ZoomUserType_EMAIL_LOGIN: 1,
  /** 2, User logged in with Facebook. */
  ZoomUserType_FACEBOOK: 2,
  /** 3, User logged in with Google. */
  ZoomUserType_GoogleOAuth: 3,
  /** 4, User logged in with SSO. */
  ZoomUserType_SSO: 4,
  /** 5, User of unknown type. */
  ZoomUserType_Unknown: 5
};

/**
 * @alias LeaveMeetingCmd
 * @readonly
 * @enum {Number}
 */
const LeaveMeetingCmd = {
  /** 0, Leave meeting */
  LEAVE_MEETING: 0,
  /** 1, End meeting */
  END_MEETING: 1
};

/**
 * @alias MeetingType
 * @readonly
 * @enum {Number}
 */
const MeetingType = {
  /** 0, For initialization. */
  MEETING_TYPE_NONE: 0,
  /** 1, Ordinary meeting. */
  MEETING_TYPE_NORMAL: 1,
  /** 2, Webinar. */
  MEETING_TYPE_WEBINAR: 2,
  /** 3, Breakout meeting. */
  MEETING_TYPE_BREAKOUTROOM: 3
};

/**
 * @alias ZoomMeetingFailCode
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingFailCode = {
  /** 0, Start meeting successfully. */
  MEETING_SUCCESS: 0,
  /** 1, Network error. */
  MEETING_FAIL_NETWORK_ERR: 1,
  /** 2, Reconnect error. */
  MEETING_FAIL_RECONNECT_ERR: 2,
  /** 3, Multi-media Router error. */
  MEETING_FAIL_MMR_ERR: 3,
  /** 4, Password is wrong. */
  MEETING_FAIL_PASSWORD_ERR: 4,
  /** 5, Session error. */
  MEETING_FAIL_SESSION_ERR: 5,
  /** 6, Meeting is over. */
  MEETING_FAIL_MEETING_OVER: 6,
  /** 7, Meeting has not begin. */
  MEETING_FAIL_MEETING_NOT_START: 7,
  /** 8, Meeting does not exist. */
  MEETING_FAIL_MEETING_NOT_EXIST: 8,
  /** 9, The capacity of meeting is full. */
  MEETING_FAIL_MEETING_USER_FULL: 9,
  /** 10, The client is incompatible. */
  MEETING_FAIL_CLIENT_INCOMPATIBLE: 10,
  /** 11, The Multi-media router is not founded.  */
  MEETING_FAIL_NO_MMR: 11,
  /** 12, The meeting is locked. */
  MEETING_FAIL_CONFLOCKED: 12,
  /** 13, The meeting is failed because of the restriction by the same account. */
  MEETING_FAIL_MEETING_RESTRICTED: 13,
  /** 14, The meeting is restricted by the same account while the attendee is allowed to join before the host. */
  MEETING_FAIL_MEETING_RESTRICTED_JBH: 14,
  /** 15, Unable to send web request. */
  MEETING_FAIL_CANNOT_EMIT_WEBREQUEST: 15,
  /** 16, The token is expired. */
  MEETING_FAIL_CANNOT_START_TOKENEXPIRE: 16,
  /** 17, Video hardware or software error. */
  SESSION_VIDEO_ERR: 17,
  /** 18, Audio autostart error. */
  SESSION_AUDIO_AUTOSTARTERR: 18,
  /** 19, The number of webinar registered has reached the upper limit. */
  MEETING_FAIL_REGISTERWEBINAR_FULL: 19,
  /** 20, Register webinar with the role of webinar host. */
  MEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER: 20,
  /** 21, Register webinar with the role of panelist member. */
  MEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER: 21,
  /** 22, Register webinar with the denied email. */
  MEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL: 22,
  /** 23, Webinar request to login. */
  MEETING_FAIL_ENFORCE_LOGIN: 23,
  /** 24, Invalid for Windows SDK. */
  MEETING_FAIL_ZC_CERTIFICATE_CHANGED: 24,
  /** 27, Vanity conference ID does not exist. */
  MEETING_FAIL_VANITY_NOT_EXIST: 27,
  /** 28, Join webinar with the same email. */
  MEETING_FAIL_JOIN_WEBINAR_WITHSAMEEMAIL: 28, // Join webinar with the same email.
  /** 29, Meeting settings is not allowed to start a meeting. */
  MEETING_FAIL_DISALLOW_HOST_MEETING: 29,
  /** 50, Failed to write configure file. */
  MEETING_FAIL_WRITE_CONFIG_FILE: 50,
  /** 60, Forbidden to join the internal meeting. */
  MEETING_FAIL_FORBID_TO_JOIN_INTERNAL_MEETING: 60,
  /** 61, Removed by the host. */
  MEETING_FAIL_REMOVEDBYHOST: 61,
  /** 62, Forbidden to join meeting. */
  MEETING_FAIL_HOST_DISALLOW_OUTSIDE_USER_JOIN: 62,
  /** 500, App join token error. */
  MEETING_FAIL_APP_PRIVILEGE_TOKEN_ERROR: 500,
  /** 1143, Jmak user email not match. */
  MEETING_FAIL_JMAK_USER_EMAIL_NOT_MATCH: 1143
};

/**
 * @alias MeetingEndReason
 * @readonly
 * @enum {Number}
 */
const MeetingEndReason = {
  /** 0, For initialization. */
  EndMeetingReason_None: 0,
  /** 1, Kicked by host. */
  EndMeetingReason_KickByHost: 1,
  /** 2, Ended by host. */
  EndMeetingReason_EndByHost: 2,
  /** 3, JBH times out. */
  EndMeetingReason_JBHTimeOut: 3,
  /** 4, No attendee. */
  EndMeetingReason_NoAttendee: 4,
  /** 5, Host starts another meeting. */
  EndMeetingReason_HostStartAnotherMeeting: 5,
  /** 6, Free meeting times out. */
  EndMeetingReason_FreeMeetingTimeOut: 6,
  /** 7, Network is broken. */
  EndMeetingReason_NetworkBroken: 7
};

/**
 * @alias ZoomMeetingUIFloatVideoType
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingUIFloatVideoType = {
  FLOATVIDEO_List: 0,
  FLOATVIDEO_Small: 1,
  FLOATVIDEO_Large: 2,
  FLOATVIDEO_Minimize: 3
};

/**
 * @alias SDKViewType
 * @readonly
 * @enum {Number}
 */
const SDKViewType = {
  /** 0, Primary displayer. */
  SDK_FIRST_VIEW: 0,
  /** 1, Secondary displayer. */
  SDK_SECOND_VIEW: 1,
  SDK_SEND_SHARE_VIEW: 2
};

/**
 * @alias ZoomMeetingButtonType
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingButtonType = {
  ButtonType_ToolBarParticipant: 0,
  ButtonType_ToolBarShare: 1,
  ButtonType_ToolBarInvite: 2,
};

/**
 * @alias ZoomMeetingUIViewType
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingUIViewType = {
  MEETINGUI_FIRST_MONITOR: 0,
  MEETINGUI_SECOND_MONITOR: 1,
};

/**
 * @alias ZoomAnnotationToolType
 * @readonly
 * @enum {Number}
 */
const ZoomAnnotationToolType = {
  /** 0, Switch to mouse cursor. */
  ANNOTOOL_NONE_DRAWING: 0,
  /** 1, Pen. */
  ANNOTOOL_PEN: 1,
  /** 2, Highlighter. */
  ANNOTOOL_HIGHLIGHTER: 2,
  /** 3, A straight line changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_LINE: 3,
  /** 4, A rectangle changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_RECTANGLE: 4,
  /** 5, An ellipse changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_ELLIPSE: 5,
  /** 6, An arrow changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_ARROW: 6,
  /** 7, A filled rectangle. */
  ANNOTOOL_AUTO_RECTANGLE_FILL: 7,
  /** 8, A filled ellipse. */
  ANNOTOOL_AUTO_ELLIPSE_FILL: 8,
  /** 9, Laser pointer. */
  ANNOTOOL_SPOTLIGHT: 9,
  /** 10, An arrow showing the name of whom click on the sharing content. */
  ANNOTOOL_ARROW: 10,
  /** 11, earser */
  ANNOTOOL_ERASER: 11,
  /** 12, Insert a textbox in order to input letters. */
  ANNOTOOL_TEXTBOX: 12,
  /** 13, Select the annotations. */
  ANNOTOOL_PICKER: 13,
  /** 14, A fair rectangle changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_RECTANGLE_SEMI_FILL: 14,
  /** 15, A fair ellipse changes automatically in pace with the mouse cursor. */
  ANNOTOOL_AUTO_ELLIPSE_SEMI_FILL: 15,
  /** 16, A line with double-arrow. */
  ANNOTOOL_AUTO_DOUBLE_ARROW: 16,
  /** 17, An unfilled rhombus. */
  ANNOTOOL_AUTO_DIAMOND: 17,
  /** 18, A fixed-size arrow for marking. */
  ANNOTOOL_AUTO_STAMP_ARROW: 18,
  /** 19, A sign marking that something is correct. */
  ANNOTOOL_AUTO_STAMP_CHECK: 19,
  /** 20, A sign marking that something is wrong. */
  ANNOTOOL_AUTO_STAMP_X: 20,
  /** 21, A star for marking. */
  ANNOTOOL_AUTO_STAMP_STAR: 21,
  /** 22, A heart for marking. */
  ANNOTOOL_AUTO_STAMP_HEART: 22,
  /** 23, A sign for interrogation. */
  ANNOTOOL_AUTO_STAMP_QM: 23
};

/**
 * @alias ZoomAnnotationClearType
 * @readonly
 * @enum {Number}
 */
const ZoomAnnotationClearType = {
  /** 0, Clear all annotations. */
  ANNOCLEAR_ALL: 0,
  /** 1, Clear only your own annotations. */
  ANNOCLEAR_SELF: 1,
  /** 2, Clear only the others' annotations. */
  ANNOCLEAR_OTHER: 2
};

/**
 * @alias ZoomMeetingAudioStatus
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingAudioStatus = {
  /** 0, Initialization. */
  Audio_None: 0,
  /** 1, Muted status. */
  Audio_Muted: 1,
  /** 2, Muted by the host. */
  Audio_UnMuted: 2,
  /** 3, Muted by the host. */
  Audio_Muted_ByHost: 3,
  /** 4, Unmuted by the host. */
  Audio_UnMuted_ByHost: 4,
  /** 5, The host mutes all. */
  Audio_MutedAll_ByHost: 5,
  /** 6, The host unmutes all. */
  Audio_UnMutedAll_ByHost: 6,
};

/**
 * @alias ZoomMeetingVideoStatus
 * @readonly
 * @enum {Number}
 */
const ZoomMeetingVideoStatus = {
  /** 0, Video is on. */
  Video_ON: 0,
  /** 1, Video is off. */
  Video_OFF: 1,
};

/**
 * @alias ConnectionQuality
 * @readonly
 * @enum {Number}
 */
const ConnectionQuality = {
  /** 0, Unknown connection status */
  Conn_Quality_Unknow: 0,
  /** 1, The connection quality is very poor. */
  Conn_Quality_Very_Bad: 1,
  /** 2, The connection quality is poor. */
  Conn_Quality_Bad: 2,
  /** 3, The connection quality is not good. */
  Conn_Quality_Not_Good: 3,
  /** 4, The connection quality is normal. */
  Conn_Quality_Normal: 4,
  /** 5, The connection quality is good. */
  Conn_Quality_Good: 5,
  /** 6, The connection quality is excellent. */
  Conn_Quality_Excellent: 6
};

/**
 * @alias ZoomH323deviceType
 * @readonly
 * @enum {Number}
 */
const ZoomH323deviceType = {
  /** 0, Unknown device, only for initialization. */
  H323DeviceType_Unknown: 0,
  /** 1, H.323 device. */
  H323DeviceType_H323: 1,
  /** 2, SIP device. */
  H323DeviceType_SIP: 2,
  /** 3, H.323 device and SIP device. */
  H323DeviceType_BOTH: 3
};

/**
 * @alias ZoomH323CalloutStatus
 * @readonly
 * @enum {Number}
 */
const ZoomH323CalloutStatus = {
  /** 0, Used only for initialization. */
  H323Callout_Unknown: 0,
  /** 1, Call successfully. */
  H323Callout_Success: 1,
  /** 2, Bell during the call. */
  H323Callout_Ring: 2,
  /** 3, Call timeout. */
  H323Callout_Timeout: 3,
  /** 4, Call fails. */
  H323Callout_Failed: 4,
  /** 5, Busy */
  H323Callout_Busy: 5,
  /** 6, Decline */
  H323Callout_Decline: 6
};

/**
 * @alias MeetingReminderType
 * @readonly
 * @enum {Number}
 */
const MeetingReminderType = {
  /** 0, host */
  MeetingReminderType_CanFreeTrial: 0,
  MeetingReminderType_CanUpgradeAccount: 1,
  /** 2, guest */
  MeetingReminderType_GuestReminder: 2,
  MeetingReminderType_UpgradeSuccess: 3,
  MeetingReminderType_UpgradeFailed: 4,
  MeetingReminderType_None: 5
};

/**
 * @alias RawDataMemoryMode
 * @readonly
 * @enum {Number}
 */
const RawDataMemoryMode = {
  RawDataMemoryMode_Stack: 0,
  RawDataMemoryMode_Heap: 1
};

/**
 * @alias RawDataResolution
 * @readonly
 * @enum {Number}
 */
const RawDataResolution = {
  RawDataResolution_90: 0,
  RawDataResolution_180: 1,
  RawDataResolution_360: 2,
  RawDataResolution_720: 3,
  RawDataResolution_1080: 4
};

/**
 * @alias VideoStatus
 * @readonly
 * @enum {Number}
 */
const VideoStatus = {
  /** 0, Video is on. */
  Video_ON: 0,
  /** 1, Video is off. */
  Video_OFF: 1
};

/**
 * @alias SDKRawDataError
 * @readonly
 * @enum {Number}
 */
const SDKRawDataError = {
  SDKRawDataError_SUCCESS: 0,
  SDKRawDataError_UNINITIALIZED: 1,
  SDKRawDataError_MALLOC_FAILED: 2,
  SDKRawDataError_WRONGUSAGE: 3,
  SDKRawDataError_INVALID_PARAM: 4,
  SDKRawDataError_NOT_IN_MEETING: 5,
  SDKRawDataError_NO_LICENSE: 6,
  SDKRawDataError_VIDEO_MODULE_NOT_READY: 7,
  SDKRawDataError_VIDEO_MODULE_ERROR: 8,
  SDKRawDataError_VIDEO_DEVICE_ERROR: 9,
  SDKRawDataError_NO_VIDEO_DATA: 10,
  SDKRawDataError_SHARE_MODULE_NOT_READY: 11,
  SDKRawDataError_SHARE_MODULE_ERROR: 12,
  SDKRawDataError_NO_SHARE_DATA: 13,
  SDKRawDataError_AUDIO_MODULE_NOT_READY: 14,
  SDKRawDataError_AUDIO_MODULE_ERROR: 15,
  SDKRawDataError_NO_AUDIO_DATA: 16,
};

/**
 * @alias ShareStatus
 * @readonly
 * @enum {Number}
 */
const ShareStatus = {
  /** 0, For initialization. */
  Sharing_None: 0,
  /** 1, Begin to share by the user himself. */
  Sharing_Self_Send_Begin: 1,
  /** 2, Stop sharing by the user. */
  Sharing_Self_Send_End: 2,
  /** 3, Others begin to share. */
  Sharing_Other_Share_Begin: 3,
  /** 4, Others stop sharing. */
  Sharing_Other_Share_End: 4,
  /** 5, View the sharing of others. */
  Sharing_View_Other_Sharing: 5,
  /** 6, Pause sharing. */
  Sharing_Pause: 6,
  /** 7, Resume sharing. */
  Sharing_Resume: 7,
  /** 8, Sharing content changes. */
  Sharing_ContentTypeChange: 8,
  /** 9, The current user begins to share the sounds of computer audio. */
  Sharing_SelfStartAudioShare: 9,
  /** 10, The current user stops to share the sounds of computer audio. */
  Sharing_SelfStopAudioShare: 10,
  /** 11, Other user begins to share the sounds of computer audio. */
  Sharing_OtherStartAudioShare: 11,
  /** 12, Other user stops to share the sounds of computer audio. */
  Sharing_OtherStopAudioShare: 12
};

/**
 * @alias SettingTabPage
 * @readonly
 * @enum {Number}
 */
const SettingTabPage = {
  /** 0, General setting page. */
  SettingTabPage_General: 0,
  /** 1, Audio setting page. */
  SettingTabPage_Audio: 1,
  /** 2, Video setting page. */
  SettingTabPage_Video: 2
};

/**
 * @alias SDKMinimizeUIMode
 * @readonly
 * @enum {Number}
 */
const SDKMinimizeUIMode = {
  /** 0, For initialization. */
  MinimizeUIMode_NONE: 0,
  /** 1, Minimized mode for sharing. */
  MinimizeUIMode_SHARE: 1,
  /** 2, Minimized mode for video. */
  MinimizeUIMode_VIDEO: 2,
  /** 3, Minimized mode for speaking. */
  MinimizeUIMode_ACTIVESPEAKER: 3
};

/**
 * @alias SMSVerificationCodeErr
 * @readonly
 * @enum {Number}
 */
const SMSVerificationCodeErr = {
  /** 0, For initialization. */
  SMSVerificationCodeErr_Unknown: 0,
  /** 1, Success. */
  SMSVerificationCodeErr_Success: 1,
  /** 2, Send SMS Failed. */
  SMSVerificationCodeErr_Retrieve_SendSMSFailed: 2,
  /** 3, Invalid phone number. */
  SMSVerificationCodeErr_Retrieve_InvalidPhoneNum: 3,
  /** 4, The phone number is already bound. */
  SMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound: 4,
  /** 5, Send phone number too frequently. */
  SMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent: 5,
  /** 6, Verification code is incorrect. */
  SMSVerificationCodeErr_Verify_CodeIncorrect: 6,
  /** 7, Verification code is expired. */
  SMSVerificationCodeErr_Verify_CodeExpired: 7,
  /** 8, Unknown error for verification. */
  SMSVerificationCodeErr_Verify_UnknownError: 8
};

/**
 * @alias SDKInviteDlgTabPage
 * @readonly
 * @enum {Number}
 */
const SDKInviteDlgTabPage = {
  /** 0, Invite by Email' tab page */
  SDK_INVITEDLG_TAB_EMAILCONTACT: 0,
  /** 1, Invite by Phone' tab pag */
  SDK_INVITEDLG_TAB_PHONECONTACT: 1,
  /** 2, Invite a Room System' tab page */
  SDK_INVITEDLG_TAB_ROOMSYSTEM: 2
};

/**
 * @alias SDKH323TabPage
 * @readonly
 * @enum {Number}
 */
const SDKH323TabPage = {
  /** 0, Dial In' sub-tab page under Room System invitation tab page */
  SDK_INVITEDLG_H323_DIALIN: 0,
  /** 1, Call Out' sub-tab page under Room System invitation tab page */
  SDK_INVITEDLG_H323_CALLOUT: 1
};

/**
 * @alias SettingsNetWorkType
 * @readonly
 * @enum {Number}
 */
const SettingsNetWorkType = {
  /** 0, Wired LAN */
  SETTINGS_NETWORK_WIRED: 0,
  /** 1, WIFI */
  SETTINGS_NETWORK_WIFI: 1,
  /** 2, PPP */
  SETTINGS_NETWORK_PPP: 2,
  /** 3, 3G */
  SETTINGS_NETWORK_3G: 3,
  /** 4, Others */
  SETTINGS_NETWORK_OTHERS: 4,
  /** 5, Unknown network. */
  SETTINGS_NETWORK_UNKNOWN: -1
};

/**
 * @alias SettingConnectionType
 * @readonly
 * @enum {Number}
 */
const SettingConnectionType = {
  /** 0, Cloud connection. */
  SETTINGS_CONNECTION_TYPE_CLOUD: 0,
  /** 1, Direct connection. */
  SETTINGS_CONNECTION_TYPE_DIRECT: 1,
  /** -1, Unknown connection. */
  SETTINGS_CONNECTION_TYPE_UNKNOWN: -1
};

/**
 * @alias SDKCustomizedStringType
 * @readonly
 * @enum {Number}
 */
const SDKCustomizedStringType = {
  /** 0, The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item ON %S on live streaming. */
  SDK_Customized_LiveStream_MenuString_LiveOn_String: 0,
  /** 1, The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item VIEW STREAM ON %S on live streaming. */
  SDK_Customized_LiveStream_MenuString_LiveView_String: 1,
  /** 2, The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item STOP LIVE STREAM on live streaming. */
  SDK_Customized_LiveStream_MenuString_LiveStop_String: 2,
  /** 3, The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item COPY STREAMING LINK on live streaming. */
  SDK_Customized_LiveStream_MenuString_CopyURL_String: 3,
  /** 4, The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI. */
  SDK_Customized_Title_App: 4,
  /** 5, The new string must be the same format as "Zoom Participant ID: %s Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI. */
  SDK_Customized_Title_ZoomVideo: 5,
  /** 6, The new string must be the same format as "Zoom Participant ID: %s  %d-Minutes Meeting ID:%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. */
  SDK_Customized_Title_FreeZoomVideo: 6,
  /** 7, The new string must be the same format as "Zoom %d-Minutes Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. */
  SDK_Customized_Title_ViewOnly_FreeZoomVideo: 7
};

/**
 * @alias SDKCustomizedURLType
 * @readonly
 * @enum {Number}
 */
const SDKCustomizedURLType = {
  /** 0, Set the custom help URL in the virtual background tab page. */
  SDKCustomizedURL_VITRULBG_HELP: 0,
  /** 1, Set the custom Learn More URL in the virtual background tab page. */
  SDKCustomizedURL_VITRULBG_LEARN_MORE: 1,
  /** 2, Set the Support URL in the meeting. */
  SDKCustomizedURL_SUPPORTURL: 2
};

/**
 * @alias RequiredInfoType
 * @readonly
 * @enum {Number}
 */
const RequiredInfoType = {
  /** 0, Initialization. */
  REQUIRED_INFO_TYPE_NONE: 0,
  /** 1, The user needs to enter the password when joins the meeting. Via the InputMeetingPasswordAndScreenName() to specify the password information. */
  REQUIRED_INFO_TYPE_Password: 1,
  /** 2, If the password is invalid, the user needs to re-enter it. Via the InputMeetingPasswordAndScreenName() to specify the password information. */
  REQUIRED_INFO_TYPE_Password4WrongPassword: 2,
  /** 3, The user needs to enter the screen name and the password,via the InputMeetingPasswordAndScreenName() to specify the necessary information. */
  REQUIRED_INFO_TYPE_PasswordAndScreenName: 3,
  /** 4, The user needs to enter the screen name. Via the InputMeetingScreenName() to specify the screen name information. */
  REQUIRED_INFO_TYPE_ScreenName: 4,
  /** 5, The user needs to enter the screen name and the meeting id,via the InputMeetingMeetingIDAndScreenName() to specify the necessary information. */
  REQUIRED_INFO_TYPE_MeetingIDAndScreenName: 5
};

/**
 * @alias WebinarNeedRegisterType
 * @readonly
 * @enum {Number}
 */
const WebinarNeedRegisterType = {
  /** 0, Initialization. */
  WebinarReg_NONE: 0,
  /** 1, Register webinar account by URL. */
  WebinarReg_By_Register_Url: 1,
  /** 2, Register webinar account by email and the screen name. */
  WebinarReg_By_Email_and_DisplayName: 2
};

/**
 * @alias AudioCallbackActionInfo
 * @readonly
 * @enum {Number}
 */
const AudioCallbackActionInfo = {
  /** 0, For initialization. */
  ACTION_INFO_NONE: 0,
  /** 1, Choose audio device because no audio device is connected yet. */
  ACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED: 1,
  /** 2, Choose audio device because there is an error in the connected computer audio device. */
  ACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR: 2,
  /** 3, Choose audio device because there is an error in the connected phone call device. */
  ACTION_INFO_CHOOSE_AUDIO_DEVICE_PHONECALLDEVICEERROR: 3,
  /** 4, Need to join voip. */
  ACTION_INFO_NEED_JOIN_VOIP: 4,
  /** 5, Mute or unmute some user's audio */
  ACTION_INFO_MUTE_UNMUTE_AUDIO: 5,
  /** 6, Show audio setting window. */
  ACTION_INFO_SHOW_AUDIO_SETTING_WINDOW: 6
};

/**
 * @alias RecordingStatus
 * @readonly
 * @enum {Number}
 */
const RecordingStatus = {
  /** 0, Start recording on local computer or on cloud. */
  Recording_Start: 0,
  /** 1, Stop recording on local computer or on cloud. */
  Recording_Stop: 1,
  /** 2, There is no space to store for both local and cloud recording. */
  Recording_DiskFull: 2,
  /** 3, Pause recording on local or on cloud. */
  Recording_Pause: 3,
  /** 4, Connecting, only for cloud recording. */
  Recording_Connecting: 4
};

/**
 * @alias SDKUserInfoType
 * @readonly
 * @enum {Number}
 */
const SDKUserInfoType = {
  REAL_USERINFO: 0,
  FAKE_USERINFO: 1
};

/**
 * @alias CustomizedLanguageType
 * @readonly
 * @enum {Number}
 */
const CustomizedLanguageType = {
  /** 0, No use of the custom resource. */
  CustomizedLanguage_None: 0,
  /** 1, Use the specified file path to assign the custom resource. */
  CustomizedLanguage_FilePath: 1,
  /** 2, Use the specified content to assign the custom resource. */
  CustomizedLanguage_Content: 2
};

/**
 * @alias ZoomSDKRawDataType
 * @readonly
 * @enum {Number}
 */
const ZoomSDKRawDataType = {
  RAW_DATA_TYPE_VIDEO: 0,
  RAW_DATA_TYPE_SHARE: 1
};

/**
 * @alias RawDataStatus
 * @readonly
 * @enum {Number}
 */
const RawDataStatus = {
  RawData_On: 0,
  RawData_Off: 1
};

/**
 * @alias ZoomSDKVideoRenderMode
 * @readonly
 * @enum {Number}
 */
const ZoomSDKVideoRenderMode = {
  SDKVideoRenderMode_None: 0,
  SDKVideoRenderMode_Auto: 1,
  SDKVideoRenderMode_D3D11EnableFLIP: 2,
  SDKVideoRenderMode_D3D11: 3,
  SDKVideoRenderMode_D3D9: 4,
  SDKVideoRenderMode_GDI: 5
};

/**
 * @alias SDKRawDataMemoryMode
 * @readonly
 * @enum {Number}
 */
const SDKRawDataMemoryMode = {
  SDKRawDataMemoryModeStack: 0,
  SDKRawDataMemoryModeHeap: 1
};

/**
 * @alias ZoomSDKVideoCaptureMethod
 * @readonly
 * @enum {Number}
 */
const ZoomSDKVideoCaptureMethod = {
  ZoomSDKVideoCaptureMethod_None: 0,
  ZoomSDKVideoCaptureMethod_Auto: 1,
  ZoomSDKVideoCaptureMethod_DirectSHow: 2,
  ZoomSDKVideoCaptureMethod_MediaFoundation: 3
};

/**
 * @alias ZoomSDKRenderPostProcessing
 * @readonly
 * @enum {Number}
 */
const ZoomSDKRenderPostProcessing = {
  ZoomSDKRenderPostProcessing_None: 0,
  ZoomSDKRenderPostProcessing_Auto: 1,
  ZoomSDKRenderPostProcessing_Enable: 2,
  ZoomSDKRenderPostProcessing_Disable: 3
};

/**
 * @alias ZoomSDKVideoHardwareEncodeType
 * @readonly
 * @enum {Number}
 */
const ZoomSDKVideoHardwareEncodeType = {
  /** 0, Mac platform only has this option */
  VIDEO_HARDWARE_ENCODE_RECEIVING: 0,
  VIDEO_HARDWARE_ENCODE_SENDING: 1,
  VIDEO_HARDWARE_ENCODE_PROCESSING: 2
};

/**
 * @alias ZoomSDKEchoCancelLationLevel
 * @readonly
 * @enum {Number}
 */
const ZoomSDKEchoCancelLationLevel = {
  SDK_ECHO_CANCELLATION_DEFAULT: 0,
  SDK_ECHO_CANCELLATION_AGGRESSIVE: 1
};

/**
 * @alias LoginFailReason
 * @readonly
 * @enum {Number}
 */
const LoginFailReason = {
  LoginFail_None: 0,
  LoginFail_EmailLoginDisable: 1,
  LoginFail_UserNotExist: 2,
  LoginFail_WrongPassword: 3,
  LoginFail_AccountLocked: 4,
  LoginFail_SDKNeedUpdate: 5,
  LoginFail_TooManyFailedAttempts: 6,
  LoginFail_SMSCodeError: 7,
  LoginFail_SMSCodeExpired: 8,
  LoginFail_PhoneNumberFormatInValid: 9,
  LoginFail_LoginTokenInvalid: 10,
  LoginFail_OtherIssue: 100
};

/**
 * @alias DirectShareStatus
 * @readonly
 * @enum {Number}
 */
const DirectShareStatus = {
  /** 0, Only for initialization. */
  DirectShare_Unknown: 0,
  /** 1, Waiting for enabling the direct sharing. */
  DirectShare_Connecting: 1,
  /** 2, In direct sharing mode. */
  DirectShare_In_Direct_Share_Mode: 2,
  /** 3, End the direct sharing. */
  DirectShare_Ended: 3,
  /** 4, Re-enter the meeting ID/paring code. */
  DirectShare_Need_MeetingID_Or_PairingCode: 4,
  /** 5, Network error. Please try again later. */
  DirectShare_NetWork_Error: 5,
  /** 6, Other errors. Mainly occur in SIP call mode. */
  DirectShare_Other_Error: 6,
  DirectShare_WrongMeetingID_Or_SharingKey: 7,
  /** 8, Please input new paring code. */
  DirectShare_InputNewParingCode: 8,
  /** 9, Prepare to share data. */
  DirectShare_Prepared: 9
};

/**
 * @alias FreeMeetingNeedUpgradeType
 * @readonly
 * @enum {Number}
 */
const FreeMeetingNeedUpgradeType = {
  /** 0, Initialization. */
  FreeMeetingNeedUpgradeType_NONE: 0,
  /** 1, It is necessary for administrator to upgrade the free meeting. */
  FreeMeetingNeedUpgradeType_BY_ADMIN: 1,
  /** 2, Upgrade the free meeting by the gift link. */
  FreeMeetingNeedUpgradeType_BY_GIFTURL: 2
};

/**
 * @alias AudioType
 * @readonly
 * @enum {Number}
 */
const AudioType = {
  /** 0, Normal audio type. */
  AUDIOTYPE_NONE: 0,
  /** 1, In VoIP mode. */
  AUDIOTYPE_VOIP: 1,
  /** 2, In telephone mode. */
  AUDIOTYPE_PHONE: 2,
  /** 3, Unknown mode. */
  AUDIOTYPE_UNKNOW: 3
};

/**
 * @alias UserRole
 * @readonly
 * @enum {Number}
 */
const UserRole = {
  /** 0, For initialization. */
  USERROLE_NONE: 0,
  /** 1, Role of the host. */
  USERROLE_HOST: 1,
  /** 2, Role of co-host. */
  USERROLE_COHOST: 2,
  /** 3, Role of the panelist, valid only in webinar. */
  USERROLE_PANELIST: 3,
  /** 4, Host role in breakout room. */
  USERROLE_BREAKOUTROOM_MODERATOR: 4,
  /** 5, Role of attendee. */
  USERROLE_ATTENDEE: 5
};

/**
 * @alias PremeetingAPIResult
 * @readonly
 * @enum {Number}
 */
const PremeetingAPIResult = {
  /** 0, API returns unknown error. */
	PREMETAPIRET_UNKNOW: 0,
  /** 1, Calls API successfully. */
	PREMETAPIRET_SUCCESS: 1
};

/**
 * @alias StatisticsWarningType
 * @readonly
 * @enum {Number}
 */
const StatisticsWarningType = {
  /** 0, No warning. */
	Statistics_Warning_None: 0,
  /** 1, The network connection quality is bad. */
	Statistics_Warning_Network_Quality_Bad: 1,
  /** 2, The system is busy. */
	Statistics_Warning_Busy_System: 2
};

/**
 * @alias AudioShareMode
 * @readonly
 * @enum {Number}
 */
 const AudioShareMode = {
  /** 0, Mono mode. */
	AudioShareMode_Mono: 0,
  /** 1, Stereo mode. */
	AudioShareMode_Stereo: 1
};

/**
 * @alias LiveStreamStatus
 * @readonly
 * @enum {Number}
 */
 const LiveStreamStatus = {
  /** 0, Only for initialization. */
	LiveStreamStatus_None: 0,
  /** 1, In progress. */
	LiveStreamStatus_InProgress: 1,
  /** 2, Be connecting. */
	LiveStreamStatus_Connecting: 2,
  /** 3, Connect timeout. */
	LiveStreamStatus_Start_Failed_Timeout: 3,
  /** 4, Failed to start live streaming. */
	LiveStreamStatus_Start_Failed: 4,
  /** 5, Live stream ends. */
	LiveStreamStatus_Ended: 5
};

module.exports = {
  ZOOM_TYPE_OS_TYPE,
  ZoomSDK_LANGUAGE_ID,
  ZoomSDKError,
  ZoomAPPLocale,
  ZoomAuthResult,
  ZoomLanguageType,
  ZoomLoginStatus,
  ZoomLoginType,
  ZoomMeetingStatus,
  ZoomSDKUserType,
  ZoomUserType,
  LeaveMeetingCmd,
  MeetingType,
  ZoomMeetingFailCode,
  MeetingEndReason,
  ZoomMeetingUIFloatVideoType,
  SDKViewType,
  ZoomMeetingButtonType,
  ZoomMeetingUIViewType,
  ZoomAnnotationToolType,
  ZoomAnnotationClearType,
  ZoomMeetingAudioStatus,
  ZoomMeetingVideoStatus,
  ConnectionQuality,
  ZoomH323deviceType,
  ZoomH323CalloutStatus,
  MeetingReminderType,
  RawDataMemoryMode,
  RawDataResolution,
  VideoStatus,
  SDKRawDataError,
  ShareStatus,
  SettingTabPage,
  SDKMinimizeUIMode,
  SMSVerificationCodeErr,
  SDKInviteDlgTabPage,
  SDKH323TabPage,
  SettingsNetWorkType,
  SettingConnectionType,
  SDKCustomizedStringType,
  SDKCustomizedURLType,
  RequiredInfoType,
  WebinarNeedRegisterType,
  AudioCallbackActionInfo,
  RecordingStatus,
  SDKUserInfoType,
  CustomizedLanguageType,
  ZoomSDKRawDataType,
  RawDataStatus,
  ZoomSDKVideoRenderMode,
  SDKRawDataMemoryMode,
  ZoomSDKVideoCaptureMethod,
  ZoomSDKRenderPostProcessing,
  ZoomSDKVideoHardwareEncodeType,
  ZoomSDKEchoCancelLationLevel,
  LoginFailReason,
  DirectShareStatus,
  FreeMeetingNeedUpgradeType,
  AudioType,
  UserRole,
  PremeetingAPIResult,
  StatisticsWarningType,
  AudioShareMode,
  LiveStreamStatus
};
