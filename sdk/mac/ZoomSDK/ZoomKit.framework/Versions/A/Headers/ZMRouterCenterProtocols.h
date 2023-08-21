//
//  ZMRouterCenterProtocols.h
//  ZoomKit
//
//  Created by martin.yu on 4/23/22.
//

#ifndef ZMRouterCenterProtocols_h
#define ZMRouterCenterProtocols_h

#import <Foundation/Foundation.h>
#import <ZoomKit/ZMRouterMacroUtil.h>
#import <ZoomKit/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMEventPoster <NSObject, NSCopying>
@property (weak) id sender;
@property (assign) BOOL ignoreSender;
@property (weak) id object;
@end

@protocol ZMEventTarget <NSObject>
@property (assign, readonly) Protocol *p;
@property (weak, readonly) NSObject *target;
@property (weak, readonly) id object;
@end


#define ZMEventPosterFor(P) ((id<P>)[ZMRouterCenter.shared posterForProtocol:@protocol(P)])
@protocol ZMEventPosterGenerator <NSObject>
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object;
@end

@protocol ZMEventRegistry <NSObject>
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol;
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol object:(nullable id)object;
- (void)unregisterTartget:(NSObject *)target forProtocol:(Protocol *)protocol;
- (void)unregisterTartgetByEventTarget:(id<ZMEventTarget>)eventTarget;
- (void)unregisterTartget:(NSObject *)target;
@end

/*!
 export protocol for routerA
 @code
 xxx.h
 @protocol protocolA<NSObject>
 @end
 
 @protocol protocolB<NSObject>
 @end
 
 @interface routerA
 @end
 
 xxx.m
 @routerable(routerA, protocolA, protocolB)
 @implementation routerA
 @end
 @endcode
 */
#define routerable(className, protocolName...) routerable_(className, protocolName)

/*!
 export protocol for routerA
 @code
 xxx.h
 @protocol protocolA<NSObject>
 @end
 @protocol protocolB<NSObject>
 @end
 
 @interface routerA<ZMRoutableObject>
 @end
 
 xxx.m
 @implementation routerA
 ZMExportProtocol(protocolA,protocolB)
 @end
 @endcode
 */
#define ZMExportProtocol(protocol...) ZMExportProtocol_(protocol)


/*!
 get Instance methods
 @code
 id<protocolA> objectA = ZMObjectFor(Protocol);
 @endcode
 */
#define ZMObjectFor(P) (id<P>)[ZMRouterCenter.shared objectForProtocol:@protocol(P)]

/*!
 get singleton methods
 @code
 id<protocolA> objectA = ZMSharedFor(Protocol);
 @endcode
 */
#define ZMSharedFor(P) ((id<P>)[ZMRouterCenter.shared singletonForProtocol:@protocol(P)])

/*!
 observe xxx router did register
 @code
 [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(routerADidReady) name:ZMRouterReady object:@protocol(protocolA)];
 @endcode
 */
extern NSNotificationName const ZMRouterReady;

@protocol ZMRouterCenterDelegate;
@protocol ZMRouterCenter <ZMEventPosterGenerator, ZMEventRegistry, ZMRoutableObject>
@property(nullable, weak) id<ZMRouterCenterDelegate> delegate;
- (void)registerProtocol:(Protocol *)protocol forClass:(Class)aClass;
- (void)registerProtocols:(NSArray<Protocol *> *)protocols forClass:(Class)aClass;
- (nullable Class)classForProtocol:(Protocol *)protocol;
- (nullable id)objectForProtocol:(Protocol *)protocol;

- (void)registerSingleton:(id)Object forProtocol:(Protocol *)protocol;
- (void)removeSingletonForProtocol:(Protocol *)protocol;
- (nullable id)singletonForProtocol:(Protocol *)protocol;

- (id)registerSuccessAction:(void(^_Nullable)(void))action forProtocol:(Protocol *)protocol;
- (BOOL)registerSuccessAction:(void(^_Nullable)(void))action forProtocol:(Protocol *)protocol withID:(id)identifer;
- (void)removeSuccessActionForProtocol:(Protocol *)protocol WithID:(id)identifer;
@end

@protocol ZMRouterCenterDelegate <NSObject>
@optional
//for Singleton
- (id)routerCenter:(id<ZMRouterCenter>)routerCenter singletonForProtocol:(Protocol *)protocol;

//for EventPoster
- (void)routerCenter:(id<ZMRouterCenter>)routerCenter collectTargets:(id<ZMEventRegistry>)collector forProtocol:(Protocol *)protocol;
@end
NS_ASSUME_NONNULL_END

#endif /* ZMRouterCenterProtocols_h */
