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
#define arm  2 //servo that lifts/lowers basket-carryig claw
#define up 435 //positions for "arm" servo
#define carry  1250
#define down  1859

// Grip
#define gripper 2 //the motor that turns the fertilizer handle


// Back Weight-bearer
#define wheel 3 // servo that lifts/lowers the larger third wheel
#define wheel_motor 3 //motor that drives third wheel
#define sled 0 //servo that lifts/lowers sled thing that helps balance robot

int motor_recalibration(int distance);
void move_servo(int port, int position, int speed);

// Recursion was fun but it hurt my eyes to look at
// so it's getting changed, again
// This is more efficient, accurate, and doesn't suck
// method that drives the robot a certain distance, but only using two smaller wheels
void drive_distance(int speed, int distance, int direction) {
  clear_motor_position_counter(left_motor);
  clear_motor_position_counter(right_motor);
  motor(left_motor,  (speed * direction * l_motor_factor));
  motor(right_motor, (speed * direction * r_motor_factor));
  while(motor_recalibration(distance)) {
    //* LOGGING PURPOSES:
    printf("I need to go: somewhere, but I have only gone %f!\n", fabs(get_motor_position_counter(left_motor)));
    //*/
  }
  ao();
  msleep(250);
}

//method that uses all three wheels to drive robot
void drive_distance_awd(int speed, int distance, int direction) {
  clear_motor_position_counter(left_motor);
  clear_motor_position_counter(right_motor);
  motor(left_motor,  (speed * direction * l_motor_factor));
  motor(right_motor, (speed * direction * r_motor_factor));
  motor(wheel_motor, (speed * direction * r_motor_factor));
  while(motor_recalibration(distance)) {
    //* LOGGING PURPOSES:
    printf("I need to go: somewhere, but I have only gone %f!\n", fabs(get_motor_position_counter(left_motor)));
    //*/
  }
  ao();
  msleep(250);
}

int motor_recalibration(int distance) {
  int r_motor_dist = fabs(get_motor_position_counter(right_motor));
  int l_motor_dist =  fabs(get_motor_position_counter(left_motor));
  int avg_motor_pos = (r_motor_dist + l_motor_dist) / 2;
  int tick_distance = ticks_per_centimeter * distance;
  return avg_motor_pos < tick_distance;
}

//method that turns the robot
void turn(int speed, int time, int direction) {
  motor(left_motor, direction * speed * l_motor_factor);
  motor(right_motor, -direction * speed * r_motor_factor);
  msleep(time);
  ao();
  msleep(250);
}

//method that rotates the fertilizer handle
void rotate_grip(int speed, int time, int dir) {
  motor(gripper, speed * dir);
  msleep(time);
  ao();
  msleep(250);
}

// changes servo positions
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

//method that lifts/lowers the claw that holds basket
void pitchfork(int position, int speed) {
    move_servo(arm, position, speed);
    msleep(250);
}
