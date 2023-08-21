//
//  ZMTimer.h
//  SaasBeeConfUIModule
//
//  Created by francis on 2/13/17.
//  Copyright © 2017 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
extern ZMTimerName kZMTimerPlistVoipAudioFlash;
extern ZMTimerName kZMTimerPlistTeleAudioFlash;
extern ZMTimerName kZMTimerPlistRecordFlash;
extern ZMTimerName kZMTimerPlistMuteTipView;
extern ZMTimerName kZMTimerPlistSortPanelist;
extern ZMTimerName kZMTimerPlistSortPanelistAudioStatusChange;
extern ZMTimerName kZMTimerPlistUpdateAttendee;
extern ZMTimerName kZMTimerPlistSortActiveChanded;
extern ZMTimerName kZMTimerConfClockTime;
extern ZMTimerName kZMTimerToolbarHandTipView;
extern ZMTimerName kZMTimerMainUIAttedeeVideoLayout;
extern ZMTimerName kZMTimerMonitorMemoryDisk;
extern ZMTimerName kZMTimerWallViewTopCountChanged;
extern ZMTimerName kZMTimerPushToTalk;
extern ZMTimerName kZMTimerCheckCoreAudio;
extern ZMTimerName kZMTimerFitbarAudioFlash;
extern ZMTimerName kZMTimerChatRotate;

@interface ZMTimerMgr : ZMTimer
+ (id)shareTimer_0_01;
+ (id)shareTimer_0_1;
+ (id)shareTimer_1_0;
+ (void)removeTimerWithTarget:(id)target;
@end
