//
//  ZMSessionGroupProperty.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <zChatApp/SaasBeePTAppInterface.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSessionGroupProperty : NSObject

@property (nonatomic,assign) BOOL isPublic;
@property (nonatomic,assign) BOOL isRestrictSameOrg;
@property (nonatomic,assign) BOOL isNewMemberCanSeeMessageHistory;
@property (nonatomic,assign) BOOL isMuc;
@property (nonatomic,assign) BOOL isExternalUsersCanAddExternalUsers;
// ZOOM-387575
@property (nonatomic,assign) BOOL isOnlyAdminCanAddMembers;
@property (nonatomic,assign) BOOL isOnlyAdminCanAddExternalUsers;
@property (nonatomic,assign) ns_zoom_messager::GroupAnnouncerType announcerType;

@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *desc;
@property (nonatomic,retain) NSArray *announcers;

@property (nonatomic,copy) NSString *classificationID;

@property (nonatomic,copy) NSString *backgroundInfo;

- (void)updateWithGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
- (void)updateAnnouncerWithGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
@end

NS_ASSUME_NONNULL_END
