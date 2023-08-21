

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZoomSDKReactionControllerDelegate <NSObject>

/**
 * @brief Notify receive the emoji reaction.
 * @param userid The user id of the send emoji reaction.
 * @param type The send emoji reaction type.
 * @param skinTone The send emoji reaction skinstone.
 */
-(void)onEmojiReactionReceived:(unsigned int)userid reactionType:(ZoomSDKEmojiReactionType)type reactionSkinTone:(ZoomSDKEmojiReactionSkinTone)skinTone;

/**
 * @brief Emoji reaction callback. This callback notifies the user when an emoji is received in the webinar.
 * @param type Specify the type of the received reaction.
 */
-(void)onEmojiReactionReceivedInWebinar:(ZoomSDKEmojiReactionType)type;

@end

@interface ZoomSDKReactionController : NSObject
{
    id<ZoomSDKReactionControllerDelegate> _delegate;
}
@property (assign, nonatomic) id<ZoomSDKReactionControllerDelegate> delegate;

/**
 * @brief Determine if the Reaction function is enabled.
 * @return YES means Reaction function is enable,otherwise not.
 */
-(BOOL)isEmojiReactionEnabled;

/**
 * @brief Send emoji reaction.
 * @param type The type of the emoji reaction.
 * @param skinTone The skintone of the emoji reaction
 * @return If the function succeeds, it will return ZoomSDKError_succuss, otherwise not.
 */
-(ZoomSDKError)sendEmojiReaction:(ZoomSDKEmojiReactionType)type reactionSkinTone:(ZoomSDKEmojiReactionSkinTone)skinTone DEPRECATED_MSG_ATTRIBUTE("Use -sendEmojiReaction: instead");

/**
 * @brief Send emoji reaction.
 * @param type The type of the emoji reaction.
 * @return If the function succeeds, it will return ZoomSDKError_succuss, otherwise not.
 */
-(ZoomSDKError)sendEmojiReaction:(ZoomSDKEmojiReactionType)type;

/**
 * @brief Set emoji reaction display type in webinar.
 * @param type The display type of the emoji reaction. For more details see {@link ZoomSDKEmojiReactionDisplayType}.
 * @return If the function succeeds, it will return ZoomSDKError_succuss. Otherwise the function returns an error.
 */
-(ZoomSDKError)setWebinarEmojiReactionDisplayType:(ZoomSDKEmojiReactionDisplayType)type;

/**
 * @brief Get emoji reaction display type in webinar. For more details see {@link ZoomSDKEmojiReactionDisplayType}
 * @return If the function succeeds, it will return the display type of the emoji reaction. Otherwise, the function returns ZoomSDKEmojiReactionDisplayType_None.
 */
-(ZoomSDKEmojiReactionDisplayType)getWebinarEmojiReactionDisplayType;
@end

NS_ASSUME_NONNULL_END
