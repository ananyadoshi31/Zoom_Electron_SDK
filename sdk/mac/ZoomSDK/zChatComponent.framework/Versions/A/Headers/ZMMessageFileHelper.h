//
//  ZMMessageFileHelper.h
//  ChatUI
//
//  Created by Zoro.Fu on 2022/9/27.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

#define FILE_NAME_MAX_LENGTH_DEFAULT (36)

NS_ASSUME_NONNULL_BEGIN

@class ZMFileEntity;
@interface ZMMessageFileHelper : NSObject

/// return NO if file is not exists at local path and is not a thirdpart file
+ (BOOL)checkFileExistsAtPath:(NSString *)filePath;

/// return the first unexists file path in the file array, if there is no unexists file, return nil
+ (nullable NSString *)firstUnexistsFileInArray:(NSArray<NSString *> *)fileList;

/// return all unexist files in the file array, if there is no unexists file, return @[ ];
+ (NSArray *)unexistFilesInArray:(NSArray<NSString *> *)fileList;

/// long fileName will display in format like abcdefg...xxyz.txt
+ (NSString *)convertFileNameByTruncatingMiddle:(NSString *)fileName toMaxLength:(NSUInteger)maxLength;

/// toast string for file not exists
+ (NSString *)fileNotExistsTip:(NSString *)filePath;

/// show toast for not exist files
+ (void)showToastsWithNotExistFiles:(NSArray<NSString *> *)fileList byToastCoordinator:(id<ZMToastCoordinatorProtocol>)toastCoordinator;

/// get file paths array from ZMFileEntity array
+ (NSArray<NSString *> *)filePathsFromFileEntityArray:(NSArray<ZMFileEntity *> *)fileEntityArr;

/// filter unexist files
+ (NSArray<ZMFileEntity *> *)availableFileFilter:(NSArray<ZMFileEntity *> *)fileList;

@end

NS_ASSUME_NONNULL_END
