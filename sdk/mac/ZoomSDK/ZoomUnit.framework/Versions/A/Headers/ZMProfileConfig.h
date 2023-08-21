//
//  ZMProfileConfig.h
//  zChatUI
//
//  Created by Jed Zheng on 31/5/2022.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMUserProfileFloatTrackType) {
    ZMUserProfileFloatTrackTypeNone = 0,
    ZMUserProfileFloatTrackTypeHome,
    ZMUserProfileFloatTrackTypeChatSidebar,
    ZMUserProfileFloatTrackTypeChatMessageContent,
    ZMUserProfileFloatTrackTypeChatMemberList,
    ZMUserProfileFloatTrackTypePickerView,
    ZMUserProfileFloatTrackTypeSearch,
    ZMUserProfileFloatTrackTypePhone,
    ZMUserProfileFloatTrackTypeMeetingList,
    ZMUserProfileFloatTrackTypeContact,
    ZMUserProfileFloatTrackTypeSessionMenu,
    ZMUserProfileFloatTrackTypeInvite,
    ZMUserProfileFloatTrackTypeMeeting,
    ZMUserProfileFloatTrackTypeMeetingMenu,
};

@interface ZMProfileConfig : NSObject

@property(nonatomic, assign) BOOL showUserCustomerAvatar;

@property(nonatomic, assign) BOOL showJobTitle;

@property(nonatomic, assign) BOOL showPresence;

@property(nonatomic, assign) BOOL showUserPronoun;


@property(nonatomic, assign) BOOL showChatButton;

@property(nonatomic, assign) BOOL showMeetingButton;

@property(nonatomic, assign) BOOL showJoinButton;

@property(nonatomic, assign) BOOL showCallButton;

@property(nonatomic, assign) BOOL showSmsButton;

@property(nonatomic, assign) BOOL showAddContactButton;

@property(nonatomic, assign) BOOL showMessageInputBox;

@property(nonatomic, assign) ZMUserProfileFloatTrackType trackType;

@end

NS_ASSUME_NONNULL_END
