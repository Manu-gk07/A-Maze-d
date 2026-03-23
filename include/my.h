/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** my.h - Main header file
*/

#ifndef MY_H_
	#define MY_H_

	#include <math.h>
	#include <stdarg.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	// Include my_printf functions
	#include "../lib/my_printf/include/my_printf.h"

	// Include other_functions
	#include "../lib/other_functions/other_functions.h"

typedef enum type_s { START, MIDDLE, END } type_t;

typedef struct tunnel_s {
	struct room_s *room_ptr;
	struct tunnel_s *next;
} tunnel_t;

typedef struct room_s {
	char *name;
	int x;
	int y;
	type_t type;

	bool occupied;
	int distance;
	bool visited;
	tunnel_t *tunnels;
	struct room_s *next;
} room_t;

typedef struct line_s {
	char *content;
	struct line_s *next;
} line_t;

typedef struct values_s {
	int number_of_robots;
	room_t *rooms;
	room_t *start;
	room_t *end;
	line_t *lines;
} values_t;

typedef struct queue_node_s {
	room_t *room;
	struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s {
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

typedef struct path_s {
	room_t **rooms;
	int length;       // nombre de salles dans le chemin
	int robots_count; // nombre de robots déjà assignés à ce chemin
	struct path_s *next;
} path_t;

typedef struct robot_s {
	int id;
	path_t *path;
	int pos_in_path;
	bool finished;
} robot_t;

int parsing(values_t *values);
int calcul_distances(room_t *head, room_t *end);
path_t *extract_single_path(room_t *start);
void print_distance(room_t *head);
void assign_robots(path_t *paths, robot_t *robots, int nb_robots);
void solve_lemin(path_t *paths, robot_t *robots, int nb_robots);
void run_graphical(room_t *maze, robot_t *robots, int nb_robots);

#endif
