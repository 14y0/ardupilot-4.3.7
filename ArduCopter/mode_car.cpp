#include "Copter.h"

#if MODE_CAR_ENABLED == ENABLED
#define Turn_Channel (int16_t)last_value[0]
#define Thr_Channel (int16_t)last_value[2]
#define Lock_Channel (int16_t)last_value[5]
#define Turn_Mid 1500
#define Thr_Mid 1500
#define Threshold 350
#define Up_Rate 35

bool ModeCar::init(bool ignore_checks)
{
    // only allow flip from some flight modes, for example ACRO, Stabilize, AltHold or FlowHold flight modes
    // ensure roll input is less than 40deg
    if (abs(channel_roll->get_control_in()) >= 4000) {
        return false;
    }
    Differ_Speed=0;
    Thr_Forward_L=0;
    Thr_Backup_L=0;
    Thr_Forward_R=0;
    Thr_Backup_R=0;
    return true;
}

// run - runs the flip controller
// should be called at 100hz or more
void ModeCar::run()
{
    attitude_control->input_euler_angle_roll_pitch_euler_rate_yaw(0.0f,0.0f , 0.0f);
    read_channels();
    update_Thr();
    attitude_control->set_throttle_out(0, true, g.throttle_filt);

}


void ModeCar::output_to_motors()
{
    if (Lock_Channel<1500){
        motors->rc_write(4,0);
        motors->rc_write(5,0);
        motors->rc_write(6,0);
        motors->rc_write(7,0);
        motors->rc_write(0,0);
        motors->rc_write(1,0);
        motors->rc_write(2,0);
        motors->rc_write(3,0);
    }
    else{
        motors->rc_write(6,Thr_Forward_L);
        motors->rc_write(7,Thr_Backup_L);
        motors->rc_write(5,Thr_Forward_R);
        motors->rc_write(4,Thr_Backup_R);
        motors->rc_write(0,0);
        motors->rc_write(1,0);
        motors->rc_write(2,0);
        motors->rc_write(3,0);
    }

}

void ModeCar::update_Thr(void)
{
    int16_t Thr_Fix = 0;
		Differ_Speed = Turn_Channel - Turn_Mid;
	    //printf(" Differ_Speed:%d",Differ_Speed);
		if (Differ_Speed>Threshold)//上边界 threshold=1000
		{
			Differ_Speed = Threshold;
		}
		if (Differ_Speed<-Threshold)//下边界
		{
			Differ_Speed = -Threshold;
		}
		//left
		Thr_Fix = Thr_Channel+Differ_Speed;
		if ((Thr_Fix-Thr_Mid)>0)
		{
			if ((Thr_Fix-Thr_Mid)>500)
			{
				Thr_Fix = 500+Thr_Mid;
			}
			Thr_Forward_L = (Thr_Fix-Thr_Mid)*Up_Rate;//保证在0——10000之间 ，前轮
			Thr_Backup_L = 0; 
		}
		else
		{
			if ((Thr_Fix-Thr_Mid)<-500)
			{
				Thr_Fix = Thr_Mid-500;
			}
			Thr_Backup_L = (Thr_Fix-Thr_Mid)*-Up_Rate;
			Thr_Forward_L = 0;
		}
		//right
		Thr_Fix = Thr_Channel-Differ_Speed;
		if ((Thr_Fix-Thr_Mid)>0)
		{
			if ((Thr_Fix-Thr_Mid)>1500)
			{
				Thr_Fix = 1500+Thr_Mid;
			}
			Thr_Forward_R = (Thr_Fix-Thr_Mid)*Up_Rate;
			Thr_Backup_R = 0;
		}
		else
		{
			if ((Thr_Fix-Thr_Mid)<-1500)
			{
				Thr_Fix = Thr_Mid-1500;
			}
			Thr_Backup_R = (Thr_Fix-Thr_Mid)*-Up_Rate;
			Thr_Forward_R = 0;
		}
}
void ModeCar::read_channels(void)
{
    uint8_t nchannels = hal.rcin->num_channels();  // Get the numbers channels detected by RC_INPUT.
    if (nchannels == 0) {
        return;
    }

    if (nchannels > 8) {
        nchannels = 8;
    }

    for (uint8_t i = 0; i < nchannels; i++) {
        uint16_t v = hal.rcin->read(i);
        if (last_value[i] != v) {
            last_value[i] = v;
        }
    }

}

#endif
