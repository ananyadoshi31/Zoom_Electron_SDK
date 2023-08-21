//
//  ZMMeetingMessageProtocol.h
//  zChatComponent
//
//  Created by Jeffery Lin on 11/8/2022.
//

#ifndef ZMMeetingMessageProtocol_h
#define ZMMeetingMessageProtocol_h
#import <Foundation/Foundation.h>

@protocol ZMMeetingMessageProtocol <ZMRoutableObject>

@optional

- (BOOL)canSendToIMUser:(NSString *)userId messageType:(NSInteger)messageType;
- (void)selectChatToWithInfo:(NSDictionary *)info;
- (NSInteger)getMsgType;
- (NSString *)getReceiveUserId;
- (NSImage *)getAvatarByConfUserId:(NSString *)confUserId senderName:(NSString *)senderName messageType:(NSInteger)type;
//- (void)showFileMenuWithButton:(NSButton *)sender;
- (BOOL)checkFileSizeFailed:(unsigned long long)size;
- (BOOL)checkFileTypeFailed:(NSString *)path;
- (void)shareFailedWithReason:(NSString *)reason;
- (unsigned long long)getMaxFileSize;
- (BOOL)meeting_isSilentMode;
- (BOOL)checkErrorWithSessionId:(NSString *)sessionId threadId:(NSString *)threadId;
- (BOOL)isMyDLPEnabled;
- (ZMDLPPolicyResult *)checkDLPPolicyWithConent:(NSString *)content;
- (BOOL)isTeamChatEnabled;
- (BOOL)isPMCForBackendEnabled;
- (NSString *)getAccountId;
- (void)showChatDeletedByDlpAlert;
- (BOOL)amIhostCohost;
- (void)showChatDLPBlockAlert;
- (void)showChatDLPCheckAlertWithConfirm:(void(^)())actionConfirm;
@end

#endif /* ZMMeetingMessageProtocol_h */
