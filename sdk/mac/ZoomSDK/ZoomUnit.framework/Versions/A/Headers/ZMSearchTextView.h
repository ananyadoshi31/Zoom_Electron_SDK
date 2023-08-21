//
//  ZMSearchTextView.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/19.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMSearchScrollView : NSScrollView

@property(nonatomic,retain) IBInspectable NSColor *borderColor;
@property(nonatomic,retain) IBInspectable NSColor *activeBorderColor;
@property(nonatomic,assign) IBInspectable CGFloat radius;
@property(nonatomic,assign) IBInspectable CGFloat borderWidth;

@property (assign, nonatomic) IBInspectable BOOL hasFloatingPlaceHolder;//!< default is NO
@property (copy, nonatomic) IBInspectable NSString *floatingPlaceHolder;//!< If nil, use placeholder or attributted placeholder

@end

@protocol ZMSearchTextViewDelegate <NSObject>

- (BOOL)shouldPaste;

@end

@interface ZMSearchTextView : NSTextView

@property (nonatomic, copy) NSString *searchPlaceholderString;

@property (nonatomic, copy) NSString *searchAccessibilityDescription;

@property (nonatomic, copy) NSAttributedString *searchPlaceholderAttributedString;

@property (nonatomic, assign) BOOL needShowSearchIcon;

@property (nonatomic,copy) CGSize (^updateTextContainerInset)(ZMSearchTextView *textView);

@property (nonatomic,copy) void (^updateFirstResponse)(BOOL firstResponse);

@property (nonatomic,copy) BOOL (^mouseMoveOn)(id<NSTextAttachmentCell> mouseMoveOnCell, NSRect attachmentRect, NSPoint atPoint);

- (void)updateTextViewContainerInset;

- (NSRange)inputNearFieldSelectionStringRange ;

- (NSString *)inputNearFieldSelectionString;

+ (ZMSearchTextView *)createSearchTextView NS_RETURNS_RETAINED;

@end
