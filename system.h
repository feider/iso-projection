#ifndef SYSTEM_H
#define SYSTEM_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Tilemap;

extern sf::RenderWindow window;

extern int size_x;
extern int size_y;

extern int tile_x;
extern int tile_y;
extern int tile_z;

extern int max_z;
extern int min_z;

void game_interaction(Tilemap *tilemap, float seconds_elapsed);
void time_function(Tilemap * tilemap);


extern sf::Clock clk;

int get_mouse_tile_x();
int get_mouse_tile_y();
sf::Vector3i get_mouse_tile(Tilemap * tilemap, const sf::Vector2f & offset);

#endif
