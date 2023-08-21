//
//  ZMCheckButton.h
//  SaasBeePTUIModule
//
//  Created by groot.ding on 2018/4/13.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <ZoomKit/ZMALButton.h>

@interface ZMCheckButtonCell : ZMALButtonCell
@property (assign) CGFloat checkImageRadius;
@property (nonatomic) BOOL isHighlightMode;
@end

@interface ZMCheckButton : ZMALButton
- (void)sizeToFitWithLimitedWidth:(CGFloat)width;
@property (nonatomic,copy) BOOL (^interceptKeyDownBlock)(NSEvent *);
- (void)cleanUp;
@end
