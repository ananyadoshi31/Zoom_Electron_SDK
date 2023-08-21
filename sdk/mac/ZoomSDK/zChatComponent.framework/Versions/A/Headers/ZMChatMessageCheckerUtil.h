//
//  ZMChatMessageCheckerUtil.h
//  ZoomMsgUI
//
//  Created by Yong Zhou on 5/17/22.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMFileConstants.h>

@class ZMFileEntity;
@class ZMMessageAdapter;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMSecurityAlertProxy <NSObject>

- (BOOL)needAlertForFileEntity:(ZMFileEntity *)fileEntity;
- (BOOL)needShowAlwaysTrustCheckButton:(ZMFileEntity *)fileEntity;

@optional
- (void)didSelectedConfirmButton:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;
- (void)didSelectedCancelButton:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;
- (void)didClosedAlertWithESC:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;

- (NSPoint)alertCenterPosition;

@end

@interface ZMChatMessageCheckerUtil : NSObject

+ (ZMChatMessageCheckerUtil*)sharedInstance;
+ (void)releaseInstance;

+ (BOOL)checkIfBeyondMaximunMessageLength:(NSUInteger)msgLength;

+ (BOOL)checkWithToastWhenSharingFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *)sessionID toastInView:(NSView *_Nullable)view;

+ (NSArray <NSString *> *)validFilesFilterSendingFiles:(NSArray <NSString *> *)filePaths sessionId:(NSString *)sessionId toastInView:(NSView *_Nullable)view;

+ (ZMFileCheckResult)checkValidFileAtPath:(NSString *)path sessionID:(nullable NSString*)sessionID;
+ (ZMFileCheckResult)checkValidFileSizeInSession:(NSString *)sessionID fileSize:(unsigned long long)fileSize;
+ (ZMFileCheckResult)checkFileTypeAndSizeWithFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *_Nullable)sessionID;

+ (ZMToast *)toastForInvalidFileWithErrorType:(ZMFileCheckResult)errorType filePath:(NSString*)filePath inSession:(NSString*_Nullable)sessionID;

+ (BOOL)checkWithToastWhenSaveAsWithFileItem:(nonnull ZMFileEntity *)fileItem fromView:(nullable NSView *)fromView;

+ (BOOL)checkWithToastIfValidFileAtPath:(NSString *)path sessionID:(NSString *)sessionID fromView:(nullable NSView *)fromView;

+ (BOOL)checkIfNeedsShowingTipForSuspiciousLink:(NSString*)suspiciousLink
                                    displayLink:(NSString *_Nullable *_Nullable)displayLink
                                    textStorage:(NSTextStorage*)textStorage
                                      charIndex:(NSInteger)charIndex
                                      sessionId:(NSString *)sessionId;

- (void)showTipForSuspiciousLink:(NSString *)suspiciousLink
                     displayLink:(NSString *)displayLink
                           allow:(void(^)(BOOL result))allowed;

+ (BOOL)needToShowAtAllWarningForMessageBody:(NSAttributedString*)message inSession:(NSString*)session;
- (void)showAtAllWarningInWindow:(NSWindow*)window forSession:(NSString*)session onConfirm:(void (^)(void))userConfirmedSend;

+ (BOOL)needShowPotentialRiskDetectedAlertForFileEntity:(ZMFileEntity *)fileEntity;
- (void)showPotentialRiskDetectedAlertForFileEntity:(ZMFileEntity *)fileEntity
                                           allowed:(void(^)(BOOL result))allowed;
- (void)closePotentialRiskDetectedAlertForSession:(NSString *)sessionId;

+ (BOOL)canSendMessage:(nullable ZMMessageAdapter*)messageAdapter withSessionId:(NSString*)sessionId fromView:(NSView*)fromView;

/* NSString Util */
+ (NSString *)getPathExtensionWithDotFromFile:(NSString *)fileName;

/* long fileName will display in format like abcdefg...xxyz.txt */
+ (NSString *)convertFileNameByTruncatingMiddle:(NSString *)fileName toMaxLength:(NSUInteger)maxLength;

+ (NSString *)convertLongStringByTruncatingTai:(NSString *)aString toMaxLength:(NSUInteger)maxLength;

+ (NSUInteger)getTotalLengthFromInsertLink:(NSArray<ZMMessageFontInfo*> *)fontInfoArray;

/* SuspiciousLink */
+ (BOOL)hasAuthorizedVisitForSuspiciousLink;

+ (void)setAuthorizedVisitForSuspiciousLink;

+ (void)registerSecurityAlertProxy:(id<ZMSecurityAlertProxy>)proxy forSession:(NSString *)sessionId;
+ (void)removeSecurityAlertProxyForSession:(NSString *)sessionId;

@end

NS_ASSUME_NONNULL_END
