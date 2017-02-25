#include <kipr/botball.h>
#include <pocky.h>

int main()
{
    set_servo_position(arm,arm_up);
    enable_servos();
    move_servo(arm, arm_up, fast);
    msleep(1000);
    drive_distance(-50,120,1);
    msleep(3000);
    disable_servos();
    return 0;
}
