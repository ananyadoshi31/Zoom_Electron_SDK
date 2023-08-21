//
//  ZMControls.h
//  ZCommonUI
//
//  Created by likevin on 12/12/17.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ZMButton;

@interface ZMMenuBtn : NSButton{
    NSUInteger  _radius;
    CGFloat     _borderWidth;
    NSColor*    _normalBorderColor;
    NSColor*    _focusBorderColor;
    NSString*   _titleString;
}
@property(nonatomic, readwrite, assign) NSUInteger  radius;
@property(nonatomic, readwrite, assign) CGFloat     borderWidth;
@property(nonatomic, readwrite, retain) NSColor*    normalBorderColor;
@property(nonatomic, readwrite, retain) NSColor*    focusBorderColor;
@property(nonatomic, readwrite, copy)   NSString*   titleString;

- (void)cleanUp;
@end

@interface ZMNoFocusRingScrollView : NSScrollView

@end

@class ZMTableViewMenuView;
@protocol ZMTableViewMenuViewDelegate <NSObject>
@optional
- (void)tableViewMenuView:(ZMTableViewMenuView *)menuView selectItemTitle:(NSString *)title;

@end
@interface ZMTableViewMenuView : NSView<NSTableViewDelegate, NSTableViewDataSource>{
    NSUInteger                      _radius;
    ZMNoFocusRingScrollView*        _scrollView;
    NSTableView*                    _tableView;
    NSMutableArray*                 _dataArray;
    NSTrackingArea*                 _area;
}
- (void)cleanUp;
- (void)updateDataArray:(NSArray*)array;
- (void)updateUI;
- (void)tryToScroll:(NSString*)tmpString;
- (NSString*)selectedItemString;
- (void)selectDownOne;
- (void)selectUpOne;
@property (nonatomic, weak) id<ZMTableViewMenuViewDelegate> delegate;
@property (nonatomic, assign) CGFloat leftPadding;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, assign) CGFloat rowHeight;
@property (nonatomic, retain) NSColor *borderColor;
@property (nonatomic, retain) NSColor *bgColor;
@property (nonatomic, retain) NSColor *selectionColor;
@property (nonatomic, assign) BOOL showDark;
@end

@interface ZMTableViewMenu : NSWindow{
    ZMTableViewMenuView*    _menuView;
}
- (void)cleanUp;
- (ZMTableViewMenuView*)menuView;
@end



@interface ZMAlertView : NSView{
    ZMButton* _confirmBtn;
    NSButton* _cancelBtn;
}
- (id)initWithFrame:(NSRect)frameRect WithTitle:(NSString*)title andDescription:(NSAttributedString*)description andBtn1Title:(NSString*)btn1Title andBtn2Title:(NSString*)btn2Title;
@end

@interface ZMAlertWindow : NSWindow{
    ZMAlertView* _alertView;
}
@property(nonatomic, readwrite, assign) id privateDelegate;
- (id)initContentFrame:(NSRect)contentRect WithTitle:(NSString*)title andDescription:(NSAttributedString*)description andBtn1Title:(NSString*)btn1Title andBtn2Title:(NSString*)btn2Title;
- (void)cleanUp;
@end
