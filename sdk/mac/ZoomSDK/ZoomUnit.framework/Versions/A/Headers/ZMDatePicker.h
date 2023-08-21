//
//  ZMDatePicker.h
//  SaasBeePTUIModule
//
//  Created by Deal Shao on 1/21/13.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMCalendarWindowController.h>


@interface ZMDatePicker : NSDatePicker{
    ZMCalendarWindowController* _calendarWindowController;
}

- (void)cleanUp;
- (void)showCalendarWindow;
@end

