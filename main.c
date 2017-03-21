#include <kipr/botball.h>
#include <board_functions.c>

void main() {
  start_up();
  basket_pickup();
  to_dispenser();
  use_dispenser();
  celebration();
  shutdown();
}
