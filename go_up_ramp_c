#include <kipr/botball.h>

int main()
{
    enable_servos();
    set_servo_position(2,1250);
    while(get_servo_position(3) > 150) {
    	set_servo_position(3, get_servo_position(3)-10);
        printf("Moving Servo");
        msleep(150);
    }
    msleep(1500);
    while(magneto_x()<-90) {
     printf("NOT GOING UP\n");
  	 motor(0,50);
   	 motor(1,50);
   	 motor(3,50);
    }
    msleep(250);
    while(magneto_x()>-100){
        printf("GOING UP\n");
        if(analog(0)>3700){
            motor(0,25);
            motor(1,75);
            motor(3,100);
            printf("analog 0: %d\t",analog(0));
        }
        else if(analog(1)>3700){
            motor(0,75);
            motor(1,25);
            motor(3,100);
            printf("analog 1: %d\t",analog(1));
        }
        else{
        	motor(0,100);
        	motor(1,100);
        	motor(3,100);
        }
        msleep(1000);
    }
    printf("NO T GOING UP");
    set_servo_position(3,220);
    msleep(100);
    int count=0;
    while(count < 80){
        motor(0,100);
        motor(1,100);
        motor(3,100);
        msleep(100);
        count+=2;
    }
    ao();
    set_servo_position(3, 150);
    msleep(5000);
    while(get_servo_position(2)>1000){
    	set_servo_position(2,get_servo_position(2)-5);
        msleep(50);
	}
    set_servo_position(2,1000);
    msleep(2000);
    motor(0,100);
    motor(1,100);
    motor(3,100);
    msleep(5000);
    freeze(0);
    freeze(1);
    freeze(3);
    msleep(5000);
    while(get_servo_position(2)<1640){
        set_servo_position(2,get_servo_position(2)+5);
        msleep(50);
    }
    set_servo_position(2,1640);
    ao();
    motor(0,-100);
    motor(1,-100);
    motor(3,-100);
    msleep(1000);
    ao();
    
}
