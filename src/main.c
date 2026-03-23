/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** main
*/

#include "../include/my.h"

static void display_info(line_t *curr_l, line_t *lines)
{
	bool rooms_header_done = false;
	bool tunnels_header_done = false;

	my_printf("#number_of_robots\n");
	while (curr_l) {
		if (!rooms_header_done && !my_strchr(curr_l->content, '-') &&
			curr_l->content[0] >= '0' && curr_l->content[0] <= '9' &&
			curr_l != lines) {
			my_printf("#rooms\n");
			rooms_header_done = true;
		}
		if (!tunnels_header_done && my_strchr(curr_l->content, '-')) {
			my_printf("#tunnels\n");
			tunnels_header_done = true;
		}
		my_printf("%s", curr_l->content);
		if (curr_l->content[my_strlen(curr_l->content) - 1] != '\n')
			my_printf("\n");
		curr_l = curr_l->next;
	}
}

int handle_paths(room_t *start, values_t *values)
{
	path_t *path_list = NULL;
	path_t *new_path = extract_single_path(start);
	robot_t *robots = malloc(sizeof(robot_t) * values->number_of_robots);

	while (new_path != NULL) {
		new_path->next = path_list;
		path_list = new_path;
		new_path = extract_single_path(start);
	}
	if (!path_list) {
		my_printf("no path found, start and end not connected\n");
		return 84;
	}
	assign_robots(path_list, robots, values->number_of_robots);
	solve_lemin(path_list, robots, values->number_of_robots);
	run_graphical(values->rooms, robots, values->number_of_robots);
	return 0;
}

int main(int argc, char **argv)
{
	values_t values = {0};

	(void)argc;
	(void)argv;
	if (parsing(&values) == 84)
		return 84;
	display_info(values.lines, values.lines);
	if (!values.start || !values.end) {
		write(2, "No start or end room\n", 21);
		return 84;
	}
	calcul_distances(values.rooms, values.end);
	return handle_paths(values.start, &values);
}
