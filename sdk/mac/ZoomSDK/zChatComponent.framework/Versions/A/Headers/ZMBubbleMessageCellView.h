//
//  ZMBubbleMessageCellView.h
//  ZCommonUI
//
//  Created by groot.ding on 21/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <zChatComponent/ZMBaseMessageCellView.h>
#import <zChatComponent/ZMMessageBubbleView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAvatarView;
@class ZMMessageBubbleView;
@class ZMReactionContainarView;
@class ZMStackView;
@class ZMButton;
@class ZMIMImageButton;
@class ZMIMOnlyImageButton;
@class ZMCopyMessageInfo;

static const NSInteger kDefaultReminderBubbleTopToBottom = 2;

@interface ZMBubbleMessageCellView : ZMBaseMessageCellView

@property (nonatomic,retain) ZMAvatarView* avatarView;

@property (nonatomic,retain) NSTextView *nameTextView;

@property (nonatomic,retain) NSTextField *unreadTextField;

@property (nonatomic,retain) NSTextField* dateField;

@property (nonatomic,retain) ZMMessageBubbleView *bubbleView;

@property (nonatomic,retain) ZMReactionContainarView* reactionView;

@property (nonatomic,retain) ZMReminderContainerView* reminderView;

@property (nonatomic,assign,getter=isSelectedBubble) BOOL selectedBubble;

@property (nonatomic,readonly) BOOL isShowDecodeFail;

@property (readonly, assign) CGFloat bubbleTop;
@property (readonly, assign) CGFloat bubbleLeading;
@property (readonly, assign) CGFloat bubbleHeight;
@property (readonly, assign) CGFloat bubbleWidth;

- (BOOL)isUnreadViewVisible;

- (void)updateNameView;
- (void)updateAvatarView;
- (void)updateBubbleView;
- (void)updateReminderViewLayout:(NSInteger)topToBottom;
- (void)updateToolButtonsStatus;
- (CGFloat)buttonsViewLeadingConstraintConstant;

- (void)mouseDownInBubbleView;

- (ZMCopyMessageInfo *)getCopyMessageInfo;


- (void)onMouseEntered;
- (void)onMouseExited;
@end

NS_ASSUME_NONNULL_END
