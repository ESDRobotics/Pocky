#include <kipr/botball.h>
#include <hummus.h>
// THINGS THAT ARE AVLIBLE TO YOU
// drive(int speed);
// driveTime(int speed, int time);
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
    /*clawOpen();
    armLower();
    clawGrab(bot);
    armRaise();
    clawOpen();
    armLower();
    basketDump();
    */
    Drive(-100);
    msleep(1000);
    ao();
    Drive(100);
    msleep(8000);
    ao();
    turnLeft(100,3900);
    ao();
    Drive(-100);
    msleep(1400);
    ao();
    
    return 0;
}
