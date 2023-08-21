//
//  ZMShareSelectHoldKeyTipWindow.h
//  ZCommonUI
//
//  Created by walt.li on 9/23/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMShareSelectHoldKeyTipWindowDelegate <NSObject>
- (void)onShareSelectHoldKeyTipWindowClose;
@end

@interface ZMShareSelectHoldKeyTipWindow : NSPanel
@property(nonatomic, weak, nullable) id<ZMShareSelectHoldKeyTipWindowDelegate> wndDelegate;
- (void)invisibleInSharing;
@end

NS_ASSUME_NONNULL_END
