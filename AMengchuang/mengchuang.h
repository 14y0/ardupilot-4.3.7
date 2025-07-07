#pragma once
#include <cmath>
#include <stdarg.h>
#include <stdint.h>

// Libraries
#include <AP_Common/AP_Common.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_Logger/AP_Logger.h>



// #include <AP_AHRS/AP_AHRS.h>
// #include <AP_BoardConfig/AP_BoardConfig.h>
// #include <AP_BattMonitor/AP_BattMonitor.h>          // Battery monitor library
// #include <AP_Camera/AP_Camera.h>                    // Camera triggering
// #include <AP_Mount/AP_Mount.h>                      // Camera/Antenna mount
// #include <AP_Param/AP_Param.h>
// #include <AP_RangeFinder/AP_RangeFinder.h>          // Range finder library
// #include <AP_RCMapper/AP_RCMapper.h>                // RC input mapping library
// #include <AP_RPM/AP_RPM.h>                          // RPM input library
// #include <AP_Scheduler/AP_Scheduler.h>              // main loop scheduler
// #include <AP_Vehicle/AP_Vehicle.h>                  // needed for AHRS build
// #include <AP_WheelEncoder/AP_WheelEncoder.h>
// #include <AP_WheelEncoder/AP_WheelRateControl.h>
// #include <AP_Logger/AP_Logger.h>
// #include <AP_OSD/AP_OSD.h>
// // #include <AR_Motors/AP_MotorsUGV.h>
// #include <AP_Mission/AP_Mission.h>
// #include <AP_Mission/AP_Mission_ChangeDetector.h>
// #include <AR_WPNav/AR_WPNav_OA.h>
// #include <AP_RangeFinder/AP_RangeFinder.h
// #include <AP_GPS/AP_GPS.h>
// #include <AP_Baro/AP_Baro.h>
// #include <AP_ExternalAHRS/AP_ExternalAHRS.h>
// #include "GCS_MChuang.h"
// #include <RC_Channel/RC_Channel.h>

// static AP_SerialManager serial_manager;
// AP_Int32 logger_bitmask;
// static AP_Logger logger{logger_bitmask};
// class MChuang : public AP_Vehicle {
// public:
//     Vector3f drift;
//     Vector3f omega;
//     AP_AHRS ahrs{AP_AHRS::FLAG_ALWAYS_USE_EKF};
//     bool set_mode(const uint8_t new_mode, const ModeReason reason) override { return true; };
//     uint8_t get_mode() const override { return 1; };
//     void get_scheduler_tasks(const AP_Scheduler::Task *&tasks, uint8_t &task_count, uint32_t &log_bit) override {};
//     void init_ardupilot() override {};
//     void load_parameters() override {};
//     void init() {
//         BoardConfig.init();
//         ins.init(100);
//         ahrs.init();
//         gcs().init();
//         gcs().setup_console();
//     }

// };