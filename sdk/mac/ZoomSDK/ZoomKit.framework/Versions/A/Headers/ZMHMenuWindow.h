//
//  ZMHMenuWindow.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/24.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <ZoomKit/ZMBase.h>

@class ZMHMenu, ZMBaseMenuItem, ZMHMenuListView;
@interface ZMHMenuWindow : NSPanel <NSTextFieldDelegate>
{
    BOOL _loaded;
    __weak ZMHMenu *_menu;
}

@property (weak, nonatomic) ZMHMenuWindow *subMenuWindow;
@property (retain) ZMHMenuListView *menuListView;
@property (retain, readonly) ZMBaseMenuItem * representedItem;
@property NSRectCorner preferredAnchorConner;
@property (nonatomic, assign) int cornerRadius;
@property (assign) NSSize maxListSize;
@property (assign) BOOL hasSearchField;
@property (assign) BOOL assignKeyWindow;

@property (assign, readonly) NSSize fittingContentSize;

- (void)constructWithMenu:(ZMHMenu *)menu representedItem:(id)item;
- (void)constructWithMenu:(ZMHMenu *)menu representedItem:(id)item maxSize:(NSSize)maxSize;

- (BOOL)isDescendantOf:(ZMHMenuWindow *)window;

- (void)show;
- (void)showInScreen:(NSScreen *)screen;
- (void)showAsChildOf:(NSWindow*)window;
- (void)close;

- (BOOL)mouseOnSelfOrDescendantWindows;

- (void)performShowSubWindowWithItem:(ZMBaseMenuItem *)menuItem;

- (void)reloadMenuData;

- (ZMBaseMenuItem *)getSelectedItem;

@end

@interface ZMHMenuSubWindow : ZMHMenuWindow

@end
