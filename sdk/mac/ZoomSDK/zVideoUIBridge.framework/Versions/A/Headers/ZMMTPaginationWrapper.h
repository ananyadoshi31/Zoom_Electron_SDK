//
//  ZMMTPaginationWrapper.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 7/23/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMMTPaginationWrapper;
@protocol ZMMTPaginationProtocol <NSObject>

@optional
- (void)onTotalUserCountChanged:(NSUInteger)originUserCount pagination:(ZMMTPaginationWrapper*)wrapper;
- (void)onTotalPageNumberChanged:(NSUInteger)totalPageNumber pagination:(ZMMTPaginationWrapper*)wrapper;
- (void)onCurrentPageNumberChanged:(NSUInteger)currentPageNumber pagination:(ZMMTPaginationWrapper*)wrapper;
- (void)onCurrentPageUsersCountChanged:(NSUInteger)currentPageUsersCount pagination:(ZMMTPaginationWrapper*)wrapper;
- (void)onCurrentPageUsersChanged:(ZMMTPaginationWrapper*)wrapper;
- (void)triggerJSEventOnGalleryPageChanged:(ZMMTPaginationWrapper*)wrapper;

@end

@interface ZMMTPaginationWrapper<Type> : NSObject
@property(nonatomic, weak) id<ZMMTPaginationProtocol> delegate;
@property(nonatomic, retain) NSArray<Type>* userArray;
@property(nonatomic, assign) NSUInteger maxCountPerPage;

- (NSUInteger)allUserCount;

- (NSUInteger)totalPageNumber;
- (NSUInteger)currentPageNumber;
- (NSUInteger)currentPageUsersCount;

- (NSArray<Type>*)getCurrentPageUsers;

- (nullable Type)userAtIndex:(NSUInteger)index;
- (NSRange)currentPageRange;

- (BOOL)isFirstPage;
- (BOOL)isLastPage;

- (BOOL)canScroll2PrevPage;
- (BOOL)canScroll2NextPage;

- (void)onScroll2PrevPage;
- (void)onScroll2NextPage;
- (void)onScroll2Page:(NSUInteger)galleryPage;


@end

NS_ASSUME_NONNULL_END
