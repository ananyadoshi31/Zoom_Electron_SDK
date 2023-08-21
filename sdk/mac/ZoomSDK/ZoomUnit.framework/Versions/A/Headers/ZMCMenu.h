//
//  ZMCMenu.h
//  zSIPCallUI
//
//  Created by lisa on 2017/12/27.
//  Copyright © 2017 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMenuTableView;

@interface ZMCMenuTableCellView : NSTableCellView

@property(nonatomic,getter=isSelected) BOOL selected;

@end

@interface ZMCMenuItem : NSObject
{
    NSString*   _title;
    NSImage*    _image;
    NSImage*    _stateImage;
    ZMCMenuTableCellView*     _customerView;
    NSInteger   _tags;
    SEL         _action;
    float       _textLeftpadding;
    float       _itemHeight;
    NSColor*    _itemHoverColor;
    NSColor*    _speraClolor;
    NSColor*    _textColor;
    NSFont*     _textFont;
    BOOL        _enable;
}

@property (nonatomic, retain)NSString *title;
@property (nonatomic, retain)NSImage *image;
@property (nonatomic, retain)NSImage *stateImage;
@property (nonatomic, retain)ZMCMenuTableCellView *customerView;
@property (nonatomic, retain)NSColor *itemHoverColor;
@property (nonatomic, retain)NSColor *speraClolor;
@property (nonatomic, retain)NSColor *textColor;
@property (nonatomic, retain)NSFont *textFont;
@property (nonatomic, assign)NSInteger tags;
@property (nonatomic, assign)float textLeftpadding;
@property (nonatomic, assign)float itemHeight;
@property (nonatomic, weak)id target;
@property (nonatomic, assign)SEL action;
@property (nonatomic, assign)BOOL enable;
@property (nullable, retain) id representedObject;

+ (ZMCMenuItem *)seperatorItem;
+ (ZMCMenuItem *)initWithSeperator:(float)height andColor:(NSColor *)speratorColor;
@end


@protocol ZMCMenuDelegate <NSObject>
- (void)menuItemDidClicked:(ZMCMenuItem *)item;
@end
@interface ZMCMenu : NSWindowController
{
    NSColor*           _menuColor;
    NSMutableArray*    _menuItems;
    NSInteger          _maxCount;
    float              _windowMaxWidth;
    float              _cornerRadius;
    float              _minimumWidth;
    BOOL               _isDark;
}

@property(nonatomic,assign)NSInteger         maxCount;
@property(nonatomic,assign)float             windowMaxWidth;
@property(nonatomic,retain)NSMutableArray*   menuItems;
@property(nonatomic,retain)NSColor*          menuColor;
@property(nonatomic,assign)float             cornerRadius;
@property(nonatomic,weak)id<ZMCMenuDelegate> menuDelegate;
@property(nonatomic,assign)BOOL isDark;
@property (nonatomic, assign)float minimumWidth;

@property (nonatomic, copy) NSString *theAccessibilityLabel;

- (void)cleanUp;
- (void)popupMenuForView:(NSView *)view;
- (void)popupMenuForView:(NSView *)view showItem:(ZMCMenuItem*)item;
- (void)insertItem:(ZMCMenuItem *)newItem atIndex:(NSInteger)index;
- (void)addItem:(ZMCMenuItem *)newItem;
- (void)removeItem:(ZMCMenuItem *)item;
- (void)removeItemAtIndex:(NSInteger)index;
- (void)setMenuItems:(NSMutableArray *)items;
- (NSInteger)selectedRow;
- (void)popMenuForPoint:(NSPoint)point;
@end

NS_ASSUME_NONNULL_END
