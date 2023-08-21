//
//  ZMIMMessageLayoutManager.h
//  zChatUI
//
//  Created by groot.ding on 2019/6/18.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <AppKit/AppKit.h>
#import "ZMMessageLayoutManager.h"

@class ZMChatMsgItemInfo;

@interface ZMIMMessageLayoutManager : ZMMessageLayoutManager

- (ZMChatMsgItemInfo *)item;

@end
