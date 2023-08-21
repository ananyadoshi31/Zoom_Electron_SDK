//
//  IZMConfTipMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMConfTipMgr_h
#define IZMConfTipMgr_h

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMTipType) {
    ZMTipType_None                 = 0,
    ZMTipType_Session_Default      = 1ll << 0,
    ZMTipType_Session_BOMaster     = 1ll << 1,
    ZMTipType_Session_Backstage    = 1ll << 2,
    ZMTipType_Session_NewBO        = 1ll << 3,
    ZMTipType_Session_Common       = 0xFFFFFFFF,
    
    ZMTipType_Scene_Slient         = 1ll << 61,
    ZMTipType_Scene_Transfor       = 1ll << 62,
    
    ZMTipType_All                  = 0xFFFFFFFFFFFFFFFF,
};

typedef void(^ZMMTTipNotificationResponseBlock)(BOOL* closeTip);

@protocol ZMMTTipNotification <NSObject>
@property (nonatomic, assign) BOOL manualClose;
@property (nonatomic, assign) BOOL transformIfNeed;
@property (nonatomic, assign) BOOL flashUpdate;
@property (nonatomic, assign) BOOL announcement;
@property (nonatomic, assign) BOOL rotateAnimation;
@property (nonatomic, assign) BOOL supportSilentMode;
@property (nonatomic, assign) CGFloat outTiming;//if outTiming == 0, will not auto close
@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *identifier;
@property (nonatomic, retain) NSString *actionButtonTitle;
@property (nonatomic, retain) NSString *otherButtonTitle;
@property (nonatomic, retain) NSString *actionTitle;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock actionButtonResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock otherButtonResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock clickContentResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock closeResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock actionTitleResponse;
@property (nonatomic, retain, nullable) NSImage *contentImage;
@property (nonatomic, retain, nullable) NSURL *contentImageURL;

@property (nonatomic, assign) ZMTipType tipType;
@end

@protocol IZMConfTipMgr <ZMRoutableObject>
- (id<ZMMTTipNotification>)newTipNotification;

- (NSString*)deliverTipNotification:(id<ZMMTTipNotification>)tip;
- (BOOL)isTipExistsWithIdentifier:(NSString *)tipIdentifier;
- (void)removeTipWithIdentifier:(NSString *)tipIdentifier;

- (void)showlTip:(NSString *)tipString
     manualClose:(BOOL)close
       outTiming:(float)times
      identifier:(nullable NSString *)tipIdentifier;

- (void)showTip:(NSString *)tipString
     manualClose:(BOOL)close
    clickDismiss:(BOOL)dismiss
       outTiming:(float)times
      identifier:(nullable NSString *)tipIdentifier;

- (void)showTip:(NSString *)tipString
     manualClose:(BOOL)close
    clickDismiss:(BOOL)dismiss
       outTiming:(float)times
    announcement:(BOOL)announcement
         tipType:(ZMTipType)type
      identifier:(nullable NSString *)tipIdentifier;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMConfTipMgr_h */
