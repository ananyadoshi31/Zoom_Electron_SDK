//
//  ZMIMDataInfo.h
//  zChatUI
//
//  Created by likevin on 2019/5/18.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "dataModule/zDataConstants.h"

@interface ZMOnZoomOpenChatOption : NSObject
@property (assign)  NSInteger      viewMode; // 0 - docking; 1 - floating
@property (assign)  BOOL           canShowTitleBar;
@property (assign)  BOOL           canShowInfoPanel;
@property (assign)  BOOL           canShowInputToolbar;

+ (ZMOnZoomOpenChatOption*)createZMOnZoomOpenChatOption:(void*)sdkChatOption;
@end


typedef NS_ENUM(NSInteger, ZMReportTag){
	
	ZMReportTag_ReportUser = 1,
	ZMReportTag_RemoveChatMsg,
	ZMReportTagTag_ReportRemoveUserAndMsg,
};

@interface ZMReportInChannelCommonInfo : NSObject
@property (assign)  ZMReportTag             reportTag;
@property (assign)  BOOL                    isAdmin;
@property (assign)	ReportInChannelAction   reportAction;
@property (assign)	RemoveInChannelAction   removeAction;
@property (assign)	ReportInChannelType     reportType;
@property (copy)    NSString*      channelID;
@property (copy)    NSString*      msgID;
@property (copy)    NSString*      reportedUserName; //  only enabled in ui callback
@property (retain)  NSArray<NSImage*> * sourceImageArray; //screenshot
@property (copy)    NSArray<NSString*> * imagePathArray;
@property (assign)  BOOL                    is1v1ZoomEventChannel;
- (void)processLongUserName;
@end

@interface ZMReportInChannelRes : NSObject
@property (assign)  NSInteger      result;
@property (retain)  ZMReportInChannelCommonInfo* commonInfo;
@property (assign)  ReportInChannelErrorType  errorType;
+ (ZMReportInChannelRes*)createZMReportInChannelRes:(void*)sdkReportInChannelRes NS_RETURNS_RETAINED;
@end

@interface ZMPreviewGroupInfo : NSObject
@property (copy)    NSString*      reqId;
@property (assign)  NSInteger      result;
@property (copy)    NSString*      groupId;
@property (copy)    NSString*      groupName;
@property (copy)    NSString*      groupDesc;
@property (assign)  NSInteger      totalMemberCount;
@property (assign)  NSInteger      roomFlags;

@property (retain)  NSArray* memberArray;

+ (ZMPreviewGroupInfo*)createZMPreviewGroupInfo:(void*)sdkPreviewGroupInfo NS_RETURNS_RETAINED;
@end

@interface ZMOutdatedLocalFileInfo : NSObject
@property (assign)  NSInteger      type;
@property (copy)    NSString*      fileId;
@property (copy)    NSString*      path;
@property (copy)    NSString*      originalPath;
@property (copy)    NSString*      previewPath;
@property (retain)    NSArray<NSString*>*      tmpPathArray;
+ (ZMOutdatedLocalFileInfo*)createZMOutdatedLocalFileInfo:(void*)sdkOutdatedLocalFileInfo NS_RETURNS_RETAINED;
@end


/*@interface ZMWBPreviewInfo: NSObject
@property (assign)  NSInteger      fileIndex;
@property (copy)    NSString*      fileId;
@property (copy)    NSString*      title;
@property (copy)    NSString*      link;
@property (copy)    NSString*      fileName;
@property (assign)  NSInteger      fileSize;
@property (assign)  NSSize         imageSize;
@property (assign)  BOOL           hasAccess;

+ (ZMWBPreviewInfo*)createZMWBPreviewInfo:(void*)pTmpSdkWBPreviewInfo;
@end*/


@interface ZMChannelMemberSearchFilter : NSObject

@property (copy)    NSString*      channelId;
@property (copy)    NSString*      keyWord;
@property (assign)  NSUInteger      pageNum;
@property (assign)  NSUInteger      maxSize;

@end


