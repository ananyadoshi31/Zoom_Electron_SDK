//
//  ZMShareSelectDef.h
//  ZCommonUI
//
//  Created by walt.li on 9/21/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

typedef NS_ENUM(NSInteger, ZMShareSoundsMode){
    ZMShareSoundsMode_Mono,
    ZMShareSoundsMode_Stereo,
};

typedef NS_ENUM(NSInteger, ZMShareSelectItemType) {
    ZMShareSelectItemEmpty = -1,
    ZMShareSelectItemUnknown = 0, //old client
    ZMShareSelectItemAs,    //application share
    ZMShareSelectItemDs,    //desktop share
    ZMShareSelectItemWb,    //whiteboard share
    ZMShareSelectItemAirhost,    //mobile device from PC
    ZMShareSelectItemCamera,    //camera share
    ZMShareSelectItemWiredDevice, //wired device, connect between Mac and iPhone
    ZMShareSelectItemFrame, //share a selected region area of desktop
    ZMShareSelectItemComputerAudio, //pure computer audio share, note: this type is different with other share
    ZMShareSelectItemDropbox, //share dropbox, open dropbox website in default browser
    ZMShareSelectItemOneDriver,
    ZMShareSelectItemGoogleDriver,
    ZMShareSelectItemBox,//SSB_MC_AS_SHARED_OBJ_BOX,
    ZMShareSelectItemDoc,
    ZMShareSelectItemMsSharePoint, //ZOOM-135932
    ZMShareSelectItemPs,
    ZMShareSelectItemVideo,
    ZMShareSelectItemZoomApps,
};
