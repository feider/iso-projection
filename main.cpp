#include "tilemap.h"
#include "render.h"

int main()
{
	Tilemap * tilemap = new Tilemap(10, 10, 1);

	render_ascii(tilemap);


	sf::RenderWindow window(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Iso RenderWindow");

	init_iso_target();

	render_isometric(tilemap);

	sf::Sprite map_sprite;
	map_sprite.setTexture(iso_target.getTexture());
	window.clear();
	window.draw(map_sprite);
	window.display();
	while(true){}

	delete tilemap;
	return 0;
}
