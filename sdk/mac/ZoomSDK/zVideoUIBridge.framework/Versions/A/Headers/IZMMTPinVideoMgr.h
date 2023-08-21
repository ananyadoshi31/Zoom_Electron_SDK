//
//  IZMMTPinVideoMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/22/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTPinVideoMgr <ZMRoutableObject>
#pragma mark - pinned video
- (BOOL)canPinVideo;
- (BOOL)canPinVideoWithUser:(ZMUser*)zmUser;
- (BOOL)canPinVideoOnMainWindow;
- (BOOL)isPinMultipleVideoEnable;
- (BOOL)canIPinMultipleVideo;
- (NSArray<ZMUser*>*)getPinnedUserArray;
- (NSUInteger)getPinnedUserCount;
- (BOOL)isUserPinnedWithUser:(ZMUser*)zmUser;
- (void)pinWithUser:(ZMUser*)zmUser;
- (void)unpinWithUser:(ZMUser*)zmUser;
- (void)unpinAllUser;
- (void)unpinAllUser:(BOOL)unpinAux;
- (void)pinUserAndUnpinOthers:(ZMUser*)zmUser;

#pragma mark - pinned video in 2rd
- (BOOL)canPinVideoOnAuxWindow;
- (BOOL)isUserAuxPinnedWithUser:(ZMUser*)zmUser;
- (ZMUser*)getAuxPinnedUser;
- (void)pinToAuxWithUser:(ZMUser*)zmUser;
- (void)unpinAuxWithUser:(ZMUser*)zmUser;
- (void)unpinAllAuxUser;

#pragma mark - spotlight
- (BOOL)isLeadShipMode;
- (BOOL)isLeadShipModeUser:(ZMUser*)zmUser;
- (ZMUser*)getLeadShipModeUser;

- (BOOL)amISpotlighted;
- (BOOL)canISpotlightMultipleVideo;
- (BOOL)isSpotlightingMode;
- (BOOL)isSpotlightingUser:(ZMUser*)zmUser;
- (NSUInteger)getSpotlightingUserCount;
- (NSArray<ZMUser*>*)getSpotlightingUserArray;

- (void)spotlightUser:(ZMUser*)zmUser;
- (void)spotlightUser:(ZMUser*)zmUser removeOthers:(BOOL)removeOthers;
- (void)spotlightUserArray:(NSArray*)zmUser removeOthers:(BOOL)removeOthers;
- (void)stopSpotlightUser:(ZMUser*)zmUser;
- (void)stopSpotlightUserArray:(NSArray<ZMUser*>*)userArray;
- (void)stopSpotlightAllUser;

#pragma mark - drag layout
- (BOOL)isFollowHostVideoOrderEnable;
- (BOOL)isFollowHostVideoOrder;
- (BOOL)shouldFollowHostVideoOrder;
- (void)setFollowHostVideoOrder:(BOOL)follow;

- (BOOL)isVideoDragMode;
- (BOOL)isVideoOrderMode;
- (NSArray<ZMUser*>*)getVideoOrderUserArray;
- (void)setVideoOrderUserArray:(nullable NSArray<ZMUser*>*)orderArray;
- (void)setVideoDragUserArray:(nullable NSArray<ZMUser*>*)dragArray;

#pragma mark - save video order
- (void)saveGalleryVideoOrderArray;
- (void)loadGalleryVideoOrderArray;

#pragma mark - zoom room order
- (BOOL)isUserGroupInPin:(ZMUser*)zmUser;
- (BOOL)isUserGroupInSpotlight:(ZMUser*)zmUser;
- (BOOL)isUserGroupInRaiseHand:(ZMUser*)zmUser;
- (NSMutableArray<ZMUser*>*)sortUserOrderArray:(NSMutableArray<ZMUser*> *)array;

@end

@protocol IZMMTPinVideoSinkProtocol <NSObject>
- (void)onSpotlightStatusChanged:(BOOL)inSpotlightMode;
- (void)onSpotlightGroupChanged;

- (void)onFollowVideoOrderStatusChanged;
- (void)onDragVideoLayoutStatusChanged;

- (void)onGalleryVideoOrderSaved:(BOOL)ret;
- (void)onGalleryVideoOrderLoaded:(NSString*)orderString;
@end

@protocol IZMMTPinVideoStatusProtocol <ZMRoutableObject>
@optional
- (void)onPinnedGroupChanged:(ZMConfSession*)confSession;
- (void)onSpotlightGroupChanged:(ZMConfSession*)confSession;
- (void)onDraggedGroupChanged:(ZMConfSession*)confSession;

- (void)onPinnedAuxGroupChanged:(ZMConfSession*)confSession;
@end

NS_ASSUME_NONNULL_END
