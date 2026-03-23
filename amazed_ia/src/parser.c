/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** parser - Reads labyrinth from standard input
*/

#include "../include/my.h"

static room_t *add_room(room_t **head, char *name, int x, int y, TYPE type) {
  room_t *new = malloc(sizeof(room_t));

  if (!new)
    return NULL;
  new->name = my_strdup(name);
  new->x = x;
  new->y = y;
  new->type = type;
  new->occupied = false;
  new->tunnels = NULL;
  new->next = *head;
  *head = new;
  return new;
}

static room_t *get_room_by_name(room_t *head, char *name) {
  while (head) {
    if (strcmp(head->name, name) == 0)
      return head;
    head = head->next;
  }
  return NULL;
}

static void add_tunnel_by_names(room_t *head, char *n1, char *n2) {
  room_t *r1 = get_room_by_name(head, n1);
  room_t *r2 = get_room_by_name(head, n2);
  tunnel_t *t;

  if (!r1 || !r2)
    return;
  t = malloc(sizeof(tunnel_t));
  if (!t)
    return;
  t->room_ptr = r2;
  t->next = r1->tunnels;
  r1->tunnels = t;

  t = malloc(sizeof(tunnel_t));
  if (!t)
    return;
  t->room_ptr = r1;
  t->next = r2->tunnels;
  r2->tunnels = t;
}

static void process_room(char *line, room_t **head, TYPE *next_type) {
  char *name;
  int x, y;
  char *saveptr;

  name = strtok_r(line, " \t\n", &saveptr);
  if (!name)
    return;
  char *xs = strtok_r(NULL, " \t\n", &saveptr);
  char *ys = strtok_r(NULL, " \t\n", &saveptr);
  if (!xs || !ys)
    return;
  x = my_atoi(xs);
  y = my_atoi(ys);
  add_room(head, name, x, y, *next_type);
  *next_type = MIDDLE;
}

static void process_tunnel(char *line, room_t *head) {
  char *n1, *n2;
  char *dash = strchr(line, '-');

  if (!dash)
    return;
  *dash = '\0';
  n1 = line;
  n2 = dash + 1;
  // Trim \n from n2 if present
  char *nl = strchr(n2, '\n');
  if (nl)
    *nl = '\0';
  add_tunnel_by_names(head, n1, n2);
}

room_t *parser(int *n_robots) {
  char *line = NULL;
  size_t len = 0;
  room_t *head = NULL;
  TYPE next_type = MIDDLE;
  bool robots_parsed = false;

  printf("#number_of_robots\n");
  while (getline(&line, &len, stdin) != -1) {
    if (line[0] == '\0' || line[0] == '\n')
      break;
    if (line[0] == '#') {
      if (strcmp(line, "##start\n") == 0)
        next_type = START;
      if (strcmp(line, "##end\n") == 0)
        next_type = END;
      printf("%s", line); // Print comments
      continue;
    }
    if (!robots_parsed) {
      *n_robots = my_atoi(line);
      robots_parsed = true;
      printf("%s", line); // Print robot count
      printf("#rooms\n");
      continue;
    }
    if (strchr(line, '-')) {
      static bool tunnels_header = false;
      if (!tunnels_header) {
        printf("#tunnels\n");
        tunnels_header = true;
      }
      printf("%s", line);
      process_tunnel(line, head);
    } else {
      printf("%s", line);
      process_room(line, &head, &next_type);
    }
  }
  free(line);
  return head;
}
