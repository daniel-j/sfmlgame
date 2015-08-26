#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Game {

class Tileset {
	public:
		Tileset();
		~Tileset();
		//void drawTile(sf::RenderWindow *window, int index, int x, int y);

		bool loadFromFile(std::string filename);

		sf::Texture* getTexture() const;
		sf::Vector2u getSize() const;

	private:
		void setTexture(sf::Texture *tex);

		sf::Texture *texture;
		//sf::Sprite sprite;
		int width;
		int height;
		sf::Vector2u size;
};

}

#endif // TILESET_H
