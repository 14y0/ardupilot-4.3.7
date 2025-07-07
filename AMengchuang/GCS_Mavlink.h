#pragma once

#include <GCS_MAVLink/GCS.h>
#include "mengchuang.h"
class GCS_MAVLINK_MChuang : public GCS_MAVLINK
{
public:
    using GCS_MAVLINK::GCS_MAVLINK;

private:

    uint32_t telem_delay() const override { return 0; }
    void handleMessage(const mavlink_message_t &msg) override {}
    bool try_send_message(enum ap_message id) override { return true; }
    bool handle_guided_request(AP_Mission::Mission_Command &cmd) override { return true; }

protected:

    uint8_t sysid_my_gcs() const override { return 1; }

    // dummy information:
    MAV_MODE base_mode() const override { return (MAV_MODE)MAV_MODE_FLAG_CUSTOM_MODE_ENABLED; }
    MAV_STATE vehicle_system_status() const override { return MAV_STATE_CALIBRATING; }

    bool set_home_to_current_location(bool _lock) override { return false; }
    bool set_home(const Location& loc, bool _lock) override { return false; }

    void send_nav_controller_output() const override {};
    void send_pid_tuning() override {};
};
