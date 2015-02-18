#include "render.h"

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
			std::cout<<tile_pile.back()->type<<" ";
		}
		std::cout<<std::endl;
	}
}



void render_isometric(Tilemap * tilemap)
{
	int dx = 64;
	int dy = 32;
	int dz= 256-224;

	iso_target.clear();

	sf::Sprite render_sprite;
	for(int x = 0; x<tilemap->get_size_x(); x++)
	{
		for(int y = 0; y<tilemap->get_size_y(); y++)
		{

			int sx = x-y;
			int sy = x+y;
			Tile_Pile & tile_pile = tilemap->get_tile(x, y);
			std::cout<<"("<<sx<<", "<<sy<<")";

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
		std::cout<<std::endl;
	}

	iso_target.display();

	
}

sf::RenderTexture iso_target;

sf::Texture* textures = nullptr;

void init_iso_target()
{
	int screen_x = 800;
	int screen_y = 600;
	

	iso_target.create(screen_x, screen_y, sf::VideoMode::getDesktopMode().bitsPerPixel);

	textures = new sf::Texture[2];
	
	textures[0].loadFromFile("iso-64x64-outside.png", {0, 0, 64, 32});
	textures[1].loadFromFile("iso-64x64-outside.png", {256, 193, 64, 64});

}
