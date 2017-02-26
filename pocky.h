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

void drive_distance(int speed, int distance, int direction) {
  int tick_distance = ticks_per_centimeter * distance;
	clear_motor_position_counter(left_motor);
	while (fabs(get_motor_position_counter(left_motor)) < tick_distance){
    /* LOGGING PURPOSES:
    printf("I need to go: %d, but I have only gone %f!\n", tick_distance, fabs(get_motor_position_counter(left_motor)));
    //*/
		motor(left_motor, (int)(speed*direction*l_motor_factor));
		motor(right_motor, (int)(speed*direction));
	}
	msleep(0);
  ao();
  msleep(250);
}

void rotate_grip(int speed, int time, int dir) {
  motor(gripper, speed*dir);
  msleep(time);
  ao();
  msleep(250);
}

// PEOPLE TOLD ME I WAS INSANE WHEN I VOWED TO IMPLEMENT RECURSION
// NOW THEY'll SEE! THEY'll ALL SEE! AHAHAAHAHAHAHHAHAHAA
void move_servo(int port, int desired_pos, int speed) {
  int actual_pos = get_servo_position(port);
  if(actual_pos/10 > desired_pos/10) {
     set_servo_position(port, actual_pos-10);
     msleep(speed);
     move_servo(port, desired_pos, speed);
  }
  if(actual_pos/10 < desired_pos/10) {
     set_servo_position(port, actual_pos+10);
     msleep(speed);
     move_servo(port, desired_pos, speed);
  }
}

void pitchfork(int position, int speed) {
  move_servo(arm, position, speed);
  msleep(250);
}

void turn(int speed, int time, int direction) {
  motor(left_motor, -direction*speed*l_motor_factor);
  motor(right_motor, direction*speed*r_motor_factor);
  msleep(time);
  ao();
  msleep(250);
}
