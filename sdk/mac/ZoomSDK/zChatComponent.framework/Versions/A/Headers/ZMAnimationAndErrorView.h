//
//  ZMAnimationAndErrorView.h
//  ZCommonUI
//
//  Created by groot.ding on 27/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAnimationAndErrorView : NSView

@property (nonatomic, assign, getter=isShowErrImage)  BOOL showErrImage;
@property (nonatomic, assign, getter=isShowAnimation) BOOL showAnimation;
@property (nonatomic, assign, getter=isShowCornerRadius) BOOL showCornerRadius;

@end

NS_ASSUME_NONNULL_END
