#import <Cocoa/Cocoa.h>

#import <ZoomKit/ZMBaseView.h>
#import <ZoomUnit/ZMTableView.h>
#import <zChatComponent/ZMUserInfo.h>

@protocol ZMCheckablePeopleListViewDelegate
@optional // Note, ZMViewMentionGroupViewCtrl doesn't use these.
- (void) checkmarkChangedForUser:(ZMUserInfo* _Nonnull)user checked:(BOOL)checked;
- (BOOL) searchStringDidChangeTo:(NSString* _Nullable)string;
- (void)updateHeaderLabelCount:(NSInteger)count;
@end

@interface ZMCheckablePeopleListView : NSView

- (void) updateChannel:(NSString* _Nonnull)channelID
                people:(NSArray<ZMUserInfo*>* _Nonnull)peopleArray
        filteredPeople:(NSArray<ZMUserInfo*>* _Nullable)filteredPeopleArray
               hasMore:(BOOL)hasMore
         checkedPeople:(NSArray<ZMUserInfo*>* _Nonnull)checkedPeopleArray;

- (NSArray*) checkedPeople;
- (NSArray*) uncheckedPeople;
- (void) clearFilter;

@property (nonatomic, retain) NSString* _Nonnull sessionID;
@property (nonatomic, assign) BOOL readOnly;
@property (nonatomic, assign) float borderRadius;
@property (nonatomic, assign) float fontSize;
@property (nonatomic, assign) float borderWidth;
@property (nonatomic, assign) float fieldHeight;
@property (nonatomic, retain) NSColor* _Nullable borderColor;
@property (nonatomic, assign) NSObject<ZMCheckablePeopleListViewDelegate> *delegate;
@end

@interface ZMCheckablePersonTableCell : NSTableCellView
- (void) setUserInfo:(ZMUserInfo *)info needsCheck:(BOOL)needsCheck;
@property (nonatomic, assign) float fontSize;
@property (nonatomic, assign) BOOL readOnly;
@end
