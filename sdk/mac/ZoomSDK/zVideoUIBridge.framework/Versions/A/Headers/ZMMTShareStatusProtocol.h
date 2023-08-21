//
//  ZMMTShareStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/8/19.
//

#ifndef ZMMTShareStatusProtocol_h
#define ZMMTShareStatusProtocol_h

@protocol ZMMTShareStatusProtocol <NSObject>
@optional
- (void)userStartSharing:(ZMUser *)user;
- (void)userStopSharing:(ZMUser *)user;
- (void)onStartSendShare;
- (void)onStopSendShare;

@end



#endif /* ZMMTShareStatusProtocol_h */
