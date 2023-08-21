//
//  ZMWindowBorderView.h
//  ZMResizableWindowDemo
//
//  Created by francis zhuo on 2019/9/5.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMResizeMaskView;
typedef NS_OPTIONS(NSUInteger, ZMResizeEdge) {
    ZMResizeEdgeNone        = 0,
    ZMResizeEdgeWest        = 1<<0,
    ZMResizeEdgeNorthwest   = 1<<1,
    ZMResizeEdgeNorth       = 1<<2,
    ZMResizeEdgeNortheast   = 1<<3,
    ZMResizeEdgeEast        = 1<<4,
    ZMResizeEdgeSoutheast   = 1<<5,
    ZMResizeEdgeSouth       = 1<<6,
    ZMResizeEdgeSouthwest   = 1<<7,
    
    ZMResizeEdge4Side = ZMResizeEdgeWest|ZMResizeEdgeNorth|ZMResizeEdgeEast|ZMResizeEdgeSouth,
    ZMResizeEdgeCorner = ZMResizeEdgeNorthwest|ZMResizeEdgeNortheast|ZMResizeEdgeSoutheast|ZMResizeEdgeSouthwest,
    ZMResizeEdgeAll = ZMResizeEdge4Side|ZMResizeEdgeCorner,
};

NS_ASSUME_NONNULL_BEGIN

@protocol ZMResizeViewDelegate <NSObject>
@optional
- (void)windowStartResize:(NSWindow *)sender;
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize resizedFromEdge:(ZMResizeEdge)edge;
- (void)windowDidResize:(NSWindow *)sender toFrame:(NSRect)frame;
- (void)windowEndResize:(NSWindow *)sender;

- (void)windowStartMove:(NSWindow *)sender;
- (void)windowEndMove:(NSWindow *)sender;

- (void)mouseEnteredView:(NSView*)sender;
- (void)mouseExitedView:(NSView*)sender;
@end

@protocol ZMResizeMaskViewDelegate <NSObject>
@optional
- (void)maskView:(ZMResizeMaskView *)maskView directionEdge:(ZMResizeEdge)edge;
@end

@interface ZMResizeView : ZMTrackingView <ZMResizeMaskViewDelegate>
@property(nonatomic, assign) ZMResizeEdge allowResizeEdge;
@property(nonatomic, assign) ZMResizeEdge resizingEdge;
@property(nonatomic, weak) id<ZMResizeViewDelegate> delegate;

- (BOOL)isMovingWindow;

- (ZMResizeMaskView *)generateMaskViewWithEdge:(ZMResizeEdge)edge;

@end

@interface NSCursor(ZMResize)
+ (NSCursor*)zmResizeEastWestCursor;
+ (NSCursor*)zmResizeNorthSouthCursor;
+ (NSCursor*)zmResizeNorthEastSouthWestCursor;
+ (NSCursor*)zmResizeNorthWestSouthEastCursor;
@end

@interface ZMResizeMaskView : NSView
@property(nonatomic, assign) ZMResizeEdge maskEdge;
@property (nonatomic, weak) id<ZMResizeMaskViewDelegate> delegate;
@end

NS_ASSUME_NONNULL_END


