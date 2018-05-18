#ifndef _Data_Constant_H_
#define _Data_Constant_H_

//   File này dùng để định nghĩa các thông số của game

#include <string>

//   Thông số màn hình
const int Screen_Width = 900;                 //   Chiều rộng
const int Screen_Height = 600;                //   Chiều cao
const int Frame_Screen = 100;                  //   FPS

//   Đường dẫn đến assets
std::string const Path_Image_Bullets        = "Assets/Textures/Bullets/";
std::string const Path_Image_Spaceships     = "Assets/Textures/Spaceships/";
std::string const Path_Image_GUI            = "Assets/Textures/GUI/";
std::string const Path_Image_Map            = "Assets/Textures/Map/";
std::string const Path_Image_Asteroids      = "Assets/Textures/Asteroids/";
std::string const Path_Font                 = "Assets/Fonts/";
std::string const Path_Image_Items          = "Assets/Textures/Items/";

enum Area
{
	One,
	Two,
	Three,
	Four,
	Special
};

#endif  //   _Data_Constant_H_