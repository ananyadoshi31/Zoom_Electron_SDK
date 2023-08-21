//
//  ZMChatAppsManager.h
//  zChatComponent
//
//  Created by Yong Zhou on 9/7/22.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMChatAppsEntity.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChatAppsManager : NSObject

@property (nonatomic, retain, readonly) NSArray<ZMChatAppInfo*> *chatAppComposeShortcuts;
@property (nonatomic, retain, readonly) NSArray<ZMChatAppShortcutInfo*> *chatMessageShortcuts;
@property (nonatomic,copy) void (^composeShortcutUpdated)(void);

+ (instancetype)sharedInstance;

- (void)onComposeShortcutUpdated;

- (void)onMessageShortcutUpdated;

+ (void)releaseInstance;

@end

NS_ASSUME_NONNULL_END
