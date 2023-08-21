//
//  ZMMTStudioScene.h
//  VideoUI
//
//  Created by geno.chen on 2022/8/9.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTStudioSceneContentType) {
    ZMMTStudioSceneContentType_Video,
    ZMMTStudioSceneContentType_Share,
};

#define kStudioActiveSpeakerIdentifier @"active_speaker"
#define kStudioNotAssignedIdentifier @"not_assigned"

@interface ZMMTStudioSceneContent : NSObject

@property(nonatomic, assign) NSRect frame;
@property(nonatomic, strong, nullable, readonly) ZMUser *user;
@property(nonatomic, assign) NSInteger borderWidth;
@property(nonatomic, strong) NSColor *borderColor;
@property(nonatomic, assign) ZMMTStudioSceneContentType type;
@property(nonatomic, copy) NSString *userEmail;
@property(nonatomic, assign) NSSize videoRatio;

@end


@interface ZMMTStudioScene : NSObject

@property (nonatomic, copy) NSString *sceneID;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, assign) NSInteger layoutType;
@property (nonatomic, copy) NSString *wallpaperPath;

@property (nonatomic, assign) NSInteger safeArea;

@property (nonatomic, assign) NSInteger borderWidth;
@property (nonatomic, strong) NSColor *borderColor;

@property (nonatomic, assign) NSInteger videoSpacing;
@property (nonatomic, assign) NSSize videoRatio;

@property (nonatomic, strong) NSArray *videoUserEmails;
@property (nonatomic, strong) NSArray *shareUserEmails;


@property (nonatomic, strong, readonly) NSImage *wallpaper;
@property (nonatomic, strong, readonly) NSArray <ZMMTStudioSceneContent *> *contents;
@property (nonatomic, assign, readonly) NSSize size;

@property(nonatomic, assign, getter=isLiving) BOOL living;
@property(nonatomic, assign, getter=isEnable) BOOL enable;

#ifdef __cplusplus
class CmmPSLScene;
//@property (nonatomic, assign) CmmPSScene psScene;
- (instancetype)initWithPSScene:(CmmPSLScene)scene;

+ (ZMUser *_Nullable)getStudioUserFromEmail:(NSString *)email;

- (ZMMTStudioSceneContent *_Nullable)getContentByEmail:(NSString *)email contentType:(ZMMTStudioSceneContentType)type;


#endif

@end


@interface ZMMTStudioScene (Helper)

- (BOOL)hasSpeaker;

- (NSUInteger)availableSpeakers;

- (NSUInteger)totalSpeakers;

- (BOOL)isContainShare;
- (BOOL)isSharingContent;
- (BOOL)isContainUser:(ZMUserID)userID;
- (BOOL)isContainActiveSpeaker;

@end

NS_ASSUME_NONNULL_END
