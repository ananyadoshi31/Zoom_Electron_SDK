//
//  ZMAssignedGroupResult.h
//  ZoomUnit
//
//  Created by zhengrong xiao on 2021/11/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAssignedGroupParam : NSObject

@property (nonatomic,copy) NSString *groupID;
@property (nonatomic,copy) NSString *localVersion;
@property (nonatomic,copy) NSString *targetVersion;
@property (nonatomic,assign) NSInteger cursor;
@property (nonatomic,assign) NSInteger limit;

@end



@interface ZMAssignedGroupResult : NSObject

@property (nonatomic,retain) ZMAssignedGroupParam *groupParam;
@property (nonatomic,retain) NSArray<NSString *> *items;
@property (nonatomic,assign) NSInteger result; //0 is success
@property (nonatomic,assign) BOOL hasNextPage;
@property (nonatomic,copy) NSString *reqID;

@end



@interface ZMZBuddyGroup : NSObject

@property (nonatomic,copy) NSString *groupID;
@property (nonatomic,copy) NSString *groupName;
@property (nonatomic,assign) NSInteger groupType;  //BuddyGroupType

@end


@interface ZMAssignedGroupSearchResult : NSObject

@property (nonatomic,retain) ZMZBuddyGroup *group;
@property (nonatomic,retain) NSArray *jids;

@end

NS_ASSUME_NONNULL_END
