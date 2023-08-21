//
//  ZMBuddyCellView.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/4/30.
//

#import <ZoomUnit/ZoomUnit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMIMAvatarView;

@interface ZMBuddyCellView : ZMBaseTableCellView

@property (nonatomic,retain) ZMIMAvatarView *avatarImageView;

@property (nonatomic,retain) NSTextField *nameTextField;

@end

NS_ASSUME_NONNULL_END
