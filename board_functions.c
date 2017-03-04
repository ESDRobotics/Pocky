#include <pocky.h>

/* Begin Board Functions (or more like *bored* functions, ehh? haha) */

void start_up() {
  msleep(1000);
  enable_servos();
  pitchfork(up, fast);
  rotate_grip(20, 2500, forwards);
  rotate_grip(-20, 2500, backwards);
  msleep(1000);
}

void basket_pickup() {
  drive_distance(50, 118, backwards);
  turn(50,(int)(full_rotation)*.248, forwards);
  drive_distance(35, 60, backwards);
  pitchfork(down, medium);
  drive_distance(50, 65, forwards);
  pitchfork(carry, medium);
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
  rotate_grip(medium, 7500, forwards);
  rotate_grip(medium, 7500, backwards);
  rotate_grip(medium, 7500, forwards);
  rotate_grip(medium, 7500, backwards);
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
