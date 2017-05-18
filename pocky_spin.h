#include <kipr/botball.h>
#define front_right 0
#define front_left 1
#define back_right 2
#define back_left 3
#define left 0
#define right 1
#define left_light 0
#define right_light 1
#define threshold 3500
        
void spin (){
  set_servo_position(1, 0);
  msleep(1000);
  set_servo_position(1, 2047);
  msleep(1000);
}

void drive_straight(int speed, int time){
 motor (front_right, speed * .87);
 motor (front_left, speed);
 motor (back_left, speed);
 motor (back_right, speed * .87);
 msleep (time);
  ao();
}
void drive_straight_ramp(int speed, int time){
 motor (front_right, speed * .9);
 motor (front_left, speed);
 motor (back_left, speed);
 motor (back_right, speed * .9);
 msleep (time);
  ao();
}
void turn(int direction, int time){
if(direction == left){
 motor (front_right, 50);
 motor (front_left, -50);
 motor (back_left, -50);
 motor (back_right, 50);
 msleep (time);
  ao();
}
  else{
 motor (front_right, -50);
 motor (front_left, 50);
 motor (back_left, 50);
 motor (back_right, -50);
 msleep (time);
  ao();
}
}
  void claw(int position){
    while(get_servo_position(0) > position){
      set_servo_position(0, get_servo_position(0) - 75);
        msleep(100);
    }
  }
   void align_black(){
     while (analog(left_light) < threshold && analog(right_light) < threshold){
       drive_straight(50, 50);
     }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
     msleep(150);
     if (analog(right_light) > threshold)
     while(analog(left_light) < threshold){
     motor (front_left, 25);
     motor (back_left, 25);
       msleep(50);
     }
     else
     while(analog(right_light) < threshold){
     motor (front_right, 25);
     motor (back_right, 25);
       msleep(50);
     }
   }
void black_line(){
  while (analog(left_light)<threshold)
    drive_straight(25,50);
}
void drive_cm (int cm){
  int ticks = 90 * cm;
  clear_motor_position_counter(back_left);
 motor (front_right, 100 * .85);
 motor (front_left, 100);
 motor (back_left, 100);
 motor (back_right, 100 * .85);
  while(get_motor_position_counter(back_left) < ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}

void tick_turn_right(int degrees){
  int ticks = 17 * degrees;
  clear_motor_position_counter(back_left);
  motor (front_right, -50);
  motor (front_left, 50);
  motor (back_left, 50);
  motor (back_right, -50);
  while(get_motor_position_counter(back_left) < ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}

void tick_turn_left(int degrees){
  int ticks = 15 * degrees;
  clear_motor_position_counter(back_right);
  motor (front_right, 50);
  motor (front_left, -50);
  motor (back_left, -50);
  motor (back_right, 50);
  while(get_motor_position_counter(back_right) < ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}
void drive_cm_back (int cm){
  cm = cm * -1;
  int ticks = 90 * cm;
  clear_motor_position_counter(back_left);
 motor (front_right, -100 * .87);
 motor (front_left, -100);
 motor (back_left, -100);
 motor (back_right, -100 * .87);
  while(get_motor_position_counter(back_left) > ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}
void drive_cm_back_slow (int cm){
  cm = cm * -1;
  int ticks = 90 * cm;
  clear_motor_position_counter(back_left);
 motor (front_right, -75 * .87);
 motor (front_left, -75);
 motor (back_left, -75);
 motor (back_right, -75 * .87);
  while(get_motor_position_counter(back_left) > ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}
void drive_cm_ramp (int cm){
  int ticks = 90 * cm;
  clear_motor_position_counter(back_left);
 motor (front_right, 100 * .89);
 motor (front_left, 100);
 motor (back_left, 100);
 motor (back_right, 100 * .89);
  while(get_motor_position_counter(back_left) < ticks){
    msleep(10);
  }
  freeze(0);
  freeze(1);
  freeze(2);
  freeze(3);
}
