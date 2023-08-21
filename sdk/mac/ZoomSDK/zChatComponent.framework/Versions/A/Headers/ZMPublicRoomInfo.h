//
//  ZMPublicRoomInfo.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <zChatApp/SaasBeePTAppInterface.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPublicRoomInfo : NSObject

@property (nonatomic, copy) NSString* groupName;
@property (nonatomic, copy) NSString* ownerName;
@property (nonatomic, copy) NSString* jid;
@property (nonatomic, assign) long long memberCount;
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, assign) NS_SSB_XMPP::kMUCFlag flag;
@property (nonatomic, assign) BOOL amIInGroup;

- (id)initWithZoomRoom:(NS_SSB_XMPP::ZoomXmppRoom)room;

@end

NS_ASSUME_NONNULL_END
