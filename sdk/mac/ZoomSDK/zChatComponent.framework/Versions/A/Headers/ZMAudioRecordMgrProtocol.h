//
//  ZMAudioRecordMgrProtocol.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/7/16.
//

#ifndef ZMAudioRecordMgrProtocol_h
#define ZMAudioRecordMgrProtocol_h

@protocol ZMAudioRecordMgrProtocol <NSObject>

- (NSString*)getRcdFilePath;
- (BOOL)isRecording;
- (BOOL)isReplyRecordingWithSessionId:(NSString*)sessionId threadId:(NSString*)threadId;
- (BOOL)isThreadRecordingWithSessionId:(NSString*)sessionId;
- (NSString*)recordingReplyIdWithSessionId:(NSString*)sessionId;
- (NSDate*)ThreadRecordingDateWithSessionId:(NSString*)sessionId;

- (BOOL)willRecordWithSessionId:(NSString*)sessionId threadId:(NSString*)threadId;
- (BOOL)startRecordWithController:(id)rcdController;
- (NSDictionary*)sendRecordWithController:(id)rcdController;
- (BOOL)stopRecordWithSessionId:(NSString*)sessionId threadId:(NSString*)threadId;
- (BOOL)stopRecordWithSessionId:(NSString*)sessionId;
- (void)stopRecord;
- (void)interruptRecordWithSessionId:(NSString*)sessionId;
- (void)interruptRecord;

- (void)onRecordMessageSettingChanged;

@end

#ifndef ZMShareAudioRecordMgrProtocol
#define ZMShareAudioRecordMgrProtocol (id <ZMAudioRecordMgrProtocol>)ZMSharedFor(ZMAudioRecordMgrProtocol)
#endif

#endif /* ZMAudioRecordMgrProtocol_h */
