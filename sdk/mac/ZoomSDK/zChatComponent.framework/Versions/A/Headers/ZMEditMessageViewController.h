//
//  ZMEditMessageViewController.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/29.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMIMInputButtonsContainerView.h>

@class ZMInputTextView;
@class ZMStickerInfo;
@class ZMChatsInputFileView;
@class ZMEditMessageInfo;
@class ZMFileEntity;
@class ZMIMOnlyImageButton;
@class ZMEditMessageViewController;

typedef NS_ENUM(NSUInteger, ZMEditMessageUIStyle)
{
    ZMEditMessageUIStyle_AddReply     = 0,
    ZMEditMessageUIStyle_EditMessage  = 1<<0,
};

typedef NS_ENUM(NSUInteger, ZMRecordMessageType)
{
    ZMRecordMessageVoiceType,
    ZMRecordMessageVideoType
};

@protocol ZMEditMessageViewControllerProtocol <NSObject>

- (void)editViewController:(ZMEditMessageViewController *)vc addReplyDidClickFileButton:(id)sender;
- (BOOL)editViewController:(ZMEditMessageViewController *)vc checkScreenshotPath:(NSString *)imagePath;
// fetch a flag: should enable parsing deeplinks
- (BOOL)editViewControllerFetchEnableParseDeeplink:(ZMEditMessageViewController *)vc;
// invoke when deeplink parsing is disabled
- (void)editViewControllerShowDisableDeeplink:(ZMEditMessageViewController *)vc;

@end

@interface ZMEditMessageViewController : ZMBaseViewController

@property (nonatomic,retain) ZMIMInputButtonsContainerView *compositionButtonContainerView;

@property (nonatomic,copy) NSString *sessionID;

@property (nonatomic,copy) NSString *threadId;

@property (nonatomic,retain) ZMInputTextView *inputTextView;

@property (nonatomic,retain) ZMChatsInputFileView *inputFileView;

@property (nonatomic,readonly) NSEdgeInsets inputViewEdgeinset;

@property (nonatomic,readonly) NSEdgeInsets inputFileViewEdgeinset;

@property (nonatomic,assign) BOOL isContainAt;

@property (nonatomic,assign) BOOL hasAppPreviewCard;

/**
 default YES
 */
@property (nonatomic,assign) BOOL needEmojiButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needFileButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needRecordButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needRecordVideoButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needScreenShotButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needCodeSinppetButton;

/**
 default NO
 */
@property (nonatomic,assign) BOOL needGiphy;
/**
 default NO
 */
@property (nonatomic,assign) BOOL needCustomEmoji;
/**
 default NO
 For in meeting chat
 */
@property (nonatomic,assign) BOOL needHideAtList;
/**
 default NO
  1. If return NO, when clicked the screenshot button, ZMIMScreenShotMgr will read 'kCaptureWithoutChatWindow' from userDefalt to determine whether or not it will capture current window.
  2. If return YES, ZMIMScreenShotMgr will capture current window.
 */
@property (nonatomic,assign) BOOL needForceCaptureWindow;
/**
 default YES
 */
@property (nonatomic,assign) BOOL isVideoPlayable;

@property (nonatomic,assign) ZMEditMessageUIStyle style;

@property (nonatomic,readonly,assign) BOOL isFormatMenusExpanded;

@property (nonatomic,copy) void (^commitMessage)(NSAttributedString *message, NSArray<ZMFileEntity *> *fileListArr);

@property (nonatomic,copy) BOOL (^recordBtnClicked)(ZMRecordMessageType recordMessageType);

@property (nonatomic,copy) void (^selectFileIntegration)(NSInteger fileType);

@property (nonatomic,copy) void (^sendGiyph)(NSString *giyphId);

@property (nonatomic,copy) void (^sendCustomEmoji)(ZMStickerInfo *customEmoji);

@property (nonatomic,copy) void (^cancelEditMessage)();

@property (nonatomic,copy) void (^updateMessage)(NSAttributedString *message, NSArray<ZMFileEntity *> *fileListArr);

@property (nonatomic,copy) void (^updateFirstResponse)(BOOL firstResponse);

@property (nonatomic,copy) void (^saveDraft)();

@property (nonatomic, weak) id<ZMEditMessageViewControllerProtocol> delegate;

- (void)makeInputViewFirstResponse;

- (void)cleanContent;
- (void)updateUIWithStyle:(ZMEditMessageUIStyle)style;
- (void)updateTextViewLayout;
- (void)updateButtonsLayout;

- (NSAttributedString *)messageString;

- (void)setEditMessageInfo:(ZMEditMessageInfo *)editMessageInfo;

- (void)setInputTextViewFontSize:(NSInteger)fontSize;

- (void)selectUserWithJid:(NSString*)jid name:(NSString*)name isCheckAtRange:(BOOL)isCheckAt;

- (CGFloat)calculateToolMenusHeight:(BOOL)formatsExpanded;
- (NSSize)calculateSizeWithAttributeStirng:(NSAttributedString *)string width:(CGFloat)width;
- (NSSize)calculateSizeWithFileLists:(NSArray <ZMFileEntity *> *)fileLists width:(CGFloat)width;

- (void)updateFileInputViewHeight:(CGFloat)height scrollViewHeight:(CGFloat)scrollViewH;

- (void)uploadLocalFile;
- (void)addIntegrationFile:(NSDictionary*)info;
- (BOOL)isFileButtonEnable;

- (nullable NSArray *)fontStyleInfoWithAttachment:(BOOL)parseAttachment;

@end
