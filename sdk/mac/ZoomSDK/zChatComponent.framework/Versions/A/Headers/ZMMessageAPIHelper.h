//
//  ZMMessageAPIHelper.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/8/4.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMIMCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN


@class ZMChannelMemberSearchFilter;


@interface ZMAtEventTelemetryData : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, assign) NSInteger index;

@end


@interface ZMMessageAPIHelper : NSObject

+ (ZoomIMPresence)getMyPresence;
+ (ZoomIMPresenceStatus)getMyPresenceStatus;

+ (void)joinMeetingWithMessageID:(NSString * _Nullable)messageID sessionID:(NSString * _Nullable)sessionID;
+ (BOOL)isSharePointEnabledInChannel:(nullable NSString*)groupID;
+ (ZMFileStorageType)currentFileStorageType;
+ (NSInteger)getSessionFileSotrageType:(nonnull NSString*)sessionID;
+ (E2EChatOption)getMyE2EOption:(nullable NSString *)sessionID;
+ (BOOL)isWhiteboardURL:(nonnull NSString*)url sessionID:(nonnull NSString*)sessionID;
+ (BOOL)searchMessageFileDisable;

+ (BOOL)isMessageAtChannelAllowPreview:(nonnull NSString*)sessionId withMessageID:(nonnull NSString*)messageID groupID:(nonnull NSString*)groupID;

+ (BOOL)isSessionExistByID:(nonnull NSString*)sessionID ;

+ (BOOL)sendButtonCommand:(NSDictionary*)info;
+ (BOOL)sendSelectCommand:(NSDictionary*)info;

+ (BOOL)isLargeChannelForMemberListOptimization:(NSString*)sessionId;
+ (NSString*)searchChannelMember:(ZMChannelMemberSearchFilter*)searchFilter;

+ (nullable NSArray<NSString*>*)sortChannelMemberSearchResult:(nonnull NSString*)sessionId threadId:(nullable NSString*)threadId keyword:(nullable NSString*)keyword jidArray:(nonnull NSArray<NSString*>*)jidArray hasMore:(nullable BOOL*)hasmore;

+ (nullable NSString*)searchChannelByKeyword:(nonnull NSString*)keyword;

+ (nullable NSString*)getMarketplaceURLForMioSupport; //ZOOM-386910

+ (BOOL)isEnableImprovedMentionSortLogic;
+ (void)sendAtEventTelemetryWithList:(nullable NSArray*)list type:(ZMMessageSrcType)srcType;
+ (nullable NSArray*)getAtMentionSortedListForSessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID key:(nullable NSString*)key hasMore:(nullable BOOL*)hasmore;

+ (BOOL)isEnableOutOfOffice;

@end

NS_ASSUME_NONNULL_END
