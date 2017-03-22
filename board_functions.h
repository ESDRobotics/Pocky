#include <pocky.h>

/* Begin Board Functions (or more like *bored* functions, ehh? haha) */

// the method used before the robot actually starts going anywhere, makes sure all servos are in right position
void start_up() {
  msleep(1000);
  pitchfork(up, fast);
  set_servo_position(wheel,get_servo_position(wheel));
  move_servo(sled, 1740, fast);  //Optimally, we would do 432, but, in order to spite Duke, 433 is advised.
  enable_servos();
  msleep(100);
}

//the method that drives the robot from the starting box and picks up the basket
void basket_pickup() {
  set_servo_position(wheel,325);
  drive_distance_awd(50, 125, backwards);
  msleep(10);
  //move_servo(sled,0,medium);
  msleep(10);
  while (get_servo_position(wheel)<1090){
      set_servo_position(wheel,get_servo_position(wheel)+50);
      msleep(100);
  }
  set_servo_position(wheel, 1090);
  msleep(1000);
  turn(30,(int)(full_rotation)*.52, forwards); //.248
  msleep(1500);
  drive_distance(35, 50, backwards); //might not be necessary
  pitchfork(down, medium);
  drive_to_basket(50, 66, forwards);
  pitchfork(carry, slow);
}

//the method that backs up from the bin area and goes to the fertilizer thing, including putting the basket below the fertilizer and backs up and turns
void to_dispenser() {
  drive_distance(50, 25, backwards);
  turn(50,(int)(full_rotation)*.27, backwards);
  drive_distance(50, 95, forwards);
  pitchfork(down-200, medium);
  set_servo_position(wheel,1920);
  turn(15,(int)(full_rotation)*.9, backwards);
  pitchfork(down, medium);
  drive_distance(30,7,forwards);
  drive_distance(30, 20, backwards);
  pitchfork(up, fast);
  turn(30,(int)(full_rotation)*1.05, backwards);
}

// TODO finish this --> the method that drives up to the fertilizer and turns the handle to get the poms
void use_dispenser() {
  drive_distance(30, 18, backwards);
  rotate_grip(medium, 8000, forwards);
  rotate_grip(medium, 8000, backwards);
  rotate_grip(medium, 8000, forwards);
  rotate_grip(medium, 8000, backwards);
  rotate_grip(medium, 8000, forwards);
  rotate_grip(medium, 8000, backwards);
  drive_distance(30, 20, forwards);
  turn(50,(int)(full_rotation)*.54, forwards);
  pitchfork(down, slow);
  drive_distance(50, 40, backwards);
  pitchfork(carry, slow);
  drive_distance(30, 20, forwards);
}

// TODO start this --> the method that gets basket back and drives up to ramp
void to_bridge() {

}

// TODO start this
void celebration() {

}

void shutdown() {
  msleep(3000);
  disable_servos();
}
