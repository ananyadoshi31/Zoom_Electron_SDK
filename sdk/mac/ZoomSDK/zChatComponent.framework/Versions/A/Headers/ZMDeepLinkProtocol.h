//
//  ZMDeepLinkProtocol.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/7/19.
//

#ifndef ZMDeepLinkProtocol_h
#define ZMDeepLinkProtocol_h

#import <zChatComponent/ZMIMCommonDefine.h>
#include <zChatApp/SaasBeePTAppInterface.h>

@class ZMMessageAdapter;

@interface ZMUniversalDeepLinkInfo : NSObject

@property (nonatomic) ZMUniversalDeepLinkType linkType;
@property (nonatomic, nullable, retain) NSString *messageID;
@property (nonatomic, nullable, retain) NSString *sessionID;

@end

@protocol ZMDeepLinkProtocol <NSObject>

@optional

- (BOOL)isDeepLink:(NSString *_Nonnull)url sessionId:(NSString *_Nullable)sessionId;

- (void)openLink:(NSString* _Nonnull)url sessionId:(NSString *_Nullable)sessionId;

- (ZMUniversalDeepLinkType)getDeepLinkType:(NSString *_Nonnull)url sessionId:(NSString *_Nullable)sessionId;
- (ZMUniversalDeepLinkInfo *_Nullable)getLinkInfo:(NSString *_Nonnull)forLink sessionId:(NSString *_Nullable)sessionId;

- (BOOL)isDeepLinkEnabledForPhase:(NS_ZOOM_MESSAGER::IDeepLinkV2Manager::FeaturePhase)phase;
- (BOOL)isDeepLinkEnabledForSessionID:(NSString *_Nonnull)sessionID messageID:(NSString *_Nullable)messageID serverTime:(long long)serverTime;

- (ZMDeepLinkEntity *_Nullable)getEntity:(NSString *_Nonnull)forLink sessionId:(NSString *_Nullable)sessionId;

- (void)cleanDeepLinkManager:(NSString *_Nullable)sessionId;

- (void)makeLinkFromMessageAdapter:(ZMMessageAdapter *_Nonnull)adapter callback:(void(^_Nullable)(NSString *_Nonnull, NSUInteger))callback;

- (void)approveJoinRequest:(ZMMessageEntity *_Nonnull)message resultCallback:(void (^_Nullable)(CmmUInt32))resultCallback;
- (void)declineJoinRequest:(ZMMessageEntity *_Nonnull)message resultCallback:(void (^_Nullable)(CmmUInt32))resultCallback;

@end

#ifndef ZMShareDeepLinkProtocol
#define ZMShareDeepLinkProtocol (id <ZMDeepLinkProtocol>)ZMSharedFor(ZMDeepLinkProtocol)
#endif


#endif /* ZMDeepLinkProtocol_h */
