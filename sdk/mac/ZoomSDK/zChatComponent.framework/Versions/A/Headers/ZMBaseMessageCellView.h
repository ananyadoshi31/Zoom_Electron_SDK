//
//  ZMBaseMessageCellView.h
//  ZCommonUI
//
//  Created by groot.ding on 17/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMBaseTableCellView.h>
#import <ZoomKit/ZMTextView.h>
#import <ZoomKit/ZMMutableSelectProtocal.h>
#import <zChatComponent/ZMMessageItemInfo.h>
#import <zChatComponent/ZMMessageLayoutManager.h>
#import <zChatComponent/ZMMessageCellViewDelegate.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseMessageCellView : ZMBaseTableCellView <ZMMutableSelectProtocal,ZMTextViewDelegate,ZMCustomReuseViewProtocal>

@property (nonatomic,readonly) ZMMessageItemInfo *item;

@property (nonatomic,retain) ZMMessageLayoutManager *layoutManager;

@property (nonatomic,weak) id <ZMMessageCellViewDelegate> delegate;

- (NSSize)calculateMessageByMaxWidth:(CGFloat)width;

- (NSSize)calculateReactionByMaxWidth:(CGFloat)width;

- (NSSize)calculateReminderByMaxWidth:(CGFloat)width;

- (CGFloat)fitHeight;

- (NSSize)emptyMessageSize;

- (void)onMouseEntered;

- (void)asyncNotifyCellViewSizeChanged;

- (void)notifyCellViewSizeChanged;

- (void)notifyCellViewSizeChangedWithoutReloading;

- (void)updateBackgroundColorWithAnimation;


@end

NS_ASSUME_NONNULL_END
