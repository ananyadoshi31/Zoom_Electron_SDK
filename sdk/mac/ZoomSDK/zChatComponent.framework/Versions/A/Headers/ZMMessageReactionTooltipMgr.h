//
//  ZMMessageReactionTooltipMgr.h
//  zChatUI
//
//  Created by likevin on 2019/7/15.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMReactionItemView;


@interface ZMMessageReactionTooltipMgr : NSObject
+ (ZMMessageReactionTooltipMgr*)sharedInstance;
+ (void)releaseInstance;

- (void)showToolTipWithSessionID:(NSString*)inSID messageID:(NSString*)inMsgID reactionView:(ZMReactionItemView*)inReactionView;
- (void)hideTooltipWithReactionView:(ZMReactionItemView*)inReactionView;

- (void)onTooltipWindowDidClosed:(id)sender;
@end



@interface ZMReactionTooltipView : NSView
- (void)updateUIWithTooltipArray:(NSArray<NSString*>*) tooltipArray;
- (void)onWindowDidClosed:(id)sender;
@end
