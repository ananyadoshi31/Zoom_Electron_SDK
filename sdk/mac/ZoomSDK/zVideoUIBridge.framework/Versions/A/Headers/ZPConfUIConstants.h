//
//  ZPConfUIConstants.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 1/19/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#ifndef SaasBeeConfUIModule_ZPConfUIConstants_h
#define SaasBeeConfUIModule_ZPConfUIConstants_h


typedef enum
{
    RENDER_ACTIVE,
    RENDER_MYSELF,
    RENDER_ATTENDEE,
    RENDER_FLOAT,
    RENDER_WALL
}RENDER_CONTAINER_TYPE;

typedef enum
{
	Video_Frame_Bk = 0,
	Video_Pic_Avatar,
	Video_SpeakerName,
	Video_Btn_Switch,
	Video_Icon_Mute,
    Video_WaterMark,
    Video_Quality,
    Video_Conf_Info,
    Video_Confidential_WaterMark,
    Video_Update_AllButtons,
    Video_SDK_WaterMark,//BUILD_FOR_CLIENT_SDK
    VIDEO_UNKNOWN,
}RENDER_PIC_LAYER;

typedef enum
{
	PT_NAV_HELP			= 0,
	PT_NAV_USER_PROFILE = 1,
	PT_NAV_FEEDBACK,
	PT_NAV_WEB_DOWNLOAD,
	PT_NAV_RECOMMEND,
    PT_NAV_USER_SPECIFIED,
	PT_NAV_SIGNUP,
	PT_NAV_FORGOTPASSWORD,
	PT_NAV_ACCOUNT_MGR,
	PT_NAV_SSO_LOGOUT,
	PT_NAV_ZOOM_TERMS,
	PT_NAV_CONTACT_ADMIN,
    PT_NAV_INTERNATIONAL_CALLIN,
    PT_NAV_EDITWEBINAR,
	PT_NAV_INVITE_EMAIL_CONTACTS,
	PT_NAV_INVITE_GMAIL_CONTACTS,
}PT_NAVWEB_TYPE;

typedef enum {
    ZMVideo_Layout_Customized_None = 0,
    ZMVideo_Layout_Customized_Horizontal,
    ZMVideo_Layout_Customized_Vertical
}ZMVideo_Layout_Customized_Type;

typedef enum {
    ZMConfAudioNotConnect,
    ZMConfAudioConnecting,
    ZMConfAudioConnectSuccess,
    ZMConfAudioConnectFail
} ZMConfAudioConnectStatus;

#define kZoomPTLoginNotEntitled @"1111"
#define kZoomPTLoginNotRegistered @"1112"
#define kZoomPTLoginBBMURL @"http://www.blackberry.com/bbmmeetings"

#endif
