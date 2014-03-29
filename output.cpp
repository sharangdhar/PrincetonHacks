#include <time.h>
#include <stdlib.h>

uint8_t output (uint32_t range){
  srand(time(NULL));
  int r = rand() % range;
  r -= 20000;
  if (r < 0)
    return 0;
  return 1;
}
