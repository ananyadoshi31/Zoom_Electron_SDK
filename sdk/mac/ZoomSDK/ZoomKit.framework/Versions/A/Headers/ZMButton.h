//
//  ZMButton.h
//  ZCommonUI
//
//  Created by John on 6/27/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <ZoomKit/ZPTrackingButton.h>
#import <ZoomKit/NSBezierPath+ZoomKit.h>

enum _zoomButtonStyle
{
    Button_Type_Rect,
    Button_Type_RoundRect,
    Button_Type_CircleRect,
    Button_Type_RoundRect_Right,
    Button_Type_RoundRect_Left,
    Button_Type_RoundRect_BottomLeft,
    Button_Type_RoundRect_BottomRight,
    Button_Type_RoundRect_Bottom,
};

typedef NS_ENUM(NSUInteger, ZMButtonColorStyle) {
    ZMButtonColorStylePrimary,
    ZMButtonColorStyleSecondary,
    ZMButtonColorStyleTertiary,// for meeting
    ZMButtonColorStyleDestructive,
    ZMButtonColorStyleText,
};

enum _zoomButtonTriangleDirection
{
    Button_Trangle_Left,
    Button_Trangle_Right,
    Button_Trangle_Up,
    Button_Trangle_Down,
};

#define TAG_BADGE 123
typedef NS_ENUM(NSInteger,ZMBadgeCorner)
{
    Badge_Corner_LeftTop    = 0,
    Badge_Corner_Left       = 1,
    Badge_Corner_LeftBottom = 2,
    Badge_Corner_MidTop     = 1<<2,
    Badge_Corner_Mid        = (1<<2)|1,
    Badge_Corner_MidBottom  = (1<<2)|2,
    Badge_Corner_RightTop   = 2<<2,
    Badge_Corner_Right      = (2<<2)|1,
    Badge_Corner_RightBottom= (2<<2)|2,
    
    Badge_Corner_TopLeft = Badge_Corner_LeftTop,
    Badge_Corner_Top = Badge_Corner_MidTop,
    Badge_Corner_TopRight = Badge_Corner_RightTop,
    Badge_Corner_BottomLeft = Badge_Corner_LeftBottom,
    Badge_Corner_Bottom = Badge_Corner_MidBottom,
    Badge_Corner_BottomRight = Badge_Corner_RightBottom,
    Badge_Corner_MidLeft = Badge_Corner_Left,
    Badge_Corner_MidRight = Badge_Corner_Right
};

typedef NS_OPTIONS(NSUInteger, ZMButtonStatus) {
    ZMButtonNormalStatus = 1 << 0,
    ZMButtonHoverStatus = 1 << 1,
    ZMButtonPressStatus = 1 << 2,
    ZMButtonSelectStatus = 1 << 3,
    ZMButtonDisableStatus = 1 << 4,
    
    ZMButtonAllStatus = (1 << 5) - 1,
};
@interface ZMTruncateButton: NSButton

@end

@interface ZMCloseButton   : ZPTrackingButton
{
    CGFloat  _btnWidth;
    CGFloat  _btnMargin;
}
@property(nonatomic, assign, readwrite)CGFloat btnWidth;
@property(nonatomic, assign, readwrite)CGFloat btnMargin;
@end

typedef void(^ZMBackgroundDrawer)(NSRect bounds);

@interface ZMButton : ZPTrackingButton
{
    NSImage* _normalImage;
    NSImage* _hoverImage;
    NSImage* _pressImage;
    NSImage* _selectImage;
    NSImage* _disableImage;
    
    ZMBackgroundDrawer _backgroundDrawer;
    ZMBackgroundDrawer _normalBackgroundDrawer;
    ZMBackgroundDrawer _hoverBackgroundDrawer;
    ZMBackgroundDrawer _pressBackgroundDrawer;
    ZMBackgroundDrawer _selectBackgroundDrawer;
    ZMBackgroundDrawer _disableBackgroundDrawer;
    
    NSImage* _backgroundImage;
    NSImage* _normalBackgroundImage;
    NSImage* _hoverBackgroundImage;
    NSImage* _pressBackgroundImage;
    NSImage* _selectBackgroundImage;
    NSImage* _disableBackgroundImage;
    
    NSColor* _backgroundColor;
    NSColor* _normalBackgroundColor;
    NSColor* _hoverBackgroundColor;
    NSColor* _pressBackgroundColor;
    NSColor* _selectBackgroundColor;
    NSColor* _disableBackgroundColor;
    
    NSColor* _titleColor;
    NSColor* _normalTitleColor;
    NSColor* _hoverTitleColor;
    NSColor* _pressTitleColor;
    NSColor* _selectTitleColor;
    NSColor* _disableTitleColor;
    
    NSColor* _borderColor;
    NSColor* _normalBorderColor;
    NSColor* _hoverBorderColor;
    NSColor* _pressBorderColor;
    NSColor* _selectBorderColor;
    NSColor* _disableBorderColor;
    
    BOOL     _floatCenter;
    float    _topMargin;
    float    _bottomMargin;
    float    _leftMargin;
    float    _rightMargin;
    float    _centerMargin;
    
    //is useful for image and title only
    float    _horizontalAdjust;
    float    _verticalAdjust;
    BOOL     _drawImageOrigalSize;
    
    float   _topBackgroundImageCap;
    float   _bottomBackgroundImageCap;
    float   _leftBackgroundImageCap;
    float   _rightBackgroundImageCap;
    
    int      _buttonStyle;
    int      _textAlignment;
    int      _radius;
    float    _borderWidth;
    NSUnderlineStyle    _textUnderLineStyle;
    NSColor*            _textUnderLineColor;
    
    BOOL     _isSelected;
    
    CGSize _fixedSize;
    CGFloat _fixedHeight;
}
@property(nonatomic, retain) NSImage* normalImage;
@property(nonatomic, retain) NSImage* hoverImage;
@property(nonatomic, retain) NSImage* pressImage;
@property(nonatomic, retain) NSImage* selectImage;
@property(nonatomic, retain) NSImage* disableImage;

@property(copy) ZMBackgroundDrawer backgroundDrawer;
@property(copy) ZMBackgroundDrawer normalBackgroundDrawer;
@property(copy) ZMBackgroundDrawer hoverBackgroundDrawer;
@property(copy) ZMBackgroundDrawer pressBackgroundDrawer;
@property(copy) ZMBackgroundDrawer selectBackgroundDrawer;
@property(copy) ZMBackgroundDrawer disableBackgroundDrawer;

@property(nonatomic, retain) NSImage* backgroundImage;
@property(nonatomic, retain) NSImage* normalBackgroundImage;
@property(nonatomic, retain) NSImage* hoverBackgroundImage;
@property(nonatomic, retain) NSImage* pressBackgroundImage;
@property(nonatomic, retain) NSImage* selectBackgroundImage;
@property(nonatomic, retain) NSImage* disableBackgroundImage;

@property(nonatomic, retain) IBInspectable NSColor* backgroundColor;
@property(nonatomic, retain) IBInspectable NSColor* normalBackgroundColor;
@property(nonatomic, retain) IBInspectable NSColor* hoverBackgroundColor;
@property(nonatomic, retain) IBInspectable NSColor* pressBackgoundColor;
@property(nonatomic, retain) IBInspectable NSColor* selectBackgroundColor;
@property(nonatomic, retain) IBInspectable NSColor* disableBackgroundColor;

@property(nonatomic, retain) IBInspectable NSColor* titleColor;
@property(nonatomic, retain) IBInspectable NSColor* normalTitleColor;
@property(nonatomic, retain) IBInspectable NSColor* hoverTitleColor;
@property(nonatomic, retain) IBInspectable NSColor* pressTitleColor;
@property(nonatomic, retain) IBInspectable NSColor* selectTitleColor;
@property(nonatomic, retain) IBInspectable NSColor* disableTitleColor;

@property(nonatomic, retain) IBInspectable NSColor* borderColor;
@property(nonatomic, retain) IBInspectable NSColor* normalBorderColor;
@property(nonatomic, retain) IBInspectable NSColor* hoverBorderColor;
@property(nonatomic, retain) IBInspectable NSColor* pressBorderColor;
@property(nonatomic, retain) IBInspectable NSColor* selectBorderColor;
@property(nonatomic, retain) IBInspectable NSColor* disableBorderColor;

@property(nonatomic, assign) IBInspectable BOOL     floatCenter;
@property(nonatomic, assign) IBInspectable float    topMargin;
@property(nonatomic, assign) IBInspectable float    bottomMargin;
@property(nonatomic, assign) IBInspectable float    leftMargin;
@property(nonatomic, assign) IBInspectable float    rightMargin;
@property(nonatomic, assign) IBInspectable float    centerMargin;
@property(nonatomic, assign) IBInspectable float    horizontalAdjust;
@property(nonatomic, assign) IBInspectable float    verticalAdjust;
@property(nonatomic, assign) IBInspectable BOOL     drawImageOrigalSize;
@property(nonatomic, assign) IBInspectable float    maxTextHeight;

@property(nonatomic, assign) IBInspectable float    topBackgroundImageCap;
@property(nonatomic, assign) IBInspectable float    bottomBackgroundImageCap;
@property(nonatomic, assign) IBInspectable float    leftBackgroundImageCap;
@property(nonatomic, assign) IBInspectable float    rightBackgroundImageCap;

@property(nonatomic, assign) IBInspectable int      buttonStyle;
@property(nonatomic, assign) IBInspectable ZMButtonColorStyle colorStyle;
@property(nonatomic, assign) IBInspectable int      textAlignment;
@property(nonatomic, assign) IBInspectable int      radius;
@property(nonatomic, assign) IBInspectable float    borderWidth;
@property NSLineBreakMode lineBreakMode API_AVAILABLE(macos(10.9));
@property(nonatomic, assign) ZMButtonStatus textUnderLineShowMask;
@property(nonatomic, assign) NSUnderlineStyle textUnderLineStyle;
@property(nonatomic, retain) IBInspectable NSColor*   textUnderLineColor;
@property(nonatomic, getter=isSelected, assign) BOOL selected;
@property (nonatomic) IBInspectable BOOL ignoreFirstMouse;
@property (nonatomic) IBInspectable BOOL alwaysFirstMouse;
@property (nonatomic) NSRectCorner roundedCorners;
@property (nonatomic) IBInspectable BOOL matchImageColorWithTitle;
@property (nonatomic) BOOL useQuarterRadius;

@property (nonatomic,copy) NSAttributedString *zmAttributedTitle;

@property (nonatomic,retain) NSMutableAttributedString *zmDisplayAttributeTitle;

@property (nonatomic,assign) SEL firstResponseChanged;

- (instancetype)initWithColorStyle:(ZMButtonColorStyle)colorStyle;
+ (instancetype)buttonWithColorStyle:(ZMButtonColorStyle)colorStyle;

- (void)drawBackground;
- (void)drawRectWithImageOnly;
- (void)drawRectWithTitleOnly;
- (void)drawRectWithImageAbove;
- (void)drawRectWithImageLeft;
- (void)drawRectWithImageRight;

- (NSBezierPath*)getBezierPath;
- (NSImage*)getDisplayImage;
- (void)getDisplayImageWidth:(float*)outWidth height:(float*)outHeight;
- (NSColor*)getDisplayTitleColor;
- (NSImage*)getDisplayBgImage;
- (NSColor*)getDisplayBgColor;
- (NSColor*)getDisplayBorderColor;
- (NSAttributedString *)getDispalyAttributeTitle;
- (NSInteger)getTitleStringWidth;
- (NSInteger)getTitleStringHeight;
- (NSInteger)getFitWidth;

- (void)showBadgeWithString:(NSString*)string shouldLighten:(BOOL)inLighten;
- (void)showBadgeWithNumber:(NSInteger)inNumber shouldLighten:(BOOL)inLighten;

- (void)showBadgeWithImage:(NSImage*)image corner:(int)corner offsetX:(float)offsetX offsetY:(float) offsetY;
- (void)showBadgeWithImage:(NSImage*)badgeImage corner:(int)corner offsetX:(float)offsetX offsetY:(float) offsetY shouldBadgeRefusesFouce:(BOOL)shouldBadgeRefusesFouce;
- (void)showBadgeWithAttributeString:(NSAttributedString*)attributeString bgColor:(NSColor*)bgColor borderColor:(NSColor*)borderColor borderWidth:(float)borderWidth corner:(ZMBadgeCorner)corner offsetX:(float)offsetX offsetY:(float) offsetY;
- (void)showBadgeWithString:(NSString*)string bgColor:(NSColor*)bgColor borderColor:(NSColor*)borderColor borderWidth:(float)borderWidth corner :(ZMBadgeCorner)corner offsetX:(float)offsetX offsetY:(float) offsetY;

- (void)hideBadge;

- (CGFloat)widthToFit;
- (CGFloat)widthToFitWithMinWidth:(float)minWidth maxWidth:(float)maxWidth;
- (CGFloat)heightToFit;

- (void)setFixedSize:(CGSize)fixedSize;
- (void)setFixedHeight:(CGFloat)fixedHeight;
@end

@interface ZMPopupMenuButton : ZMButton
{
    int _triangleDirection;
}
@property(nonatomic, assign) int triangleDirection;
@end

//can be used by others
typedef enum {
    ZMBOLeftIconNone = 0,
    ZMBOLeftIconNormalImage,
    ZMBOLeftIconRightDownTriangle,
    ZMBOLeftIconCross, // X
    ZMBOLeftIconMoveTo,
    ZMBOLeftIconExchange,
    ZMBOLeftIconCircle,
    ZMBOLeftIconCircleGreen,
    ZMBOLeftIconCircleGray,
    ZMBOLeftIconUptick,
    ZMBOLeftIconLeftTick,// > & down arrow
    ZMBOLeftIconCheckBox,
    ZMBOLeftIconChecktick,
    ZMLeftIconPlus,// +
    ZMLeftIconMinus,// -
    ZMLeftIconPen,//ZOOM-1560
    ZMLeftIconOut,//ZOOM-5960
    ZMLeftIconRoundRect,//ZOOM-5960
    ZMLeftIconWallViewTriangleRight,// ▹
    ZMLeftIconWallViewTriangleLeft,// ◃
} ZMBOLeftIconType;

@interface ZMBOLeftIconButton : ZMButton
{
    BOOL        _isTitleToRight;//right title
    BOOL        _isFlippedToRight;//right image
    BOOL        _isCenteral;//if the width is too big , centeral the icon and string;//ZOOM-5960
    float       _iconLeftMargin;
    float       _iconWidth;
    float       _iconRightMargin;
    float       _titleRightMargin;
    int         _iconType;
    BOOL        _isDown;
    NSColor*    _iconColor;
    NSColor*    _disableIconColor;
    NSColor*    _pressIconColor;
    NSColor*    _hoverIconColor;//ZOOM_5960
    NSString*   _zmAccessibilityTitle;//ZOOM-43259
    NSString*   _hoverTitle;
}
@property (nonatomic, readwrite, retain)NSString*   hoverTitle; //ZOOM-43259
@property (nonatomic, readwrite, retain)NSString*   zmAccessibilityTitle; //ZOOM-43259
@property (nonatomic, readwrite, assign)BOOL        isCenteral;
@property (nonatomic, readwrite, assign)BOOL        isFlippedToRight;
@property (nonatomic, readwrite, assign)float       iconLeftMargin;
@property (nonatomic, readwrite, assign)float       iconWidth;
@property (nonatomic, readwrite, assign)float       iconRightMargin;
@property (nonatomic, readwrite, assign)float       titleRightMargin;//if NSImageAbove ,is the buttom Margin
@property (nonatomic, readwrite, assign)int         iconType;
@property (nonatomic, readwrite, assign)BOOL        isDown;
@property (nonatomic, readwrite, assign)BOOL        isTitleToRight;
@property (nonatomic, readwrite, retain)NSColor*    iconColor;
@property (nonatomic, readwrite, retain)NSColor*    disableIconColor;
@property (nonatomic, readwrite, retain)NSColor*    pressIconColor;
@property (nonatomic, readwrite, retain)NSColor*    hoverIconColor;//ZOOM_5960
- (NSPoint)getTipPointToScreen;
- (NSPoint)getLeftBottomPointToScreen;
- (float)preferedWidth;
@end

@interface ZMIconButton : ZMButton
@end


@interface ZMMouseDownCanMoveWindowButton : ZMButton
{
    NSPoint     _mouseDownLocation;
    NSPoint     _mouseDownWindowLocation;
    NSPoint     _currentMouseLocation;
    BOOL        _isMouseDragged;
}
@end

@interface ZPTrackingButton (ZMAccessibility)
@property(copy)NSString* (^accessibilityDescriptionBlock)(__kindof ZPTrackingButton* mySelf);
@property(copy)NSString* (^accessibilityRoleDescriptionBlock)(__kindof ZPTrackingButton* mySelf);
@end

@interface ZMSampleButton : ZMButton
{
    NSColor *_enterKeyColor;
}

@property (copy) IBInspectable NSColor *enterKeyColor;

@end

