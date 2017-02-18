#include <kipr/botball.h>
//driving
#define LeftMotor 0
#define RightMotor 1
#define AuxMotor 2
#define Forwards 1
#define Backwards -1
#define f_r_motor_factor 1.0
#define f_l_motor_factor 0.80
#define b_r_motor_factor 0.70
#define b_l_motor_factor 1.0
//************servos*********
#define slow  50
#define medium  10
#define fast  5
//basket
#define basket  2
#define basket_down  74
#define basket_up  800
//arm
#define arm  1
#define arm_up  397
#define arm_down  1780
#define arm_down_bot  1650
#define arm_up_half  690
//claw
 #define claw  0
 #define claw_open  200
 #define bot  1680
 #define cow  1510

void drive(int speed);
void driveBackward(int speed);
void driveTime(int speed, int time, int direction);
void turnRight(int speed, int time);
void turnLeft(int speed, int time);
void move_servo(int port, int position, int speed);
void basketDump();
void armLower();
void armRaise();
void clawGrab(int closeTo);
void clawOpen();
//*******************************************FUCNTIONS******************************************
//*****************************************PEPE_SAD_FROG****************************************
//***************************************SAD_(REEEEEEEEE)***************************************


void drive(int speed){
    motor(LeftMotor, (speed*f_l_motor_factor));
    motor(RightMotor, (speed*f_r_motor_factor));
    motor(AuxMotor, speed);   
}
void driveBackward(int speed){
    motor(LeftMotor, -(speed*b_l_motor_factor));
    motor(RightMotor, -(speed*b_r_motor_factor));
    motor(AuxMotor, -speed);   
}
void driveTime(int speed, int time, int direction){
    if (direction==1)
        drive(speed);
    else if (direction==-1)
        driveBackward(speed);
    msleep(time);
    ao();
}
void turnRight(int speed, int time){
    motor(LeftMotor, speed);
    motor(RightMotor, -speed);
    motor(AuxMotor,0);
    msleep(time);
}
void turnLeft(int speed, int time){
    motor(LeftMotor, -speed);
    motor(RightMotor, speed);
    motor(AuxMotor,0);
    msleep(time);
}

void move_servo(int port, int position, int speed){
    int pos = get_servo_position(port);
    if(position < pos){
        for(pos; pos > position; pos -= 10){
            set_servo_position(port,pos);
            msleep(speed);
        }
    }
    if(position > pos){
        for(pos; pos < position; pos += 10){
            set_servo_position(port,pos);
            msleep(speed);
        }
    }
}
void basketDump(){
    move_servo(basket, basket_up, medium);
}
void armLower(){
    move_servo(arm, arm_down, medium);
}
void armRaise(){
    move_servo(arm, arm_up, medium);
}
// either pass in cow or bot to determine how much it closes
void clawGrab(int closeTo){
    move_servo(claw, closeTo, medium);
}
void clawOpen(){
    move_servo(claw, claw_open, medium);
}

















