//
//  ZMMessageAdapter.h
//  Zoom
//
//  Created by Deal Shao on 9/25/13.
//  Copyright (c) 2013 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "zoom_client_conf.h"
#import <zChatComponent/ZMMessageEntity.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatApp/SaasBeePTAppInterface.h>
#import <zChatApp/IZoomMessenger.h>

@class ZMPinMessageInfo;
@class ZMFileEntity;
@class ZMChatFileItem;
@class ZMScheduleMeetingInfo;
@class ZMShareEmailInfo;
@class ZMReminderMessageInfo;

typedef NS_ENUM(NSUInteger, ZMDisplayMsgTypeCheckResult) {
    ZMDisplayMsgTypeCheckResult_None = 0,
    ZMDisplayMsgTypeCheckResult_Checked = 1,
    ZMDisplayMsgTypeCheckResult_DisabledFileFromOthers = 2,
};


typedef NS_ENUM(NSUInteger, ZMMessageAdapterSenderType)
{
    ZMMessageAdapterSenderType_unknow = 0,
    ZMMessageAdapterSenderType_me,
    ZMMessageAdapterSenderType_other,
};

typedef NS_ENUM(NSUInteger, ZMCloudStoreState)
{
    ZMCloudStoreState_unknow = 0,
    ZMCloudStoreState_stored,
    ZMCloudStoreState_NotStored,
};

typedef NS_ENUM(NSUInteger, ZMThreadHasCommentType)
{
    ZMThreadHasCommentType_unknow = 0,
    ZMThreadHasCommentType_has,
    ZMThreadHasCommentType_no,
};

typedef NS_ENUM(NSUInteger, ZMPMCUnsupportMessageType)
{
    ZMPMCUnsupportMessageType_None, //supported message
    ZMPMCUnsupportMessageType_MeetChatToTeamChat, // message from Meet chat to Team chat，only support text message.
    ZMPMCUnsupportMessageType_TeamChatToMeetChat, // message from Team chat to Meet chat，only support text message.
    ZMPMCUnsupportMessageType_MeetChatToMeetChat, //message from Meet chat to Meet char，only support MessageType_JPG，MessageType_PNG，MessageType_GIF，MessageType_OtherFile，MessageType_ZappMessage，MessageType_MeetFileIntegration
};

@interface ZMMessageAdapter : ZMMessageEntity

@property (nonatomic, assign) MessageType       m_msgType;
@property (nonatomic, assign) MessageState      m_msgState;
@property (nonatomic, assign) ZMFileStorageType fileStorageType;
@property (nonatomic, assign) BOOL              m_isPending;
@property (nonatomic, assign) BOOL              m_isSendingFailed;
@property (nonatomic, assign) BOOL              m_isHistorySyncMessage;

@property (nonatomic, retain) NSString*         m_picturePreviewPath;
@property (nonatomic, assign) BOOL              m_isFileDownloaded;
@property (nonatomic, retain) NSString*         m_timeDescription;
@property (nonatomic, assign) BOOL              m_isPlayed;
@property (nonatomic, assign) BOOL              m_isPreviewPicDownloaded;
@property (nonatomic, assign) BOOL              m_isFileUploaded;
@property (nonatomic, assign) NSUInteger        m_uploadPercentage;
@property (nonatomic, assign) NSUInteger        m_uplaodBitsPerSecond;
@property (nonatomic, assign) NSUInteger        m_uploadTransferredSize;
@property (nonatomic, assign) NSInteger         m_uploadErrorID;
@property (nonatomic, retain) NSMutableArray*   m_atList;
@property (nonatomic, retain) NSMutableArray*   m_mentionInfoList;
@property (nonatomic, retain) NSMutableArray*   m_fontStyleInfoList;
@property (copy) NSString*                      m_XMPPGuid;
@property (nonatomic, assign) BOOL              m_isSupportedMessage;
@property (assign) BOOL                         isStickerMessage;
@property (assign) unsigned long long           prevMsgSvrSideTime;
@property (assign) NSInteger                    filterType;
@property (assign) BOOL                         isNeedTriggerUpdate;
@property (nonatomic, readwrite, copy)NSString* m_giphyID;
@property (assign) NSInteger                    internalTimeValue;
@property (assign) ZMMessageAdapterSenderType   senderType;
@property (copy) NSString*                      linkMessageID;
@property (copy) NSString*                      linkURL;
@property (nonatomic, retain) NSMutableArray*   linkUnfurlingMessages;
@property (nonatomic, assign) NSUInteger        appPreviewCardCount;
@property (nonatomic, assign) BOOL isAppPreviewCardMsgWithNoTextAndFile;
//comments
@property (assign) unsigned long long           lastCommentTime;
@property (assign) unsigned long long           lastEmojiTime;
@property (assign) BOOL                         isFollowedThread;
@property (nonatomic, copy)   NSString*         deleteThreadOperator;
@property (assign) BOOL                         isContainCommentFeature;
@property (assign) BOOL                         isCouldReallySupport;
@property (nonatomic,assign) BOOL               isSaveInDatabase;
@property (nonatomic,assign) BOOL               isWaring;
@property (nonatomic,assign) BOOL               isBotMessageCanReply;
@property (nonatomic,assign) ZMCloudStoreState          msgCloudStoreState;
@property (nonatomic,assign) ZMCloudStoreState          commentThreadCloudStoreState;
@property (nonatomic,assign) BOOL               hasReplyPending;
@property (nonatomic,assign) BOOL               isSentByZoomRoom;

@property (nonatomic,readonly) BOOL isMyNoteMessage;
@property (nonatomic,readonly) BOOL isMeetingMessage;
@property (nonatomic,readonly) BOOL isMeetingMessagePostByHost;
@property (nonatomic,readonly) long long meetingMessageTime;
@property (nonatomic,retain) ZMScheduleMeetingInfo *scheduleMeetingInfo;
@property (nonatomic,assign,readonly) ZMPMCUnsupportMessageType PMCUnsupportMessageType;
@property (nonatomic,retain) ZMShareEmailInfo *shareEmailInfo;

@property (nonatomic,assign) BOOL isMCCMessage; // ZOOM-377225 Flag, meeting chat card message

@property (nonatomic, copy)   NSString*         appId;//zapp
@property (nonatomic, copy)   NSString*         zappName;
@property (nonatomic, copy)   NSString*         iconPath;
@property (nonatomic, copy)   NSString*         appUuid;

//zapp meeting chat
@property (nonatomic, retain) ZMZAppConfShareInfo  *zappShareInfo;
@property (nonatomic, copy)   NSString             *appCompanyName;
@property (nonatomic, assign) ZMZAppToastViewType   viewType;
@property (nonatomic, retain) NSImage              *betaIcon;
@property (nonatomic, assign) BOOL              isZappMessage;

/** Some type of image (like .png, .jpg, or .jif) would be deleted from file-server and not sync with xmpp server, which can no longer be download anymore. This "isNotExistAtServerImage" serves as a flag of those invalid image. Those image-msg would convert to text-msg */
@property (nonatomic,assign) BOOL isNotExistAtServerImage;

@property (nonatomic,readonly) BOOL isUnread;

@property (nonatomic,readonly) BOOL isShortcutUnfurlingMsg;

@property (nonatomic,readonly) NSArray <ZMChatFileItem *> *allFiles;

@property (nonatomic,readonly) BOOL hasFile;

- (id)initWithMessage:(void*)zmMessage;
- (id)initWithMessage:(void*)zmMessage ignoreStyle:(BOOL)ignoreStyle;
- (id)initTimeMessage:(NSString*)description;
- (void*)messageExtention;
- (BOOL)isMentioned:(NSString*)jid;
- (BOOL)isReminderMessage;
- (BOOL)supportsReminderMessage;
- (BOOL)isE2EMessageDecoded;
- (BOOL)isPicMessage;
- (BOOL)isVoiceMessge;
- (BOOL)isFileMessge;
- (BOOL)isDisabledFileFromOthers;
- (BOOL)isHybridMessage;
- (BOOL)isCodeSnippetMessage;
- (BOOL)isHTMLCodeSinnpetBody;
- (BOOL)isRobotMessage;
- (BOOL)isCallMessage;
- (BOOL)isVideoMessage;
- (NS_ZOOM_MESSAGER::FileIntegrationType)fileIntegrationType;
- (void)update;
- (void)updateComments;
- (void)updatePinInfo;
- (BOOL)isNotOrderGroupSysmentMessage;
- (BOOL)isCountdownMeetingCard;
// meeting
- (NSString *)receiverNameByJid:(NSString *)jid;
//todo-
//- (BOOL)getFileIntegrationDetailWithFileIntegrations:(std::vector<NS_ZOOM_MESSAGER::FileIntegrationData>)fileIntegrations;
- (BOOL)isSupportMarkUnread;
- (ZMThreadHasCommentType)hasCommentsType;
- (BOOL)isNeedSyncComments;
//ZOOM-108962
- (BOOL)isBroadcastAnnouncement;
- (BOOL)isBroadcastAnnouncementReceiver;
//ZOOM-164281
/**Server verify, avoid customers to get around by renaming the extension to the account's approved file types */
- (BOOL)validateFailedOfApprovedFileInServer;

- (BOOL)getFileIntegrationDetailWithFileIntegrations:(std::vector<NS_ZOOM_MESSAGER::FileIntegrationData>)fileIntegrations;

+ (ZMPinMessageInfo *)getPinMessageInfo:(const ns_zoom_messager::PinMessageInfo &)pinMsgInfo;

+ (ZMReminderMessageInfo *)getReminderMessageInfo:(const NS_ZOOM_MESSAGER::ReminderInfo &)reminderMsgInfo
                                            event:(const NS_ZOOM_MESSAGER::ReminderEvent)event;

- (void)addAccessoryDeepLink:(NSString *)url sessionId:(NSString *)sessionId;
- (NSMutableArray<NSString *>*)getAccessoryDeepLinkList;
- (void)clearAccessoryDeepLinkList;

@end



@interface ZMMessageMentionInfo : NSObject

@property (nonatomic, assign) NS_ZOOM_MESSAGER::MessageAtType mentionType;
@property (nonatomic, copy) NSString* messageID;
@property (nonatomic, assign) NSRange range;

- (id)initWithMessageMentionInfo:(NS_ZOOM_MESSAGER::MessageAtInfo *)messageMentionInfo;
@end
