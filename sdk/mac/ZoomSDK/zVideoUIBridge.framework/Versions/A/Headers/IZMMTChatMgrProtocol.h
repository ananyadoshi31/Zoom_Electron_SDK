//
//  IZMMTChatMgrProtocol.h
//  VideoUIBridge
//
//  Created by Cain Zhou on 2022/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTRosterList;
@class ZMConfSession;
@protocol IZMMTChatMgrProtocol <ZMRoutableObject>

//panelist changed
//- (void)onUserRosterChanged:(ZMMTRosterList *)roster session:(ZMConfSession *)session;
// attendee changed
- (void)onAttendeeRosterChanged;

@end

NS_ASSUME_NONNULL_END
