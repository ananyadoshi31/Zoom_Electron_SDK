//
//  ZMMTImageView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 10/28/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface ZMMTImageView : ZMTagView
@property(nonatomic, retain) NSImage* image;
@property(nonatomic) NSRectCorner cornerType;
@property(nonatomic) CGFloat cornerRadius;
@property(nonatomic) CGFloat borderWidth;
@property(retain) NSColor* borderColor;
@property(retain) NSColor* backgroundColor;
@property(nonatomic) BOOL drawImageOrigalSize;
@end

NS_ASSUME_NONNULL_END
