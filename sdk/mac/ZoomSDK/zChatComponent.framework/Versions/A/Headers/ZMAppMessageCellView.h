//
//  ZMAppMessageCellView.h
//  zChatUI
//
//  Created by kevin.li on 2019/9/2.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMBubbleMessageCellView.h>

@class ZMChatMsgItemTextView;

@interface ZMAppMessageCellView : ZMBubbleMessageCellView

@property (nonatomic,retain) ZMChatMsgItemTextView *messageTextView;

@end
