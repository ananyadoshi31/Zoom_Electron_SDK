//
//  IZMMTToolbarMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTToolbarMgr_h
#define IZMMTToolbarMgr_h

typedef NS_ENUM(NSInteger, ZPConfToolBarButtonTag) {
    ZPConfToolBarButtonTagAudio = 1,
    ZPConfToolBarButtonTagAudioOrAudioSetting,
    ZPConfToolBarButtonTagAudioMenu,
    ZPConfToolBarButtonTagVideo,
    ZPConfToolBarButtonTagParticipant,
    ZPConfToolBarButtonTagChat,
    ZPConfToolBarButtonTagBackstage,
    ZPConfToolBarButtonTagBO,
    ZPConfToolBarButtonTagNewBO,
    ZPConfToolBarButtonTagClosedCaption,
    ZPConfToolBarButtonTagInterpretation,
    ZPConfToolBarButtonTagReacitons,
#ifdef ENABLE_ZAPP
    ZPConfToolBarButtonTagZoomApps,
#endif
    ZPConfToolBarButtonTagPolling,
    ZPConfToolBarButtonTagRecord,
    ZPConfToolBarButtonTagQA,
    ZPConfToolBarButtonTagMore,
    ZPConfToolBarButtonTagWhiteboard,
    ZPConfToolBarButtonTagSidecar,
    ZPConfToolBarButtonTagMoreFeatures,
    ZPConfToolBarButtonTagHand,
};

NS_ASSUME_NONNULL_BEGIN

@protocol IZPConfToolbarController <ZMRoutableObject>
- (nullable __kindof NSView *)buttonWithTag:(ZPConfToolBarButtonTag)tag;
- (void)updateButtonWithTag:(ZPConfToolBarButtonTag)tag;
- (void)updateButtonWithTag:(ZPConfToolBarButtonTag)tag needRelayoutUI:(BOOL)needRelayoutUI;

- (void)updateAudio;

// Implementated at category.
@optional
- (BOOL)isToolbarAvailableInterpretLanguageTipShowing;
- (BOOL)isToolbarInterpretationMicStateEnabledTipShowing;
- (BOOL)isToolbarInterpretationMicStateDisabledTipShowing;
@end

@protocol IZMMTToolbarMgr <ZMRoutableObject>
@property (nonatomic, retain, readonly) ZMMTBaseViewController<IZPConfToolbarController> *toolbarController;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTToolbarMgr_h */
