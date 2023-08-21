//
//  ZPBundleHelper.h
//  SaasBeePTUIModule
//
//  Created by sanshi on 11-12-8.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZPBundleHelper : NSObject


+ (NSBundle *)resBundle;
+ (NSString *)resBundlePath;
+ (NSString *)resBundlePathForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (NSString *)mainResBundlePathForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (NSImage *)resBundleImageForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (NSImage *)getAvatarByPath:(NSString*)inPath;
+ (BOOL)removeAvatarByPath:(NSString*)inPath;//ZOOM-123364

+ (NSImage *)getImageByName:(NSString*)resName;//[Zoom-33534]
+ (NSString *)getImagePathByImage:(NSImage*)inImage; //ZOOM-71195
+ (NSImage *)getDarkImageByName:(NSString *)resName;

+ (NSString *)resolveImagePath:(NSString *)imagePath;
+ (NSString*)localizedString:(NSString *)theKey;
+ (NSString*)localizedString:(NSString *)theKey value:(NSString*)value;
+ (void)cleanUp;
+ (NSString*)localizedEnString:(NSString *)theKey value:(NSString*)value;

+ (BOOL)hasValidZoomCodeSign:(NSString*)path NS_DEPRECATED_MAC(10.9, 10.9, "Use +hasValidZoomCodeSignWithPath:completion: instead");
+ (BOOL)hasValidZoomCodeSignBlock:(CFStringRef)filepath NS_DEPRECATED_MAC(10.9, 10.9, "Use +hasValidZoomCodeSignWithPathRef:completion: instead");//ZOOM-157888
+ (void)hasValidZoomCodeSignWithPath:(NSString *)path completion:(void (^)(BOOL result))completion; // ZOOM-455387
+ (void)hasValidZoomCodeSignWithPathRef:(CFStringRef)filepath completion:(void (^)(BOOL result))completion; // ZOOM-455387

+ (NSString *)getBundleVersion:(NSString *)bundlePath;
+ (BOOL)needDownloadWithLatestVersion:(NSString*)inLatestVersion currentVersion:(NSString*)inCurrentVersion;

+ (BOOL)isRunningOnArm64;
+ (BOOL)isBuildForArm64;

+ (NSURL *)URLForImageName:(NSString *)imageName;

@end
