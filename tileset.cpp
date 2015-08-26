#include "tileset.h"
#include "game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>


namespace Game {

Tileset::Tileset() {
	texture = NULL;
}

bool Tileset::loadFromFile(std::string filename) {
	sf::Texture *tex = new sf::Texture();
	if (!tex->loadFromFile(filename)) {
		return false;
	}
	setTexture(tex);
	return true;
}

Tileset::~Tileset() {
	if (texture != NULL) {
		delete texture;
	}
}

void Tileset::setTexture(sf::Texture *tex) {
	if (texture != NULL) {
		delete texture;
	}
	texture = tex;
	texture->setSmooth(false);
	size = texture->getSize();
	size.x /= Game::TileSize;
	size.y /= Game::TileSize;
	width = size.x;
	height = size.y;
	//sprite.setTexture(*texture);
}

/*void Tileset::drawTile(sf::RenderWindow *window, int index, int x, int y) {
	sprite.setTextureRect(sf::IntRect((index % width)*Game::TileSize, (index / width)*Game::TileSize, Game::TileSize, Game::TileSize));
	sprite.setPosition(x, y);
	window->draw(sprite);
}*/

sf::Texture* Tileset::getTexture() const {
	return texture;
}

sf::Vector2u Tileset::getSize() const {
	return size;
}

}
