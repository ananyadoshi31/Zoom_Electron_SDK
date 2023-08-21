//
//  ZMBaseMenuItem.h
//  ZoomKit
//
//  Created by Ado Du on 2021/12/20.
//

#import <ZoomKit/ZMBaseViewController.h>
#import <ZoomKit/ZMMenuConfig.h>
#import <ZoomKit/ZMBaseView.h>

@class ZMHMenu, ZMStackView, ZMHLine, ZMGuideTipPopover;

NS_ASSUME_NONNULL_BEGIN

typedef BOOL(^ZMHMenuItemBackgroundDrawer)(NSRect bounds, NSRect dirtyRect, BOOL selected);
typedef void(^ZMHMenuItemHoverBlock)(ZMBaseMenuItem * ofItem);

@interface NSView (ZMHMenuItemSubview)

/// To override, called by rowview selection changed
- (void)enclosingMenuItemSelected:(BOOL)selected;

@end

@interface ZMBaseMenuItem : ZMBaseViewController

@property (copy, nonatomic, nullable) NSArray <__kindof ZMBaseMenuItem *> *subItems;
@property (weak, nonatomic) ZMHMenu *hmenu; //do not call the setter

@property (class, readonly) ZMBaseMenuItem *rootItem;
@property (class, readonly) ZMBaseMenuItem *separatedItem;
@property (nonatomic, retain, readonly) ZMHLine *separateLineView;

@property (nonatomic, retain) ZMMenuConfig *config;

@property (nonatomic, retain) NSFont *titleFont;
@property (nonatomic, retain) NSColor *titleColor;
@property (nonatomic, retain) NSColor *titleHighlightColor;
@property (nonatomic, retain) NSColor *subtitleColor;
@property (nonatomic, retain) NSColor *subtitleHighlightColor;
@property (nonatomic, retain) NSColor *selectBackgroundColor;
@property (nonatomic, retain) NSColor *highlightBackgroundColor;

@property (nonatomic, assign) NSEdgeInsets margin;
@property (nonatomic, assign) CGFloat indentationDistance;
@property (nonatomic, assign) CGFloat minWidth;

@property (nonatomic, copy, nullable) NSString *subtitleText;
@property (nonatomic, assign) BOOL isSubtitleMultiLineShow;// defaule NO
@property (nonatomic, copy, nullable) NSString *tailTitleText;
@property (nonatomic, retain, nullable) NSImage *image;
@property (nonatomic, retain, nullable) NSImage *alternateImage;
@property (nonatomic, retain) NSImage *tailImage;
/// If attributedTitle is set, title(from itemWithTitle:title) and titleColor will be ignored
@property (nonatomic, retain) NSAttributedString *attributedTitle;
@property (nonatomic, retain, nullable) NSView *tailView;
@property (nonatomic, assign) NSEdgeInsets tailViewInsets;

@property (nonatomic, assign) NSInteger tag;
@property (retain, nullable) id representedObject;
@property (nullable, weak) id target;
@property (nullable) SEL action;
@property (nullable) SEL hoverAction;
@property (nullable, copy) ZMHMenuItemHoverBlock hoverBlock;

@property (nonatomic, assign) BOOL needTailImage;
@property (readonly, nonatomic) BOOL isRoot;
@property (readonly, nonatomic) BOOL isSeparated;
@property (readonly, nonatomic) BOOL isCustomView;
@property (nonatomic, retain, readonly) NSView *customView;

@property (nonatomic, assign) BOOL canSelect; /**< can highlight */
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) BOOL eventFree;
@property (nonatomic, assign) BOOL defaultSelectedWithChecked;
@property (nonatomic, assign) BOOL noCloseMenuOnAction;
/// Default NO, will draw a light blue background. If Yes, will draw no background.
@property (nonatomic, assign) BOOL drawsNoBackground;
@property (nonatomic, assign) BOOL ignoreIsCustomView; //lisa.si's build break fix
@property (nonatomic, assign) BOOL shouldIndent;

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign, getter=isChecked) BOOL checked;
@property (nonatomic, assign) BOOL hovered;
@property (nullable, copy) ZMHMenuItemBackgroundDrawer backgroundDrawer;
@property (assign) BOOL draggable;
@property (assign) BOOL rounded;

@property (nonatomic, copy, nullable) NSString *toolTip;
@property (nonatomic, copy) NSString *accessibilityLabel;
@property (nonatomic, copy) NSString *accessibilityRoleLabel;

@property (nonatomic, retain, nullable) ZMGuideTipPopover *guideTipPopover;

+ (instancetype)itemWithTitle:(nullable NSString *)title informative:(nullable NSString *)informative image:(nullable NSImage *)image;

+ (instancetype)itemWithView:(NSView *)customView; //become customViewOnly with zero paddings
+ (instancetype)itemWithView:(NSView *)customView edgePaddings:(NSEdgeInsets)edgePaddings; //become customViewOnly

+ (instancetype)separatedItemWithColor:(nullable NSColor *)color;
+ (instancetype)separatedItemWithColor:(nullable NSColor *)color lineViewHeight:(CGFloat)lineViewHeight;
+ (instancetype)separatedItemWithColor:(nullable NSColor *)color lineViewHeight:(CGFloat)lineViewHeight lineHeight:(CGFloat)lineHeight;

//MARK: Utils
- (void)performAction;
- (void)performHoverAction;
- (void)performHoverBlock;

- (BOOL)locationInFrame:(NSPoint)location from:(NSView *)aView;

- (void)viewReceivedMouseUp;

- (void)updateCheckedStatus;

- (void)adjustToFixedWidth:(float)width;

@end

NS_ASSUME_NONNULL_END
