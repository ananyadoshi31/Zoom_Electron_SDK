//
//  IZMMTWhiteboardMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTWhiteboardDashboard;
@class ZMMTWhiteboardViewController;
@protocol IZMMTWhiteboardMgr <ZMRoutableObject>

@property (nonatomic, readonly) ZMMTWhiteboardDashboard *dashboard;
- (ZMMTWhiteboardViewController*)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isPresentingWhiteboard;
- (BOOL)isViewingWhiteboard;
- (BOOL)isInWhiteboardMode;

- (BOOL)isReceivingWhiteboard;
- (BOOL)isAnyoneInWhiteboardMode;
- (BOOL)isWhiteboardSettingLocked;
- (int)viewRole;

- (NSUInteger)viewableWhiteboardCount;
- (NSString *)viewableWhiteboardId;
- (ZMUser *)viewableWhiteboardUser;

- (BOOL)isAllowShareWhiteboard;
- (void)setAllowShareWhiteboard:(BOOL)allowed;

- (void)showAllStatusWnd;
- (void)hideAllStatusWnd;
- (void)showWhiteboardSetting;
- (void)showDashboard;
- (void)closeDashboard;

- (void)startShareWhiteboard:(nullable NSString *)docId templateId:(nullable NSString*)templatedId;
- (void)stopShareWhiteboard;
- (void)stopAllWhiteboards;

//Native Sink
- (void)onDocumentStatusChanged:(NSString*)docId status:(int)status;
- (void)onActiveSourceChanged:(NSString*)docId userID:(ZMUserID)userID;
- (void)onPresenterChanged:(NSString*)docId userID:(ZMUserID)userID;
- (void)onShareRoleChanged:(NSString*)docId role:(int)role;
- (void)onDocumentDeleted:(NSString*)docTitle;
- (void)onStartShare;
- (void)onStopShare;
//Web Sink
- (void)onWebWBEvent:(int)event docId:(NSString*)docId userID:(ZMUserID)userID;

@end

@protocol IZMMTWhiteboardStatusProtocol <NSObject>

- (void)onPermissionChanged;

- (void)onWindowDidEnterFullScreen:(NSWindow*)window;
- (void)onWindowDidExitFullScreen:(NSWindow*)window;
- (void)onWindowDidMove:(NSWindow*)window;
- (void)onWindowDidResize:(NSWindow*)window;

@end

NS_ASSUME_NONNULL_END
