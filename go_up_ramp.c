#include <kipr/botball.h>
void follow_line_left(int counter);
void raise_bin();
void up_ramp();
int main()
{
    //Prep servos
    set_servo_position(3, 1500);
    set_servo_position(2,1800);
    enable_servos();

    // Raise claw
    while(get_servo_position(2) > 1600) {
    	set_servo_position(2, get_servo_position(2)-30);
        msleep(50);
    }
    set_servo_position(2,1600);
    msleep(1000);

    // Lower the back wheel
    while(get_servo_position(3) > 510) {
    	set_servo_position(3, get_servo_position(3)-50);
        msleep(100);
    }
    msleep(1500);

    // Approach the ramp
    while(magneto_x()<-90) {
     printf("NOT GOING UP\n");
  	 motor(0,50);
   	 motor(1,50);
   	 motor(3,50);
     msleep(20);
    }

    // Drive up ramp
    msleep(250);

    up_ramp();

  //  while(get_servo_position(2)>1313){
  //  	set_servo_position(2,get_servo_position(2)-5);
  //      msleep(5);
	//}
    set_servo_position(2,1313);
    //We are at top
    printf("Take it back now y'all");
    //ao();
    motor(0,25);
    motor(1,50);
    msleep(500);
	raise_bin();
    msleep(500);

    follow_line_left(100);

    ao();
    msleep(2000);
    motor(0,60);
    motor(1,60);
    motor(3,60);
    msleep(1750);
    freeze(0);
    freeze(1);
    freeze(3);
    msleep(50);
    while(get_servo_position(2)<1640){
        set_servo_position(2,get_servo_position(2)+5);
        msleep(50);
    }
    set_servo_position(2,1640);
    ao();
    motor(0,-60);
    motor(1,-60);
    motor(3,-60);
    msleep(1000);
    ao();
    return 1;

}

void follow_line_left(int counter){
int count= 0;
    while(count<counter){
        if(analog(0)>3500){
            motor(0,60);
            motor(1,30);
            motor(3,60);
            msleep(10);
            printf("Slide to the left: %d\n",analog(0));
        }
        else{
        	motor(0,15);
        	motor(1,100);
        	motor(3,15);
            msleep(10);
            printf("Slide to the right: %d\n",analog(0));
        }
        msleep(10);
        count++;
    }
}

void up_ramp(){
int count= 0;
    while(count<575){
        if(analog(0)>3500){
            motor(0,60);
            motor(1,30);
            motor(3,60);
            msleep(10);
            printf("Slide to the left: %d\n",analog(0));
        }
        else{
        	motor(0,15);
        	motor(1,100);
        	motor(3,15);
            msleep(10);
            printf("Slide to the right: %d\n",analog(0));
        }

        if(575 - count < 100){
        	set_servo_position(2,get_servo_position(2)-2);
        }
        msleep(10);
        count++;
    }
}

void raise_bin(){
motor(0,10);
motor(1,10);
while(get_servo_position(2)>1000){
    	set_servo_position(2,get_servo_position(2)-5);
        msleep(50);
	}
    set_servo_position(2,1000);
ao();
}
