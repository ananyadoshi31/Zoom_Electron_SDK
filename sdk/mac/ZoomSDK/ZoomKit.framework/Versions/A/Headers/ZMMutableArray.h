//
//  ZMMTMutableArray.h
//  VideoUI
//
//  Created by martin.yu on 1/11/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMutableArray<__covariant ObjectType> : NSObject <NSFastEnumeration, NSCopying>
@property(readonly) NSArray<ObjectType> *array;
@property(readonly, copy) NSMutableArray<ObjectType> *mutableArray;

+ (instancetype)array;
+ (instancetype)arrayWithArray:(NSArray<ObjectType> * _Nullable)array;

- (instancetype)initWithArray:(NSArray<ObjectType> * _Nullable)array;

@property (nonatomic, readonly) NSUInteger count;

- (BOOL)addObject:(ObjectType)anObject;
- (BOOL)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;

- (BOOL)removeObject:(ObjectType)anObject;
- (void)removeAllObjects;

// Support indexed subscripting need to declare this method
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index;
- (ObjectType)objectAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfObject:(ObjectType)anObject;

- (BOOL)containsObject:(ObjectType)anObject;

- (void)sortUsingComparator:(NSComparator)cmptr;
@end

@interface ZMOrderedSet<ObjectType> : ZMMutableArray<ObjectType>
+ (instancetype)setWithArray:(NSArray<ObjectType> * _Nullable)array;
- (nullable ObjectType)member:(ObjectType)object;
@end

NS_ASSUME_NONNULL_END
