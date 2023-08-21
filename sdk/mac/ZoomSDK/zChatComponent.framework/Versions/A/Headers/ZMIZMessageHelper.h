//
//  ZMIZMessageHelper.h
//  ChatUI
//
//  Created by Groot Ding on 2022/5/18.
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef ZMIZMessageHelper_h
#define ZMIZMessageHelper_h

#import <Foundation/Foundation.h>
#include <zChatApp/SaasBeePTAppInterface.h>

extern BOOL __attribute__((noinline)) IsZoomMeetChannelID (NSString * _Nonnull sessionId);

extern ISBPTAppAPI * _Nullable __attribute__((noinline)) GetMeetingPTAppAPI(void);

extern ISBPTAppAPI * _Nullable __attribute__((noinline)) GetPTAppAPIBySessionId (NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessenger * _Nullable __attribute__((noinline)) GetIMMessenger(void);

extern NS_ZOOM_MESSAGER::IZoomMessenger * _Nullable __attribute__((noinline)) GetIZMessengerBySessionId (NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::ThreadDataProvider * _Nullable __attribute__((noinline)) GetThreadDataProviderBySessionId (NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomChatSession * _Nullable __attribute__((noinline)) GetIZSessionById (NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::IZoomGroup * _Nullable __attribute__((noinline)) GetIZGroupById (NSString * _Nonnull groupId);

extern NS_ZOOM_MESSAGER::IZoomBuddy * _Nullable __attribute__((noinline)) GetIZoomBuddy (NSString * _Nonnull jid,NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) GetIZoomMessage (NSString * _Nonnull messageId,NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) GetIZoomMessage (unsigned long long svrSideTime,NSString * _Nonnull sessionId,BOOL useDB);

extern NS_ZOOM_MESSAGER::FileContentMgr * _Nullable __attribute__((noinline)) GetFileContentMgr(void);

extern NS_ZOOM_MESSAGER::FileContentMgr * _Nullable __attribute__((noinline)) GetFileContentMgrBySessoinId(NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IMessageTemplate * _Nullable __attribute__((noinline)) GetMessageTemplate(NSString * _Nullable messageId, NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IMessageTemplate * _Nullable __attribute__((noinline)) GetMessageTemplateWithIndex(NSString * _Nullable messageId, NSString * _Nullable sessionId, int index);

extern NS_ZOOM_MESSAGER::ISearchMgr * _Nullable __attribute__((noinline)) GetISearchMgr(void);

extern zoom_sipcall_app::ISIPCallAPI * _Nullable __attribute__((noinline)) GetSipCallAPI(void);

#endif /* ZMIZMessageHelper_h */
