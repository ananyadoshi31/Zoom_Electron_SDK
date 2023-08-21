//
//  ZMBubbleObject.h
//  ZMTipWindowDemo
//
//  Created by Francis Zhuo on 2/9/21.
//  Copyright © 2021 Francis Zhuo. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMArrowAlignment){
    ZMArrowAlignmentCenter,
    ZMArrowAlignmentLeft,
    ZMArrowAlignmentRight,
    
    ZMArrowAlignmentTop = ZMArrowAlignmentLeft,
    ZMArrowAlignmentBottom = ZMArrowAlignmentRight,
};

typedef NS_ENUM(NSInteger, ZMBubbleAppearance){
    ZMBubbleAppearanceSystem,
    ZMBubbleAppearanceLight,
    ZMBubbleAppearanceDark,
};

typedef NS_ENUM(NSInteger, ZMBubbleConstrainFrameMode){
    ZMBubbleConstrainFrameModeScreen,
    ZMBubbleConstrainFrameModeWindow,
    ZMBubbleConstrainFrameModeScreenAndWindow,
    ZMBubbleConstrainFrameModeBlock,
    ZMBubbleConstrainFrameModeCustom,//if ConstrainFrame equal to NSZeroRect will not constain
};

typedef NS_ENUM(NSUInteger, ZMBubbleArrowSizeMode) {
    ZMBubbleArrowSizeModeDefault,
    ZMBubbleArrowSizeModeRegular,
    ZMBubbleArrowSizeModeSmall,
    ZMBubbleArrowSizeModeNone,
    ZMBubbleArrowSizeModeCustom,
};

@interface ZMBubbleConfig : NSObject
@property(nonatomic, assign) ZMBubbleArrowSizeMode arrowSizeMode;
@property(assign) NSSize arrowSize;
@property(assign) CGFloat arrowRadius;//suggest arrowSize.height/2
@property(assign) ZMArrowAlignment alignment;//default ZMArrowAlignmentCenter

@property(assign) CGFloat minWidth;
@property(assign) CGFloat maxWidth;
@property(assign) CGFloat minHeight;
@property(assign) CGFloat maxHeight;

@property(assign) NSEdgeInsets margin;

@property(nonatomic, assign) ZMBubbleAppearance appearance;//default ZMBubbleAppearanceSystem
@property(nullable, copy) NSColor* backgroundColor;
@property(nullable, copy) NSColor* borderColor;
@property(assign) CGFloat borderWidth;
@property(assign) CGFloat cornerRadius;

@property(assign) BOOL canBecomeKey;
@property(assign) BOOL makeKeyWhenOrderFront;
@property(assign) BOOL careMouseMoveEvent;
@property(assign) BOOL relayoutWhenPositionViewRectChanged;
@property(assign) BOOL preferUseCacheArrowEdge;//default YES

@property(assign) ZMBubbleConstrainFrameMode constrainFrameMode;//default ZMBubbleConstrainFrameModeScreen
@property(assign) NSEdgeInsets constrainFrameMargin;//default NSEdgeInsetsZero
@property(copy) NSRect (^constrainFrameBlock)(NSView* positioningView);

/**
 return  rectangle in positioningView coordinates.
 */
@property(copy) NSRect (^positioningRectBlock)(NSView* positioningView);

@property(nullable, readonly, weak) NSView* positioningView;

@property(nullable, copy) BOOL (^forwardFirstResponder)(void);

@property(assign) NSInteger relativeWindowLevel;

+ (instancetype)defautConfig;
+ (instancetype)smallConfig;
@end

@interface ZMBubbleObject : NSObject
@property(nullable, retain) NSViewController* contentViewController;
@property(nullable, nonatomic, retain) NSView* contentView;
@property(nullable, retain) ZMBubbleConfig* config;
@property(readonly) BOOL isShowing;
@property(readonly) NSWindow* bubbleWindow;
@property(nullable, nonatomic, retain) id representedValue;

@property(copy) void (^escAction)(ZMBubbleObject* bubbleObj);
@property(copy) void (^mouseEventAction)(ZMBubbleObject* bubbleObj,NSEvent* event);

@property(copy) NSString* (^accessibilityBlock)(void);

- (void)cleanUp;
- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;
- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge constrainFrame:(NSRect)constrainFrame;
- (void)relayout;
- (void)close;

- (BOOL)isMouseActionOnContentView:(NSEvent*)event;
- (BOOL)isMouseActionOnPositionView:(NSEvent*)event;
@end

NS_ASSUME_NONNULL_END
