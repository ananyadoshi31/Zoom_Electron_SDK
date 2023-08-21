//
//  ZMLengthLimitFormatter.h
//  ZCommonUI
//
//  Created by John on 9/2/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMLengthLimitFormatter : NSFormatter
{
    int _maxLength;
}

@property(nonatomic, assign) int maxLength;
@end
