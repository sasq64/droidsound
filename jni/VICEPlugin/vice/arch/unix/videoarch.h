#include "vice.h"

#if defined(GP2X) || defined(WIZ)
#include "gp2x/videoarch.h"
#else
#ifdef USE_GNOMEUI
#include "x11/gnome/videoarch.h"
#else
#ifdef VMS
#include "x11xawvideoarch.h"
#else
#include "x11/xaw/videoarch.h"
#endif
#endif
#endif
