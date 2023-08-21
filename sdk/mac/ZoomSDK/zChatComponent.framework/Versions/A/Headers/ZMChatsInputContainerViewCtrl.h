//
//  ZMChatsInputContainerViewCtrl.h
//  ZoomSDKChatUI
//
//  Created by ryan on 25/05/2018.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatComponent/ZMCustomEmojiMgr.h>
#import <zChatComponent/ZMRTFShortcutWindowCtrl.h>
#import <zChatComponent/ZMIMScreenShotMgr.h>
#import <zChatComponent/ZMChatsInputContainerViewCtrlModel.h>
#import <zChatComponent/ZMIMInputButtonsContainerView.h>
#import <zChatComponent/ZMInputTextView.h>
@class ZMChatsInputFileView;
@class ZMChatsSessionViewCtrl;
@class ZMScreenShotItem;
@class ZMInputTextView;
@class ZMGroupedElementOnlyImageButton;
@class ZMInputContainerViewCtrl;
@class ZMGroupedAccessibilityView;
@class ZMTextFormatContainerView;
@class ZMFileEntity;
@class ZMSendMessageParams;

typedef NS_ENUM(NSUInteger, ZMChatsInputSendButtonToolTipType)
{
    ZMChatsInputSendButtonToolTip_Default     = 0,
    ZMChatsInputSendButtonToolTip_CanNotSendSignleChatApp
};

@protocol ZMChatsInputProtocol <NSObject>

- (void)popupNewChatNoContactTipWithSessionId:(NSString*)sessionId;
- (BOOL)isSessionHasContactWithSessionId:(NSString*)sessionId;
@end

@protocol ZMChatsInputContainerViewCtrlDelegate <NSObject>

@optional

- (BOOL)scrollToEditMyFirstThread;
- (void)chatInputViewController:(__kindof NSViewController *)viewController didClickMenuMoreButton:(__kindof NSButton *)button;
- (void)chatInputViewController:(__kindof NSViewController *)viewController didClickMenuFileButton:(__kindof NSButton *)button;
- (BOOL)chatInputViewControllerCheckCanSendMessage:(__kindof NSViewController *)viewController;

@end

@protocol ZMChatsSessionViewCtrlDelegate <NSObject>

- (void)showRecordViewFromInputView;
- (void)sessionNewChatsViewCtrlDidShow;
- (void)checkShowUserGuideInE2EChannelAfterSendHybridMsg;
@end

@interface ZMChatsInputContainerViewCtrl : ZMBaseViewController
<
ZMRTFShortcutWindowCtrlDelegate,
ZMChatEmojiOperationDelegate,
ZMScreenshotCallback,
ZMInputTextViewDelegate,
ZMToastCoordinatorProvider
>
@property (nonatomic,weak) id<ZMChatsSessionViewCtrlDelegate> sessionViewCtrlDelegate;
@property (nonatomic,weak) id<ZMChatsInputContainerViewCtrlDelegate> delegate;
@property (nonatomic,retain) ZMIMInputButtonsContainerView *menusContainerView;
@property (nonatomic,retain) ZMTextFormatContainerView *formatsContainerView;
@property (nonatomic,retain) ZMInputTextView* inputTextView;
@property (nonatomic,retain) ZMChatsInputFileView *inputFileView;
@property (nonatomic,retain) ZMPopupAlertViewController* alertMentinAll;
@property (nonatomic,assign) NSInteger style;
@property (nonatomic, retain) NSString* sessionID;
@property (assign) BOOL isFromHoverOrSelect;
@property (nonatomic, assign) NSUInteger iBtnFlag;
@property (nonatomic,copy) void (^heightChange)(float height);
//@property (nonatomic, copy) NSString *rootNodeRequestID;
@property (nonatomic, assign) BOOL isChannelEnabled3rdPartStorage;
@property (nonatomic, assign) BOOL showPrivacyExternalWarning;
@property (nonatomic, assign) NSInteger largeChannelWarningMemberCount;

@property (nonatomic, assign) NSTimeInterval editDraftTime;
@property (nonatomic, assign) BOOL isGroupChat;
@property (nonatomic, copy) NSString *searchRequestID;
@property (nonatomic, copy, readonly) NSString* searchKey;

// Custom top view, nullable
@property (nonatomic, retain) __kindof NSView *topView;
@property (nonatomic, assign) NSEdgeInsets topViewInsets;
@property (nonatomic, assign) CGFloat topViewHeight;

@property (nonatomic, assign) BOOL needHideAtList;
- (void)changeShouldShowTopView:(BOOL)shouldShowTopView needUpdate:(BOOL)needUpdate;

// UI configs Model: nullable (ZOOM-401850)
@property (nonatomic, retain) ZMChatsInputContainerViewCtrlModel *model;

@property (nonatomic, retain) id<ZMToastCoordinatorProtocol> toastCoordinator;

// Init methods
- (instancetype)initWithModel:(ZMChatsInputContainerViewCtrlModel *)model;
- (instancetype)initWithSessionID:(NSString*)sessionID;

/*
 Set placeholder
*/
// IM ssession custom placeholders: A)"What's on your mind" for my note; B) "Message someone" for DM; C) "Announce" for broadcast;
- (void)updateIMSessionPlaceholder:(NSString *)name;
// Text view placeholder
- (void)updatePlaceholder:(NSString *)placeholder;

- (void)cleanUp;
- (void)viewDidShow;
- (void)focusInputView;

- (void)updateButtons;
- (void)viewFrameDidChange:(NSNotification*)notification;

- (BOOL)popupNewChatWithBlockContactTip;

- (BOOL)sendMessageWithType:(NSInteger)type body:(NSString*)body;
- (BOOL)sendMessageWithType:(NSInteger)type body:(NSString*)body attrString:(NSMutableAttributedString*)attrString;
- (void)sendDataForNewChat:(NSDictionary*)data;
- (void)sendFiles:(NSArray<NSString*>*)files;
- (NSRect)emojiButtonFrame;
- (void)try2UpdateEmojiWndPosition;
- (void)selectCommand:(NSString*)command;
- (void)onUploadLocalFile;
- (void)onUploadLocalFileWithNode:(NSString*)nodeID;
- (void)onUploadLocalFileWithTriggerThread;

- (void)sendMessage;
- (void)checkToSendMessage;

//save draft
- (void)saveDraft;
- (NSString*)currentDraft;
- (NSArray *)currentDraftFileList;
- (NSDate *)draftLastEditTime;
- (void)cleanDraft;

//addon
- (void)addonCopyMsgAction:(NSString*)bodyMessage andType:(NSInteger)type;

- (void)updateE2EStatus:(BOOL)isEnableE2E;

- (void)addMentionToTextViewWithInfo:(NSDictionary*)dict;

- (void)updateUIForFontSizeRate:(NSInteger)sizeOffset;

- (void)popupNewChatNoContactTip;
- (BOOL)isSessionHasContact;

- (BOOL)closePopWindowIncludeFontMarkWindow:(BOOL)isInclude;

- (BOOL)showCommandListWithKey:(NSString*)key;

- (void)addIntegrationFile:(NSDictionary*)info;

- (BOOL)tryTriggerThreadInputboxActionWith:(NSButton*)btn;
- (BOOL)enterToSelectCommondOrContact;

- (BOOL)isMyNotes;
- (BOOL)isRobot;
- (BOOL)isNewChat;
- (BOOL)isScreenCaptureEabled;
- (BOOL)isCodeSnippetEnabled;
- (BOOL)isBroadcastAnnouncement;
- (BOOL)isEncrypted;

- (void)cleanInputFile;
- (BOOL)hasInputFile;

- (void)checkToUpdateFormatInfo;

- (void)changeContainForViewSizeChange;
- (NSRect)rectOfStringInInputTextViewWithRange:(NSRange)range;
- (void)showFontMarkWindowForRange:(NSRange)range;

- (void)updateInputStatus:(NSNumber*)inStatusNumber;

- (void)hideAllMenu;

// Capture Image
- (void)screenShotReceivedWithPath:(NSString *)imagePath;

// warp sending params: need to override
- (ZMSendMessageParams *)wrapSendMessageParams;
@end
