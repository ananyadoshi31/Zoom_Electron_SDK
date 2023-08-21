//
//  ZMShareSelectWindow.h
//  ZCommonUI
//
//  Created by walt.li on 3/2/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//


#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZPShareSelectWindowModel;
@class ZMSharePaddingMgr;
#ifdef ENABLE_ZAPP
@class ZMZAppShareScreenInfo;
#endif

@protocol ZMShareSelectWindowDelegate <NSObject>

@property (assign) BOOL isShareAudioOnForVideoShare;
@property (assign) BOOL isShareVideoOnForVideoShare;
@property (readonly) BOOL isShareAudioEnabledForVideoShare;
@property (readonly) BOOL isShareVideoEnabledForVideoShare;
@property (readonly) BOOL hasShareSoundToBOFeature;

- (void)onSegmentSelected:(NSUInteger)selectedIndex;
- (void)onStandardCloseButtonClicked;
- (void)onItemSelected:(NSArray<ZPShareSelectWindowModel *> * )selectedItems videoShare:(BOOL)videoShare audioShare:(BOOL)audioShare boShare:(BOOL)boShare;
- (void)selectWindowWillClose;
- (void)selectWindowShouldClose;
- (void)selectHoldKeyTipWindowClosed;
@optional
- (void)onItemSelected:(ZPShareSelectWindowModel *)item;
- (void)onMoreMenuClicked:(ZPShareSelectWindowModel *)model menuTag:(NSInteger)menuTag;
- (NSNumber *)moreMenuSelectedStatus:(ZPShareSelectWindowModel *)model;
- (void)onBoAlertDontShow:(BOOL)notShow;
@end

@interface ZMShareSelectWindow : /*ZMInvisibleWindow*/NSPanel

@property (nonatomic, weak, nullable) ZMSharePaddingMgr* paddingMgr;
@property (nonatomic, retain, nullable) NSArray<NSString *> *segmentTitles;
@property (nonatomic, retain, nullable) NSArray<ZPShareSelectWindowModel *> *collectionViewContent;
@property (nonatomic, retain, nullable) NSIndexSet *collectionViewSelectedIndexes;
@property (nonatomic, assign) BOOL audioShareDefaultOn;
@property (nonatomic, assign) BOOL videoShareDefaultOn;
@property (nonatomic, assign) BOOL boShareDefaultOn;
@property (nonatomic, assign) BOOL audioShareDefaultEnalbed;
@property (nonatomic, assign) BOOL videoShareDefaultEnalbed;
@property (nonatomic, assign) BOOL checkBoxContainerHidden;
@property (nonatomic, assign) BOOL audioMoreButtonHidden;
@property (nonatomic, assign) BOOL boCheckButtonHidden;
@property (nonatomic, assign) BOOL segmentHidden;
@property (nonatomic, weak, nullable) id<ZMShareSelectWindowDelegate> wndDelegate;
@property (nonatomic, copy, nullable) NSString *shareButtonTitle;
@property (nonatomic, assign) BOOL allowMultiSelect;
@property (nonatomic, assign) BOOL holdKeyTipHidden;
@property (nonatomic, assign) BOOL shouldShowBoAlert;

- (void)showWithPostion:(NSPoint)position;
- (void)selectSegmentItemAtIndex:(NSUInteger)index;
- (void)invisibleInSharing;

#ifdef ENABLE_ZAPP
- (void)updateCheckBoxForZapp:(ZMZAppShareScreenInfo *)shareInfo;
#endif
@end

NS_ASSUME_NONNULL_END
