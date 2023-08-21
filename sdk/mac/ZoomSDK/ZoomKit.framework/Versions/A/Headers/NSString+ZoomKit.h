//
//  NSString+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Zoomkit/ZMBase.h>
#import <ZoomKit/ZMHtmlNodeColor.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef IsEmptyString
#define IsEmptyString(str) ([ZMUtil isEmptyString:str])
#endif

APPKIT_EXTERN NSString * ZMAutoIdentifier(void);//!< a random string
APPKIT_EXTERN NSString * const kNSEmptyString;//!< aka @""
APPKIT_EXTERN NSString * NSNonnullString( NSString * _Nullable aString);//!< no null string
APPKIT_EXTERN NSString * NSNullPlaceholderString(NSString * _Nullable aString, NSString * placeHolder);

APPKIT_EXTERN NSString * const ZMFileInfoLocalPathKey;
APPKIT_EXTERN NSString * const ZMFileInfoFileNameKey;

@interface NSString (ZoomKit)

- (BOOL)zm_containsString:(NSString *)str;
- (BOOL)hasPrefixCaseInsensitive:(NSString*)str;

@property (readonly) NSString *localizedString;
@property (readonly) NSString *unlocalized;//for analyze test
@property (readonly) NSImage *resourceImage;
@property (readonly) NSImage *resourceSvgImage;
@property (readonly) NSImage *locatedImage;

@property (readonly) NSString *stringByTrimmedWhitespaceAndNewline;
@property (readonly) NSString *stringByReplaceNewlineWithSpace;

+ (NSString *)formattedStringWithSize:(long long)size;
@property (readonly) NSString *formattedMeetingNumber;

//Path
@property (nonatomic, readonly) BOOL pathExist;
@property (nonatomic, readonly) BOOL pathIsDirectory;
- (BOOL)pathRemove;
- (NSString *)zmImageSavedPathByAppendingSelf;
- (NSString*)stringByReplaceNewlineAndParagraphWithString:(NSString*)string;
- (BOOL)isURLEncoded;
- (NSString *) MD5;

- (NSDictionary *)getURLParams;

- (NSAttributedString*)attributedString:(NSDictionary*)attributed;
- (BOOL)zm_isEqualToString:(NSString *)string;

- (NSString *)trans2HtmlSnippetALabelWithLink:(NSString *)link;
- (NSString *)trans2HtmlSnippetBLabel;
- (NSString *)trans2HtmlSnippetFontLabel:(NSInteger)fontSize;
- (NSString *)trans2HtmlSnippetFontLabel:(NSInteger)fontSize textColor:(ZMHtmlNodeColor)textColor;

- (NSAttributedString *)parseHTMLSnippet;
- (NSAttributedString *)parseHTMLSnippetWithAttachments:(NSDictionary * _Nullable)attachments;
- (NSString *)htmlEncode;

- (NSString *)trimWhitespaceAndNewline;

- (NSString *)firstComponent;

- (NSString *)stringByUrlEncoding;

- (NSURL *)matchUrl;

- (NSString *)formatMeetingNumber;

- (BOOL)isEqualToStringIgnoreCase:(NSString *)aString;

+ (NSString *) formatByEllipsis:(NSString*)aString;
+ (NSString *) formatByEllipsis:(NSString*)aString withLength:(int)strLen;

- (BOOL)isEmptyOrSpacesOnly;

- (NSArray <NSValue *> *)transUTF8RangesToNSStringRanges:(NSArray <NSValue *> *)ranges;

- (NSString *)replaceChineseColonToEnglish;

- (NSString *)replaceTWFlagEmoji;

- (NSImage *)asImageWithAttributes:(NSDictionary<NSAttributedStringKey, id> *_Nullable)attributes;

- (NSInteger)countOfCharacters:(NSCharacterSet*)characters inRange:(NSRange)range;

@property (nonatomic, readonly) BOOL isValidEmail;
//ZOOM-184780 secutity

@property (nonatomic, assign, readonly) NSInteger numberOfLines;
- (NSString*)substringWithMaxUTF8Size:(NSInteger)maxUTF8ByteSize;
@end

@interface NSString (ZMHotkey)
- (NSString*)HKStateId;
- (NSString*)HKComboId;
- (NSString*)gHKStateId;
- (NSString*)gHKComboId;
@end

@interface NSString (File)
+ (nullable NSImage *)iconImageWithFileName:(NSString *)fileName filePath:(nullable NSString *)filePath;
+ (NSDictionary *)preparedFileInfoAtDownloadDirectoryWithName:(NSString *)aFileName;
/// This method will give user a chance to choice a download dir when default download dir be deleted or permission denied
+ (void)preparedFileInfoAtDownloadDirectoryWithName:(NSString *)fileName completion:(void (^)(NSDictionary * fileInfo, BOOL isCustomFilePath))completion;

/// Returns a new string made by appending to the receiver a suitable sequential number.
///
/// Use this method to create a path string that is eligible checked by the given block.
/// A general use case is choosing the path for saving files without overwritting the
/// exisiting files. The predicate block will be called multiple times until the method
/// finds an eligible path. If the receiver is currently eligible, it will be returned
/// unmodified.
///
/// Note that if there is already an sequential number, the method will updated it instead
/// of appending a new one.
///
/// - Parameter block: A predicate block to check whether the given path is eligible.
- (NSString *)stringByAppendingFileSequentialNumberIfNecessaryUsingPredicateBlock:(BOOL (^)(NSString *proposalString))block;
@end

@interface NSMutableString (ZoomKit)
- (void)mutableReplaceTWFlagEmoji;
@end

NS_ASSUME_NONNULL_END
