//

#import <Foundation/Foundation.h>
#import "ZoomSDKRawDataController.h"
NS_ASSUME_NONNULL_BEGIN


@interface ZoomSDKAudioRawDataSender : NSObject
/**
 * @brief Send audio raw data, channel number must be mono, and sampling bits must be 16.
 * @param data The address of audio data.
 * @param length The length of audio data, it must be even numbers.
 * @param rate The sampling rate of audio data(8000/11025/32000/44100/48000/50000/50400/96000/192000/2822400).
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
- (ZoomSDKError)send:(char*)data dataLength:(unsigned int)length sampleRate:(int)rate;
@end

@protocol ZoomSDKVirtualAudioMicDelegate <NSObject>
/**
 * @brief Callback for virtual audio mic to do some initialization.
 * @param rawdataSender A object of audio sender, you can send audio data based on this object.
 */
- (void)onMicInitialize:(ZoomSDKAudioRawDataSender*)rawdataSender;
/**
 * @brief Callback for virtual audio mic can send raw data with 'rawdataSender'.
 */
- (void)onMicStartSend;
/**
 * @brief Callback for virtual audio mic should stop send raw data.
 */
- (void)onMicStopSend;
/**
 * @brief Callback for virtual audio mic is uninitialized.
 */
- (void)onMicUninitialized;
@end


@interface ZoomSDKRawDataAudioSourceController : NSObject

/**
 * @brief Subscribe audio mic raw data with a callback.
 * @param audioMicDelegate The delegate to receive callback.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
- (ZoomSDKError)setExternalAudioSource:(id <ZoomSDKVirtualAudioMicDelegate> _Nullable)audioMicDelegate;
@end

NS_ASSUME_NONNULL_END
