//
//  ZMMTToolbarTipEvents.h
//  VideoUI
//
//  Created by martin.yu on 4/24/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef ZMMTToolbarTipEventsProtocol_h
#define ZMMTToolbarTipEventsProtocol_h

@protocol ZMMTToolbarTipEventsProtocol <NSObject>
@optional
- (void)updateToolbarTipPosition;
- (void)hideAllToolbarTips;

- (void)showJoinAudioTip:(BOOL)isFocedPrompt;
- (void)hideJoinAudioTip;

- (void)showSelectAuidoDeviceTipWithTipString:(NSString *)tipString;
- (void)hideSelectAuidoDeviceTip;

- (void)showFitBarCanNotJoinAudioTip;
- (void)hideFitBarCanNotJoinAudioTip;

- (void)showToolbarChatTip:(NSString *)thePhotoUrl title:(NSString *)theTitle desc:(NSString *)theDesc from:(int)fromFriendId to:(int)toFriendId fromName:(NSString *)fromName;
- (void)hideToolbarChatTip;
- (void)showToolbarEnableChatTip;
- (void)hideToolbarEnableChatTip;
- (void)showToolbarPMCChatTip;
- (void)hideToolbarPMCChatTip;

// source: 0 toolBar, 1 fitBar
- (void)showCCTipWithTipString:(NSString *)tipString source:(int)source;
- (void)hideCCTipWithSource:(int)source;

- (void)showToolbarBOTip:(NSString*)inTip force:(BOOL)force;
- (void)hideToolbarBOTip;
- (void)showToolbarBOUnassignUserTipWithCount:(int)inCount;
- (void)hideToolbarBOUnassignUserTip;

- (void)showResetOrderTipIfNeed;
- (void)hideResetOrderTip;

- (void)showToolbarAvailableInterpretLanguageTipWithTipString:(NSString *)tipString;
- (void)hideToolbarAvailableInterpretLanguageTip;
//ZOOM-330475
- (void)showToolbarInterpretationMicStateTipWithTipString:(NSString *)tipString enabled:(BOOL)enabled;
- (void)hideToolbarInterpretationMicStateTip;

- (void)toolbarCopyInviteLinkAndNotice;

- (void)showHasSendReactionTipWithTipString:(NSString *)tipString;
- (void)hideHasSendReactionTip;

- (void)showToolbarMoreFeaturesNewTip;
- (void)hideToolbarMoreFeaturesNewTip;

- (void)showSidecarTip:(NSString*)tip;
- (void)hideSidecarTip;

- (BOOL)isToolbarReactionsGestureNewTipShowing;
- (void)showToolbarReactionsGestureNewTip;
- (void)hideToolbarReactionsGestureNewTip;

- (void)hideRaiseHandTip;
- (void)showLiveStreamTip;
- (void)hideLiveStreamTip;


- (void)showToolbarNewBOTipWithTipString:(NSString *)tipString
                        mouseEventAction:(nullable BOOL(^)(ZMBubbleObject *bubbleObj, NSEvent *event))mouseEventAction;
- (void)hideToolbarNewBOTip;
@end

#endif /* ZMMTToolbarTipEventsProtocol_h */
