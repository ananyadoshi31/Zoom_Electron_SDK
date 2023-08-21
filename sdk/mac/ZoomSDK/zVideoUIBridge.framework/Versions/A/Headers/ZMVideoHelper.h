//
//  ZMVideoHelper.h
//  VideoUI
//
//  Created by javenlee.li on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMMTVideoFilter) {
    ZMMTVideoFilter_None                    = 0,
    ZMMTVideoFilter_MySelf                  = 1 << 0,
    ZMMTVideoFilter_PureCallIn              = 1 << 1,
    ZMMTVideoFilter_MMRUser                 = 1 << 2,
    ZMMTVideoFilter_NoVideo                 = 1 << 3,
    ZMMTVideoFilter_NoVideoAndNoRaiseHand   = 1 << 4 | ZMMTVideoFilter_NoVideo,
    ZMMTVideoFilter_SLInterpreter           = 1 << 5,
};

@class ZMUser;
@interface ZMVideoHelper : ZMBaseHelper

- (BOOL)isStartVideoDisabled;
- (void)setIsStartVideoDisable:(BOOL)disable;

- (BOOL)canIViewVideoForUserID:(ZMUserID)userID;
- (BOOL)canIViewVideoForUser:(ICmmUser*)cmmUser;

- (void)toggleVideoBlurMode;
- (BOOL)isCanBlur;
- (BOOL)isBlurVBMode;
- (BOOL)isForceVB;
- (void)turnOffAvatar;

- (BOOL)isVideoFeatureDisabled;
- (BOOL)isNoVideoToDisplay;

- (BOOL)isStoppedIncomingVideo;

// If sign language interpreter is not allowed to talk,
// we can not see their video in the speaker && gallery && immersive && floating mode.
- (BOOL)canViewVideoOfSignLanguageInterpreter:(ICmmUser*)inCmmUser; //ZOOM-330475

// lipsync
- (BOOL)isLipsyncEnabled;//web & device support
- (void)startSendLipsync;
- (void)stopSendLipsync;
//- (void)refreshLipsync;
- (BOOL)isSupport3DAvatar;

- (nullable ZMUser*)getPinnedUser;

- (std::vector<ICmmUser*>)getAvailableVideoArrayWithFilter:(ZMMTVideoFilter)filter;
@end

NS_ASSUME_NONNULL_END
