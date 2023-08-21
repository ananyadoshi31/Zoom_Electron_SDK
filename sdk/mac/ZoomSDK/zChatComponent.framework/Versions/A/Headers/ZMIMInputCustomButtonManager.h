//
//  ZMIMInputCustomButtonManager.h
//  zChatComponent
//
//  Created by Yong Zhou on 10/31/22.
//

#import <Foundation/Foundation.h>
#import "ZMIMInputCustomButtonItem.h"

@class ZMIMInputCustomSettingWindowCtrl;

NS_ASSUME_NONNULL_BEGIN

typedef NSString* ZMIMComposeBoxButtonInfoName NS_TYPED_ENUM;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeVideoButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeAudioButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeCodeSnippetButtonInfo;
/* Reserved Begin ↓↓ */
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeFormatButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeEmojiButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeGiphyButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeScreenShotButtonInfo;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeFileButtonInfo;
/* Reserved End  ↑↑ */
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeButton;
extern ZMIMComposeBoxButtonInfoName const ZMIMComposeButtonAttributeLeading;

extern NSNotificationName const kNotificationCustomizedComposeMenusUpdated;

@interface ZMIMInputCustomButtonManager : NSObject

/// Index from which cell that can be moved
@property (nonatomic, class, readonly, assign) NSUInteger moveableBeginningIndex;

@property (nonatomic, readonly, assign) NSUInteger systemDescSeparateLineIndex;

@property (nonatomic, readonly, retain) ZMIMInputCustomSettingWindowCtrl *customizeSettingWindow;

@property (nonatomic, readonly, retain) NSMutableArray<ZMIMInputCustomButtonItem*> *internalFixedButtonInfoArr;

/// This used when commit local changes, call SDK UpdateCustomizedComposeShortcutsConfig
@property (nonatomic, readonly, retain, nullable) NSArray<ZMIMInputCustomButtonItem*> *needsUpdateButtonItemInfoArr;

@property (nonatomic, readonly, retain, nullable) NSArray<ZMIMInputCustomButtonItem*> *customizeButtonItemInfoArr;

@property (nonatomic, readonly, retain, nonnull) NSMutableArray<ZMIMInputCustomButtonItem*> *allButtonItemInfoArr;

@property (nonatomic, copy) void (^customizedComposeShortcutsChangedLocally)(void);

+ (instancetype)sharedInstance;

+ (void)releaseInstance;

// operation action
- (void)onCustomizedComposeShortcutsReset;
- (void)onUpdateOperationCanceled;
- (void)onCustomizedComposeShortcutsUpdated;

// datasource manage
- (void)setButtonHidden:(BOOL)hidden shortcutID:(nonnull NSString *)shortcutID;
- (BOOL)moveDatasourceFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/// Recycle useless  window. Try to close  setting window if not actived for several minutes(for memory issue)
- (void)tryToReleaseSettingWindow;

@end

NS_ASSUME_NONNULL_END

