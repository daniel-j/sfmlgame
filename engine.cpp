#include "engine.h"
#include "stage.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game {

const sf::Time Engine::TimePerFrame = sf::milliseconds(1000/60);

Engine::Engine(int argc, char *argv[]) {
	window.create(sf::VideoMode(640, 480, 16), "Game", sf::Style::Close);
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	isExiting = false;

	stage = new Stage();
}
Engine::~Engine() {
	delete stage;
}

int Engine::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen()) {
		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();
		processEvents();
		if (isExiting) return 0;
		update(elapsedTime);
		//std::cout << "FPS: " << 1.0f / elapsedTime.asSeconds() << std::endl;
		//updateStatistics(elapsedTime);
		render();
	}
	return 0;
}

void Engine::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
			isExiting = true;
			return;
		}

		switch (event.type) {
			case sf::Event::KeyPressed:
				handleKeyboardInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handleKeyboardInput(event.key.code, false);
				break;

			default:
				// supresses warnings
				break;
		}
	}
}

void Engine::update(sf::Time elapsedTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		std::cout << "left key!!" << std::endl;
	}
	stage->update(elapsedTime);
}

void Engine::render() {
	window.clear(); // Clears the backbuffer
	window.draw(*stage);
	window.display(); // Move/copy backbuffer to frontbuffer
}



void Engine::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
	std::cout << key << " " << isPressed << std::endl;
}

}
