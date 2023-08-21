//
//  ZMMTBaseViewController.h
//  zVideoUI
//
//  Created by Francis Zhuo on 2020/8/9.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseView.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMMTViewControllerType : ZMMTViewType
@end

@interface ZMMTBaseViewController : ZMBaseViewController
@property(assign)ZMMTType  viewControllerType;
@property(retain)ZMMTBaseView* view;

@property(readonly, assign) BOOL isViewShowing;
- (void)showView NS_REQUIRES_SUPER;
- (void)hideView;

@end

NS_ASSUME_NONNULL_END
