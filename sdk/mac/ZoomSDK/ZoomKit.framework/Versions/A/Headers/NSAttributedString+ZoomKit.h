//
//  NSAttributedString+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

extern NSString* const kPhoneNumber;
extern NSString* const kMeetingNumber;
extern NSString* const ZMLinkAttributeName;
extern NSString* const ZMAXRoleAttributeName;
extern NSString* const ZMTargetAttributeName;
extern NSString* const ZMActionAttributeName;

@interface NSAttributedString (ZoomKit)

+ (instancetype)attributedStringWithString:(NSString *)str attributes:(nullable NSDictionary *)attrs;

+ (instancetype)hyperlinkWithString:(NSString *)string link:(id)link;

- (NSArray *)getRectsByGlyphRange:(NSRange)glyphRange textContainer:(NSTextContainer *)textContainer;

- (NSRect)getRectByGlyphIndex:(NSInteger)index textContainer:(NSTextContainer *)textContainer;

- (NSRange)getSameAttributeRangeWithIndex:(NSUInteger)index attributeKey:(NSString *)attributeKey value:(id)value;

- (NSUInteger)charIndexWithPoint:(NSPoint)point textContainer:(NSTextContainer *)textContainer;

- (NSImage *)asImage;

/**
 Returns a new string where all new-line style characters (e.g. CRLF, paragraph separator, etc.) are replaced with the new line character
 */
- (NSAttributedString*)stringBySimplifyingNewlines;
/**
 Writes this string to the given pasteboard item for all the specified types.
 @return True if writing succeeded for all types, false if writing for any type failed
 */
- (BOOL)writeToPasteboardItem:(NSPasteboardItem*)item forTypes:(NSArray<NSPasteboardType>*)types;

- (CGFloat)getParagraphTailIndentInLocatioin:(NSInteger)location;

//support link
@property(readonly, assign) BOOL containHyperlinks;
@end
NS_ASSUME_NONNULL_END
