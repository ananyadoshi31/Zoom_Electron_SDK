//
//  ZMIMAvatarView.h
//  zChatUI
//
//  Created by ryan on 2018/4/23.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMIMCommonDefine.h>
//#import "ZMUserManager.h"

typedef NS_ENUM(NSUInteger, ZMIMAvatarViewType) {
    ZMIMAvatarViewType_Default,
    ZMIMAvatarViewType_Custom,
    ZMIMAvatarViewType_AtAll,
    ZMIMAvatarViewType_MUC,
    ZMIMAvatarViewType_Public,
    ZMIMAvatarViewType_Public_E2e,
    ZMIMAvatarViewType_Private,
    ZMIMAvatarViewType_MeetingChats,
    ZMIMAvatarViewType_MeetingChats_Recurring,
    ZMIMAvatarViewType_Broadcast,
    ZMIMAvatarViewType_Muted,
    ZMIMAvatarViewType_NewChat,
    ZMIMAvatarViewType_MentionMe,
    ZMIMAvatarViewType_MissedCall,
    ZMIMAvatarViewType_ContactRequest,
    ZMIMAvatarViewType_Notes,
    ZMIMAvatarViewType_BookMarks,
    ZMIMAvatarViewType_AllFiles,
    ZMIMAvatarViewType_ReminderMessage,
    ZMIMAvatarViewType_Tutorials,
    ZMIMAvatarViewType_ViewMore,
    ZMIMAvatarViewType_Drafts,
};

@interface ZMIMAvatarView : NSControl

@property (nonatomic, retain) NSImage* image;
@property (nonatomic, assign) int radius;
@property (assign) float alpha;

@property (assign) NSSize inset;
@property (nonatomic, assign) ZMIMBuddyPresenceType presenceType;
@property (nonatomic, assign) ZMIMAvatarViewType type;
@property (nonatomic, assign) BOOL isHighlighted;
@property (nonatomic, assign) BOOL isDark;
@property (nonatomic, assign) BOOL isBigIcon;
@property (nonatomic, assign) BOOL isBlocked;
@property (nonatomic, assign) BOOL needShowPresence;
@property (nonatomic, copy)   NSString* jid;
@property (nonatomic, retain) NSColor *avatarFillColor;
@property (nonatomic,retain) NSImageView *imageView;

@property (nonatomic,assign) NSSize zmIntrinsicContentSize;
@property(nonatomic, assign) ZMUserProfileFloatTrackType trackType;

- (void)onMouseEntered;

+ (NSImage *)getPresenceImageByType:(ZMIMBuddyPresenceType)presenceType dark:(BOOL)isDark highlight:(BOOL)isHighlight;
+ (NSString *)getPresenceSpeakByType:(ZMIMBuddyPresenceType)presenceType;
+ (CGFloat)getPresenceRadiusByType:(ZMIMBuddyPresenceType)presenceType;

@end

@interface ZMUserAvatarView : ZMIMAvatarView
@property(copy) NSString* zmAccessibilityLabel;
@property(copy) NSString* zmAccessibilityRoleDescription;
@end
