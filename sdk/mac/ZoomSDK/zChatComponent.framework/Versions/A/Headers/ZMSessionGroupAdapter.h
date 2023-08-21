//
//  ZMSessionGroupAdapter.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 5/13/14.
//  Copyright (c) 2014 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatApp/SaasBeePTAppInterface.h>
#import <zChatComponent/ZMSessionGroupAdapter.h>

enum
{
    GroupType_None = 0,
    GroupType_1V1,
    GroupType_MUC,
    GroupType_Channel,
};

typedef NS_ENUM(NSUInteger, ZMGroupAnnouncerType)
{
    ZMGroupAnnouncerType_EveryOne = 0,
    ZMGroupAnnouncerType_AdminOnly,
    ZMGroupAnnouncerType_AdminAndSpecialMember
};

typedef NS_ENUM(NSUInteger, ZMChannelUpdateState) {
    ZMChannelUpdateNone                       = 0,
    ZMChannelUpdateName                       = 1<<1,
    ZMChannelUpdateFlag                       = 1<<2,
    ZMChannelUpdateMember                     = 1<<3,
    ZMChannelUpdateDesc                       = 1<<4,
    ZMChannelUpdateInfo                       = 1<<5,
};

/*!
 * Contains channel/MUC data, including info about admins and members.
 */
@class ZMBuddyAdapter;
@class ZMSessionGroupProperty;
@class ZMUserInfo;
@class ZMGroupPersistentMeetingInfo;

@interface ZMSessionGroupAdapter : NSObject
{
    NSUInteger _hashKey;
}
@property (nonatomic, retain) ZMSessionGroupProperty *_Nullable groupProperty;
@property (nonatomic, retain) NSString* m_gID;
@property (nonatomic, retain) NSString* m_gName;
@property (nonatomic, retain) NSString* m_gOwner;
@property (nonatomic, copy) NSString* m_gDesc;
@property (nonatomic, retain) NSMutableArray* m_gAdmins;
@property (nonatomic, retain) NSMutableArray* m_buddies;
@property (nonatomic, retain) NSMutableArray* pendingMailBuddies;
@property (nonatomic, retain) NSArray * subAdmins;
@property (nonatomic, assign) BOOL m_amIInGroup;
@property (nonatomic, assign) BOOL isForceE2E;
@property (nonatomic, assign) BOOL isSearchableGroup;
@property (nonatomic, assign) BOOL isRestrictSameorg;
@property (nonatomic, assign) BOOL isPublicRoom;
@property (nonatomic, assign) BOOL isPrivateRoom;
@property (nonatomic, assign) BOOL isRoom;
@property (nonatomic, assign) NS_SSB_XMPP::kMUCFlag flag;
@property (nonatomic, assign) BOOL amIAnnouncer;// Indicates whether I can speak in this group
@property (nonatomic, assign) ZMGroupAnnouncerType announcerType;
@property (nonatomic, retain) NSArray *announcers;
@property (nonatomic, assign) BOOL isRestricHistoryMessages;
@property (nonatomic, assign, readonly) BOOL isPersistentMeetingGroup;
@property (nonatomic, assign, readonly) BOOL isNeedInsertPMCGroupChatSysMsg;
@property (nonatomic, retain, readonly) ZMGroupPersistentMeetingInfo * _Nullable persistentMeetingInfo;
@property (nonatomic, readonly) NSArray<NSString*>* m_MUCNames;
@property (nonatomic, readonly) NSArray<ZMUserInfo *>* mucMemberInfos;

@property (assign) NSInteger lastMatchScore;

@property (nonatomic,assign) NSInteger lastUpdateState;

- (id)initWithSessionGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
- (id)initWithSessionGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup upDateMemberList:(BOOL)update;
- (NSArray*)getBuddyIDs;
- (NSString*)getGroupID;
- (NSString*)getGroupName;
- (NSString*)getGroupOwner;
- (NSString*)getOwnerName;
- (NSUInteger)getBuddyCount;
- (BOOL)amIInGroup;
- (BOOL)amIAdmin;
- (BOOL)amIOwner;
- (ZMBuddyAdapter*)getBuddyAt:(NSUInteger)index;
- (ZMBuddyAdapter*)getBuddyWithJid:(NSString *)jid;
- (NSArray*)getBuddies;
- (NSUInteger)getBuddyCountWithoutMyself;
- (NSArray*)getBuddiesWithoutMyself;
- (NSArray*)getBuddiesWithoutPendingEmail;
- (NSArray*)getBuddiesWithoutMyselfAndRobot;
- (void)update;
- (void)updateAnnouncerInfo;
- (void)updateBuddies;
- (void)updateLastMatchScore;
- (void)updateProperty;
- (void)updateAdmins;
- (void)updateGroupPersistentMeetingInfo:(BOOL)isRequestFromWeb;
- (NSString*)getMucMemberListToolTip;
+ (NSUInteger)groupTypeByID:(NSString*)groupID;
+ (BOOL)isGroupInfoReadyWithGroupID:(NSString *)groupID;
- (BOOL)isBroadcastAnnouncementReceiver;
- (BOOL)isMuted;
- (BOOL)isGroupMemberWithJid:(NSString *)jid;
- (BOOL)hasTopic;
- (BOOL)amIAbleToAddMembers; //ZOOM-387575

+ (BOOL)isEventChannel:(NSString*)channelId;
+ (NSUInteger)getTotalMemberCount:(NSString*)channelId;
+ (BOOL)isPublicRoom:(NSString*)sessionId;
+ (BOOL)isUniversalChannelByMio:(NSString*)sessionId;
+ (BOOL)isGroupID:(NSString*)groupID;
+ (NSArray<ZMBuddyAdapter*>*)orderedMemberListInSession:(nullable NSString*)sessionID;
+ (NSArray<ZMBuddyAdapter*>*)orderedMemberListInSession:(nullable NSString*)sessionID isNeedRefresh:(BOOL)isNeedRefresh;
+ (BOOL)isPersistentMeetingGroupChannel:(NSString*)channelId;
@end

