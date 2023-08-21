//
//  ZMMTStudioBizSession.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
class IStudioCanvasMgr;
class IStudioVideoRenderMgr;
#endif

typedef NS_ENUM(NSInteger, ZMMTStudioBizSessionType) {
    ZMMTStudioBizSessionTypeMeeting
};

@interface ZMMTStudioBizSession : NSObject

@property (nonatomic, class, readonly) ZMMTStudioBizSession *meetingSession;

@property (nonatomic, readonly) ZMMTStudioBizSessionType sessionType;
- (instancetype)initWithSessionType:(ZMMTStudioBizSessionType)sessionType;

#ifdef __cplusplus
@property (nonatomic, assign, nullable, readonly) IStudioCanvasMgr *canvasMgr;
@property (nonatomic, assign, nullable, readonly) IStudioVideoRenderMgr *videoRenderMgr;
#endif

@end

NS_ASSUME_NONNULL_END
