//
//  ZMTextFormatAddLinkView.h
//  SaasBeePTUIModule
//
//  Created by Yong Zhou on 6/22/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import "ZMTextFormatEntity.h"

@interface ZMTextFormatAddLinkView : NSView

@property (nonatomic, copy) void (^onConfirmBtnClicked)(NSString *linkUrlString);
@property (nonatomic, copy) void (^onEditBtnClicked)(NSString *linkUrlString, NSRange linkRange);
@property (nonatomic, copy) void (^onRemoveBtnClicked)(NSRange linkRange);
@property (nonatomic, copy) void (^checkLinkURLCompletion)(BOOL isValidUrl, BOOL needsClose);
@property (nonatomic, copy) void (^checkURL)(NSString *tmpUrlString);

- (void)showWithType:(ZMTextFormatShowLinkViewType)type url:(NSString*)urlString linkRange:(NSRange)range;

- (void)linkViewDidClosed;

@end


