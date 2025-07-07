/*
  simple test of RC output interface
  Attention: If your board has safety switch,
  don't forget to push it to enable the PWM output.
 */

#include <AP_HAL/AP_HAL.h>

// we need a boardconfig created so that the io processor's enable
// parameter is available
#if CONFIG_HAL_BOARD == HAL_BOARD_CHIBIOS
#include <AP_BoardConfig/AP_BoardConfig.h>
#include <AP_IOMCU/AP_IOMCU.h>
AP_BoardConfig BoardConfig;
#endif

void setup();
void loop();

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

void setup (void)
{
    hal.console->printf("Starting AP_HAL::RCOutput test\n");
#if CONFIG_HAL_BOARD == HAL_BOARD_CHIBIOS //初始化IO板
    hal.console->printf("boardinit");
    BoardConfig.init();
#endif
    for (uint8_t i = 0; i< 14; i++) {
        hal.rcout->enable_ch(i); //使能PWM输出通道（包括IO板及主控板）
    }
    hal.rcout->set_freq(1,300); //设置PWM输出通道频率，默认值为50HZ
    hal.rcout->set_freq(0,300); //注意：根据PWM通道分组的不同部分PWM通道不允许频率超过50HZ
    hal.rcout->set_freq(3,200);
    hal.rcout->force_safety_off();//安全按钮强制解锁
}

static uint16_t pwm = 0;

void loop (void)
{
    int16_t user_input;
    hal.rcout->write(1, pwm); //设置PWM脉宽
    hal.rcout->write(0, pwm);
    hal.rcout->write(3, pwm);

    // read in user input
    while (hal.console->available()) { 
        user_input = hal.console->read();//获取串口输入，根据串口输入改变占空比

        if (user_input == 'D' || user_input == 'd') {
           pwm=4500;
        }

        if (user_input == 'T' || user_input == 't') {
           pwm=0 ;
        }

    }

}

AP_HAL_MAIN();
