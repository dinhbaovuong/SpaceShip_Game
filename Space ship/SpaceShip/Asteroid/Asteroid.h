#ifndef _Asteroid_H_
#define _Asteroid_H_

#include <SFML/Graphics.hpp>
#include "../DataConstant.h"
#include "../GUI/GUI.h"

using namespace sf;
using namespace GUI;

class Asteroid
{
private:
	Texture * texture;

	float column;
	float line;

	Animation animation;

	bool life;

public:
	Asteroid(RenderWindow * window);
	void update();
	void draw();
	Vector2f getPosition();

};


#endif //   _Asteroid_H_