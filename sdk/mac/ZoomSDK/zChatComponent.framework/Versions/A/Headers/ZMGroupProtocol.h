//
//  ZMGroupProtocol.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/18.
//

#ifndef ZMGroupProtocal_h
#define ZMGroupProtocal_h

NS_ASSUME_NONNULL_BEGIN

typedef void(^ZMChannelListenCompletion)(NSString * channelId,id param);

@class ZMSessionGroupAdapter;

/**
 channel operate event call back,like : create channel, modify channel name
 */
@protocol ZMChannelOperateListen <NSObject>

- (void)addListenChannelCreateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelJoinByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelDeleteByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelInfoUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelMembersRemoveByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelMembersAddedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelAssignAdminByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelInfoDescUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelNameUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelPendingUserUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenClassificationUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenMioLicenseUpdatedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenGroupExternalUsersReceivedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)removeAllListenByTarget:(id)target;

@end

@protocol ZMGroupProtocol <ZMChannelOperateListen>

- (nullable ZMSessionGroupAdapter *)getChannelById:(nonnull NSString *)channelId;

- (nullable ZMSessionGroupAdapter *)getChannelById:(nonnull NSString *)channelId refersh:(BOOL)refersh;

- (void)refreshMembersByChannelIds:(nonnull NSArray <NSString *> *)channelIds;

- (BOOL)checkAmIOwnerInChannel:(NSString *)channelId;

- (BOOL)checkAmIAdminInChannel:(NSString *)channelId;

- (BOOL)checkOwner:(NSString *)jid inChannel:(NSString *)channelId;

- (BOOL)amIAnnouncerInChannel:(NSString *)channelId;

- (BOOL)checkMute:(NSString *)channelId;

- (BOOL)checkIfAdminsExceedLimitInChannel:(NSString *)channelId;

- (NSArray <ZMSessionGroupAdapter *> *)getAllChannels;
- (NSArray <ZMSessionGroupAdapter *> *)getAllChannelsWithoutMUC;
@end

#ifndef ZMShareGroupProtocol
#define ZMShareGroupProtocol (id <ZMGroupProtocol>)ZMSharedFor(ZMGroupProtocol)
#endif

#endif /* ZMGroupProtocal_h */

NS_ASSUME_NONNULL_END
