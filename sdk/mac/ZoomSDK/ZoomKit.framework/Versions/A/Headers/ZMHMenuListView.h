//
//  ZMHMenuListView.h
//  zChatUI
//
//  Created by Huxley on 2018/3/31.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMBaseMenuItem;
@protocol ZMHMenuListViewDelegate;
@interface ZMHMenuListView : NSView
{
    NSTrackingArea *_trackingArea;
    BOOL _mouseInside;
}

@property (retain, readonly) NSTableView *tableView;

@property (weak) id <ZMHMenuListViewDelegate> mouseEventDelegate;
@property (retain, nonatomic) NSArray <ZMBaseMenuItem *> *menuItemList;
@property (readonly) BOOL mouseInside;
@property (nonatomic) NSEdgeInsets paddings;

@property (readonly) ZMBaseMenuItem *selectedItem;

- (instancetype)initWithMaxListSize:(NSSize)size;
- (void)searchByKey:(NSString*)key;

@end

@protocol ZMHMenuListViewDelegate <NSObject>

- (void)listViewSelectionDidChange:(ZMHMenuListView *)listView hovered:(BOOL)hovered;

- (BOOL)shouldListViewDeselectCurrentItem:(ZMHMenuListView *)listView;
- (void)mouseExistListView:(ZMHMenuListView *)listView;

@end
