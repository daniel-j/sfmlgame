#ifndef STAGE_H
#define STAGE_H
#include <SFML/Graphics/VertexArray.hpp>
#include "game.h"
#include "tileset.h"

namespace Game {

class Stage : public sf::Drawable, sf::Transformable {
	public:
		Stage();
		~Stage();
		void update(sf::Time elapsedTime);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		int mapWidth;
		int mapHeight;
		int map[Game::MaxStageWidth*Game::MaxStageHeight];
		sf::VertexArray vertices;
		Tileset *tileset;
		sf::View view;

};

}
#endif // STAGE_H
