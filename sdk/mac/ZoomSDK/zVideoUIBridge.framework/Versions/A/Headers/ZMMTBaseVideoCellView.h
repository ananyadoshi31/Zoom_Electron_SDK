//
//  ZMMTBaseVideoView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 1/4/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTGridCellView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTBaseVideoCellView;
@class ZMMTRender;
@protocol ZMMTBaseVideoCellViewDelegate <NSObject>
@optional

- (void)videoCellView:(ZMMTBaseVideoCellView*)cellView willSubscribeVideo:(ZMUser *)theUser;
- (void)videoCellView:(ZMMTBaseVideoCellView*)cellView didSubscribeVideo:(ZMUser *)theUser;

- (BOOL)videoCellView:(ZMMTBaseVideoCellView*)cellView enableCustomSizeWithHeight:(CGFloat)height;
- (uint8_t)videoCellView:(ZMMTBaseVideoCellView*)cellview renderSizeWithHeight:(CGFloat)height;

- (BOOL)doubleClickedOnVideoCellView:(ZMMTBaseVideoCellView*)cellView;

//Powered Water mark
- (BOOL)enableShowPWMarkForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
//avatar
- (BOOL)enableShowAvatarForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
//user info
- (BOOL)enableShowUserInfoForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
- (NSRect)videoCellView:(ZMMTBaseVideoCellView*)cellView frameForInfoView:(NSRect)defaultFrame;
//active border
- (BOOL)enableShowBorderForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
//personal water mark
- (BOOL)enableShowPersonalWaterMarkForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
- (BOOL)enableShowNameTagForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
- (BOOL)enableShowLiveTagForVideoCellView:(ZMMTBaseVideoCellView*)cellView;
- (NSString *)personalWaterMarkText;
- (CGFloat)personalWaterMarkerOpacityLevel;
- (ZMConfWaterMarkCoverType)personalWaterMarkCoverType;
- (ZMConfWaterMarkPosition)personalWaterMarkPosition;
- (NSEdgeInsets)contentInsetsForWaterMark:(ZMMTBaseVideoCellView *)cellView;

- (NSRect)videoCellView:(ZMMTBaseVideoCellView*)cellView renderRectForBounds:(NSRect)rect;

- (NSRect)visibleRectForCellView:(ZMMTBaseVideoCellView*)cellView;
@end

@class ZMMTVideoRender;
@interface ZMMTBaseVideoCellView : ZMMTGridCellView
@property (nonatomic, weak) id<ZMMTBaseVideoCellViewDelegate> delegate;
@property (nonatomic, nullable, retain) ZMMTVideoRender *videoItem;
@property (nonatomic, readonly) NSView* renderView;
@property (nonatomic, assign) NSInteger renderType;//default is Render_ATTENDE, type RENDER_CONTAINER_TYPE
@property (nonatomic, nullable, weak) ZMMTRender *render;
@property (nonatomic, assign) BOOL isTransparent;
@property (nonatomic, assign) ZMUser *zmUser;
@property (nonatomic, assign) NSInteger aspectMode;//default is SSB_MC_VIDEO_ASPECT_LETTER_BOX, type SSB_MC_VIDEO_ASPECT_MODE
@property (nonatomic, assign) NSInteger portraitMode;//default is disable, type SSB_MC_VIDEO_SMART_PORTRAIT_MODE;
@property (nonatomic, readonly, assign)BOOL isActiveVideo;

@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) CGFloat borderWidth;

- (id)initWithFrame:(NSRect)frame userID:(int)userID NS_DEPRECATED_MAC(10_7, 10_7, "Use -initWithFrame instead");
- (id)initWithFrame:(NSRect)frame;

- (void)cleanUp NS_REQUIRES_SUPER;

- (ZMMTVideoRender*)generateRenderView;
- (NSRect)getRenderRectWithBounds:(NSRect)frame;

- (void)destroyRender;

- (void)lockVideo;
- (void)unlockVideo;

- (void)startShowingVideo:(ZMUser *)theUser;
- (void)stopShowingVideo;

- (void)startPreview;
- (void)stopPreview;

// Override by subclass
- (void)setIsActiveVideo:(BOOL)isActive;

- (void)forceUpdateVideoView:(ZMVideoUpdateStrategy)strategy;//ZOOM-82229

- (void)updateUI;
- (void)resetVideoView;//ZOOM-27757

- (void)willSubcribeUserID:(ZMUser *)theUser;
- (void)didSubcribeUserID:(ZMUser *)theUser;

@end

//ZOOM-29483
@interface ZMMTBaseVideoCellView(ZMReusePool)
+ (nullable id)getNewVideoView;
+ (void)recyclingVideoView:(__kindof ZMMTBaseVideoCellView*)videoView;
+ (void)cleanUpVideoViewPool;
@end

NS_ASSUME_NONNULL_END
