/*
** EPITECH PROJECT, 2026
** A-room-d
** File description:
** graphical - Scaled visualization
*/

#include "../include/my.h"
#include <SFML/Graphics.h>

	#define WINDOW_WIDTH 1280
	#define WINDOW_HEIGHT 720
	#define RADIUS 15
	#define PADDING 50

typedef struct gui_s
{
  sfRenderWindow *win;
  sfCircleShape *circle;
  sfFont *font;
  sfText *text;
  float scale;
  float offset_x;
  float offset_y;
  int min_x, max_x, min_y, max_y;
} gui_t;

static void get_bounds(room_t *room, gui_t *gui)
{
	int first = 1;

	for (room_t *r = room; r; r = r->next) {
		if (first) {
			gui->min_x = gui->max_x = r->x;
			gui->min_y = gui->max_y = r->y;
			first = 0;
		} else {
		if (r->x < gui->min_x)
			gui->min_x = r->x;
		if (r->x > gui->max_x)
			gui->max_x = r->x;
		if (r->y < gui->min_y)
			gui->min_y = r->y;
		if (r->y > gui->max_y)
			gui->max_y = r->y;
		}
	}
}

static void calc_scale(gui_t *gui)
{
	float width = gui->max_x - gui->min_x + 1;
	float height = gui->max_y - gui->min_y + 1;
	float scale_x = (WINDOW_WIDTH - 2 * PADDING) / width;
	float scale_y = (WINDOW_HEIGHT - 2 * PADDING) / height;

	gui->scale = scale_x < scale_y ? scale_x : scale_y;
	gui->offset_x = PADDING - gui->min_x * gui->scale;
	gui->offset_y = PADDING - gui->min_y * gui->scale;
}

static gui_t *create_gui(void)
{
	gui_t *gui = malloc(sizeof(gui_t));
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

	if (!gui)
		return NULL;
	gui->win = sfRenderWindow_create(mode, "room", sfClose, NULL);
	gui->circle = sfCircleShape_create();
	gui->font =
		sfFont_createFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
	if (!gui->font)
		gui->font = sfFont_createFromFile("/usr/share/fonts/dejavu/DejaVuSans.ttf");
	gui->text = sfText_create();
	sfCircleShape_setRadius(gui->circle, RADIUS);
	sfCircleShape_setOutlineThickness(gui->circle, 1.0f);
	sfCircleShape_setOutlineColor(gui->circle, sfWhite);
	sfCircleShape_setFillColor(gui->circle, sfBlack);
	if (gui->font)
		sfText_setFont(gui->text, gui->font);
	sfText_setCharacterSize(gui->text, 12);
	sfText_setFillColor(gui->text, sfWhite);
	return gui;
}

static sfVector2f get_pos(room_t *r, gui_t *gui)
{
	return (sfVector2f){gui->offset_x + r->x * gui->scale,
						gui->offset_y + r->y * gui->scale};
}

static void draw_tunnels(gui_t *gui, room_t *room)
{
	for (room_t *r = room; r; r = r->next) {
		sfVector2f p1 = get_pos(r, gui);
		for (tunnel_t *t = r->tunnels; t; t = t->next) {
			sfVector2f p2 = get_pos(t->room_ptr, gui);
			sfVertex v[] = {
							{p1, sfWhite, {0, 0}},
							{p2, sfWhite, {0, 0}}};
			sfRenderWindow_drawPrimitives(gui->win, v, 2, sfLines, NULL);
		}
	}
}

static void draw_room_label(gui_t *gui, room_t *r, sfVector2f pos)
{
	char *name = r->name;

	if (strncmp(name, "room_", 5) == 0)
		name += 5;
	sfText_setString(gui->text, name);
	sfFloatRect b = sfText_getGlobalBounds(gui->text);
	sfText_setPosition(gui->text,
						(sfVector2f){pos.x - b.width / 2, pos.y - b.height / 2});
	sfRenderWindow_drawText(gui->win, gui->text, NULL);
}

static void draw_rooms(gui_t *gui, room_t *room)
{
	for (room_t *r = room; r; r = r->next) {
		sfVector2f p = get_pos(r, gui);
		sfCircleShape_setPosition(gui->circle,
								(sfVector2f){p.x - RADIUS, p.y - RADIUS});
		sfRenderWindow_drawCircleShape(gui->win, gui->circle, NULL);
		if (gui->font)
			draw_room_label(gui, r, p);
	}
}

static void handle_events(sfRenderWindow *win)
{
	sfEvent ev;

	while (sfRenderWindow_pollEvent(win, &ev)) {
		if (ev.type == sfEvtClosed)
			sfRenderWindow_close(win);
	}
}

void run_graphical(room_t *room, robot_t *robots, int n_robots)
{
	gui_t *gui = create_gui();

	(void)robots;
	(void)n_robots;
	if (!gui || !gui->win || !room)
		return;
	get_bounds(room, gui);
	calc_scale(gui);
	while (sfRenderWindow_isOpen(gui->win)) {
		handle_events(gui->win);
		sfRenderWindow_clear(gui->win, sfBlack);
		draw_tunnels(gui, room);
		draw_rooms(gui, room);
		sfRenderWindow_display(gui->win);
	}
	sfCircleShape_destroy(gui->circle);
	sfText_destroy(gui->text);
	if (gui->font)
		sfFont_destroy(gui->font);
	sfRenderWindow_destroy(gui->win);
	free(gui);
}
