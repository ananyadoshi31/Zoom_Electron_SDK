//
//  ZMMTRender.h
//  zVideoUI
//
//  Created by Geno on 8/13/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMConfSession;
@class ZMUser;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTRenderType) {
    ZMMTRenderType_Normal,
    ZMMTRenderType_Group,
    ZMMTRenderType_Sub
};

@interface ZMMTRender : NSObject

@property (nonatomic, assign) BOOL backgroundTransparent;
@property (nonatomic, assign) int aspectMode;
@property (nonatomic, assign) int portraitMode;
@property (nonatomic, assign, readonly) ZMMTRenderType type;
@property (nonatomic, weak, readonly) ZMConfSession *session;
@property (nonatomic, weak, readonly) NSView *view;
@property (nonatomic, assign, readonly) BOOL isSubRender;

- (instancetype)initWithSession:(ZMConfSession *)session view:(NSView *)view type:(ZMMTRenderType)type;

- (void)destoryRender;
- (nullable ZMMTRender *)newSubRenderWithView:(NSView *)view;
- (void)cleanRender;
- (void)moveRender:(NSRect)frame;
- (BOOL)updateVideoSize:(int)size;
//- (BOOL)updateVideoSizeWithViewHeight:(CGFloat)height;
- (BOOL)showVideoWithUser:(ZMUser *)user size:(int)size;
- (void)stopShowVideoWithClearRender:(BOOL)clearRender;

- (void)startRendering;
- (void)stopRendering;

@end

NS_ASSUME_NONNULL_END
