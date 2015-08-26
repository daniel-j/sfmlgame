#include "stage.h"
#include <SFML/Window/Mouse.hpp>
#include <fstream>
#include <iostream>

namespace Game {

Stage::Stage() {
	vertices.setPrimitiveType(sf::Quads);
	tileset = NULL;
	view.setSize(640, 480);
	view.setCenter(320, 480);
	view.zoom(0.5);


	std::ifstream file("../game/map2.txt");

	std::string line;
	std::string tilesetName;
	int cursor = 0;
	mapHeight = 0;

	if (file.is_open()) {
		std::getline(file, tilesetName);
		std::cout << tilesetName << std::endl;
		while (!file.eof() && std::getline(file,line)) {
			int length = line.length();
			if (length == 0) continue;
			if (cursor == 0) {
				mapWidth = length;
			}


			for (int i = 0; i < length; i++) {
				map[cursor] = stoi(line.substr(i, 1))-1;
				if (map[cursor] < 0) map[cursor] = 0;
				cursor++;
				//std::cout << map[cursor-1] << " ";
			}
			//std::cout << std::endl;
			++mapHeight;
		}

		//std::cout << "closing file..." << std::endl;
		file.close();
	}

	std::cout << "done " << cursor << std::endl;

	tileset = new Tileset();
	tileset->loadFromFile(tilesetName);


	vertices.resize(mapWidth * mapHeight * 4);

	auto tilesetSize = tileset->getSize();

	for (int i = 0; i < mapWidth*mapHeight; i++) {
		int index = map[i];
		if (index == 0) continue;
		int texu = index % tilesetSize.x;
		int texv = index / tilesetSize.x;
		int x = i % mapWidth;
		int y = i / mapWidth;

		// get a pointer to the current tile's quad
		sf::Vertex *quad = &vertices[i * 4];

		// define its 4 corners
		quad[0].position = sf::Vector2f(x * Game::TileSize, y * Game::TileSize);
		quad[1].position = sf::Vector2f((x + 1) * Game::TileSize, y * Game::TileSize);
		quad[2].position = sf::Vector2f((x + 1) * Game::TileSize, (y + 1) * Game::TileSize);
		quad[3].position = sf::Vector2f(x * Game::TileSize, (y + 1) * Game::TileSize);

		// define its 4 texture coordinates
		quad[0].texCoords = sf::Vector2f(texu * Game::TileSize, texv * Game::TileSize);
		quad[1].texCoords = sf::Vector2f((texu + 1) * Game::TileSize, texv * Game::TileSize);
		quad[2].texCoords = sf::Vector2f((texu + 1) * Game::TileSize, (texv + 1) * Game::TileSize);
		quad[3].texCoords = sf::Vector2f(texu * Game::TileSize, (texv + 1) * Game::TileSize);
	}
}

Stage::~Stage() {
	if (tileset != NULL) {
		delete tileset;
	}
}

void Stage::update(sf::Time elapsedTime) {
	auto pos = sf::Mouse::getPosition();
	view.setCenter(pos.x, pos.y);
}

void Stage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.texture = tileset->getTexture();

	target.setView(view);
	target.draw(vertices, states);


	/*
	for (int i = 0; i < mapWidth*mapHeight; i++) {
		tileset->drawTile(target, map[i], (i%mapWidth)*Game::TileSize, (i/mapWidth)*Game::TileSize);
	}
	*/
}

}
