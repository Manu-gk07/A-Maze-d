/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** algorithm - BFS pathfinding for robots through the maze
*/

#include "../include/my.h"

typedef struct bfs_node_s {
  room_t *room;
  struct bfs_node_s *prev;
  struct bfs_node_s *next;
} bfs_node_t;

static bfs_node_t *bfs_node_new(room_t *room, bfs_node_t *prev) {
  bfs_node_t *node = malloc(sizeof(bfs_node_t));

  if (!node)
    return NULL;
  node->room = room;
  node->prev = prev;
  node->next = NULL;
  return node;
}

static bool room_in_queue(bfs_node_t *q, room_t *room) {
  while (q) {
    if (q->room == room)
      return true;
    q = q->next;
  }
  return false;
}

/* Returns linked list of bfs_nodes representing the path, NULL if not found */
static bfs_node_t *bfs(room_t *start, room_t *end) {
  bfs_node_t *queue_head = bfs_node_new(start, NULL);
  bfs_node_t *queue_tail = queue_head;
  bfs_node_t *current;
  bfs_node_t *neighbor;
  tunnel_t *t;

  while (queue_head) {
    current = queue_head;
    queue_head = queue_head->next;
    if (current->room == end)
      return current;
    t = current->room->tunnels;
    while (t) {
      if (!room_in_queue(queue_head, t->room_ptr) &&
          (!current->prev || current->prev->room != t->room_ptr)) {
        if (!room_in_queue(queue_tail, t->room_ptr) ||
            queue_tail == queue_head) {
          neighbor = bfs_node_new(t->room_ptr, current);
          if (!neighbor)
            return NULL;
          if (!queue_head)
            queue_head = neighbor;
          else
            queue_tail->next = neighbor;
          queue_tail = neighbor;
        }
      }
      t = t->next;
    }
  }
  return NULL;
}

/* Rebuild path from bfs result into a simple room pointer array */
static room_t **build_path(bfs_node_t *end_node, int *path_len) {
  int len = 0;
  bfs_node_t *cur = end_node;
  room_t **path;

  while (cur) {
    len++;
    cur = cur->prev;
  }
  path = malloc(sizeof(room_t *) * (len + 1));
  if (!path)
    return NULL;
  path[len] = NULL;
  cur = end_node;
  for (int i = len - 1; i >= 0; i--) {
    path[i] = cur->room;
    cur = cur->prev;
  }
  *path_len = len;
  return path;
}

/* Run all robots through the maze simultaneously, printing step-by-step */
void run_robots(room_t *maze, robot_t *robots, int n_robots) {
  room_t *start = get_room_by_type(maze, START);
  room_t *end = get_room_by_type(maze, END);
  room_t ***paths = malloc(sizeof(room_t **) * n_robots);
  int *path_lens = malloc(sizeof(int) * n_robots);
  int *positions = malloc(sizeof(int) * n_robots);
  int *done = malloc(sizeof(int) * n_robots);
  bfs_node_t *result;
  robot_t *cur_robot;
  int all_done = 0;
  int step = 1;
  bool first_move;

  if (!paths || !path_lens || !positions || !done) {
    free(paths);
    free(path_lens);
    free(positions);
    free(done);
    return;
  }
  cur_robot = robots;
  for (int i = 0; i < n_robots; i++) {
    result = bfs(start, end);
    paths[i] = result ? build_path(result, &path_lens[i]) : NULL;
    positions[i] = 0;
    done[i] = 0;
    if (cur_robot) {
      cur_robot->current_room = start;
      cur_robot = cur_robot->next;
    }
  }
  printf("#moves\n");
  while (!all_done) {
    all_done = 1;
    first_move = true;
    for (int i = 0; i < n_robots; i++) {
      if (done[i] || !paths[i])
        continue;
      if (positions[i] + 1 < path_lens[i]) {
        room_t *next_room = paths[i][positions[i] + 1];
        if (next_room->type == END || !next_room->occupied) {
          if (paths[i][positions[i]]->type != START)
            paths[i][positions[i]]->occupied = false;
          positions[i]++;
          if (next_room->type != END)
            next_room->occupied = true;
          if (!first_move)
            printf(" ");
          printf("P%d-%s", i + 1, next_room->name);
          first_move = false;
          all_done = 0;
        } else {
          all_done = 0; // Still have robots mid-way
        }
      } else {
        done[i] = 1;
      }
    }
    if (!all_done)
      printf("\n");
    step++;
    if (step > 10000)
      break;
  }
  for (int i = 0; i < n_robots; i++)
    free(paths[i]);
  free(paths);
  free(path_lens);
  free(positions);
  free(done);
}

robot_t *create_robots(int n, room_t *start) {
  robot_t *head = NULL;
  robot_t *tail = NULL;
  robot_t *r;

  for (int i = 0; i < n; i++) {
    r = malloc(sizeof(robot_t));
    if (!r)
      break;
    r->id = i + 1;
    r->current_room = start;
    r->next = NULL;
    if (!head) {
      head = r;
      tail = r;
    } else {
      tail->next = r;
      tail = r;
    }
  }
  return head;
}

void free_robots(robot_t *head) {
  robot_t *cur = head;
  robot_t *next;

  while (cur) {
    next = cur->next;
    free(cur);
    cur = next;
  }
}
