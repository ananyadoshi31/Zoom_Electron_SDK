//
//  ZMEmojiDataSrcMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 9/30/16.
//  Copyright © 2016 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMGridViewDelegate.h"
#import "ZMGridViewItem.h"

@interface ZMZoomEmojiDataSrcMgr : NSObject
{
    NSMutableArray*  _emojiArray;
    id               _gridViewId;
}
- (void)attach2GridView:(id)inGridView;
- (ZMEmojiItemData*)gridItemByKeyString:(NSString*)keyString;
- (void)cleanUp;
- (void)gridViewReloadAllItems;
@end


