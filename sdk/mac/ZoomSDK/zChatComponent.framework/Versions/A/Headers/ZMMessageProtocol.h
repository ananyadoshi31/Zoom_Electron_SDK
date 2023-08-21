//
//  ZMMessageProtocol.h
//  SaasBeePTUIModule
//
//  Created by groot.ding on 2019/7/18.
//  Copyright © 2019 Zoom. All rights reserved.
//

#ifndef ZMMessageProtocol_h
#define ZMMessageProtocol_h

#import <dataModule/zDataConstants.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#include <zChatApp/IZoomMessenger.h>
#include <zChatComponent/ZMMessageDraftHelper.h>
#import <zChatComponent/ZMReminderMessageMgrProtocol.h>
#import <zChatComponent/ZMIMInputCustomButtonMgrProtocol.h>

@class ZMSyncDataResult;
@class ZMMessageAdapter;
@class ZMSyncMessageFilter;
@class ZMStickerInfo;
@class ZMFileIntegrationShareInfo;
@class ZMPinMessageCallback;
@class ZMPinMessageInfo;
@class ZMUserInfo;
@class ZMMessageRevokeInfo;
@class ZMThreadCommentState;
@class ZMFileEntity;
@class ZMBuddyAdapter;
@class ZMDLPPolicyResult;
@class ZMToastCoordinator;
@class ZMChatsCommandData;
@class ZMChannelMeetingEvent;
@class ZMChannelMeetingStatus;
@class ZMScheduleMeetingCallback;
@class ZMCustomMessageInfo;
@class ZMMeetingChatCardEntity;
@class ZMMeetingChatCardReqParticipantsPara;
@class ZMMCCSyncMessageResult;
@class ZMMCCSyncParticipantsResult;
@class ZMShareEmailInfo;
@class ZMChatAppInfo;
@class ZMChatAppShortcutInfo;
@class ZMChatAppMessagePreviewInfo;
@class ZMSendMessageParams;
@class ZMChannelMeetingAttendeeEvent;

static NSString * _Nonnull const kChatMessageItemInfoConfUserId = @"kChatMessageItemInfoConfUserId";
static NSString * _Nonnull const kChatMessageItemInfoUserJid = @"kChatMessageItemInfoUserJid";

typedef NS_ENUM(NSUInteger, ZMThreadSortType){
    ZMThreadSortTypeVisableTime,
    ZMThreadSortTypeThreadTime
};

typedef NS_ENUM(NSUInteger, ERR_CODE){
    ERR_CODE_TIMEOUT = 1001,
    ERR_CODE_REDIRECTED,
    ERR_CODE_DataStatePreviewNoPermission,
};

typedef NS_ENUM(NSUInteger, ZMJumpMessageSourceType){
    ZMJumpMessageFromUnknow,
    ZMJumpMessageFromPinMessage,
};

typedef NS_ENUM(NSUInteger, InputBoxMsgType) {
    InputBoxMsgType_TextOnly = 0,
    InputBoxMsgType_SingleFileOnly = 1 << 0,
    InputBoxMsgType_HybridMsg = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMReminderMessageStatus) {
    ZMReminderMessageStatus_OK,
    ZMReminderMessageStatus_Unknown,
    ZMReminderMessageStatus_Fail,
    ZMReminderMessageStatus_Fail_Session_Not_Found,
    ZMReminderMessageStatus_Probing_In_Progress,
    ZMReminderMessageStatus_Sync,
    ZMReminderMessageStatus_Sync_Expire,
    ZMReminderMessageStatus_Sync_Set,
    ZMReminderMessageStatus_Sync_Edit,
    ZMReminderMessageStatus_Sync_Reschedule,
};

typedef NS_ENUM(NSUInteger, ZMReminderMessageEvent) {
    ZMReminderMessageEvent_None,
    ZMReminderMessageEvent_Set,
    ZMReminderMessageEvent_Edited,
    ZMReminderMessageEvent_Rescheduled,
};

typedef NS_ENUM(NSUInteger, ZMReminderMessageError) {
    ZMReminderMessageError_OK,
    ZMReminderMessageError_Unknown,
    ZMReminderMessageError_System,
    ZMReminderMessageError_NotImplemented,
    ZMReminderMessageError_MessageNotFound,
    ZMReminderMessageError_ReminderNotFound,
    ZMReminderMessageError_E2E,
    ZMReminderMessageError_OpDisabled,
    ZMReminderMessageError_UnsupportedMessageType,
    ZMReminderMessageError_TooMany,
    ZMReminderMessageError_TimeoutTooSmall,
    ZMReminderMessageError_TimeoutTooBig,
    ZMReminderMessageError_NoteTooLong,
    
    ZMReminderMessageError_NoSyncPerformed = UINT_MAX
};

@protocol ZMSyncMessageProtocal <NSObject>

- (nullable ZMSyncDataResult *)syncThreadsByFilter:(nonnull ZMSyncMessageFilter *)filter completion:(nullable ZMCallbackBlock)completion;

- (nullable ZMSyncDataResult *)syncCommentsByFilter:(nonnull ZMSyncMessageFilter *)filter completion:(nullable ZMCallbackBlock)completion;

- (nullable ZMSyncDataResult *)syncSingleThread:(nonnull ZMSyncMessageFilter *)filter completion:(nullable ZMCallbackBlock)completion;

- (BOOL)cancelDBRequest:(nonnull NSString *)requestId sessionId:(nonnull NSString *)sessionId;

- (BOOL)cancelXMSRequest:(nonnull NSString *)requestId sessionId:(nonnull NSString *)sessionId;

- (BOOL)hasSyncMessageCallBackByRequestId:(nonnull NSString *)requestId;

- (void)addSyncMessageCallBackByRequestId:(nonnull NSString *)requestId sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId syncWeb:(BOOL)syncWeb block:(nullable ZMCallbackBlock)completion;
@end

@protocol ZMSyncMessageCallback <NSObject>

- (void)didSyncThreadDataByDataResult:(nonnull ZMSyncDataResult *)syncDataResult;

- (void)didSyncCommentDataByDataResult:(nonnull ZMSyncDataResult *)syncDataResult;

- (void)didSyncSignleThread:(nonnull NSString *)threadId sessionId:(nonnull NSString *)sessionId requestId:(nonnull NSString *)requestId fromAsync:(BOOL)fromAsync success:(BOOL)success;

@end

@protocol ZMSyncSessionUnreadCallback <NSObject>

- (void)didSessionUnreadCountReady:(nonnull NSArray <NSString *> *)sessionIds;

@end

@protocol ZMCheckMessageProtocal <NSObject>

- (BOOL)checkHasMoreCommentsByChannelID:(nonnull NSString*)channelID threadID:(nonnull NSString*)threadID startCommentID:(nonnull NSString*)startCommentID;

- (BOOL)checkHasRecentCommentsByChannelID:(nonnull NSString*)channelID threadID:(nonnull NSString*)threadID startCommentID:(nonnull NSString*)startCommentID;

- (BOOL)checkHasMoreHistoricThreadsWithChannelID:(nonnull NSString*)sessionID startThreadID:(nonnull NSString*)threadID;

- (BOOL)checkHasMoreRecentThreadsWithChannelID:(nonnull NSString*)sessionID startThreadID:(nonnull NSString*)threadID;

- (BOOL)checkMessageIsDirtyByChannelID:(nonnull NSString *)channelID threadID:(nullable NSString*)threadID commnetID:(nonnull NSString *)commnetID;

- (BOOL)checkThreadHasReply:(nonnull NSString *)threadId sessionId:(nonnull NSString *)sessionId;

- (NSInteger)checkThreadHasReplyOdds:(nonnull NSString *)threadId sessionId:(nonnull NSString *)sessionId;

// v5.12.0-persistent chat: original messages are from old meeting-chat senders
- (BOOL)checkThreadIsOriginalMeetingMessage:(nonnull NSString *)threadId sessionId:(nonnull NSString *)sessionId;
@end

@protocol ZMOperateMessageProtocol <NSObject>

- (nullable ZMMessageAdapter *)getMessageById:(nonnull NSString *)msgId sessionId:(nonnull NSString *)sessionId;

- (nullable ZMMessageAdapter *)getMessageWithoutStyleById:(nonnull NSString *)msgId sessionId:(nonnull NSString *)sessionId;

- (nullable ZMMessageAdapter *)getMessageByServerTime:(long long)serverTime sessionId:(nonnull NSString *)sessionId;

- (nullable ZMMessageAdapter *)getMessageByServerTime:(long long)serverTime sessionId:(nonnull NSString *)sessionId useDb:(BOOL)useDB;

- (nullable ZMMessageAdapter*)getLastMessageBySessionId:(nonnull NSString *)sessionId;

- (BOOL)checkMessageExistById:(nonnull NSString *)msgId sessionId:(nonnull NSString *)sessionId;

- (nullable NSDate *)getThreadVisibleTimeByChannelID:(nonnull NSString*)channelID threadID:(nonnull NSString*)threadID;

- (long long)getVisibleTimeWithSessionID:(nonnull NSString *)sessionId threadID:(nonnull NSString *)messageId;

- (long long)getServerVisibleTimeWithSessionID:(nonnull NSString*)sessionID threadID:(nonnull NSString*)messageId;

- (nullable NSDate *)getMessageTimeStampById:(nonnull NSString *)msgId sessionId:(nonnull NSString *)sessionId;

- (void)readMessageById:(nonnull NSString *)msgId sessionId:(nonnull NSString *)sessionId;

- (void)deleteMessage:(nonnull ZMMessageAdapter *)message;

- (BOOL)markMessage:(nonnull ZMMessageAdapter *)message asUnread:(BOOL)asUnread;

- (BOOL)markLastMessageUnreadBySessionId:(nonnull NSString *)sessionId;

- (BOOL)isMarkUnreadMessage:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (nullable NSArray <ZMCustomMessageInfo *>*)getMarkUnreadMessagesBySessionId:(nonnull NSString *)sessionId;

- (void)deleteNoAccessWhiteBoardPreview:(nonnull NSString *)sessionId msgId:(nonnull NSString *)msgId fileIndex:(NSInteger)fIdx;

- (BOOL)isUnreadReply:(nonnull NSString *)replyMessageId sessionId:(nonnull NSString *)sessionId;

- (BOOL)tryDecodeMessageById:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (BOOL)isThreadCommentInfoAccurate:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (void)syncMessageEmojiCountInfoWithChanelID:(nonnull NSString*)channelID msgArray:(nonnull NSArray<NSString*>*)msgArray;

- (void)addTempMessageWithBody:(nonnull NSString *)msgBody sessionID:(nonnull NSString *)sessionID;

- (void)searchUnsupportMessages:(nonnull NSArray <ZMMessageAdapter*> *)messages;

- (nullable NSString *)insertSystemMessage:(nonnull NSString *)msgBody inMsgId:(nonnull NSString *)inMsgId sessionId:(nonnull NSString *)sessionId sendId:(nonnull NSString *)sendId messageType:(MessageType)type isRead:(BOOL)isRead timeStamp:(nullable NSDate*)timeStamp serverSideTime:(NSUInteger)svrSideTm prvMsgTime:(NSUInteger)prvMsgTm outTimeStamp:(nullable NSUInteger*)pOutTimestamp;

- (BOOL)editMessageWithBody:(nonnull NSString *)msgBody sessionId:(nonnull NSString *)sessionId guid:(nonnull NSString *)guid atList:(nullable NSArray *)atList emojiInfo:(nullable void *)emojiInfo fontStyleInfo:(nullable NSArray*)fontStyleList fileList:(nullable NSArray *)fileList isE2E:(BOOL)isE2E  isAutoEditWBPreviewMsg:(BOOL)isAutoEditWBPreviewMsg hasAppPreviewCard:(BOOL)hasAppPreviewCard;

- (BOOL)syncThreadCommentCountWithChannelID:(nonnull NSString*)channelID msgSvrTimes:(nonnull NSArray<NSNumber*> *)msgSvrTimeArray;

- (BOOL)isThreadCommentCountSyncedWithChannelID:(nonnull NSString*)channelID msgSvrTime:(long long)svrTime;

- (ZMThreadSortType)getThreadSortTypeWithSessionId:(nullable NSString *)sessionId;

- (ZMThreadSortType)getThreadSortTypeIfHavePending;

- (void)setThreadSortType:(ZMThreadSortType)sortType;

- (BOOL)isDisableReply;

- (BOOL)isDisableReplyWithSessionId:(nullable NSString *)sessionId;

- (BOOL)isDisableReactionWithSessionId:(nullable NSString *)sessionId;

- (nullable NSArray <NSString *> *)getUnreadAllMentionedMessagesBySessionId:(nonnull NSString *)sessionId;

- (long long)getReadedMsgTimeBySessionId:(nonnull NSString *)sessionId;

- (NSInteger)getUnreadCountBySessionId:(nonnull NSString *)sessionId;

- (void)cleanUnreadMessageCountBySessoinId:(nonnull NSString *)sessionId;

- (NSInteger)getUnreadCommentCount:(long long)threadServerTime sessionId:(nonnull NSString *)sessionId;

- (BOOL)cleanUnreadCommentsForThread:(long long)threadServerTime sessionId:(nonnull NSString *)sessionId;

- (BOOL)setMessageAsRead:(BOOL)isRead messageId:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (BOOL)isUnreadMessage:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (NSInteger)getMarkUnreadMessageCount:(nonnull NSString *)sessionId;

- (nullable NSArray <ZMThreadCommentState *> *)getUnreadReplysInfoBySessionId:(nonnull NSString *)sessionId;

- (nullable NSArray *)getSendErrorMessagesBySessionId:(nonnull NSString *)sessionId;

- (BOOL)checkSessionCanChat:(nonnull NSString *)sessionId;

- (BOOL)checkSessionCanAddReaction:(nonnull NSString *)sessionId;

- (BOOL)isEnableE2EWithSessionID:(nonnull NSString*)sessionId;

- (BOOL)isHybridMessageEnabledWithSessionId:(NSString*)sessionId;

- (BOOL)isFileTransferDisabled;

- (BOOL)isNewChatSessionViewCtrlWithSessionID:(nonnull NSString *)sessionID newSessionID:(NSString** _Nullable)newSessionID;

- (BOOL)isAllowWhiteboardPreviewShareToChat:(nonnull NSString*)sessionId;

- (nullable NSMutableArray<ZMFileEntity*> *)filterWhiteboardURLWithArray:(nullable NSMutableArray<NSString*> *)urlMutableArray andSessionId:(nonnull NSString *)sessionId;

+ (nullable NSDictionary *)getNewChatMembersInfoInSession:(nonnull NSString *)sessionID;

- (BOOL)canSendFileInSession:(nonnull NSString*)sessionID;

- (BOOL)isRichTextFormatEnabledWithSessionId:(nullable NSString *)sessionId;
- (BOOL)isRichTextFormatEnabledOnWebWithSessionId:(nullable NSString *)sessionId;

- (BOOL)isChatAppsShortcutsEnabled;

- (long long)getMaxFileSizeInSession:(nonnull NSString*)sessionID;

- (long long)getMaxFileSize4InternalInByte;

- (long long)getMaxFileSize4ExternalInByte;

- (ZMFTPermissionType)getUploadFilePermissionInSession:(nonnull NSString*)sessionID fileSuffix:(nonnull NSString*)fileSuffix;

- (BOOL)isValidInsertLink:(nonnull NSString*)inputLink outLink:(NSString ** _Nullable)outLink sessionId:(nullable NSString *)sessionId;

- (BOOL)isRecordMessageEnabledWithSessionId:(nullable NSString *)sessionId;

- (BOOL)isRecordVideoMessageEnabled;

- (BOOL)needShowSendVideoMorethan30MTip;

- (BOOL)isEnablePlayableVideoMsgWithSessionId:(nullable NSString *)sessionId;

- (BOOL)isSipEnable;

- (BOOL)isNoMeetingLicenseUser;

- (BOOL)isFullScreen;

- (void)startSipCallByJid:(nonnull NSString*)jid;

- (void)startMeetingWithFriendJid:(nonnull NSString *)jid;

- (void)startSipCallBySipnumber:(nonnull NSString *)sipNumber;

- (void)startChatByChannelID:(nonnull NSString *)channelID isSearch:(BOOL)isSearch;

- (nullable NSString*)getJoinMeetingURL:(nonnull NSString*)meetingNum;

- (nullable NSString*)getRootNodeInfoFromCacheWithSessionID:(nonnull NSString*)sessionID;

- (BOOL)joinMeetingWithURL:(nonnull NSString*)url;

- (BOOL)checkConnectionGood:(nonnull NSString *)sessionId;

- (nullable NSString *)getJoinMeetingURLByCallHistoryMessageId:(nonnull NSString *)messageId;

- (nullable NSString *)localStorageTimeStringBySessionId:(nonnull NSString *)sessionId;

- (BOOL)isSessionUnreadReady;

- (nullable NSString *)getDataFolderInSession:(nonnull NSString *)sessionId;

- (BOOL)isZoomRoomSession:(nonnull NSString *)sessionId;

- (BOOL)isGroupChatSession:(nonnull NSString *)sessionId;

- (BOOL)amIInGroup:(nonnull NSString*)groupID;

- (BOOL)isBroadcastAnnouncementsSession:(nonnull NSString *)sessionID;

- (BOOL)isScreenCaptureEnabled;

- (BOOL)is3rdPartStorageEnabledInChannel:(nonnull NSString*)groupID;

- (BOOL)isBoxEnabledInChannel:(nonnull NSString*)groupID;

- (nullable NSArray*)getFileStorageSupportedTypesFromCache;

- (nullable NSString*)getFileStorageSupportedTypes;

- (nullable NSArray*)getArrayForFileIntegrationShare;

- (nullable NSString*)getOpusFilePathWithSessionId:(nonnull NSString*)sessionID;

- (nullable NSArray*)getAllRobotCmdBySessionID:(nonnull NSString*)inSessionId;

- (BOOL)set1V1Session:(nonnull NSString*)sessionId inputStatus:(NSInteger)inStatus;

- (BOOL)isE2EGetCanSendMessageCipher:(NSUInteger *_Nonnull)outReason sessionID:(nonnull NSString *)sessionID;

- (NSUInteger)getBuddyCountInSession:(nonnull NSString*)sessionID;

- (BOOL)isDLPEnabled;

- (nullable ZMDLPPolicyResult*)checkDLPPolicyWithConent:(nullable NSString*)content;

- (BOOL)checkSessionIsChannel:(nonnull NSString *)sessionId;

- (nullable ZMToastCoordinator *)getMainToastCoordinator;

- (nullable NSString *)getCurrentSessionID;

- (void)setAsTrustedSenderForDownloadFileWithSenderJID:(nonnull NSString*)senderJID trust:(BOOL)trust;

- (BOOL)setLastUsedRobotCommand:(nullable ZMChatsCommandData*)commandData;

- (nullable ZMChatsCommandData*)getLastUsedRobotCommand;

- (nullable NSString*)sendAddonMessage:(nonnull NSString*)message sessionID:(nonnull NSString *)sessionID jid:(nonnull NSString*)jid;

- (nullable NSString*)getCorrectLink:(nullable NSString*)relativeURL;

- (BOOL)requestSaveOrOpenUrlWithType:(NSInteger)type isSaved:(BOOL)isSaved messageInfo:(nonnull ZMMessageAdapter *)msg;

- (BOOL)isStarredMessage:(nonnull NSString*)sessionID serverTime:(long long)time;
- (void)starMessage:(nonnull ZMMessageAdapter *)inMsgInfo;
- (void)unStarMessage:(nonnull ZMMessageAdapter *)inMsgInfo;

- (void)unStarMessageBySessionId:(nonnull NSString *)sessionID serverTime:(long long)time;

- (nullable NSArray *)getIntegrationFileManagerListWithMessage:(nonnull ZMMessageAdapter *)message;

- (BOOL)isThreadFollowedWithSessionID:(nonnull NSString*)sessionID threadID:(nonnull NSString*)msgID;
- (BOOL)followThreadWithSessionID:(nonnull NSString*)sessionID threadID:(nonnull NSString*)msgID;
- (BOOL)discardFollowThreadWithSessionID:(nonnull NSString*)sessionID threadID:(nonnull NSString*)msgID;

- (ZMStartRecordStatus)checkStartRecordAudioStatus;
- (ZMStartRecordStatus)checkStartRecordVideoStatus;

- (nonnull NSString *)getMeetingJidByUserId:(nonnull NSString *)userID sessionId:(nonnull NSString *)sessionId;
- (nonnull NSString*)getMeetingChatUserIdByJid:(nonnull NSString *)jid sessionId:(nonnull NSString *)sessionId;
- (BOOL)checkMeetingMessageCanBeDeleted:(NSString *)messageId sessionId:(NSString *)sessionId;

- (BOOL)isOnlyVisibleToYouForMessage:(NSString *)messageId inSession:(NSString *)sessionID;

- (nullable NSString *)GetZoomMeetPMCChannelID:(nullable NSString *)groupID ;
- (BOOL)PMC_CheckInTeamChatFromMeetingChat:(nullable NSString *)accountID meetingGroupID:(nullable NSString *)meetingGroupID PMCChannelID:(nullable NSString *)PMCChannelID;

/** messageId, threadId, messageSvrTime and ThreadSvrTime can’t be empty if jump to a message */
- (BOOL)PMC_OpenTeamChatFromMeetingChatWithAccountID:(nullable NSString *)accountID meetingGroupID:(nullable NSString *)meetingGroupID PMCChannelID:(nullable NSString *)PMCChannelID messageId:(nullable NSString *)messageId threadId:(nullable NSString *)threadId messageSvrTime:(NSInteger)messageSvrTime threadSvrTime:(NSInteger)threadSvrTime;

- (void)PMC_NotifyTeamChatUpdated:(PMCTeamChatUpdatedInfo)info;

- (BOOL)isAdminRemoveChannelMsgEnabled:(nullable NSString *)sessionID;

@end

@protocol ZMEmojiProtocol <NSObject>

- (BOOL)isEnableChatEmojiWithSessionId:(NSString *)sessionId;
- (BOOL)isEnableSelectedChatEmojiWithSessionId:(NSString *)sessionId;
- (NSString *)code2SDKEmojiID:(NSString *)emojiID withType:(ZMEmojiType)emojiType;
- (NSString *)decodeSDKEmojiID:(NSString *)emojiID emojiType:(ZMEmojiType*)emojiType;

@end

@protocol ZMGiphyProtocol <NSObject>

- (nullable NSArray*)getCachedHotGiphyInfoList;

- (BOOL)getHotGiphyInfoWithNum:(NSUInteger)giphyNum requestID:(NSString *_Nullable *_Nullable)requestID;

- (BOOL)getGiphyInfoByStr:(nonnull NSString*)giphyString andGiphyNum:(NSUInteger)giphyNum requestID:( NSString *_Nullable * _Nullable)requestID chatSession:(nonnull NSString*)sessionID;

- (nullable NSDictionary *)getGiphyInfo:(nonnull NSString*)giphyID;

- (nullable NSString*)giphyImgPathByGiphyID:(nonnull NSString*)giphyID;

- (BOOL)downloadGIFFromGiphyByUrl:(nonnull NSDictionary*)downloadInfoDict  requestID:(NSString *_Nullable *_Nullable)requestID andIsBigPic:(BOOL)isBigPic;

- (BOOL)cancelGiphyDownload:(nonnull NSString*)reqId;

- (BOOL)getGiphyInfoFromSever:(nonnull NSString*)giphyID sessionId:(nonnull NSString*)sessionId messageId:(nonnull NSString*)msgId;

- (BOOL)isGiphyOptionEnabled;

- (BOOL)isGiphyMixedMessageEnabled;

@end

@protocol ZMGiphyCallbackProtocol <NSObject>

- (void)didGotGiphyInfo:(nonnull id)param;

- (void)didGiphyDownloaded:(nonnull id)param;

@end

@protocol ZMStickerProtocol <NSObject>

- (BOOL)syncStickerList;

- (nullable NSArray <ZMStickerInfo *> *)getStickerList;

- (NSInteger)getStickersCont;

- (int)downloadSticker:(nonnull ZMStickerInfo *)sticker path:(nonnull NSString *)path reqId:(NSString *_Nullable *_Nullable)reqId;

- (int)makeStickerWithFileId:(nonnull NSString *)fileId;

- (int)uploadFileAndMakeSticker:(nonnull NSString *)filePath reqId:(NSString *_Nullable *_Nullable)reqId;

- (int)discardSticker:(nonnull ZMStickerInfo *)sticker;

@end

@protocol ZMLinkPreviewProtocol <NSObject>

- (BOOL)isHyperlinkPreviewEnabledInE2EWithSessionId:(nullable NSString *)sessionId;

- (BOOL)isEnableLinkPreview;

- (BOOL)checkNeedParseURLBySender:(nonnull NSString *)senderJid sessionId:(nonnull NSString*)sessionId;

- (nullable NSMutableDictionary *)fuzzyGetLinkMetaInfoWithURL:(nonnull NSString *)linkURL sessionId:(nonnull NSString *)sessionId;

- (void)sendLinkMetaInfoWithSessionID:(nonnull NSString *)sessionID messageID:(nonnull NSString *)messageID urls:(nonnull NSArray *)urls;

- (BOOL)crawlLinkMetaInfoWithSessionID:(nonnull NSString *)sessionID messageID:(nonnull NSString *)messageID urls:(nonnull NSArray *)urls;

@end

@protocol ZMOperateMessageCallback <NSObject>

- (void)didReceiveMessageById:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (void)didReceiveMessage:(nonnull ZMMessageAdapter *)message;

- (void)didSendComfirmMessageById:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (void)didRevokeMessage:(nonnull NSString *)messageId param:(nonnull ZMMessageRevokeInfo *)param;

- (void)didUpdateMessage:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (void)didEditMessage:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId result:(BOOL)success;

- (void)didMarkUnreadMessagesUpdate:(nullable NSArray <NSString *> *)messageIds sessionId:(nullable NSString *)sessionId;

- (void)didReactionUpdatedWithChannelID:(nonnull NSString*)channelID msgID:(nonnull NSString*)msgID needSync:(BOOL)needSync;

- (void)didE2EMessageUpdateWithChannelID:(nonnull NSString*)channelID msgID:(nonnull NSString*)msgID;

- (void)didSyncThreadCommentCountWithChannelID:(nonnull NSString*)channelID msgArray:(nonnull NSArray<NSString*>*)ids requestId:(nonnull NSString *)requestId success:(BOOL)success;

- (void)didPlayAudioMessageStatusChange:(nonnull NSString *)messageId sessionId:(nonnull NSString *)sessionId;

- (void)didReceivedUnsupportMessage:(nonnull NSString*)messageId sessionId:(nonnull NSString*)sessionId;

- (void)didConnectOnline:(BOOL)online;

- (void)PMC_NotifyCheckInTeamChatFromMeetingChatResult:(BOOL)isBelongTo groupID:(nonnull NSString *)groupID;

- (void)PMC_NotifyOpenTeamChatFromMeetingChatResult:(PMCOpenTeamChatRespResult)result;

@end

@protocol ZMOperateReactionProtocal <NSObject>

- (void)syncMessageEmojiCountInfoWithChanelID:(nonnull NSString*)channelID msgArray:(nonnull NSArray<NSString*>*)msgArray;

- (nullable NSArray *)getEmojiCountInfoWithChanelID:(nonnull NSString*)channelID messageID:(nonnull NSString*)msgID isLocalOnly:(BOOL)isLocalOnly xmsReqID:( NSString * _Nullable *_Nullable)outXmsReqID;

- (nullable NSArray *)getEmojiDetailInfoWithChanelID:(nonnull NSString*)channelID messageID:(nonnull NSString *)msgID emojiString:(nonnull NSString *)emojiString isLocalOnly:(BOOL)isLocalOnly xmsReqID:( NSString * _Nullable *_Nullable)outXmsReqID;

- (BOOL)addEmojiForChanelID:(nonnull NSString *)channelID messageID:(nonnull NSString *)msgID emoji:(nonnull NSString *)emoji xmsReqID:( NSString * _Nullable *_Nullable)outXmsReqID;

- (BOOL)removeEmojiForChanelID:(nonnull NSString *)channelID messageID:(nonnull NSString *)msgID emoji:(nonnull NSString *)emoji xmsReqID:( NSString * _Nullable *_Nullable)outXmsReqID;

- (BOOL)checkSessionCanAddReaction:(nonnull NSString *)sessionId;

- (void)onFetchEmojiCountInfoWithSessionID:(nonnull NSString*)inSID messages:(nonnull NSArray<NSString*> *)msgArray reqID:(nonnull NSString *)reqID;

- (void)onFetchEmojiDetailInfoWithSessionID:(nonnull NSString *)inSID messageID:(nonnull NSString *)inMsgID emojiCode:(nonnull NSString *)emojiCode reqID:(nonnull NSString *)reqID;

@end

@protocol ZMListenMessageProtocal <NSObject>

- (void)removeAllListenByTarget:(nonnull id)target;

- (void)addListenMessageReceiveByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenMessageSendComfirmByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenSyncSingleThreadReceiveCommentsByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenMessageUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenEditMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenDeleteMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenMarkUnreadMessagesUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReactionUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReactionDetailUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenE2EMessageUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

//pin message
//completion param,key is sessionId,param is ZMPinMessageCallback

- (void)addListenTopPinMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenUnTopPinMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenHideTopPinMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenTopPinMessageUpdateByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenRemovePinMessageByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

//meeting chat card
- (void)addListenMCCDetailMessagesSyncByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenMCCMessagesAllSyncDone:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenMCCParticipantsSyncByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

//schedule channel meeting

- (void)addListenReceiveChannelMeetingMemberChangedByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReceiveChannelMeetingListByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReceiveChannelMeetingStatusChangedByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReceiveSearchMeetingAttendeesByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

// persistent meetings chat

- (void)addListenReceivePMCMeetingInfoChangedByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

//reminder message

- (void)addListenSetReminderByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenRemoveReminderByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReminderExpireByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReminderSyncByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReminderSyncRequiredByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenReminderUnreadCountByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

//audio
- (void)addListenPlayAudioStatusByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenUnreadCountReadyByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenGotGiphyInfoByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenGihpyDownloadReadyByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

// chat App
- (void)addListenChatAppMessagePreviewSyncFromWebviewByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;

- (void)addListenPMCCheckInTeamChatFromMeetingChatResultByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;
- (void)addListenPMCNotifyOpenTeamChatFromMeetingChatResultByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;
- (void)addListenPMC_NotifyTeamChatUpdatedByTarget:(nonnull id)target completion:(nonnull ZMCallbackBlock)completion;
@end


@protocol ZMSendMessageProtocal <NSObject>

- (InputBoxMsgType)boxMsgTypeWithTrimmedString:(nonnull NSString *)string fileCount:(NSUInteger)fileCount;

- (nullable NSArray <NSString *> *)sendMessageWithAttributedString:(nullable NSAttributedString *)attributedString sessionId:(nonnull NSString *)sessionId threadId:(nonnull NSString *)threadId fileList:(nullable NSArray *)fileList;

- (nullable NSString *)shareTextMessage:(nonnull NSString *)text messageType:(MessageType)type toSessionId:(nonnull NSString *)toSessionId fromSessionId:(nonnull NSString *)fromSessionId fromMessageId:(nonnull NSString *)fromMessageId;

- (nullable NSString *)sendTextMessage:(nonnull NSString *)text
                             sessionId:(nonnull NSString *)sessionId
                              threadId:(nullable NSString *)threadId
                                atList:(nullable NSArray*)atList
                             extension:(nullable void*)ext
                         fontStyleInfo:(nullable NSArray*)fontStyleArray
                              fileList:(nullable NSArray *)fileList
                  appPreviewsInfoArray:(nullable NSArray*)appPreviewsInfoArray
                                params:(nullable ZMSendMessageParams *)params;

- (nullable NSString*)sendSharepointIntegration:(nonnull ZMFileEntity *)fileInfo sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (nullable NSString *)sendLocalFileIntegrationMessage:(nonnull NSString *)filePath sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId isFromScreenShot:(BOOL)isFromScreenShot;

- (nullable NSString *)sendFileMessage:(nonnull NSString *)filePath sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId isFromScreenShot:(BOOL)isFromScreenShot;

- (nullable NSString *)sendVideoMessage:(nonnull NSString *)videoPath previewPath:(nonnull NSString *)previewPath previewSize:(NSSize)size session:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (nullable NSString *)sendGiphyMessage:(nonnull NSString *)giphyID sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (nullable NSString *)sendCodeSnippetMessage:(nonnull NSString *)filePath sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (BOOL)sendCustomEmojiMessage:(nonnull ZMStickerInfo *)customEmoji sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (nullable NSString *)sendFileIntegrationMessage:(nonnull ZMFileIntegrationShareInfo *)fileInfo sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;

- (nullable NSString *)sendAudioFile:(nonnull NSString*)audioFilePath sessionId:(nonnull NSString*)sessionId threadId:(nullable NSString*)threadId audioLength:(NSUInteger)audioLenInSec;

- (NSString * _Nonnull)sendEmail:(ZMShareEmailInfo * _Nonnull)emailInfo text:(NSString * _Nonnull)text file:(NSString * _Nonnull)file sessionId:(NSString* _Nonnull)sessionId;

- (nullable NSString*)editCodeSnippetMsgWithFileId:(nullable NSString*)webFileId andFileName:(nullable NSString*)fileName andLocalPath:(nullable NSString*)localPath andIsOnlyNameChanged:(BOOL)isOnlyNameChanged sessionId:(nullable NSString*)inSessionId;

- (nullable NSString *)sendFileMessage:(nonnull NSString *)filePath sessionId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId isFromScreenShot:(BOOL)isFromScreenShot params:(nullable ZMSendMessageParams *)param;
- (nullable NSArray <NSString *> *)sendMessageWithAttributedString:(nullable NSAttributedString *)attributedString sessionId:(nonnull NSString *)sessionId threadId:(nonnull NSString *)threadId fileList:(nullable NSArray *)fileList params:(nullable ZMSendMessageParams *)param;
@end

/* meeting chat: need to move to VideoUI Component @cain zhou */
@protocol ZMMessageMeetingChatSendProtocol <NSObject>
- (NSInteger)meetingChatManager_fetchCurrentReceiverType:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;
- (nonnull NSString *)meetingChatManager_fetchCurrentReceiverId:(nonnull NSString *)sessionId threadId:(nullable NSString *)threadId;
- (NSInteger)meetingChatManager_fetchCurrentNodeId:(nullable NSString *)threadId;
- (nonnull NSString *)meetingChatManager_fetchCurrentSessionId;
- (BOOL)meetingChatManager_canChat;
@end

@protocol ZMOperatePinMessageProtocal <NSObject>

- (nullable ZMPinMessageInfo *)getTopPinInfo:(nonnull NSString *)sessionId;

- (nullable ZMMessageAdapter *)getTopPinMessage:(nonnull NSString *)sessionId;

- (BOOL)isDisablePinMessage;

- (BOOL)checkIfNeedRefreshTopPinMessage:(nonnull NSString *)sessionId;

- (BOOL)topPinMessage:(long long)msgSvrTime sessionId:(nonnull NSString *)sessionId requestId:( NSString * _Nullable *_Nullable)requestId;

- (BOOL)unTopPinMessage:(long long)msgSvrTime sessionId:(nonnull NSString *)sessionId requestId:( NSString * _Nullable *_Nullable)requestId;

- (BOOL)removePinMessage:(long long)msgSvrTime sessionId:(nonnull NSString *)sessionId requestId:( NSString * _Nullable *_Nullable)requestId;

- (BOOL)hiddenTipPinMessage:(nonnull NSString *)sessionId;

- (BOOL)isNeedHideTopPinMessage:(nonnull NSString *)sessionId;

- (BOOL)isNeedHidePinPoppedTips;

- (void)setHidePinPopedTips;

- (BOOL)syncTopPinMessages:(nonnull NSArray <NSString *> *)sessionIds requestId:( NSString * _Nullable *_Nullable)requestId completion:(nullable ZMCallbackBlock)completion;

- (nullable NSArray <ZMPinMessageInfo *> *)queryPinMessageHistory:(nonnull NSString *)sessionId startMsgTime:(long long)startMsgTime count:(NSInteger)count requestId:( NSString * _Nullable *_Nullable)requestId hasMore:(BOOL *_Nullable)hasMore error:(NSError *_Nullable *_Nullable)error completion:(nullable ZMCallbackBlock)completion;

- (void)cancelPinOperateByRequestId:(nonnull NSString *)requestId;

@end

@protocol ZMOperatePinMessageCallbackProtocal <NSObject>

- (void)didTopPinMessage:(nonnull ZMPinMessageCallback *)callback;

- (void)didUnTopPinMessage:(nonnull ZMPinMessageCallback *)callback;

- (void)didRemovePinMessage:(nonnull ZMPinMessageCallback *)callback;

- (void)didSyncTopPinMessage:(nonnull ZMPinMessageCallback *)callback;

- (void)didQueryPinMessageHistory:(nonnull ZMPinMessageCallback *)callback;

@end

@protocol ZMScheduleChannelMeetingProtocol <NSObject>

- (void)didReceiveChannelMeetingList:(ZMScheduleMeetingCallback * _Nonnull)callback;
- (void)didReceiveMeetingMemberChanged:(ZMChannelMeetingEvent * _Nonnull)channelMeetingEvent;
- (void)didReceiveMeetingStatusChanged:(ZMChannelMeetingStatus * _Nonnull)channelMeetingStatus;
- (void)didReceiveSearchMeetingAttendees:(ZMChannelMeetingAttendeeEvent *_Nonnull)attendeeEvent;

@end

@protocol ZMPersistentMeetingsChatProtocol <NSObject>

- (void)didReceivePMCMeetingInfoChanged:(nonnull NSString *)groupId;

@end

@protocol ZMBotProtocol<NSObject>

- (BOOL)chatAppsGetBotsList:(nonnull NSString *)key req:(NSString *_Nullable*_Nullable)reqID;
- (BOOL)chatAppsAddBotsToChannel:(nonnull NSArray<NSString*>*)jids channel:(nonnull NSString*)channelID req:(NSString *_Nullable*_Nullable)reqID;
- (BOOL)chatAppsRemoveBotsFromChannel:(nonnull NSArray<NSString*>*)jids channel:(nonnull NSString*)channelID req:(NSString *_Nullable*_Nullable)reqID;

@end

@protocol ZMIMSinkProtocol <NSObject>

- (void)zmIMMessageHelper_registerMeetingUISink;
- (void)zmIMMessageHelper_unregisterMeetingUISink;

@end

@protocol ZMMessageGetterProtocol

- (nonnull NSString *)getBroadcastID;
- (nonnull NSString*)localStorageTimeStringForPersonalChannel;
- (nonnull NSString*)localStorageTimeString;
@end

@protocol ZMMeetingChatCardMessageProtocal <NSObject>

- (BOOL)syncMCCMessageWithPara:(nonnull ZMMeetingChatCardEntity*)para needsLastvalue:(BOOL)needsLastvalue;

- (void)didSyncMCCMessages:(nonnull ZMMCCSyncMessageResult*)syncResult;

- (nullable NSArray<ZMMessageAdapter*>*)getMCCLocalMessagesWithSessionID:(nonnull NSString *)sessionID messageID:(nonnull NSString *)messageID;

- (BOOL)syncMCCParticipantWithPara:(nonnull ZMMeetingChatCardReqParticipantsPara*)para;

- (nullable NSArray<ZMBuddyAdapter*>*)getMCCLocalParticipantsWithSessionID:(nonnull NSString *)sessionID messageID:(nonnull NSString *)messageID;

- (void)didSyncMCCParticipants:(nonnull ZMMCCSyncParticipantsResult*)syncResult;

- (nullable NSArray<ZMBuddyAdapter*>*)syncMCCLocalSearchParticipantWithSessionID:(nonnull NSString* )sessionID messageID:(nonnull NSString *)messageID key:(nonnull NSString *)key;

@end

@protocol ZMReminderMessageProtocol<NSObject>

- (BOOL)setReminderMessage:(ZMMessageAdapter* _Nonnull)message timeout:(NSInteger)timeout note:(NSString* _Nullable)note
                   context:(ZMReminderMessageContext)context;

- (BOOL)setReminderMessage:(ZMMessageAdapter* _Nonnull)message timeout:(NSInteger)timeout note:(NSString* _Nullable)note
                   context:(ZMReminderMessageContext)context
                completion:(ZMCallbackBlock _Nonnull)block;

- (BOOL)removeReminderMessage:(ZMMessageAdapter* _Nonnull)message
                      context:(ZMReminderMessageContext)context;

- (BOOL)removeReminderMessage:(ZMMessageAdapter* _Nonnull)message
                      context:(ZMReminderMessageContext)context
                   completion:(ZMCallbackBlock _Nonnull)block;

- (BOOL)removeReminderMessageByServerTime:(long long)serverTime session:(NSString* _Nonnull)sessionId
                                  context:(ZMReminderMessageContext)context;

- (BOOL)removeReminderMessageByServerTime:(long long)serverTime session:(NSString* _Nonnull)sessionId
                                  context:(ZMReminderMessageContext)context
                               completion:(ZMCallbackBlock _Nonnull)block;

- (NSString* _Nullable)syncReminderMessages;
- (NSString* _Nullable)syncReminderMessages:(ZMCallbackBlock _Nonnull)block;

- (BOOL)isReminderMessageEnabled;
- (BOOL)isReminderMessage:(ZMMessageAdapter* _Nonnull)message;

- (BOOL)reminderizableByServerTime:(long long)message sessionId:(NSString* _Nonnull)sessionId;

- (NSInteger)reminderMessageUnreadCount;
- (NSInteger)reminderMessageUnreadCountReset:(long long)serverTime;
- (NSInteger)reminderMessageCount;

- (NSArray* _Nonnull)reminderMessageArray;

- (NSInteger)reminderMessageExpiryTimeoutMin;
- (NSInteger)reminderMessageExpiryTimeoutMax;
- (NSInteger)reminderMessageCountMax;
- (NSInteger)reminderMessageNoteLengthMax;

- (NSArray<NSString*> * _Nonnull)reminderMessageBodyByServerTime:(long long)serverTime sessionId:(NSString* _Nonnull)sessionId;

- (ZMReminderMessageStatus)reminderStatusForCode:(NS_ZOOM_MESSAGER::ReminderMessageStatus)status;
- (ZMReminderMessageEvent)reminderEventForCode:(NS_ZOOM_MESSAGER::ReminderEvent)event;

@end

@protocol ZMGradientLabelProtocol<NSObject>

- (NSString* _Nonnull)gradientLabelInitializeKey;
- (NSString* _Nonnull)gradientLabelClickedKey;

- (BOOL)setGradientLabelTimestamp:(NSString* _Nonnull)key;
- (NSInteger)getGradientLabelTimestamp:(NSString* _Nonnull)key;

@end

@protocol ZMReminderMessageCallbackProtocol <NSObject>

- (void)didSetReminderMessage:(ZMReminderMessageInfo * _Nonnull)reminder;
- (void)didRemoveReminderMessage:(ZMReminderMessageInfo * _Nonnull)reminder;
- (void)didExpireReminderMessage:(ZMReminderMessageInfo * _Nonnull)reminder;
- (void)didSyncReminderMessages:(NSString * _Nonnull)requestId;
- (void)didUpdateReminderUnreadCount:(NSInteger)count;
- (void)needsReminderMessagesSync;

@end

@protocol ZMChatAppProtocol

- (nullable NSArray<ZMChatAppInfo*>*)getChatAppComposeShortcuts;
- (nullable NSArray<ZMChatAppShortcutInfo*>*)getChatMessageShortcuts;
- (void)setChatAppContextWithSessionID:(NSString * _Nullable)sessionID threadID:(NSString * _Nullable)threadID;

//call back from webView
- (void)didReceiveChatAppMessagePreviewInfoFromWebView:(nonnull ZMChatAppMessagePreviewInfo*)syncResult;

@end

@protocol ZMMessageProtocol <ZMSyncMessageProtocal,ZMSyncMessageCallback,ZMCheckMessageProtocal,ZMOperateMessageProtocol,ZMOperateMessageCallback,ZMOperateReactionProtocal,ZMListenMessageProtocal,ZMSendMessageProtocal,ZMOperatePinMessageProtocal,ZMOperatePinMessageCallbackProtocal,ZMSyncSessionUnreadCallback,ZMEmojiProtocol,ZMGiphyProtocol,ZMGiphyCallbackProtocol,ZMStickerProtocol,ZMLinkPreviewProtocol,ZMBotProtocol,ZMMessageGetterProtocol,ZMScheduleChannelMeetingProtocol,ZMReminderMessageProtocol,ZMReminderMessageCallbackProtocol,ZMGradientLabelProtocol,ZMMeetingChatCardMessageProtocal,ZMChatAppProtocol,ZMPersistentMeetingsChatProtocol,ZMIMInputCustomButtonMgrProtocol>
@end

#ifndef ZMShareMessageProtocol
#define ZMShareMessageProtocol (id <ZMMessageProtocol>)ZMSharedFor(ZMMessageProtocol)
#endif

#endif /* ZMMessageProtocol_h */

