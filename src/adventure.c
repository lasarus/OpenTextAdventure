#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adventure.h"

adventure_t * new_adventure()
{
  adventure_t * adventure = NULL;

  adventure = malloc(sizeof(adventure_t));

  adventure->room_count = 10;
  adventure->rooms = malloc(sizeof(room_t) * adventure->room_count);
  memset(adventure->rooms, 0, sizeof(room_t) * adventure->room_count);

  adventure->item_count = 10;
  adventure->items = malloc(sizeof(item_t) * adventure->item_count);
  memset(adventure->items, 0, sizeof(item_t) * adventure->item_count);

  return adventure;
}

void free_adventure(adventure_t * adventure)
{
  free(adventure->items);
  free(adventure->rooms);
  free(adventure);
}

void init_adventure(adventure_t * adventure)
{
  /* THIS INITS A BASIC ADVENTURE */
  /* THIS SHOULD NOT BE NECESSARY IN THE FUTURE */

  adventure->adventurer.room = 0; /* STARTING IN ROOM #1 (0) */

  /* ROOM #1 */

  adventure->rooms[0].name = "The Funny Gray Home";
  adventure->rooms[0].description = "The walls are gray with stripes of blue, and many many boxes filled with more boxes!";

  adventure->rooms[0].neighbour_rooms[0] = 1; /* SETTING NORTH ROOM TO ROOM #2 (1) */

  /* ROOM #2 */

  adventure->rooms[1].name = "The Blue Road";
  adventure->rooms[1].description = "A BLUE ROAD!! There's a gray house to the north.";

  adventure->rooms[1].neighbour_rooms[2] = 0; /* SETTING SOUTH ROOM TO ROOM #1 (0) */
}

int update_adventure(adventure_t * adventure)
{
  char input[256];

  fgets(input, sizeof(input), stdin);
  input[strlen(input) - 1] = 0;

  if(strcmp(input, "quit") == 0)
    return 1;

  printf("%s\n", adventure->rooms[adventure->adventurer.room].name);

  return 0;
}
