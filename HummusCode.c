#include <kipr/botball.h>
#define LeftMotor 0
#define RightMotor 1
#define AuxMotor 2
#define forwards 1
#define backwards -1

void Drive(int direction, int speed);
void DriveTime(int direction, int speed, int time);

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