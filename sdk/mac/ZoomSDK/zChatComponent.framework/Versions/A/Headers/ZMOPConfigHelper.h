//
//  ZMOPConfigHelper.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMConfigValue) {
    ZMChatDisable = 1,
    ZMAccountChatDisable,
    ZMCopyDisable,
    ZMReplyDisable,
    ZMReactionDisable,
    ZMHyperlinkPreviewEnabledInE2E,
    ZMTWEmojiEnableInLibrary,
    ZMTWEmojiEnableFilter,
    ZMFileTransferDisabled,
    ZMHybridMessageEnabled,
    ZMRichTextFormatEnabled,
    ZMRecordMessageEnabled,
    ZMRecordVideoMessageEnabled,
    ZMPlayVideoMessageEnable,
    ZMDLPEnabled,
    ZMScreenShotEnabled,
    ZMCodeSnippetEnabled,
    ZMConsolidatePresenceEnable,
    ZME2eEditMessageEnable,
    ZMMyAccountEnableE2E,
    ZMEnableMultiChannelAdmins,
    ZMEnableSMS,
    ZMRichTextFormatEnabledOnWeb,
    ZMEnableReportInChannel,
    ZMMioLicenseEnabled,
    ZMSendingHybridMsgEnabledOnWeb,
    ZMVideoMirrorEnabled,
    ZMOPEnabledLargeChannelMemberListOptimizationOption,
    ZMChatAppsShortcutsEnabled,
    ZMBusyPresenceEnabled,
    ZMAppsInReplyBoxEnabled,
};

@protocol ZMOPConfigProtocol <NSObject>

- (void)addOPValue:(ZMConfigValue)value;

- (void)removeOPValue:(ZMConfigValue)value;

- (BOOL)checkByValue:(ZMConfigValue)value;

- (BOOL)isChatDisable;
- (BOOL)isAccountChatDisable;
- (BOOL)isCopyDisable;
- (BOOL)isReplyDisable;
- (BOOL)isReactionDisable;
- (BOOL)isHyperlinkPreviewEnabledInE2E;
- (BOOL)isTWEmojiEnableInLibrary;
- (BOOL)isTWEmojiEnableFilter;
- (BOOL)isFileTransferDisabled;
- (BOOL)isHybridMessageEnabled;
- (BOOL)isRichTextFormatEnabled;
- (BOOL)isRecordMessageEnabled;
- (BOOL)isRecordVideoMessageEnabled;
- (BOOL)isPlayVideoMessageEnable;
- (BOOL)isDLPEnabled;
- (BOOL)isScreenShotEnabled;
- (BOOL)isCodeSnippetEnabled;
- (BOOL)isMyAccountEnableE2E;
- (BOOL)isEnableConsolidatePresence;
- (BOOL)isE2ECanEditMessageEnable;
- (BOOL)isEnableSMS;
- (BOOL)isRichTextFormatEnabledOnWeb;
- (BOOL)isEnableReportInChannel;
- (BOOL)isMioLicenseEnabled;
- (BOOL)isSendingHybridMsgEnabledOnWeb;
- (BOOL)isEnableMultiChannelAdmins;
- (BOOL)isVideoMirrorEnabled;
- (BOOL)isOPEnabledLargeChannelMemberListOptimizationOption;
- (BOOL)isChatAppsShortcutsEnabled;
- (BOOL)isBusyPresenceEnabled;
- (BOOL)isShowAppsInReplyBoxEnabled;
@end

@protocol ZMConfigChangedEventProtocol <NSObject>

- (void)configDidChange:(ZMConfigValue)value key:(NSString *)key;

@end

@interface ZMOPConfigHelper : NSObject

+ (id<ZMOPConfigProtocol>)defaultOPConfig;

+ (id<ZMOPConfigProtocol>)makeOPConfigByKey:(NSString *)key;

+ (id<ZMOPConfigProtocol>)getOPConfigByKey:(NSString *)key;

+ (void)removeDefaultOPConfig;

+ (void)removeOPConfigByKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
