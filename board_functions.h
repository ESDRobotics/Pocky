#include <pocky.h>

/* Begin Board Functions (or more like *bored* functions, ehh? haha) */

void start_up() {
  msleep(1000);
  enable_servos();
  pitchfork(up, fast);
  set_servo_position(wheel,get_servo_position(wheel));
  move_servo(sled, 1750, fast);  //Optimally, we would do 432, but, in order to spite Duke, 433 is advised.
  msleep(1000);
}

void basket_pickup() {
 	set_servo_position(wheel,325);
  drive_distance_awd(50, 118, backwards);
  set_servo_position(wheel, 1090);
  turn(50,(int)(full_rotation)*.29, forwards); //.248
  msleep(10);
  move_servo(sled,0,fast);
  drive_distance(35, 60, backwards);
  pitchfork(down, medium);
  //move_servo(sled,433,fast);
  drive_distance(50, 67, forwards);
  pitchfork(carry, slow);
}

void to_dispenser() {
  drive_distance(50, 25, backwards);
  turn(50,(int)(full_rotation)*.248, backwards);
  drive_distance(50, 91, forwards);
  pitchfork(down-200, medium);
  turn(15,(int)(full_rotation), backwards);
  pitchfork(down, slow);
  drive_distance(30, 15, backwards);
  pitchfork(up, fast);
  turn(50,(int)(full_rotation)*.54, forwards);
}

// TODO finish this
void use_dispenser() {
  drive_distance(30, 20, backwards);
  rotate_grip(medium, 6000, forwards);
  rotate_grip(medium, 6000, backwards);
  rotate_grip(medium, 6000, forwards);
  rotate_grip(medium, 6000, backwards);
  rotate_grip(medium, 6000, forwards);
  rotate_grip(medium, 6000, backwards);
  drive_distance(30, 20, forwards);
  turn(50,(int)(full_rotation)*.54, forwards);
  pitchfork(down, slow);
  drive_distance(50, 40, backwards);
  pitchfork(carry, slow);
  drive_distance(30, 20, forwards);
}

// TODO start this
void to_bridge() {

}

// TODO start this
void celebration() {

}

void shutdown() {
  msleep(3000);
  disable_servos();
}