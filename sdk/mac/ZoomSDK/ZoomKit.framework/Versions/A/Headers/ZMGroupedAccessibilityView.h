//
//  ZMGroupedAccessibilityView.h
//  ZoomKit
//
//  Created by simon shang on 2021/11/30.
//

//#import <ZoomKit/ZoomKit.h>

#import <ZoomKit/ZMNTrackingView.h>
#import <ZoomKit/ZMButton.h>

NS_ASSUME_NONNULL_BEGIN

// ZMGroupedAccessibilityView's element should adopt this protocol
@protocol ZMGroupedAccessibilityElement <NSObject>

@property (nonatomic, readonly) BOOL isElementFocusable;

- (void)showFocusRingMask;
- (void)dismissFocusRingMask;
- (NSString *)accessibilityString;

@end

@protocol ZMGroupedAccessibilityViewDelegate <NSObject>

- (void)clickElement:(id)element AtIndex:(NSUInteger)index;

@end

@interface ZMGroupedAccessibilityView : ZMNTrackingView


@property (nonatomic, weak) id<ZMGroupedAccessibilityViewDelegate> accessibilityViewDelegate;

@end

// ---------------------------------------------------------------------------------------------
@interface ZMGroupedElementButton : ZMButton <ZMGroupedAccessibilityElement>

@end

NS_ASSUME_NONNULL_END
