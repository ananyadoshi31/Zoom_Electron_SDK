//
//  ZMMTDelayCall.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/10/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTDelayCall : NSObject
@property(copy) void (^action)(void);
@property(assign) CGFloat timeInterval;//default 0.1
+ (instancetype)delayCall;
///will call by delay if needed
- (void)setNeedsCall:(BOOL)need;
///will call immediately
- (void)callAction;
@end

@interface ZMMTAsyncCall<Type> : NSObject
@property(copy) void (^action)(Type value);
+ (instancetype)asyncCall;
- (void)callWithValue:(nullable Type)value;
@end

@interface ZMMTCoalesceCall<Type> : NSObject
@property(copy) void (^action)(NSArray<Type>* values);
@property(assign) CGFloat timeInterval;//default 0.1
+ (instancetype)coalesceCall;
- (void)callWithValue:(nullable Type)value;
- (void)cancel;
@end

@interface ZMMTConcurrencyCall<Type> : NSObject
@property(copy) void (^action)(NSArray<Type>* values);
@property(assign) CGFloat timeInterval; // default 0.1
@property(assign) NSUInteger concurrency; // default 20
+ (instancetype)concurrencyCall;
- (void)callWithValue:(nullable Type)value;
- (void)cancel;
@end
NS_ASSUME_NONNULL_END
