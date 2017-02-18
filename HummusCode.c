#include <kipr/botball.h>
#include <hummus.h>
// THINGS THAT ARE AVLIBLE TO YOU
// drive(int speed);
// void driveBackward(int speed);
// void driveTime(int speed, int time, int direction);
// turnRight(int speed, int time);
// turnLeft(int speed, int time);
// move_servo(int port, int position, int speed);
// basketDump();
// armLower();
// armRaise();
// clawGrab(int closeTo); // pass in either bot or cow
// clawOpen();

int main()
{
    enable_servos();
    armRaise();
    clawGrab(cow);
    //void driveTime(100,1500,-1)
    driveTime(100,8000,1);
    turnRight(100,3800);
    driveTime(100,3000,-1);
    driveTime(100,800,1);
    turnRight(100,11400);
    //turnLeft(100,3800);
    ao();
    driveTime(100,3000,1);
    clawOpen();
	armLower();
    clawGrab(cow);
    
    //driveTime(100,8000,1);
    //msleep(1000);
    //driveTime(100,8000,-1);
    ao();
    
    
    
    
    return 0;
}
