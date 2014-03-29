#include <time.h>
#include <stdlib.h>

boolean output (uint32_t range){
  srand(time(NULL));
  int r = rand() % range;
  r -= 20000;
  return r > 0;
}
