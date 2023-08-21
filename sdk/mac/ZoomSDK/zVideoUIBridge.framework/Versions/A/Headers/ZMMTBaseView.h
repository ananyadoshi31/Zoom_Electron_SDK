//
//  ZMMTBaseVeiw.h
//  ZMMTNewUIDemo
//
//  Created by francis zhuo on 5/10/20.
//  Copyright © 2020 zoom. All rights reserved.
//

typedef NSUInteger ZMMTType;

@interface ZMMTViewType : NSObject
//level 1 type
@property(class, readonly) ZMMTType main;
@property(class, readonly) ZMMTType aux;
@property(class, readonly) ZMMTType mini;
@property(class, readonly) ZMMTType floatPanel;
@property(class, readonly) ZMMTType countDown;
@property(class, readonly) ZMMTType interpreter;

//level 2 type
@property(class, readonly) ZMMTType backstage;

//level 3 type
@property(class, readonly) ZMMTType share_screen;
@property(class, readonly) ZMMTType viewer_screen;
@end

#import <ZoomKit/ZoomKit.h>
@interface ZMMTBaseView : ZMBaseView
@property(assign) NSRectCorner cornerType;
@property(getter=isFlipped, assign) BOOL flipped;
@end
