//
//  ZMMTStudioHelper.h
//  VideoUI
//
//  Created by geno.chen on 2022/8/9.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#include <zVideoApp/Confdef.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTStudioScene;
@class ZMUser;
@class ZMMTStudioLayoutModel;

@interface ZMMTStudioHelper : ZMBaseHelper

- (BOOL)isCurrentProducerPublishing;
- (BOOL)fetchPSScenes;
- (CmmPSLSceneReqStatus)getFetchPSSceneStatus;
- (NSArray <ZMMTStudioScene *> *)getPSScenes;
- (void)changePSScene:(NSString *)sceneID scene:(ZMMTStudioScene *)scene;
- (void)updateDisablePSSceneList:(NSArray <ZMMTStudioScene *> *)sceneList;

- (nullable ZMUser *)getCurrentProducer;
- (BOOL)isProductionStudioEnabled;
- (BOOL)forceSubscribeProducer;

- (void)notifyPSUserWillLivedWithVideo:(ZMUser *)user;
- (void)notifyPSUserWillLivedWithShare:(ZMUser *)user;
- (void)broadcastMyPublishingScene:(ZMMTStudioScene *)scene;

- (void)joinProducerAudioChannel;
- (void)leaveProducerAudioChannel;

- (BOOL)isFirstTimeStudioSendLive;
- (void)setNotFirstTimeStudioSendLive;

- (BOOL)isFirstTimeStudioOnBoarding;
- (void)setNotFirstTimeStudioOnBoarding;

- (NSInteger)generateCommonLayoutWithUserCount:(NSUInteger)userCount
                              videoRects:(NSArray*_Nullable*_Nullable)videoRects
                                     row:(int*_Nullable)row
                                     col:(int*_Nullable)col
                                  layout:(ZMMTStudioLayoutModel*)layoutModel;

- (void)rectsWithLayoutID:(NSInteger)layoutID
               videoRects:(NSArray*_Nullable*_Nullable)videoRects
               shareRects:(NSArray*_Nullable*_Nullable)shareRects
                   layout:(ZMMTStudioLayoutModel*)layoutModel;

- (void)notifyPSUserLived:(ZMUserID)userID context:(CmmUInt32)context;


- (void)startSendLive;
- (void)stopSendLive;

@end

NS_ASSUME_NONNULL_END
