//
//  ZMChatMessageDataSource.h
//  zChatUI
//
//  Created by groot.ding on 2019/6/3.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMMessageAdapter;
@class ZMChatMsgItemInfo;
@class ZMChatSearchMessageInfo;

#import <zChatComponent/ZMMessageItemInfo.h>

typedef NS_ENUM(NSInteger, ZMSyncMsgType) {
    ZMSyncMsgType_None,
    ZMSyncMsgType_Init,
    ZMSyncMsgType_Newest,
    ZMSyncMsgType_LoadMoreHistroy,
    ZMSyncMsgType_Refresh,
    ZMSyncMsgType_Recent,
};

typedef NS_ENUM(NSInteger, ZMFilterReceiveMessage) {
    ZMNotFilterReceiveMessages                   = 0,
    ZMFilterReceiveThreads                       = 1 <<0,
    ZMFilterReceiveCommentsWhenThreadNotShow     = 1 <<1,
    ZMFilterReceiveOtherSendComments             = 1 <<2,
    ZMFilterReceiveAllMessages                   = 0xFFFFFFFF,
};


typedef NS_ENUM(NSInteger, ZMDataSourceType) {
    ZMDataSourceType_None                   =0,
    ZMDataSourceType_PreviewChannel         = 1 <<0,
};

typedef NS_ENUM(NSInteger, ZMHideMeetingMessageType) {
    ZMHideMeetingMessageType_None           =0,
    ZMHideMeetingMessageType_No_PMC         = 1 <<0,
    ZMHideMeetingMessageType_PMC            = 1 <<1,
};

@protocol ZMChatMessageDataSource <NSObject>

@optional
- (void)didUpdateMessagesByNodes:(NSArray <NSTreeNode *> *)nodes;

- (void)didInsertMessagesByNodes:(NSArray <NSTreeNode *> *)msgNodes indexs:(NSIndexSet *)indexset parentNode:(NSTreeNode *)parentNode;

- (void)didRemoveMessagesByNodes:(NSArray <NSTreeNode *> *)msgNodes indexs:(NSIndexSet *)indexset parentNode:(NSTreeNode *)parentNode;

- (void)didMoveMessageNode:(NSTreeNode *)msgNode fromIndex:(NSInteger)fromIndex fromParent:(NSTreeNode *)fromParent toIndex:(NSInteger)toIndex toParent:(NSTreeNode *)toParent;

- (BOOL)shouldJump2Message:(NSTreeNode *)msgNode;

- (void)didReloadAllMessage;

- (BOOL)checkMessageVisableByNode:(NSTreeNode *)msgNode;
- (BOOL)checkMessageNeedMoveByNode:(NSTreeNode *)msgNode;

- (BOOL)shouldAddReplyInputByThreadNode:(NSTreeNode *)msgNode;

- (void)didAddReplyCommentInputWithNode:(NSTreeNode *)msgNode param:(id)param;

- (void)willReceiveMessage:(ZMChatMsgItemInfo *)msg;
- (void)didReceiveMessage:(NSTreeNode *)msgNode;

- (void)didUpdateUnreadMentionMeMessageByNode:(NSTreeNode *)msgNode;
@end

@protocol ZMChatMessageLoadDelegate <NSObject>
@optional

- (void)willLoadFirstScreenThreads:(BOOL)isFromServer isSyncHistory:(BOOL)isSyncHistory;

- (void)willLoadCommentsWithRequestType:(NSInteger)reqType isSyncHistory:(BOOL)isSyncHistory isFromServer:(BOOL)isFromServer;

- (void)willLoadMoreThreads:(BOOL)isFromServer isSyncHistory:(BOOL)isSyncHistory;

- (void)willLoadNewestThreads;

- (void)didLoadFirstScreenThreads:(NSError *)error isFromServer:(BOOL)isFromServer isSyncHistory:(BOOL)isSyncHistory;

- (void)didLoadComments:(NSError *)error requestType:(NSInteger)requestType isSyncHistory:(BOOL)isSyncHistory isFromServer:(BOOL)isFromServer onThreadId:(NSString*)threadId;

- (void)didLoadMoreThreads:(NSError *)error isFromServer:(BOOL)isFromServer isSyncHistory:(BOOL)isSyncHistory;

- (void)didLoadNewestThreads:(NSError *)error;

- (void)didReceiveUnreadComment:(NSString*)commentId commentSvrSideTime:(NSInteger)commentSvrSideTime threadId:(NSString*)threadId threadSvrSideTime:(NSInteger)threadSvrSideTime;

- (void)willCollapseAllCommentMessageByThread:(NSString*)threadId;

- (void)showLoadingAnimation;
- (void)hideLoadingAnimation;
@end

@interface ZMChatMessageDataSourceImpl : NSObject

@property (weak) id<ZMChatMessageDataSource,ZMChatMessageLoadDelegate> delegate;

@property (readonly) NSTreeNode *rootNode;

@property (readonly) NSArray <NSTreeNode *> *cacheDateNodes;

@property (readonly) NSString *sessionId;

@property (readonly) NSArray < NSString *> *atMessageIds;

@property (readonly) BOOL hasMoreHistory;
@property (readonly) BOOL hasMoreRecent;

@property (readonly) ZMChatSearchMessageInfo *anchorPointSearchMessage;

@property (nonatomic,assign) BOOL needAutoAddInputReply;

@property (nonatomic,assign) BOOL needListenMessageUpdate;

@property (nonatomic,assign) BOOL needMessageTimePrompt;

@property (nonatomic,assign) BOOL needShowUnreadComments;

@property (nonatomic,assign) BOOL needShowSystemMessage;

@property (nonatomic,assign) BOOL needGroupedSystemMessage;

@property (nonatomic,assign) BOOL needSplitGroupedTodaySystemMessage;

@property (nonatomic,assign) BOOL needGroupedNewReceiveSystemMessage;

@property (nonatomic,assign) BOOL needAutoLoadComments;

@property (nonatomic,assign) NSInteger filterReceiveMessage;

@property (nonatomic,assign) BOOL isSearchDataSource;

@property (nonatomic,assign) BOOL isSearchPageSource; //Search message only in current session.

@property (nonatomic,assign) BOOL isShowPinHightlight;

@property (nonatomic,assign) NSInteger dataSourceType;

@property (nonatomic,assign) BOOL needMergeNewestThreads;

@property (nonatomic,assign) NSInteger hideMeetingSystemMessageType;

- (instancetype)initWithSessionId:(NSString *)sessionId;
- (void)updateWithSessionId:(NSString* )sessionId;
- (void)cleanAllMessages;

- (void)loadFirstScreenMessages;
- (void)loadFirstScreenMessagesByAnchorPoint:(ZMChatSearchMessageInfo *)message syncThreadsIfComment:(BOOL)loadThread;

- (void)loadMoreHistoryMessages;
- (void)loadMoreRecentMessages;
- (void)loadNewestMessages;
- (void)resetAllCacheMessages;

- (BOOL)isLoadingHistoryThreads;
- (BOOL)isLoadingRecentsThreads;
- (BOOL)isLoadingHistoryCommentsByThreadId:(NSString *)threadId;
- (BOOL)isLoadingRecentCommentsByThreadId:(NSString *)threadId;
- (BOOL)isLoadingAnchorPointMessage;

- (void)deleteMessageById:(NSString *)msgId threadSvrTime:(long long)threadSvrTime;
- (void)removeMessageById:(NSString *)msgId;
- (BOOL)updateMessageById:(NSString *)msgId;
- (BOOL)updateMessageById:(NSString *)msgId searchRanges:(NSArray <NSValue *> *)searchRanges;
- (BOOL)updateMessageById:(NSString *)msgId forceUpdate:(BOOL)forceUpdate;
- (BOOL)updateAllCodeSnippetMessages;

- (NSArray<NSString*>*)atMessageIds;
- (void)removeAtMessageInfoById:(NSString *)mgsId;
- (BOOL)updateEditedAtMessageById:(NSString *)msgId;

- (BOOL)jump2MessageWithId:(NSString *)msgId sessionId:(NSString*)sessionId;
- (BOOL)jump2MessageWithId:(NSString *)msgId;

- (void)addReplyCommentInputByThreadId:(NSString *)threadId param:(id)param;
- (void)removeReplyCommentInputByThreadId:(NSString *)threadId;
- (void)enableAllReplyCommentInput:(BOOL)isEnabled;

- (void)updateReplyInput:(NSTreeNode *)node editing:(BOOL)isEditing;
- (NSTreeNode*)findReplyNodeByThreadId:(NSString*)threadId;

- (void)upadteAllReplyCommentInput;

- (void)loadMoreCommentsByThreadId:(NSString *)threadId;
- (void)loadMoreCommentsByThreadId:(NSString *)threadId expLoadCount:(NSInteger)expLoadCount;
- (void)loadMoreRecentCommentsByThreadId:(NSString *)threadId startCommentId:(NSString *)startCommentId;
- (void)collapseAllCommentMessageByThreadId:(NSString *)threadId;

- (void)viewMoreOrLessGroupedMessage:(NSString *)msgId;

- (void)unreadCountReady;
- (void)onChatSessionActiveChanged:(BOOL)isActived;

- (void)beginEditMessageById:(NSString *)msgId;
- (void)endEditMessageById:(NSString *)msgId;

- (void)addTimedChat;
- (void)removeTimedChat;
- (void)updateTimedChatNode;
- (void)removeOutdatedMsgByEraseTime:(NSInteger)eraseTime;

- (void)removeDateNode:(NSTreeNode *)dateNode;
- (NSTreeNode*)checkAddDateNodeByDate:(NSDate *)date doInsert:(BOOL)doInsert;

- (void)addUnreadHint:(NSInteger)readedTime;
- (NSInteger)unreadHintTime;
- (void)removeUnreadHint;
- (NSTreeNode*)findMessageNodeById:(NSString*)msgId;
- (ZMChatMsgItemInfo *)findOldestThreadMessageItem;
- (ZMChatMsgItemInfo *)findNewestThreadMessageItem;
- (ZMChatMsgItemInfo *)findOldestServerTimeMessageItem;
- (ZMChatMsgItemInfo *)findLastLastSuccessItem;
- (ZMChatMsgItemInfo *)findMessageItemBySessionId:(NSString *)sessionId serverTime:(long long)serverTime;

- (NSTreeNode*)findTheLastEditableThreadSendByMe;
- (NSArray <NSTreeNode *> *)findAppMessagesContainFileId:(NSString *)fileId;
- (BOOL)hasOnlyReplyNodeByThreadId:(NSString*)threadId;
- (NSDictionary *)allExpandedThreadDict;

- (NSInteger)unreadReplyCountOnThread:(long long)threadSvrTime commentReadedTime:(long long)commentReadedTime;

- (void)reMarkLastThreadMsgWithMsgId:(NSString *)msgId;
- (NSTreeNode*)lastMarkedThreadMsgNode;
- (NSArray <ZMChatMsgItemInfo *> *)getAllFileMessages:(BOOL)imageOnly;

- (BOOL)filterMessage:(ZMChatMsgItemInfo *)msgItem;
- (void)updateNodesByShowType:(ZMMessageShowType)showType;

- (void)updateMentionMessageForMessageEditedWithMessageID:(NSString*)msgID sessionID:(NSString*)sessionID;
- (NSArray <ZMChatMsgItemInfo *> *)getAllZappMessages;

- (void)updateOnline:(BOOL)isOnline;

- (void)registerListenMessage;

- (void)removeAllMessageData;

- (void)removeMessageByItemInfo:(ZMChatMsgItemInfo *)itemInfo;

- (ZMChatMsgItemInfo *)findMessageInCacheById:(NSString*)msgId;

- (NSArray <NSTreeNode *> *)mergeMessageItems:(NSArray <ZMChatMsgItemInfo *> *)inMsgItems doReload:(BOOL)doReload;

- (ZMChatMsgItemInfo *)getMessageItemByAdapater:(ZMMessageAdapter *)message;

- (ZMChatMsgItemInfo *)messageItemByAdapater:(ZMMessageAdapter *)inMessage;

- (ZMChatMsgItemInfo *)messageItemByDate:(NSDate *)date;

- (NSArray <ZMChatMsgItemInfo *> *)getMessageItemsByAdapaters:(NSArray <ZMMessageAdapter *> *)messageArray;

- (void)callBackWillLoadMessageDelegateWithRequestType:(ZMSyncMsgType)requestType isThread:(BOOL)isThread isSyncHistory:(BOOL)isSyncHistory isFromServer:(BOOL)isFromServer;

- (void)callBackDidLoadMessageDelegateWithRequestType:(ZMSyncMsgType)requestType isThread:(BOOL)isThread isSyncHistory:(BOOL)isSyncHistory isFromServer:(BOOL)isFromServer error:(NSError *)error;

- (void)doReloadAllMessage;

- (void)onReceiveMessage:(ZMMessageAdapter *)message;

@end
