#ifndef _Bullets_H_
#define _Bullets_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../DataConstant.h"
#include "../GUI/GUI.h"

using namespace sf;
using namespace GUI;


class Bullets
{
private:
	RenderWindow * window;

	//   Tọa độ của viên đạn trên màn hình

	float column;
	float line;

	Sprite * sprite;
	Texture * texture;

	std::string Name;

	Area area;

public:
	Bullets(RenderWindow * window, float column, float line, std::string Name);
	void update();
	void draw();
	float getColumn();
	Area getArea();
	Vector2f getPosition();
};



#endif //   _Bullets_H_