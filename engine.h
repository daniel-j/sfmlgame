#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "stage.h"

namespace Game {

class Engine : private sf::NonCopyable {
	public:
		Engine(int argc, char *argv[]);
		~Engine();
		int run();

	private:
		void processEvents();
		void update(sf::Time elapsedTime);
		void render();
		void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);

		static const sf::Time TimePerFrame;

		sf::RenderWindow window;
		bool isExiting;
		Stage *stage;
};

}

#endif // ENGINE_H
