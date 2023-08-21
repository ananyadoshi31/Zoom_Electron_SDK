//
//  ZPShareSelectWindowModel.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>
#import <ZoomUnit/ZMCaptureModel.h>
#import <Zoomkit/zoom_client_conf.h>

@interface ZPShareSelectWindowModel : ZMCaptureModel

@property(assign)ZMShareSelectItemType sharingType;
@property(copy)NSString* toolTip;
@property(copy)NSString* disabledInfo;
@property(copy)NSString* documentPath;
@property(assign)NSUInteger winCount;
@property(copy)NSString* axTitle;
@property(copy)NSString* nativeToolTip;
@property(retain)NSArray<NSNumber *> *winIDsForPS;
@property(retain)NSDictionary<NSNumber *, NSString *> *moreMenus;
@property(assign)BOOL isZappModel;
@property(retain)NSDictionary* zappShareParam;
+ (id)modelWithCaptureModel:(ZMCaptureModel*)model;
- (id)initWithCaptureModel:(ZMCaptureModel*)model;
- (BOOL)isValid;
- (BOOL)isEqualToModel:(ZPShareSelectWindowModel *)model;
- (BOOL)isDesktopModel;
- (BOOL)isAsOrPsModel;
- (BOOL)isAsModel;
- (BOOL)isZoomAppsCollaborationModel; //add for collaborateMode
- (BOOL)isPsModel;
- (BOOL)isAudioModel;
- (BOOL)isVideoModel;
- (BOOL)isDocModel;
- (BOOL)isFrameModel;
+ (NSArray<ZPShareSelectWindowModel*>*)getScreensModelList;
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelList;
+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeList;
+ (ZPShareSelectWindowModel*)getEmptyScreenModel;
+ (ZPShareSelectWindowModel*)getIOSDevideModel;
+ (ZPShareSelectWindowModel*)getIOSWiredDeviceModel;
+ (ZPShareSelectWindowModel*)getModelWithFileStorageModel:(NSString *)name imageName:(NSString *)imageName shareType:(ZMShareSelectItemType)shareType;
+ (ZPShareSelectWindowModel*)getWhiteboardModel;
+ (ZPShareSelectWindowModel*)getCameraModel;
+ (ZPShareSelectWindowModel*)getFrameModel;
+ (ZPShareSelectWindowModel*)getSoundModel;
+ (ZPShareSelectWindowModel*)getDocModel;
+ (ZPShareSelectWindowModel*)getVideoModel;
@end
