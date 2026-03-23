/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** algo
*/

#include "../include/my.h"
#include <stdlib.h>

static void get_first_step(room_t *start, room_t **first_step)
{
    tunnel_t *t = start->tunnels;

    while (t) {
        if (t->room_ptr->distance != -1) {
            *first_step = t->room_ptr;
            return;
        }
        t = t->next;
    }
}

room_t *find_next_step(room_t *current, int current_dist)
{
    tunnel_t *tmp = current->tunnels;
    room_t *next_step = NULL;

    while (tmp) {
        if (tmp->room_ptr->type == END
            && tmp->room_ptr->distance == current_dist - 1)
            return tmp->room_ptr;
        if (tmp->room_ptr->distance == (current_dist - 1)
            && tmp->room_ptr->distance != -2) {
            next_step = tmp->room_ptr;
            break;
        }
        tmp = tmp->next;
    }
    return next_step;
}

path_t *no_end_path(int len, path_t *path)
{
    if (len == 0 || path->rooms[len - 1]->type != END) {
        free(path->rooms);
        free(path);
        return NULL;
    }
    return path;
}

static void go_trough_all_rooms(room_t *curr, path_t *path,
    int *len, int current_dist)
{
    while (curr != NULL) {
        (*len)++;
        path->rooms[*len - 1] = curr;
        if (curr->type == END)
            break;
        current_dist = curr->distance;
        curr->distance = -2;
        curr = find_next_step(curr, current_dist);
        if (*len > 1990) {
            curr = NULL;
            break;
        }
    }
}

path_t *extract_single_path(room_t *start)
{
    room_t *curr = NULL;
    int len = 0;
    room_t *first_step = NULL;
    path_t *path = malloc(sizeof(path_t));
    int current_dist = 0;

    path->rooms = malloc(sizeof(room_t *) * 2000);
    get_first_step(start, &first_step);
    if (!first_step)
        return NULL;
    path->robots_count = 0;
    path->next = NULL;
    curr = first_step;
    go_trough_all_rooms(curr, path, &len, current_dist);
    if (!no_end_path(len, path))
        return NULL;
    path->length = len;
    return path;
}

void get_best(path_t *paths, path_t **best)
{
    for (path_t *curr = paths; curr; curr = curr->next) {
        if ((curr->length + curr->robots_count) <
            ((*best)->length + (*best)->robots_count))
            *best = curr;
    }
}

void assign_robots(path_t *paths, robot_t *robots, int nb_robots)
{
    path_t *best = paths;

    for (int i = 0; i < nb_robots; i++) {
        get_best(paths, &best);
        robots[i].id = i + 1;
        robots[i].path = best;
        robots[i].pos_in_path = -1;
        robots[i].finished = false;
        best->robots_count++;
    }
}
