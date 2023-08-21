//
//  ZMMTStudioCanvas.h
//  zStudioUI
//
//  Created by geno.chen on 2021/6/2.
//

#import <Cocoa/Cocoa.h>

@class ZMMTStudioResource;
@class ZMMTStudioRender;
@class ZMMTStudioBizSession;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTStudioCanvas : NSObject
#ifdef __cplusplus
class IStudioCanvas;
@property (nonatomic, readonly, nullable) IStudioCanvas *studioCanvas;
#endif
@property (nonatomic, strong, readonly) ZMMTStudioBizSession *bizSession;
@property (nonatomic, copy, readonly) NSString *canvasID;
@property (nonatomic, weak, readonly) ZMMTStudioCanvas *superCanvas;
@property (nonatomic, assign) BOOL transparent;
@property (nonatomic, assign) NSRect frame;
@property (nonatomic, weak) NSColor *backgroundColor;
@property (nonatomic, assign, readonly) CGFloat aspectRatio;
@property (nonatomic, assign) int aspectMode; //SSB_MC_VIDEO_ASPECT_MODE
@property (nonatomic, assign) BOOL canMove;
@property (nonatomic, strong) NSMutableArray * _Nullable resources;
@property (nonatomic, strong) NSMutableArray * _Nullable subCanvases;
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, strong, nullable) id representedObject;
@property (nonatomic, assign) NSSize videoRatio;

- (instancetype)initWithCanvasID:(NSString *)canvasID superCanvas:(nullable ZMMTStudioCanvas *)superCanvas bizSession:(ZMMTStudioBizSession *)bizSession;

- (ZMMTStudioCanvas * _Nullable)createSubCanvasWithFrame:(NSRect)frame;
//- (ZMMTStudioCanvas * _Nullable)createShareSubCanvasWithFrame:(NSRect)frame;

- (void)destorySubCanvas:(ZMMTStudioCanvas *)subCanvas;
- (void)removeAllSubCanvas;

- (void)updateWithCanvas:(ZMMTStudioCanvas *)canvas;

- (void)addResource:(ZMMTStudioResource *)resource;
- (void)removeResource:(ZMMTStudioResource *)resource;
- (void)removeAllResource;

- (void)redraw;
- (void)moveUpper;
- (void)moveDown;
- (void)moveTop;
- (void)moveBottom;

- (ZMMTStudioCanvas * _Nullable)subCanvasWithTag:(NSInteger)tag;
- (nullable ZMMTStudioResource *)resourceWithTag:(NSInteger)tag;

@end

@interface ZMMTStudioRootCanvas : ZMMTStudioCanvas

@property (nonatomic, weak) NSView *view;
@property (nonatomic, assign, readonly) BOOL isAttachedToRender;
@property (nonatomic, assign, readonly) BOOL isPublishing;
- (instancetype)initWithFrame:(NSRect)frame bizSession:(ZMMTStudioBizSession *)bizSession;
- (ZMMTStudioCanvas *)hitTest:(NSPoint)point;
- (void)attachToRender:(ZMMTStudioRender *)render;
- (void)deAttachRender;
- (void)publish;
- (void)stopPublish;
- (void)start;
- (void)stop;

@end


NS_ASSUME_NONNULL_END
