//
//  ZMChatEmojiWindowController.h
//  SaasBeePTUIModule
//
//  Created by ryan on 9/2/15.
//  Copyright (c) 2015 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMZoomEmojiDataSrcMgr.h>
#import <zChatComponent/ZMGridViewDelegate.h>
#import <zChatComponent/ZMCustomEmojiMgr.h>
#import <ZoomUnit/ZoomUnit.h>
#import <ZoomUnit/ZMSysEmojiMgr.h>

@class ZMButton;
@class ZMChatEmojiToolbarView;
@class ZMCutomEmojiDataSrcMgr;
@class ZMZoomEmojiDataSrcMgr;
@class ZMCollectionView;
@class ZMSysEmojiMgr;
@class ZMGiphyMgr;
@class ZMChatsInputContainerViewCtrl, ZMCustomSearchField;
@class ZMChatAlwaysOverlayScrollView;

typedef enum {
    ADD_CUSTOM_EMOJI_STYLE = 1,
    SYNC_CUSTOM_EMOJI_STYLE,
    NORMAL_CUSTOM_EMOJI_STYLE,
} CUSTOM_EMOJI_UI_STYLE;

typedef enum {
    GIPHY_NORMAL_STYLE = 1,
    GIPHY_NO_MATCHED_STYLE,
    GIPHY_NET_ERROR_STYLE,
    GIPHY_SERVER_ERROR_STYLE,
} GIPHY_UI_STYLE;

typedef NS_ENUM(NSUInteger, ZMShowEmojiType) {
    ZMShowEmoji          = 1,
    ZMShowGiyph          = 1 << 1,
    ZMShowCustomEmoji    = 1 << 2,
    
    ZMShowEmojiReaction  = (ZMShowEmoji | (1 << 3)),
};

@interface ZMChatEmojiListView : NSView
{
    NSTrackingArea*     _area;
    float           _angleLoaction;
    NSColor*        _triangleBackgroundColor;
}
@property (copy) NSColor* triangleBackgroundColor;
@property (assign) float angleLocation;


@end

@interface ZMChatEmojiListWindow : NSWindow
- (void)invisibleInSharing;
@end

@interface ZMChatEmojiWindowController : NSWindowController<ZMGridViewDelegate,NSTabViewDelegate,
        ZMSysEmojiMgrDelegate, ZMSysEmojiActionDelegate>
{
    IBOutlet NSTabView *_tabView;
    IBOutlet NSView* _toolbar;
    IBOutlet ZMChatAlwaysOverlayScrollView* _zoomEmojiScrollView;
    IBOutlet ZMChatAlwaysOverlayScrollView* _customEmojiScrollView;
    IBOutlet ZMChatAlwaysOverlayScrollView* _sysEmojiScrollView;
    ZMZoomEmojiDataSrcMgr*     _zoomEmojiDataSrcMgr;
    ZMCollectionView *           _zoomEmojiGridView;
    ZMCollectionView*            _customEmojiGridView;
    
    IBOutlet NSTextField*           _customEmojiSaveTip;
    IBOutlet NSTextField*           _customEmojiSaveLabel;
    IBOutlet NSTextField*           _customEmojiUploadTip;
    IBOutlet NSTextField*           _customEmojiUploadLabel;
    IBOutlet NSSearchField*         _giphySearchField;
    
    IBOutlet NSTextField*           _syncEmojiTip;
    IBOutlet NSProgressIndicator*   _syncProgressIndicator;
    IBOutlet ZMCollectionView*      _giphyEmojiGridView;
    IBOutlet NSTextField*           _giphyErrorTextField;
    BOOL                            _isCustomEmojiEnabled;
    id                              _localMouseEventMonitor;
    BOOL                            _isNeedReloadWhen2NormalMode;
    BOOL                            _isCanCloseEmojiWhenClickOutside;
    BOOL                            _isCanCloseEmojiWhenExitWnd;
    BOOL                            _isNeedShowSyncUI;
    ZMSysEmojiMgr*                  _sysEmojiMgr;
    ZMGiphyMgr*                     _giphyMgr;
}
@property(nonatomic, readwrite, assign) BOOL isCustomEmojiEnabled;
@property(nonatomic, readwrite, assign) BOOL isNeedReloadWhen2NormalMode;
@property(nonatomic, readwrite, assign) BOOL isNeedShowSyncUI;
@property(nonatomic, readonly) ZMSysEmojiMgr* sysEmojiMgr;
@property(nonatomic, readonly) ZMGiphyMgr*    giphyMgr;
@property(nonatomic, readonly) NSInteger showEmojiType;
@property(nonatomic, retain) id<ZMChatEmojiOperationDelegate> emojiOperationDelegate;
@property(nonatomic, assign) NSRect referRect;

- (id)initWithEditViewController:(id)editViewController;

- (void)showEmojiWithPositionView:(NSView *)positionView delayShow:(BOOL)delayShow emojiType:(NSInteger)emojiType delegate:(id<ZMChatEmojiOperationDelegate>)delegate;
//mail
- (void)showEmojiWithPositionView:(NSView *)posView emojiType:(NSInteger)emojiType delegate:(id)delegate rect:(NSRect)rect;

- (void)setIsCustomEmojiEnabled:(BOOL)isCustomEmojiEnabled isE2ESession:(BOOL)isE2ESession;
- (BOOL)isEditMode;
- (void)cleanUp;
- (void)customEmojiViewScrollBottom;
- (void)updateSyncServerProgress:(NSUInteger)inExpectNum completeNum:(NSUInteger)inCompletNum reqNum:(NSUInteger)inReqNum;
- (void)updateSyncServerProgressWhenDownloadFailed:(NSUInteger)inExpectNum completeNum:(NSUInteger)inCompletNum reqNum:(NSUInteger)inReqNum;
- (void)schedule2CloseEmojiWnd;
- (void)schedule2CloseEmojiWndWith:(NSTimeInterval)timeInterval;
//- (void)showAsChildWindow:(NSWindow*)parentWindow positionView:(NSView*)posView;
- (IBAction)addEmojiBtnClicked:(id)sender;
- (void)cancel2CloseEmojiWnd;
- (void)clickedUnicodeEmojiItem:(NSString*)uniCode;
- (BOOL)isGiphyNormalView;
- (void)updateGiphyView:(NSUInteger)viewType;
- (NSView *)positionView;
@end
