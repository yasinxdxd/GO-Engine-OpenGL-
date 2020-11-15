#include "Window/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"
#include <chrono>
#include <thread>
#include <time.h>


int main()
{
	go::Window window(go::Vec2ui(600, 400), "Window!!!");
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

	go::Texture texture("assets/woodyFloor.jpg");
	go::Sprite sprite(texture);
	sprite.setPosition(go::Vec2f(200, 320));
	sprite.setSize(go::Vec2f(50, 50));

	go::Texture t("assets/texture_sand.png");
	go::Sprite s(t);
	s.setPosition(go::Vec2f(0, 0));
	s.setSize(go::Vec2f(200, 200));
	float x1=0, y1=0, x2=200, y2=320;




	float FPS = 60.0;
	float start, end, res, delay;
	
	while (!window.isClose())
	{
		start = (float)glfwGetTime()*1000000;
		/////////////////////////////////////////////////////////////////////
		window.pollEvent();
		s.setPosition(go::Vec2f(x1, y1));
		x1 += 2;
		y1 += 2;

		x2--;
		sprite.setPosition(go::Vec2f(x2, y2));


		window.clear();
		window.render(sprite);
		window.render(s);
		window.display();


		/////////////////////////////////////////////////////////////////////
		end = (float)glfwGetTime()*1000000;
		
		res = end - start;
		
		delay = (1000000 / FPS) - res;
		if (delay > 0)
		{
			std::this_thread::sleep_for(std::chrono::microseconds((int(delay))));
			std::cout << 1000000/res << std::endl;
		}
	
	}
	

	return 0;
}