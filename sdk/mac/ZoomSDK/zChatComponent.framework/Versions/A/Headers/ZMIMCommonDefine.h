
//
//  ZMIMCommonDefine.h
//  SaasBeePTUIModule
//
//  Created by ryan on 24/05/2018.
//  Copyright © 2018 Zoom. All rights reserved.
//

#ifndef ZMIMCommonDefine_h
#define ZMIMCommonDefine_h

#import "dataModule/zDataConstants.h"

typedef NS_ENUM(NSUInteger, ZMMessageSrcType) {
    ZMMessageSrcType_NotSet,
    ZMMessageSrcType_MUC,
    ZMMessageSrcType_Channel,
    ZMMessageSrcType_Thread
};

typedef enum {
    ZMSearchFileSourceType_None = 0,
    ZMSearchFileSourceType_IM   = 1,
    ZMSearchFileSourceType_PBX  = 2,
}ZMSearchFileSourceType;

typedef NS_ENUM(NSUInteger, ZMChatsNumberMenuStyle)
{
    ZMChatsNumberMenuStyle_meeting      = 1 << 0,
    ZMChatsNumberMenuStyle_phone      = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMFileStorageType)
{
    FileStorageType_None = 0,
    FileStorageType_ZoomCloud,
    FileStorageType_SharePoint,
    FileStorageType_Box,
};

typedef NS_ENUM (NSUInteger, ZMFileButtonDisabledType)
{
    ZMFileButtonDisabledType_BeyondMaxFileCount = 0,
    ZMFileButtonDisabledType_FTResctricted = 1,
};

enum{
    Filter_None                                         = 0,
    Filter_Not_Contain_ZR                               = 1<<0,
    Filter_Not_Contain_Robot                            = 1<<1,
    Filter_Not_Contain_Pending                          = 1<<2,
    Filter_Not_Contain_RoomDevice                       = 1<<3,
    Filter_Not_Contain_NoSip                            = 1<<4,
    Filter_Not_Contain_GlobalUser                       = 1<<5,
    Filter_Not_Contain_BlockedTerminatedDeactivated     = 1<<6,
    Filter_Not_Contain_MySelf                           = 1<<7,
    Filter_Not_Contain_IMIBBlocked                      = 1<<8,
    Filter_Not_Contain_MeetingIBBlocked                 = 1<<9,
    Filter_Not_Contain_ContactCanNotChat                = 1<<10,
    Filter_Not_Contain_AuditRobot                       = 1<<11
};

typedef NS_ENUM(NSUInteger, ZMIMBuddyPresenceType) {
    ZMIMBuddyPresenceType_none,
    ZMIMBuddyPresenceType_unknow,
    ZMIMBuddyPresenceType_offline,
    ZMIMBuddyPresenceType_desktopOnline,
    ZMIMBuddyPresenceType_mobileOnline,
    ZMIMBuddyPresenceType_pzrOnline,
    ZMIMBuddyPresenceType_pzrAway,
    ZMIMBuddyPresenceType_away,
    ZMIMBuddyPresenceType_dnd,
    ZMIMBuddyPresenceType_inMeeting,
    ZMIMBuddyPresenceType_inZoomMeeting,
    ZMIMBuddyPresenceType_inCall,
    ZMIMBuddyPresenceType_e2e,
    ZMIMBuddyPresenceType_other,
    ZMIMBuddyPresenceType_inZoomMeetingPresenting,
    ZMIMBuddyPresenceType_busy,
    ZMIMBuddyPresenceType_outOfOffice
};

typedef enum ZMUniversalDeepLinkType {
    ZMUniversalDeepLinkType_Indeterminate,
    ZMUniversalDeepLinkType_Channel,
    ZMUniversalDeepLinkType_Message,
} ZMUniversalDeepLinkType;

typedef NS_ENUM(NSUInteger, ZMChatsSessionInfoNotificationType)
{
    ZMChatsSessionInfoNotificationType_All,
    ZMChatsSessionInfoNotificationType_Mention,
    ZMChatsSessionInfoNotificationType_None,
};

typedef NS_ENUM(NSUInteger, ZMSendErrorMessageStatus) {
    ZMSendErrorMessageStatusAdd,
    ZMSendErrorMessageStatusDelete,
    ZMSendErrorMessageStatusRetry,
};

typedef NS_ENUM(NSUInteger, ZMStartRecordStatus) {
    ZMStartRecordSuccess,
    ZMCannotRecordIsInSipCall,
    ZMCannotRecordIsInMeeting,
    ZMCannotRecordIsMicDeviceUnavailable,
    ZMCannotRecordIsCameraDeviceUnAvailable,
    ZMCannotRecordIsAudioDeviceAuthorizeDenied,
    ZMCannotRecordIsVideoDeviceAuthorizeDenied,
};

typedef NS_ENUM(NSUInteger, ZMNotifyType)
{
    ZMNotifyType_None,
    ZMNotifyType_syncFailed,
    ZMNotifyType_connectFailed,
    ZMNotifyType_connecting,
    ZMNotifyType_uploadSuccess,
    ZMNotifyType_fileNotExistedWhenUpload,
    ZMNotifyType_isDictionary,
    ZMNotifyType_disturb,
    ZMNotifyType_fileSizeTooBig,
    ZMNotifyType_timedChat,
    ZMNotifyType_timedChatAdmin,
    ZMNotifyType_E2E_waitingKeyTimeout,
    ZMNotifyType_E2E_waitingKeyTimeout_noOneOnline,
    ZMNotifyType_DiskFull,
    ZMNotifyType_PeerCannotChat,
    ZMNotifyType_fileIsBlockedForSecurityReason,
};

typedef NS_ENUM(NSUInteger, ZMPersonSignatureDurationType) {
    PersonSignatureDurationAlways,
    PersonSignatureDurationCustom,
    PersonSignatureDurationSomeHours
};

typedef NS_ENUM(NSUInteger, ZMChatE2ENotificationType) {
    ZMChat_noti_notShow,
    ZMChat_noti_showNooneOnline,
    ZMChat_noti_showWaitingForKey,
    ZMChat_noti_willNeverShowAgain,
};

typedef enum {
    ZMIME2EIncludeType_waitingKey,
    ZMIME2EIncludeType_noOneOnline,
    ZMIME2EIncludeType_none,
}ZMIME2EIncludeType;

typedef NS_OPTIONS(NSUInteger, ZMLoacalContactSearchFilter) {
    ZMLoacalContactSearchFilterNone     = 1,
    ZMLoacalContactSearchFilterBuddy    = 1 << 1,
    ZMLoacalContactSearchFilterChannel  = 1 << 2,
    ZMLoacalContactSearchFilterMyNote   = 1 << 3,
    ZMLoacalContactSearchFilterCloudContact = 1 << 4,
    ZMLoacalContactSearchFilterPersonalContact = 1 << 5,
    ZMLoacalContactSearchFilterNotMatchChannelMember = 1 << 6,
    ZMLoacalContactSearchFilterZoomPhoneAppliances = 1 << 7,
};

// items' tags in system menu bar (move from ZPPTMainMenuMgr.h)
enum{
    TAG_Memu_Item_Copy = 1001,
    TAG_Memu_Item_Select_All = 1002,
    TAG_Menu_Item_Previous_Chat = 1003,
    TAG_Menu_Item_Next_Chat = 1004,
    TAG_Menu_Item_Callapse_All = 1005,
};

/// Requests that the session in userInfo[@"sessionID"] be made the active session.
/// Used by search, see ZMPTUIApi::startChatBySessionId:messageId:isSearch:isDockout:
extern NSString* kIM_OpenChatSession;
/// Sent when the active (i.e. selected) chat session changes.
/// userInfo[@"sessionID"] contains the new session ID.
extern NSNotificationName const kIM_DidChangeActiveSession;
extern NSString* kIM_ExpandPinHistory;
extern NSString* kIM_SearchChatSession;
extern NSString* kIM_JumpToSearchModeSession;
extern NSString* kIM_SessionQueryFileBack;
extern NSString* kIM_UpdateSessionTab;
extern NSString* kIM_UpdateAllSessionTabForMarkUnread;
extern NSString* kIM_CodeSnippetBundle_downloaded;
extern NSString* kIM_NotificationTypeChange;
extern NSString* kIM_ChatsCreateNewChat;
/// Informs unread-count related UI that it should reload. Sent when the unread count changes.
extern NSString* kIM_ChatsUpdateUnreadTip;
extern NSString* kIM_ChatsUpdateMentionBadge;
extern NSString* kIM_ChatsUpdateAllUnreadTip;
extern NSString* kIM_ChatsUpdateStarredSessions;
extern NSString* kIM_ChatsStarredSessions;
extern NSString* kIM_ChatsRemoveNewChatSession;
extern NSString* kIM_ChatsNewChatDataReadyNotification;
extern NSString* kIM_ChatsStarMessage;
extern NSString* kIM_ChatsUnstarMessage;
extern NSString* kIM_ChatsStarMessageCountChanged;
extern NSString* kIM_ChatSessionResetUnreadCount;
extern NSString* kIM_ChatSessionHistoryCleared;
extern NSString* KIM_ZMLinkAttributeName;
extern NSString* kIM_OpenContactDetail;
extern NSString* kIM_LastOpenedSession;

extern NSString* kIM_CrawlURLBack;
extern NSString* KIM_BroadcastAnnouncementUpdate;
extern NSString* kIM_SingleChatSessionWillClose;
extern NSString* kIMChatsAllJID;

extern NSString* kIM_StartMeetWithVideoUpdate;

extern NSString* kIM_ContactAutoAnswerGroupUpdate;

extern NSString* kIM_CheckDiskStorage;
extern NSString* kIM_MouseDownOnStarMsg;
extern NSString* kIM_MouseDownOnRequestItem;
extern NSString* kIM_CommonAppSelectionChange;
extern NSString* kIM_CommonAppEditChange;

extern NSString*  kIM_ChatsTab_DidAppear;
extern NSString*  kIM_ChatsTab_DidDisappear;

extern NSString* kIM_MentionedMessagesSessionID;
extern NSString* kIM_BookmarkedMessagesSessionID;
extern NSString* kIM_AllFilesSessionID;
extern NSString* kIM_ContactRequestSessionID;
extern NSString* kIM_MissedCallsSessionID;
extern NSString* kIM_ReminderMessageSessionID;
extern NSString* kIM_DraftsMessageSessionID;
extern NSString* const kIM_TutorialsSessionID;

extern NSString* kIM_EditMsgBlockedByContact;

extern NSString* kZMPTRemoveSystemNotification;

extern NSString* kZMPTRecordUpdate;
extern NSString* kZMPTReplyDraftSaved;
extern NSString* kIM_UnreadHintMessageID;

extern NSString* kCaptureWithoutChatWindow;

extern NSString* kIM_AddAppTipShowCount;
extern NSString* kIM_SendVideoMorethan30MTip;
extern NSString* kIM_PersonalNoteTip;
extern NSString* kIM_ScheduleChannleMeetingGuideTip;
extern NSString* kIM_PersistentMeetingsChatGuideTip;
extern NSString* kIM_ClickAddAppButton;
extern NSString* kIM_VideoMessageVirtualBgTip;

extern NSString* kIM_ChannelMuteStatusChanged;

extern NSString* kIM_DownloadedFileNotification;

extern NSString* kIM_ChatsEncDBMigrateStart;
extern NSString* kIM_ChatsEncDBMigrateDone;

extern NSString* kIM_ViewPinHistoryLink;
extern NSString* kIM_Jump2Session;
extern NSString* kIM_ViewJump2MsgLink;
extern NSString* kIM_ChangeGroupSetting;
extern NSString* kIM_Jump2Setting;
extern NSString* kIM_GetNodeInfo;
extern NSString* kIM_ViewMentionGroupLink;
extern NSString* kIM_ViewLessOrMoreHistory;

extern NSString* kIM_RecentContactsDidFinish;
extern NSString* kIM_WebSearchTopResultsDidFinish;
extern NSString* kIM_LocalSearchTopResultsDidFinish;
extern NSString* kIM_PublicChannelTopResultsDidFinish;
extern NSString* kIM_ContactsInfoUpdate;

extern NSString* kIM_JumpToZapp; //zapp
extern NSString* kIM_UpdateZapp;

//ZOOM-301814
extern NSString* kIM_UpdateSlowMode;
extern NSString* kIM_UpdateFastMode;
extern NSString* kIM_UpdatePublicBetaMode;

const static NSInteger kImageFromScreenShotTag = 100;
const static NSUInteger ZMMaxFileContainerHeightForReply = 224;
const static NSInteger MAX_CHATS_TEXT_LENGTH = 4096;

extern NSString *kIM_FlagInE2EChatAfterSendHybridMsg;
extern NSString *kIM_FlagInE2EChannelAfterSendHybridMsg;

extern NSString *kIM_ChatSessionWillDisappear;
extern NSString *kIM_HideToolbarSesionFromList;

extern NSString * const kZoomCommandMeet;
extern NSString * const kZoomCommandCall;

extern NSString* kZMIsNotFirstUser;
extern NSString* kIMReplaceCharBeforeMention;
extern NSString* kIMShowContactRequest;

/// Posted when "Show link preview" setting item updated.
extern NSString *kIM_NotifyLinkPreviewSettingUpdated;  // ZOOM-322697
extern NSString* kIM_NotifyCodeSnippetEditUpdated; //zoom-40759
extern NSString* kIM_NotifyCodeSnippetEditNeedDownload; //zoom-40759
extern NSString* kZMChatsNewChatSessionID;
extern NSString * kZPSettingShowCodeSnippet;
extern NSString * kZPSettingNotShowVoiceMessage;
extern NSString * kZPSettingShowRecordVideoMessageButton;
extern NSString *kZPSettingE2EStateUpdated;

/*!
 Sent after the user sends a message.
 @discussion userInfo[@"sessionID"] contains the sessionID if present, empty string otherwise.
 @note Only sent for main chat messages. Threaded messages do not generate this notification.
 @note This is sent after the user has gone through all the mesage send UI (e.g. confirming "chat policy" warnings),
 but before the server has acknowledged the message.
 Thus, it is possible that this notification is sent for a message which later fails to send (due to server error).
 */
extern NSString *kIM_MessageSentSucceed;
extern NSString *kIM_OnFormatButtonExpand;
extern NSString *kIM_OnCodeSnippetButtonClicked;

extern NSString *kIM_ClickNotifactionCenterItem;
extern NSString *kIM_Jid;
extern NSString *kIM_Channel;
extern NSString *kIM_Add;
extern NSString *kEllipsesCharacter;


const static NSUInteger ZMMaxAddMembersCount = 500;
const static NSUInteger ZMMaxAddExternalEmails = 100;

#define kCommandSymbolChar '/'
#define kCommandSymbolString @"/"

#define ZMChatNeedShowBlur                  ZMAvailable(11)
#define ZM_WHITEBOARD_TAB_CONDITION         @available(macOS 10.13, *)

extern NSString* kIM_NewChat;

#ifndef __ZOOM_NO_CLIENT_LOG
#define ZMBeginLogUseTime(format, ...) \
NSDate *theLogbeginDate = [NSDate date];\
NSLog(@"[zoom-useTime],begin " format, ##__VA_ARGS__);\
ZMLog(@"[zoom-useTime],begin " format, ##__VA_ARGS__);\

#define ZMResetLogUseTime \
theLogbeginDate = [NSDate date];\

#define ZMDidLogUseTime(format, ...) \
NSLog(@"[zoom-useTime],did " format @" useTime:%.2f ms" , ##__VA_ARGS__,[[NSDate date] timeIntervalSinceDate:theLogbeginDate] *1000);\
ZMLog(@"[zoom-useTime],begin " format, ##__VA_ARGS__);\

#else
#define ZMBeginLogUseTime(format, ...)
#define ZMResetLogUseTime
#define ZMDidLogUseTime(format, ...)
#endif

#define ZMChatRouterShared (ZMRouterCenter.shared)

#define ZMChatEventPosterFor(P) ((id<P>)[ZMRouterCenter.shared posterForProtocol:@protocol(P)])

#define kZMPuppeteerSaysNotification @"kZMPuppeteerSaysNotification"
#define kZMPuppetRepliesNotification @"kZMPuppetRepliesNotification"

#define ZMPuppetReply(VALUE) do { \
    int success = (VALUE) ? 1 : -1; \
    [NSNotificationCenter.defaultCenter postNotificationName:kZMPuppetRepliesNotification object:@(success)]; \
} while(0)

#endif /* ZMIMCommonDefine_h */
