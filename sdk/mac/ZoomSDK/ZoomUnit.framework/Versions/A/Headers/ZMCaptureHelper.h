//
//  ZMCaptureHelper.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/3/12.
//  Copyright © 2018年 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZMCaptureModel;
@interface ZMCaptureHelper : NSObject
+ (NSArray<ZMCaptureModel*>*)getScreenInfo;//do not contain the image
+ (NSArray<ZMCaptureModel*>*)getScreenShots;//contain the image
+ (NSArray<ZMCaptureModel*>*)getWindowInfo:(NSWindowNumberListOptions)options;//do not contain the image
+ (NSArray<ZMCaptureModel*>*)getWindowShots:(NSWindowNumberListOptions)options;//contain the image
+ (ZMCaptureModel*)getWindowInfo:(NSInteger)windowId contianImage:(BOOL)contain;
+ (NSRect)cgRect2NSRect:(CGRect)cgRect; //ZOOM-38254
+ (BOOL)isValidWindowID:(NSInteger)windowID;
+ (CGRect)getWindowBounds:(CGWindowID)windowID;
+ (NSRect)getWindowFrameFromWindowId:(CGWindowID)inWindowId;
+ (int)getProcessIDByWindowID:(CGWindowID)windowID;

+ (NSRect)getDisplayRectfromWindow:(CGWindowID)windowID;
+ (CGDirectDisplayID)getDisplayIdFromWindow:(CGWindowID)windowID;
@end
