//
//  ZMPTRoundImageView.h
//  SaasBeePTUIModule
//
//  Created by ryan on 14-5-8.
//  Copyright (c) 2014年 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMPTUserAccountActionProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPTRoundImageView : NSControl
{
@private
    NSImage*                                _image;
    int                                     _messageNumber;
    BOOL                                    _isRound;
    id<ZMPTUserAccountActionProtocol>       _actionDelegate;
    id                                      _actionID;
    int                                     _radius;
    BOOL                                    _notCompressSize;
    float                                   _alpha;
}

@property (nonatomic, readwrite, retain) NSImage* image;
@property (nonatomic, readwrite, assign) int messageNumber;
@property (nonatomic, readwrite, assign) BOOL isRound;
@property (nonatomic, readwrite, assign) id actionID;
@property (nonatomic, readwrite, assign) int radius;
@property (assign) BOOL notCompressSize;
@property (assign) float alpha;

- (void)setActionDelegate:(id<ZMPTUserAccountActionProtocol>)actionDelegate;
- (void)cleanup;
- (void)generateBackColorWithJID:(NSString*)Jid;
- (void)generateImageWithName:(NSString*)name JID:(NSString*)Jid;
+ (NSImage*)generateFixedSizeImageWithName:(NSString*)name JID:(nullable NSString*)Jid;
+ (NSImage*)generateFixedSizeImageWithName:(NSString*)name JID:(nullable NSString*)Jid imageSize:(CGSize)imageSize;
+ (NSImage*)generateFixedSizeImageWithName:(NSString*)name JID:(nullable NSString*)Jid imageSize:(CGSize)imageSize backgroundColor:(nullable NSColor *)backgroundColor;
+ (NSImage*)generateImageWithIcon:(nullable NSImage*)inIcon string:(NSString*)inString imageSize:(NSSize)inSize;
+ (NSColor*)getColorWithJID:(nullable NSString*)JID;
+ (NSImage*)generateImageWithIcon:(nullable NSImage*)inIcon bgColor:(NSColor*)bgColor imageSize:(NSSize)inSize;
+ (NSImage*)generateFixedSizeImageWithName:(NSString*)name JID:(nullable NSString*)Jid imageSize:(CGSize)imageSize textColor:(nullable NSColor *)textColor backgroundColor:(nullable NSColor *)backgroundColor;
+ (NSImage*)generateRoundImageWithIcon:(NSImage*)inIcon string:(NSString*)inString imageSize:(NSSize)inSize radius:(float)radius; //ZOOM-72661
+ (NSImage*)generateRoundImageWithIcon:(NSImage*)inIcon string:(NSString*)inString imageSize:(NSSize)inSize;//ZOOM-72640 RTT
+ (NSImage*)generateRoundImageWithIcon:(nullable NSImage*)inIcon string:(nullable NSString*)inString imageSize:(NSSize)inSize withRadius:(float)radius;
@end

NS_ASSUME_NONNULL_END

