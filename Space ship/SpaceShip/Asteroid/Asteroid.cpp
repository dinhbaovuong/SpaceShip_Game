#include "Asteroid.h"

Asteroid::Asteroid(RenderWindow * window)
{
	this->texture = new Texture;
	this->column = rand() % 200 + 900;
	this->line = rand() % 480 + 60;
	this->life = true;

	this->texture->loadFromFile(Path_Image_Asteroids + "Asteroids.png");
	this->texture->setSmooth(true);
	this->animation.setData(window, *this->texture, 0, 0, 160, 120, this->column, this->line, 16, 0.1, LEFT_RIGHT, 0.8);
}


void Asteroid::update()
{
	this->column -= 5;
	this->animation.setPosition(Vector2f(this->column, this->line));
	this->animation.update();
}

void Asteroid::draw()
{
	this->animation.draw();
}

Vector2f Asteroid::getPosition()
{
	return Vector2f(this->column, this->line);
}