#include "system.h"
#include "tilemap.h"
#include <iostream>
#include "render.h"


int size_x = 800;
int size_y = 600;

int tile_x = 64;
int tile_y = 32;
int tile_z = 12;

int max_z = 10;
int min_z = -10;

sf::RenderWindow window;

sf::Clock clk;

void time_function(Tilemap * tilemap)
{
	float seconds_elapsed = clk.getElapsedTime().asSeconds();
	game_interaction(tilemap, seconds_elapsed);
}

sf::Vector3i get_mouse_tile_pre(Tilemap * tilemap, const sf::Vector2f & offset)
{
	
	int gmx = sf::Mouse::getPosition(window).x - offset.x;
	int gmy = sf::Mouse::getPosition(window).y - offset.y;
	gmx -= tile_x/2;


	for(int z = max_z; z>=min_z; z--)
	{
		int mx = gmx;
		int my = gmy;
		my += tile_z*z;		
		int sx = (2* my + mx) / 2;
		int sy = (2 * my - mx) / 2;
		int tx = (sx/(tile_y));
		int ty = (sy/(tile_y));

		
		if(tilemap->is_in(tx, ty))
		{
			Tile_Pile & tile_pile = tilemap->get_tile(tx, ty);
			for(auto & t : tile_pile)
			{
				if(z == t->z)
				{
					return {tx, ty, z};
				}
			}
		}
	}

	return {-1, -1, min_z-1};
}

sf::Vector3i get_mouse_tile(Tilemap * tilemap, const sf::Vector2f & offset)
{
	sf::Vector3i normal;
	sf::Vector3i side;

	normal = get_mouse_tile_pre(tilemap, offset);

	sf::Vector2f sv(offset.x, offset.y+tile_z);

	side = get_mouse_tile_pre(tilemap, sv);

	if(side.z > normal.z)
		return side;
	return normal;

}

void game_interaction(Tilemap * tilemap, float second_elapsed)
{
	float pps = 10;
	auto offset = sf::Vector2f(iso_target.getViewport(iso_target.getView()).left,iso_target.getViewport(iso_target.getView()).top) ;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		offset.y = offset.y-(pps*second_elapsed);
		iso_target.setView(sf::View(sf::Rect<float>(offset.x, offset.y, 800, 600)));

	}


}

int get_mouse_tile_x()
{

	int mx = sf::Mouse::getPosition(window).x;
	int my = sf::Mouse::getPosition(window).y;


	mx -= tile_x/2;

	int sx = (2* my + mx) / 2;
	int tx = (sx/(tile_y));

	return tx;

}
int get_mouse_tile_y()
{
	int mx = sf::Mouse::getPosition(window).x;
	int my = sf::Mouse::getPosition(window).y;

	mx -= tile_x/2;

	int sy = (2 * my - mx) / 2;
	int ty = (sy/(tile_y));

	return ty;
}
