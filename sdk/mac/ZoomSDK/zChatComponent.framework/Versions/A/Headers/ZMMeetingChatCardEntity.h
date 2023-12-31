//
//  ZMMeetingChatCardEntity.h
//  ZoomUnit
//
//  Created by Yong Zhou on 6/29/22.
//

#import <Foundation/Foundation.h>
@class ZMMessageAdapter;
@class ZMBuddyAdapter;

static const NSUInteger kMaxDisalayAvataCount = 7;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMeetingChatCardParticipant : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *jid;
@property (nonatomic, retain) NSImage *avataImage;
@end

@interface ZMMeetingChatCardEntity : NSObject
@property (nonatomic, copy) NSString *meetingID;
@property (nonatomic, copy) NSString *meetingTopic;
@property (nonatomic, copy) NSArray<ZMMeetingChatCardParticipant*> *participantInfo;
@property (nonatomic, retain, nullable) NSDate *meetingStartTime;
@property (nonatomic, retain, nullable) NSDate *meetingEndTime;
@property (nonatomic, assign) NSUInteger participantCount;
@property (nonatomic, assign) NSUInteger totalMessageCount;
/*Not required*/
@property (nonatomic, copy, nullable) NSString *sessionID;
@property (nonatomic, copy, nullable) NSString *messageID;

- (NSString *)getFormatTimePeriodString;
- (NSString *)getTimeInfoString;
- (NSString *)getTimePeriodInfoString;

/// description for message. Generally for  Pin message or last message.
- (NSString *)getMessageDescString;

- (NSString *)getTitle4ViewMoreParticipantsButton;

@end

@interface ZMMeetingChatCardReqParticipantsPara : NSObject
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *messageID;
@property (nonatomic, copy, nullable) NSString *meetingID;
@end

@interface ZMMCCSyncMessageResult : NSObject
@property (nonatomic, copy) NSArray<ZMMessageAdapter*> *messages;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *messageID;
@property (nonatomic, copy, nullable) NSString *meetingID;
@property (nonatomic, copy) NSString *lastValue;
@property (nonatomic, assign) BOOL hasMore;
@property (nonatomic, assign) NSUInteger respCode;
@end

@interface ZMMCCSyncParticipantsResult : NSObject
@property (nonatomic, copy) NSArray<ZMBuddyAdapter*> *buddies;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *messageID;
@property (nonatomic, copy, nullable) NSString *meetingID;
@end

NS_ASSUME_NONNULL_END
