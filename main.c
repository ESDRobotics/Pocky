#include <kipr/botball.h>
#include <pocky_spin.h>
#define front_right 0
#define front_left 1
#define back_right 2
#define back_left 3
#define left 0
#define right 1
#define right_90_turn 2125
#define left_90_turn 2525

/*
All functions in pocky_spin.h:
spin()
drive_straight(int speed, int time)
turn(int direction, int time)
claw(int position)
align_black()
drive_cm (int cm)
tick_turn_right(int degrees)
tick_turn_left(int degrees)
drive_cm_back (int cm)
void drive_cm_ramp (int cm)
*/
        
int main()
{
  enable_servos();
  set_servo_position(0, 1700);
  set_servo_position(1, 0);
  drive_cm (118);
  msleep(500);
  tick_turn_right(89);
  msleep(500);
  drive_cm (27);
  msleep(500);
  claw(70);
  msleep(500);
  drive_cm_back (30);
  msleep(500);
  tick_turn_right(83);
  msleep(500);
  drive_cm (75);
  msleep(500);
  align_black();
  msleep(1000);
  tick_turn_right(87);
  msleep(500);
  set_servo_position(0, 500);
  msleep(500);
  black_line();
  msleep(500);
  drive_cm(7);
  msleep(500);
  spin();
  spin();
  spin();
  spin();
  spin();
  msleep(500);
  drive_cm_back (75);
  msleep(500);
  drive_cm (3);
  msleep (500);
  claw(70);
  msleep(500);
  tick_turn_right(87);
  msleep(500);
  drive_cm_back (50);
  msleep(500);
  drive_cm (30);
  msleep(500);
  set_servo_position(0, 500);
  msleep(500);
  drive_cm_ramp (150);
  msleep(500);
  set_servo_position(0,0);
  msleep(500);
  drive_cm_ramp(30);
  msleep(500);
  set_servo_position(0,1000);
  msleep(500);
  ao();
  /*
  enable_servos();
  set_servo_position(0, 1700);
  set_servo_position(2, 0);
  drive_straight(100, 7000);
  msleep(500);
  turn(right, 2400);
  msleep(500);
  drive_straight(100, 1250);
  msleep(500);
  claw(70);
  msleep(500);
  drive_straight(-100, 1450);
  msleep(500);
  turn(right, 2000);
  msleep(500);
  align_black();
  msleep(500);
  turn(right, 2100);
  msleep(500);
  set_servo_position(0, 500);
  msleep(500);
  drive_straight(100, 1400);
  msleep(500);
  spin();
  spin();
  spin();
  spin();
  spin();
  msleep(500);
  claw(70);
  drive_straight(-100, 1450);
  msleep(500);
  ao();
  */
}
