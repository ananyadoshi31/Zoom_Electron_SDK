//
//  ZMMessageEntity.h
//  ZCommonUI
//
//  Created by groot.ding on 17/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMFileEntity.h>
#import <zChatComponent/ZMDeepLinkEntity.h>
//#import <zChatComponent/ZMChannelInviteRequestEntity.h>


@class ZMPinMessageInfo;
@class ZMMessageFontInfo;
@class ZMMeetingChatCardEntity;
@class ZMChannelInviteRequestEntity;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMessageEntity : NSObject

@property (nonatomic, copy)      NSString *m_msgID;
@property (nonatomic, copy)      NSString *serverGuid;

@property (nonatomic, copy)      NSString *m_msgBody;

@property (nonatomic, assign)    BOOL m_isUnread;

@property (nonatomic,copy)      NSString *sessionID;

@property (nonatomic, copy)      NSString *m_senderID;
@property (nonatomic, copy)      NSString *m_senderName;

@property (nonatomic, copy)      NSString *m_receiverID;

@property (nonatomic, retain)    NSDate *m_timeStamp;
@property (nonatomic, retain)    NSDate * _Nullable editTime;

@property (nonatomic, assign)   BOOL m_atEveryone;
@property (nonatomic, assign)   BOOL m_atMe;
@property (nonatomic, assign)   BOOL m_atMentionGroup;

@property (nonatomic, assign)    unsigned long long svrSideTime;

@property (nonatomic, assign)    BOOL m_isOffline;

@property (nonatomic, readonly)  BOOL isSendOrReceived;

@property (nonatomic, readonly)  BOOL isSending;

@property (nonatomic, readonly)  BOOL isSendByMe;

@property (nonatomic, readonly)  BOOL isSendSuccessMessage;

@property (nonatomic, readonly)  BOOL isSendErrorMessage;

@property (nonatomic, readonly)  BOOL isSendFailMessage;

@property (nonatomic, readonly)  BOOL isMarkUnread;

/*msg type*/
@property (nonatomic, readonly)  BOOL isSystemMessage;

/*e2e*/
@property (nonatomic, assign)    BOOL isE2EMessage;

@property (nonatomic, readonly)  BOOL isE2EDecodeFailed;

@property (nonatomic, readonly)  BOOL isE2EMessageDecoded;

/*thread & comment*/
@property (nonatomic, assign)    BOOL isComment;
@property (nonatomic, assign)    BOOL isThread;

@property (nonatomic, assign)    BOOL hasComments;
@property (nonatomic, assign)    NSInteger iCommentsCount;

@property (nonatomic, assign)    BOOL isDeletedThread;
@property (nonatomic, assign)    BOOL isNotExistThread;
@property (nonatomic, assign)    BOOL isDeletedByChannelAdmin;

@property (nonatomic, copy)      NSString *threadID;
@property (nonatomic, assign)    unsigned long long threadServerTime;

/*reaction*/
@property (nonatomic, readonly)  BOOL hasReaction;

/*file*/
@property (nonatomic, copy)      NSString *m_localFilePath;
@property (nonatomic, assign)    NSUInteger m_audioLength;
@property (nonatomic, assign)    NSUInteger m_videoLength;
@property (nonatomic, copy)      NSString *m_fileName;
@property (nonatomic, assign)    NSUInteger m_fileSize;

/*time out*/
@property (nonatomic, assign)    BOOL isTimeout;

/*Pin Message*/
@property (nonatomic, copy) NSString *pinner;
@property (nonatomic, assign) BOOL isTopPin;

/**/
@property (nonatomic, assign) BOOL isNeedHighlightBubble;

@property (nonatomic, assign) BOOL isEmailInviteMessage;

@property (nonatomic, assign) BOOL isTempMessage;

@property (nonatomic,assign) BOOL is3rdFileStorageMsg;

@property (nonatomic,retain) ZMFileEntity *fileModel;

@property (nonatomic, retain) ZMMeetingChatCardEntity *meetingChatModel;

//jeffery add for meeting chat
@property (nonatomic, assign)BOOL            needMeetingStyle;
@property (nonatomic, copy)NSString*         m_receiverName;
@property (nonatomic, assign)NSInteger       m_MeetingChatmsgType;
@property (nonatomic, copy)NSString*         m_receiverConfId; 
@property (nonatomic, assign)BOOL            m_isSendToMe;
@property (nonatomic, copy)NSString*         m_meetingMsgId;
@property (nonatomic, assign)BOOL            enablePersistentChannel;

@property (nonatomic, retain, nullable) ZMChannelInviteRequestEntity *channelInviteRequest;

/*hybrid message*/
- (BOOL)onlyHasWhiteboardPreviewFlieList;
- (BOOL)hasAccessoryLists;
- (BOOL)hasAccessoryListsWithoutDeepLink;
- (BOOL)hasAccessoryListsWithoutWhiteboarePreview;
- (BOOL)hasAccessoryListsWithoutWhiteboardOrDeepLink;
- (NSArray<ZMFileEntity *> *)getAccessoryWhiteboardPreviewList;
- (NSArray<ZMFileEntity *> *)getAccessoryFileList;
- (NSArray<ZMFileEntity *> *)getAccessoryImageList;
- (NSArray<ZMDeepLinkEntity *> *)getAccessoryDeepLinkList;
/* combined with accessoryFileList & accessoryImageList, sorted with [ZMFileEntity positionIndex] */
- (NSArray<ZMFileEntity *> *)getSortedAccessoryList;
- (NSArray<ZMFileEntity *> *)getSortedAccessoryListWithoutWhiteboard;
/* RTF */
- (NSArray<ZMMessageFontInfo *> *)getFontStyleInfoList;

@end

@interface ZMMessageFontRangeInfo : NSObject

@property (nonatomic, assign) NSRange range;
@property (nonatomic, copy) NSString *value; //match _reserve1 in SDK data -> StyleOffset

@end

@interface ZMMessageFontInfo : NSObject

@property (nonatomic, assign) unsigned long long style;
@property (nonatomic, retain, readonly) NSMutableArray<ZMMessageFontRangeInfo*>* rangeInfoArray;

- (void)addRangeInfo:(ZMMessageFontRangeInfo*)rangeInfo;

@end

NS_ASSUME_NONNULL_END
