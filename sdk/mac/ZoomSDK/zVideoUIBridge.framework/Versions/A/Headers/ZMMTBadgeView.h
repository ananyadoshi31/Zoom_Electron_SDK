//
//  ZMMTBadgeView.h
//  VideoUI
//
//  Created by  Devl on 5/18/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTBadgeConfig : NSObject

@property (nonatomic, retain) NSColor *leftColor;
@property (nonatomic, retain) NSColor *rightColor;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, copy) NSString *badgeTxt;

+ (instancetype)smallConfig;// "NEW", 16f
+ (instancetype)defaultConfig;// "NEW", 20f

@end

@interface ZMMTBadgeView : NSView

+ (instancetype)viewWithConfig:(ZMMTBadgeConfig *)config;

@end

NS_ASSUME_NONNULL_END
