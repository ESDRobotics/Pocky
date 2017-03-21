#include <kipr/botball.h>
#include <board_functions.h>

int main() {
  start_up();
  basket_pickup();
  to_dispenser();
  use_dispenser();
  celebration();
  shutdown();
  return 666;
}
