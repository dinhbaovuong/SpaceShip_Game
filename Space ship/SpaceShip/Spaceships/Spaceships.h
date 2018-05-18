#ifndef _Spaceships_H_
#define _Spaceships_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "../DataConstant.h"
#include "../Bullets/Bullets.h"

using namespace sf;
using namespace std;

class Spaceships
{
protected:
	RenderWindow * window;

	//   true is life
	//   false is die
	bool  life;

	//   Tọa độ trên màn hình
	float column;
	float line;

	float Hp;
	float HpMax;
	int   timeShoot;
	int   damage;
	Area  area;
	//int   CountBullets;
	RectangleShape barHp;

public:
	list <Bullets> bullets;
	Vector2f getPosition();
	Area getArea();
	void setHp(int Hp);
	int getHp();
	int getDamage();
	//void setCountBullets(int CountBullets);
};


class Player : public Spaceships
{
private:
	//list <Bullets> bullets;
	bool Shoot;
	int countCoin;

	//   Texture
	Texture * tx_main_gun;
	Texture * tx_main_body;
	Texture * tx_wing_up;
	Texture * tx_wing_down;
	Texture * tx_box;

	//   Sprite
	Sprite * sp_main_gun;
	Sprite * sp_main_body;
	Sprite * sp_wing_up;
	Sprite * sp_wing_down;
	Sprite * sp_box;


	
public:
	Player(RenderWindow * window);
	void update();
	void draw();
	void setLife(bool life);
	bool getLife();
	void setCoin(int coins);
	int getCoin();
};

class Threat : public Spaceships
{
private:
	//   Texture
	Texture * texture;
	
	//   Sprite
	Sprite * sprite;

	

public:
	Threat() {}
	void setData(RenderWindow * window);
	void update();
	void draw();
	void setLife(bool life);

};

#endif  //   _Spaceships_H_