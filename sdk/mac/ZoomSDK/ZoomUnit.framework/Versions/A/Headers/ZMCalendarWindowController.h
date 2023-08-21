//
//  ZMCalendarWindowController.h
//  SaasBeePTUIModule
//
//  Created by Deal Shao on 1/21/13.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMCalendarWindowController : NSWindowController<NSWindowDelegate, NSDatePickerCellDelegate>

@property (nonatomic, retain) NSDatePicker *myDatePicker;
@property (nonatomic, weak, readwrite) NSDatePicker *targetDatePicker;
@property (nonatomic, assign) NSInteger dateHour;
@property (nonatomic, assign) NSInteger dateMin;
@property (nonatomic, assign) BOOL pickerInited;


- (id)initWithDatePicker:(NSDatePicker *)datePciker;

- (void)updateDatePicker;
@end
