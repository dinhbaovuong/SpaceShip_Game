#include "Map.h"

Map::Map(RenderWindow * window)
{
	this->window = window;

	this->column_1 = 0;
	this->tx_background.loadFromFile(Path_Image_Map + "Background.png");
	this->tx_background.setSmooth(true);
	this->Sp_background.setTexture(this->tx_background);
	this->Sp_background.setTextureRect(IntRect(this->column_1, 0, Screen_Width, Screen_Height));

	this->column_2 = 0;
	this->tx_map.loadFromFile(Path_Image_Map + "Map.png");
	this->tx_map.setSmooth(true);
	this->Sp_map.setTexture(this->tx_map);
	this->Sp_map.setTextureRect(IntRect(this->column_2, 0, Screen_Width, Screen_Height));
}

void Map::update()
{
	//   Update background
	this->column_1 += 0.5;
	if (this->column_1 >= 4800)
		this->column_1 -= 4800;
	this->Sp_background.setTextureRect(IntRect(this->column_1, 0, Screen_Width, Screen_Height));

	//   Update map
	this->column_2 += 1;
	if (this->column_2 > 4800)
		this->column_2 -= 4800;
	this->Sp_map.setTextureRect(IntRect(this->column_2, 0, Screen_Width, Screen_Height));
}

void Map::draw()
{
	//   Draw background
	this->window->draw(this->Sp_background);

	//   Check and apply background
	if (this->column_1 > 3900)
	{
		this->Sp_background.setTextureRect(IntRect(0, 0, this->column_1 - 3900, Screen_Height));
		this->Sp_background.setPosition(Screen_Width - (this->column_1 - 3900), 0);
		this->window->draw(this->Sp_background);
		this->Sp_background.setTextureRect(IntRect(this->column_1, 0, Screen_Width, Screen_Height));
		this->Sp_background.setPosition(0, 0);
		//cout << "Temp background\n";
	}

	//   Draw background
	this->window->draw(this->Sp_map);


	//   Check and apply map
	if (this->column_2 > 3900)
	{
		this->Sp_map.setTextureRect(IntRect(0, 0, this->column_2 -3900, Screen_Height));
		this->Sp_map.setPosition(Screen_Width - (this->column_2 - 3900), 0);
		this->window->draw(this->Sp_map);
		this->Sp_map.setTextureRect(IntRect(this->column_2, 0, Screen_Width, Screen_Height));
		this->Sp_map.setPosition(0, 0);
		//cout << "Temp map\n";
	}

}