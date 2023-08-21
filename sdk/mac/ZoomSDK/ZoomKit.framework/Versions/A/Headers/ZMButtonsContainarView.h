//
//  ZMButtonsContainarView.h
//  ZCommonUI
//
//  Created by Huxley on 2019/5/20.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMMessageItemInfo;

@interface ZMButtonsContainarView : NSView
{
    NSUInteger _lineNumber;
}
@property IBInspectable CGFloat spacing;
@end

@interface ZMReactionContainarView : NSView
{
    NSUInteger _maxLineNum; //start from 0
}
@property IBInspectable CGFloat spacing;
@property(nonatomic, retain) NSView* anchorView;
@property(nonatomic, retain) NSView* tailView;
@property(nonatomic, assign) NSSize  expSize;
@end

@interface ZMReminderContainerView : NSView
{
    NSUInteger _maxLineNum; //start from 0
}
@property IBInspectable CGFloat spacing;
@property (nonatomic, retain) NSView *anchorView;
@property (nonatomic, retain) NSView *tailView;
@property (nonatomic, assign) NSSize  expSize;
- (void)updateWithMessageInfo:(ZMMessageItemInfo * _Nullable)info;
@end
