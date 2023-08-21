//
//  ZoomKit.h
//  ZoomKit
//
//  Created by Francis Zhuo on 6/21/21.
//

#import <Foundation/Foundation.h>

//! Project version number for ZoomKit.
FOUNDATION_EXPORT double ZoomKitVersionNumber;

//! Project version string for ZoomKit.
FOUNDATION_EXPORT const unsigned char ZoomKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ZoomKit/PublicHeader.h>

#import <Zoomkit/ZMBaseKit.h>
#import <Zoomkit/zoom_client_conf.h>

//main
#import <Zoomkit/ZPLogHelper.h>
#import <Zoomkit/ZPBundleHelper.h>
#import <Zoomkit/ZMProductBuildMgr.h>

//AX
#import <ZoomKit/ZMAXHelper.h>

//baseView
#import <Zoomkit/ZMButtonsContainarView.h>
#import <ZoomKit/ZMStackView.h>
#import <Zoomkit/ZMFlowView.h>
#import <ZoomKit/ZMTrackingView.h>
#import <ZoomKit/ZMTrackingBaseView.h>
#import <ZoomKit/ZMTrackBubbleView.h>
#import <ZoomKit/ZMDrawingView.h>
#import <ZoomKit/ZMBackgroundControl.h>
#import <ZoomKit/ZMBackgroundView.h>
#import <Zoomkit/ZMVisualEffectView.h>
#import <ZoomKit/ZMHighlightAndGradientBorderView.h>
#import <ZoomKit/ZMFocusedTargetDimmingView.h>
#import <ZoomKit/ZMLine.h>
#import <ZoomKit/ZMHLine.h>
#import <ZoomKit/ZMGridAccessibilityView.h>

#import <ZoomKit/ZMBaseViewController.h>
#import <ZoomKit/ZMBaseView.h>
#import <ZoomKit/ZMAccessibleView.h>

//baseWindow
#import <ZoomKit/ZMPureWindow.h>
#import <ZoomKit/ZMPlainWindow.h>
#import <ZoomKit/ZMWindowWidgets.h>

//textView/textField
#import <ZoomKit/ZMTokenTextAttachmentCell.h>
#import <ZoomKit/ZMPTBaseTextAttachmentCell.h>
#import <ZoomKit/ZMViewAttachmentCell.h>
#import <ZoomKit/ZMMutableSelectProtocal.h>

#import <ZoomKit/ZMTextView.h>
#import <ZoomKit/ZMPlaceholderTextView.h>
#import <ZoomKit/ZMLabel.h>

#import <ZoomKit/ZMHyperLinkTextField.h>
#import <ZoomKit/ZMLinkTextField.h>
#import <ZoomKit/ZMAutoShowToolTipTextField.h>
#import <ZoomKit/ZMMultiLineTextField.h>
#import <ZoomKit/ZMTextField.h>
#import <Zoomkit/ZMHTextField.h>

#import <ZoomKit/ZMDropDownTextField.h>
#import <ZoomKit/ZMDropDownListView.h>
#import <ZoomKit/ZMDropDownItem.h>

#import <ZoomKit/ZMTextStorage.h>

//button
#import <ZoomKit/ZMSwitch.h>
#import <ZoomKit/ZMGradientButton.h>
#import <ZoomKit/ZMStickCheckButton.h>
#import <ZoomKit/ZMBubbleButton.h>
#import <ZoomKit/ZMHelpButton.h>
#import <Zoomkit/ZMBadgeView.h>
#import <ZoomKit/ZMButton.h>
#import <ZoomKit/ZMRadioButton.h>
#import <ZoomKit/ZMCheckButton.h>
#import <ZoomKit/ZMIMOnlyImageButton.h>
#import <ZoomKit/ZMGroupedElementOnlyImageButton.h>
#import <ZoomKit/ZMPopUpButton.h>
#import <ZoomKit/ZMMoveableButton.h>

//menu
#import <ZoomKit/ZMHMenuListView.h>
#import <ZoomKit/ZMHMenu.h>
#import <ZoomKit/ZMHMenuItem.h>
#import <ZoomKit/ZMHMenuItemView.h>

//alert
#import <ZoomKit/ZMAlertPanel.h>
#import <ZoomKit/ZMAlertViewController.h>

//bubbleTip
#import <ZoomKit/ZMBubbleObject.h>
#import <ZoomKit/ZMTextBubbleObject.h>

//scrollView
#import <ZoomKit/ZMTrackingScrollView.h>
#import <ZoomKit/ZMIMTrackingScrollView.h>
#import <ZoomKit/ZMScrollView.h>

//Appearance
#import <ZoomKit/ZMAppearanceImage.h>

//event
#import <ZoomKit/ZMKeyBoardType.h>
#import <ZoomKit/ZMHotkeyKit.h>
#import <ZoomKit/NSEventMonitoringCenter.h>

//router
#import <ZoomKit/ZMURLRouter.h>
#import <ZoomKit/ZMRouterKit.h>

//Svg
#import <Zoomkit/ZMSVGMgr.h>
#import <Zoomkit/ZMSvgElement.h>
#import <Zoomkit/ZMSVGLibHelper.h>

//autolayout
#import <ZoomKit/ZMLayout.h>

//invisibleShare
#import <ZoomKit/NSWindow+ZoomShare.h>
#import <Zoomkit/ZMShareWindowMonitor.h>

//Timer
#import <ZoomKit/ZMClock.h>
#import <ZoomKit/ZMClockWatcherField.h>
#import <ZoomKit/ZMTimer.h>

//Cache
#import <ZoomKit/ZMCache.h>

//Concurrency
#import <ZoomKit/ZMAsyncTask.h>

//Toast
#import <ZoomKit/ZMToastPanel.h>
#import <ZoomKit/ZMToastCoordinator.h>

//NotificationCenter
#import <ZoomKit/ZMNotificationProtocol.h>
#import <ZoomKit/ZMNotificationManager.h>

//Categories
#import <ZoomKit/NSTrackingArea+ZoomKit.h>
#import <ZoomKit/NSTextFieldCell+ZoomKit.h>
#import <ZoomKit/NSToolTipManager+ZoomKit.h>
#import <ZoomKit/NSOpenPanel+ZoomKit.h>

//Other
#import <ZoomKit/ZMUtil.h>
#import <ZoomKit/ZMParseHTMLSnippetImpl.h>
#import <ZoomKit/ZMTooltipMgr.h>
#import <ZoomKit/ZMCallbackImpl.h>
#import <ZoomKit/ZMAccessibilityElement.h>
#import <ZoomKit/ZMAppearanceHelper.h>
#import <ZoomKit/ZMAppEventHotkeyMgr.h>
#import <ZoomKit/ZMKeyboardLayoutMgr.h>
#import <ZoomKit/ZMAppearanceColor.h>
#import <ZoomKit/ZMPkgAuthHelper.h>

//Data Stucture
#import <ZoomKit/ZMMutableArray.h>
#import <ZoomKit/ZMThreadSafeArray.h>
#import <ZoomKit/ZMWebJsDispatchManager.h>
#import <ZoomKit/ZMGradientLabelView.h>
#import <ZoomKit/ZMGroupedAccessibilityView.h>
#import <ZoomKit/ZMNTrackingView.h>
#import <ZoomKit/ZMNWKWebViewController.h>
