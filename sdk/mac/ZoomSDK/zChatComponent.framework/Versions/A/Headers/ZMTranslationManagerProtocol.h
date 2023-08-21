//
//  ZMTranslationManagerProtocol.h
//  zChatComponent
//
//

#import <Foundation/Foundation.h>

#ifndef ZMTranslationManagerProtocol_h
#define ZMTranslationManagerProtocol_h

NS_ASSUME_NONNULL_BEGIN

/// ISO 639-1 language codes for translation supported languages
typedef NSString* ZMLanguageCode NS_TYPED_ENUM;
extern ZMLanguageCode const ZMLanguageCodeEnglish;
extern ZMLanguageCode const ZMLanguageCodeFrench;
extern ZMLanguageCode const ZMLanguageCodeGerman;
extern ZMLanguageCode const ZMLanguageCodeSpanish;
extern ZMLanguageCode const ZMLanguageCodeItalian;
extern ZMLanguageCode const ZMLanguageCodeChineseSimplified;
extern ZMLanguageCode const ZMLanguageCodeRussian;
extern ZMLanguageCode const ZMLanguageCodeJapanese;
extern ZMLanguageCode const ZMLanguageCodeKorean;
extern ZMLanguageCode const ZMLanguageCodeVietnamese;
extern ZMLanguageCode const ZMLanguageCodeDutch;
extern ZMLanguageCode const ZMLanguageCodePortugese;

typedef void (^ZMDidTranslateMessageBlock)(BOOL success, NSString* requestID,
                                           NSString* messageID,NSString* sessionID,
                                           NSString* translation);
typedef void (^ZMDidRemoveMessageTranslationBlock)(NSString* messageID, NSString* sessionID);

@protocol ZMTranslationManagerProtocol <NSObject>
@property (nonatomic, readonly, assign) BOOL isTranslationEnabled;
/// Tries to translate the given message from sourceLanguage to self.destinationLanguage.
/// Returns a request ID when the request is succesfully sent to the server, nil on failure.
- (NSString* _Nullable)requestTranslationForMessage:(NSString*)msgID inSession:(NSString*)sessionID
                                       fromLanguage:(ZMLanguageCode _Nullable)sourceLanguage;
- (void)removeTranslationForMessage:(NSString*)msgID inSession:(NSString*)session;
/// The supported source languages for translation
/// @note The supported source languages changes based on the destination language (which is the app's language)
@property (nonatomic, readonly, strong) NSArray<ZMLanguageCode>* sourceLanguages;
/// The destination language for translation. nil if the current destinationLanguage doesn't support translation
/// @note The destination language is the app's language
@property (nullable, nonatomic, readonly, strong) ZMLanguageCode destinationLanguage;
- (NSString*)localizedNameForLanguage:(ZMLanguageCode)language;
- (void)addDidTranslateMessageListener:(id)listener block:(ZMDidTranslateMessageBlock)block;
- (void)addDidRemoveMessageTranslationListener:(id)listener block:(ZMDidRemoveMessageTranslationBlock)block;
/// Removes all registered callback-blocks for the given listener
- (void)unregisterListener:(id)listener;
@end

#ifndef ZMShareTranslationManagerProtocol
#define ZMShareTranslationManagerProtocol (id <ZMTranslationManagerProtocol>)ZMSharedFor(ZMTranslationManagerProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMTranslationManagerProtocol_h */
