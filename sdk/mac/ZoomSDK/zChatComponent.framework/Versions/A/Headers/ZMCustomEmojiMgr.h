//
//  ZMCustomEmojiMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 10/25/16.
//  Copyright © 2016 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "cmmlib/CmmDef.h"
#include "zChatApp/SaasBeePTAppInterface.h"
#include "zChatApp/StickerInterface.h"
#import "ZMGridViewDelegate.h"

@class ZMChatFileItem;
@class ZMChatEmojiWindowController;
@class ZMEmojiItemData;
@class ZMCustomEmojiItemData;
@class ZMGiphyEmojiItemData;
@class ZMStickerInfo;

@protocol ZMChatEmojiOperationDelegate <NSObject>

@optional;

- (void)didSelectedEmoji:(NSString *)emoji;

- (void)didSelectedGiyph:(ZMGiphyEmojiItemData *)customGiphyData;

- (void)didSelectedCustomEmoji:(ZMCustomEmojiItemData *)customEmojiData;


- (NSString *)currentLoginUser;

- (NSString *)emojiOperation_currentSessionId;

@end

@interface ZMCutomEmojiDataSrcMgr : NSObject
{
    NSMutableArray*       _emojiItemArray;
    id                    _gridViewId;
    BOOL                  _isImmediateReload;
    BOOL                  _isNeedScrollToEnd;
}
@property(nonatomic, readwrite, assign) BOOL isNeedScrollToEnd;
- (void)beginEdit;
- (void)endEdit;
- (BOOL)isHasExisted:(ZMStickerInfo*)inStickerInfo;
- (void)attach2GridView:(id)inGridView;
- (NSUInteger)itemDataCount;
- (ZMCustomEmojiItemData*)gridItemByStickerFileId:(NSString*)fileid;
- (void)removeAllItems;
- (void)cleanUp;
- (void)addCustomEmoji:(NSString*)strFilePath stickerInfo:(ZMStickerInfo*)inStickerInfo date:(NSDate*)inItemDate;
- (void)removeMultiCustomEmoji:(NSArray*)inItemArray;
@end


@interface ZMCustomEmojiMgr : NSObject
{
    ZMChatEmojiWindowController* _emojiWindowController;
    NSMutableDictionary* _reqestCustomEmojiDownloadDict;
    NSMutableDictionary* _reqestUploadImg2EmojiDict;
    ZMCutomEmojiDataSrcMgr* _customEmojiDataSrcMgr;
    NSUInteger                          _expectCustomEmojiItemCount;
    BOOL                                _isUISinkEnabled;
}
@property(nonatomic, readonly)          BOOL isUISinkEnabled;
@property(nonatomic, readwrite, retain) ZMChatEmojiWindowController* emojiWindowController;
@property(nonatomic, readwrite, retain) ZMCutomEmojiDataSrcMgr* customEmojiDataSrcMgr;

+ (ZMCustomEmojiMgr*)sharedInstance;

- (void)showEmojiWithPositionView:(NSView *)positionView delayShow:(BOOL)delayShow delegate:(id<ZMChatEmojiOperationDelegate>)delegate;

- (void)showEmojiWithPositionView:(NSView *)positionView delayShow:(BOOL)delayShow emojiType:(NSInteger)emojiType delegate:(id<ZMChatEmojiOperationDelegate>)delegate;

- (void)closeEmojiWindow;

- (void)cleanUp;

- (NSUInteger)expectCustomEmojiItemCount;
- (NSUInteger)requstDownloadItemCount;
- (void)checkNotDownloadedItems;
- (void)reloadAllEmoji;
- (void)makePrivateStickerByMsgWebFileID:(NSString*)inMsgWebFileId withSessionId:(NSString*)inSessionId parentWindow:(NSWindow*)inParentWindow;
- (void)uploadAndMakeEmoji:(NSString*)strFilePath sessionId:(NSString*)inCurrentSessionId;
- (BOOL)discardEmoji:(ZMStickerInfo*)inStickerInfo;
- (BOOL)discardMultiEmoji:(NSArray*)inGridItemArray;

//callback
- (void)onPrepareRegister;
- (void)onUnregistered;
- (void)onPrivateStickersUpdated;
- (void)onMakePrivateSticker:(NSUInteger)inResult stickerInfo:(ZMStickerInfo*)inStickerInfo;
- (void)onDiscardPrivateSticker:(NSUInteger)inResult stickerInfo:(ZMStickerInfo*)inStickerInfo;
- (void)onNewStickerUploaded:(NSString*)inReqId result:(NSUInteger)inResult stickerInfo:(ZMStickerInfo*)inStickerInfo;
- (void)onStickerDownloaded:(NSString*)inReqId result:(NSUInteger)inResult;

- (void) showCustomEmojiFileSizeExceed4MAlert:(NSWindow*)parentWindow;

+ (ZMChatFileItem*)fileItemByStickerInfo:(ZMStickerInfo*)inStikerInfo;
//mail
- (void)showEmojiWithPositionView:(NSView *)posView delegate:(id)delegate show:(BOOL)show emojiType:(NSInteger)emojiType rect:(NSRect)rect;

@end
