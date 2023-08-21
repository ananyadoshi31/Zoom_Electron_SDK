//
//  NSWindow+ZmmtKit.h
//  VideoUI
//
//  Created by Francis Zhuo on 11/28/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSWindow (ZmmtKit)
- (void)zm_windowStartLiveResize;
- (void)zm_windowEndLiveResize;
@end

NS_ASSUME_NONNULL_END
