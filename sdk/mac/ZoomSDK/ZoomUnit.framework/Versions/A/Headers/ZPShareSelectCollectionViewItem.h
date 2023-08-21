//
//  ZPShareSelectCollectionViewItem.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZPShareSelectView.h>

@class ZPShareSelectWindowModel;
@interface ZPShareSelectCollectionViewItem : NSCollectionViewItem<ZPShareSelectViewDelegate>

- (instancetype)initWithRepresentedObject:(ZPShareSelectWindowModel *)object;
- (void)cleanUp;

@end
