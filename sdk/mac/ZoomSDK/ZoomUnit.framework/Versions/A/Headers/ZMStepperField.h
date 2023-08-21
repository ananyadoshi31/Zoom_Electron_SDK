//
//  ZMStepperField.h
//  Test
//
//  Created by Huxley on 2019/10/11.
//  Copyright © 2019 Huxley. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMStepperFieldCell : NSTextFieldCell

- (NSRect)stepperRectForBounds:(NSRect)rect;

- (BOOL)isPointInUpStepper:(NSPoint)point;
- (BOOL)isPointInDownStepper:(NSPoint)point;

- (BOOL)mouseMoved:(NSPoint)point;

@end

@interface ZMStepperField : NSTextField

+ (instancetype)stepperWithmMinValue:(CGFloat)minValue maxValue:(CGFloat)maxValue;

@property (assign, nonatomic) IBInspectable NSInteger minValue;
@property (assign, nonatomic) IBInspectable NSInteger maxValue;

@end

NS_ASSUME_NONNULL_END
