//
//  ZMSharePaddingMgr.h
//  ZCommonUI
//
//  Created by walt.li on 8/14/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMSharePaddingMgr : NSObject

- (void)cleanUp;
- (void)screenResolutionDidChanged;
- (void)showPaddingWindow:(CGDirectDisplayID)displayId;
- (void)closePaddingWindow;
- (void)showNumberWindowForSelectWindow;
- (void)showNumberWindowForTipWindowWithDisplayId:(CGDirectDisplayID)displayId;
- (void)closeNumberWindowForSelectWindow;
- (void)closeNumberWindowForTipWindow;
@end
