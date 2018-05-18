#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include "DataConstant.h"
#include "Game.h"

using namespace std;
using namespace sf;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main()
{
	RenderWindow window(VideoMode(Screen_Width, Screen_Height), "Space Battle 2D", Style::Close);
	window.setFramerateLimit(Frame_Screen);

	srand(time(NULL));


	//   Change Icon for window
	Image Icon;
	Icon.loadFromFile(Path_Image_GUI + "Icon.png");
	window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

	Game game(&window);

	//   Game Loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		bool check = game.update();
		game.draw();
		if (!check)
			break;
		window.display();
	}

	//   Tạm thời
	/*
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}*/

	return EXIT_SUCCESS;
}