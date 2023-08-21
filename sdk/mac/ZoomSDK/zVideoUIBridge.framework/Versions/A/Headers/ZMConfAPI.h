//
//  ZMConfAPI.h
//  SaasBeeConfUIModule
//
//  Created by javenlee.li on 2021/7/23.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMConfAPI : ZMBaseHelper

//ZOOM-13936
- (BOOL)isSelectAuduioDeviceDone;
- (void)setSelectAuduioDeviceDone;
//ZOOM-13934
- (BOOL)isConnectVOIPTIPDone;
- (void)setConnectVOIPTIPDone;
- (void)requestToRebootAndJoin;

- (int)getMaxMeetingParticipantCount;

- (BOOL)isSettingValueExistForKey:(NSString*)key;
- (BOOL)getBoolSettingValueForKey:(NSString*)key;
- (void)setSettingBoolValueForKey:(NSString*)key value:(BOOL)isYes;
- (BOOL)getIntSettingValueForKey:(NSString*)inKey value:(int*)outValue;
- (void)setSettingIntValueForKey:(NSString*)key value:(int)inValue;
- (BOOL)getStringSettingValueForKey:(NSString*)inKey value:(NSString *_Nonnull *_Nonnull)outValue;
- (void)setSettingStringValueForKey:(NSString*)inKey value:(NSString*)inValue;

- (void)logClientAction:(NSString*)uicontainer action:(NSString*)action param:(NSString*)param;

- (BOOL)isAccEventOptionOn:(NSInteger)eventId;//ZOOM-19946;

- (BOOL)needShowAttendeeNumber;

- (BOOL)isPTLogin;
- (BOOL)isPTLogined;//common api
- (BOOL)retrievePTLoginStatus;
- (nullable NSString *)getPTLoginJid;

- (BOOL)isFreewayUserIndex:(int)userID;
- (BOOL)isUserOriginalOrAltHostByJID:(NSString*)inJID;
- (BOOL)isSelfOriginalHost;
- (BOOL)hasHostInMeeting;

- (BOOL)isSupportInvite;//ZOOM-167535
- (BOOL)isInDebriefSession;

- (nullable NSString*)getBackstageWebinarStartTime;

- (BOOL)isAllowParticipantRenameEnabled;//ZOOM-68095
- (BOOL)isAllowParticipantRenameLocked;
- (BOOL)isAllowParticipantRename;//ZOOM-68095
- (void)setAllowParticipantRename:(BOOL)allow;//ZOOM-68095
- (BOOL)isHostRenameWaitingRoomAttendeesEnabled;

- (BOOL)isAllowAttendeeRaiseHand;//ZOOM-15291
- (BOOL)isAttendeeVideoControlFollow;//ZOOM-15291
- (BOOL)isAttendeeVideoControlSideBySide;//ZOOM-248971
- (BOOL)isAttendeeVideoControlActive;//ZOOM-15291
- (BOOL)isAttendeeVideoControlWall;//ZOOM-15291

- (BOOL)isAvatarAllowed;

- (BOOL)isLegalConfNumber:(NSString*)confNumber;
- (nullable NSString*)getJoinMeetingURL;
- (nullable NSString*)getCopyJoinMeetingURLWithString:(NSString *)passwordString;
- (nullable NSString*)getPhoneCallInNumber;
- (nullable NSString*)getTollFreeNumber;
- (int)getMeetingDuration;
- (nullable NSString*)getProductDomain;
- (nullable NSString*)getLoginHostName;
- (nullable NSString*)getMeetingPassword;
- (nullable NSString*)getRawMeetingPassword;
- (nullable NSString*)getH323Password;
- (nullable NSString*)getMeetingTopic;
- (nullable NSString*)getMeetingHostName;
- (nullable NSURL*)getWebinarRegisterURL;
- (int)getFECCContinueIntervalInMS;
- (uint8_t)getAttendeeChatPriviledge;    //ZOOM-65890

- (BOOL)isSpotlightVideoByUserId:(int)inUserId;
- (void)spotlightUserById:(int)inUserId shouldSpotlight:(BOOL)inShouldSpotlight;

- (BOOL)hasEnoughPerformanceForWallView;
- (BOOL)hasEnoughPerformanceForDualMonitor;
- (BOOL)hasEnoughPerformanceForVirtualBackground;
- (BOOL)isEnabledDualMonitorMode;
- (BOOL)isAutoFullscreenWhenStartingConferenceVideo;
- (BOOL)isAutoFullscreenWhenViewShare;
- (BOOL)isAutoFit2Window4ViewingSharing;
- (BOOL)isConfirmWhenLeave;
- (BOOL)isAutoStartShare;
- (BOOL)shouldShowVideoUIDirectlyBeforeMeetingReady;
- (BOOL)isPrivateChatOff;
- (BOOL)isFeedbackOff;
- (BOOL)isMeetingSupportSilentMode;
- (BOOL)isAlwaysShowUserName;
- (BOOL)isAble2HideSystemCursor;
- (BOOL)amISpotlightSelf;
- (BOOL)isFileTransferEnabled;
- (BOOL)canSaveChat;
- (BOOL)isChatCopyEnabled;   //ZOOM-68845
- (BOOL)isPaidMeeting;//ZOOM-35970
- (BOOL)isEnablePushToTalk;//ZOOM-542
- (BOOL)isAllowUserRejoinAfterRemove;
- (BOOL)needPromptGuestParticipantLoginWhenJoin;
- (BOOL)isRemoteAdminExisting;//ZOOM-113382
- (BOOL)isAssistantAdminExisting;//ZOOM-255798
- (BOOL)isMMRSupportWaitingRoomMsg;//ZOOM-46301
- (BOOL)canMutedWhenScreenLocked;//ZOOM-136057
- (BOOL)isLeaveAssignNewHostEnabled;

//ZOOM-115938
- (BOOL)isBindTelephoneUserEnable;
- (BOOL)isUnbindTelephoneUserEnable;

- (BOOL)isSupportLivestreamToZoomEventLobby;
- (nonnull NSString *)getZoomEventsLivestreamLabel;

- (BOOL)isShareLocked;
- (BOOL)isSharePaused:(BOOL*)isManualPause;

- (int)getViewOnlyUserCount;
- (int)getViewOnlyTelephoneUserCount;

// ZOOM-360254
- (BOOL)isMoreFeaturesAvailable;
- (void)setAgreeJoinSDKMeeting:(BOOL)agree;
- (BOOL)isJoinSDKMeeting;
- (nullable NSString *)sdkMeetingFeatureUrl;
- (nullable NSString *)sdkMeetingLogoPathForDarkMode:(BOOL)darkMode;
- (nullable NSString *)gatewayName;
- (BOOL)isFirstTimeUseMoreFeatures;
- (void)setNotFirstTimeUseMoreFeatures;

- (float)getTitleBarHeightWithStyleMask:(int)inStyleMask;

//ZOOM-4026 Attention Track
- (BOOL)isEnableWebAttentionTrack;
- (BOOL)isEnableConfAttentionTrack;

- (BOOL)isWaitingOnEntryLocked;//ZOOM-147468
- (BOOL)isMasterConfSupportWaitingOnEntry;//ZOOM-224693
- (BOOL)isWaitingOnEntry;//ZOOM-147468

- (BOOL)isMMRSupportViewOnlyClient;//ZOOM-15291

- (BOOL)isWallViewEnable180P;

- (NSInteger)freeGroupMeetingCount;//ZOOM-41323
- (BOOL)isMeetingUpgradedFromSip;
- (NSUInteger)getMeetingElapsedTime;

- (BOOL)isRequireEncryptionFor3rdEndpotins; // ZOOM-97072

- (BOOL)isAutoShowJoinAudioDialogEnabled;//ZOOM-76554
- (BOOL)isWebJoinFromTestMeeting;

- (BOOL)needShowBandWidthLimit;
- (BOOL)isEnableBandWidthLimit;//ZOOM-82229
- (BOOL)isBandWidthLimitSendVideo;//ZOOM-82229
- (BOOL)isBandWidthLimitReceiveVideo;//ZOOM-82229

- (NSString *)getMeetingID;
- (nullable NSString *)getConfDCRegion;//ZOOM-151956
- (nullable NSString *)getEventDetailLink;//ZOOM-167535

- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString *)messageId needShowCheck:(BOOL *)needShow;
- (void)setAlwaysTrustFileSender:(int)senderId alwaysTrust:(BOOL)alwaysTrust;

- (NSInteger)getConfStatus;//CONF_STATUS
- (nullable NSString *)getE2EMeetingSecurityCode;

- (NSInteger)getE2EMeetingSecurityCodePassedSeconds;
- (BOOL)isMeetingArchiveEnabled;//ZOOM-182945
- (BOOL)isMeetingArchiveInProgress;
- (nullable NSString *)getMeetingArchiveLearnMoreLink;
- (NSInteger)getMeetingArchiveOptions;
- (BOOL)needPromptArchiveDisclaimer;
- (BOOL)needPromptViewBOActDisclaimer;
- (void)agreeViewBOActDisclaimer;
- (void)disagreeViewBOActDisclaimer:(BOOL)bLeaveMeeting;
- (BOOL)canShowPollingDownloadLink;//ZOOM-199234
- (BOOL)isUnencryptedDataPromptEnabled;
- (BOOL)isLiveUnencrypted;
- (BOOL)hasUnencryptedData;
- (NSInteger)getUnencryptedExceptionCount;
- (NSInteger)getMeshUnSignedParticipantsCount;  // ZOOM-421787
- (BOOL)hasMeshUnSignedParticipants;                 // ZOOM-421787
- (BOOL)needHideMeetingNumber;//ZOOM-193452
- (BOOL)needHideMeetingPasscode;//ZOOM-193452
- (BOOL)isMyDlpEnabled;
- (NSInteger)checkDlpWithContent:(NSString *)content receiver:(NSString *)receiver policyName:(NSString *_Nullable *_Nullable)policyName;

//ZOOM-206956
- (BOOL)isImmersiveMode;
- (BOOL)isImmersiveModeEnabled;
- (BOOL)isImmersiveFirstUse;

//ZOOM-271443
- (BOOL)isFocusModeFirstUse;
- (BOOL)isFocusModeEnabled;
- (BOOL)isFocusModeEnding;
- (BOOL)isFocusModeOn;
- (BOOL)isVideoFocusModeOn;

//ZOOM-298093
- (BOOL)isGalleryVideoOrderEnabled;
- (BOOL)isGalleryVideoOrderSaved;

- (BOOL)isCloudWhiteboardEnabled;
- (BOOL)isCloudWhiteboardWebEnabled;
- (BOOL)canShareWhiteboard;

- (BOOL)isPollingLegalNoticeAvailable;
- (BOOL)isQALegalNoticeAvailable;
- (nullable NSString*)getRegisterAccountOwnerLink;
- (nullable NSString*)getRegisterTermsLink;
- (nullable NSString*)getRegisterPrivacyPolicyLink;
- (BOOL)isMeetingArchivingDisclaimerAvailable;
- (void)getMeetingArchivingDisclaimerWithTitle:(NSString *_Nonnull *_Nonnull)title
                                   description:(NSString *_Nonnull *_Nonnull)description
                                    linkString:(NSString *_Nonnull *_Nonnull)linkString
                                       linkUrl:(NSString *_Nonnull *_Nonnull)linkUrl;
- (nullable NSString *)getArchiveOwnerLink;
- (BOOL)isMeetingArchiveFailed;
- (BOOL)isZappServiceEnabled;

- (BOOL)isAllowPanelistSendFileViaWebinarChatEnabled;
//ZOOM-273485
- (BOOL)isShareMyPronounEnabled;
- (BOOL)isEventDirectMeeting;

- (BOOL)isDisplayWebinarChatSettingEnabled;
- (void)changePanelistChatPriviledge:(NSInteger)priviledge;
- (NSInteger)getPanelistChatDefaultPrivilege;
- (NSInteger)getAttendeeDefaultChatTo;
- (NSInteger)getSaveChatPrivilege;
- (BOOL)isSupportAdvancedPollEnabled;
- (BOOL)supportWaitingRoomChat;
- (BOOL)shouldShowMeetingChatAvatar;

- (nullable NSString *)getUnlimitedMeetingNoticeTitleForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeDescriptionForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeButtonForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeUrlForThird30Min;
@end

NS_ASSUME_NONNULL_END
