// Driving
#define left_motor 0
#define right_motor 1
#define forwards 1 // Pitchfork/Claw side
#define backwards -1 // Spinny-grip-thing-still-haven't-named side
#define ticks 1317
#define ticks_per_centimeter ticks/18
#define r_motor_factor 1.0
#define l_motor_factor 0.99
#define full_rotation 3700  // Time in miliseconds it takes to turn 360 degrees at speed 50
                            // (Super rough, but all the turn functions do what I want them to do so...
                            // expect to need to use small modifiers in usage, but *DO NOT* change this)

// Servo Speeds
#define slow  50
#define medium  10
#define fast  5

// Arm
#define arm  1
#define up 435
#define carry  1250
#define down  1859

// Grip
#define gripper 2

// Recursion was fun but it hurt my eyes to look at
// so it's getting changed, again
// This is more efficient, accurate, and doesn't suck
void drive_distance(int speed, int distance, int direction) {
  clear_motor_position_counter(left_motor);
  clear_motor_position_counter(right_motor);
  motor(left_motor,  (speed * direction * l_motor_factor));
  motor(right_motor, (speed * direction * r_motor_factor));
  while(motor_recalibration(distance)) {
    //* LOGGING PURPOSES:
    printf("I need to go: %d, but I have only gone %f!\n", tick_distance, fabs(get_motor_position_counter(left_motor)));
    //*/
  }
  ao();
  msleep(250);
}

boolean motor_recalibration(int distance) {
  r_motor_dist = fabs(get_motor_position_counter(right_motor));
  l_motor_dist =  fabs(get_motor_position_counter(left_motor));
  int avg_motor_pos = (r_motor_dist + l_motor_dist) / 2;
  int tick_distance = ticks_per_centimeter * distance;
  return avg_motor_pos < tick_distance;
}

void turn(int speed, int time, int direction) {
  motor(left_motor, -direction * speed * l_motor_factor);
  motor(right_motor, direction * speed * r_motor_factor);
  msleep(time);
  ao();
  msleep(250);
}

void rotate_grip(int speed, int time, int dir) {
  motor(gripper, speed * dir);
  msleep(time);
  ao();
  msleep(250);
}

// TODO: Change pls
void move_servo(int port, int position, int speed) {
    int pos;
    for(pos = get_servo_position(port); pos > position; pos -= 10) {
       set_servo_position(port,pos);
       msleep(speed);
    }
    for(pos = get_servo_position(port); pos < position; pos += 10) {
       set_servo_position(port,pos);
       msleep(speed);
    }
    msleep(250);
}

void pitchfork(int position, int speed) {
    moveServo(arm, position, speed);
    msleep(250);
}
