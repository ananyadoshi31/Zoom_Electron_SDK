//
//  ZMPTAppProtocol.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/20.
//

#ifndef ZMPTAppProtocol_h
#define ZMPTAppProtocol_h

#include "zChatApp/SaasBeePTAppInterface.h"

@protocol ZMPTAppProtocol <NSObject>

- (ISBPTAppAPI *)getPTAppApi;

@end

#ifndef ZMSharePTAppProtocol
#define ZMSharePTAppProtocol (id <ZMPTAppProtocol>)ZMSharedFor(ZMPTAppProtocol)
#endif

#endif /* ZMPTAppProtocol_h */
