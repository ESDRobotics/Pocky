#include <kipr/botball.h>
void move_servo();
int main()
{
    int slow = 50;
    int medium = 10;
    int fast = 5;
    
    int claw = 0;
    int claw_open = 200;
    int claw_close_bot = 1680;
    int claw_close_cow = 1510;
    
    int lift_arm = 1;
    int lift_up = 397;
    int lift_down = 1780;
    int lift_down_bot = 1650;
	int lift_up_half = 690;
    
    int dump = 2;
    int dump_down = 74;
    int dump_up = 800;
    
    set_servo_position(claw, claw_close_cow);
    set_servo_position(lift_arm, lift_down);
    set_servo_position(dump, dump_down);
    
    enable_servos();
    msleep(1000);
    int i;
    for(i = 0; i < 2; i++){
    move_servo(claw, claw_open, medium);
    msleep(2000);
    move_servo(claw, claw_close_bot, medium);
    msleep(500);
    move_servo(lift_arm, lift_up, medium);
    msleep(500);
    move_servo(claw, claw_open, medium);
    msleep(2000);
    if(i != 2)
        move_servo(lift_arm, (i == 0) ? lift_down_bot:lift_down, fast);
    msleep(500);
    }
    move_servo(lift_arm, lift_down, medium);
    move_servo(claw, claw_close_cow, medium);
 	move_servo(lift_arm, lift_up_half, medium);
    msleep(500);
  //  move_servo(lift_arm, lift_up-600, fast);
   // move_servo(lift_arm, lift_up, fast);
    move_servo(dump, dump_up, 25);
    move_servo(dump, dump_down, medium);
    move_servo(dump, dump_up, 25);
    move_servo(dump, dump_down, medium);
    move_servo(dump, dump_up, 0);
    move_servo(dump, dump_down, medium);
    move_servo(lift_arm, lift_up, medium);
    move_servo(lift_arm, lift_up, medium);
    move_servo(claw, claw_open, medium);
    move_servo(dump, dump_up, 10);
     move_servo(dump, dump_down, medium);
    move_servo(dump, dump_up, 0);
    move_servo(dump, dump_down, medium);
    disable_servos();
    return 0;
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

