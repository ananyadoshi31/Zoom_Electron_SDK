//
//  ZPLogHelper.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 5/4/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/log_control.h>

#define ZPLogHelper [ZMLogger getLogger]

#if (defined(__ZOOM_NO_CLIENT_LOG) || defined(__ZOOM_ROOMS_UI_LOG_DISABLED))

    #define ZRLog(format, ...)
    #define ZRLogFuncName()
    #define ZRLogInt(intValue)
    #define ZRLogLongLong(longlongValue)
    #define ZRLogBool(boolValue)
    #define ZRLogFloat(floatValue)
    #define ZRLogString(stringValue)
    #define ZRLogRect(rectValue)
    #define ZRLogPoint(pointValue)
    #define ZRLogSize(sizeValue)

    #define ZMLog(format, ...)
    #define ZMFuncLog(format, ...)
    #define ZMMacLog(info)
    #define ZMMacLogInt(info,intValue)
    #define ZMMacLogLongLong(info,longlongValue)
    #define ZMMacLogBool(info,boolValue)
    #define ZMMacLogFloat(info,floatValue)
    #define ZMMacLogString(info,stringValue)
    #define ZMMacLogRect(info,rectValue)
    #define ZMMacLogPoint(info,pointValue)
    #define ZMMacLogSize(info,sizeValue)
    #define ZMMacWarningLog(info)

#else

    #define ZRLog(format, ...)              ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])
    #define ZRLogFuncName()              ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s ", __func__]])
    #define ZRLogInt(intValue)    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=", __func__, #intValue] withInt:intValue])
    #define ZRLogLongLong(longlongValue)            ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",  __func__,  info, #longlongValue] withLongLong:(long long)longlongValue])
    #define ZRLogBool(boolValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #boolValue] withBOOL:boolValue])
    #define ZRLogFloat(floatValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #floatValue] withFloat:floatValue])
    #define ZRLogString(stringValue)                ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #stringValue] withString:stringValue])
    #define ZRLogRect(rectValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #rectValue] withString:NSStringFromRect(rectValue)])
    #define ZRLogPoint(pointValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #pointValue] withString:NSStringFromPoint(pointValue)])
    #define ZRLogSize(sizeValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #sizeValue] withString:NSStringFromSize(sizeValue)])


    #define ZMLog(format, ...)                              ([ZPLogHelper infoLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])
    #define ZMFuncLog(format, ...)                          ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])
    #define ZMMacLog(info)                                  ([ZPLogHelper infoLog:info])
    #define ZMMacLogInt(info,intValue)                      ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #intValue] withInt:intValue])
    #define ZMMacLogLongLong(info,longlongValue)            ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #longlongValue] withLongLong:(long long)longlongValue])
    #define ZMMacLogBool(info,boolValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #boolValue] withBOOL:boolValue])
    #define ZMMacLogFloat(info,floatValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #floatValue] withFloat:floatValue])
    #define ZMMacLogString(info,stringValue)                ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #stringValue] withString:stringValue])
    #define ZMMacLogRect(info,rectValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #rectValue] withString:NSStringFromRect(rectValue)])
    #define ZMMacLogPoint(info,pointValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #pointValue] withString:NSStringFromPoint(pointValue)])
    #define ZMMacLogSize(info,sizeValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #sizeValue] withString:NSStringFromSize(sizeValue)])
    #define ZMMacWarningLog(info)                           ([ZPLogHelper warningLog:info])

#endif

#define ZMMemLog(format, ...) ([ZPLogHelper memoryLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])

#define ZMMemFuncLog(format, ...)  ([ZPLogHelper memoryLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])

#define ZMPTMemLog(format, ...) ([ZPLogHelper ptMemoryLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])

@protocol ZMLogProtocal <NSObject>

- (void)infoLog:(NSString*)content;
- (void)memoryLog:(NSString*)content;
- (void)ptMemoryLog:(NSString*)content;
- (void)infoLog:(NSString*)content withInt:(long)intValue;
- (void)infoLog:(NSString*)content withLongLong:(long long)longlongValue;
- (void)infoLog:(NSString*)content withBOOL:(BOOL)boolValue;
- (void)infoLog:(NSString*)content withFloat:(float)floatValue;
- (void)infoLog:(NSString*)content withString:(NSString*)stringValue;
- (void)warningLog:(NSString*)content;

@end

@interface ZMLogger : NSObject

+ (void)setLogger:(id <ZMLogProtocal>)logger;
+ (id <ZMLogProtocal>)getLogger;

@end
