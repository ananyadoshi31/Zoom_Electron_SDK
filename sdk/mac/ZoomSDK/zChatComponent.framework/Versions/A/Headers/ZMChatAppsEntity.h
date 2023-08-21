//
//  ZMChatAppsEntity.h
//  zChatComponent
//
//  Created by Yong Zhou on 8/29/22.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ZMAPPShortcutSourceType) {
    ZMAPPShortcutSourceType_InputBox = 0,
    ZMAPPShortcutSourceType_Message,
    ZMAPPShortcutSourceType_BotMessage,
    ZMAPPShortcutSourceType_Webhook
};

typedef NS_ENUM(NSUInteger, ZMChatSessionType)
{
    ZMChatSessionType_1V1 = 0,
    ZMChatSessionType_Group, /* Channel, MUC */
};

NS_ASSUME_NONNULL_BEGIN

static NSString* const kAppCardInfo  = @"kAppCardInfo";
static NSString* const kDefaultAPPAXDesc  = @"App Card";

static NSString* const ZMChatAppShortcutAction_Dialog = @"dialog";
static NSString* const ZMChatAppShortcutAction_Command = @"command";

@interface ZMChatAppShortcutInfo : NSObject
/* The action from InputBox or Message menu */
@property (nonatomic, assign) ZMAPPShortcutSourceType sourceType;
@property (nonatomic, assign) ZMChatSessionType sessionType;
/* sessionID,messageID,threadID, locate which message the shortcut action is related */
@property (nonatomic, copy, nullable) NSString *sessionID;
@property (nonatomic, copy, nullable) NSString *messageID;
@property (nonatomic, copy, nullable) NSString *threadID;

@property (nonatomic, copy) NSString *messageHash; // message_hash
@property (nonatomic, copy) NSString *asyncID;     // bot_message_id

@property (nonatomic, copy) NSString *actionID;
@property (nonatomic, copy) NSString *zmAppID;
@property (nonatomic, copy) NSString *robotName;
@property (nonatomic, copy) NSString *robotJID;
/* shortcut name */
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *iconPath;
/* the link to open a popup webview */
@property (nonatomic, copy) NSString *link;
/* the title of popup webview */
@property (nonatomic, copy) NSString *title;
/* hide the title of popup webview */
@property (nonatomic, assign) BOOL isHideTitle;
/* hide the app name and app icon of popup webview */
@property (nonatomic, assign) BOOL isHideApp;
/* the width of popup webview */
@property (nonatomic, assign) int width;
/* the height of popup webview */
@property (nonatomic, assign) int height;

/* ZOOM-438509, dialog/command */
@property (nonatomic, copy) NSString *actionType;
/* only for webhook */
@property (nonatomic, copy) NSString *triggerID;
@property (nonatomic, copy) NSString *actionFrom;

@end


@interface ZMChatAppInfo : NSObject

@property (nonatomic, copy) NSString *robotJID;
@property (nonatomic, copy) NSString *robotName;
@property (nonatomic, copy) NSString *robotIcon;
@property (nonatomic, copy) NSArray<ZMChatAppShortcutInfo*> *shortcuts;

@end


@interface ZMChatAppMessagePreviewInfo : NSObject

@property (nonatomic, copy) NSString *threadID;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *zoomAppID;
@property (nonatomic, copy) NSString *previewID;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *desp;
@property (nonatomic, copy) NSString *appPayload;

@property (nonatomic, copy, readonly) NSString *accDescription;

@end


NS_ASSUME_NONNULL_END
