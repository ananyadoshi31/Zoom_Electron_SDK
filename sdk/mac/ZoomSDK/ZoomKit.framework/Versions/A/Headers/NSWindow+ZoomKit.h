//
//  NSWindow+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <ZoomKit/ZMBase.h>

typedef NS_OPTIONS(NSUInteger, NSWindowShowAlertType) {
    NSWindowShowAlertNotSpecified = 0,
    NSWindowShowAlertPopup = 1 << 0,
    NSWindowShowAlertSheet = 1 << 1,
};

NS_ASSUME_NONNULL_BEGIN

extern NSString *const KZMJoinMeetingFlowAnchor;

@interface NSWindow (Private)

- (BOOL)_shouldSnapSizeOnDoubleClick;
+ (BOOL)_shouldMiniaturizeOnDoubleClick;
+ (BOOL)_shouldZoomOnDoubleClick;
- (NSDictionary *)shadowParameters;

@end

@interface NSWindow (ZoomKit)

/**
 discard origin touchbar, create a new one
 */
- (void)reloadTouchBar;
- (void)updateTouchBar;

@property NSPoint frameCenter;
@property (readonly) NSPoint boundsCenter;
@property (readonly, getter=isFullScreen) BOOL fullScreen;

//MARK: framw adjust
@property (readonly) NSRectCorner preferredAnchorConner;//default is NSRectCornerBottomLeft;
- (void)setFrameSize:(NSSize)size animate:(BOOL)animate;
- (void)setPosition:(NSPoint)position animate:(BOOL)animate;
- (void)adjustFrameInBoundary:(NSRect)boundary safeDistance:(ZMDistance)distance animate:(BOOL)animate;
- (void)adjustFrameInScreen;

- (void)setFrameSize:(NSSize)size anchorCorner:(NSRectCorner)corner animate:(BOOL)animate;
- (void)setPosition:(NSPoint)position forCorner:(NSRectCorner)corner animate:(BOOL)animate;
- (NSPoint)positionAtCorner:(NSRectCorner)corner;

+ (BOOL)isSafeFrame:(NSRect)frame inBoundary:(NSRect)boundary safeDistance:(ZMDistance)distance;
+ (NSRect)adjustedFrame:(NSRect)frame inBoundary:(NSRect)boundary safeDistance:(ZMDistance)distance;

//MARK: anchor
- (void)anchor:(NSString *)anchorId;
- (void)adjustFrameToAnchor:(NSString *)anchorId;

//MARK: popup mask
APPKIT_EXTERN NSString * const kNSWindowAlertWindowWillBeReplace;
APPKIT_EXTERN NSString * const kNSWindowAlertViewWillBeReplace;

- (NSRect)startRectForSheet:(NSWindow *)sheet;//!< privite API to override
@property (readonly, nonatomic) NSWindowShowAlertType alertType;//!< default is NSWindowShowAlertPopup
@property (readonly, nonatomic) NSWindowShowAlertType advocateAlertTypeOnHostWindow;//!< priority: advocateAlertTypeOnHostWindow > alertType
@property (readonly, nullable, nonatomic) NSView *maskContentView;//!< default is contentView, subclass should override
@property (retain, nullable, nonatomic) __kindof NSView *alertView;//!< mask maskContentView, and popup this View(On a NSPureWindow), set nil will dismiss current alertWindow
@property (retain, nullable, nonatomic) __kindof NSViewController *alertViewController;
@property (retain, nullable, nonatomic) __kindof NSWindow *alertWindow;//!< mask maskContentView, and popup this Window
@property (readonly) NSRectCorner positingCornerInHostWindow;//!< NSRectCornerNotSpecified means center in hostWindow
@property (nonatomic, nullable) NSWindow *hostWindow;//!< do not set this property manually

@property (assign, readonly) NSUInteger masked;//!< Masked by NSVisualEffectView if available

- (void)increaseMask;
- (void)decreaseMask;
- (void)increaseIgnoreClick;
- (void)decreaseIgnoreClick;

@property (readonly, retain, nullable) NSView *maskView;//!< do not maintain this View manually
@property (nonatomic, readonly) NSWindowShowAlertType effectiveAlertType;

#pragma mark - tab/shift+tab
- (BOOL)zmSelectNextKeyView;
- (BOOL)zmSelectPreviousKeyView;

@end
NS_ASSUME_NONNULL_END
