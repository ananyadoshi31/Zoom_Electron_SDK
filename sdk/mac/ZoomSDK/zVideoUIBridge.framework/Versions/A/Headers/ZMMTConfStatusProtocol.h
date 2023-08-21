//
//  ZMMTConfStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/8/15.
//

#ifndef ZMMTConfStatusProtocol_h
#define ZMMTConfStatusProtocol_h


@protocol ZMMTConfStatusProtocol <NSObject>
@optional
- (void)onPSSceneFetchResult:(BOOL)result;
- (void)onPSProducerChanged;
- (void)onPSProducerLiving;
- (void)onPSProducerWillLived:(NSUInteger)context;
- (void)onPSPublishSceneChanged;
- (void)onAvatarPermissionChanged;

@end


#endif /* ZMMTConfStatusProtocol_h */
