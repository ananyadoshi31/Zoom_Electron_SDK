//
//  ZMTooltipMgr.h
//  SaasBeeConfUIModule
//
//  Created by John on 15/11/19.
//  Copyright (c) 2015年 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMTooltipMgr : NSObject
{
    NSPanel*  _toolTipPanel;
    NSRect    _effectRect;
}
@property (nonatomic,retain) NSView *positioningView;

+ (ZMTooltipMgr*)sharedMgr;
- (void)showTooltipWithString:(NSString*)inString location:(NSPoint)inPoint;
- (void)showTooltipWithString:(NSString*)inString location:(NSPoint)inPoint effectRect:(NSRect)rect inWindow:(NSWindow*)window;
- (void)showTooltipWithString:(NSString*)inString location:(NSPoint)inPoint ofView:(NSView *)positioningView relativeRect:(NSRect)relativeRect;
- (void)closeTooltip;
- (BOOL)isTooltipShowing;
- (BOOL)isTooltipShowingWith:(NSString*)inToolTip;

@end
