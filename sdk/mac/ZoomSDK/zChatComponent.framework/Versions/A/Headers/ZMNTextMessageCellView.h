//
//  ZMNTextMessageCellView.h
//  ZCommonUI
//
//  Created by groot.ding on 24/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <zChatComponent/ZMBubbleMessageCellView.h>
@class ZMMessageAccessoryView;

NS_ASSUME_NONNULL_BEGIN

@interface ZMNTextMessageCellView : ZMBubbleMessageCellView

@property (nonatomic,retain) NSTextView *messageTextView;

@property (nonatomic,retain) ZMMessageAccessoryView *accessoryListView;
- (NSSize)updateRemoveTranslationButtonSize;
@end

NS_ASSUME_NONNULL_END
