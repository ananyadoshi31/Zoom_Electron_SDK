//
//  ZMInnerFocusRingTableView.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMInnerFocusRingTableView : NSTableView
{
    CALayer *_innerFocusRingLayer;
    BOOL _isFirstResponder;
    BOOL _usesInnerFocusRingOnEnclosingScrollView;
}

@property (nonatomic) IBInspectable BOOL usesInnerFocusRingOnEnclosingScrollView;
@property (retain, readonly) CALayer *innerFocusRingLayer;

- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;
- (void)viewWillMoveToSuperview:(nullable NSView *)newSuperview NS_REQUIRES_SUPER;
- (void)viewDidMoveToSuperview NS_REQUIRES_SUPER;

@end

@interface ZMInnerFocusRingOutlineView : NSOutlineView
{
    CALayer *_innerFocusRingLayer;
    BOOL _isFirstResponder;
    BOOL _usesInnerFocusRingOnEnclosingScrollView;
}

@property (nonatomic) IBInspectable BOOL usesInnerFocusRingOnEnclosingScrollView;
@property (retain, readonly) CALayer *innerFocusRingLayer;

- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;
- (void)viewWillMoveToSuperview:(nullable NSView *)newSuperview NS_REQUIRES_SUPER;
- (void)viewDidMoveToSuperview NS_REQUIRES_SUPER;

@end
NS_ASSUME_NONNULL_END
