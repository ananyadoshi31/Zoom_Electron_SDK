//
//  ZMMEventTracker.h
//  VideoUIBridge
//
//  Created by Lenard Zhou on 2022/12/9.
//

#import <Foundation/Foundation.h>
#import <ZoomPaapDef.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMEventTracker : NSObject

#ifdef ENABLE_ZAPP
+ (void)trackZappFunnelWithInfo:(ZMZAppsInteractInfo *)info;
#endif

// Meeting.Interact2 : Annotation
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2468578357/New+Annotations+Telemetry+Instrumentation+Spec
+ (void)trackAnnotationInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                        type:(e_meetings_MeetingInteractV2_event_type)eventType
                                    location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                        name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Meeting.Interact2 : Video Layout
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2470609198/Video+Layouts+Instrumentation
+ (void)trackVideoLayoutInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                         type:(e_meetings_MeetingInteractV2_event_type)eventType
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : Breakout Room
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2464551034/Breakout+Rooms+Instrumentation
+ (void)trackBreakoutRoomInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                          type:(e_meetings_MeetingInteractV2_event_type)eventType
                                      location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                          name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : Reaction
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2463334848/Product+Intelligence+-+Reactions
+ (void)trackReactionInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      type:(e_meetings_MeetingInteractV2_event_type)eventType
                                  location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                      name:(e_meetings_MeetingInteractV2_event_name)eventName
                               contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Language
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2468053091/Product+Intelligence+-+Language+Interpretation
+ (void)trackLanguageInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      type:(e_meetings_MeetingInteractV2_event_type)eventType
                                  location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                      name:(e_meetings_MeetingInteractV2_event_name)eventName
                               contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Polling
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2478866505/Product+Intelligence+-+Polling
+ (void)trackPollingInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                     type:(e_meetings_MeetingInteractV2_event_type)eventType
                                 location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                     name:(e_meetings_MeetingInteractV2_event_name)eventName
                              contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : MeetingChat
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2463728149/In-Meeting+Chat+Instrumentation
+ (void)trackChatInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                  type:(e_meetings_MeetingInteractV2_event_type)eventType
                              location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                  name:(e_meetings_MeetingInteractV2_event_name)eventName
                           contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Whiteboard
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2466496154/Snowplow+Old+whiteboard+Instrumentation+Spec
+ (void)trackWhiteboardInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                        type:(e_meetings_MeetingInteractV2_event_type)eventType
                                    location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                        name:(e_meetings_MeetingInteractV2_event_name)eventName
                                 contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Participants Panel
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2474447698/Participants+Panel+Instrumentation
+ (void)trackParticipantInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                         type:(e_meetings_MeetingInteractV2_event_type)eventType
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName
                                  contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Share Screen
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2483454081/Screen+Share+Instrumentation
+ (void)trackShareScreenInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                         type:(e_meetings_MeetingInteractV2_event_type)eventType
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName
                                  contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Recording
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2488467512/Recording+Instrumentation
+ (void)trackRecordInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                    type:(e_meetings_MeetingInteractV2_event_type)eventType
                                location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                    name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : In Meeting Invite
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2490207253/Product+Intelligence+-+Telemetry+Product+Requirements+-+In-meeting+invite
+ (void)trackInviteInMeetingInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                             type:(e_meetings_MeetingInteractV2_event_type)eventType
                                         location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                             name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : Meeting Information
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2504265036/Meeting+Information+Button+Instrumentation
+ (void)trackMeetingInfoInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                         type:(e_meetings_MeetingInteractV2_event_type)eventType
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : Video Menus
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2505411364/Video+Tile+Menus+Instrumentation
+ (void)trackVideoMenuInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                       type:(e_meetings_MeetingInteractV2_event_type)eventType
                                   location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                       name:(e_meetings_MeetingInteractV2_event_name)eventName
                                contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : Translation
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2310275798/Translation+Multi-language+Transcription+Client+Instrumentation+Spec
+ (void)trackTranslateInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                       type:(e_meetings_MeetingInteractV2_event_type)eventType
                                   location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                       name:(e_meetings_MeetingInteractV2_event_name)eventName
                                contextDesc:(nullable NSString *)eventContextDesc;

// Metting.Interact2 : JoinFlow
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2501420207/Join+Flow+Instrumentation+Refactored
+ (void)trackJoinFlowInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      type:(e_meetings_MeetingInteractV2_event_type)eventType
                                  location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                      name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Metting.Interact2 : IA Navigation
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2478704774/iA+Navigation+Instrumentation
+ (void)trackMeetingToolbarInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                            type:(e_meetings_MeetingInteractV2_event_type)eventType
                                        location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                     featureName:(e_meetings_MeetingInteractV2_feature_name)featureName
                                            name:(e_meetings_MeetingInteractV2_event_name)eventName
                                     contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Panelist/Co-host Options and View Options
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524089/Standardised+Panelist+Co-host+Options+and+View+Options+added+to+PIA+Dec
+ (void)trackWebinarOptionsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                        location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                     featureName:(e_meetings_MeetingInteractV2_feature_name)featureName
                                            name:(e_meetings_MeetingInteractV2_event_name)eventName
                                     contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Polls
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524143/Standardised+Polls
+ (void)trackWebinarPollsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                          name:(e_meetings_MeetingInteractV2_event_name)eventName
                                   contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Raise Hands
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524510/Standardised+Raise+hands
+ (void)trackWebinarRaiseHandsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                               name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Webinar.Interact : QnA
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525786/Standardised+QnA
+ (void)trackWebinarQnAInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                        type:(e_meetings_MeetingInteractV2_event_type)eventType
                                    location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                        name:(e_meetings_MeetingInteractV2_event_name)eventName
                                 contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Closed Captions
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524297/Standardised+Closed+Captions
+ (void)trackWebinarCloseCaptionInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                             location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                                 name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Webinar.Interact : Stream Options
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524559/Standardised+Streaming+options
+ (void)trackWebinarStreamInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                       location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                    featureName:(e_meetings_MeetingInteractV2_feature_name)featureName
                                           name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Webinar.Interact : Apps
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525469/Standardised+Apps
+ (void)trackWebinarAppsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName;

// Webinar.Interact : Whiteboard
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524752/Standardised+Whiteboards
+ (void)trackWebinarWhiteboardInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                           location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                               name:(e_meetings_MeetingInteractV2_event_name)eventName
                                        contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Chat
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524986/Standardised+Host+Chat
+ (void)trackWebinarChatInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                     location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                         type:(e_meetings_MeetingInteractV2_event_type)eventType
                                         name:(e_meetings_MeetingInteractV2_event_name)eventName
                                  contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Participants
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525889/Standardised+Participants
+ (void)trackWebinarParticipantsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                             location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                                 name:(e_meetings_MeetingInteractV2_event_name)eventName
                                          contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : End
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524436/Standardised+End+webinar
+ (void)trackWebinarEndInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                    location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                        name:(e_meetings_MeetingInteractV2_event_name)eventName
                                 contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Record
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477524633/Standardised+Record+webinar
+ (void)trackWebinarRecordInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                       location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                           name:(e_meetings_MeetingInteractV2_event_name)eventName
                                    contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Video
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525350/Standardised+Start+Stop+Video
+ (void)trackWebinarVideoInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                          name:(e_meetings_MeetingInteractV2_event_name)eventName
                                   contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Audio
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477523760/Standardised+Webinar+Host+Controls+Telemetry+Spec+-+December+2022+Release
+ (void)trackWebinarAudioInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                      location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                          name:(e_meetings_MeetingInteractV2_event_name)eventName
                                   contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Share Screen
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525637/Standardised+Share+Screen
// 部分点位和 meeting 的字段值都一样，复用 meeting 的
+ (void)trackWebinarShareScreenInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                            location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                                name:(e_meetings_MeetingInteractV2_event_name)eventName
                                         contextDesc:(nullable NSString *)eventContextDesc;

// Webinar.Interact : Reactions
// https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2477525998/Standardised+Reactions
// 部分点位和 meeting 的字段值都一样，复用 meeting 的
+ (void)trackWebinarReactionsInteractionWithSource:(e_meetings_MeetingInteractV2_event_source)eventSource
                                          location:(e_meetings_MeetingInteractV2_event_location)eventLocation
                                              name:(e_meetings_MeetingInteractV2_event_name)eventName
                                       contextDesc:(nullable NSString *)eventContextDesc;

//In-meeting Dialog
//https://zoomvideo.atlassian.net/wiki/spaces/DSB/pages/2581563178/In-meeting+Dialog
+(void)trackInMeetingDialogWithEventType:(e_client_ClientInteract_event_type)eventType
                               eventName:(e_client_ClientInteract_event_name)eventName
                             contextDesc:(nullable NSString *)eventContextDesc
                             noticeTitle:(nullable NSString *)noticeTitle
                           noticeMessage:(NSString *) noticeMessage;

@end

NS_ASSUME_NONNULL_END
