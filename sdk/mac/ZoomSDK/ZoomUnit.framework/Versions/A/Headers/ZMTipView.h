//
//  ZMTipView.h
//  ZCommonUI
//
//  Created by John on 10/26/15.
//  Copyright (c) 2015 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTipView : NSControl
{
}
- (id)initWithString:(NSString*)inString attributes:(NSDictionary *)inAttribute constrainRect:(NSRect)inRect;
- (void)cleanUp;

- (void)setTipString:(NSString*)inString;
- (void)setShowCloseButton:(BOOL)inbShow;
- (void)updateUI;
@end

//ZOOM-38370{
@interface ZMAccessibilityTipView : ZMTipView <NSAccessibilityStaticText>
{
}
@end
//ZOOM-38370}

//add by francis,for ZOOM-11169
@interface ZMDialogTipView : NSControl
{
    NSTextField*    _tipLabel;
    NSTextView*     _tipContent;
    NSMutableArray* _buttonArray;
    
    BOOL            _autoResizeButton;
    float           _tipMinWidth;
    
    id              _repObject;
}
@property(assign)BOOL   autoResizeButton;
@property(assign)float  tipMinWidth;
@property(retain)id     representedObject;
- (void)cleanUp;
- (void)setAttributeLabel:(NSAttributedString*)attrLabel;
- (void)setAttributeContent:(NSAttributedString*)attrContent;
- (void)addButton:(NSButton*)button;
- (void)addButton:(NSButton*)button atIndex:(NSUInteger)index;
- (void)hideButton:(BOOL)hide Tag:(NSInteger)tag;
- (void)removeAllButton;
- (void)updateUI;
@end
