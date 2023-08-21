//
//  ZMScheduleMeetingCardView.h
//  ChatUI
//
//  Created by simon shang on 2022/5/20.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMScheduleMeetingInfo;
@class ZMScheduleMeetingCardView;

@protocol ZMScheduleMeetingCardViewDelegate <NSObject>

- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView joinMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber password:(NSString *)password;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView viewInCalendar:(NSString *)calendarLink;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView copyInvitation:(NSString *)joinURL;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView editMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber occurrenceTime:(long)occurrenceTime;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView deleteMeeting:(NSString *)sessionId meetingNumber:(long)meetingNumber occurrenceTime:(long)occurrenceTime;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView joinFromARoom:(NSString *)sessionId meetingNumber:(long)meetingNumber;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView moreParticipantsClicked:(ZMScheduleMeetingInfo *)meetingInfo;
- (BOOL)scheduleMeetingCardView:(ZMScheduleMeetingCardView *)scheduleMeetingCardView isInMeeting:(long)meetingNumber;

@end

@interface ZMScheduleMeetingCardView : ZMBaseView

@property (nonatomic, retain) ZMScheduleMeetingInfo *scheduleMeetingInfo;

@property (nonatomic, weak) id<ZMScheduleMeetingCardViewDelegate> scheduleMeetingCardViewDelegate;

- (void)updateUI;

- (CGFloat)calculateHeightWithWidth:(CGFloat)width;

@end

NS_ASSUME_NONNULL_END
