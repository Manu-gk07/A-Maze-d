/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** maze_generate - generate a random connected labyrinth
*/

#include "../include/my.h"
#include <time.h>

static room_t *create_room(int id, int x, int y, TYPE type) {
  room_t *room = malloc(sizeof(room_t));
  char buf[32];

  if (!room)
    return NULL;
  snprintf(buf, sizeof(buf), "room_%d", id);
  room->name = my_strdup(buf);
  room->x = x;
  room->y = y;
  room->type = type;
  room->occupied = false;
  room->tunnels = NULL;
  room->next = NULL;
  return room;
}

static void add_tunnel(room_t *from, room_t *to) {
  tunnel_t *t = malloc(sizeof(tunnel_t));

  if (!t)
    return;
  t->room_ptr = to;
  t->next = from->tunnels;
  from->tunnels = t;
}

static bool tunnel_exists(room_t *from, room_t *to) {
  tunnel_t *t = from->tunnels;

  while (t) {
    if (t->room_ptr == to)
      return true;
    t = t->next;
  }
  return false;
}

static void connect_rooms(room_t **rooms, int n, int density) {
  int extra = density;
  int a;
  int b;

  /* First ensure connectivity with a spanning path */
  for (int i = 0; i < n - 1; i++) {
    if (!tunnel_exists(rooms[i], rooms[i + 1])) {
      add_tunnel(rooms[i], rooms[i + 1]);
      add_tunnel(rooms[i + 1], rooms[i]);
    }
  }
  /* Add extra random connections based on density */
  for (int k = 0; k < extra * n; k++) {
    a = rand() % n;
    b = rand() % n;
    if (a != b && !tunnel_exists(rooms[a], rooms[b])) {
      add_tunnel(rooms[a], rooms[b]);
      add_tunnel(rooms[b], rooms[a]);
    }
  }
}

room_t *generate_maze(int n_rooms, int density) {
  room_t **rooms = malloc(sizeof(room_t *) * n_rooms);
  room_t *head;
  int cols;
  int x;
  int y;
  TYPE type;

  if (!rooms)
    return NULL;
  srand((unsigned int)time(NULL));
  cols = (int)(n_rooms > 1 ? n_rooms / 2 + 1 : 1);
  for (int i = 0; i < n_rooms; i++) {
    x = i % cols;
    y = i / cols;
    if (i == 0)
      type = START;
    else if (i == n_rooms - 1)
      type = END;
    else
      type = MIDDLE;
    rooms[i] = create_room(i, x, y, type);
    if (!rooms[i]) {
      free(rooms);
      return NULL;
    }
  }
  connect_rooms(rooms, n_rooms, density);
  head = rooms[0];
  for (int i = 0; i < n_rooms - 1; i++)
    rooms[i]->next = rooms[i + 1];
  rooms[n_rooms - 1]->next = NULL;
  free(rooms);
  return head;
}

room_t *get_room_by_type(room_t *head, TYPE type) {
  room_t *cur = head;

  while (cur) {
    if (cur->type == type)
      return cur;
    cur = cur->next;
  }
  return NULL;
}

void free_maze(room_t *head) {
  room_t *cur = head;
  room_t *next;
  tunnel_t *t;
  tunnel_t *tn;

  while (cur) {
    next = cur->next;
    t = cur->tunnels;
    while (t) {
      tn = t->next;
      free(t);
      t = tn;
    }
    free(cur->name);
    free(cur);
    cur = next;
  }
}
