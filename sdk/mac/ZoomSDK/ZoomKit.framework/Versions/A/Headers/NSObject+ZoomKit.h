//
//  NSObject+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <ZoomKit/ZMBase.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef __ZM_FUNC__

#define __ZM_FUNC__ [NSString stringWithFormat:@"[%p]%s,%@",self,__FUNCTION__,self.zmLogIdentifier].UTF8String

#endif

@interface NSObject (ZoomKit) <ZMObjectDispose>

@property (nonatomic,copy) NSString *zmLogIdentifier;

- (void)performSelector:(SEL)aSelector withArguments:(NSArray *)arguments afterDelay:(NSTimeInterval)delay;
- (void)modifyValueWithBlock:(/*NS_NOESCAPE*/ ZMPlainBlock)block forKey:(NSString *)key;

+ (BOOL)swizzleSEL:(SEL)originalSEL withSEL:(SEL)swizzledSEL;
@end
NS_ASSUME_NONNULL_END
