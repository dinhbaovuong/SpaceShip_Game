#include "GUI.h"

using namespace GUI;

//   ======================================================== Class Animation ========================================================

Animation::Animation(RenderWindow * window, Texture &texture, float x, float y, float Column, float Line, float column, float line, int Count, float speed, Direction direction, float ratio)
{
	//   Đây là constructor của class Animation

	this->window = window;
	this->direction = direction;
	this->speed = speed;
	this->sprite.setTexture(texture);
	this->sprite.setOrigin(Column / 2, Line / 2);

	if (this->direction == LEFT_RIGHT)
		for (int count = 0; count < Count; count++)
			Frames.push_back(IntRect(x + count * Column, y, Column, Line));
	else if (this->direction == UP_DOWN)
		for (int count = 0; count < Count; count++)
			Frames.push_back(IntRect(x, y + count * Line, Column, Line));
	this->sprite.setScale(ratio, ratio);
	this->sprite.setTextureRect(Frames[0]);
	this->sprite.setPosition(column, line);
}

void Animation::setData(RenderWindow * window, Texture &texture, float x, float y, float Column, float Line, float column, float line, int Count, float speed, Direction direction, float ratio)
{
	this->window = window;
	this->direction = direction;
	this->speed = speed;
	this->sprite.setTexture(texture);
	this->sprite.setOrigin(Column / 2, Line / 2);

	if (this->direction == LEFT_RIGHT)
		for (int count = 0; count < Count; count++)
			Frames.push_back(IntRect(x + count * Column, y, Column, Line));
	else if (this->direction == UP_DOWN)
		for (int count = 0; count < Count; count++)
			Frames.push_back(IntRect(x, y + count * Line, Column, Line));
	this->sprite.setScale(ratio, ratio);
	this->sprite.setTextureRect(Frames[0]);
	this->sprite.setPosition(column, line);
}


void Animation::update()
{
	this->Frame += this->speed;

	//   Biến đếm số khung hình
	int Count = this->Frames.size();

	if (this->Frame >= Count)
		this->Frame -= Count;

	if (Count > 0)
		this->sprite.setTextureRect(this->Frames[int(this->Frame)]);
}


void Animation::draw()
{
	this->window->draw(this->sprite);
}

bool Animation::isEnd()
{
	return Frame + speed >= Frames.size();
}

void Animation::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}