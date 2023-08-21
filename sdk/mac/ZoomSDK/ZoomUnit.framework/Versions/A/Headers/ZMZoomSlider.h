//
//  ZMZoomSlider.h
//  MessageListDemo
//
//  Created by groot.ding on 3/9/20.
//  Copyright © 2020 groot.ding. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMZoomSlider : NSControl

@property (nonatomic,assign) float minValue;
@property (nonatomic,assign) float maxValue;

@property (nonatomic,assign) float value;

@property (nonatomic,assign) BOOL needShowTipPopover;

@property (nonatomic,weak,nullable) id zmTarget;

@property (nonatomic,assign,nullable) SEL zmAction;

@end

NS_ASSUME_NONNULL_END
