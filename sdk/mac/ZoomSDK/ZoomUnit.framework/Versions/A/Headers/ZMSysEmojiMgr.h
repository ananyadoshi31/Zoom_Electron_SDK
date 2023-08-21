//
//  ZMSysEmojiMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/3/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMEmojiUnicodeData.h>
@class ZMBaseView;
@class ZMSysEmojiToolbarItemModel;

@protocol ZMSysEmojiMgrDelegate <ZMEmojiUnicodeDataDelegate>
- (void)sysEmojiMgrDidSelectedEmoji:(NSString *)emojiCode;
- (void)sysEmojiMgrDidAddFavorite:(NSString *)emojiCode;
- (int)sysEmojiMgrDidGetSkinTone;
@end

@protocol ZMSysEmojiActionDelegate <NSObject>
- (void)emojiItemDidClicked:(NSString *)emojiCode;
@end

@interface ZMSysEmojCollectionView : NSCollectionView{
    NSInteger      _hoverIndex;
}

@property (nonatomic, assign) BOOL respondToKeyboard;
@property (nonatomic, strong) NSNumber *zm_canBecomeKeyView;
@property (nonatomic, strong) NSNumber *zm_canBecomeFirstResponder;

@property (weak) id myController;
@property (nonatomic, weak) id<ZMSysEmojiActionDelegate> actionDelegate;
- (NSString*)selectedEmojiCode;
- (void)hoverItemViewByIndex:(NSInteger)idx andIsHovered:(BOOL)isHovered;
- (void)resetAllItemHoverStatus;
- (void)mouseIsMoving;
- (void)mouseExisted;
- (void)produceTrackingBySelf;
- (void)stopProducesTracking;
@end

@interface ZMSysEmojiView : NSView
@property (nonatomic, assign) BOOL drawBorder;
@property (nonatomic, retain) NSColor *backgroundColor;
@property (nonatomic, retain) NSColor *borderColor;
@end

@interface ZMSysEmojiMgr : NSObject 
@property (nonatomic, weak) id<ZMSysEmojiMgrDelegate> delegate;
@property (nonatomic, assign) BOOL forceDarkMode;

- (instancetype)initWithDelegate:(id<ZMSysEmojiMgrDelegate>)delegate;
- (ZMEmojiUnicodeData*)emojiUnicodeData;
- (void)cleanUp;
- (void)onSearch:(NSString*)searchString;
- (void)onTagSelected:(NSUInteger)tag;
- (void)addFavorite:(NSString*)uniCode;
- (void)clickedItem:(NSString*)uniCode;
- (void)resetEmojiView;
- (void)makeSearchFiledFirstResponder;
- (NSView*)getUnicodeEmojiView:(NSRect)inRect;
- (void)reloadSysEmojiData;
- (BOOL)isInEmojiFont:(NSString*)uniString;
- (Class)emojiItemViewClass;
- (NSArray<ZMSysEmojiToolbarItemModel *> *)tableBarDataSource;
@end

@protocol ZMSkinToneButtonDelegate <NSObject>

- (void)skinToneButtonDidSetSkinTone:(NSUInteger)skinTone;

@end
@interface ZMSkinToneButton : NSView
@property (nonatomic, assign) BOOL forceDarkMode;
@property (nonatomic, weak) id<ZMSkinToneButtonDelegate> delegate;

+ (NSInteger)expWidth;
+ (BOOL)isSupportSkinTone;
- (void)cleanUp;
@end

@interface ZMSysEmojiItemView : NSView
@property(nonatomic, readwrite, assign)BOOL isHovered;
@property(nonatomic, readwrite, copy)NSString* emojiUnicodeString;
- (void)cleanUp;
@end


