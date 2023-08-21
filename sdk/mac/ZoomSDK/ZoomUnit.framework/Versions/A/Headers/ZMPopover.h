//
//  ZMPopover.h
//  TestHHH
//
//  Created by Yang on 1/17/17.
//  Copyright © 2017 Yang. All rights reserved.
//



@class ZMPopoverView;
@class ZMPopoverWindow;
@protocol ZMPopoverDelegate;

@interface ZMPopover : NSObject <ZMObjectDispose>
{
    @private
    ZMPopoverWindow * _window;
    ZMPopoverView * _popoverView;
    CGFloat _distance;
    BOOL _holding;
    BOOL _wantsDisppear;
    BOOL _holdWhenMouseHover;
}

+ (instancetype)popover;
- (void)showAtHostView:(NSView *)hostView makeKey:(BOOL)makeKey;
- (void)forceClose;
- (void)disappearWithDaley:(NSTimeInterval)daley;
- (void)cancelDisappearing;

@property (retain, nonatomic) IBOutlet NSView * contentView;
@property (assign) BOOL holdWhenMouseHover; //!<default is No.
@property (assign, nonatomic) BOOL showTriangle; //!<default is Yes.
@property (weak) id <ZMPopoverDelegate> delegate;

@property(readonly, getter=isShown) BOOL shown;

@end

@protocol ZMPopoverDelegate <NSObject>
@optional
- (void)popoverWillShow:(ZMPopover *)popover;
- (BOOL)popoverShouldDisappear:(ZMPopover *)popover;
- (void)popoverDidDisappeared:(ZMPopover *)popover;

@end





