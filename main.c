#include <kipr/botball.h>
#include <pocky.h>
#include <board_functions.h>

void main() {
  start_up();
  basket_pickup();
  to_dispenser();
  use_dispenser();
  to_bridge();
  shutdown();
}
