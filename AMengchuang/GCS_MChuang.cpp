#include "GCS_MChuang.h"

void GCS_MChuang::send_textv(MAV_SEVERITY severity, const char *fmt, va_list arg_list, uint8_t dest_bitmask)
{
#if !APM_BUILD_TYPE(APM_BUILD_Replay)
    DEV_PRINTF("TOGCS: ");
    hal.console->vprintf(fmt, arg_list);
    DEV_PRINTF("\n");
#else
    ::printf("TOGCS: ");
    ::vprintf(fmt, arg_list);
    ::printf("\n");
#endif
}