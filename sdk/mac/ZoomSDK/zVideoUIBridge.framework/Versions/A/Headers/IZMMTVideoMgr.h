//
//  IZMMTVideoMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTVideoMgr <NSObject>
- (void)onAutoStartVideo:(NSInteger)ret session:(ZMConfSession*)session;
- (void)onFocusModeStatusChanged;

- (void)onEnableVBFailed:(ZMConfSession*)session;

- (void)onSendVideoPrivilegeChange;//ZOOM-82229
- (void)onReceiveVideoPrivilegeChange;//ZOOM-82229

- (void)resetFocusModeWhiteList;
- (void)onVideoSizeChanged:(ZMUser *)zmUser;
@end

NS_ASSUME_NONNULL_END
