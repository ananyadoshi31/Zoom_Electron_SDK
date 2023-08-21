//
//  NSDictionary+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSDictionary (ZoomKit)

+ (instancetype)stringAttributesWithColor:(nullable NSColor *)color font:(nullable NSFont *)font alignment:(NSTextAlignment)alignment;

- (NSString *)toJsonString;

- (NSDictionary *)dictionaryForKey:(NSString *)key;

- (NSArray *)arrayForKey:(NSString *)key;

- (NSString *)stringForKey:(NSString *)key;

- (NSNumber *)numberForKey:(NSString *)key;

- (NSInteger)integerForKey:(NSString *)key;

- (double)doubleForKey:(NSString *)key;

@end

@interface NSMutableDictionary (ZoomKit)

- (void)safelySetObject:(NSObject *)obj forKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END
