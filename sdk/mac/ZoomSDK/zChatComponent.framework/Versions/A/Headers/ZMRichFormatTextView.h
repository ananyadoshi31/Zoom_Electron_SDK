//
//  ZMRichFormatTextView.h
//  ChatUI
//
//  Created by Yong Zhou on 8/19/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMTextFormatEntity.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMRichFormatTextView : ZMTextView

- (void)updateInsertionPointColor;
- (void)setDefaultTypingAttributes;

- (NSUInteger)enabledFormats;
- (NSUInteger)fontStyleInfo;
- (ZMTextFormatInfo*)textFormatInfo;

- (CGFloat)curAppFontSize;

- (void)boldSelectedString;
- (void)italicSelectedString;
- (void)underlineSelectedString;
- (void)strikeThroughSelectedString;
- (void)setColorForSelectedString:(ZMTextColorItem *)colorItem setColorType:(ZMTextFormatTextColorType)colorType;
- (void)textSizeMenuClicked:(ZMTextFormatSizeType)sizeType;
- (void)listSelectedParagraphWithType:(ZMTextFormatListType)listType;
- (void)adjustSelectedParagraphIndent:(BOOL)increaseIndent;
- (void)onTextFormatLinkUrlConfirmed:(NSString *)linkUrlString;
- (void)onTextFormatLinkUrlEdited:(NSString *)linkUrlString linkRange:(NSRange)range;
- (void)onTextFormatLinkUrlRemoved:(NSRange)range;
- (void)setParagraphHeadingType:(ZMTextFormatParagraphType)paragraphType;
- (void)clearAllFormat;

- (void)quoteAsInputTextWithSelectedMessage:(NSString*)messageString;

- (BOOL)checkToRemoveListTypingAttributes;

- (void)convertContentFontSize;

- (void)try2ParseCopiedZMRichFormat2TextStorage:(BOOL*)parseZMRTFSucceed;
/** Same as @c try2ParseCopiedZMRichFormat2TextStorage except it returns the string instead of pasting it */
- (nullable NSAttributedString*)tryToGetZMRichTextFormatFromPasteboard;

- (void)setCurColorRange:(NSRange)range;

@end

NS_ASSUME_NONNULL_END
