//
//  ZMChatsAtListWindowCtrl.h
//  zChatUI
//
//  Created by ryan on 20/06/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMTableViewUtilCellView.h>
#import <zChatComponent/ZMChatsAtListEntity.h>

@class ZMBuddyAdapter;
@class ZMSessionGroupAdapter;

extern NSString* kIMChatsAllJID;

@interface ZMChatsAtListBaseView : NSTableCellView

@property (nonatomic, assign) BOOL showExternalIcon;

- (void)updateUI;
- (void)setSelected:(BOOL)isSelected;

@end

@interface ZMChatsAtListChannelView : ZMChatsAtListBaseView

@end

@interface ZMChatsAtListContactView : ZMChatsAtListBaseView

@end

@interface ZMChatsAtListMucView : ZMChatsAtListBaseView

@end

@interface ZMSearchMoreCellView : ZMChatsAtListBaseView

@end

@interface ZMChatsAtListWindow : NSWindow

- (void)invisibleInSharing;

@end

@interface ZMChatsAtListView : NSView

@end

@class ZMSearchResultItem;

@class ZMChatsAtListWindowCtrl;

@protocol ZMChatsAtListWindowDelegate <NSObject>
@optional
- (void)handleChannelUpdates:(ZMChatsAtListWindowCtrl*)sender channel:(NSString*)channelId;
- (void)selectUserInAtList:(NSDictionary*)dict;
@end

typedef NS_ENUM(NSUInteger, ZMChatAtListShowFrom) {
    ZMChatAtListShowFrom_ChatInviteSearch,
    ZMChatAtListShowFrom_ChatInviteInput
};

@interface ZMChatsAtListWindowCtrl : NSWindowController

@property (nonatomic, assign) id<ZMChatsAtListWindowDelegate> delegate;
@property (nonatomic, assign) BOOL isInEditView;
@property (nonatomic, assign) ZMChatsAtListType listType;
@property (nonatomic, copy) NSString* sessionID;
@property (nonatomic, copy) NSString* threadID;
@property (nonatomic, assign) BOOL showExternalIcon;
@property (nonatomic, weak) NSView *positionView;

+ (instancetype)defaultWindowController;

- (void)updateDataWithKey:(NSString*)key forType:(ZMChatsAtListType)type;
- (void)resetWithSessionID:(NSString*)sessionID;
- (void)removeFromParentWindow;

- (BOOL)setContactData:(NSArray*)data forFromType:(ZMChatAtListShowFrom)fromType;
- (BOOL)setContactData:(NSArray*)data forFromType:(ZMChatAtListShowFrom)fromType andKeepSelectedRow:(BOOL)isRemain;
- (NSArray<ZMBuddyAdapter*>*)getContactData;
- (void)setMucData:(NSArray *)mucs andKeepSelectedRow:(BOOL)isRemain withKey:(NSString *)key;

- (void)updateBuddys:(NSArray*)jids;
- (void)subscribeVisibleUsersPresence;
- (void)addSearchResult:(NSArray<ZMSearchResultItem*>*)items;
- (void)addChannelWithKey:(NSArray<ZMSessionGroupAdapter*>*)channels key:(NSString *)key;

- (BOOL)canShowWindow;

- (void)updateCurrentSelectionView:(BOOL)bSelected;

- (void)selectNextItem;
- (void)selectPreviousItem;
- (NSDictionary*)getSelectedItemInfo;

- (NSArray *)getSubscribeVisibleUsersPresence;
@end
