//
//  ZMCommonUIClass.h
//  ZoomMsgUI
//
//  Created by Kevin Li on 2022/4/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern const NSInteger MAX_INPUT_TEXTVIEW_HEIGHT;
extern const NSInteger MAX_TEXT_LENGTH;

extern NSString* kJIRAID;
extern NSString* kGITHUBID;
extern NSString* kGITLABID;

static const NSInteger gXMLColorCount = 17;
static const    CFStringRef  gXMLColorArray[][2] =
{
    CFSTR("Aqua"),      CFSTR("00FFFF)"),
    CFSTR("Black"),     CFSTR("000000"),
    CFSTR("Blue"),      CFSTR("0000FF"),
    CFSTR("Fuchsia"),   CFSTR("FF00FF"),
    CFSTR("Gray"),      CFSTR("808080"),
    CFSTR("Green"),     CFSTR("008000"),
    CFSTR("Lime"),      CFSTR("00FF00"),
    CFSTR("Maroon"),    CFSTR("800000"),
    CFSTR("Navy"),      CFSTR("000080"),
    CFSTR("Olive"),     CFSTR("808000"),
    CFSTR("Orange"),    CFSTR("FFA500"),
    CFSTR("Purple"),    CFSTR("800080"),
    CFSTR("Red"),       CFSTR("FF0000"),
    CFSTR("Silver"),    CFSTR("C0C0C0"),
    CFSTR("Teal"),      CFSTR("008080"),
    CFSTR("White"),     CFSTR("FFFFFF"),
    CFSTR("Yellow"),    CFSTR("FFFF00"),
};

@interface ZMChatXMLMessageBody : NSObject
{
    NSString*               _tmpID;
    NSString*               _imageURL;
    NSString*               _message;
    BOOL                    _isOnlyMessage;
    BOOL                    _failed;
    NSMutableArray*         _summaryArray;
    NSMutableArray*         _buddyArray;
    NSMutableArray*         _titleArray;
    NSMutableArray*         _actionArray;
}

@property (assign) BOOL isOnlyMessage;
@property (assign, readonly) BOOL failed;
@property (copy) NSString* tmpID;
@property (copy) NSString* message;
@property (copy) NSString* imageURL;

- (id)initWithXMLString:(NSString*)XMLString;
- (NSArray*)summmaryArray;
- (NSArray*)buddyArray;
- (NSArray*)titleArray;
- (NSArray*)actionArray;

@end

NS_ASSUME_NONNULL_END
