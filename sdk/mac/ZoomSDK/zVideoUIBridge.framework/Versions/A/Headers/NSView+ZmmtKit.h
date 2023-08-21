//
//  NSView+zmmtKit.h
//  zVideoUI
//
//  Created by francis zhuo on 5/23/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (ZmmtKit)

@property(nullable, retain) id mtObject;

- (void)zm_viewWillStartLiveResize;
- (void)zm_viewDidEndLiveResize;

- (NSArray<id<NSAccessibilityElement>> *)zm_accessibilityChildrenInNavigationOrder NS_AVAILABLE_MAC(10_13);

- (void)setMinSizeConstraint:(NSSize)minSize;
@end

NS_ASSUME_NONNULL_END
