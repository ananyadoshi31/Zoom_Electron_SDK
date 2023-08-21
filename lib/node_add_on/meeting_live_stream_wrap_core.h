#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingLiveStreamWrap
{
public:
	ZMeetingLiveStreamWrap();
	virtual ~ZMeetingLiveStreamWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingLiveStreamWrapSink* pSink);

	ZNSDKError CanStartLiveStream();
	ZNSDKError StartLiveStream(int64_t liveStreamHandle);
	ZNSDKError StartLiveStreamWithSteamingURL(ZoomSTRING streamingURL, ZoomSTRING streamingKey, ZoomSTRING broadcastURL);
	ZNSDKError StopLiveStream();
	ZNList<int64_t> GetSupportLiveStreamItems();
	ZNLiveStreamStatus GetCurrentLiveStreamStatus();
	ZNSDKError StartRawLiveStream(ZoomSTRING broadcastURL);
	ZNSDKError StopRawLiveStream();
	ZNLiveStreamItemInfo GetLiveStreamItemInfo(int64_t liveStreamHandle);
	bool IsRawLiveStreamSupported();
	ZNSDKError CanStartRawLiveStream();
	ZNSDKError RequestRawLiveStream(ZoomSTRING broadcastURL);
	ZNSDKError RemoveRawLiveStreamPrivilege(unsigned int userid);
	ZNList<ZNRawLiveStreamInfo> GetRawLiveStreamingInfoList();
	ZNList<unsigned int> GetRawLiveStreamPrivilegeUserList();
	

	//callback
	void onLiveStreamStatusChange(ZNLiveStreamStatus status);
	void onRawLiveStreamPrivilegeChanged(bool bHasPrivilege);
	void onUserRawLiveStreamPrivilegeChanged(unsigned int userid, bool bHasPrivilege);
	void onRawLiveStreamPrivilegeRequested();
	void onUserRawLiveStreamingStatusChanged(ZNList<ZNRawLiveStreamInfo> pLivingList);
	void onRawLiveStreamPrivilegeRequestTimeout();


private:
	bool isValidItem(int64_t liveStreamHandle);
	ZNativeSDKMeetingLiveStreamWrapSink* m_pSink;
	ZNList<int64_t> m_live_stream_items_list;
};

class ZRequestRawLiveStreamPrivilegeHandlerWrap
{
public:
	ZRequestRawLiveStreamPrivilegeHandlerWrap();
	virtual ~ZRequestRawLiveStreamPrivilegeHandlerWrap();

	ZoomSTRING GetRequestId();
	unsigned int GetRequesterId();
	ZoomSTRING GetRequesterName();
	ZoomSTRING GetBroadcastUrl();
	ZNSDKError GrantRawLiveStreamPrivilege();
	ZNSDKError DenyRawLiveStreamPrivilege();
};
