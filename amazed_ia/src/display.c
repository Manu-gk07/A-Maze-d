/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** display - Print maze structure to stdout
*/

#include "../include/my.h"

static void print_type(TYPE type) {
  if (type == START)
    printf("[START]");
  else if (type == END)
    printf("[END]");
  else
    printf("[ROOM]");
}

static void print_tunnels(tunnel_t *tunnels) {
  tunnel_t *t = tunnels;

  printf("  Links: ");
  if (!t) {
    printf("(none)");
  } else {
    while (t) {
      printf("%s", t->room_ptr->name);
      if (t->next)
        printf(", ");
      t = t->next;
    }
  }
  printf("\n");
}

void display_maze(room_t *head) {
  room_t *cur = head;

  printf("=== Maze Structure ===\n");
  while (cur) {
    printf("%s ", cur->name);
    print_type(cur->type);
    printf(" at (%d,%d)\n", cur->x, cur->y);
    print_tunnels(cur->tunnels);
    cur = cur->next;
  }
  printf("======================\n");
}
