#pragma once
#include <GCS_MAVLink/GCS.h>
#include "GCS_Mavlink.h"
#define THISFIRMWARE "GCSMChuang V3.1.4-dev"

#define FW_MAJOR 3
#define FW_MINOR 1
#define FW_PATCH 4
#define FW_TYPE FIRMWARE_VERSION_TYPE_DEV

/*
 *  GCS backend used for many examples and tools
 */


/*
 * a GCS singleton used for many example sketches and tools
 */

extern const AP_HAL::HAL& hal;

class GCS_MChuang : public GCS
{
public:

    using GCS::GCS;

protected:

    uint8_t sysid_this_mav() const override { return 1; }

    GCS_MAVLINK_MChuang *new_gcs_mavlink_backend(GCS_MAVLINK_Parameters &params,
                                               AP_HAL::UARTDriver &uart) override {
        return new GCS_MAVLINK_MChuang(params, uart);
    }

private:
    GCS_MAVLINK_MChuang *chan(const uint8_t ofs) override {
        if (ofs > _num_gcs) {
            INTERNAL_ERROR(AP_InternalError::error_t::gcs_offset);
            return nullptr;
        }
        return (GCS_MAVLINK_MChuang *)_chan[ofs];
    };
    const GCS_MAVLINK_MChuang *chan(const uint8_t ofs) const override {
        if (ofs > _num_gcs) {
            INTERNAL_ERROR(AP_InternalError::error_t::gcs_offset);
            return nullptr;
        }
        return (GCS_MAVLINK_MChuang *)_chan[ofs];
    };

    void send_textv(MAV_SEVERITY severity, const char *fmt, va_list arg_list, uint8_t dest_bitmask) override;

    MAV_TYPE frame_type() const override { return MAV_TYPE_FIXED_WING; }
    uint32_t custom_mode() const override { return 3; } // magic number
};
