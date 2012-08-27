#include <stdio.h>

#include "adventure.h"

int main(int argc, char ** argv)
{
  adventure_t * adventure = NULL;

  adventure = new_adventure();

  init_adventure(adventure);

  
  while(!update_adventure(adventure));
   
  
  free_adventure(adventure);
  
  return 0;
}
