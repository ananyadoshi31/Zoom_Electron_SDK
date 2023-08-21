//
//  ZMChatMsgItemInfo.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/16.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMessageItemInfo.h>
#import <ZoomUnit/ZoomUnit.h>

typedef NS_ENUM(NSUInteger, ZMChatMsgItemFlag)
{
    ZMChatMsgItemFlag_none              = 0,
    ZMChatMsgItemFlag_session           = 1<<0,
    ZMChatMsgItemFlag_starredSession    = 1<<1,
    ZMChatMsgItemFlag_starredInfoPanel  = 1<<2,
    ZMChatMsgItemFlag_InfoPanel_Pin     = 1<<3,
    ZMChatMsgItemFlag_searchMsg         = 1<<4,
    ZMChatMsgItemFlag_mentionSession    = 1<<5,
    ZMChatMsgItemFlag_previewMsg        = 1<<6,
    ZMChatMsgItemFlag_reminderSession   = 1<<7,
};

@class ZMMessageAdapter,ZMCommonAppData,ZMChatXMLMessageBody, ZMPTGiphyData;

@interface ZMChatMsgItemInfo : ZMMessageItemInfo

@property (assign) NSSize linkPreviewSize;

@property (nonatomic, readonly) BOOL threadNotLoad;
@property (assign) BOOL isDownloading;
@property (assign) BOOL isDecoding;
@property (assign) BOOL isLinkPreviewExpanded;
@property (assign) NSUInteger  iInfoFlag;
@property (retain) NSArray* links;

@property (nonatomic, copy) NSURL* selectedLinkRUL;
@property (retain) ZMCommonAppData* commonAppData;

@property (retain) NSMutableArray<ZMChatMsgItemInfo*>* childMessages;
@property (retain) NSMutableArray<NSString*>* childURLs;

@property (retain) NSMutableArray<ZMChatMsgItemInfo*>* shortcutChildMessages;

@property (nonatomic,retain) ZMChatXMLMessageBody *xmlMessageBody;

@property (nonatomic,retain) NSDate *visibleTime;

@property (nonatomic,assign) BOOL isCommentsCountReady;
@property (nonatomic,assign) BOOL isRetryMsg;
@property (nonatomic,assign) BOOL isHasReplyItem;
@property (nonatomic,assign) BOOL isSearchMessage;
@property (nonatomic,assign) BOOL isFestivalType;
@property (nonatomic,assign) BOOL isExpandChildsMessage;
@property (nonatomic,assign) BOOL isNewReceiveMessage;
@property (assign) BOOL isPartSelected;

@property (assign) BOOL isEditByUpKey;

@property (nonatomic,retain) NSCursor *messageCursor;

@property (nonatomic,retain) AVPlayer *avPlayer;

- (ZMMessageAdapter *)messageInfo;

- (BOOL)isNeedShowShareFile;

- (BOOL)hasLinkPreview;
- (BOOL)isMentionMessage;

- (BOOL)isReminderMessage;
- (BOOL)hasReminderMessageNote;

- (BOOL)isSidebarMessage;

- (void)updateGiphyData;
- (void)checkDownloadGiphy;

- (void)updateMessageInfo;
- (void)updateCommentsInfo;

- (void)updateHasMoreCommentsWith:(NSString *)startCommentId;
- (void)updateVisableTime;

- (void)updateFestivalType;

- (void)updateLinkPreviewLinksInfo;
- (NSAttributedString*)linkPreviewAttributedString;
// ZOOM-354983: functions for new link preview UI
- (NSAttributedString*)linkPreviewAttributedStringWithSpacing:(CGFloat)spacing;
- (NSAttributedString*)linkPreviewAttributedStringWithSpacing:(CGFloat)spacing
                                              hasElementAbove:(BOOL)elementAbove
                                              hasElementBelow:(BOOL)elementBelow;

+ (instancetype)addReplyItemWithSessionId:(NSString *)sessionId threadId:(NSString *)threadId;
+ (BOOL)doesMessageFromSender:(NSString*)senderJid
    needUrlParsingInSessionId:(NSString*)sessionId;//If ZoomEvent except 1:1, only the host's text supports link preview

- (NSAttributedString *)getNameAttributedString:(CGFloat)useCache;

@end

