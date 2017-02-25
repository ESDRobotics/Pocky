// Driving
#define left_motor 0
#define right_motor 1
#define Forwards 1
#define Backwards -1
#define ticks 1317
#define ticks_per_centimeter ticks/18
#define r_motor_factor 1.0
#define l_motor_factor 0.99
#define full_rotation 3700  // Time in miliseconds it takes to turn 360 degrees at speed 50

// Servos
#define slow  50
#define medium  10
#define fast  5

// Arm
#define arm  1
#define up 435
#define carry  1250
#define down  1859
#define half  1437

// Grip
#define gripper 2

void driveDistance(int speed, int distance, int direction){
    int tick_distance = ticks_per_centimeter * distance;
	clear_motor_position_counter(left_motor);
	while (fabs(get_motor_position_counter(left_motor)) < tick_distance){
        // LOGGING PURPOSE: printf("I need to go: %d, but I have only gone %f!\n", tick_distance, fabs(get_motor_position_counter(left_motor)));
		motor (left_motor, (int)(speed*direction*l_motor_factor));
		motor (right_motor, (int)(speed*direction));
	}
	msleep(0);
    ao();
    msleep(250);
}

void rotateGrip(int speed, int time) {
    motor(gripper, speed);
    msleep(time);
    ao();
    msleep(250);
}

void moveServo(int port, int position, int speed) {
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

void turn(int speed, int time, int direction){
  motor (left_motor, -direction*speed*l_motor_factor);
  motor (right_motor, direction*speed*r_motor_factor);
  msleep(time);
  ao();
  msleep(250);
}

void startup() {
  msleep(1000);
  enable_servos();
  pitchfork(up, fast);
  rotateGrip(20, 2500);
  rotateGrip(-20, 2500);
  msleep(1000);
}

void basketPickup() {
  driveDistance(50, 118, -1);
  turn(50,(int)(full_rotation)*.248, 1);
  driveDistance(35, 60, -1);
  pitchfork(down, medium);
  driveDistance(50, 65, 1);
  pitchfork(carry, medium);
}

void toDispenser() {
  driveDistance(50, 25, -1);
  turn(50,(int)(full_rotation)*.248, -1);
  driveDistance(50, 91, 1);
  pitchfork(down-200, medium);
  turn(15,(int)(full_rotation), -1);
  pitchfork(down, slow);
  driveDistance(30, 15, -1);
  pitchfork(up, fast);
  turn(50,(int)(full_rotation)*.54, 1);
}

void useDispenser() {
  driveDistance(30, 20, -1);
  rotateGrip(medium, 2000);
  rotateGrip(-medium, 2000);
  rotateGrip(medium, 2000);
  rotateGrip(-medium, 2000);
  driveDistance(30, 20, 1);
  turn(50,(int)(full_rotation)*.54, 1);
  pitchfork(down, slow);
  driveDistance(50, 40, -1);
  pitchfork(carry, slow);
  driveDistance(30, 20, 1);
}

void shutdown() {
  msleep(3000);
  disable_servos();
}
