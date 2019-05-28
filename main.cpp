#include "reader.h"
#include <SFML/Graphics.hpp>

int main()
{
	std::string stream = read_file("test.gi");
	std::vector<std::vector<std::string>> parsed = parse(stream);
	std::cout << "passed" << std::endl;
	sf::RenderWindow window(sf::VideoMode(200,200),"Gogeta Image Viewer",sf::Style::Close | sf::Style::Titlebar);
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;

	image.create(200,200, sf::Color::Black);
	
	int y = 0;
	int x = 0;
	for(std::vector<std::string> str_vec : parsed) { // str_vec is a row 
		for(std::string s : str_vec) { // s is a RRGGBBAA pixel
			image.setPixel(x, y, extract_color(s));
			x++;
			if(x > image.getSize().x) break;
		}
		x = 0;
		y++;
		if(y > image.getSize().y) break;
	}

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	
	sf::Event event;
	while(window.isOpen()) {
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}

}