#ifndef _Game_H_
#define _Game_H_

#include "DataConstant.h"
#include "Spaceships/Spaceships.h"
#include "Map.h"
#include "Items/Items.h"
#include "Asteroid/Asteroid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;
using namespace std;
using namespace GUI;

class Game
{
private:
	Texture * boom;
	RenderWindow * window;
	Player * player;
	Map * map;
	Threat threats[5];
	list <Animation> animations;
	list <Asteroid> asteroid;
	list <Coin> coins;

public:
	Game(RenderWindow * window);
	bool update();
	void draw();
};


#endif  //   _Game_H_