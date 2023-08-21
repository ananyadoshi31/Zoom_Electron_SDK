//
//  ZMUIConstants.h
//  SaasBeeConfUIModule
//
//  Created by francis zhuo on 2019/7/22.
//  Copyright © 2019 zoom.us. All rights reserved.
//

#ifndef ZMUIConstants_h
#define ZMUIConstants_h

#define ZMUserID unsigned int
#define ZMUUID uint64_t
#define ZMUJID CmmUInt32

#define kBitNewBO 47
typedef NS_ENUM(NSUInteger, ZMConfInstType) {
    ZMConfInstType_Default      = 1,
    ZMConfInstType_BOMaster     = 2,
    ZMConfInstType_Backstage    = 3,
    
    ZMConfInstType_Common       = 100,
    ZMConfInstType_Transition   = 101,
    
    ZMConfInstType_NewBO        = 1ll<<kBitNewBO,//roomID = ConfInstType>>(kBitNewBO+1)
};

#define kZMConfInstType_Default @"kZMConfInstType_Default"
#define kZMConfInstType_BOMaster @"kZMConfInstType_BOMaster"
#define kZMConfInstType_Backstage @"kZMConfInstType_Backstage"
#define kZMConfInstType_Common @"kZMConfInstType_Common"
#define kZMConfInstType_NewBO_Prefix "kZMConfInstType_NewBO:"
#define ZMBOIdentifer(roomID) [NSString stringWithFormat:@"%s%@", kZMConfInstType_NewBO_Prefix, @(roomID)]
#define ZMBOInstType(roomID) (ZMConfInstType)(((1ll*roomID)<<(kBitNewBO+1))|ZMConfInstType_NewBO)
#define ZMBORoomID(InstType) (InstType>>(kBitNewBO+1))

#define kZMConfInstType_Transition @"kZMConfInstType_Transition"

#pragma mark - video render
typedef NS_OPTIONS(NSUInteger, ZMVideoUpdateStrategy) {
    ZMVideoUpdateStrategyAvatar     = 1,
    ZMVideoUpdateStrategyUserInfo   = 1<<1,
    ZMVideoUpdateStrategyRender     = 1<<2,
    ZMVideoUpdateStrategyWaterMark  = 1<<3, // ZOOM-277664 personal water mark
    ZMVideoUpdateStrategyNameTag    = 1<<4, // ZOOM-314071 webinar username tag
    ZMVideoUpdateStrategyMuteButton = 1<<5,
    ZMVideoUpdateStrategyKubiButton = 1<<6,
    ZMVideoUpdateStrategyOtherButton= 1<<7,
    ZMVideoUpdateStrategyButton     = ZMVideoUpdateStrategyMuteButton|ZMVideoUpdateStrategyKubiButton|ZMVideoUpdateStrategyOtherButton,
    
    ZMVideoUpdateStrategyResubscribe= 1<<10,
    
    ZMVideoUpdateStrategySkintone   = 1<<13,
    ZMVideoUpdateStrategyReactions  = 1<<14,
    ZMVideoUpdateStrategyHandView   = 1<<15,
    
    ZMVideoUpdateStrategyAllInfo    = ZMVideoUpdateStrategyAvatar|ZMVideoUpdateStrategyButton|ZMVideoUpdateStrategyUserInfo|ZMVideoUpdateStrategySkintone,
    ZMVideoUpdateStrategyAll        = ZMVideoUpdateStrategyRender|ZMVideoUpdateStrategyAllInfo,
    
//    ZMVideoUpdateStrategyActiveVideo= 1<<18,
    ZMVideoUpdateStrategyCleanRender= 1<<19,
    ZMVideoUpdateStrategyDockbar    = 1<<20,
};

#pragma mark - ZMMTConferenceStrategy
typedef NS_ENUM(NSInteger, ZMConfUpdateStrategy) {
    ZMConfUpdateStrategy_ConfReady,
    ZMConfUpdateStrategy_ConfLeave,
    
    ZMConfUpdateStrategy_BOConfReady,
    
    ZMConfUpdateStrategy_Preview_Changed,
    ZMConfUpdateStrategy_Companion_Changed,
    ZMConfUpdateStrategy_Silent_Changed,
    ZMConfUpdateStrategy_Backstage_Changed,
    ZMConfUpdateStrategy_Debrief_Changed,
    ZMConfUpdateStrategy_Practice_Changed,
    ZMConfUpdateStrategy_JoinFlow_Changed,
    ZMConfUpdateStrategy_Transition_Status_Changed,
    
    ZMConfUpdateStrategy_Zapp_Immersive_Changed,
    ZMConfUpdateStrategy_Zapp_Collaborate_Changed,
    
    ZMConfUpdateStrategy_Customer_Mode_Changed,
    ZMConfUpdateStrategy_Backstage_Leave_CountDown,
    ZMConfUpdateStrategy_Meeting_Topic_Changed,
    ZMConfUpdateStrategy_Avatar_Permission_Changed,
    
    ZMConfUpdateStrategy_Dual_Monitor_Changed,
    
    ZMConfUpdateStrategy_Audio_Status,
    ZMConfUpdateStrategy_Audio_Type,
    ZMConfUpdateStrategy_Active_Audio,
    
    ZMConfUpdateStrategy_Video_Status,
    ZMConfUpdateStrategy_My_Video_Status,
    ZMConfUpdateStrategy_Talking_Video,
    ZMConfUpdateStrategy_Active_Video,
    ZMConfUpdateStrategy_Active_Video_Deck,
    ZMConfUpdateStrategy_Active_Video_2nd,
    
    ZMConfUpdateStrategy_User_Roster,//add/left/silent/BO/GR/Update
    ZMConfUpdateStrategy_User_Add,
    ZMConfUpdateStrategy_User_Left,
    ZMConfUpdateStrategy_User_Enter_Silent,
    ZMConfUpdateStrategy_User_Exit_Silent,
    ZMConfUpdateStrategy_User_Rename,
    
    ZMConfUpdateStrategy_Become_HostCohost,
    ZMConfUpdateStrategy_Lose_HostCohost,
    ZMConfUpdateStrategy_OtherUser_BecomeLoseHostCoHost,
    
    ZMConfUpdateStrategy_Show_My_Video,
    ZMConfUpdateStrategy_Show_No_Video,
    ZMConfUpdateStrategy_Show_Incoming_Video,
    ZMConfUpdateStrategy_Spotlight_Self_Changed,
    
    ZMConfUpdateStrategy_Pin_Group_Changed,
    ZMConfUpdateStrategy_Spotlight_Changed,
    ZMConfUpdateStrategy_Drag_Layout_Changed,
    
    ZMConfUpdateStrategy_Attende_Layout_Changed,
    
    ZMConfUpdateStrategy_Meeting_Controls,
    ZMConfUpdateStrategy_Dockbar_Status_Changed,
    ZMConfUpdateStrategy_Dockbar_Did_Show,
    ZMConfUpdateStrategy_Dockbar_Did_Hide,
    
    ZMConfUpdateStrategy_Sending_Share_Status,
    ZMConfUpdateStrategy_Share_Source_Changed,
    ZMConfUpdateStrategy_New_Share_Source_Received,
    ZMConfUpdateStrategy_Share_Content_Received,
    ZMConfUpdateStrategy_Share_Content_First_Frame_Received,

    
    ZMConfUpdateStrategy_Closed_Caption,
    ZMConfUpdateStrategy_Captions_Status_Changed,
    
    ZMConfUpdateStrategy_Backsatge_Transfer,
    
    ZMConfUpdateStrategy_Focus_Mode_Changed,
    
    ZMConfUpdateStrategy_BackSplash_Changed,
    
    ZMConfUpdateStrategy_E2E_Security_Code_Changed,
    ZMConfUpdateStrategy_DC_Region_Ready,
    ZMConfUpdateStrategy_IDP_Status_Changed,
    ZMConfUpdateStrategy_Unencypted_Status_Changed,
    ZMConfUpdateStrategy_Livestream_Status_Changed,
    
    ZMConfUpdateStrategy_Share_Doc_Source_Changed,
    ZMConfUpdateStrategy_Share_Doc_Content_Received,
    ZMConfUpdateStrategy_Share_Doc_Load_State_Changed,
    
    ZMConfUpdateStrategy_Share_Audio_Sending_Status,
    ZMConfUpdateStrategy_Share_Audio_Source_Changed,
    
    ZMConfUpdateStrategy_Webinar_Reactions_Received,
    ZMConfUpdateStrategy_Webinar_Reactions_Type_Changed,
    ZMConfUpdateStrategy_Webinar_Reactions_Enabled_Changed,
    
    ZMConfUpdateStrategy_Mesh_Badge_Changed,
    
    ZMConfUpdateStrategy_Whiteboard_Source_Changed,
    ZMConfUpdateStrategy_Whiteboard_Presenter_Changed,
    ZMConfUpdateStrategy_Record_Status_Changed,
    
    ZMConfUpdateStrategy_Gateway_Logo_Downloaded,
    ZMConfUpdateStrategy_Lipsync_State_Changed,
    
    ZMConfUpdateStrategy_Login_State_Changed,
};

#pragma mark - ZMMTContentType
typedef NS_OPTIONS(NSUInteger, ZMMTContentType){
    ZMMTContentType_None        = 0,
    ZMMTContentType_Previewing  = 1ll<<0,
    ZMMTContentType_BrandView   = 1ll<<2,
    ZMMTContentType_Waiting_Host= 1ll<<3,
    
    ZMMTContentType_Transition  = 1ll<<4,
    ZMMTContentType_GRTransform = 1ll<<5,
    ZMMTContentType_BackStage   = 1ll<<6,
    ZMMTContentType_BRTransform = 1ll<<7,
    
    ZMMTContentType_Companion   = 1ll<<11,
    ZMMTContentType_Thumbnail   = 1ll<<12,
    ZMMTContentType_View_Share  = 1ll<<13,
    ZMMTContentType_Whiteboard  = 1ll<<14,
    ZMMTContentType_BarrageView = 1ll<<15,
    
    ZMMTContentType_Active      = 1ll<<21,
    ZMMTContentType_Gallery     = 1ll<<22,
    ZMMTContentType_Customer    = 1ll<<23,
    ZMMTContentType_Group_Pin   = 1ll<<24,
    ZMMTContentType_Zapp_Immersive = 1ll<<25,
    ZMMTContentType_Zapp_Collaborate = 1ll<<26,
    
    ZMMTContentType_Send_Doc_Share= 1ll<<30,
    ZMMTContentType_Side_By_Side= 1ll<<31,
    ZMMTContentType_Toolbar     = 1ll<<32,
    ZMMTContentType_Toolbar_Lock= 1ll<<33,
    ZMMTContentType_SidePanel   = 1ll<<34,
    ZMMTContentType_Swap_Share  = 1ll<<35,
    ZMMTContentType_Practice_Session = 1ll<<36,
    ZMMTContentType_FullScreen  = 1ll<<37,
};

typedef NS_OPTIONS(NSUInteger, ZMUserExcludeFilter){
    ZMUserExcludeFilter_None    = 0,
    ZMUserExcludeFilter_Silent  = 1<<1,
    ZMUserExcludeFilter_BO      = 1<<2,
    ZMUserExcludeFilter_ViewOnly= 1<<3,
    ZMUserExcludeFilter_GR      = 1<<4,
    ZMUserExcludeFilter_MultiStream = 1<<5,
    ZMUserExcludeFilter_VirtualAssistant = 1<<6,
    ZMUserExcludeFilter_Myself = 1<<7,
    ZMUserExcludeFilter_SignInterpreter = 1<<8,
    ZMUserExcludeFilter_CompanionModeWithParent = 1<<9,
};

#pragma mark - Water Mark
typedef NS_ENUM(NSInteger, ZMConfWaterMarkCoverType) {
    ZMConfWaterMarkCoverTypeNone,
    ZMConfWaterMarkCoverTypeInstance,
    ZMConfWaterMarkCoverTypeRepeated,
};
typedef NS_OPTIONS(NSUInteger, ZMConfWaterMarkVisibleOnType) {
    ZMConfWaterMarkVisibleOnTypeNone            = 0,
    ZMConfWaterMarkVisibleOnTypeShareContent    = 1 << 0,
    ZMConfWaterMarkVisibleOnTypeVideoFeeds      = 1 << 1,
};
typedef NS_ENUM(NSInteger, ZMConfWaterMarkPosition) {
    ZMConfWaterMarkPositionMiddle,
    ZMConfWaterMarkPositionTop,
    ZMConfWaterMarkPositionBottom,
    ZMConfWaterMarkPositionLeft,
    ZMConfWaterMarkPositionRight,
};

typedef NS_ENUM(NSInteger, ZMMTJoinUpdateStrategy)
{
    ZMMTJoinUpdateStrategy_None,
    ZMMTJoinUpdateStrategy_Login_Changed,
    ZMMTJoinUpdateStrategy_Content_Changed,
    ZMMTJoinUpdateStrategy_Silent_Changed,
    ZMMTJoinUpdateStrategy_ConnectedMMR,
    ZMMTJoinUpdateStrategy_Silent_Countdown,
    
    ZMMTJoinUpdateStrategy_Preview_Audio_Status,
    ZMMTJoinUpdateStrategy_Preview_Video_Status,
    ZMMTJoinUpdateStrategy_Preview_Lipsync_State,
    
    ZMMTJoinUpdateStrategy_Preview_Camera_Changed,
    ZMMTJoinUpdateStrategy_Status_NonHost_Changed,
    ZMMTJoinUpdateStrategy_Status_Preview_Changed,
    ZMMTJoinUpdateStrategy_Status_Topic_Changed,
    
    ZMMTJoinUpdateStrategy_Waiting_Image_Status, //defult Image
    ZMMTJoinUpdateStrategy_Waiting_Logo_Status,
    ZMMTJoinUpdateStrategy_Waiting_Video_Status,
    ZMMTJoinUpdateStrategy_Waiting_Video_Progress,
    ZMMTJoinUpdateStrategy_Waiting_Video_PausePlay,
};

#endif /* ZMUIConstants_h */
