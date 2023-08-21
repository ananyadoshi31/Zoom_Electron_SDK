//
//  VideoUIBridge.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/6/17.
//

#import <Foundation/Foundation.h>

//! Project version number for VideoUIBridge.
FOUNDATION_EXPORT double VideoUIBridgeVersionNumber;

//! Project version string for VideoUIBridge.
FOUNDATION_EXPORT const unsigned char VideoUIBridgeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <VideoUIBridge/PublicHeader.h>

#ifdef __OBJC__

#import <zVideoUIBridge/ZMUIConstants.h>
#import <zVideoUIBridge/ZMMTTransitionModel.h>
#import <zVideoUIBridge/ZMConfSession.h>
#import <zVideoUIBridge/ZMHelperMgr.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMMTAudioHelper.h>
#import <zVideoUIBridge/ZMMTConstants.h>
#import <zVideoUIBridge/ZMNsMenu.h>
#import <zVideoUIBridge/ZMConfAPI.h>
#import <zVideoUIBridge/ZMContextHelper.h>
#import <zVideoUIBridge/ZMMTInterpretHelper.h>

#import <zVideoUIBridge/NSView+ZmmtKit.h>
#import <zVideoUIBridge/NSWindow+ZmmtKit.h>
#import <zVideoUIBridge/NSColor+ZmmtKit.h>
#import <zVideoUIBridge/NSString+ZmmtKit.h>

// CommonUI

#import <zVideoUIBridge/ZMMTBaseVideoCellView.h>
#import <zVideoUIBridge/ZMMTRender.h>

#import <zVideoUIBridge/ZMMTThumbnailView.h>
#import <zVideoUIBridge/ZMMTPageVideoView.h>
#import <zVideoUIBridge/ZMMTPaginationWrapper.h>

#import <zVideoUIBridge/ZMMTViewMgr.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>
#import <zVideoUIBridge/ZMMTBaseView.h>
#import <zVideoUIBridge/ZMMTTrackingView.h>

#import <zVideoUIBridge/ZMMTVideoView.h>
#import <zVideoUIBridge/ZMMTVideoViewController.h>
#import <zVideoUIBridge/ZMMTVideoViewMgr.h>

#import <zVideoUIBridge/ZMMTGridView.h>
#import <zVideoUIBridge/ZMMTGridCellView.h>
#import <zVideoUIBridge/ZMMTGridDragView.h>

#import <zVideoUIBridge/ZMMTSplitViewController.h>
#import <zVideoUIBridge/ZMMTSplitView.h>
#import <zVideoUIBridge/ZMMTSplitDivider.h>
#import <zVideoUIBridge/ZMMTSizeScaleFactor.h>

#import <zVideoUIBridge/ZMVideoRenderMonitor.h>

#import <zVideoUIBridge/ZMTimerMgr.h>

#import <zVideoUIBridge/ZMGuideHelpButton.h>
#import <zVideoUIBridge/ZMMTBadgeView.h>
#import <zVideoUIBridge/ZMMTDelayCall.h>
#import <zVideoUIBridge/ZMMTImageView.h>
#import <zVideoUIBridge/ZMMTLoadingView.h>
#import <zVideoUIBridge/ZMResizeView.h>
#import <zVideoUIBridge/ZMWeakProxy.h>

#import <zVideoUIBridge/ZPConfEventHandler.h>
#import <zVideoUIBridge/ZMFloatThumbnailHelper.h>

//Session&helper
#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-attributes"
#import <zVideoApp/CmmConfAPI.h>
#import <zVideoUIBridge/ZMConfHelper.h>
#import <zVideoUIBridge/ZMUser.h>
#import <zVideoUIBridge/ZMRecordHelper.h>
#import <zVideoUIBridge/ZMMTUserHelper.h>
#import <zVideoUIBridge/ZMVideoHelper.h>
#import <zVideoUIBridge/ZMAvatarHelper.h>
#import <zVideoUIBridge/ZMBOHelper.h>
#import <zVideoUIBridge/ZMMTStudioHelper.h>
#pragma clang diagnostic pop
#endif
#import <zVideoUIBridge/IZMMTPinVideoMgr.h>

//protocols
#import <zVideoUIBridge/IZMMTUserStatusProtocol.h>
#import <zVideoUIBridge/IZMMTInterpretationMgr.h>
#import <zVideoUIBridge/IZMMTSignInterpretVideoMgr.h>
#import <zVideoUIBridge/IZMMTWallViewMgr.h>
#import <zVideoUIBridge/IZMMTGroupMgr.h>
#import <zVideoUIBridge/IZMMTVideoMgr.h>
#import <zVideoUIBridge/IZMMTPlistMgr.h>
#import <zVideoUIBridge/IZMMTWhiteboardMgr.h>

#endif

