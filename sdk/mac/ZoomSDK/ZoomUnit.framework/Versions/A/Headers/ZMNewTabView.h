

#import <Cocoa/Cocoa.h>


typedef enum
{
    TAG_TAB_TRIANGLE_POSITION_NONE,
    TAG_TAB_TRIANGLE_POSITION_TOP,
    TAG_TAB_TRIANGLE_POSITION_BOTTOM,
}trianglePosition;
typedef enum
{
    TAG_TAB_BORDER_TYPE_SQUARE,
    TAG_TAB_BORDER_TYPE_ROUND_RECT,
    TAG_TAB_BORDER_TYPE_NONE_SQUARE,
    TAG_TAB_BORDER_TYPE_NONE_ROUND_RECT,
    TAG_TAB_BORDER_TYPE_ALL_SQUARE,
    TAG_TAB_BORDER_TYPE_ALL_ROUND_RECT,
    TAG_TAB_BORDER_TYPE_BAR,
}tabType;
@protocol ZMNewTabViewDelegate <NSObject>
@end
@interface ZMNewTabView : NSView    <NSWindowDelegate>
@property(nonatomic,weak)id<ZMNewTabViewDelegate> delegate;
- (id)initWithFrame:(NSRect)frameRect;

- (void)addTabItem:(NSTabViewItem *)item;
- (void)insertTabItem:(NSTabViewItem *)item atIndex:(NSInteger)index;
- (void)removeTabItem:(NSTabViewItem *)item;

- (void)selectFirstItem;
- (void)selectLastItem;
- (void)selectTabItemAtIndex:(NSInteger)index;
- (void)selectTheTabItem:(NSTabViewItem *)tabItem;
- (void)selectTabItem:(id)tabItem;

//set frame for buttonview and tabview default is buttonview is up on the tabview
- (void)setButtonViewFrame:(NSRect)rect;
- (void)setTabViewFrame:(NSRect)rect;


// set color button item and title
- (void)setOnStateBackGroundColor:(NSColor *)color;
- (void)setOffStateBackGroundColor:(NSColor *)color;
- (void)setOnStateTitleColor:(NSColor *)color;
- (void)setOffStateTitleColor:(NSColor *)color;
//set the title's font and image for button item
- (void)setTitle:(NSString *)inTitle forIdentifier:(NSString *)identifier;
- (void)setImage:(NSImage *)image forIdentifier:(NSString *)identifier;
- (void)setTitleFont:(NSFont *)font;
//set whether have triangle or not
- (void)setTrianglePosition:(trianglePosition)position;
//set autoresizeingmask for buttonview
- (void)setButtonViewAutoresizingMask:(NSUInteger)autoresizingMask;
//set for the item's border
- (void)setBorderType:(tabType)borderType;
- (void)setBorderColor:(NSColor *)color;
- (void)setBorderRadius:(float)radius;
- (void)setBorderWidth:(float)width;
//set for buttonview
- (void)setSpacing:(NSInteger)spacing;
- (void)setButtonViewColor:(NSColor *)color;

//set for all tabview
- (void)setBackGroundColor:(NSColor *)color;

// get the select item
- (NSTabViewItem *)getSelectedTabItem;
// get the number of item
- (NSInteger)getNumberOfTabItem;

//get the index for item
- (NSInteger)indexOfTabItem:(NSTabViewItem*)theItem;
- (NSInteger)indexOfTabViewItemWithIdentifier:(NSString *)identifier;

@end

