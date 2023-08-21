//
//  ZMMessageCellViewFactory.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/17.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMessageItemInfo.h>
#import <zChatComponent/ZMBaseMessageCellView.h>

@interface ZMMessageCellViewFactory : NSObject

+ (instancetype)sharedInstance;

+ (void)releaseInstance;

/*! ZOOM-354983 OP flag copied here so it's reachable outside of the ChatUI project */
@property (nonatomic, assign) BOOL isImageFileSharingImprovementEnabled;

- (Class)cellViewClassByMessageItem:(ZMMessageItemInfo *)item ;

- (Class)defaultLayoutManagerClass;

- (CGFloat)tableView:(NSTableView *)tableView cellHeightForMessage:(ZMMessageItemInfo *)message;

- (CGFloat)tableView:(NSTableView *)tableView cellHeightForMessage:(ZMMessageItemInfo *)message layoutManager:(Class)layoutManagerClass;

- (CGFloat)tableView:(NSTableView *)tableView cellHeightForMessage:(ZMMessageItemInfo *)message layoutManager:(Class)layoutManagerClass layoutConfig:(ZMIMMessageLayoutConfig *)layoutConfig;

- (ZMBaseMessageCellView *)tableView:(NSTableView *)tableView cellForMessage:(ZMMessageItemInfo *)message;

- (ZMBaseMessageCellView *)tableView:(NSTableView *)tableView cellForMessage:(ZMMessageItemInfo *)message layoutManager:(Class)layoutManagerClass;

- (ZMBaseMessageCellView *)tableView:(NSTableView *)tableView cellForMessage:(ZMMessageItemInfo *)message layoutManager:(Class)layoutManagerClass layoutConfig:(ZMIMMessageLayoutConfig *)layoutConfig;

@end
