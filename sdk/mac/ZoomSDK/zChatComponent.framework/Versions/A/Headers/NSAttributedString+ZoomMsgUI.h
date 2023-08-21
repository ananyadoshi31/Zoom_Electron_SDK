//
//  NSAttributedString+Message.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/30.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZMMessageFontInfo;
@class ZMImageViewAttachmentCell;

@interface NSAttributedString (ZoomMsgUI)

- (NSString *)getMessageStringAndAtList:(NSArray **)atlist emojiExtension:(void **)emojiExtension sessionID:(NSString*)sessionID;

- (NSArray *)splitInputMessage;

- (NSArray*)fontStyleInfo;

/* attachment like "@name, #channel-name" should not parsed to plain-text to calculate the range of font-style when save to draft */
- (NSArray*)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment;

- (NSMutableAttributedString *)getRichFormatTextWithText:(NSString*)text fontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo curAppFontSize:(CGFloat)appFontSize;

- (NSArray <ZMImageViewAttachmentCell *> *)getImageViewAttachments;

@end


@interface NSMutableAttributedString (ZMLink)

- (void)addZMLinkToolTip;
- (void)removeZMLinkToolTip;
- (void)removeLink;
- (void)removeCursor;

@end

@interface NSMutableAttributedString (Emoji)

- (void)changeEmojiStringFont;
- (void)changeEmojiStringFontForIMInputTextViewWithFontSize:(CGFloat)fontSize;
@end
