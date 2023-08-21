//
//  ZMMTCCHelper.h
//  VideoUIBridge
//
//  Created by martin.yu on 10/25/22.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
class ICmmUser;
#endif

#ifdef __cplusplus
extern "C" {
#endif
ZMConfSession *ZMMTCCGetCurrentConfSession(void);
#ifdef __cplusplus
}
#endif

@interface ZMMTCCHelper : ZMBaseHelper

- (BOOL)hasClosedCaption;
- (BOOL)hasManualTranscription; // ZOOM-322516
- (BOOL)allowHostToAssignCCEditor; // ZOOM-322516
- (BOOL)is3rdPartCCServerAvailable;
- (nullable NSString *)getClosedCaptionGatewayURL;
- (BOOL)hasLiveTranscription;
- (BOOL)isLiveTranscriptionEnabled;

- (BOOL)canShowCCButton;
- (BOOL)canSaveClosedCaption; //ZOOM-40173
- (BOOL)saveCaptions;

- (BOOL)isClosedCaptionLegalNoticeAvailable;

- (BOOL)grabCCEditorRole;
- (BOOL)isCCEditorAssigned;
- (BOOL)isCCEditor;
#ifdef __cplusplus
- (nullable ICmmUser *)getClosedCaptionEditorUser;
#endif

// ZOOM-268562
- (BOOL)canViewFullTranscript;

// ZOOM-283768
- (BOOL)isMultiLanguageTranscriptionEnabled;
- (BOOL)isMeetingLanguageLocked;
- (BOOL)canAssignCCEditor;

// ZOOM-319811
- (BOOL)isLTTTextLiveTranslationEnabled;

// ZOOM-423983
- (BOOL)isMMRSupportTemporarilyDisableLTTCaptions;
- (void)temporarilyDisableCaptions:(BOOL)bDisable;
- (BOOL)isCaptionsTemporarilyDisabled;

// ZOOM-423978
- (BOOL)needSetSpeakingLanguageForSubscription:(BOOL)bEnableTranslation;
- (BOOL)needApplyForAllWhenChangingSpeakingLanguage;
- (BOOL)isLTTTextTranslationStarted;

// ZOOM-439505
- (BOOL)isCaptionsStartedWhenRestricted;

@end

NS_ASSUME_NONNULL_END
