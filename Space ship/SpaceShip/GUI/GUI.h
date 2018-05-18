#ifndef _GUI_H_
#define _GUI_H_

#include <vector>
#include <SFML\Graphics.hpp>
#include "Data.h"

using namespace sf;
using namespace std;

//  GUI là tập hợp những class sử dụng tạo giao diện và hiệu ứng động
namespace GUI
{
	class Animation
	{
	private:
		RenderWindow * window;
		Sprite sprite;

		//   Dùng để xác định chiều khi tạo Animation
		Direction direction;

		//   Số chỉ một khung hình
		float Frame;

		//   Tốc độ của khung hình
		float speed;

		//   Toàn bộ khung hình
		vector <IntRect> Frames;

	public:
		//   x và y là tọa của điểm bắt đầu load
		//   Column và Line là kích thước của một khung hình
		//   Count là số khung hình
		//   speed là tốc độ khung hình
		//   direction là chiều của khung hình (từ trái qua phải hoặc từ trên xuống dưới)
		Animation(RenderWindow * window, Texture &texture, float x, float y, float Column, float Line, float column, float line, int Count, float speed, Direction direction, float ratio);

		Animation() {}

		//   Dùng để cập nhật hình ảnh
		void update();

		//   Dùng để vẽ ảnh lên màn hình
		void draw();

		//   Như Một Constructor
		void setData(RenderWindow * window, Texture &texture, float x, float y, float Column, float Line, float column, float line, int Count, float speed, Direction direction, float ratio);
		bool isEnd();
		void setPosition(Vector2f position);

	};
}

#endif       //   _GUI_H_