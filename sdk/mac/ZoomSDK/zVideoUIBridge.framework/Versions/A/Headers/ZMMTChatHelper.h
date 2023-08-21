//
//  ZMMTChatHelper.h
//  VideoUIBridge
//
//  Created by Cain Zhou on 2022/11/8.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;

#ifdef __cplusplus
class IZoomChatInWebinar;
#endif

#ifdef __cplusplus
extern "C" {
#endif
ZMConfSession *ZMMTChatGetCurrentSession(void);
#ifdef __cplusplus
}
#endif

@interface ZMMTChatHelper : ZMBaseHelper

#ifdef __cplusplus
- (nullable IZoomChatInWebinar *)fetchWebinarChatComponent;
- (PANELIST_CHAT_PRIVILEGE)fetchPanelistChatPrivilege;
#endif
- (uint8_t)fetchAttendeeChatPrivilege;
- (BOOL)isWebinarChatSettingEnabled;

//chat permission
- (BOOL)isPrivateOff;
- (BOOL)isChatDisabledByInfoBarrier;
- (BOOL)isChatOff;
- (BOOL)isChatDisabledByServer;
- (NSInteger)getChatDisabledReasons;
- (BOOL)isChatDisabledByDLP;
- (BOOL)isChatDisabledByRegulatedUserJoinE2EEMeeting;

// save chat
- (BOOL)hasSaveChatPrivilege; // show up the save chat item
- (BOOL)enableSaveChat; // enable to click the save chat item
- (BOOL)isSaveChatOff;

// user
- (BOOL)isUserInSilentMode:(int)uid;
- (BOOL)isGuestByUser:(ZMUser *)zmUser; // the condition is not connected with the guest web setting, which is different from `zmUserHelper`
- (int)fetchWebinarChattedAttendeeCount;

// copy chat
- (BOOL)hasCopyChatPrivilege;
- (BOOL)isCopyChatEnabled;

// delete chat
- (BOOL)hasDeleteChatPrivilege:(NSString *)messageId;
- (void)deleteMessage:(NSString *)messageId;
- (BOOL)isDeleteChatEnabled;

// message
- (int)fetchMessageCount;
- (nullable NSString *)fetchMessageIDByIndex:(int)index isNotification:(BOOL *)isNotification;
#ifdef __cplusplus
- (nullable CmmChat::ICmmChatMessageItem *)fetchMessageByID:(NSString *)messageId;
#endif
- (void)notifyUnreadMessageCount:(int)num;

// tip of legal notice: who can see your messages
- (BOOL)isNoticeAvailable;
- (BOOL)isCMRNoticeAvailable;
- (BOOL)isLocalRecordingNoticeAvailable;
- (BOOL)isArchiveNoticeAvailable;

// file
- (BOOL)isFileTransferEnabled;
- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString *)messageId needShowCheck:(BOOL *)needShow;
#ifdef __cplusplus
- (BOOL)IsDropBoxInMeetingOn:(FileIntegrationOperation)op;
- (ssb_xmpp::XmppError)uploadFile:(NSString *)filePath
     toUser:(int)userID
chatMsgType:(ChatMsgType)msgType;
- (ssb_xmpp::XmppError)downloadFile:(NSString *)filePath
  messageID:(NSString *)msgID;
- (BOOL)shareFileIntegrationTo:(int)receiveID
                       content:(const ShareFileInMeetingChatParam_s &)fileInfo
                   chatMsgType:(ChatMsgType)msgType;
#endif
- (BOOL)filePause:(NSString *)msgID;
- (BOOL)fileResume:(NSString *)msgID;
- (BOOL)fileCancel:(NSString *)msgID;
- (uint64_t)fetchFileTransferLimitSize; // Can be 0 if sdk makes some error.
- (unsigned long long)fetchMaxFileSize; // if `fetchFileTransferLimitSize` is 0, will return `512M`.
- (BOOL)isFileSizeFailed:(unsigned long long)size;
- (BOOL)isFileTypeBlocked:(NSString *)path;
- (BOOL)isFileTransferDisabledByInfoBarrier;
- (BOOL)isFileDisabledByInfoBarrier; // with `isFileTransferDisabledByInfoBarrier` || `isChatDisabledByInfoBarrier`

// webinar
- (void)updateChattedAttendees;
- (void)changeAttendeeChatPrivilege:(NSInteger)privilege;
- (void)changePanelistChatPriviledge:(NSInteger)privilege;

// window
- (BOOL)isPopupChatWindowEnabled;

/* send messages for meeting & webinar
   params:
     - to user group: `receiverId` is `0`;
   ZOOM-46301: to silent users;
 */
#ifdef __cplusplus
- (BOOL)sendMessage:(NSString *)content to:(int)receiverId chatMsgType:(ChatMsgType)msgType;
- (BOOL)isSilentModeMessageType:(ChatMsgType)type;
#endif

// new chat & pmc
- (BOOL)isPMCNewExperienceEnabled;
- (NSString *)fetchNewChatSessionId;

@end

NS_ASSUME_NONNULL_END
