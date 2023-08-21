//
//  ZPShareSelectView.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>

@class ZMTrackingView;
@class ZPShareSelectView;
@protocol ZPShareSelectViewDelegate <NSObject>
//respond selectview action
- (void)selectViewDidDoubleClicked:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewDidHovered:(ZPShareSelectView*_Nonnull)view hovered:(BOOL)hovered;
- (void)selectViewWillSelect:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteLeft:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteRight:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteTop:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteBottom:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewDidTabKeyPressed:(ZPShareSelectView*_Nonnull)view isShiftDown:(BOOL)isShiftDown;
- (void)selectViewDidReturnKeyPressed:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillBecomeFirstResponder:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewMoreMenuResponder:(ZPShareSelectView*_Nonnull)view menuTag:(NSInteger)tag;

//setting content
- (NSString *_Nullable)selectViewStringForAxTitle:(ZPShareSelectView*_Nonnull)view;
- (NSString *_Nullable)selectViewStringForToolTip:(ZPShareSelectView*_Nonnull)view;
- (NSString *_Nullable)selectViewStringForDisabledInfo:(ZPShareSelectView*_Nonnull)view;
- (BOOL)selectViewIsDesktopType:(ZPShareSelectView*_Nonnull)view;
- (ZMShareSelectItemType)selectViewShareType:(ZPShareSelectView*_Nonnull)view;
- (NSDictionary<NSNumber *, NSString *>*_Nullable)selectViewMoreMenu:(ZPShareSelectView*_Nonnull)view;
- (NSNumber *_Nullable)moreMenuSelectedStatus:(ZPShareSelectView*_Nonnull)view;
@end

@interface ZPShareSelectView : ZMTrackingView {
    
    BOOL _selected;
    BOOL    _valid;
    BOOL    _enabled;
}

@property (nonatomic, weak, readwrite, nullable) NSImageView *imageView;
@property (nonatomic, weak, readwrite, nullable) NSTextField *nameField;

@property (nonatomic, assign, readwrite) BOOL selected;
@property (nonatomic, assign, getter=isValid)   BOOL valid;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
@property (nonatomic, weak, nullable) id<ZPShareSelectViewDelegate> viewDelegate;

- (void)cleanUp;

@end
