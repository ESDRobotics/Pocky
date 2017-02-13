#include <kipr/botball.h>
#define LeftMotor 0
#define RightMotor 1
#define AuxMotor 2
#define Forwards 1
#define Backwards -1

void Drive(int speed);
void DriveTime(int speed, int time);
void turnRight(int speed, int time);
void turnLeft(int speed, int time);




int main()
{
	
    msleep(20000);    
    return 0;
}

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



