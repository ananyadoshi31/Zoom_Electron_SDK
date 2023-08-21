//
//  ZPConfEventHandler.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 1/29/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* kNoti_Param;
extern NSString* kNoti_Param2;
extern NSString* kNoti_Param3;
extern NSString* kNoti_Unknow;
extern NSString* kNoti_Conf_WaitingID;
extern NSString* kNoti_Conf_TryWeb;
extern NSString* kNoti_Conf_UserConfirm;//Confirm the user's screen name
extern NSString* kNoti_Conf_Quality;

extern NSString* kNoti_ShowWaiting;//param1 bShow, param2 NULL
extern NSString* kNoti_PreviewVideo;
extern NSString* kNoti_ConfFail;
extern NSString* kNoti_ConfReady;//param1 ret, param2 NULL
extern NSString* kNoti_Conf_One2One;
extern NSString* kNoti_AudioReady;
extern NSString* kNoti_ConfLeave;
extern NSString* kNoti_AutoStartVideo;
extern NSString* kNoti_Invitation_Sent;
extern NSString* kNoti_EndOtherMeeting;
extern NSString* kNoti_AutoShowAudioSelection;
extern NSString* kNoti_ConfStart;

extern NSString* kNoti_User_VideoStatus;
extern NSString* kNoti_User_ActiveVideo_For_Wall;
extern NSString* kNoti_User_ActiveVideo_For_Deck;
extern NSString* kNoti_User_ActiveVideo_For_2ndView;
extern NSString* kNoti_User_PictureDownloaded;
extern NSString* kNoti_BO_Back_User_PictureDownloaded;
extern NSString* kNoti_My_VideoStatus;
extern NSString* kNoti_User_ActiveVideo;
extern NSString* kNoti_User_ActiveAudio;
extern NSString* kNoti_User_ActiveAudio_For_Wall;
extern NSString* kNoti_User_Join;
extern NSString* kNoti_User_Left;
extern NSString* kNoti_User_Updated;
extern NSString* kNoti_Video_Quality_Changed;
extern NSString* kNoti_User_VideoSizeChanged;
extern NSString* kNoti_User_HostChanged;
extern NSString* kNoti_User_CoHostChanged;
extern NSString* kNoti_User_MyAudioMutedByOther;
extern NSString* kNoti_Host_Request_TurnOn_Video;
extern NSString* kNoti_Attendee_TurnOn_Video_Later;
extern NSString* kNoti_CameraControl_Camera_Type_Changed;

//Conf Action
extern NSString* kNoti_Act_Mute;//Param1 TRUE:Mute, FALSE:Unmute
extern NSString* kNoti_Act_Video;//Param1 TRUE:StartVideo, FALSE:StopVideo
extern NSString* kNoti_Act_Share;//Param1 TRUE:StartShare, FALSE:StopShare
extern NSString* kNoti_Act_Invite;//Param1 NULL, Param2 NULL
extern NSString* kNoti_Act_Annotate;
extern NSString* kNoti_Act_Chat;
extern NSString* kNoti_Act_Quit;
extern NSString* kNoti_Act_GoShare;
extern NSString* kNoti_Act_GoVideo;
extern NSString* kNoti_Act_FullScreen;
extern NSString* kNoti_Act_ExitFullScreen;
extern NSString* kNoti_Act_ShowFIT;
extern NSString* kNoti_Video_OnOff_InSharingOnly;
extern NSString* kNoti_User_ActiveShare;
extern NSString* kNoti_User_ShareReceivingStatus;
extern NSString* kNoti_User_ShareSizeChanged;
extern NSString* kNoti_User_BWchanged;
extern NSString* kNoti_Meeting_LockStatus;
extern NSString* kNoti_Meeting_FreeMeeting_CountDown;
extern NSString* kNoti_ViewOnly_UserCount_Changed;
extern NSString* kNoti_ViewOnly_Telephone_UserCount_Changed;
extern NSString* kNoti_Audio_MuteAll_Changed;
extern NSString* kNoti_Silent_Mode_Changed;
extern NSString* kNoti_Suggest_Using_Telephone;
extern NSString* kNoti_Callout_Status_changed;
extern NSString* kNoti_PairCode_Status_Changed;
extern NSString* kNoti_Video_Mute_By_Host;
extern NSString* kNoti_Webinar_Show_Attendee_Count_Changed;
extern NSString* kNoti_Statistic_Warning;
extern NSString* kNoti_Webinar_Max_Panelist;
extern NSString* kNoti_Practice_Status_Changed;
extern NSString* kNoti_Allow_Attendee_Chat_Changed;
extern NSString* kNoti_Allow_Attendee_RaiseHand_Status_Changed;
extern NSString* kNoti_FECC_Update;
extern NSString* kNoti_Verify_HostKey_Status;
extern NSString* kNoti_Expel_Webinar_Attendee_Result;
extern NSString* kNoti_Roster_Count_Changed;

//Raise Hand
extern NSString* kNoti_Raise_Hand;
extern NSString* kNoti_Lower_Hand;

//Chat
extern NSString* kNoti_Chat_OnMessage;//Param1 *pstrMessageID
extern NSString* kNoti_Chat_OnOpen;
extern NSString* kNoti_chat_fileSended;
extern NSString* kNoti_chat_fileProgressUpdate;
extern NSString* kNoti_chat_fileStateChange;

//Video dock
extern NSString* kNoti_VideoDock_Collapsed;
extern NSString* kNoti_VideoDock_Expanded;
extern NSString* kNoti_Click2View;

//Share capturer status
extern NSString* kNoti_Shared_Window_Closed;
extern NSString* kNoti_Shared_Window_Paused;
extern NSString* kNoti_Shared_Window_Resumed;
extern NSString* kNoti_Shared_Window_Locked;
extern NSString* kNoti_Shared_Screen_Disconnected;//ZOOM-68195
extern NSString* kNoti_Shared_Capture_Process_Quit;//ZOOM-74747

extern NSString* kNoti_Click2Switch;
extern NSString* kNoti_Start_Share_Failed;

//Sharing sending status
extern NSString* kNoti_Sharing_Sending_Status_Changed;

//Payment
extern NSString* kNoti_Payment_Upgrade_Account;
extern NSString* kNoti_Host_Account_Upgraded;
extern NSString* kNoti_Remain_Time;

//Parameter keys
extern NSString* kParam_ConfQuality_Type;
extern NSString* kParam_ConfQuality_Score;
extern NSString* kParam_Roster_Change_User;
extern NSString* kParam_Roster_Change_Flag;

//Join scheduled meeting 
//extern NSString* kNoti_Conf_WaitingPwd;
//extern NSString* kNoti_Conf_CanJoinScheduledMeeting;
//extern NSString* kNoti_Conf_PwdOK;

extern NSString* kNoti_Conf_ConfirmMeetingInfo;
extern NSString* kNoti_Conf_ConfirmPasswordValidateResult;
extern NSString* kNoti_Conf_ConfirmMeetingStatus;
extern NSString* kNoti_Conf_showWaitingUIBeforeMeeting;
extern NSString* kNoti_Conf_hideWaitingUIBeforeMeeting;

extern NSString* kParam_Conf_Result;
extern NSString* kParam_Conf_HasPassword;
extern NSString* kParam_Conf_HasScreenName;
extern NSString* kParam_Conf_NeedWait;
extern NSString* kParam_Conf_CanJoinNow;
extern NSString* kParam_Conf_NoHost;

extern NSString* kNoti_PT_LoginSuccess;
extern NSString* kParam_PT_LoginSuccess_ZoomID;
extern NSString* kParam_PT_LoginSuccess_UserName;
extern NSString* kParam_PT_LoginSuccess_SNSID;
extern NSString* kParam_PT_LoginSuccess_SNSType;

//record
extern NSString* kNoti_Record_Privilege_Change;
extern NSString* kNoti_Record_Error;
extern NSString* kNoti_Record_Status_Change;
extern NSString* kNoti_Record_Auto_Start;
extern NSString* kNoti_Record_CMR_Timeout;

//remote control
extern NSString* kNoti_RemoteControl_Privilege;
extern NSString* kNoti_RemoteControl_Start;
extern NSString* kNoti_RemoteControl_Request_Received;
extern NSString* kNoti_RemoteControl_Abandan_Received;

//annotation
extern NSString* kNoti_Annotation_Root_Wnd_Changed;
extern NSString* kNoti_Annotation_Tool_Changed;
extern NSString* kNoti_Annotation_UndoRedo_Changed;
extern NSString* kNoti_Annotation_Imprint_Changed;
// WB
extern NSString* kNoti_Annotation_Whiteboard_WindowState_Changed;
extern NSString* kNoti_Annotation_Whiteboard_Auto_Save;
extern NSString* kNoti_Annotation_Show_Saved_Info;
extern NSString* kNoti_Annotation_Started_Up;

//Q&A
extern NSString* kNoti_QA_Webinar_Need_Register;

//airhost
extern NSString* kNoti_AirHost_Installed;

//Breakout Session
extern NSString* kNoti_BO_Moderatro_Changed;
extern NSString* kNoti_BO_MasterHost_Available;

//closed caption
extern NSString* kNoti_ClosedCaptionUser_Changed;

//audio device check
extern NSString* kNoti_Show_Audio_Device_Check_Result;
extern NSString* kNoti_Conf_ConfirmVanityURLSelect; //ZOOM-100649
//video share
//ZOOM-73894
extern NSString* kNoti_Video_Share_Hide_Floating_Video;

@interface ZPConfEventHandler : NSObject
+ (void)notify:(NSString*)eventName object:(id)param;
+ (void)notify:(NSString*)eventName dict:(NSDictionary*)dict;
+ (id)parseNotify:(NSNotification*)aNotification;
+ (void)asynNotify:(NSString*)eventName object:(id)param;
+ (void)asynNotify:(NSString*)eventName dict:(NSDictionary*)dict;

@end
