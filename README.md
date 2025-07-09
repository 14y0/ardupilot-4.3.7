# ardupilot-4.3.7
ardupilot 4.3.7版本魔改的魔改，在添加了top、climb、recovery等模式的基础上完善recovery模式

本版本在pid控制成功版本上修改：
1：删除PIDcontroller.c里的icxxxxxx头文件，解决gcc报错问题。
2：修改mode_climb.cpp里的init函数，在第二个if判断中增加&& copter.flightmode->mode_number() != Mode::Number::ALT_HOLD 允许alt_hold模式切换到climb。
3：修改mode_recovery.cpp里的油门输出，将文件最后注释掉的油门输出移至start中，并将角度补偿改为false、输入改为30%。
4：修改修改mode_recovery.cpp里的定高高度，由1000改为150，同时修改了定高稳定判断。
5：注释掉了mode_recovery.cpp里的所有printf大法。

2.0：
本版本实现一键起飞模式（ModeAuto_takeoff），模式编号为34，遥控器通道模式编码为311。此模式仿照Alt_Hold实现。

3.0：
1、考虑解决加入轮胎增高架后TOP模式失效的问题，首次尝试失败。
2、试图将TOP模式的恢复接入Recovery模式中。

分支：
为了演示暂时去掉不成熟的TOP恢复
