//
// Simple test for the AP_AHRS interface
//

#include "mengchuang.h"
void setup();
void loop();
const AP_HAL::HAL& hal = AP_HAL::get_HAL();
// static AP_SerialManager serial_manager;
// AP_Int32 logger_bitmask;
// static AP_Logger logger{logger_bitmask};

// static MChuang vehicle;

// choose which AHRS system to use
// AP_AHRS_DCM ahrs = AP_AHRS_DCM::create(barometer, gps);
// auto &ahrs = vehicle.ahrs;

void setup(void)
{

    // vehicle.init();
    // serial_manager.init();
    // AP::compass().init();
    // if (!AP::compass().read()) {
    //     hal.console->printf("No compass detected\n");
    // }
    // AP::gps().init(serial_manager);
    //hal.gpio->init();
    //hal.gpio->pinMode(0, 1);
    
}

void loop(void)
{
    hal.gpio->write(0,1);

    hal.scheduler->delay(200);
    // static uint16_t counter;
    // static uint32_t last_t, last_print, last_compass,last_update;
    // uint32_t now = AP_HAL::micros();
    // //float heading = 0;
    // mavlink_msg_heartbeat_send(
    //     MAVLINK_COMM_0,
    //     gcs().frame_type(),
    //     MAV_AUTOPILOT_ARDUPILOTMEGA,
    //     MAV_MODE_STABILIZE_DISARMED,
    //     gcs().custom_mode(),
    //     MAV_STATE_ACTIVE);
    // if (last_t == 0) {
    //     last_t = now;
    //     return;
    // }
    // last_t = now;

    // if (now - last_compass > 100 * 1000UL &&
    //     AP::compass().read()) {
    //     //heading = AP::compass().calculate_heading(ahrs.get_rotation_body_to_ned());
    //     // read compass at 10Hz
    //     last_compass = now;
    // }

    // ahrs.update();
    // counter++;

    // if (now - last_print >= 100000 /* 100ms : 10hz */) {
    //     vehicle.drift  = ahrs.get_gyro_drift();
    //     vehicle.omega = ahrs.get_gyro();
    //     // hal.console->printf(
    //     //         "r:%4.1f  p:%4.1f y:%4.1f "
    //     //             "drift=(%5.1f %5.1f %5.1f) hdg=%.1f rate=%.1f\n",
    //     //         (double)ToDeg(ahrs.roll),
    //     //         (double)ToDeg(ahrs.pitch),
    //     //         (double)ToDeg(ahrs.yaw),
    //     //         (double)ToDeg(drift.x),
    //     //         (double)ToDeg(drift.y),
    //     //         (double)ToDeg(drift.z),
    //     //         (double)(AP::compass().use_for_yaw() ? ToDeg(heading) : 0.0f),
    //     //         (double)((1.0e6f * counter) / (now-last_print)));
    //     // last_print = now;
    //     counter = 0;
    //     // mavlink_msg_ahrs_send(
    //     // MAVLINK_COMM_0,
    //     // drift.x,
    //     // drift.y,
    //     // drift.z,
    //     // 0,
    //     // 0,
    //     // ahrs.get_error_rp(),
    //     // ahrs.get_error_yaw());
    //     // hal.scheduler->delay(200);
    //     // mavlink_msg_attitude_send(
    //     // MAVLINK_COMM_0,
    //     // AP_HAL::millis(),
    //     // ahrs.roll,
    //     // ahrs.pitch,
    //     // ahrs.yaw,
    //     // omega.x,
    //     // omega.y,
    //     // omega.z);
    // }
    // if (now - last_update >= 10000 /* 100ms : 10hz */) {
    //     gcs().update_receive();
    //     hal.scheduler->delay(50);
    //     gcs().update_send();
    //     last_update = now;  
    //     mavlink_msg_ahrs_send(
    //     MAVLINK_COMM_0,
    //     vehicle.drift.x,
    //     vehicle.drift.y,
    //     vehicle.drift.z,
    //     0,
    //     0,
    //     ahrs.get_error_rp(),
    //     ahrs.get_error_yaw());
    //     hal.scheduler->delay(200);
    //     mavlink_msg_attitude_send(
    //     MAVLINK_COMM_0,
    //     AP_HAL::millis(),
    //     ahrs.roll,
    //     ahrs.pitch,
    //     ahrs.yaw,
    //     vehicle.omega.x,
    hal.gpio->write(0,0);
    //     vehicle.omega.y,
    //     vehicle.omega.z);
    // }
    hal.scheduler->delay(500);
}

// const struct AP_Param::GroupInfo        GCS_MAVLINK_Parameters::var_info[] = {
//     AP_GROUPEND
// };
// GCS_MChuang _gcs;

AP_HAL_MAIN();
