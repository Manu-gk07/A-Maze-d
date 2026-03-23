/*
** EPITECH PROJECT, 2026
** A-maze-d
** File description:
** graphical_laberint - Modular graphical display with refactored functions
*/

#include "../include/my.h"
#include <SFML/Graphics.h>

#define CELL_SIZE 100
#define RADIUS 25
#define OFFSET_X 150.0f
#define OFFSET_Y 150.0f

static sfFont *get_font(void)
{
	sfFont *f = sfFont_createFromFile(
		"/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
	if (!f)
		f = sfFont_createFromFile("/usr/share/fonts/dejavu/DejaVuSans.ttf");
	return f;
}

static sfVector2f get_room_pos(room_t *r)
{
	return (sfVector2f){OFFSET_X + r->x * CELL_SIZE,
		OFFSET_Y + r->y * CELL_SIZE};
}

static void setup_circle(sfCircleShape *c)
{
	sfCircleShape_setRadius(c, RADIUS);
	sfCircleShape_setOutlineThickness(c, 1.0f);
	sfCircleShape_setOutlineColor(c, sfWhite);
	sfCircleShape_setFillColor(c, sfBlack);
}

static void setup_text(sfText *text, sfFont *font)
{
	if (!font)
		return;
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 14);
	sfText_setFillColor(text, sfWhite);
}

static void draw_line(sfRenderWindow *win, sfVector2f p1, sfVector2f p2)
{
	sfVertex v[] = {{p1, sfWhite, {0, 0}}, {p2, sfWhite, {0, 0}}};
	sfRenderWindow_drawPrimitives(win, v, 2, sfLines, NULL);
}

static void draw_tunnels(sfRenderWindow *win, room_t *maze)
{
	for (room_t *r = maze; r; r = r->next) {
		sfVector2f p1 = get_room_pos(r);
		for (tunnel_t *t = r->tunnels; t; t = t->next)
			draw_line(win, p1, get_room_pos(t->room_ptr));
	}
}

static void draw_room_label(sfRenderWindow *win, room_t *r, sfText *text,
	sfFont *font)
{
	char *name = r->name;

	if (!font || !text)
		return;
	if (strncmp(r->name, "room_", 5) == 0)
		name += 5;
	sfText_setString(text, name);
	sfVector2f pos = get_room_pos(r);
	sfFloatRect bounds = sfText_getGlobalBounds(text);
	sfText_setPosition(text, (sfVector2f){pos.x - bounds.width / 2,
		pos.y - bounds.height / 2 - 5});
	sfRenderWindow_drawText(win, text, NULL);
}

static void draw_rooms(sfRenderWindow *win, room_t *maze, sfCircleShape *c,
	sfText *text, sfFont *font)
{
	for (room_t *r = maze; r; r = r->next) {
		sfVector2f pos = get_room_pos(r);
		sfCircleShape_setPosition(c, (sfVector2f){pos.x - RADIUS,
			pos.y - RADIUS});
		sfRenderWindow_drawCircleShape(win, c, NULL);
		draw_room_label(win, r, text, font);
	}
}

void run_graphical(room_t *maze, robot_t *robots, int n_robots)
{
	sfVideoMode mode = {1280, 720, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, "Maze", sfClose, NULL);
	sfCircleShape *c = sfCircleShape_create();
	sfFont *font = get_font();
	sfText *text = sfText_create();
	sfEvent ev;

	(void)robots;
	(void)n_robots;
	setup_circle(c);
	setup_text(text, font);
	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &ev))
			if (ev.type == sfEvtClosed)
				sfRenderWindow_close(win);
		sfRenderWindow_clear(win, sfBlack);
		draw_tunnels(win, maze);
		draw_rooms(win, maze, c, text, font);
		sfRenderWindow_display(win);
	}
	sfCircleShape_destroy(c);
	sfText_destroy(text);
	if (font)
		sfFont_destroy(font);
	sfRenderWindow_destroy(win);
}
