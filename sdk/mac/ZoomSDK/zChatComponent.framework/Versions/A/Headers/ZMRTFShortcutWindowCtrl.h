//
//  ZMRTFShortcutWindowCtrl.h
//  ZoomMsgUI
//
//  Created by Yong Zhou on 4/26/22.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMRichFormatConstants.h>

@protocol ZMRTFShortcutWindowCtrlDelegate <NSObject>
@optional
- (void)onBoldMenuClicked;
- (void)onStrikeThroughMenuClicked;
- (void)onItalicMenuClicked;
- (void)onBulletedListMenuClicked;
- (void)onNumberedListMenuClicked;
- (void)onMoreButtonClicked;
@end

@interface ZMRTFShortcutWindowCtrl : NSWindowController

@property (nonatomic, weak) id<ZMRTFShortcutWindowCtrlDelegate> delegate;
@property (nonatomic, assign) BOOL reserveStatus;
@property (nonatomic, assign) BOOL disableRichFormat;

+ (instancetype)defaultWindowController;

- (void)setButtonsStatus:(NSInteger)fontStyleInfo;

- (void)selectedNextButton;
- (void)selectedPreviewButton;
- (BOOL)clickSelectedButton;

@end
