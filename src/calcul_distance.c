/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** calcul_distance
*/

#include "../include/my.h"

queue_t *init_queue(void)
{
    queue_t *q = malloc(sizeof(queue_t));

    if (!q)
        return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void add_to_queue(queue_t *queue, room_t *to_add)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));

    if (!new_node || !to_add)
        return;
    new_node->room = to_add;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

room_t *remove_from_queue(queue_t *queue)
{
    queue_node_t *temp;
    room_t *room;

    if (queue->front == NULL)
        return NULL;
    temp = queue->front;
    room = temp->room;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return room;
}

void go_in_tunnels(tunnel_t *current_tunnel,
    room_t *current_room, queue_t *queue)
{
    while (current_tunnel != NULL) {
        if (current_tunnel->room_ptr->distance == -1) {
            current_tunnel->room_ptr->distance = current_room->distance + 1;
            add_to_queue(queue, current_tunnel->room_ptr);
        }
        current_tunnel = current_tunnel->next;
    }
}

int calcul_distances(room_t *head, room_t *end)
{
    room_t *current_room = NULL;
    tunnel_t *current_tunnel = NULL;
    queue_t *queue = init_queue();

    if (!head || !end || !queue)
        return 84;
    for (room_t *tmp = head; tmp != NULL; tmp = tmp->next) {
        tmp->distance = -1;
    }
    end->distance = 0;
    add_to_queue(queue, end);
    while (queue->front != NULL) {
        current_room = remove_from_queue(queue);
        current_tunnel = current_room->tunnels;
        go_in_tunnels(current_tunnel, current_room, queue);
    }
    free(queue);
    return 0;
}
