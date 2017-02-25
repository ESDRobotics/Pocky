//driving
#define left_motor 0
#define right_motor 1
#define Forwards 1
#define Backwards -1
#define ticks 1317
#define ticks_per_centimeter ticks/18
#define r_motor_factor 1.0
#define l_motor_factor 0.96
  
//servos
#define slow  50
#define medium  10
#define fast  5

//arm
#define arm  1
#define arm_up  397
#define arm_down  1780
#define arm_up_half  690

// spinner
#define spinner 2


void drive(int speed) {
    motor(left_motor, (speed*l_motor_factor));
    motor(right_motor, (speed*r_motor_factor)); 
}

void drive_distance(int speed, int distance, int direction){
    int tick_distance = ticks_per_centimeter * distance;
	clear_motor_position_counter(left_motor);
	while (fabs(get_motor_position_counter(left_motor)) < tick_distance){
        printf("I need to go: %d, but I have only gone %f!\n", tick_distance, fabs(get_motor_position_counter(left_motor)));
		motor (left_motor, (int)(speed*direction*l_motor_factor));
		motor (right_motor, (int)(speed*direction));
	}
	msleep(0);
    ao();
}
void driveBackward(int speed) {
    motor(left_motor, -(speed*l_motor_factor));
    motor(right_motor, -(speed*r_motor_factor));  
}

void driveTime(int speed, int time, int direction) {
    if (direction==1)
        drive(speed);
    else if (direction==-1)
        driveBackward(speed);
    msleep(time);
    ao();
}

void turnRight(int speed, int time) {

    motor(left_motor, speed);
    motor(right_motor, -speed);
    msleep(time);
}

void turnLeft(int speed, int time) {
    motor(left_motor, -speed);
    motor(right_motor, speed);
    msleep(time);
}
void rotate_spinner(int speed, int time) {
    motor(spinner, speed);
    msleep(time);
}

void move_servo(int port, int position, int speed) {
    int pos = get_servo_position(port);
    if(position < pos) {
        for(pos; pos > position; pos -= 10) {
            set_servo_position(port,pos);
            msleep(speed);
        }
    }
    if(position > pos) {
        for(pos; pos < position; pos += 10) {
            set_servo_position(port,pos);
            msleep(speed);
        }
    }
}

void armLower() {
    move_servo(arm, arm_down, medium);
}

void armRaise() {
    move_servo(arm, arm_up, medium);
}
