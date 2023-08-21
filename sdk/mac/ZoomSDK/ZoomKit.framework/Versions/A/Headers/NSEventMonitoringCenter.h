//
//  NSEventMonitoringCenter.h
//  ZCommonUI
//
//  Created by Huxley on 2018/9/25.
//  Copyright © 2018年 zoom. All rights reserved.
//

#import <ZoomKit/ZMBaseKit.h>

typedef NSEvent *(^NSEventMonitoring)(NSEvent *event);

@interface NSEventMonitoringCenter : NSObject

/// is option key down
+ (BOOL)isOptionModifierDown;

/// Monitoring modifier flags changed. such as option, cmd, ctrl etc. You need to retain and release the return value yourself.
+ (NSString *)addMonitorForModifiersChanged:(NSEventMonitoring)monitoring;
+ (void)removeMonitorForModifiers:(NSString *)monitorIdentifier;

/// Monitoring mouse down/up:  NSLeftMouseDownMask |NSRightMouseDownMask | NSLeftMouseUpMask | NSOtherMouseDownMask
+ (NSString *)addMonitor:(NSEventMonitoring)monitoring;
+ (void)removeMonitor:(NSString *)monitorIdentifier;

@end
