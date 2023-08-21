//
//  ZMDatePickerDropdownView.h
//  ZoomUnit
//
//  Created by Michael Poulain on 4/13/22.
//

#import <ZoomUnit/ZMDatePicker.h>
#import <ZoomUnit/ZoomUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDatePickerDropdownView : ZMBaseView
+ (ZMDatePickerDropdownView*)datePickerForCalendarDays;
+ (ZMDatePickerDropdownView*)datePickerForHoursMinutes;
@property(nonatomic, retain) ZMDatePicker* datePicker;
@property(nonatomic, copy) void (^onDateValueChanged)(ZMDatePickerDropdownView* picker);
//the interval, in minutes, for the time picker dropdown menu (e.g. 15 == 10:00, 10:15, 10:30, etc.)
@property(nonatomic, assign) NSInteger minuteInterval;
@property(nonatomic, assign) BOOL useShortTimeFormat;
@end

NS_ASSUME_NONNULL_END
