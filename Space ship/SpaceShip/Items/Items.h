#ifndef _Items_H_
#define _Items_H_

#include <SFML/Graphics.hpp>
#include "../DataConstant.h"
#include "../GUI/GUI.h"


using namespace sf;
using namespace GUI;

class ItemsInGame
{
protected:
	Texture * texture;
	float column;
	float line;
	bool life;
	int countSecondLife;
	Animation * animation;

public:
	bool getLife();
	Vector2f getPosition();
};


class Coin : public ItemsInGame
{
private:

public:
	Coin(RenderWindow * window, float column, float line);
	void update();
	void draw();
};


#endif //   _Items_H_