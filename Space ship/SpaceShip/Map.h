#ifndef _Map_H_
#define _Map_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "DataConstant.h"

using namespace sf;
using namespace std;


//   Có chức năng load map
class Map
{
private:
	RenderWindow * window;

	Texture tx_background;
	Texture tx_map;

	Sprite Sp_background;
	Sprite Sp_map;

	float column_1;            //   Background
	float column_2;            //   Map

public:
	Map(RenderWindow * window);
	void update();
	void draw();
};




#endif //   _Map_H_