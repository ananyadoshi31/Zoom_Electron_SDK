//
//  ZMBuddyProtocal.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/4/26.
//

#ifndef ZMBuddyProtocal_h
#define ZMBuddyProtocal_h

#import <Cocoa/Cocoa.h>

typedef void(^ZMBuddyListenCompletion)(NSArray <NSString *> * _Nullable jids);

typedef NS_ENUM(NSInteger, ZMBuddyCacheType){
    ZMBuddyCacheType_IM,
    ZMBuddyCacheType_Meeting,
};

@class ZMBuddyAdapter;

@protocol ZMBuddyOperateProtocol <NSObject>

- (nullable void *)getRawDataOfBuddyByJid:(nonnull NSString *)jid;

- (nullable ZMBuddyAdapter *)getBuddyByJId:(nonnull NSString *)jid;

- (nullable ZMBuddyAdapter *)getBuddyByEmail:(nonnull NSString*)email;

- (nullable ZMBuddyAdapter *)getBuddyByEmailFromCache:(nonnull NSString*)email;

- (nullable ZMBuddyAdapter *)getBuddyByJId:(nonnull NSString *)jid sessionId:(nullable NSString *)sessionId;

- (nullable ZMBuddyAdapter *)getBuddyByZoomBuddy:(nonnull void *)pBuddy;

- (nullable ZMBuddyAdapter *)getBuddyCreateIfNotExistByJID:(nonnull NSString *)jid;

- (nullable ZMBuddyAdapter *)getBuddyCreateIfNotExistByEmail:(nonnull NSString *)email;

- (nullable ZMBuddyAdapter*)getPendingBuddyByEmail:(nonnull NSString *)email;

- (nullable NSArray<ZMBuddyAdapter*>*)quickGetSortedMatchedBuddiesByKey:(nonnull NSString*)key withFilter:(NSInteger)filterValue;

- (BOOL)getBuddiesPresence:(nonnull NSArray*)jids shouldSubscribe:(BOOL)bSubscribe;

- (NSInteger)subscribeContactsPresence_v2:(nonnull NSArray*)jids forType:(int)type;

- (nullable ZMBuddyAdapter*)getSessionBuddyWithSessionID:(nonnull NSString*)sessionID;

- (nullable NSMutableArray*)sortBudddies:(nullable NSArray*)buddiesArray;

- (void)refreshBuddyVCard:(nonnull NSString *)jid;

- (void)refreshBuddyVCards:(nonnull NSArray<NSString *> *)jids; //ZOOM-68776

- (void)refreshBuddyVCards:(nonnull NSArray<NSString *> *)jids rightNow:(BOOL)rightNow;

- (void)refreshBuddyVCards:(nonnull NSArray<NSString *> *)jids rightNow:(BOOL)rightNow sessionId:(nullable NSString *)sessionId;

- (void)refreshBuddyChatAvailable:(nonnull NSString *)jid;

- (BOOL)isUserBlocked:(nonnull NSString *)jid;

- (BOOL)isPassed:(nonnull ZMBuddyAdapter*)buddyAdapter withFilter:(NSInteger)filterValue;

- (nullable NSString*)getBuddyScreenNameByJID:(nullable NSString*)jid;

- (void)blockUsers:(nonnull NSArray <NSString *> *)uids completion:(nonnull void(^)(NSArray <NSString *> * _Nonnull jids, NSError * _Nullable error))completion;

- (void)unBlockUsers:(nonnull NSArray <NSString *> *)uids completion:(nonnull void(^)(NSArray <NSString *> * _Nonnull jids,NSError * _Nullable error))completion;

- (BOOL)unblockContacts:(nonnull NSArray*)contacts;

- (BOOL)isDeactivedBuddy:(nonnull NSString*)jid;

- (BOOL)isTerminatedBuddy:(nonnull NSString*)jid;

- (nullable NSString *)getMyJidBySessionId:(nullable NSString *)sessionId;
- (nullable NSString *)getMyScreenNameBySessionId:(nullable NSString *)sessionId;

- (BOOL)checkMySelf:(nonnull NSString *)jid sessionId:(nullable NSString *)sessionId;

- (BOOL)isMyContact:(nonnull NSString *)jid sessionId:(nonnull NSString *)sessionId;

- (BOOL)isZoomRoom:(nonnull NSString *)jid sessionId:(nonnull NSString *)sessionId;

- (BOOL)checkBuddyInAddonsGroup:(nonnull NSString *)jid;

- (BOOL)isRobot:(nonnull NSString *)jid;

- (BOOL)isAuditRobot:(nonnull NSString *)jid;

- (nullable NSString*)getMeetingBuddyScreenNameByJID:(nullable NSString*)jid sessionId:(NSString *)sessionId;

- (void)cleanBuddiesCacheByType:(ZMBuddyCacheType)type;

@end

@protocol ZMBuddyUpdateCallback <NSObject>

- (void)didAllBuddyListUpdate;

- (void)didMyBuddyUpdate;

- (void)didBuddyUpdate:(nonnull NSString *)jid;

- (void)didBuddiesUpdate:(nonnull NSArray <NSString *> *)jids;

- (void)didBuddyRemove:(nonnull NSString *)jid;

- (void)didBuddiesIBUpdate:(nonnull NSArray <NSString *> *)jids;

- (void)didBuddyDeactivated:(nonnull NSString *)jid;

@end


@protocol ZMBuddyPresenceUpdateCallBack <NSObject>

- (void)didBuddyPresenceUpdate:(nonnull NSString *)jid;

- (void)didConnectChange:(NSInteger)state;

- (void)willPresenceSubscriptionExpire:(NSArray *)jids;

@end

@protocol ZMBuddyBlockCallBack <NSObject>

- (void)didBlockUsers:(nonnull NSArray <NSString *> *)uids;

- (void)didUnBlockUsers:(nonnull NSArray <NSString *> *)uids;

- (void)didBlockUsersUpdate;

@end

@protocol ZMBuddyUpdateListen <NSObject>

- (void)addListenAllBuddyListUpdateByTarget:(nonnull id)target completion:(nonnull ZMBuddyListenCompletion)completion;

- (void)addListenBuddiesUpdateByTarget:(nonnull id)target completion:(nonnull ZMBuddyListenCompletion)completion;

- (void)addListenBlockUsersUpdateByTarget:(nonnull id)target completion:(nonnull ZMBuddyListenCompletion)completion;

- (void)addListenIBUpdateByTarget:(nonnull id)target completion:(nonnull ZMBuddyListenCompletion)completion;

- (void)addListenBuddyDeactivated:(nonnull id)target completion:(nonnull ZMBuddyListenCompletion)completion;

- (void)removeAllListenByTarget:(nonnull id)target;

@end

@protocol ZMBuddyProfileProtocol
- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView autoClose:(BOOL)autoClose sessionId:(nonnull NSString*)sessionId;

- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView relativeRect:(NSRect)rect;

- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView trackType:(ZMUserProfileFloatTrackType)trackType;

- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView autoClose:(BOOL)autoClose panelSourceType:(int)sourceType;

- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView relativeRect:(NSRect)rect byMousePoint:(BOOL)mouse;

- (void)showUserProfilePannel:(nonnull NSString *)uid positioningView:(nonnull NSView *)positioningView relativeRect:(NSRect)rect byCenterPoint:(BOOL)center;

@end

@protocol ZMBuddyProtocol <ZMBuddyOperateProtocol,ZMBuddyUpdateCallback,ZMBuddyPresenceUpdateCallBack,ZMBuddyBlockCallBack,ZMBuddyUpdateListen, ZMBuddyProfileProtocol>

@end

#ifndef ZMShareBuddyProtocol
#define ZMShareBuddyProtocol (id <ZMBuddyProtocol>)ZMSharedFor(ZMBuddyProtocol)
#endif

#endif /* ZMBuddyProtocal_h */
