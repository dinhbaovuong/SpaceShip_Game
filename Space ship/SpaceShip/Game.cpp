#include "Game.h"

Game::Game(RenderWindow * window)
{
	this->window = window;
	this->map = new Map(this->window);
	this->player = new Player(this->window);

	for (int count = 0; count < 5; count++)
		this->threats[count].setData(this->window);

	this->boom = new Texture;
	this->boom->loadFromFile(Path_Image_GUI + "Boom.png");
	this->boom->setSmooth(true);
	//this->asteroid.push_back(Asteroid(this->window));
	//this->countAsteroid = 1;
}

bool Game::update()
{
	map->update();
	for (int count = 0; count < 5; count++)
		this->threats[count].update();

	player->update();

	if (this->asteroid.size() > 0)
		for (list <Asteroid> ::iterator it = this->asteroid.begin(); it != this->asteroid.end(); it++)
			it->update();

	if (rand() % 200 == 50 && this->asteroid.size() >= 0)
	{
		this->asteroid.push_back(Asteroid(this->window));
		//this->countAsteroid++;
	}


	if (this->asteroid.size() > 0 && this->asteroid.begin()->getPosition().x <= 0)
	{
		this->asteroid.pop_front();
		//this->countAsteroid--;
	}


	if (this->coins.size() > 0)
	{
		for (list <Coin> ::iterator it = this->coins.begin(); it != this->coins.end(); it++)
			it->update();

		if (!this->coins.begin()->getLife())
			this->coins.pop_front();
	}


	if (this->player->getLife())
	{
		//   Kiểm tra xem thiên thạch có trúng Player không
		for (list <Asteroid> ::iterator it = this->asteroid.begin(); it != this->asteroid.end(); it++)
		{
			float x = abs(this->player->getPosition().x - it->getPosition().x);
			float y = abs(this->player->getPosition().y - it->getPosition().y);
			if (x <= 60 && y <= 50)
			{
				this->player->setHp(this->player->getHp() - 30);
				if (this->player->getHp() <= 0)
					this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->player->getPosition().x, this->player->getPosition().y, 64, 1, LEFT_RIGHT, 5));
				else
					this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->player->getPosition().x, this->player->getPosition().y, 64, 1, LEFT_RIGHT, 0.8));
				//this->countAsteroid--;
				this->asteroid.erase(it);
				break;
			}
		}


		//   Kiểm tra xem Player có ăn tiền không
		if (this->coins.size() > 0)
		{
			for (list <Coin> ::iterator it = this->coins.begin(); it != this->coins.end(); it++)
			{
				float x = abs(this->player->getPosition().x - it->getPosition().x);
				float y = abs(this->player->getPosition().y - it->getPosition().y);
				if (x <= 60 && y <= 50)
				{
					this->player->setCoin(this->player->getCoin() + 1);
					//cout << this->player->getCoin() << endl;
					this->coins.erase(it);
					break;
				}
			}
		}



		//   Kiểm tra va chạm giữa Player và Threats
		for (int i = 0; i < 5; i++)
		{
			float x = abs(this->player->getPosition().x - this->threats[i].getPosition().x);
			float y = abs(this->player->getPosition().y - this->threats[i].getPosition().y);
			//float x = abs(this->threats[i].getPosition().x - this->player->getPosition().x);
			//float y = abs(this->threats[i].getPosition().y - this->player->getPosition().y);
			if (x <= 100 && y <= 50)
			{
				float xx = (this->player->getPosition().x < this->threats[i].getPosition().x) ? this->player->getPosition().x : this->threats[i].getPosition().x;
				float yy = (this->player->getPosition().y < this->threats[i].getPosition().y) ? this->player->getPosition().y : this->threats[i].getPosition().y;
				this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, xx + x / 2, yy + y / 2, 64, 1, LEFT_RIGHT, 3));
				this->player->setLife(false);
				break;
			}
		}

		//   Kiểm tra Player có bắn trúng Threat không

		//if (this->player->getCountBullets() > 0)
		if (this->player->bullets.size() > 0)
		{
			bool check_player_kill_threats = false;

			for (int i = 0; i < 5; i++)
			{
				for (list <Bullets> ::iterator it = this->player->bullets.begin(); it != this->player->bullets.end(); it++)
				{
					float x = abs(this->threats[i].getPosition().x - it->getPosition().x);
					float y = abs(this->threats[i].getPosition().y - it->getPosition().y);
					if (this->threats[i].getArea() == it->getArea() && x<= 50 && y <= 28)
					{
						check_player_kill_threats = true;
						this->threats[i].setHp(this->threats[i].getHp() - this->player->getDamage());
						if (this->threats[i].getHp() > 0) this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->threats[i].getPosition().x - 39, this->threats[i].getPosition().y, 64, 1, LEFT_RIGHT, 0.5));
						else
						{
							this->threats[i].setLife(false);
							this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->threats[i].getPosition().x - 39, this->threats[i].getPosition().y, 64, 1, LEFT_RIGHT, 1));

							if (rand() % 100 == 50)
								this->coins.push_back(Coin(this->window, this->threats[i].getPosition().x - 39, this->threats[i].getPosition().y));
						}
						this->player->bullets.erase(it);
						break;
					}
				}
				if (check_player_kill_threats)
				{
					break;
				}
			}
		}

		//   Kiểm tra Player có bắn trúng thiên thạch không

		//if (this->player->getCountBullets() > 0 && this->countAsteroid > 0)
		if (this->player->bullets.size() >0 && this->asteroid.size() >0)
		{
			list <Bullets> ::iterator bullet;
			list <Asteroid> ::iterator asteroid;
			bool check_player_kill_asteroid = false;
			
			for (list <Asteroid> ::iterator it_1 = this->asteroid.begin(); it_1 != this->asteroid.end(); it_1++)
			{
				for (list <Bullets> ::iterator it_2 = this->player->bullets.begin(); it_2 != this->player->bullets.end(); it_2++)
				{
					float x = abs(it_2->getPosition().x - it_1->getPosition().x);
					float y = abs(it_2->getPosition().y - it_1->getPosition().y);
					if (x <= 50 && y <= 40)
					{
						check_player_kill_asteroid = true;
						asteroid = it_1;
						bullet = it_2;
						this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, it_1->getPosition().x, it_1->getPosition().y, 64, 1, LEFT_RIGHT, 1));
						this->player->bullets.erase(it_2);
						this->asteroid.erase(it_1);
						break;
					}
				}
				if (check_player_kill_asteroid)	break;
			}
		}
		
		//   Kiểm tra Threat có bắn Player không

		bool check_theat_shoot_player = false;

		for (int i = 0; i < 5; i++)
		{
			for (list <Bullets> ::iterator it = this->threats[i].bullets.begin(); it != this->threats[i].bullets.end(); it++)
			{
				float x = abs(this->player->getPosition().x - it->getPosition().x);
				float y = abs(this->player->getPosition().y - it->getPosition().y);

				if (x <= 100 && y <= 50)
				{
					check_theat_shoot_player = true;

					this->player->setHp(this->player->getHp() - this->threats[i].getDamage());
					if (this->player->getHp() > 0) 
						this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->player->getPosition().x, this->player->getPosition().y, 64, 1, LEFT_RIGHT, 0.5));
					else
					{
						this->player->setLife(false);
						this->animations.push_back(Animation(this->window, *this->boom, 0, 0, 192, 192, this->player->getPosition().x, this->player->getPosition().y, 64, 1, LEFT_RIGHT, 3));
					}
					this->threats[i].bullets.erase(it);
					break;
				}
			}

			if (check_theat_shoot_player)
			{
				break;
			}
		}
	}

	if (this->animations.size() > 0)
	{
		for (list <Animation> ::iterator it = this->animations.begin(); it != this->animations.end(); it++)
			it->update();
		if (this->animations.begin()->isEnd())
			this->animations.pop_front();
	}

	if (this->animations.size() == 0 && !this->player->getLife())
		return false;
	else return true;
}

void Game::draw()
{
	map->draw();
	for (int count = 0; count < 5; count++)
		this->threats[count].draw();


	if (this->coins.size() > 0)
		for (list <Coin> ::iterator it = this->coins.begin(); it != this->coins.end(); it++)
			it->draw();

	//if (this->countAsteroid > 0)
	if (this->asteroid.size() > 0)
		for (list <Asteroid> ::iterator it = this->asteroid.begin(); it != this->asteroid.end(); it++)
			it->draw();


	if (this->player->getLife()) player->draw();
	if (this->animations.size() > 0)
	{
		for (list <Animation> ::iterator it = this->animations.begin(); it != this->animations.end(); it++)
			it->draw();
	}
}