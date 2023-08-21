//
//  ZMStackView.h
//  zChatUI
//
//  Created by Huxley on 2018/4/25.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Zoomkit/ZMBaseKit.h>
#import <Zoomkit/ZMAccessibleView.h>

@interface NSView (ZMStackViewSubView)

@property (readonly) BOOL stackViewEscape;

@end

@interface ZMStackView : ZMAccessibleView

@property IBInspectable ZMUserInterfaceOrientation orientation;

@property IBInspectable CGFloat spacing;
@property IBInspectable NSLayoutAttribute alignment;
@property IBInspectable NSEdgeInsets edgeInsets;

@property IBInspectable BOOL isRespondedArrowKey;
@property IBInspectable BOOL isKeyboardAccessGroup;

/**
 * the property is only effect when alignment == kZMUserInterfaceOrientationHorizontal
 * default value is ZMLayoutDirectionLeftToRight
 */
@property IBInspectable ZMLayoutDirection layoutDirection;

- (void)relayoutUsingFrameCalculation;
- (void)relayoutUsingLayoutConstrains;
/** This method is useless if(self.orientation != kZMUserInterfaceOrientationVertical) */
- (void)relayoutWithFixedWidth:(float)fixedWidth;

- (void)removeAllSubviewsAndConstraints;
@end
