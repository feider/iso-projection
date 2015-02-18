#include "render.h"
#include "system.h"

#include <iostream>

void render_ascii(Tilemap * tilemap)
{
	int size_x = tilemap->get_size_x();
	int size_y = tilemap->get_size_y();

	for(int y = 0; y<size_y; y++)
	{
		for(int x = 0; x<size_x; x++)
		{
			Tile_Pile & tile_pile = tilemap->get_tile(x, y);
			std::cout<<tile_pile.front()->type<<" ";
		}
		std::cout<<std::endl;
	}
}



void render_isometric(Tilemap * tilemap)
{
	int dx = tile_x;
	int dy = tile_y;
	int dz= tile_z;

	iso_target.clear();

	sf::Sprite render_sprite;
	for(int x = 0; x<tilemap->get_size_x(); x++)
	{
		for(int y = 0; y<tilemap->get_size_y(); y++)
		{

			int sx = x-y;
			int sy = x+y;
			Tile_Pile & tile_pile = tilemap->get_tile(x, y);
//			std::cout<<"("<<sx<<", "<<sy<<")";

			for(auto t : tile_pile)
			{
				sx = t->x-t->y;
				sx = sx*dx/2;
				sy = t->x+t->y;
				sy = sy*dy/2;
				sy = sy-(dz*t->z);
				int & type = t->type;
				
				render_sprite.setTexture(textures[type]);
				render_sprite.setPosition(sx, sy);
				
				iso_target.draw(render_sprite);
				
			}
			
		}
//		std::cout<<std::endl;
	}

/*
	int cx = get_mouse_tile_x();
	int cy = get_mouse_tile_y();

	int sx = cx-cy;
	sx = sx*dx/2;
	int sy = cy+cx;
	sy = sy*dy/2;
*/ 

//	render_sprite.setTexture(cursor);
//	render_sprite.setPosition(sx, sy);
//	iso_target.draw(render_sprite);

	int cx, cy, cz;

	auto c_pos = get_mouse_tile( tilemap, {0, 0} );
	if(c_pos != sf::Vector3i(-1, -1, min_z-1))
	{
		cx = c_pos.x;
		cy = c_pos.y;
		cz = c_pos.z;

		int sx = cx-cy;
		sx = sx*dx/2;
		int sy = cy+cx;
		sy = sy*dy/2;
		
		sy -= cz*tile_z;

		render_sprite.setPosition(sx, sy);
		render_sprite.setTexture(cursor);
		iso_target.draw(render_sprite);



	}


	iso_target.display();

	
}

sf::RenderTexture iso_target;

sf::Texture* textures = nullptr;
sf::Texture cursor;

void init_iso_target()
{
	int screen_x = size_x;
	int screen_y = size_y;
	

	iso_target.create(screen_x, screen_y, sf::VideoMode::getDesktopMode().bitsPerPixel);

	textures = new sf::Texture[2];
	
	textures[0].loadFromFile("iso-64x64-outside.png", {0, 0, 0, 0});
	textures[1].loadFromFile("tiles.png", {0, 0, 64, 44});

	cursor.loadFromFile("tiles.png", {64, 0, 64, 44});

}
