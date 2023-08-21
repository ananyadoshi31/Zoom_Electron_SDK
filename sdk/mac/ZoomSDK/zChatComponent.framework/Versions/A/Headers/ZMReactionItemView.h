//
//  ZMReactionItemView.h
//  ZCommonUI
//
//  Created by groot.ding on 21/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import "ZMReactionEmojiInfo.h"
#import <ZoomKit/ZPTrackingButton.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMReactionItemView : ZPTrackingButton

@property (nonatomic,assign)  BOOL        isSelected;
@property (nonatomic,copy)    NSString*   emojiCode;
@property (nonatomic,assign)  NSInteger   reactionCount;
@property (nonatomic,copy)    NSString*   sessionID;
@property (nonatomic,copy)    NSString*   messageID;

+ (NSInteger)caculateWidthWithInfo:(ZMReactionEmojiInfo *)emojiCountInfo;

+ (ZMReactionItemView *)reactionItemButtonWithInfo:(ZMReactionEmojiInfo *)emojiCountInfo;

@end

NS_ASSUME_NONNULL_END
