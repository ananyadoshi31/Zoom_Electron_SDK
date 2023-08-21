//
//  ZMEmojiUnicodeData.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/11/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZMEmojiUnicodeDataDelegate <NSObject>
@optional
- (BOOL)canShowTWFlagEmoji;
@end

@interface ZMEmojiUnicodeData : NSObject

@property(nonatomic, readonly) NSArray* categoryArray;
@property(nonatomic, retain, readonly) NSDictionary *allEmojiDict;
@property(nonatomic, retain) NSMutableDictionary* key2EmojiDict;
@property (nonatomic, retain, readonly) NSMutableArray *frequentArray;
@property (nonatomic, weak) id<ZMEmojiUnicodeDataDelegate> delegate;
- (void)initData;
+ (NSArray*)skinToneEmojiArray;
- (void)scheduleSaveFavoriteEmojiList;
/// Get the selected emojis setting by admin
- (NSArray *)selectedEmojiStringArray;
- (BOOL)isEmojiAllowedInSelectedEmoji:(NSString *)emoji;
- (NSMutableArray*)getFrequentMutableArray;
- (NSMutableArray *)getLottieMutableArray;
- (NSArray*)getEmojiArrayByCategory:(NSString*)category;
- (BOOL)isInEmojiFont:(NSString*)inEmojiUnicode;
- (BOOL)contains1CharacterEmojiStr:(NSString *)emojiStr;
- (NSString *)tryReplaceCusEmojiWithSystemEmoji:(NSString *)emojiStr;
- (NSArray *)availableFrequentlyUsedEmoji;
- (void)cleanUp;
@end
