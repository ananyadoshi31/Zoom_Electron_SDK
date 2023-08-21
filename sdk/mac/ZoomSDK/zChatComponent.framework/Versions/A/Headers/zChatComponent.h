//
//  zChatComponent.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/7/6.
//

#import <Foundation/Foundation.h>

//! Project version number for zChatComponent.
FOUNDATION_EXPORT double zChatComponentVersionNumber;

//! Project version string for zChatComponent.
FOUNDATION_EXPORT const unsigned char zChatComponentVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <zChatComponent/PublicHeader.h>

//Base
//#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatComponent/ZPAvatarLoader.h>
#import <zChatComponent/ZMRoomCalloutDevice.h>
#import <zChatComponent/ZMCommonUIClass.h>
#import <zChatComponent/ZMMentionGroupSingleton.h>

//ZMFile
#import <zChatComponent/ZMFileEntity.h>
#import <zChatComponent/ZMFileModule.h>
#import <zChatComponent/ZMFileOperateProtocal.h>
#import <zChatComponent/ZMImageOperateModule.h>

//preview
#import <zChatComponent/ZMVideoPreViewItem.h>
#import <zChatComponent/ZMPreviewVideoItemView.h>
#import <zChatComponent/ZMFilePreViewItem.h>
#import <zChatComponent/ZMFilePreviewManager.h>
#import <zChatComponent/ZMImagePreViewItem.h>
#import <zChatComponent/ZMPreviewBaseItemView.h>
#import <zChatComponent/ZMPreviewContentView.h>
#import <zChatComponent/ZMPreviewImageItemView.h>


//ZMMessage
#import <zChatComponent/ZMMessageEntity.h>
#import <zChatComponent/ZMMessageItemInfo.h>
#import <zChatComponent/ZMChatMsgItemInfo.h>
#import <zChatComponent/ZMPTGiphyData.h>
#import <zChatComponent/ZMPinMessageInfo.h>
#import <zChatComponent/ZMReactionEmojiInfo.h>

//ZMMessage-cellview
#import <zChatComponent/ZMDLPPolicy.h>
#import <zChatComponent/ZMMessageNameCache.h>
#import <zChatComponent/ZMIMMessageLayoutManager.h>
#import <zChatComponent/ZMFileMessageCellView.h>
#import <zChatComponent/ZMVoiceMessageCellView.h>
#import <zChatComponent/ZMAppMessageCellView.h>
#import <zChatComponent/ZMIMMessageLayoutManager.h>
#import <zChatComponent/ZMIMVideoMessageCellView.h>

//ZMMessage View
#import <zChatComponent/ZMBaseMessageCellView.h>
#import <zChatComponent/ZMBubbleMessageCellView.h>
#import <zChatComponent/ZMNTextMessageCellView.h>
#import <zChatComponent/ZMPromptMessageCellView.h>
#import <zChatComponent/ZMImageMessageCellView.h>
#import <zChatComponent/ZMGiphyMessageCellView.h>
#import <zChatComponent/ZMCodeMessageCellView.h>
#import <zChatComponent/ZMMessageAccessoryView.h>
#import <zChatComponent/ZMMessageBubbleView.h>
#import <zChatComponent/ZMMessageCellViewDelegate.h>
#import <zChatComponent/ZMMessageCellViewFactory.h>
#import <zChatComponent/ZMMessageLayoutManager.h>
#import <zChatComponent/ZMReactionItemView.h>
#import <zChatComponent/ZMAvatarView.h>

//ZMVideoPlayer
#import <zChatComponent/ZMVideoPlayerView.h>
#import <zChatComponent/ZMVideoPlayerControlView.h>

//input
#import <zChatComponent/ZMChatsInputFileView.h>
#import <zChatComponent/ZMInputTextView.h>
#import <zChatComponent/ZMChatMessageCheckerUtil.h>
#import <zChatComponent/ZMChatFeatureOptionsUtil.h>

// RTF
#import <zChatComponent/ZMRichFormatConstants.h>
#import <zChatComponent/ZMRTFShortcutWindowCtrl.h>
#import <zChatComponent/ZMRichFormatTextView.h>
#import <zChatComponent/ZMTextFormatEntity.h>
#import <zChatComponent/ZMTextFormatLayoutManager.h>
#import <zChatComponent/ZMRichFormatParagraphStyle.h>
#import <zChatComponent/NSMutableAttributedString+RichFormat.h>

//Sharepoint
#import <zChatComponent/ZMIntegrationModule.h>

//Reminder Messages
#import <zChatComponent/ZMReminderMessageInfo.h>
