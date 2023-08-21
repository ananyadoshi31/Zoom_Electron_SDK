//
//  ZMFileEntity.h
//  ZCommonUI
//
//  Created by Yong Zhou on 9/3/20.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMFileConstants.h>

@class ZMFileCallbackParam;
@class ZMChatAppMessagePreviewInfo;

@interface ZMFileEntity : NSObject

@property (nonatomic, assign) ZMFileSourceType fileSourceType;
@property (nonatomic, assign) FileShareType    fileShareType;
@property (nonatomic, assign) ZMThirdPartyFileType   thirdPartyFileType;
@property (nonatomic, copy) NSString *webID;
@property (nonatomic, copy) NSString *owner;
@property (nonatomic, copy) NSString *modifier;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *messageID;
@property (nonatomic, copy) NSString *filePath;
@property (nonatomic, copy) NSString *parrentID;
@property (nonatomic, copy) NSString *previewPath;
@property (nonatomic, copy) NSString *videoPreviewPath;
@property (nonatomic, assign) NSSize videoPreviewSize;
@property (nonatomic, assign) BOOL isPlayableVideo;
@property (nonatomic, copy) NSString *fileURL;
@property (nonatomic, assign) unsigned long long fileSize;

@property (assign) BOOL isWhiteboardPreview;
@property (assign) BOOL hasWhiteboardPreviewAccess;
@property (copy) NSString *whiteboardPreviewTitle;
@property (copy) NSString *whiteboardPreviewLink;

@property (nonatomic,assign) NSUInteger fileType;

/** Mark for file type in hybrid-message */
@property (nonatomic, assign) ZMHybridFileStyle style;
/*
 positionIndex: the index of each image or file in a hybrid-message.
 Sending hybrid-message => positionIndex = text.length+image/file.index;
 Receiving message      => sort files/images with "positionIndex" and display them.
 Attention: [Do not change it! If must, search @"positionIndex" in global and replace it also.]
 */
@property (nonatomic, assign) NSUInteger positionIndex;
@property (nonatomic, assign) long long fileTransferdSize;
@property (nonatomic, assign) ZMChatSendFileStatus fileState;
@property (nonatomic, assign) ZMFileStorageSource fileStorageSource;
@property (nonatomic, assign) BOOL supportFTResume;


@property (nonatomic,retain) NSDate* date;


@property (nonatomic, readonly) BOOL isFileExisted;
@property (nonatomic, readonly) BOOL isPreviewFileExisted;
@property (nonatomic, readonly) BOOL isLocal3rdPartFile;
@property (nonatomic, readonly) BOOL is3rdPartFile;
@property (nonatomic,assign) BOOL isSharePoint;

@property (nonatomic, assign, readonly) BOOL isHybridImageType;
@property (nonatomic, assign, readonly) BOOL isHybridItem;

@property (nonatomic, assign) ZMFTPermissionType downloadPermission;
@property (nonatomic, assign) ZMFileScopeType fileScope;
@property (nonatomic, readonly, assign) BOOL isDisabledFile;
/* async blocked file */
@property (nonatomic, assign) ZMFTPermissionType asyncFTPermission;

/* For "saved emoji" and "Giyph", need to be sent as image in Hybrid-Message **/
@property (nonatomic, assign) ZMEmojiType emojiType;
/* emojiData can be accessed in ChatUI */
@property (nonatomic, retain) id emojiData;

/********************************* Image Only Begin ********************************/
/**
 include (.png .jpg .gif. screenshot)
 */
@property (nonatomic, assign) BOOL isScreenShot;
@property (nonatomic, assign) NSSize imageSize;
@property (nonatomic, assign) BOOL imageDownloadFailed;
@property (nonatomic, assign) BOOL isDownloadPreview;

@property (nonatomic, assign) BOOL isGiphy;
@property (nonatomic, assign) BOOL isMeetingCardFile;
@property (nonatomic, copy) NSString *giphyId;
@property (nonatomic, assign) BOOL isPaused;

/// Giphy or other GIF image
@property (nonatomic, assign) BOOL isGIF;

// For SMS hold a obj
@property (nonatomic, retain) id holdObj;

/********************************* Image Only End ********************************/
@property (nonatomic, copy) NSString* sharepointPreviewURL;
@property (copy) NSString* locationLink;
@property (nonatomic, copy, getter=getFileIntegrationSharePreviewURL) NSString *fileIntegrationSharePreviewURL;

/* If FileShareType != FileShareType_Disabled, will return @"" **/
@property (nonatomic, copy) NSString *disabledFileDesp;

/* chat app card */
@property (nonatomic, assign) BOOL isChatAppCard;
@property (nonatomic, retain) ZMChatAppMessagePreviewInfo *chatAppInfo;

/*bot file*/
@property (nonatomic, assign) BOOL isMarkdownFile;

- (BOOL)isCurFileCallBack:(ZMFileCallbackParam *)param;
- (NSImage*)thirdPartyFileIcon;
- (BOOL)is3rdNote;

@end


@interface ZMUploadFileEntity : NSObject

@property (nonatomic, copy) NSString* filePath;
@property (nonatomic, copy) NSString* sessionID;
@property (nonatomic, copy) NSString* nodeID;
@property (nonatomic, copy) NSString* requestID;
@property (nonatomic, assign) NSInteger ratio;
@property (nonatomic, assign) NSInteger completeSize;
@property (nonatomic, assign) NSInteger bitPerSecond;
@property (nonatomic, assign) NSInteger errorID;

@end
