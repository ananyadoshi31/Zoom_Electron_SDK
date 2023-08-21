//
//  ZMMessageUIMgrProtocol.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/8/5.
//

#ifndef ZMMessageUIMgrProtocol_h
#define ZMMessageUIMgrProtocol_h

@class ZMFileEntity, ZMMessageAdapter, ZPZAppHeader, ZMChatAppShortcutInfo;
@protocol ZMMessageUIMgrProtocol

- (void)deleteHybridItem:(nullable ZMFileEntity *)fileItem;

- (void)topPinMessage:(nullable ZMMessageAdapter *)message;
- (void)unTopPinMessage:(nullable ZMMessageAdapter *)message;
- (void)hideTopPinMessage:(nullable ZMMessageAdapter *)message;
- (void)removePinMessage:(nullable ZMMessageAdapter *)message;

- (void)tryToCreateDocWithType:(NSInteger)type sessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID nodeID:(nullable NSString*)nodeID;
- (BOOL)tryToShareWithMessage:(nullable ZMMessageAdapter *)message;
- (void)uploadLocalSharePointFileInSession:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID nodeID:(nullable NSString*)nodeID;
- (void)didGetRootNodeInfoWithSessionID:(nullable NSString*)sessionID rootNodeID:(nullable NSString*)nodeID requestID:(nullable NSString*)requestID;

- (void)selectedSessionWithToNumber:(nullable NSString *)toNumber toName:(nullable NSString *)toName;

- (void)jumpToChatByMessage:(nullable ZMMessageAdapter *)message highlightBubble:(BOOL)highlight highlightBackground:(BOOL)highlightBackground;

- (void)jumpToChatByMessage:(nullable ZMMessageAdapter *)message highlightBubble:(BOOL)highlight highlightBackground:(BOOL)highlightBackground shouldCleanUnread:(BOOL)shouldCleanUnread;

- (BOOL)openShareLink:(nullable NSString*)shareLinkURL;

- (void)startChatBySessionId:(nullable NSString *)Id;

- (BOOL)openChatWithPeerJid:(nullable NSString*)peerJid andCurrentSession:(nullable NSString*)inSession;

- (void)closeAdvanceSearch;

- (void)showCommonAppEditFailedToastWith:(nullable NSString*)messageID sessionID:(nullable NSString*)sessionID;

- (void)showJoinMeetingMenuWithNumber:(nullable NSString*)number withStyle:(NSInteger)style contentView:(nullable NSView *)contentView point:(NSPoint)point sessionID:(nullable NSString*)sessionID;

- (void)beginEditCommonAppMessageWithInfo:(nullable NSDictionary*)info;

- (void)previewPublicChanelWithChannelId:(nullable NSString *)channelId channelName:(nullable NSString*) channelName attachedWindow:(nullable NSWindow*)inWindow;

- (void)sendAddonActionWithInfo:(nullable NSDictionary*)dict sessionID:(nullable NSString*)sessionID;


- (BOOL)switchToZappView:(nullable NSString *)appId appUuid:(nullable NSString*)appUuid;
- (void)getZappHeadById:(nullable NSString *)appId completion:(void (^_Nullable)(ZPZAppHeader * _Nullable header, NSError * _Nullable error))completion;
- (void)openZapp:(nonnull ZMChatAppShortcutInfo *)zappInfo;

- (NSInteger)sessionViewWidth:(nullable NSString *)sessionId;

- (NSInteger)getCallMeetingStatus:(nullable NSNotification *)notification;

- (nullable NSWindow *)mainIMResponsibleWindow;

- (void)checkScreenShotCaptureSettingOption;

/* Set fileIntegrationParmaDict in ZMMessageManager:
 (ZOOM-401850) sharing file integration in meeting chat, uses its custom open-url flow, and calls back to IM sending flow
*/
-(void)fileIntegrationDictSetObject:(nullable id)obj forKey:(nullable id)key;

/**
 show all participants in a Meeting Chat
 */
- (void)showMCCMembersPanel:(nullable NSString *)meetingID sessionID:(nullable NSString*)sessionID messageID:(nullable NSString*)messageID;

//zapp
- (BOOL)checkAppInstalled:(nullable NSString *)appId completion:(ZMCallbackBlock _Nonnull )completion;
- (nullable NSImage *)getZappImageByName:(nonnull NSString *)name;
@end


#ifndef ZMShareMessageUIMgrProtocol
#define ZMShareMessageUIMgrProtocol (id <ZMMessageUIMgrProtocol>)ZMSharedFor(ZMMessageUIMgrProtocol)
#endif

#endif /* ZMMessageUIMgrProtocol_h */
