#include "Bullets.h"


Bullets::Bullets(RenderWindow * window, float column, float line, std::string Name)
{
	this->window = window;
	this->Name = Name;

	this->column = column;
	this->line = line;

	this->sprite = new Sprite;
	this->texture = new Texture;

	this->texture->loadFromFile(Path_Image_Bullets + Name);
	this->texture->setSmooth(true);

	this->sprite->setTexture(*this->texture);
	this->sprite->setOrigin(this->texture->getSize().x / 2, this->texture->getSize().y / 2);
	this->sprite->setPosition(this->column, this->line);
}

void Bullets::update()
{
	if(this->Name == "BulletsPlayer.png")
		this->sprite->move(10, 0);
	else
		this->sprite->move(-8, 0);
	this->column = this->sprite->getPosition().x;
	this->line = this->sprite->getPosition().y;

	if (this->column < 450 && this->line < 300)
		this->area = One;
	else if (this->column > 450 && this->line < 300)
		this->area = Two;
	else if (this->column < 450 && this->line >= 300)
		this->area = Three;
	else if (this->column > 450 && this->line > 300)
		this->area = Four;
	if (this->line > 275 && this->line < 325)
		this->area = Special;
}

void Bullets::draw()
{
	this->window->draw(*this->sprite);
}

float Bullets::getColumn()
{
	return this->column;
}

Area Bullets::getArea()
{
	return this->area;
}

Vector2f Bullets::getPosition()
{
	return this->sprite->getPosition();
}