#include "tilemap.h"
#include "render.h"
#include "system.h"
#include <iostream>
#include <time.h>

int main()
{
	Tilemap * tilemap = new Tilemap(10, 10, 1);

	tilemap->add_tile(5, 5, 1, 1);
	tilemap->add_tile(4, 5, 1, 2);
	tilemap->add_tile(5, 4, 1, 2);
	tilemap->add_tile(4, 4, 1, 2);
	tilemap->add_tile(4, 4, 2, 1);
	tilemap->add_tile(8, 8, 1, 1);
	tilemap->add_tile(8, 8, 2, 1);
	tilemap->add_tile(8, 8, 3, 1);
	tilemap->add_tile(8, 8, 4, 1);
	tilemap->add_tile(8, 8, 5, 1);
	tilemap->add_tile(8, 8, 6, 1);
	//render_ascii(tilemap);


//	sf::RenderWindo window(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Iso RenderWindow");
//

	window.create(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Iso RenderWindow");
	init_iso_target();

	bool end = false;

	time_t start = time(0);


	double frames = 0;

	while(!end)
	{
		frames++;
		render_isometric(tilemap);
		sf::Sprite map_sprite;
		map_sprite.setTexture(iso_target.getTexture());
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			end = true;
		}
			
		window.clear();
		window.draw(map_sprite);
		window.display();

		time_function(tilemap);

	}


	double seconds_since_start = difftime( time(0), start);
	std::cout<<frames/seconds_since_start<<std::endl;

	game_interaction(tilemap, 0);

	delete tilemap;
	return 0;
}
