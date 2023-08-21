//
//  ZMMTStudioResource.h
//  zStudioUI
//
//  Created by geno.chen on 2021/5/26.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTStudioDefine.h>
@class PSCanvas;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTStudioResourcePosition) {
    ZMMTStudioResourcePosition_BG = 0,
    ZMMTStudioResourcePosition_FG,
    ZMMTStudioResourcePosition_TOP,
};


@interface ZMMTStudioResource : NSObject <NSCopying>
- (instancetype)initWithResourceID:(NSString *)resourceID;
@property (nonatomic, copy) NSString *resourceID;
@property (nonatomic, weak) PSCanvas *canvas;
@property (nonatomic, assign) NSInteger tag;

@end

@interface ZMMTStudioMeetingVideoResource : ZMMTStudioResource

@property (nonatomic, assign) NSUInteger userID;
@property (nonatomic, assign, readonly) BOOL isVideoRunning;
- (BOOL)run;
- (void)stop;

@end

@interface ZMMTStudioMeetingShareResource : ZMMTStudioResource

@property (nonatomic, assign) NSUInteger userID;
@property (nonatomic, assign, readonly) BOOL isVideoRunning;
- (BOOL)run;
- (void)stop;

@end


@interface ZMMTStudioImageResource : ZMMTStudioResource

@property (nonatomic, copy, nullable) NSString *path;
@property (nonatomic, assign) NSRect frame;
@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, assign) ZMMTStudioResourcePosition position;
@property (nonatomic, assign) StudioResourceAspectMode aspectMode;

@end

@interface ZMMTStudioMemoryImageResource : ZMMTStudioResource

@property (nonatomic, strong, nullable) NSBitmapImageRep *imageRep;
@property (nonatomic, assign) NSRect frame;
@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, assign) ZMMTStudioResourcePosition position;
@property (nonatomic, assign) StudioResourceAspectMode aspectMode;

@end


@interface ZMMTStudioTextResource : ZMMTStudioResource

@property (nonatomic, copy, nullable) NSAttributedString *string;

@end

NS_ASSUME_NONNULL_END
