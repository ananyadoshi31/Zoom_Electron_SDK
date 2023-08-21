//
//  NSUserDefaults+ZMConvenience.h
//  ZMHotkeyKit
//
//  Created by francis zhuo on 09/01/2018.
//  Copyright © 2018 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSUserDefaults (ZMHotkey)
+ (NSUserDefaults*)hotkeyUserDefaults;
@end

@interface NSUserDefaultsController (ZMHotkey)
+ (NSUserDefaultsController*)hotkeyUserDefaultsController;
@end
