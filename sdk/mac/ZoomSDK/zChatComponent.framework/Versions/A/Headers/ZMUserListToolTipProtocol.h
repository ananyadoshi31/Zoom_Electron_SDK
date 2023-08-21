//
//  ZMUserListToolTipProtocol.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/7/16.
//

#ifndef ZMUserListToolTipProtocol_h
#define ZMUserListToolTipProtocol_h

@class ZMUserInfo;
@protocol ZMUserListToolTipProtocol <NSObject>

- (void)showToolTipWithUserList:(NSArray <ZMUserInfo *> * _Nonnull)userLists ofView:(NSView * _Nonnull)positioningView;

- (void)showToolTipWithUserList:(NSArray <ZMUserInfo *> * _Nonnull)userLists ignoreUserList:(NSArray <ZMUserInfo *> * _Nullable)ignoreUserList ofView:(NSView * _Nonnull)positioningView;

- (void)showToolTipWithUserList:(NSArray <ZMUserInfo *> * _Nonnull)userLists
                 ignoreUserList:(NSArray <ZMUserInfo *> * _Nullable)ignoreUserList
                         ofView:(NSView * _Nonnull)positioningView
                         inRect:(NSRect)positioningRect
               emptyListMessage:(NSString* _Nullable)emptyListMessage;

- (void)showToolTipWithUserList:(NSArray <ZMUserInfo *> * _Nonnull)userLists
                 ignoreUserList:(NSArray <ZMUserInfo *> * _Nullable)ignoreUserList
                         ofView:(NSView * _Nonnull)positioningView
                         inRect:(NSRect)positioningRect
               emptyListMessage:(NSString* _Nullable)emptyListMessage
                    showViewAll:(BOOL)showViewAll
                  viewMoreBlock:(nullable void(^)())viewMoreBlock;

- (void)showDetailUserList:(NSArray <ZMUserInfo *> * _Nonnull)userLists ofView:(NSView * _Nonnull)positioningView;

@end

#ifndef ZMShareUserListToolTipProtocol
#define ZMShareUserListToolTipProtocol (id<ZMUserListToolTipProtocol>)ZMSharedFor(ZMUserListToolTipProtocol)
#endif

#endif /* ZMUserListToolTipProtocol_h */
