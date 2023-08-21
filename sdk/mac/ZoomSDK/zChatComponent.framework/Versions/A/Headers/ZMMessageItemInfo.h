//
//  ZMMessageItemInfo.h
//  ZCommonUI
//
//  Created by groot.ding on 17/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMessageEntity.h>
#import <zChatComponent/ZMReactionEmojiInfo.h>
#import <Zoomkit/zoom_client_conf.h>
#import <zChatComponent/ZMTranslationManagerProtocol.h>

typedef NS_ENUM(NSUInteger, ZMChatMsgItemInfoType)
{
    ZMChatMsgItemInfoType_Message = 0,
    ZMChatMsgItemInfoType_Date,
    ZMChatMsgItemInfoType_UnreadSeparator,
    ZMChatMsgItemInfoType_TodayMention,
    ZMChatMsgItemInfoType_AddReply,
    ZMChatMsgItemInfoType_GroupedSystemMessage,
};

typedef NS_ENUM(NSUInteger, ZMMessageShowType)
{
    ZMMessageShowType_Text = 0,
    ZMMessageShowType_Prompt,
    ZMMessageShowType_Image,
    ZMMessageShowType_Giphy,
    ZMMessageShowType_File,
    ZMMessageShowType_CodeSnippet,
    ZMMessageShowType_MissCall,
    ZMMessageShowType_AddReply,
    ZMMessageShowType_Audio,
    ZMMessageShowType_App,
    ZMMessageShowType_MeetingChat,
    //zapp
    ZMMessageShowType_Zapp,
    ZMMessageShowType_ScheduleMeeting,
    ZMMessageShowType_Mail,
    ZMMessageShowType_InviteRequest,
    ZMMessageShowType_PMC_UnsupportMessage
};

typedef NS_ENUM(NSUInteger, ZMCommentsMessagePostionType){
    ZMCommentsMessagePostionCenter  = 0,
    ZMCommentsMessagePostionTop     = 1 << 0,
    ZMCommentsMessagePostionBottom  = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMLoadCommentsType){
    ZMNotLoadComments,
    ZMLoadFirstScreenComments,
    ZMLoadMoreComments,
};

typedef NS_ENUM(NSUInteger, ZMEditStatus){
    ZMEditStatus_None = 0,
    ZMEditStatus_isEditing, /* Will replace property of isEditing in 'ZMMessageItemInfo.h'*/
    ZMEditStatus_isCommittingEditMsg,
    ZMEditStatus_isEditFailed,
};

@class ZMIMMessageDraft;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMessageSizeCacheProtocal <NSObject>

- (void)storeMessageSize:(NSSize)messageSize width:(CGFloat)width;
- (void)storeReactionSize:(NSSize)reactionSize width:(CGFloat)width;
- (void)storeReminderSize:(NSSize)reminderSize width:(CGFloat)width;

- (NSSize)getMessageSizeByWidth:(CGFloat)width hitCache:(BOOL *)hitCache;
- (NSSize)getReactionSizeByWidth:(CGFloat)width hitCache:(BOOL *)hitCache;
- (NSSize)getReminderSizeByWidth:(CGFloat)width hitCache:(BOOL *)hitCache;

- (void)cleanMessageSizeCache;
- (void)cleanReactionSizeCache;

@end

@protocol ZMMessageInfoUpdate <NSObject>
- (void)didMessageInfoUpdate;
- (void)didMessageExtensionUpdate;
@end

@interface ZMEditMessageInfo : NSObject

@property (nonatomic, copy, nullable) NSAttributedString *editString;

@property (nonatomic, copy, nullable) NSArray<ZMFileEntity *> *editFileList;

@property (nonatomic, retain, nullable) ZMIMMessageDraft *draft;

- (BOOL)isEmpty;

- (void)cleanContent;

@end

@interface ZMCopyMessageInfo : NSObject

@property (nonatomic, copy) NSString *string;
@property (nonatomic, retain) NSArray<ZMMessageFontInfo *> *fontStyleInfoList;
@property (nonatomic, retain) NSArray<NSURL *> *fileURLs;
@property (nonatomic, readonly) BOOL isEmpty;
- (void)writeToPasteboard;
@end

@interface ZMMessageTranslationInfo : NSObject
/// The SDK translation-request ID for this message's latest translation
@property (nonatomic, copy) NSString* requestID;
/// The message's translated text. nil if the translation request is still in-flight.
@property (nullable, nonatomic, copy) NSString* translation;
/// The language the message was translated from.
@property (nonatomic, copy) ZMLanguageCode sourceLanguage;
@end

NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN

@class ZMPTGiphyData,ZMMessageLayoutManager;

@interface ZMMessageItemInfo : NSObject <ZMMessageSizeCacheProtocal,ZMMessageInfoUpdate>

@property (nonatomic, retain) ZMMessageEntity *message;

@property (nonatomic, assign) NSSize inputFileViewSize;
@property (nonatomic, assign) NSSize inputFileScrollViewSize;

@property (nonatomic, assign) NSSize accessoryViewSize;
@property (nonatomic, assign) BOOL accessoryListViewSelected;
@property (nonatomic, assign) CGFloat messagePaneWidth;

@property (nonatomic, assign) BOOL isDeepLinkPreviewCollapsed;

@property (nonatomic,assign) NSSize messageSize;

@property (nonatomic,assign) NSSize reactionSize;

@property (nonatomic,assign) NSSize reminderSize;

@property (nonatomic,assign) NSSize linkStackSize;

@property (nonatomic,assign) NSSize shortcutStackSize;

@property (nonatomic,assign) NSSize referenceMessageSize;

@property (nonatomic, copy) NSString *sessionId;//Attention: Not reliable, may be nil. Check it before using

@property (nonatomic,readonly) NSTimeInterval timeInterval;

@property (nonatomic, readonly) ZMMessageShowType showType;

@property (nonatomic, assign) ZMChatMsgItemInfoType infoType;

@property (nonatomic, retain) ZMEditMessageInfo *editMessageInfo;

@property (nonatomic, assign) BOOL isEditMessageInfoAssigned;

@property (nonatomic,assign) BOOL isHideHead;

@property (nonatomic,assign) BOOL isEditing;

@property (nonatomic,assign) ZMEditStatus editStatus;

@property (nonatomic,assign) BOOL isE2EDecoding;

@property (nonatomic,assign) BOOL isUnreadState;

@property (nonatomic,setter=setMessageDirty:) BOOL isMessageDirty;

@property (nonatomic,getter=isHoverSelected) BOOL hoverSelected;

@property (nonatomic,assign) BOOL convertToTextMessage;

@property (nonatomic,readonly) BOOL isAddReplyItem;

//star
@property (nonatomic,readonly) BOOL isStarStyleMessage;

@property (nonatomic,readonly) BOOL isStarredMessagesSession;

@property (nonatomic,readonly) BOOL isStarred;

//pin
@property (nonatomic,readonly) BOOL isPinStyleMessage;

//link preview
@property (nonatomic,readonly) BOOL hasLinkPreview;

//Mention
@property (nonatomic,readonly) BOOL isMentionMessage;

//Reminder Messsage
@property (nonatomic,readonly) BOOL isReminderMessage;
@property (nonatomic,readonly) BOOL hasReminderMessageNote;

//thread & comments
@property (nonatomic, copy) NSString *threadId;

@property (nonatomic,assign) ZMLoadCommentsType loadCommentsType;

@property (nonatomic,assign) BOOL isLastThreadMsg;

@property (nonatomic,assign) NSInteger commentsPostionType;

@property (nonatomic,assign) BOOL isLoadCommentsFromNewest;

@property (nonatomic,readonly) NSInteger currentCommentCount;
@property (nonatomic,assign) NSInteger displayCommentCount;
@property (nonatomic,assign) NSInteger displaySuccessCommentCount;
@property (nonatomic,assign) BOOL hasMoreHistoryComments;
@property (nonatomic,assign) BOOL hasMoreRecentComments;

@property (nonatomic,assign) BOOL hasUnreadComments;

//collapsed
@property (nonatomic,assign) BOOL isCollapsed;

@property (nonatomic,assign) BOOL isFormatMenusExpanded;

@property (nonatomic,assign) BOOL isShowPinHightlight;

@property (nonatomic,assign) BOOL isNeedHighlightBackground;

@property (nonatomic,assign) BOOL enableMentionGroupLink;

@property (nonatomic,assign) BOOL isUseMessageSizeCache;

//giphy
@property (nonatomic,retain) ZMPTGiphyData *giphyData;
@property (nonatomic,assign) BOOL isGiphyMixedMessageEnabled;
//emoji
@property (nonatomic,assign) BOOL isEnableEmoji;

//search ranges
@property (nonatomic,retain) NSArray <NSValue *> *searchedRangeArray;

@property (nonatomic,weak,nullable) ZMMessageLayoutManager *layoutManager;

//attributedString
@property (nonatomic,readonly) NSAttributedString *messageAttributedString;

@property (nonatomic,readonly) NSAttributedString *editMessageAttributedString;

@property (nonatomic,readonly) NSAttributedString *nameAttributedString;

/** ZOOM-354983 OP flag copied here so it's reachable outside of the ChatUI project */
@property (nonatomic, assign) BOOL isImageFileSharingImprovementEnabled;
/// True iff this message should display the translation of its original contents.
@property (nonatomic, assign) BOOL isTranslated;
/// The translation info for this message. nil if the user has not translated this message.
@property (nullable, nonatomic, retain) ZMMessageTranslationInfo* translationInfo;
/// The translation of this message with the proper attributes for display. nil if the user has not translated this message.
@property (nullable, nonatomic, readonly, strong) NSAttributedString* translationAttributedString;

@property (nonatomic,readonly) BOOL isPMCUnsupportMessage;

@property (nonatomic,assign) BOOL needsRedraw;

- (ZMMessageEntity *)messageInfo;

- (NSAttributedString *)getMessageAttributedString;
- (NSAttributedString *)getNameAttributedString;
- (NSAttributedString *)getNameAttributedString:(CGFloat)pixels;
- (NSString *)getDateString;

- (NSString *)getFileName;

- (NSImage *)getAvatarImage;
- (NSString *)getSessionName;
- (NSString *)getPinnerName;
- (BOOL)isImageFile;

- (NSArray <ZMReactionEmojiInfo *> *)getReactionEmojiList;

- (BOOL)startDownloadFileByManual:(BOOL)isManual;

- (void)updateGiphyData;
- (void)updateMessageInfo;
- (void)updateCommentsInfo;
- (void)updateReactionInfo;
- (void)updateOtherExtesionInfo;
- (void)updateTranslated;

//copy
- (ZMCopyMessageInfo *)copyMessageByRange:(NSRange)range NS_RETURNS_NOT_RETAINED;
- (NSString *)getCopyFilePath;

@end

NS_ASSUME_NONNULL_END
