#include "tilemap.h"
#include "render.h"
#include "system.h"
#include <iostream>

int main()
{
	Tilemap * tilemap = new Tilemap(10, 10, 1);

	tilemap->add_tile(5, 5, 1, 1);
	tilemap->add_tile(4, 5, 1, 1);
	tilemap->add_tile(5, 4, 1, 1);
	tilemap->add_tile(4, 4, 1, 1);
	tilemap->add_tile(4, 4, 2, 1);
	tilemap->add_tile(8, 8, 1, 1);
	tilemap->add_tile(8, 8, 2, 1);
	tilemap->add_tile(8, 8, 3, 1);
	tilemap->add_tile(8, 8, 4, 1);
	tilemap->add_tile(8, 8, 5, 1);
	tilemap->add_tile(8, 8, 6, 1);
	render_ascii(tilemap);


//	sf::RenderWindo window(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Iso RenderWindow");
//

	window.create(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Iso RenderWindow");
	init_iso_target();

	bool end = false;
	while(!end)
	{
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

	}

	delete tilemap;
	return 0;
}
