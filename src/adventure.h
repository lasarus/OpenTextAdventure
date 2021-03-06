#ifndef ADVENTURE_H
#define ADVENTURE_H

typedef enum item_type
  {
    ITEM_NULL = 0,
    ITEM_BOX
  } item_type_t;

typedef struct item
{
  item_type_t type;
  int room;
} item_t;

typedef struct room
{
  char * name;
  char * description;

  int neighbour_rooms[4];
} room_t;

typedef struct adventurer
{
  int room;
} adventurer_t;

typedef struct adventure
{
  int room_count;
  room_t * rooms;

  int item_count;
  item_t * items;

  adventurer_t adventurer;
} adventure_t;

adventure_t * new_adventure();
void free_adventure(adventure_t * adventure);

void init_adventure(adventure_t * adventure);
int update_adventure(adventure_t * adventure);

#endif
