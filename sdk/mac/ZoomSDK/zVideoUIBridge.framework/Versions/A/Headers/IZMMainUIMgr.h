//
//  IZMMainUIMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/8/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMainUIMgr_h
#define IZMMainUIMgr_h

@protocol IZMMainUIMgr <ZMRoutableObject>
- (__kindof NSWindow *)confWindow;
- (NSRect)getWindowRect;
- (NSScreen *)getWindowScreen;
- (NSRect)getMainViewRectInScreen;
- (void)relayoutUI;
- (void)preferWallViewMode:(BOOL)isWallView;
@end

#endif /* IZMMainUIMgr_h */
