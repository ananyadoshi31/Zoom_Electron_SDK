//
//  ZMVideoPlayerView.h
//  zChatUI
//
//  Created by simon shang on 2021/1/19.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import "ZMVideoPlayerControlView.h"

NS_ASSUME_NONNULL_BEGIN
@class ZMFileEntity;
static NSString * const kPauseOthersVideoPlay = @"kPauseOthersVideoPlay";

@class ZMVideoPlayerView;

@protocol ZMVideoPlayerViewDelegate <NSObject>

@optional
- (void)fullScreenButtonClicked:(ZMVideoPlayerControlStyle)currentPlayerControlStyle videoPlayerView:(ZMVideoPlayerView *)playerView fileModel:(ZMFileEntity *)fileModel;
- (void)videoPlayStateChanged:(BOOL)isToPlay videoPlayerView:(ZMVideoPlayerView *)playerView;
- (void)mouseUpInVideoPlayerView:(NSEvent *)event;
- (void)mouseEnterInVideoPlayerView:(NSPoint)locationPoint;
- (void)clickRetryButton;
- (void)playerDidPlayToEndTime:(ZMVideoPlayerView *)playerView;

@end

@interface ZMVideoPlayerView : ZMBaseView

@property (nonatomic, retain) ZMFileEntity *fileModel;

@property (nonatomic, readonly) AVPlayer *avPlayer;

@property (nonatomic, assign) ZMVideoPlayerControlStyle controlStyle;

@property (nonatomic, assign) BOOL playDisable;

@property (nonatomic, assign) BOOL cancelDisable;

@property (nonatomic, assign) BOOL fullScreenDisable;

@property (nonatomic, assign) BOOL loopPlay;

@property (nonatomic, assign) BOOL hideFileName;

@property (nonatomic, assign) BOOL disableRespondZMkeyViewProtocol;

@property (nonatomic, assign) BOOL keepPlayingOnReset;

@property (nonatomic, weak) id<ZMVideoPlayerViewDelegate> delegate;

- (instancetype)initWithStyle:(ZMVideoPlayerControlStyle)style frameRect:(NSRect)rect;

- (void)updateUI;

- (void)playVideo;

- (void)stopPlayVideo;

- (void)pauseVideo;

- (void)displayWithAVPlayer:(AVPlayer *)avplayer;

- (void)displayWithFilePath:(NSString *)videoPath;

- (void)resetVideoPlayer;

- (void)changeStatusToDowndoading;

@end

// ---------------------------------------------------------------------------------
// ZMAVPlayerView replaces the AVPlayerView provided by Apple. ZMAVPlayerView is a view only used for visual output, and solves the problem that the subviews added to the AVPlayerView on the lower version of macOS are covered by AVPlayerView.

@interface ZMAVPlayerView : NSView

@property (nonatomic, retain) AVPlayer *player;

@end

NS_ASSUME_NONNULL_END
