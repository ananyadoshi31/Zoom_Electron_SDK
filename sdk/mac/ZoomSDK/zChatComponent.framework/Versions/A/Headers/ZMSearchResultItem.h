
//
//  ZMSearchResultItem.h
//  zChatUI
//
//  Created by groot.ding on 2018/7/9.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ZMSearchResultNone,
    ZMSearchResultCustomSession,
    ZMSearchResultContacts,
    ZMSearchResultChannel,
    ZMSearchResultMessage,
    ZMSearchResultFile,
    ZMSearchResultImageFile,
    ZMSearchResultCloudContact,
	ZMSearchResultMUC,
	ZMSearchResultBot,
    ZMSearchResultPublicChannel,
    ZMSearchResultSMSContact,
    ZMSearchResultSMSSession,
    ZMSearchResultSMSMessage,
} ZMSearchResultType;

@interface ZMSearchResultItem : NSObject

@property (nonatomic,assign) ZMSearchResultType resultType;

@property (nonatomic,retain) id resultData;

@property (nonatomic,copy) NSString *searchKey;

@end
