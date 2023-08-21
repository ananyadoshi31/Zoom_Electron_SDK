//
//  ZMBaseView.h
//  zChatUI
//
//  Created by Huxley on 2018/3/29.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <ZoomKit/ZMBase.h>
#import <ZoomKit/ZMAccessibleView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseView : ZMAccessibleView

- (void)commonInit;//!< to override

@property (nonatomic, nullable, copy) IBInspectable NSColor *zmBackgroundColor;
@property (nonatomic, nullable) CGColorRef cgBackgroundColor;

@property (nonatomic) IBInspectable CGFloat cornerRadius;

@property (nonatomic) IBInspectable CGFloat borderWidth;
@property (nonatomic, nullable, copy) IBInspectable NSColor *borderColor;
@property (nonatomic, nullable) CGColorRef cgBorderColor;

@property (nonatomic) BOOL needsRelayout;//logic like needsDisplay
- (void)relayout;//call this will force relayout

@property (weak, nullable) id <ZMViewProviding> controller;
- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;

@property (getter=isFlipped) BOOL flipped;

@property (nonatomic, assign) BOOL shouldAcceptsFirstMouseEvent;
@property (assign)BOOL ignoreViewLiftCircleWhenMoveToWindow;//default is NO, for 10.9
@property (nonatomic, assign) NSRectCorner cornerMask;
@end

@interface ZMNonLayerBaseView : ZMBaseView
@end

NS_ASSUME_NONNULL_END
