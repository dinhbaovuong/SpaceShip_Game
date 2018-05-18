#include "Spaceships.h"
#include "../DataConstant.h"
#include <stdlib.h>

//   ========================================================= Class Spaceships =========================================================

Vector2f Spaceships::getPosition()
{
	Vector2f position(this->column, this->line);
	return position;
}

Area Spaceships::getArea()
{
	return this->area;
}

int Spaceships::getHp()
{
	return this->Hp;
}

void Spaceships::setHp(int Hp)
{
	this->Hp = Hp;
}

int Spaceships::getDamage()
{
	return this->damage;
}


//   ======================================================== Class Player ========================================================

Player::Player(RenderWindow * window)
{
	this->window = window;
	this->column = 50;
	this->line = 250;
	this->life = true;
	this->timeShoot = 20;
	this->Shoot = false;
	this->HpMax = 150;
	this->Hp = this->HpMax;
	this->damage = 25;
	//this->CountBullets = 0;
	this->countCoin = 0;

	this->barHp.setFillColor(Color::Red);
	this->barHp.setSize(Vector2f(80, 5));
	this->barHp.setPosition(this->column - 60, this->line + 50);

	this->tx_main_gun = new Texture;
	this->tx_main_body = new Texture;
	this->tx_wing_up = new Texture;
	this->tx_wing_down = new Texture;
	this->tx_box = new Texture;

	this->sp_main_gun = new Sprite;
	this->sp_main_body = new Sprite;
	this->sp_wing_up = new Sprite;
	this->sp_wing_down = new Sprite;
	this->sp_box = new Sprite;


	//   Main Gun
	this->tx_main_gun->loadFromFile(Path_Image_Spaceships + "GunPlayer.png");
	this->tx_main_gun->setSmooth(true);
	this->sp_main_gun->setTexture(*this->tx_main_gun);
	this->sp_main_gun->setOrigin(this->tx_main_gun->getSize().x / 2, this->tx_main_gun->getSize().y / 2);
	this->sp_main_gun->setPosition(this->column, this->line);
	this->sp_main_gun->setScale(0.8, 0.8);


	//   Main Body
	this->tx_main_body->loadFromFile(Path_Image_Spaceships + "BodyPlayer.png");
	this->tx_main_body->setSmooth(true);
	this->sp_main_body->setTexture(*this->tx_main_body);
	this->sp_main_body->setOrigin(this->tx_main_body->getSize().x / 2, this->tx_main_body->getSize().y / 2);
	this->sp_main_body->setPosition(this->column, this->line);
	this->sp_main_body->setColor(Color::Red);
	this->sp_main_body->setScale(0.8, 0.8);


	//   Wing Up
	this->tx_wing_up->loadFromFile(Path_Image_Spaceships + "WingUp.png");
	this->tx_wing_up->setSmooth(true);
	this->sp_wing_up->setTexture(*this->tx_wing_up);
	this->sp_wing_up->setOrigin(this->tx_wing_up->getSize().x / 2, this->tx_wing_up->getSize().y / 2);
	this->sp_wing_up->setPosition(this->column - 40, this->line - 30);
	this->sp_wing_up->setScale(0.8, 0.8);



	//   Wing Down
	this->tx_wing_down->loadFromFile(Path_Image_Spaceships + "WingDown.png");
	this->tx_wing_down->setSmooth(true);
	this->sp_wing_down->setTexture(*this->tx_wing_down);
	this->sp_wing_down->setOrigin(this->tx_wing_down->getSize().x / 2, this->tx_wing_down->getSize().y / 2);
	this->sp_wing_down->setPosition(this->column - 40, this->line + 30);
	this->sp_wing_down->setScale(0.8, 0.8);



	//   Box
	this->tx_box->loadFromFile(Path_Image_Spaceships + "Box.png");
	this->tx_box->setSmooth(true);
	this->sp_box->setTexture(*this->tx_box);
	this->sp_box->setOrigin(this->tx_box->getSize().x / 2, this->tx_box->getSize().y / 2);
	this->sp_box->setPosition(this->column - 40, this->line);
	this->sp_box->setScale(0.8, 0.8);


}


void Player::update()
{
	this->sp_main_body->setPosition(this->column, this->line);
	this->sp_main_gun->setPosition(this->column, this->line);
	this->sp_wing_up->setPosition(this->column - 40, this->line - 30);
	this->sp_wing_down->setPosition(this->column - 40, this->line + 30);
	this->sp_box->setPosition(this->column - 40, this->line);
	this->sp_box->setRotation(this->sp_box->getRotation() + 10);
	this->barHp.setPosition(this->column - 60, this->line + 50);
	//if (this->Hp <= 147) this->Hp += 3;
	this->barHp.setSize(Vector2f(this->Hp / this->HpMax * 80, 5));

	//   Update Bullets

	//if (this->CountBullets > 0)
	if (this->bullets.size() > 0)
		for (list <Bullets> ::iterator it = bullets.begin(); it != bullets.end(); it++)
			it->update();

	//   Nhận sự kiện bàn phím
	if (Keyboard::isKeyPressed(Keyboard::Left) && this->column > 50)
	{
		this->column -= 5;
		this->sp_wing_up->setPosition(this->sp_wing_up->getPosition().x - 30, this->sp_wing_up->getPosition().y + 10);
		this->sp_wing_down->setPosition(this->sp_wing_down->getPosition().x - 30, this->sp_wing_down->getPosition().y - 10);
		this->sp_box->setPosition(this->sp_box->getPosition().x - 30, this->line);
		this->barHp.setPosition(this->barHp.getPosition().x - 30, this->barHp.getPosition().y);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && this->column < 850)
	{
		this->column += 5;
		this->sp_wing_up->setPosition(this->sp_wing_up->getPosition().x + 30, this->sp_wing_up->getPosition().y - 10);
		this->sp_wing_down->setPosition(this->sp_wing_down->getPosition().x + 30, this->sp_wing_down->getPosition().y + 10);
		this->sp_box->setPosition(this->sp_box->getPosition().x + 30, this->line);
		this->barHp.setPosition(this->barHp.getPosition().x + 30, this->barHp.getPosition().y);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && this->line > 50)
		this->line -= 5;
	if (Keyboard::isKeyPressed(Keyboard::Down) && this->line < 550)
		this->line += 5;

	//   Kiểm tra có bắn không
	if (Keyboard::isKeyPressed(Keyboard::Space) && this->timeShoot >= 20 && bullets.size() < 10)
	{
		//cout << "Shoot\n";
		this->Shoot = true;
		this->bullets.push_back(Bullets(this->window, this->column + 55, this->line, "BulletsPlayer.png"));
		this->timeShoot = 0;
		//this->CountBullets++;
	}
	else this->Shoot = false;

	if (this->timeShoot < 10)
	{
		this->sp_main_gun->setPosition(this->sp_main_gun->getPosition().x - 10, this->line);
		this->sp_wing_up->setPosition(this->sp_wing_up->getPosition().x - 30, this->sp_wing_up->getPosition().y - 10);
		this->sp_wing_down->setPosition(this->sp_wing_down->getPosition().x - 30, this->sp_wing_down->getPosition().y + 10);
	}

	if (this->timeShoot > 10 && this->timeShoot <= 15)
	{
		this->sp_main_gun->setPosition(this->sp_main_gun->getPosition().x + 10, this->line);
		this->sp_wing_up->setPosition(this->sp_wing_up->getPosition().x + 30, this->sp_wing_up->getPosition().y + 10);
		this->sp_wing_down->setPosition(this->sp_wing_down->getPosition().x + 30, this->sp_wing_down->getPosition().y - 10);
	}


	this->timeShoot++;

	if (this->bullets.size() >= 0 && bullets.begin()->getColumn() >= Screen_Width)
	{
		bullets.pop_front();
		//cout << "Delete\n";
		//this->CountBullets--;
	}

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

	//if (this->Hp <= 0)
		//this->life = false;
}


void Player::draw()
{
	this->window->draw(*this->sp_box);
	this->window->draw(*this->sp_main_gun);
	this->window->draw(*this->sp_main_body);
	this->window->draw(*this->sp_wing_up);
	this->window->draw(*this->sp_wing_down);
	this->window->draw(this->barHp);

	//if (this->CountBullets > 0)
	if (this->bullets.size() > 0)
		for (list <Bullets> ::iterator it = this->bullets.begin(); it != this->bullets.end(); it++)
			it->draw();

}

void Player::setLife(bool life)
{
	this->life = life;
}

bool Player::getLife()
{
	return this->life;
}

void Player::setCoin(int coins)
{
	this->countCoin = coins;
}

int Player::getCoin()
{
	return this->countCoin;
}


//   ======================================================== Class Threat ========================================================

void Threat::setData(RenderWindow * window)
{
	this->window = window;
	//srand(time(NULL));
	this->life = true;
	this->HpMax = 30;
	this->Hp = this->HpMax;
	this->damage = 20;


	//this->CountBullets = 0;

	switch (rand() % 5)
	{
	case 0:
		this->column = 1000;
		break;
	case 1:
		this->column = 1300;
		break;
	case 2:
		this->column = 1100;
		break;
	case 3:
		this->column = 900;
		break;
	case 4:
		this->column = 1200;
		break;
	}

	switch (rand() % 5)
	{
	case 0:
		this->line = 25;
		break;
	case 1:
		this->line = 200;
		break;
	case 2:
		this->line = 300;
		break;
	case 3:
		this->line = 400;
		break;
	case 4:
		this->line = 550;
		break;
	}

	this->barHp.setFillColor(Color::Red);
	this->barHp.setSize(Vector2f(60, 5));
	this->barHp.setPosition(this->column - 30, this->line + 30);

	this->texture = new Texture;
	this->sprite = new Sprite;

	this->texture->loadFromFile(Path_Image_Spaceships + "Threats.png");
	this->texture->setSmooth(true);
	this->sprite->setTexture(*this->texture);
	this->sprite->setOrigin(this->texture->getSize().x / 2, this->texture->getSize().y / 2);
	this->sprite->setPosition(this->column, this->line);

	this->timeShoot = 30;
}

void Threat::update()
{
	if (this->life)
		this->column -= 3;
	else this->setData(this->window);

	if (this->column < -40)
		this->life = false;

	//this->Hp += 3;
	this->sprite->setPosition(this->column, this->line);
	this->barHp.setPosition(this->column - 30, this->line + 30);
	this->barHp.setSize(Vector2f(this->Hp / this->HpMax * 60, 5));

	if (this->timeShoot >= 100)
	{
		this->bullets.push_back(Bullets(this->window, this->column - 39, this->line, "BulletsThreats.png"));
		this->timeShoot = 0;
		//this->CountBullets++;
	}

	this->timeShoot++;

	//if (this->CountBullets > 0)
	if (this->bullets.size() > 0)
		for (list <Bullets> ::iterator it = bullets.begin(); it != bullets.end(); it++)
			it->update();

	if (this->bullets.size() >= 0 && this->bullets.begin()->getColumn() < 0)
	{
		this->bullets.pop_front();
		//cout << "Threat Delete\n";
	}

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

	if (!this->life)
	{
		this->life = true;
		this->HpMax = 30;
		this->Hp = this->HpMax;

		switch (rand() % 5)
		{
		case 0:
			this->column = 1000;
			break;
		case 1:
			this->column = 1300;
			break;
		case 2:
			this->column = 1100;
			break;
		case 3:
			this->column = 900;
			break;
		case 4:
			this->column = 1200;
			break;
		}

		switch (rand() % 5)
		{
		case 0:
			this->line = 25;
			break;
		case 1:
			this->line = 200;
			break;
		case 2:
			this->line = 300;
			break;
		case 3:
			this->line = 400;
			break;
		case 4:
			this->line = 550;
			break;
		}
	}

	if (this->Hp <= 0)
		this->life = false;
}


void Threat::draw()
{

	//if (this->CountBullets > 0)
	if (this->bullets.size() > 0)
		for (list <Bullets> ::iterator it = bullets.begin(); it != bullets.end(); it++)
			it->draw();

	this->window->draw(*this->sprite);
	this->window->draw(this->barHp);

}

void Threat::setLife(bool life)
{
	this->life = life;
}