//
//  ZMPopUpButton.h
//  Test
//
//  Created by Huxley on 11/3/19.
//  Copyright © 2019 Huxley. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMHMenu;
@interface ZMHPopUpButtonCell : NSPopUpButtonCell

@property (retain) ZMHMenu *hMenu;
@property (nonatomic, retain) NSColor *borderColor;
@property (nonatomic, retain) NSColor *titleColor;
@property (nonatomic, copy) void(^drawIndicatorBlock)(NSRect frame, NSView *controlView);
@property IBInspectable CGFloat cornerRadius;

@end

@interface ZMPopUpButton : NSPopUpButton

@property (nonatomic, retain) NSColor *borderColor;
@property (nonatomic, assign) BOOL isMenuSharable;

@end

NS_ASSUME_NONNULL_END
