//
//  ZMMessageContentViewController.h
//  ChatUI
//
//  Created by Groot Ding on 2022/4/7.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMChatMessageDataSource.h>
#import <zChatComponent/ZMMessageCellViewDelegate.h>
#import <zChatComponent/ZMMessageInputProtocol.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *kIM_ChatSessionWillDisappear;

@class ZMChatMessageItemInfo;
@class ZMAddReplyMessageCellView;
@class ZMChatsNewMessageBubbleButton;
@class ZMInputTextView;
@class ZMIMMessageLayoutConfig;
@class ZMMessageItemInfo;
@class ZMBaseMessageCellView;

/// UI Configs Model
/// Suggest adding UI configs instead of business params for generality
@interface ZMMessageContentViewControllerModel : NSObject

@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, assign) BOOL needLoadHistoryWhenInit; // Determine invoke `initMessages` when `viewDidLoad`

@end

@interface ZMMessageContentViewController : ZMBaseViewController
<
NSOutlineViewDelegate,
NSOutlineViewDataSource,
ZMTrackingScrollViewProtocol,
ZMChatMessageDataSource,
ZMChatMessageLoadDelegate,
ZMMessageCellViewDelegate,
ZMToastCoordinatorProvider
>

@property (nonatomic,retain) ZMChatMessageDataSourceImpl *dataSourceImpl;

@property (nonatomic,retain) ZMNOutlineView *messagesOutlineView;

@property (nonatomic,retain) NSMutableArray *newAddedMarkUnreadMsgArray NS_RETURNS_NOT_RETAINED;

@property (nonatomic,copy) NSString *selfMarkReadMsgId;

@property (nonatomic,copy) NSString* sessionID;

@property (nonatomic,assign) BOOL needLoadMoreRecent;

@property (nonatomic,assign) BOOL isSyncDoneWhenInit;

@property (nonatomic,assign) BOOL shoudDecodeWhenSomeoneOnline;

@property (nonatomic,assign) BOOL shouldScrollToEnd;

@property (nonatomic,assign) BOOL isManualScroll;

@property (nonatomic,assign) NSInteger readedMsgTime;

@property (nonatomic,assign) BOOL jumpToBtnCanVisible;

@property (nonatomic,assign) BOOL isShowPinHightlight;

@property (nonatomic,assign) BOOL isNeedShowRemindButton;

@property (nonatomic,copy) NSString *highlightBackgroundSearchMessageId;

@property (nonatomic,copy) NSString *highlightBubbleMessageId;

@property (nonatomic,assign) BOOL shouldCleanUnread;

@property (nonatomic, assign) BOOL  isSearchView;

@property (nonatomic,retain) ZMStackView * reminderBtnStackViews;

@property (nonatomic,retain) ZMChatsNewMessageBubbleButton *reminderButton;

@property (nonatomic,retain) ZMChatsNewMessageBubbleButton *markUnreadReminderView;

@property (nonatomic, retain, nullable) ZMIMMessageLayoutConfig *layoutConfig;

// layoutManagerClass, works when tableView reloads, nullable (ZOOM-401850)
@property (nonatomic, assign) Class layoutManagerClass;

@property (nonatomic, copy) void (^updateUnreadMentionMe)(NSString *msgId);

@property (nonatomic, retain) id<ZMToastCoordinatorProtocol> toastCoordinator;

- (ZMInputTextView *)mainInputTextView;

// init methods
- (instancetype)initWithSessionID:(NSString*)sessionID;
- (instancetype)initWithModel:(ZMMessageContentViewControllerModel *)model;

- (ZMChatMessageDataSourceImpl *)getDataSourceBySessoinId:(NSString *)sessionId;

- (void)viewDidShow;

- (void)registerNotification;
- (void)updateUIForFontSizeRate:(NSInteger)sizeOffset;
- (void)onSessionActiveChanged:(BOOL)isActived;
- (void)updateMessageWhenActiveChanged:(BOOL)isActived;
- (void)resetCellHeight:(BOOL)fontSizeChanged;
- (void)cleanUpUnreadMessages;
- (void)cleanUnreadCommentsForThread:(NSInteger)svrSideTime;
- (void)resetUnreadHint;
- (void)cleanAllMessages;
- (void)updateWhenBlockStatusChanged:(BOOL)isBlocked;
- (void)updateFromMessageCellViewWithNode:(NSTreeNode *)item;
- (void)updateMessageUIByNode:(NSTreeNode *)msgNode;
- (void)noteHeightOfRowsWithIndexesChangedWithoutAnimation:(NSIndexSet*)indexSet;
- (void)updateNames;
- (void)checkAutoScroll;
- (BOOL)isStartAtFirstUnread;
- (BOOL)needUnreadHint;
- (BOOL)needTimeChat;
- (BOOL)isDropMode;
- (BOOL)needDragFiles;
- (CGFloat)messageTopMargin;
- (NSString*)sessionName;
- (NSString*)sessionNameWithoutGroup;
- (NSInteger)getUnreadMessageCount;
- (NSInteger)getReadedMessageTime;
- (NSString *)mySelfJid;
- (void)onResendItem:(ZMMessageItemInfo*)item forCellView:(ZMBaseMessageCellView*)cellView;


- (BOOL)checkNeedUpdateBuddies:(NSArray<NSString *>*)jids;
- (BOOL)jumpToMessageID:(NSString*)messageId;
- (BOOL)jumpToMessageIfShowed:(ZMChatMessageItemInfo *)msgInfo;
- (BOOL)shouldJump2MessageOnBottom:(NSTreeNode *)msgNode;
- (void)jumpToUnreadHintMsg;
- (void)jumpToUnreadMessage;
- (void)jumpStartOfUnreadMessage;

- (BOOL)updateMessageWithID:(NSString*)messageId;
- (BOOL)updateE2EMessageWithID:(NSString*)messageId;

- (void)selectMessageByNode:(NSTreeNode *)node;
- (void)beginEditMessageByNode:(NSTreeNode *)node;

//toast
- (void)showToast:(ZMToast*)toast;
- (void)removeToast:(ZMToast*)toast;

- (void)initMessages;

- (void)onMessageCountChanged;
- (BOOL)checkMessageUpdateIfNeedBySessionId:(NSString *)sessionId;
- (void)onMarkUnreadUpdate:(NSString *)sessionId messageIds:(NSArray <NSString *> *)messageIds;
- (void)resetMarkUnreadWhenViewDidShow;
- (void)schedule2CleanVisibleAreaMarkUnreadMsg;
- (void)markUnreadOrReadChanged;
- (NSArray*)getSortedMarkUnreadMessageArray:(BOOL)filterNewMarkUnread;

- (void)sessionUnreadCountReset:(BOOL)isFromOtherPlatform;

- (void)giveUpReplyRecordViewWithThreadId:(NSString*)threadId;
- (ZMAddReplyMessageCellView*)getReplyMessageCellViewForThreadID:(NSString*)threadID createIfNeed:(BOOL)createIfNeed;

- (void)loadMoreHistoryMessages;
- (void)loadMoreRecentMessages;
- (void)loadMoreCommentMessageByIds:(NSDictionary *)threadIds;
- (void)updateMessageCanloadMoreHistory;
- (void)updateMessageCanloadMoreRecent;
- (void)updateLoadMoreHistoryFinish;
- (void)updateLoadMoreRecentFinish;

- (void)cleanNoDropAllUnreadComments;

- (BOOL)requestNewPageAfterOnlineAgain;

- (void)tryToHighlightMessageBubble;
- (void)cancelHighlightMessageBubble:(NSString *)messageId;
- (BOOL)tryToHighlightBackground;

- (void)stashCurrentVisableScroll;
- (void)recoverLastVisableScroll;

- (void)setReminderButtonToVisible:(BOOL)isVisible;
- (void)setMarkUnreadReminderBtnVisible:(BOOL)isVisible;
- (void)scheduleCheckReminderButtonVisible;
- (BOOL)unread_isMainWindow;

- (void)scheduleDecodeVisableUndecodedMessages;

- (void)didUpdateUnreadMentionMeMessageByMsgId:(NSString *)msgId;

- (void)quoteMessage:(ZMMessageAdapter *)message; //jeffery add for meeting chat
- (BOOL)legalToEditMessageByMsgId:(NSString *)msgId;

- (void)hideAllMenu;
- (void)closeMessageAlerts;

- (void)showMenuWithNumber:(NSString*)numberString style:(NSInteger)style contentView:(NSView *)contentView point:(NSPoint)point;

- (void)viewFrameDidChange:(NSNotification*)notification;
- (void)resetVisibleCell;

@end

NS_ASSUME_NONNULL_END
