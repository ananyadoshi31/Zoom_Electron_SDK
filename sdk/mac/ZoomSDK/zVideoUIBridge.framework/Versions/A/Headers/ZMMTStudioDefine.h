//
//  ZMMTStudioDefine.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef ZMMTStudioDefine_h
#define ZMMTStudioDefine_h

#include <zStudioApp/StudioDef.h>

static inline StudioCanvasRect StudioCanvasRectFromNSRect(NSRect rect) {
    StudioCanvasRect rc;
    rc.x = rect.origin.x;
    rc.y = rect.origin.y;
    rc.w = rect.size.width;
    rc.h = rect.size.height;
    return rc;
}
static inline NSRect NSRectFromStudioCanvasRect(StudioCanvasRect rect) {
    return NSMakeRect(rect.x, rect.y, rect.w, rect.h);
}

#endif /* Header_h */
