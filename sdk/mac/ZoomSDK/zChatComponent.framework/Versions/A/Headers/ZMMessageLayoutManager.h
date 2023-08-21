//
//  ZMMessageLayoutManager.h
//  ZCommonUI
//
//  Created by groot.ding on 20/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <zChatComponent/ZMMessageItemInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZMMessageToolButtonsAlignmentMessageBubbleTop,
    ZMMessageToolButtonsAlignmentRightTop,
    ZMMessageToolButtonsAlignmentRightFloating, // ZOOM-401850
} ZMMessageToolButtonsAlignment;

typedef enum : NSUInteger {
    ZMMessageDateAlignmentTrailing,
    ZMMessageDateAlignmentLeadingToName,
    ZMMessageDateAlignmentLeadingToAvatar,
} ZMMessageDateAlignment;

typedef enum : NSUInteger {
    ZMViewMoreCommentsButtonBule,
    ZMViewMoreCommentsButtonGrey
} ZMViewMoreCommentsButtonStyle;

typedef enum : NSUInteger {
    ZMMoreButtonNormal,
    ZMMoreButtonBorde,
    ZMMoreButtonShowJump,
} ZMMoreButtonStyle;

typedef enum : NSUInteger {
    ZMMessagePinTipAlignmentLeadingToBubble,
    ZMMessagePinTipAlignmentLeadingToReplyCount,
} ZMMessagePinTipAlignment;

@protocol ZMMessageLayoutDelegate <NSObject>

- (NSEdgeInsets)contentToCellViewEdgeInsets;

- (NSEdgeInsets)bubbleToCellViewEdgeInsets;

- (NSEdgeInsets)messageToBubbleEdgeInsets;

- (NSEdgeInsets)accessoryViewToBubbleEdgeInsets;
/*!
 @abstract The space inbetween message elements
 @discussion Some message elements are link previews, the text bubble, files, and images
 */
- (CGFloat)messageElementSpacing;

- (NSEdgeInsets)nameToCellViewEdgeInsets;

- (NSColor *)nameColor;

- (NSFont *)nameFont;

- (NSSize)avatarSize;

- (CGSize)threadAvatarSize;

- (CGSize)replyAvatarSize;

- (CGFloat)avatarRadius;

- (NSColor *)avatarFillColor;

- (BOOL)avatarEnable;

- (CGFloat)bubbleToAvatarSpacing;

- (CGFloat)threadBubbleToAvatarSpacing;

- (CGFloat)commentAvatarToReadLineSpacing;

- (NSEdgeInsets)avatarToCellViewEdgeInsets;

- (NSEdgeInsets)dateToCellViewEdgeInsets;

- (ZMMessageDateAlignment)dateAlignment;

- (CGFloat)bubbleCornerRadius;

- (NSColor *)bubbleColor;

- (NSColor *)backgroundColor;

- (NSEdgeInsets)reactionToCellEdgeInsets;

- (NSEdgeInsets)reminderToCellEdgeInsets;

- (NSSize)reminderBubbleSize;

- (NSEdgeInsets)reminderBubbleInset;

- (NSSize)reminderNoteSize;

- (NSEdgeInsets)reminderNoteInset;

- (NSSize)reminderTextSize;

- (NSEdgeInsets)pinTipToCellEdgeInsets;

- (NSEdgeInsets)linkPreviewToCellViewEdgeInsets;

- (CGFloat)sendFailedViewToBubbleBottomSpace;

- (CGFloat)sendFailedViewHeight;

- (CGFloat)viewMoreCommentsButtonHeight;

- (ZMViewMoreCommentsButtonStyle)viewMoreCommentsButtonStyle;

- (ZMMessageToolButtonsAlignment)toolButtonsAlignment;

- (CGFloat)toolButtonSpacing;

- (ZMMessagePinTipAlignment)pinTipAlignment;

- (ZMMoreButtonStyle)moreButtonStyle;

- (BOOL)isMutableSelected;

- (BOOL)validateMenuItem:(NSMenuItem *)menuItem;

- (BOOL)isNeedFitFontSizeRate;

- (CGFloat)currentFontSizeRate;
@end

@protocol ZMMessageShowElementDelegate <NSObject>

- (BOOL)isNeedShowAvatar;

- (BOOL)isNeedShowName;

- (BOOL)isNeedShowUnread;

- (BOOL)isNeedShowDate;

- (BOOL)isNeedShowToolButtons;

- (BOOL)isNeedShowMarkButton;

- (BOOL)isNeedShowAddReactionButton;

- (BOOL)isNeedShowAddReplyButton;

- (BOOL)isNeedShowExtendReplyButton;

- (BOOL)isNeedShowReactionEmoji;

- (BOOL)isNeedShowReactionView;

- (BOOL)isNeedShowCommentVisibleButton;

- (BOOL)isNeedShowViewMoreCommentView;

- (BOOL)isNeedShowE2EDecodeFailedButton;

- (BOOL)isNeedShowMessageSendingSignView;

- (BOOL)isNeedShowMoreButtonWhenSendingMessage;

- (BOOL)isNeedShowMessageSendingMaskView;

- (BOOL)isShowShowSendFailedView;

- (BOOL)isNeedShowReadLine;

- (BOOL)isNeedShowLastMsgBottomReactButtons;

- (BOOL)isNeedshowReactionHoverButton;

- (BOOL)isNeedShowTopPinTip;

- (BOOL)isNeedShowPin;

- (BOOL)isNeedShowLinkPreview;

- (BOOL)isNeedShortcutPreview;

- (BOOL)isNeedShowAccessoryListView;

- (BOOL)isNeedShowSaveAsButton4ImageViewWithFile:(ZMFileEntity*)fileItem;

- (BOOL)isNeedShowReminderBubble;

- (BOOL)isNeedShowScreenshot;

- (BOOL)isNeedShowMoreButton;

- (BOOL)isNeedShowFileButton;

- (BOOL)isNeedShowGIFPauseIcon;

@end

@protocol ZMMessageElementClassDelegate <NSObject>

- (Class)nameTextViewClass;

- (Class)textMessageTextViewClass;

@end

@protocol ZMEditMessageViewControllerProtocol;

@interface ZMIMMessageLayoutConfig : NSObject

@property (nonatomic, assign) BOOL needHideEmoji;
@property (nonatomic, assign) BOOL needHideReaction;
@property (nonatomic, assign) BOOL needHideCustomEmoji;
@property (nonatomic, assign) BOOL needHideReply;
@property (nonatomic, assign) BOOL needForceCaptureWindow;
@property (nonatomic, assign) BOOL needHideAtList;
@property (nonatomic, assign) BOOL isVideoPlayable;
// event (a trick for long long way communication)
@property (nonatomic, weak, nullable) id<ZMEditMessageViewControllerProtocol> editDelegate;

@end

@interface ZMMessageLayoutManager : NSObject <ZMMessageLayoutDelegate,ZMMessageShowElementDelegate,ZMMessageElementClassDelegate>

@property (nonatomic, retain, nullable) ZMIMMessageLayoutConfig *config;

@property (nonatomic,retain) ZMMessageItemInfo *messageItem;

@end

NS_ASSUME_NONNULL_END
