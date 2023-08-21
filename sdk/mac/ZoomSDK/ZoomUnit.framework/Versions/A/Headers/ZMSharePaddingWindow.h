//
//  ZMSharePaddingWindow.h
//  ZCommonUI
//
//  Created by walt.li on 8/14/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSharePaddingView : NSView   //ZOOM-38254
@end

@interface ZMShareNumberView : NSView    //ZOOM-38254
@property(retain, nonatomic, nullable) NSString * number;
@property(nonatomic, retain, nullable) NSTextField *textField;
@end

@interface ZMSharePaddingWindow : /*ZMInvisibleWindow*/NSPanel
- (void)invisibleInSharing;
@end

NS_ASSUME_NONNULL_END
