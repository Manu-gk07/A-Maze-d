/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** parsing
*/

#include "../include/my.h"

static void add_line(line_t **head, char *content)
{
    line_t *new_node = malloc(sizeof(line_t));
    line_t *last = *head;

    if (!new_node)
        return;
    new_node->content = my_strdup(content);
    if (!new_node->content) {
        free(new_node);
        return;
    }
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new_node;
}

static room_t *find_room(room_t *room, char *name)
{
    while (room) {
        if (my_strcmp(room->name, name) == 0)
            return room;
        room = room->next;
    }
    return NULL;
}

static void add_tunnel(room_t *a, room_t *b)
{
    tunnel_t *to_b = malloc(sizeof(tunnel_t));
    tunnel_t *to_a = malloc(sizeof(tunnel_t));

    if (!to_b || !to_a) {
        free(to_b);
        free(to_a);
        return;
    }
    to_b->room_ptr = b;
    to_b->next = a->tunnels;
    a->tunnels = to_b;
    to_a->room_ptr = a;
    to_a->next = b->tunnels;
    b->tunnels = to_a;
}

static room_t *create_room(char *name, int x, int y, type_t type)
{
    room_t *room = malloc(sizeof(room_t));

    if (!room)
        return NULL;
    room->name = my_strdup(name);
    if (!room->name) {
        free(room);
        return NULL;
    }
    room->x = x;
    room->y = y;
    room->type = type;
    room->occupied = false;
    room->distance = -1;
    room->visited = false;
    room->tunnels = NULL;
    room->next = NULL;
    return room;
}

static void add_room(room_t **head, room_t **tail, room_t *room)
{
    if (!*head) {
        *head = room;
        *tail = room;
    } else {
        (*tail)->next = room;
        *tail = room;
    }
}

static int parse_room(char *line, type_t next_type,
    values_t *values, room_t **tail)
{
    char *name_end = my_strchr(line, ' ');
    char *x_end;
    room_t *room;

    if (!name_end || !my_strchr(name_end + 1, ' '))
        return 84;
    *name_end = '\0';
    x_end = my_strchr(name_end + 1, ' ');
    *x_end = '\0';
    room = create_room(line, my_atoi(name_end + 1), my_atoi(x_end + 1),
        next_type);
    if (!room)
        return 84;
    add_room(&values->rooms, tail, room);
    values->start = (next_type == START) ? room : values->start;
    values->end = (next_type == END) ? room : values->end;
    return 0;
}

static void parse_tunnel(char *line, room_t *head)
{
    char *dash;
    room_t *a;
    room_t *b;

    dash = my_strchr(line, '-');
    if (!dash)
        return;
    *dash = '\0';
    a = find_room(head, line);
    b = find_room(head, dash + 1);
    if (a && b)
        add_tunnel(a, b);
}

static int process_line(char *line, type_t *next_type,
    room_t **tail, values_t *values)
{
    if (line[0] == '#' && line[1] != '#')
        return 84;
    if (my_strcmp(line, "##start") == 0)
        *next_type = START;
    if (my_strcmp(line, "##end") == 0 && values->start)
        *next_type = END;
    if (line[0] == '#')
        return 0;
    if (my_strchr(line, '-') && !my_strchr(line, ' ')) {
        parse_tunnel(line, values->rooms);
        return 0;
    }
    if (!my_strchr(line, ' '))
        return 0;
    if (parse_room(line, *next_type, values, tail) != 0)
        return 84;
    *next_type = MIDDLE;
    return 0;
}

static int read_maze(values_t *values, room_t **tail)
{
    char *line = NULL;
    size_t len = 0;
    type_t next_type = MIDDLE;
    int line_len;

    while (getline(&line, &len, stdin) != -1) {
        add_line(&values->lines, line);
        line_len = my_strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n')
            line[line_len - 1] = '\0';
        if (process_line(line, &next_type, tail, values) == 84) {
            free(line);
            return 84;
        }
    }
    free(line);
    return 0;
}

int parsing(values_t *values)
{
    char *line = NULL;
    size_t len = 0;
    room_t *tail = NULL;

    values->rooms = NULL;
    if (getline(&line, &len, stdin) == -1)
        return 84;
    add_line(&values->lines, line);
    values->number_of_robots = my_atoi(line);
    free(line);
    if (values->number_of_robots <= 0)
        return 84;
    return read_maze(values, &tail);
}
