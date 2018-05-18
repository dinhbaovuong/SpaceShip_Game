#include "Items.h"

//   ========================================================== Class Items ==========================================================

bool ItemsInGame::getLife()
{
	return this->life;
}

Vector2f ItemsInGame::getPosition()
{
	return Vector2f(this->column, this->line);
}


//   ========================================================== Class Coins ==========================================================

Coin::Coin(RenderWindow * window, float column, float line)
{
	this->texture = new Texture;
	this->texture->loadFromFile(Path_Image_Items + "Coin.png");
	this->texture->setSmooth(true);

	this->countSecondLife = 0;
	this->life = true;

	this->column = column;
	this->line = line;
	this->animation = new Animation(window, *this->texture, 0, 0, 50, 50, this->column, this->line, 6, 0.1, LEFT_RIGHT, 1);

}

void Coin::update()
{
	this->countSecondLife++;

	if (this->countSecondLife >= 300)
		this->life = false;

	this->animation->update();
}

void Coin::draw()
{
	this->animation->draw();
}