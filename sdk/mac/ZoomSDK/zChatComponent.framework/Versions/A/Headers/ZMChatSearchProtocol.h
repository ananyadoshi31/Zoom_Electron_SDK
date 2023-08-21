//
//  ZMChatSearchProtocol.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/8/5.
//

#ifndef ZMChatSearchProtocol_h
#define ZMChatSearchProtocol_h

#import <ZoomKit/ZMCallbackImpl.h>
#import <zChatComponent/ZMIMCommonDefine.h>

@class ZMSearchBuddyParam;
@class ZMSessionGroupAdapter;

@protocol ZMChatSearchProtocol <NSObject>

@optional

- (nullable NSString *)asyn_searchLocalContactsByKey:(nonnull NSString *)key fliter:(ZMLoacalContactSearchFilter)fliter callBack:(nonnull ZMCallbackBlock)callBack;

- (nullable NSString *)searchRemoteBuddy_V2:(nonnull NSString *)key searchParam:(nullable ZMSearchBuddyParam *)searchParam callBack:(nonnull ZMCallbackBlock)callBack;

//if key is empty,will get recent groups
- (nullable NSArray <ZMSessionGroupAdapter *> *)searchGroupByKey:(nullable NSString *)key;

- (void)removeContactsSearch:(nonnull NSString *)key;


- (BOOL)searchChannelMember:(nonnull NSString *)channelId keyword:(nonnull NSString *)keyword callBack:(void(^)(NSString *key, NSArray <ZMSearchResultItem *> * items, NSError *error))callBack;

- (void)didSearchChannelMember:(NSInteger)result searchResponse:(const ns_zoom_messager::ChannelMemberSearchResponse &)searchResponse reqId:(nullable NSString *)reqId;


- (BOOL)searchChannelByKeyword:(nullable NSString *)keyword callBack:(void(^)(NSString *key,NSArray <ZMSearchResultItem *> * items,NSError *error))callBack;

- (void)didSearchChannelByKeyword:(nullable NSString *)keyword result:(NSInteger)result searchResponse:(const NS_ZOOM_MESSAGER::ChannelSearchResponse&)response reqId:(NSString *)reqId;

//ZOOM-423027
- (BOOL)queryIfUsersInChannelRequest:(nonnull NSString *)channelId jids:(nonnull NSArray<NSString*> *)jidArray callBack:(void(^)(NSString *key,NSArray <NSString *> * jidArray,NSError *error))callBack;
- (void)didQueryIfUsersInChannelRequest:(nonnull NSString *)reqId result:(NSInteger)result jids:(nonnull NSArray<NSString*> *)jidArray;
@end


#ifndef ZMShareChatSearchProtocol
#define ZMShareChatSearchProtocol (id <ZMChatSearchProtocol>)ZMSharedFor(ZMChatSearchProtocol)
#endif


#endif /* ZMChatSearchProtocol_h */
