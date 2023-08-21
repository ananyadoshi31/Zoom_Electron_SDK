//
//  ZMMessageCellViewDelegate.h
//  ZCommonUI
//
//  Created by groot.ding on 29/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#ifndef ZMMessageCellViewDelegate_h
#define ZMMessageCellViewDelegate_h

@class ZMBaseMessageCellView,ZMAvatarView,ZMMessageItemInfo,ZMReactionItemView,ZMFileEntity,ZMScheduleMeetingInfo;
@class ZMAddReplyMessageCellView;

@protocol ZMMessageCellViewDelegate <NSObject>

@optional

- (ZMMessageItemInfo *)cellView:(ZMBaseMessageCellView *)cellView getItemByNode:(NSTreeNode *)node;

- (void)cellView:(ZMBaseMessageCellView *)cellView updateMessageHeightByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView updateMessageHeightWithoutReloadingByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView addReplyByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView loadMoreReplyByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView collapseReplyByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView moreButtonClick:(NSButton *)button item:(ZMMessageItemInfo *)item;


//reaction
- (void)cellView:(ZMBaseMessageCellView *)cellView addReactionWithButton:(ZMReactionItemView *)button item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView reactionEmoji:(NSString *)emoji item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView showReactionTipWithButton:(ZMReactionItemView *)button item:(ZMMessageItemInfo *)item;

- (BOOL)cellView:(ZMBaseMessageCellView *)cellView checkReactionPannelVisibleWithItem:(ZMMessageItemInfo *)item;

//avatar
- (void)cellView:(ZMBaseMessageCellView *)cellView avatarClick:(ZMAvatarView *)avatarView isKeyPress:(BOOL)isKeyPress item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView avatarHover:(ZMAvatarView *)avatarView item:(ZMMessageItemInfo *)item;

//edit
- (void)cellView:(ZMBaseMessageCellView *)cellView commitEditMessageByItem:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView cancelEditMessageByItem:(ZMMessageItemInfo *)item;

//mark
- (void)cellView:(ZMBaseMessageCellView *)cellView markActionByItem:(ZMMessageItemInfo *)item;

//jump
- (void)cellView:(ZMBaseMessageCellView *)cellView jumpToMessageByItem:(ZMMessageItemInfo *)item;

//delete
- (void)cellView:(ZMBaseMessageCellView *)cellView deleteMessageByItem:(ZMMessageItemInfo *)item;

//resend
- (void)cellView:(ZMBaseMessageCellView *)cellView resendByItem:(ZMMessageItemInfo *)item;

//e2e decode
- (void)cellView:(ZMBaseMessageCellView *)cellView tryDecodeE2EByItem:(ZMMessageItemInfo *)item;

//code sinppet
- (void)cellView:(ZMBaseMessageCellView *)cellView installCodeSippetPluginByItem:(ZMMessageItemInfo *)item;


- (void)cellView:(ZMBaseMessageCellView *)cellView previewCodeSippetByItem:(ZMMessageItemInfo *)item;

//file
- (void)cellView:(ZMBaseMessageCellView *)cellView openFile:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView downloadButtonClick:(NSButton *)button item:(ZMMessageItemInfo *)item file:(ZMFileEntity *)fileEntity;

- (void)cellView:(ZMBaseMessageCellView *)cellView fileMoreButtonClick:(NSButton *)button item:(ZMMessageItemInfo *)item file:(ZMFileEntity *)fileEntity;

//view pin history

- (void)cellView:(ZMBaseMessageCellView *)cellView viewPinHistory:(ZMMessageItemInfo *)item;

// file view operation

- (void)cellView:(ZMBaseMessageCellView *)cellView fileViewRightMouseClickedWithInfo:(ZMFileEntity *)fileModel atPoint:(NSPoint)aPoint;

- (void)cellView:(ZMBaseMessageCellView *)cellView fileViewOpenFileWithInfo:(ZMFileEntity *)fileModel;

- (void)cellView:(ZMBaseMessageCellView *)cellView fileViewRightMouseClickedWithInfo:(ZMFileEntity *)fileModel;

- (void)cellView:(ZMBaseMessageCellView *)cellView clickAttributes:(NSDictionary *)attributes item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView textView:(NSTextView *)textView hoverAttributes:(NSDictionary *)attributes charIndex:(NSInteger)charIndex item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView textView:(NSTextView *)textView hoverAttachmentCell:(id<NSTextAttachmentCell>)cell charIndex:(NSInteger)charIndex item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMBaseMessageCellView *)cellView clickAttachmentCell:(id<NSTextAttachmentCell>)cell item:(ZMMessageItemInfo *)item;

// channel invite request
- (void)cellView:(ZMBaseMessageCellView *)cellView approveChannelJoinRequest:(ZMMessageItemInfo *)item resultCallback:(void (^_Nullable)(UInt32))resultCallback;

- (void)cellView:(ZMBaseMessageCellView *)cellView declineChannelJoinRequest:(ZMMessageItemInfo *)item resultCallback:(void (^_Nullable)(UInt32))resultCallback;

- (void)cellView:(ZMBaseMessageCellView *)cellView openNewWebView:(NSString *)htmlPath item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMAddReplyMessageCellView *)cellView addReplyMessage:(NSAttributedString *)msg fileListArr:(NSArray<ZMFileEntity *> *)fileListArr item:(ZMMessageItemInfo *)item;

- (void)cellView:(ZMAddReplyMessageCellView *)cellView updateFirstResponse:(BOOL)firstResponse item:(ZMMessageItemInfo *)item;

// schedule meeting card

- (void)cellView:(ZMBaseMessageCellView *)cellView joinMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber password:(NSString *)password;

- (void)cellView:(ZMBaseMessageCellView *)cellView viewInCalendar:(NSString *)calendarLink;

- (void)cellView:(ZMBaseMessageCellView *)cellView copyInvitation:(NSString *)joinURL;

- (void)cellView:(ZMBaseMessageCellView *)cellView editMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber occurrenceTime:(long)occurrenceTime;

- (void)cellView:(ZMBaseMessageCellView *)cellView deleteMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber occurrenceTime:(long)occurrenceTime;

- (void)cellView:(ZMBaseMessageCellView *)cellView joinFromARoom:(NSString *)sessionId meetingNumber:(long)meetingNumber;

- (void)cellView:(ZMBaseMessageCellView *)cellView moreParticipantsClicked:(ZMScheduleMeetingInfo *)meetingInfo;

- (BOOL)cellView:(ZMBaseMessageCellView *)cellView isInMeeting:(long)meetingNumber;

//zapp meeting cell
- (void)cellView:(ZMBaseMessageCellView *_Nonnull)cellView  openZappByItem:(ZMMessageItemInfo *_Nonnull)item;
- (NSString *_Nonnull)cellView:(ZMBaseMessageCellView *_Nonnull)cellView getAppInvitationInfoUrl:(NSString *_Nonnull)appId linkType:(NSUInteger)type;
@end

#endif /* ZMMessageDelegate_h */
