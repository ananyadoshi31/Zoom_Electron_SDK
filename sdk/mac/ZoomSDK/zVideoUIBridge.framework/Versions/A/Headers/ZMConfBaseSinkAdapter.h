//
//  ZMConfBaseSinkAdapter.h
//  VideoUI
//
//  Created by Francis Zhuo on 2/22/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>
#import <zVideoUIBridge/ZMMTDelayCall.h>
#import <zVideoUIBridge/ZMMTRosterList.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;
@interface ZMConfBaseSinkAdapter : NSObject
@property (nonatomic, weak) ZMConfSession* confSession;
@property (assign) BOOL isLeavingMeeting;

@property (nonatomic, retain) ZMMTDelayCall* userRosterChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* audioStatusChangedCall;
@property (nonatomic, retain) ZMMTDelayCall* activeAudioChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* videoStatusChangedCall;
@property (nonatomic, retain) ZMMTAsyncCall<ZMUser*>* activeVideoChangedCall;
@property (nonatomic, retain) ZMMTAsyncCall<ZMUser*>* activeDeckVideoChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userJoinCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userLeftCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userNameChangedCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userAvatarChangedCall;
+ (instancetype)adapterWithSession:(ZMConfSession*)confSession;

- (void)registerPolicyObserver;

- (ZMUser*)userWithID:(ZMUserID)userID;

- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy user:(ZMUser*)zmUser;
- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy;

@end

@interface ZMConfBaseSinkAdapter (User)
- (BOOL)onUserStatusChanged:(USER_CMD)cmd userID:(CMM_USERID)userID;
- (BOOL)onBatchUserStatusChanged:(USER_CMD)cmd list:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (void)onMyRosterCompleted;

//for overwriting
- (BOOL)onUserStatusChanged:(USER_CMD)cmd user:(ZMUser*)zmUser userID:(CMM_USERID)userID;

- (BOOL)onAudioStatusChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onKBRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
@end

@interface ZMConfBaseSinkAdapter (ConfStatus)
- (void)onConfReady:(CmmUInt32)result;

- (BOOL)onConfStatusChanged:(const CONF_STATUS)eStatus;
- (BOOL)onConfStatusChanged:(CONF_CMD)cmd params:(CmmUInt32)ret;

#pragma mark -
- (void)onAudioObjCreated;
- (void)onVideoObjCreated;
- (void)onShareObjCreated;
- (void)onRecordObjCreated;
- (void)onLTTObjCreated;
@end

@interface ZMConfBaseSinkAdapter (Device)

- (BOOL)onDeviceStatusChanged:(DEVICE_CMD)cmd ret:(CmmUInt32)ret handle:(CmmUInt32)handle;
- (BOOL)showMyAudioLevel:(CmmUInt32)level handle:(CmmUInt32)handle isMic:(CmmBool)isMic;
- (BOOL)onVolumeChange:(CmmUInt32)vol isMic:(CmmBool)isMic;
- (void)onAudioDeviceSpecialInfoChange:(SSB_MC_DEVICE_SPECIAL_INFO)special_info deviceInfo:(CmmAudioDeviceBriefInfo)adbi;
- (void)onUltraSoundDetect_PairCode:(CmmBool)is_timeout code:(const CAString&)pair_code;
- (void)OnDeviceStatelessButtonDown:(const CString&)device_id;

#pragma mark - ICmmConfUIAPI
- (void)onMyVideoDeviceRunStarted:(void*)hWnd type:(CMM_MY_VIDEO_RUN_TYPE)eRunType device:(PMediaDevice)pDeviceInfo;
- (void)onMyCameraCaptureSizeRatioChanged:(const CString&)cameraID fWidth2Height:(float)fWidth2Height;
@end

@interface ZMConfBaseSinkAdapter (Share)

- (void)onShareCaptureStatusChanged:(SSB_MC_AS_SPECIAL_MSG)msg
                             reason:(SSB_MC_AS_CAPTURING_STATUS)reason
                               data:(DWORD)data;
- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                                  data:(DWORD)data;
- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                            renderView:(void *)renderView
                                  data:(DWORD)data;
- (void)onRemoteSupportRequestReceived:(CMM_USERID)nUserFrom
                               cmdType:(SUPPORT_CMD_TYPE)cmdType;
- (void)onRemoteSupportResponseReceived:(CMM_USERID)nUserFrom
                                cmdType:(SUPPORT_CMD_TYPE)cmdType
                              bApproved:(CmmBool)bApproved;
- (void)onOnRemoteSupportNotificationReceived:(CMM_USERID)nUserFrom
                                      cmdType:(SUPPORT_NOTIFICATION_TYPE)cmdType;
@end

@interface ZMConfBaseSinkAdapter (ClosedCaption)
- (BOOL)onClosedCaptionMessageReceived:(const CString&)msgID
                               content:(const CString&)content
                                  time:(const Cmm::CTime&)timer;
- (BOOL)onRealtimeClosedCaptionMessageReceived:(const CString&)content;
- (BOOL)onLiveTranscriptionClosedCaptionMessageReceived:(const CString&)msgID
                                                   type:(CmmClosedCaption::CCOperationType)type;
- (void)onStartLiveTranscriptRequestReceived:(CMM_USERID)nUserFrom bAnonymous:(CmmBool)bAnonymous;
@end

@interface ZMConfBaseSinkAdapter (VideoOrder)
- (void)onGalleryVideoOrderSaved:(BOOL)ret;
- (void)onGalleryVideoOrderLoaded:(const CString&)data;
@end

@interface ZMConfBaseSinkAdapter (Chat)
- (void)onChatMessageReceived:(const CString&)msgID;
- (void)onChatSendFile:(const CString&)msgID result:(CmmUInt32)result;
- (void)onChatFileProgress:(const CString&)msgID ratio:(CmmUInt32)ratio completeSize:(CmmUInt32)size speed:(CmmUInt32)bitPerSecond;
- (void)onChatFileStateChange:(const CString&)msgID;
- (void)OnChatShareFileInMeetingChat:(const ShareFileInMeetingChatParam_s&)shareFileInfo;
- (void)OnChatGetPublicDownloadLink:(const CString&)messageID result:(CmmUInt32)result;
- (void)OnChatMessageDeleted:(const CString&)msgId deleteBy:(CHAT_DELETE_BY)deleteBy;
@end

@interface ZMConfBaseSinkAdapter (Policy)
- (void)policyUpdated:(zpref::zPolicyId)policy;
@end

NS_ASSUME_NONNULL_END
