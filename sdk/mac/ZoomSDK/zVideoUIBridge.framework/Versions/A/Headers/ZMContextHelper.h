//
//  ZMContextHelper.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/8.
//

#import <zVideoUIBridge/ZMConfAPI.h>

NS_ASSUME_NONNULL_BEGIN

#define ZMMonitor(confSession,eventType,format,...) ([confSession.zpConfHelper writeMonitorLog:(eventType) content:[NSString stringWithFormat:(format),##__VA_ARGS__]])

@class ZMUser;

@interface ZPConfHelper : ZMConfAPI

+ (ZPConfHelper*)sharedConfHelper;

- (int)getUserCount;
- (int)getPanelistUserCount;
- (int)getUserCountWithoutOnHold;

- (BOOL)isSameUser:(ZMUserID)user1 compareTo:(ZMUserID)user2;
- (BOOL)isMyUserID:(ZMUserID)userID;
- (ZMUserID)getMyUserID;
- (long long)getMyAttendeeID;
- (nullable NSString*)getMyDisplayName;
- (nullable NSString*)getZoomIdByUserId:(ZMUserID)inUserId;
- (nullable NSString*)getMeetingNumber;
- (NSString*)getFormattedMeetingNumber;
- (nullable NSString*)getUserNameByID:(int)userID;

- (BOOL)isWebinar;
- (BOOL)isViewOnly;

- (BOOL)isShowNoVideoUser;
- (BOOL)isMandatoryShowNoVideoUser;
- (BOOL)isShowMySelfVideo;
- (BOOL)isMandatoryShowMySelfVideo;
- (BOOL)isNoVideoMeeting;

- (BOOL)isFilterTWEmojiEnabled;
- (BOOL)isUserPicDownloaded:(int)inUserID;

- (BOOL)isLeadMode;

- (BOOL)isReceivingSharingFromUser:(ZMUserID)inUserId;
- (BOOL)isAnyoneSharing;
- (NSUInteger)getShareSourceCount;
- (BOOL)isReceivingSharingFromCurrentConf;
- (BOOL)isSendingAnySharing;

- (BOOL)isShareOnlyMeeting;
- (BOOL)isNoOneSendingVideo;
- (BOOL)isDirectShareClient;

- (BOOL)isUserSupportRemoteControlWithUserId:(int)inUserId;
- (void)sendRemoteSupportResponse:(ZMUserID)inUserId type:(int)type bApproved:(BOOL)bApproved;
- (BOOL)sendRemoteSupportRequest:(ZMUserID)inUserId type:(int)type;
- (BOOL)isRemoteController;

- (BOOL)canUserRecordById:(int)inUserId;
- (BOOL)isUserRaiseHandById:(int)inUserId;

- (BOOL)isChatOff;
- (BOOL)isMeetingLocked;
- (BOOL)isInSilentMode;
- (BOOL)isMasterConfSupportSilentMode;
- (BOOL)isSupportWaitingOnEntry;
- (BOOL)canShowInviteeList;
- (BOOL)isSupportEditAvatar;//ZOOM-167535
- (BOOL)isSupportUnmuteAudioPrivacy;//ZOOM-169862

- (BOOL)isAudioSessionOff;
- (BOOL)isDisableAudioForInSipCall;//zoom-14478 sip
- (BOOL)isTurnoffComputerAudioInSipCall;//zoom-14478 ZOOM-20377 sip
- (BOOL)isCurrentConferenceAudioOn;
- (BOOL)isUserAudioMuted:(int)userID;
- (int)getUserAudioType:(int)userID;

- (BOOL)isSharingWhiteboard;
- (nullable NSWindow*)getWbContentWindow;

- (BOOL)amIHost;
- (BOOL)amICoHost;

- (void)writeMonitorLog:(NSString*)inEventType content:(NSString*)inEventContent;

//ZOOM-309128
- (nullable NSString*)getConfidentialWaterMarker;
- (ZMConfWaterMarkCoverType)getWaterMarkCoverType;
- (ZMConfWaterMarkPosition)getWaterMarkPosition;
- (ZMConfWaterMarkVisibleOnType)getWaterMarkerVisibleOnType;
- (CGFloat)getWaterMarkerOpacityLevel;
- (BOOL)canSwitchWatermark;
- (BOOL)isConfidentialWatermarkOn;
- (void)setConfidentialWatermarkOn:(BOOL)turnOn;

- (BOOL)isTspEnabled;
- (nullable NSString*)getTspMergeCode;
- (BOOL)isNotSupportTelephony;
- (NSString*)getTelephoneBindingCode;//ZOOM-131003
- (NSString*)getTelephoneBindingParticipantCode;

- (nullable NSString*)getActiveSpeackName;
- (nullable ZMUser*)getActiveVideoUser;
- (nullable ZMUser*)getRealActiveVideoUser;

//ZOOM-21795
- (BOOL)isSendingComputerAudio;
- (BOOL)isReceivingComputerAudio;

- (BOOL)isAudioWatermarkEnabled;
- (BOOL)isE2EEncMeeting;

- (BOOL)isAudioForceDisabled;//ZOOM-54743
- (BOOL)isAuthLocalRecordDisabled;
- (BOOL)isAllowMessageAndFeedbackNotify;// ZOOM-82083
- (BOOL)isMessageAndFeedbackNotifyEnabled;// ZOOM-82083

- (BOOL)canSendMyVideo;//ZOOM-82229
- (BOOL)canReceiveVideo;//ZOOM-82229
- (BOOL)isInVideoCompanionMode;//ZOOM-82110

- (int)getConfEncryptionType;//ZOOM-155247

- (BOOL)isShareDisabledByInfoBarrier;//ZOOM-93173
- (BOOL)isShareDisabledByExternalLimit;

- (BOOL)isReportIssueEnable;//ZOOM-150227
- (BOOL)isParticipantReportIssueEnable;//ZOOM-200525
- (BOOL)canIReportIssue;//ZOOM-200525
- (BOOL)isSuspendMeetingEnable;//ZOOM-200525

- (BOOL)isGovEnvironment;//ZOOM-151325
- (BOOL)hasLiveOnStream;

- (NSString*)getGiftUpgradeUrl;

//ZOOM-295612
- (BOOL)canDirectChatToUser:(ZMUser*)zmUser;

- (BOOL)isNoOneInMeeting;
- (BOOL)isPracticeSessionFeatureOn;
- (BOOL)isPracticeSession;

- (BOOL)needPromptGreenRoomGuide;
- (void)increaseGreenRoomGuidePromptCount;

- (BOOL)isBrandingMeeting;
- (nullable NSString *)getBacksplashPath;
- (BOOL)canShowSessionBrandingBacksplash;

- (BOOL)isShowUserAvatarDisable;
- (BOOL)isTWEmojiLibraryEnabled;
- (BOOL)isChangeMeetingTopicEnabled;
- (BOOL)isHostChatToWaitingRoomDisabled;
- (BOOL)isChatDLPEnabled;
- (BOOL)isViewBOActivityEnabled;
- (BOOL)isSameAccountWithHost;

- (BOOL)doesCurrentMeetingSupportLivestreamToZoomEventLobby;
- (BOOL)isRecurringExceptNoFixTime;
///return WAITINGROOM_USER_SORT_METHOD
- (NSInteger)waitingRoomUserSortMethod;//ZOOM-350340

- (BOOL)isMMRSupportSubscribeVirtualUser;

- (BOOL)isMeetingVCardEnabled;
- (BOOL)isMoreCustomInterpreteLanEnabled;//ZOOM-366210

- (BOOL)shouldToolbarAlwaysBeShowing; // Implemented by category

- (int)getLeaveReason;//return CmmLeaveReason

- (BOOL)isPMCScreenShotEnabled;
- (BOOL)isPersistEditChatDisabled;
- (BOOL)isPersistReplyChatDisabled;
- (BOOL)isPersistReactionChatDisabled;
- (BOOL)isPersistGIFChatDisabled;
- (BOOL)isPMCForBackendEnabled;
- (BOOL)isTeamChatEnabled;

- (BOOL)needPromptZoomPhoneACRDisclaimer;
- (BOOL)isZoomPhoneACRInProgress;

@end

NS_ASSUME_NONNULL_END
