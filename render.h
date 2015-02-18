#ifndef RENDER_H
#define RENDER_H

#include "tilemap.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

void render_ascii( Tilemap * tilemap );

void render_isometric(Tilemap * Tilemap);

void init_iso_target();

extern sf::Texture * textures; 

extern sf::RenderTexture iso_target;
#endif
