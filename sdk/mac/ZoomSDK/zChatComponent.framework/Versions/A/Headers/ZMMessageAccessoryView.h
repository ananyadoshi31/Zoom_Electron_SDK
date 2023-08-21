//
//  ZMMessageAccessoryView.h
//  zChatUI
//
//  Created by Yong Zhou on 7/29/20.
//  Copyright © 2020 Zoom. All rights reserved.
//


#import "ZMFileView.h"
#import "ZMHybridImageView.h"
#import "ZMWhiteboardView.h"
#import <ZoomKit/ZMGridAccessibilityView.h>
#import <zChatComponent/ZMDeepLinkPreviewView.h>
#import <zChatComponent/ZMDeepLinkEntity.h>

@class ZMFileEntity;

@interface ZMMessageAccessoryView : ZMGridAccessibilityView <ZMMutableSelectProtocal>

@property (nonatomic, weak) id<ZMFileViewDelegate> fileDelegate;

@property (nonatomic, weak) id<ZMHybridImageViewDelegate> imageDelegate;

@property (nonatomic, retain) NSArray<ZMDeepLinkEntity *> *deepLinkList;

@property (nonatomic, retain) NSArray<ZMFileEntity *> *whiteboardList;

@property (nonatomic, retain) NSArray<ZMFileEntity *> *imageInfoList;

@property (nonatomic, retain) NSArray<ZMFileEntity *> *fileInfoList;

@property (nonatomic, assign) BOOL isSelected;

@property (nonatomic, assign) BOOL shouldFoldImage;

@property (nonatomic, assign) BOOL needHoverButtons;

@property (nonatomic, assign) BOOL isAttachedToReplyMessage;

/*!
 The width of the first row of accessories.
 @discussion This property is set when the view is laid out in @c layoutSubviewByMaxWidth:messagePaneWidth:contentAbove:
 @note This property is only valid if the view was laid out with @b no content above.
 If there is content above, you should use the width of that content instead.
 */
@property (nonatomic, readonly, assign) CGFloat topRowWidth;
/*! The spacing inbetween different accessories
 @note This is both the spacing inbetween accessories of the same type (e.g. image <-> image) and accessories of different types (e.g. image <-> file)
 */
@property (nonatomic, assign) CGFloat accessorySpacing;

- (void)cleanContent;

- (void)layoutSubviewByMaxWidth:(CGFloat)accessoryViewMaxWidth;
- (NSSize)calculateViewByMaxWidth:(CGFloat)accessoryViewMaxWidth maxTextWidth:(CGFloat)maxTextWidth;
- (NSSize)calculateViewByMaxWidth:(CGFloat)accessoryViewMaxWidth maxTextWidth:(CGFloat)maxTextWidth withCollapsedDeepLinkPreview:(BOOL)isDeepLinkPreviewCollapsed;
// ZOOM-354983: functions for new UI
- (void)layoutSubviewByMaxWidth:(CGFloat)accessoryViewMaxWidth messagePaneWidth:(CGFloat)messagePaneWidth
                   contentAbove:(BOOL)hasContentAbove;
- (NSSize)calculateViewByMaxWidth:(CGFloat)accessoryViewMaxWidth messagePaneWidth:(CGFloat)messagePaneWidth;
- (NSSize)calculateViewByMaxWidth:(CGFloat)accessoryViewMaxWidth messagePaneWidth:(CGFloat)messagePaneWidth withCollapsedDeepLinkPreview:(BOOL)isDeepLinkPreviewCollapsed;

@end
