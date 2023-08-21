//
//  ZMHotkeyConfiguration.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/2/21.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSNotificationName const kZMHotkeyValueDidChanged;

typedef NSString* ZMHotkeyName NS_EXTENSIBLE_STRING_ENUM;

extern ZMHotkeyName const kZMHotkeyJoinMeeting;
extern ZMHotkeyName const kZMHotkeyPushToTalk;
extern ZMHotkeyName const kZMHotkeyPushToBroadcast;
extern ZMHotkeyName const kZMHotkeyStartMeeting;
extern ZMHotkeyName const kZMHotkeyScheduleMeeting;
extern ZMHotkeyName const kZMHotkeyShareScreen;
extern ZMHotkeyName const kZMHotkeyOnOffAudio;
extern ZMHotkeyName const kZMHotkeyOnOffVideo;
extern ZMHotkeyName const kZMHotkeySwitchCamera;
extern ZMHotkeyName const kZMHotkeyOnOffShare;
extern ZMHotkeyName const kZMHotkeyPauseResumeShare;
extern ZMHotkeyName const kZMHotkeyLocalRecord;
extern ZMHotkeyName const kZMHotkeyCloudRecord;
extern ZMHotkeyName const kZMHotkeyPauseResumeRecord;
extern ZMHotkeyName const kZMHotkeyFullScreen;
extern ZMHotkeyName const kZMHotkeySwitchMinimal;
extern ZMHotkeyName const kZMHotkeySwitchDualMonitors;
extern ZMHotkeyName const kZMHotkeyOffAllAudio;
extern ZMHotkeyName const kZMHotkeyOnAllAudio;
extern ZMHotkeyName const kZMHotkeySwitchGallery;
extern ZMHotkeyName const kZMHotkeyPreGallery;
extern ZMHotkeyName const kZMHotkeyNextGallery;
extern ZMHotkeyName const kZMHotkeyParticipants;
extern ZMHotkeyName const kZMHotkeyOnOffChat;
extern ZMHotkeyName const kZMHotkeyOnInvite;
extern ZMHotkeyName const kZMHotkeyCopyInviteLink;
extern ZMHotkeyName const kZMHotkeyToggleHand;
extern ZMHotkeyName const kZMHotkeyGainRemoteControl;
extern ZMHotkeyName const kZMHotkeyStopRemoteControl;
extern ZMHotkeyName const kZMHotkeyJumpToChat;
extern ZMHotkeyName const kZMHotkeyCloseWindow;
extern ZMHotkeyName const kZMHotkeyScreenShot;
extern ZMHotkeyName const kZMHotkeySwitchPortraitView;
extern ZMHotkeyName const kZMHotkeyShowHideFitbar;
extern ZMHotkeyName const kZMHotkeyShowHideFitbarEscGlobal;
extern ZMHotkeyName const kZMHotkeyMeetingControl;
extern ZMHotkeyName const kZMHotkeyInterpreterSwitchLanguage;
extern ZMHotkeyName const kZMHotkeyReadAcitiveSpeakerName;
extern ZMHotkeyName const kZMHotkeyZoomIn;
extern ZMHotkeyName const kZMHotkeyZoomOut;
extern ZMHotkeyName const kZMHotkeyInitiateCall;
extern ZMHotkeyName const kZMHotkeyAcceptCall;
extern ZMHotkeyName const kZMHotkeyDeclineCall;
extern ZMHotkeyName const kZMHotkeyEndCall;
extern ZMHotkeyName const kZMHotkeyMuteCall;
extern ZMHotkeyName const kZMHotkeyHoldCall;
extern ZMHotkeyName const kZMHotkeyTransferCall;

extern ZMHotkeyName const kZMHotkeySelectPreviousChat; //ZOOM-108082 //210835
extern ZMHotkeyName const kZMHotkeySelectNextChat; //ZOOM-108082 //210835
extern ZMHotkeyName const kZMHotkeyNewChat;
extern ZMHotkeyName const kZMHotkeySearch;
extern ZMHotkeyName const kZMHotkeyAddGroupMembers;
extern ZMHotkeyName const kZMHotkeyFocusMasterList;
extern ZMHotkeyName const kZMHotkeyFocusStartOfUnreadMessage;
extern ZMHotkeyName const kZMHotkeyFocusMostRecentReceiveMsg;
extern ZMHotkeyName const kZMHotkeyCollapseAll;
extern ZMHotkeyName const kZMHotkeyNetworkDiagnosticTool;

@interface ZMHotkeyConfiguration : NSObject
+ (NSArray<ZMHotkeyName>*)hotkeyNameArray;
+ (BOOL)getHotkeyState:(ZMHotkeyName)hkIdentifier global:(BOOL)isGlobal;
+ (NSArray<NSDictionary*>*)defaultHotkeyArray;
+ (NSArray<NSDictionary*>*)customHotkeyArray:(BOOL)isGlobal;
+ (NSArray<ZMHotkeyName>*)supportGlobalHotkeyNameArray;
+ (void)restoreDefaults;
+ (NSDictionary*)hotkeyInfo:(ZMHotkeyName)hotkeyName global:(BOOL)isGlobal;
+ (void)saveHotkey:(ZMHotkeyName)hotkeyName global:(BOOL)isGlobal hotkey:(NSDictionary*)hotkey;
@end
