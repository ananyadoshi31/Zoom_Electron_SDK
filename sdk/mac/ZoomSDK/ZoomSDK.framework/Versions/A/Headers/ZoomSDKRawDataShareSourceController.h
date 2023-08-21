

#import <Foundation/Foundation.h>




@interface ZoomSDKShareSender : NSObject
/**
 * @brief Send share raw data in meeting.
 * @param frameBuffer The buffer of the data to send.
 * @param width The width of the data to send.
 * @param height The height of the data to send.
 * @param frameLength The length of the data to send.
 */
- (ZoomSDKError)sendShareFrame:(char*)frameBuffer width:(unsigned int)width height:(unsigned int)height frameLength:(unsigned int)frameLength;
@end


@protocol ZoomSDKShareSourceDelegate <NSObject>
/**
 * @brief Notify to start send share source.
 * @param sender The object of ZoomSDKShareSender to send share source.
 */
- (void)onStartSend:(ZoomSDKShareSender*)sender;

/**
 * @brief Notify to stop send share source.
 */
- (void)onStopSend;
@end



@interface ZoomSDKRawDataShareSourceController : NSObject

/**
 * @brief Set the delegate of share source.
 * @param shareSource The delegate to receive callback.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
- (ZoomSDKError)setExternalShareSource:(id <ZoomSDKShareSourceDelegate>)shareSource;
@end
