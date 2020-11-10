#include "Window/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Sprite.h"

#include <chrono>
#include <thread>
#include <time.h>


int main()
{
	go::Window window(go::Vec2ui(320, 240), "Window!!!");
	
	
	

	float x=10, y=10;
	float sx = 2, sy = 2;

	go::Texture texture2("assets/dvd2png.png");
	go::Sprite sprite2(texture2);
	sprite2.setSize(go::Vec2f(160, 160));
	sprite2.setPosition(go::Vec2f(x, y));
	
	
	/*
	go::Renderable renderable1;
	renderable1.setSize(go::Vec2f(0.3, 0.4));
	renderable1.setPosition(go::Vec2f(0.2, 0.2));
	go::Renderable renderable2;
	renderable2.setSize(go::Vec2f(0.5, 0.5));
	renderable2.setPosition(go::Vec2f(-0.4, -0.3));
	*/

	float FPS = 60.0;
	float start, end, res=0, delay;
	
	while (!window.isClose())
	{
		start = (float)glfwGetTime() * 1000;
		/////////////////////////////////////////////////////////////////////
		window.pollEvent();
		
		if (sprite2.getPosition().x + sprite2.getSize().x > window.getWidth() || sprite2.getPosition().x < 0 )
		{
			sx *= -1;
		}
		if (sprite2.getPosition().y + sprite2.getSize().y > window.getHeight() || sprite2.getPosition().y < 0)
		{
			sy *= -1;
		}

		x+=sx;
		y+=sy;
		sprite2.setPosition(go::Vec2f(x, y));
	
		//renderable1.setPosition(go::Vec2f(-0.5, 0.0));


		window.clear();
		window.render(sprite2);
		window.display();



		/////////////////////////////////////////////////////////////////////
		end = (float)glfwGetTime() * 1000;
		res = end - start;
	
		delay = (1000.0 / FPS) - res;
		std::this_thread::sleep_for(std::chrono::milliseconds((int(delay))));
		
	}
	

	return 0;
}