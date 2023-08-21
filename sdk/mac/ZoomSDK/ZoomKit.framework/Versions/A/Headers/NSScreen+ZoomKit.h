//
//  NSScreen+ZMConvenience.h
//  checkMainMenu
//
//  Created by francis zhuo on 24/11/2017.
//  Copyright © 2017 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@interface NSScreen(ZoomKit)

@property (readonly) NSEdgeInsets safeAreaInsets API_AVAILABLE(macos(12.0));
- (NSPoint)frameCenter;
- (BOOL)hasCameraNotch;
@end

@interface NSScreen (MenuBar)
- (BOOL)isMenuBarVisible:(CGFloat*)menuHeight;
@end
