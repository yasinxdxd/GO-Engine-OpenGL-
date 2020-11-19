#include "Window/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"
#include "Input/Mouse.h"
#include <chrono>
#include <thread>



int main()
{
	go::Window window(go::Vec2ui(1280, 720), "Window!!!");
	/*
	go::texture2d tex;
	try
	{
		tex.load_from_file("assets/dvd1.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	*/

	go::Texture player_texture("assets/woodyFloor.jpg");
	go::Sprite player_sprite(player_texture);
	player_sprite.setSize(go::Vec2f(200, 200));
	player_sprite.setColor(156,50,115);
	float x1 = 600, y1 = 400;
	

	/*go::Texture texture("assets/woodyFloor.jpg");
	go::Sprite sprite(texture);
	sprite.setPosition(go::Vec2f(900, 600));
	sprite.setSize(go::Vec2f(200, 200));
	sprite.setOrigin(go::Vec2f(100, 100));*/



	GOuint FPS = 60;
	GOuint start, delta=1;
	float delay;
	
	while (!window.isClose())
	{
		start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		/////////////////////////////////////////////////////////////////////
		window.pollEvent();
		player_sprite.setPosition(go::Vec2f(x1, y1));
		x1 += 8;
		//y1 += 2;
		if (x1 > window.getWidth())
		{
			x1 = -player_sprite.getSize().x;
		}


		
		std::cout << go::Mouse::getPosition().x << " , " << go::Mouse::getPosition().y << std::endl;


		window.clear();
		window.render(player_sprite);
		//window.render(sprite);
		window.display();

		
		delay = (1000 / FPS) - delta;
		if (delay > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds((int(delay))));
			//std::cout << 1000 / delta << std::endl;
		}

		/////////////////////////////////////////////////////////////////////	
		delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
	}
	

	return 0;
}