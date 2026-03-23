/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** move_robots
*/

#include "../include/my.h"

static bool all_finished(robot_t *robots, int nb_robots)
{
	for (int i = 0; i < nb_robots; i++) {
		if (!robots[i].finished)
		return false;
	}
	return true;
}

static void move_one_robot(robot_t *robot)
{
	int next_pos = robot->pos_in_path + 1;
	room_t *next_room = robot->path->rooms[next_pos];

	if (next_room->occupied && next_room->type != END)
		return;
	if (robot->pos_in_path >= 0)
		robot->path->rooms[robot->pos_in_path]->occupied = false;
	robot->pos_in_path = next_pos;
	next_room->occupied = true;
	my_printf("L%d-%s ", robot->id, next_room->name);
	if (next_room->type == END)
		robot->finished = true;
}

static void do_step(robot_t *robots, int nb_robots)
{
	for (int i = 0; i < nb_robots; i++) {
		if (robots[i].finished)
			continue;
		if (robots[i].pos_in_path + 1 >= robots[i].path->length)
			continue;
		move_one_robot(&robots[i]);
	}
	my_printf("\n");
}

void solve_lemin(path_t *paths, robot_t *robots, int nb_robots)
{
	(void)paths;
	while (!all_finished(robots, nb_robots))
		do_step(robots, nb_robots);
}
