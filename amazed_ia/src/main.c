/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv) {
  int n_robots = 0;
  room_t *maze;
  robot_t *robots;
  room_t *start;

  if (argc == 4) {
    n_robots = my_atoi(argv[3]);
    maze = generate_maze(my_atoi(argv[1]), my_atoi(argv[2]));
  } else {
    maze = parser(&n_robots);
  }
  if (!maze || n_robots <= 0)
    return 84;
  start = get_room_by_type(maze, START);
  if (!start || !get_room_by_type(maze, END)) {
    free_maze(maze);
    return 84;
  }
  robots = create_robots(n_robots, start);
  if (!robots) {
    free_maze(maze);
    return 84;
  }
  run_robots(maze, robots, n_robots);
  run_graphical(maze, robots, n_robots);
  free_robots(robots);
  free_maze(maze);
  return 0;
}
