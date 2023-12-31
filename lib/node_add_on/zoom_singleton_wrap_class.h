#ifndef _zoom_singleton_wrap_class_h_
#define _zoom_singleton_wrap_class_h_
#include "zoom_node_common_include.h"
#include "zoom_sdk_napi_util_exporter.h"

template<class T>
static void InitClassAttribute(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{}

template<class T>
static v8::Persistent<v8::Function>* GetConstructor(){
	return NULL;
}

template<class T>
class ZoomWrapObject : public node::ObjectWrap
{
public:
	static void Init(v8::Isolate* isolate)
	{
		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
		InitClassAttribute<T >(tpl, isolate);
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		(*GetConstructor<T >()).Reset(isolate, tpl->GetFunction(context).ToLocalChecked());
	}
	static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		const unsigned argc = 1;
		v8::Local<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> instance =
			cons->NewInstance(context, argc, argv).ToLocalChecked();

		args.GetReturnValue().Set(instance);
	}

	static void New(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();

		if (args.IsConstructCall()) {
			T* obj = new T();
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		}
		else {
			const int argc = 1;
			v8::Local<v8::Value> argv[argc] = { args[0] };
			v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
			v8::Local<v8::Object> instance =
				cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(instance);
		}
	}
	static v8::Local<v8::Object> GetNewInstance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		const unsigned argc = 1;
		v8::Local<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> instance =
			cons->NewInstance(context, argc, argv).ToLocalChecked();
		return instance;
	}
protected:
	ZoomWrapObject() {};
	~ZoomWrapObject() {};
};

class ZoomNodeSinkHelper
{
public:
	//auth_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAuthenticationReturn;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onLogout;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomIdentityExpired;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomAuthIdentityExpired;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onLoginReturnWithReason;

	//meeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onMeetingStatusChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onMeetingStatisticsWarningNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onMeetingParameterNotification;
	
	//premeeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onScheduleOrEditMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onListMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDeleteMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onGetInviteEmailContent;
	//meetingUI_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onInviteBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onStartShareBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onEndMeetingBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onParticipantListBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCustomLiveStreamMenuClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomInviteDialogFailed;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCCBTNClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAudioBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAudioMenuBtnClicked;

	//meeting_audio_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserAudioStatusChange;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserActiveAudioChange;

	//meeting_video_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserVideoStatusChange;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onActiveSpeakerVideoUserChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onActiveVideoUserChanged;
	
	//meeting_recording_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRecording2MP4Done;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRecording2MP4Processing;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRecordingStatus;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCloudRecordingStatus;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRecordPriviligeChanged;


	//meeting_share_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onSharingStatus;

	//meeting_participants_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserJoin;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserLeft;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onHostChangeNotification;

	//meeting_h323_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onH323CalloutStatusNotify;

	//meeting_config_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingNeedToUpgrade;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToGiftFreeTrialStart;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToGiftFreeTrialStop;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToProMeeting;

	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onInputMeetingPasswordAndScreenNameNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAirPlayInstructionWndNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onWebinarNeedRegisterNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onEndOtherMeetingToJoinMeetingNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingRemainTime;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingRemainTimeStopCountDown;
	

	//direct_share_helper_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > OnDirectShareStatusUpdate;

	//sdk_sms_helper_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onNeedRealNameAuthMeetingNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRetrieveSMSVerificationCodeResultNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onVerifySMSVerificationCodeResultNotification;

	//audio_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerMicDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerSpeakerDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultMicDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultSpeakerDeviceChanged;

	//video_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerCamDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultCamDeviceChanged;

	//recording_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCloudRecordingStorageInfo;

	//rawdata_render_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRawDataStatusChanged;

	//meeting_live_stream_controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onLiveStreamStatusChange;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRawLiveStreamPrivilegeChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserRawLiveStreamPrivilegeChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRawLiveStreamPrivilegeRequested;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserRawLiveStreamingStatusChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRawLiveStreamPrivilegeRequestTimeout;

	static ZoomNodeSinkHelper& GetInst()
	{
		static ZoomNodeSinkHelper inst;
		return inst;
	}

	void Reset()
	{
		onAuthenticationReturn.Reset();
		onLogout.Reset();
		onZoomIdentityExpired.Reset();
		onZoomAuthIdentityExpired.Reset();
		onMeetingStatusChanged.Reset();
		onMeetingStatisticsWarningNotification.Reset();
		onMeetingParameterNotification.Reset();

		onScheduleOrEditMeeting.Reset();
		onListMeeting.Reset();
		onDeleteMeeting.Reset();
		onInviteBtnClicked.Reset();
		onStartShareBtnClicked.Reset();
		onEndMeetingBtnClicked.Reset();
		onParticipantListBtnClicked.Reset();
		onCustomLiveStreamMenuClicked.Reset();
		onZoomInviteDialogFailed.Reset();
		onCCBTNClicked.Reset();
		onAudioBtnClicked.Reset();
		onAudioMenuBtnClicked.Reset();

		onUserAudioStatusChange.Reset();
		onUserActiveAudioChange.Reset();

		onUserVideoStatusChange.Reset();
		onActiveSpeakerVideoUserChanged.Reset();
		onActiveVideoUserChanged.Reset();

		onRecording2MP4Done.Reset();
		onRecording2MP4Processing.Reset();
		onRecordingStatus.Reset();
		onCloudRecordingStatus.Reset();
		onRecordPriviligeChanged.Reset();

		onSharingStatus.Reset();

		onUserJoin.Reset();
		onUserLeft.Reset();
		onHostChangeNotification.Reset();

		onH323CalloutStatusNotify.Reset();

		onFreeMeetingNeedToUpgrade.Reset();
		onFreeMeetingUpgradeToGiftFreeTrialStart.Reset();
		onFreeMeetingUpgradeToGiftFreeTrialStop.Reset();
		onFreeMeetingUpgradeToProMeeting.Reset();

		onInputMeetingPasswordAndScreenNameNotification.Reset();
		onAirPlayInstructionWndNotification.Reset();
		onWebinarNeedRegisterNotification.Reset();
		onEndOtherMeetingToJoinMeetingNotification.Reset();
		onFreeMeetingRemainTime.Reset();
		onFreeMeetingRemainTimeStopCountDown.Reset();


		OnDirectShareStatusUpdate.Reset();

		onNeedRealNameAuthMeetingNotification.Reset();
		onRetrieveSMSVerificationCodeResultNotification.Reset();
		onVerifySMSVerificationCodeResultNotification.Reset();

		onComputerMicDeviceChanged.Reset();
		onComputerSpeakerDeviceChanged.Reset();
		onDefaultMicDeviceChanged.Reset();
		onDefaultSpeakerDeviceChanged.Reset();

		onComputerCamDeviceChanged.Reset();
		onDefaultCamDeviceChanged.Reset();

		onCloudRecordingStorageInfo.Reset();
		onRawDataStatusChanged.Reset();

		onLoginReturnWithReason.Reset();
		onGetInviteEmailContent.Reset();

		onLiveStreamStatusChange.Reset();
		onRawLiveStreamPrivilegeChanged.Reset();
		onUserRawLiveStreamPrivilegeChanged.Reset();
		onRawLiveStreamPrivilegeRequested.Reset();
		onUserRawLiveStreamingStatusChanged.Reset();
		onRawLiveStreamPrivilegeRequestTimeout.Reset();
	}

	~ZoomNodeSinkHelper() {}
private:
	ZoomNodeSinkHelper() {}
};

///////////////////////////////////////////////////////////////////////////////

template<class T>
static bool SetProtoParam(const v8::FunctionCallbackInfo<v8::Value>& args, T& proto_param) {

	v8::Isolate* isolate_temp = args.GetIsolate();

	if (args.Length() < 1 ||
		!args[0]->IsUint8Array()
		)
	{
		return false;
	}
	if (!ZoomNodeAPIUtilHelper::GetInst().m_bInit)
	{
		if (!ZoomNodeAPIUtilHelper::GetInst().ExportNAPIUtilFunc())
		{
			return false;
		}
	}
	v8::Local<v8::Uint8Array> uint8array_temp_param = args[0].As<v8::Uint8Array>();

	size_t sz_temp_param = 0;
	char* char_temp_param = nullptr;
	fnGetRawBufferPtr pGetRawBufferPtr = NULL;
	pGetRawBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawBufferPtr;
	if (!pGetRawBufferPtr)
	{
		return false;
	}
	pGetRawBufferPtr(uint8array_temp_param, (void**)(&char_temp_param), sz_temp_param);
	if (!char_temp_param)
	{
		return false;
	}

	if (!proto_param.ParseFromArray(char_temp_param, sz_temp_param))
	{
		return false;
	}
	return true;
}
#endif // !_zoom_singleton_wrap_class_h_
