//
//  IZPAlertManager.h
//  VideoUI
//
//  Created by martin.yu on 9/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPAlertManager_h
#define IZPAlertManager_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZPAlertManager <ZMRoutableObject>
- (void)showAllowSignLanguageInterpreterToTalkAlert;
- (void)closeAllowSignLanguageInterpreterToTalkAlert;
@end

NS_ASSUME_NONNULL_END

#endif /* IZPAlertManager_h */
