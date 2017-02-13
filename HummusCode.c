#include <kipr/botball.h>
#define LeftMotor 0
#define RightMotor 1
#define AuxMotor 2
#define forwards 1
#define backwards -1
#define left -1
#define right 1

void Drive(int direction, int speed);
void DriveTime(int direction, int speed, int time);
void TurnRearPowered(int time);

int main()
{
    DriveTime(Forwards, 100, 6000);
    return 0;
}

void Drive(int direction, int speed){
    motor(LeftMotor,speed);
	motor(RightMotor,speed);
    motor(AuxMotor, speed);   
}
void DriveTime(int direction, int speed, int time){
    Drive(direction, speed);
    msleep(time);
    ao();
}
void TurnRearPowered(int time, int direction){
	motor(LeftMotor,speed*direction);
	motor(RightMotor,speed*direction);
    motor(AuxMotor, speed); 
}
