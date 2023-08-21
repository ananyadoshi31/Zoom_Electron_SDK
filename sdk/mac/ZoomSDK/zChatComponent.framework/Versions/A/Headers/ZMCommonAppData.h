//
//  ZMCommonAppData.h
//  zChatUI
//
//  Created by ryan on 2018/5/7.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SBPTUI.h"

typedef NS_OPTIONS(NSUInteger, ZMCommonAppBodyType)
{
    ZMCommonAppBodyType_head,
    ZMCommonAppBodyType_subhead,
    ZMCommonAppBodyType_message,
    ZMCommonAppBodyType_field,
    ZMCommonAppBodyType_fields,
    ZMCommonAppBodyType_fieldKey,
    ZMCommonAppBodyType_attachmentFile,
    ZMCommonAppBodyType_attachment,
    ZMCommonAppBodyType_attachments,
    ZMCommonAppBodyType_action,
    ZMCommonAppBodyType_actions,
    ZMCommonAppBodyType_selectTitle,
    ZMCommonAppBodyType_select,
    ZMCommonAppBodyType_footer,
    ZMCommonAppBodyType_subbody,
    ZMCommonAppBodyType_other,
};

typedef NS_OPTIONS(NSUInteger, ZMCommonAppActionButtonStyle)
{
    ZMCommonAppActionButtonStyle_Default,
    ZMCommonAppActionButtonStyle_Primary,
    ZMCommonAppActionButtonStyle_Danger,
    ZMCommonAppActionButtonStyle_Disable,
};

typedef NS_OPTIONS(NSUInteger, ZMCommonAppSelectSourceType)
{
    ZMCommonAppSelectSourceType_members,
    ZMCommonAppSelectSourceType_channels,
    ZMCommonAppSelectSourceType_others,
};

@interface ZMAppMarkdownFile : NSObject

// png | jpg | gif | jpeg
@property (nonatomic,copy) NSString *type;
@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *alt;

@property (assign) long index;
@property (assign) long fileSize;
@property (assign) long width;
@property (assign) long height;
@end

@interface ZMAppMarkdownText : NSObject

@property (copy) NSString* text;
@property (copy) NSString* hyperlink;
@property (copy) NSString* sip;
@property (copy) NSString* mailto;
@property (copy) NSString* mentionJID;
@property (copy) NSString* linkToJid;
@property (copy) NSString* imageLink;
@property (copy) NSString* imageAlter;

@property (assign) BOOL isItalic;
@property (assign) BOOL isBold;
@property (assign) BOOL isStrikethrough;
@property (assign) BOOL isMonospace;
@property (assign) BOOL isMentionAll;
@property (assign) BOOL isConcat;

@property (assign) NSUInteger quotes;

@property (nonatomic,retain) ZMAppMarkdownFile *file;

@end

@interface ZMCommonAppSelectItemData : NSObject

@property (copy) NSString* text;
@property (copy) NSString* value;

- (id)initWithDataPointer:(void *)pItemData;
- (BOOL)isEqualWithData:(ZMCommonAppSelectItemData*)inData;

@end

@interface ZMCommonAppSelectGroupData : NSObject

@property (copy) NSString* group;
@property (retain) NSArray<ZMCommonAppSelectItemData*>* selectItems;

//- (id)initWithData:(NS_ZOOM_MESSAGER::SelectGroup)itemData;

@end

@interface ZMCommonAppSelectAllGroupsData : NSObject

@property (retain) NSArray<ZMCommonAppSelectGroupData*>* groups;
@property (assign) ZMCommonAppSelectSourceType type;

//- (id)initWithData:(NS_ZOOM_MESSAGER::MessageTemplateSelectItems)itemData;

@end

@interface ZMCommonAppDialogData : NSObject

@property (copy) NSString* appID;
@property (copy) NSString* link;
@property (copy) NSString* title;
@property (copy) NSString* actionID;
@property (assign) BOOL isHideTitle;
@property (assign) BOOL isHideApp;
@property (assign) int width;
@property (assign) int height;

@end

@interface ZMCommonAppBaseItem : NSObject

@property (copy) NSString* text;
@property (copy) NSColor* color;
@property (copy) NSString* fallBack;
@property (assign) BOOL isBold;
@property (assign) BOOL isItalic;
@property (assign) BOOL isUnsupport;
@property (assign) ZMCommonAppBodyType type;

@end

@interface ZMCommonAppHeadItem : ZMCommonAppBaseItem

@property (retain) NSArray<ZMAppMarkdownText*>* markedTextArray;

@end

@interface ZMCommonAppActionItem : ZMCommonAppBaseItem

@property (assign) ZMCommonAppActionButtonStyle style;
@property (copy) NSString* value;
@property (retain) ZMCommonAppDialogData *dialogData;

@end

@interface ZMCommonAppActionItems : ZMCommonAppBaseItem

@property (retain) NSArray<ZMCommonAppActionItem*>* actions;
@property (copy) NSString* eventID;
@property (assign) NSInteger limited;

@end

@interface ZMCommonAppSelectItem : ZMCommonAppBaseItem

@property (copy) NSString* eventID;
@property (retain) ZMCommonAppSelectAllGroupsData* data;
@property (retain) NSArray<ZMCommonAppSelectItemData*>* selectItems;

- (BOOL)isEqualToData:(NSArray<ZMCommonAppSelectItemData*>*)dataArray;

@end

@interface ZMCommonAppMessageItem : ZMCommonAppActionItem

@property (copy) NSString* link;
@property (copy) NSString* eventID;
@property (retain) NSArray<ZMAppMarkdownText*>* markedTextArray;
@property (assign) BOOL isEditalbe;

@end

@interface ZMCommonAppFieldItem : ZMCommonAppMessageItem

@property (copy) NSString* key;
@property (assign) BOOL isName;
@property (assign) BOOL isShort;

@end

@interface ZMCommonAppFieldItems : ZMCommonAppBaseItem

@property (retain) NSArray<ZMCommonAppFieldItem*>* fieldItems;
@property (copy) NSString* eventID;

@end

@interface ZMCommonAppAttachItem : ZMCommonAppBaseItem

@property (retain) NSString* resourceUrl;
@property (retain) NSString* imageUrl;
@property (retain) NSString* extention;
@property (assign) long long size;
@property (assign) NSInteger index;
@property (retain) ZMCommonAppBaseItem* descriptionItem;

@end

@interface ZMCommonAppSubBuddyItem : ZMCommonAppBaseItem

@property (copy) NSColor* barColor;
@property (retain) NSString* footer;
@property (retain) NSString* iconURL;
@property (retain) NSString* footerFallBack;
@property (retain) NSMutableArray* bodyItems;
@property (retain) NSDate* time;
@property (retain) NSMutableArray<ZMAppMarkdownText*>* markedTextArray;
@property (assign) BOOL isAddDateToMarkedTextArray;
@property (assign) BOOL isFooterUnsupport;

@end

@class ZMPTCommonAppExpandCell;

@interface ZMCommonAppData : NSObject

@property (retain) ZMCommonAppHeadItem* head;
@property (retain) ZMCommonAppHeadItem* subHead;
@property (retain) NSMutableArray* bodyItems;
@property (assign) BOOL isUnsupportMessage;
@property (assign) BOOL hasSplitSideBar;
@property (assign) BOOL hasSubBody;
@property (assign) BOOL hasMonospace;
@property (assign) BOOL hasHighlight;
@property (assign) BOOL hasProfile;
@property (assign) BOOL hasSip;
@property (assign) BOOL hasShortField;
@property (assign) BOOL isOnlyVisibleToMe;
@property (assign) NSInteger expandInfo;
@property (copy) NSColor* defaultBarColor;
@property (nonatomic, copy) NSString *botJID;

@property (assign) NSInteger headLoaction;
@property (assign) BOOL hasContent;
@property (assign, readonly) int index;
+ (NSString*)stringByReplaceLineBreak:(NSString*)srcString;

- (id)initWithSessionID:(NSString*)sessionID messageID:(NSString*)messageID index:(int)index;
- (void)constructData;
- (NSMutableAttributedString*)contentString;
- (void)setAttachmentsHideByCell:(ZMPTCommonAppExpandCell*)cell atIndex:(NSInteger)index inAttributeString:(NSMutableAttributedString*)attString;
- (ZMCommonAppSelectItem*)getSelectItemByEventID:(NSString*)eventID;

@end

typedef NS_OPTIONS(NSUInteger, ZMPTCommonAppButtonCellStatus)
{
    ZMPTCommonAppButtonCellStatus_normal,
    ZMPTCommonAppButtonCellStatus_hover,
    ZMPTCommonAppButtonCellStatus_press,
};

@interface ZMPTCommonBaseCell : NSTextAttachmentCell

@property (nonatomic, readonly) BOOL needFocusRing;

@end

@interface ZMPTCommonAppButtonCell : ZMPTCommonBaseCell

@property (copy) NSString* name;
@property (copy) NSString* eventID;
@property (copy) NSString* value;
@property (retain) ZMCommonAppDialogData *dialogData;
@property (assign) BOOL isMoreButton;
@property (assign) BOOL isHover;
@property (nonatomic, assign) ZMPTCommonAppButtonCellStatus buttonStatus;
@property (retain) NSArray<ZMCommonAppActionItem*>* actions;
@property (assign) ZMCommonAppActionButtonStyle style;
@property (nonatomic, assign) int messageTemplateIndex;
@end

@interface ZMPTCommonAppSelectCell : ZMPTCommonBaseCell

@property (copy) NSString* eventID;
@property (copy) NSString* text;
@property (retain) ZMCommonAppSelectItem* itemData;
@property (assign) BOOL isHover;
@property (nonatomic, assign) int messageTemplateIndex;
@end

@interface ZMPTCommonAppNameCell : ZMPTCommonBaseCell

@property (copy) NSAttributedString* name;

@end

@interface ZMPTCommonAppFileCell : ZMPTCommonBaseCell

@property (retain) NSAttributedString* fileName;
@property (retain) NSAttributedString* fileDescription;
@property (retain) NSString* resourceURL;
@property (retain) NSImage* iconImage;
@property (assign) BOOL isHover;
@property (assign) BOOL shouldShowToolTip;
@property (nonatomic, assign) long long size;

@end

typedef NS_OPTIONS(NSUInteger, ZMPTCommonAppImageCellType)
{
    ZMPTCommonAppImageCell_Footer,
    ZMPTCommonAppImageCell_InlineImage,
    ZMPTCommonAppImageCell_NormalImage,
    ZMPTCommonAppImageCell_DefaultInlineImage,
};

@interface ZMPTCommonAppImageCell : ZMPTCommonBaseCell

@property (nonatomic, assign) ZMPTCommonAppImageCellType cellType;
@property (nonatomic, retain) NSString* imageAlter;

@end

@interface ZMPTCommonAppActionCell : ZMPTCommonBaseCell

@property (retain) ZMCommonAppMessageItem* item;
@property (assign) float fontSize;
@property (assign) NSInteger length;
@property (nonatomic, assign) int messageTemplateIndex;
@end

@interface ZMPTCommonAppExpandCell : ZMPTCommonBaseCell

@property (nonatomic, assign) BOOL isExpanded;
@property (nonatomic, assign) NSUInteger index;
@property (retain) id cellData;

@end

