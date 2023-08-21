//
//  ZMIMOnlyImageButton.h
//  zChatUI
//
//  Created by ryan on 12/06/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMRichKeyButton.h>

@interface ZMIMBaseButton : ZMRichKeyButton

@property (assign) BOOL entered;
@property (assign) BOOL isHandleMouseEvent;
@property (copy) NSString* customTooltip;

@property (nonatomic,assign) NSSize zmIntrinsicContentSize;
@property(nonatomic, assign) SEL hoverAction;

@property (assign) BOOL opaqueWhenDisabled;

@property(nonatomic, assign) BOOL delaySendHoverAction;

@end

@interface ZMIMOnlyImageButton : ZMIMBaseButton

@property (assign) NSEdgeInsets edgeInsets;

@property (nonatomic,assign) float radius;

@property (nonatomic,assign) BOOL isChecked;

@property (nonatomic,retain) NSImage* hoverImage;
@property (nonatomic,retain) NSImage* disableImage;

@property (nonatomic, assign) BOOL matchImageColorWithTitle;

@property (nonatomic,copy) NSColor* backgroundColor;
@property (nonatomic,copy) NSColor* normalBackgroundColor;
@property (nonatomic,copy) NSColor* hoverBackgroundColor;
@property (nonatomic,copy) NSColor* highlightBackgroundColor;
@property (nonatomic,copy) NSColor* disabledBackgroundColor;
@property (nonatomic,copy) NSColor* borderColor;
@property (nonatomic,copy) NSColor* hoverBorderColor;
@property (nonatomic,copy) NSColor* pressBorderColor;
@property (nonatomic,copy) NSColor* disabledBorderColor;
@property (nonatomic,copy) NSString* zmAccessibilityLabel;
@property (nonatomic,copy) NSString* zmAccessibilityRoleDescription;
@property (nonatomic,assign) NSRect zmAccessibilityFrame;

@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, copy) NSColor* textColor;
@property (nonatomic, copy) NSColor* textHoverColor;
@property (nonatomic, copy) NSColor* textHighlightColor;
@property (nonatomic, copy) NSColor* textDisableColor;

@property (nonatomic,retain) NSImageView *imageView;

@property (retain, nullable) id representedObject;

- (NSSize)fitSize;

@end
