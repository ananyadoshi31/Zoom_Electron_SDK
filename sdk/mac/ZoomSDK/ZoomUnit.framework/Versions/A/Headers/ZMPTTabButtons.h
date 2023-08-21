//
//  ZMPTTabButtons.h
//  SaasBeePTUIModule
//
//  Created by ryan on 14-5-9.
//  Copyright (c) 2014年 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface ZMPTTabButton : NSView
{
@private
    BOOL                _selected;
    NSString*           _title;
    NSFont*             _font;
    NSColor*            _textColor;
}

@property (nonatomic, readwrite, retain) NSString* title;
@property (nonatomic, readwrite, assign) BOOL selected;
@property (nonatomic, readwrite, retain) NSFont* font;
@property (nonatomic, readwrite, retain) NSColor* textColor;

- (void)select;

@end

@class ZMPTTabButtons;


@protocol ZMPTTabButtonsDelegate <NSObject>

- (void)tab:(ZMPTTabButtons*)tab clickedAtIndex:(int)index;

@end


@interface ZMPTTabButtons : NSView
{
@private
    NSMutableArray*             _buttonArray;
    id<ZMPTTabButtonsDelegate>  _delegate;
}

@property (nonatomic, readwrite, assign) id<ZMPTTabButtonsDelegate> delegate;

- (void)setTitle:(NSString*)title atIndex:(int)index;
- (void)initButtonsWithTitles:(NSArray*)titleArray;
- (void)selectItemAtIndex:(int)index;
- (ZMPTTabButton*)objectAtIndex:(int)index;

@end

