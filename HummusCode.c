#include <kipr/botball.h>
//driving
#define LeftMotor 0
#define RightMotor 1
#define AuxMotor 2
#define Forwards 1
#define Backwards -1
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


void Drive(int speed);
void DriveTime(int speed, int time);
void turnRight(int speed, int time);
void turnLeft(int speed, int time);
void move_servo(int port, int position, int speed);
void basket_dump();
void armLower();
void armRaise();
void clawGrab(int closeTo);
void clawOpen()



int main()
{
	while(1){
	DriveTime(100, 12000);
    turnLeft(1000);
	}
    DriveTime(100, 12000);
    turnLeft(1000);
    DriveTime(100, 12000);
    return 0;
}







//*******************************************FUCNTIONS******************************************
//*****************************************PEPE_SAD_FROG****************************************
//***************************************SAD_(REEEEEEEEE)***************************************

void Drive(int speed){
    motor(LeftMotor,speed);
	motor(RightMotor,speed);
    motor(AuxMotor, speed);   
}
void DriveTime(int speed, int time){
    Drive(speed);
    msleep(time);
    ao();
}
void turnRight(int speed, int time){
    motor(LeftMotor, -speed);
    motor(RightMotor,speed);
    motor(AuxMotor,0);
    msleep(time);
}
void turnLeft(int speed, int time){
    motor(LeftMotor, speed);
    motor(RightMotor,-speed);
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
void basket_dump(){
	move_servo(basket, basket_up, medium);
}
void armLower(){
	move_servo(lift_arm, arm_down, medium);
}
void armRaise(){
	move_servo(lift_arm, arm_up, medium);
}
// either pass in cow or bot to determine how much it closes
void clawGrab(int closeTo){
	move_servo(claw, closeTo, medium);
}
void clawOpen(){
	move_servo(lift_arm, claw_open, medium);
}
















