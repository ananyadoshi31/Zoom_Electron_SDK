//
//  IZMShareMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMShareMgr_h
#define IZMShareMgr_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMShareMgr <ZMRoutableObject>
- (BOOL)isMainConfWindowNotVisibleWhileSharing;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMShareMgr_h */
