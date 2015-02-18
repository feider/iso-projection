
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


sf::RenderTexture iso_target;

sf::Texture texture;

void init_stuff()
{
	iso_target.create(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel);

	texture.loadFromFile("iso-64x64-outside.png", {256, 193, 63, 64});
}

void draw_stuff()
{
	iso_target.clear();
	
	sf::Sprite thingy;
	thingy.setTexture(texture);
	thingy.setPosition(10, 10);

	iso_target.draw(thingy);

	iso_target.display();
}

int main()
{

	
	sf::RenderWindow window(sf::VideoMode(800, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "minimalexample");

	init_stuff();
	draw_stuff();

	sf::Sprite map_sprite;
	map_sprite.setTexture(iso_target.getTexture());

	window.clear();
	window.draw(map_sprite);
	window.display();

	while(true){}

	return 0;
}
