//
//  ZMEventLogHelper.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMEventLogHelper : NSObject

+ (void)eventLogWithType:(int)inClientType location:(int)inLoc event:(int)inEvent subEvent:(int)inSubEvent param:(nullable NSDictionary*)inParam;

@end

NS_ASSUME_NONNULL_END
