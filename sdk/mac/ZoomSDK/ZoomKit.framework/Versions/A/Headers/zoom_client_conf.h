#pragma once

#ifndef ZOOM_CLIENT_CONFIGURATION_H_
#define ZOOM_CLIENT_CONFIGURATION_H_

//#define BUILD_FOR_ZOOM_CHINESE
// #define BUILD_FOR_MIMO
//#define BUILD_FOR_RINGCENTRAL
//#define BUILD_FOR_BT
//#define BUILD_FOR_TELUS
//#define BUILD_FOR_ATT
//#define BUILD_FOR_BBM
//#define  BUILD_FOR_BROADVIEW
//#define BUILD_FOR_BBM
//#define BUILD_FOR_BSC
//#define BUILD_FOR_ZOOM
//#define BUILD_FOR_BIZCONF
//#define BUILD_FOR_ZHUMU
//#define BUILD_FOR_ZHUMU

// #ifndef ANDROID
#include "buildtime_client_config.h"
// #endif
#ifndef  BUILD_FOR_CLIENT_SDK
//temp solution for Zoom Apps, currently only support in Mac/Win. ENABLE_ZAPP will be removed in future. // 1/12/2021

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_ZOOMAPP
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_ZOOMAPP
#endif

#if (((defined WIN_ZOOMAPP) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZAPP) || (defined __IOS__) ) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER))
#ifndef ENABLE_ZAPP
    #define ENABLE_ZAPP
#endif
#endif

#ifndef ENABLE_ZAPP
#ifdef BUILD_FOR_MIMO
#   define ENABLE_ZAPP
#endif
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_CCI
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_CCI
#endif

#if (((defined WIN_CCI) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
   #define ENABLE_ZOOM_CCI
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_SIMULIVE_FROM_LOBBY
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_SIMULIVE_FROM_LOBBY
#endif

#if (((defined WIN_SIMULIVE_FROM_LOBBY) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
#define ENABLE_ZOOM_SIMULIVE_FROM_LOBBY
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined (_M_ARM64) )
#   define WIN_BOOKINGS
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined (_M_ARM64) )
#   define WIN_BOOKINGS
#endif

#if ((defined WIN_BOOKINGS) || (defined __MACOS__) || (defined (__LINUX_CLIENT__)))
   #define ENABLE_ZOOM_BOOKINGS
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined (_M_ARM64) )
#   define WIN_Calendar
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined (_M_ARM64) )
#   define WIN_Calendar
#endif

#if (((defined WIN_Calendar) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZCALENDAR) || (defined __IOS__)) && (!defined BUILD_FOR_MIMO))
#define ENABLE_ZOOM_CALENDAR
#endif

#if defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 )
#   define WIN_MailClient
#elif defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 )
#   define WIN_MailClient
#endif

#if (((defined WIN_MailClient) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZMAIL) || (defined __IOS__)) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER))
   #define ENABLE_MAILCLIENT_SERVICE
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_ZOOM_CHAT_JS
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_ZOOM_CHAT_JS
#endif

#if (((defined WIN_ZOOM_CHAT_JS) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
	#define ENABLE_ZOOM_CHAT_JS
#endif

#endif //BUILD_FOR_CLIENT_SDK

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK) && !defined(BUILD_FOR_ZPCONTROLLER)
#define ZOOM_MESH_ENABLE
#endif

#if (defined __IOS__) || (defined CMM_ANDROID)
#define ENABLE_SEND_TS_LOG_FROM_MOBILE_CLIENT
#endif // ZOOM-438924

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64) || defined(_M_ARM64)
#define ENABLE_ZOOM_DIAGNOSTIC
#elif defined(__MACOS__)
#define ENABLE_ZOOM_DIAGNOSTIC
#endif
#endif

#endif //ZOOM_CLIENT_CONFIGURATION_H_
