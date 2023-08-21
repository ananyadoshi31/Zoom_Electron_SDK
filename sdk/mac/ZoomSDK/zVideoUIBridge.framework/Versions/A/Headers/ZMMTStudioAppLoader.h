//
//  ZMMTStudioAppLoader.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <zStudioApp/IStudioApp.h>

@interface ZMMTStudioAppLoader : NSObject

@property (nonatomic, assign, readonly) IStudioApp *studioApp;
@property (nonatomic, assign, readonly) IStudioResrouceFactory *resourceFactory;
@property (nonatomic, assign, readonly) IStudioMeetingMgr *meetingMgr;

+ (instancetype)shared;

- (void)loadStudioApp;
- (void)unloadStudioApp;

@end

