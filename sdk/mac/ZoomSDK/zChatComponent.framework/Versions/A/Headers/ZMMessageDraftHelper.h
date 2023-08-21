//
//  ZMMessageDraftHelper.h
//  zChatUI
//
//  Created by kevin.li on 10/10/19.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMIMCommonDefine.h>

@class ZMIMMessageDraft;
@class ZMFileEntity;

typedef void(^ZMDraftDeletionCompletionHandler)(NSString * _Nonnull sessionID, NSString * _Nullable threadID, BOOL isPlatformEvent);
typedef void(^ZMDraftAdditionCompletionHandler)(NSString * _Nonnull sessionID, NSString * _Nullable threadID, BOOL isPlatformEvent);
typedef void(^ZMDraftConnectionStateCompletionHandler)(NSInteger err);
typedef void(^ZMDraftCountUpdateCompletionHandler)();

@protocol ZMMessageDraftProtocol <NSObject>

+ (BOOL)isDraftsTabEnabled;
- (NSUInteger)draftCount;

- (nonnull NSArray<ZMIMMessageDraft *> *)getAllDrafts;

- (nonnull NSArray<ZMIMMessageDraft *> *)draftsForSession:(nonnull NSString *)sessionID;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)setActiveDraft:(nullable ZMIMMessageDraft *)draft forSession:(nonnull NSString *)sessionID;
- (BOOL)setActiveDraft:(nullable ZMIMMessageDraft *)draft forSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID;
- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)saveActiveDraft:(nonnull ZMIMMessageDraft *)draft;
- (BOOL)saveActiveDraft:(nullable NSString *)draft sessionID:(nonnull NSString *)sessionID fontStyleInfo:(nullable NSArray *)fontStyleList fileList:(nullable NSArray *)fileList;
- (BOOL)saveActiveDraft:(nullable NSString *)draft sessionID:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID threadServerTime:(unsigned long long)threadServerTime fontStyleInfo:(nullable NSArray *)fontStyleList fileList:(nullable NSArray *)fileList;

-(BOOL)eraseActiveDraftForSession:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID;

- (BOOL)eraseDraft:(nonnull NSString *)draftID inSession:(nonnull NSString *)sessionID andThread:(nullable NSString *)threadID;

- (void)addDraftDeletionListener:(nonnull id)target completion:(nonnull ZMDraftDeletionCompletionHandler)completionHandler;
- (void)removeDraftDeletionListener:(nonnull id)target;

- (void)addDraftAdditionListener:(nonnull id)target completion:(nonnull ZMDraftAdditionCompletionHandler)completionHandler;
- (void)removeDraftAdditionListener:(nonnull id)target;

- (void)addConnectionStateListener:(nonnull id)target completion:(nonnull ZMDraftConnectionStateCompletionHandler)completionHandler;
- (void)removeConnectionStateListener:(nonnull id)target;

- (void)addDraftCountUpdateListener:(nonnull id)target completion:(nonnull ZMDraftCountUpdateCompletionHandler)completionHandler;
- (void)removeDraftCountUpdateListener:(nonnull id)target;

- (void)onConnectionStateChange:(int)err;

@end


@interface ZMIMMessageDraft : NSObject

@property (nonatomic, copy, nullable)   NSString *draft;
@property (nonatomic, retain, nullable) NSArray<ZMFileEntity*> *fileList;
@property (nonatomic, copy, nullable)   NSArray<ZMMessageFontInfo*>  *fontStyleInfoList;
@property (nonatomic, assign) int64_t createdTime;
@property (nonatomic, assign) int64_t lastEditedTime;
@property (nonatomic, retain, nonnull)  NSString *sessionID;
@property (nonatomic, retain, nullable) NSString *threadID;
@property (nonatomic, assign) int64_t threadServerTime;

@property (nonatomic, retain, nonnull) NSString  *draftID;
@property (assign) BOOL isActive;

/* Draft display format, like "Hello. (x Files)", "Hello*********..." */
@property (nonatomic, readonly, copy, nullable) NSString *draftDesp;

- (BOOL)hasDraft;

- (nullable NSString *)plaintextDraft;

- (nonnull NSString *)getRecipientName;

@end

@interface ZMMessageDraftHelper : NSObject <ZMMessageDraftProtocol>

+ (instancetype _Nonnull)sharedInstance;

+ (NSString * _Nonnull)jsonDraftMessage:(NSAttributedString * _Nonnull)attributedString;
+ (NSAttributedString * _Nullable)attributedStringFromJsonDraft:(NSString * _Nonnull)jsonDraft;

+ (BOOL)hasReplyDraftWithChannelID:(NSString * _Nonnull)channelID threadID:(NSString * _Nullable)threadID;

+ (NSString * _Nullable)fetchMessageWithSaveString:(NSString * _Nonnull)saveStr;

@end
