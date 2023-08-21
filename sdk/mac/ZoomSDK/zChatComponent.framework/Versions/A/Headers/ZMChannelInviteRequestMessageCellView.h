//
//  ZMChannelInviteRequestMessageCellView.h
//  zChatComponent
//
//  Created by Felipe Bastos on 6/22/22.
//

#import <Foundation/Foundation.h>

#import <zChatComponent/ZMAvatarView.h>
#import <zChatComponent/ZMBaseMessageCellView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChannelInviteRequestBubbleView : ZMBaseView

@property (nonatomic, retain) NSTextField *descriptionField;
@property (nonatomic, retain) NSButton *acceptButton;
@property (nonatomic, retain) NSButton *declineButton;

@end

@interface ZMChannelInviteRequestMessageCellView : ZMBaseMessageCellView

@property (nonatomic, retain) ZMAvatarView *avatarView;
@property (nonatomic, retain) NSView *headerView;
@property (nonatomic, retain) ZMChannelInviteRequestBubbleView *bubbleView;
@property (nonatomic, retain, nullable) ZMButton *acceptButton;
@property (nonatomic, retain, nullable) ZMButton *cancelButton;
@property (nonatomic, retain, nullable) NSProgressIndicator *progressIndicator;
@property (assign) BOOL isActionPending;

@end

NS_ASSUME_NONNULL_END
