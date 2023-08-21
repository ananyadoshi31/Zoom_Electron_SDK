//
//  ZMReactionDetailViewController.h
//  zChatUI
//
//  Created by likevin on 2019/7/17.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface ZMReactionDetailViewController : ZMBaseViewController
@property(nonatomic, retain) NSArray*  buddyInfoArray;
@property(nonatomic, retain) NSString* emojiCode;
@property(nonatomic, assign) BOOL visible;

- (instancetype)initWithCloseAction:(SEL)closeAction
                             target:(id)target;

- (void)updateUIWithEmojiCode:(NSString*)emojiCode
               buddyInfoArray:(NSArray*)jidArray
               titleInfoArray:(NSArray *)titleArray
                    channelID:(NSString *)channelID
                    messageID:(NSString *)messageID;

/*request callback*/
- (void)onEmojiDetailInfoCallbackWithSessionID:(NSString*)channelID
                                     messageID:(NSString*)messageID
                                     emojiCode:(NSString*)emojiCode;

@end
