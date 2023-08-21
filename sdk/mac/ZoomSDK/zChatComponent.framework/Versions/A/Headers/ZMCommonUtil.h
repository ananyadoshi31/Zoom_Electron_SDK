//
//  ZMCommonUtil.h
//  ZoomMsgUI
//
//  Created by Kevin Li on 2022/4/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUserInfo;

@interface ZMCommonUtil : NSObject

+ (nullable NSString*)getImagePathForURL:(nonnull NSString*)url;

+ (BOOL)isMarkdownFontStyle:(unsigned long long)style;
+ (BOOL)isAccessoryFileStyle:(unsigned long long)style;
+ (BOOL)isAccessoryImageStyle:(unsigned long long)style;
+ (BOOL)isAccessoryGiphyStyle:(unsigned long long)style;
+ (BOOL)isAccessoryScreenShotStyle:(unsigned long long)style;
+ (BOOL)isFileStyle:(unsigned long long)style;
+ (BOOL)isSameAsZMLink:(NSString *)zmLink1 link2:(NSString *)zmLink2;

+ (nullable NSString*)buddyPresenceString:(NSUInteger)presenceType;

+ (NSString *)getCurrentZoomDataDirectory;

+ (nullable NSAttributedString *)getMUCDisplayName:(nonnull NSArray <ZMUserInfo *> *)userInfos withAttributes:(nullable NSDictionary*)stringAttributes pixelWidth:(CGFloat)pixelWidth maxNameIndex:(NSInteger)maxNameIndex;

@end

NS_ASSUME_NONNULL_END
