//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZoomSDKInMeetingDeviceInfo : NSObject
/**
 @brief Index.
 */
@property (assign, nonatomic,readonly) int index;

/**
 @brief Device name.
 */
@property (copy, nonatomic,readonly) NSString *deviceName;

/**
 @brief Meeting topic.
 */
@property (copy, nonatomic,readonly) NSString *meetingTopic;

/**
 @brief Meeting number.
 */
@property (assign, nonatomic,readonly) long long meetingNumber;
@end

@protocol ZoomSDKNotificationServiceDelegate <NSObject>

/**
 * @brief Transfer meeting status changed callback.
 * @param bSuccess The result of transfer meeting.
 */
-(void)onTransferMeetingStatus:(BOOL)bSuccess;

/**
 * @brief Callback event that the device for users to attend the meeting has changed.
 * @param deviceList A list of meeting info with active meetings.
 */
-(void)onMeetingDeviceListChanged:(NSArray <ZoomSDKInMeetingDeviceInfo *>*)deviceList;

@end

@interface ZoomSDKNotificationServiceController : NSObject

@property(nonatomic, assign, nullable)id<ZoomSDKNotificationServiceDelegate> delegate;

/**
 * @brief Determine whether the transfer meeting feature is enabled.
 */
- (BOOL)isTransferMeetingEnabled;

/**
 * @brief Try to transfer meeting to current device.
 * @param index Specifies the index.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)transferMeeting:(int)index;
@end

NS_ASSUME_NONNULL_END
