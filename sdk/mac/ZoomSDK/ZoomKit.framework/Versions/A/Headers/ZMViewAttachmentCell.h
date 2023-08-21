//
//  ZMViewAttachmentCell.h
//  ParseHTML
//
//  Created by groot.ding on 22/6/21.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMViewAttachmentCell : NSTextAttachmentCell

@property (nonatomic,readonly) NSView *view;

@property (nonatomic,assign) NSPoint baselineOffset;

+ (instancetype)attachmentCellWithView:(NSView *)view;

+ (NSAttributedString *)attributedStringWithView:(NSView *)view;

- (NSAttributedString *)attributedString;

- (void)sizeToFit;

@end

@interface ZMImageAttachmentCell : ZMViewAttachmentCell

+ (instancetype)attachmentCellWithImageName:(NSString *)imgName;

+ (instancetype)attachmentCellWithImage:(NSImage *)image;

@end

NS_ASSUME_NONNULL_END
