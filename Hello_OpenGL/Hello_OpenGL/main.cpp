/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MIT License
Copyright (c) 2020 Muhammed Yasinhan Yaþar

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


//#include "PerlinNoise.h"
#include "Core/Application.h"

struct Animation
{
	Animation(int row_count, int column_count)
	{
		m_row_count = row_count;
		m_column_count = column_count;
		frame_count = row_count * column_count;
	}
	~Animation() {}
	void animate(go::Sprite& sprite)
	{
		frame_size.x = sprite.getSize().x / m_column_count;
		frame_size.y = sprite.getSize().y / m_row_count;
		sprite.setTextureCoords(frame_pos / sprite.getSize(), frame_size / sprite.getSize());
		sprite.setSize(frame_size);

		if (frame.x <= m_column_count)
			frame_pos.x += frame_size.x;
		else
		{
			frame.x = 0;
			if(frame.y <= m_row_count)
				frame_pos.y += frame_size.y;
			else
				frame.y = 0;
		}
		//std::cout << frame_size.x << std::endl;
	}

	go::Vec2i frame;
	go::Vec2f frame_size;
	go::Vec2f frame_pos;
	int frame_count;
	int m_column_count;
	int m_row_count;
};



class Player
{
public:
	Player():
		pos(go::Vec2f(120, 120)), 
		size(go::Vec2f(768, 64)),
		run(1, 8)
	{
		m_texture.loadFromFile("assets/Knight/noBKG_KnightRun_strip.png");
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(pos);
		m_sprite.setSize(size);
		m_sprite.setTextureCoords(go::Vec2f(0, 0), go::Vec2f(1, 1));
		vel.x = 16;
	}
	
	~Player()
	{

	}

	void update()
	{
		m_sprite.setSize(size*4);
		run.animate(m_sprite);
		m_sprite.setPosition(pos);
		pos += vel;
		if (pos.x > 650)
			pos.x = -250;
	}

	void show(go::Window* window)
	{
		window->render(m_sprite);
	}

private:
	go::Vec2f pos;
	go::Vec2f vel;
	go::Vec2f size;
	go::Sprite m_sprite;
	go::Texture m_texture;
	Animation run;
};







int main(int, char**)
{
	go::Window* window = new go::Window(800, 600, "Horse!");
	window->setFPS(6);
	window->setColor(go::Vec3si(200, 200, 123));
	Player player;

	while (!window->isClose())
	{
		window->pollEvent();

		player.update();

		window->clear();
		player.show(window);
		window->display();
	}
	
	delete window;
}


























/*
	go::SoundBuffer* buff;
	go::SoundSource* sound;
	ALCdevice* device;
	ALCcontext* context;

	device = alcOpenDevice(NULL);
	if (!device)
	{
		std::cout << "Cannot Initiliaze the Device." << std::endl;
		return 0;
	}

	context = alcCreateContext(device, NULL);
	if (!context)
	{
		std::cout << "Cannot Initiliaze the Context." << std::endl;
		return 0;
	}
	alcMakeContextCurrent(context);

	buff = new go::SoundBuffer();
	buff->loadFromFile("sounds/canary.wav");
	sound = new go::SoundSource();
	sound->setSoundBuffer(*buff);
	sound->setLoop(true);

	//sound->play();


	go::Window window(go::Vec2ui(1920, 1080), "Window!!!");
	window.setColor(go::Vec3si(200, 50, 50));

	try
	{
		go::GUI::getInstance()->Init(window);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	int scale = 1;
	float sliderfloatX = 256;
	float sliderfloatY = 256;



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	delete buff;
	delete sound;


	alcDestroyContext(context);
	alcCloseDevice(device);

*/

















//
/*
	unsigned int channels;
	unsigned int sampleRate;
	drwav_uint64 totalPCMFrameCount;
	float* pSampleData = drwav_open_file_and_read_pcm_frames_f32("my_song.wav", &channels, &sampleRate, &totalPCMFrameCount, NULL);
	if (pSampleData == NULL) {
		// Error opening and reading WAV file.
	}
	...
	drwav_free(pSampleData);
*/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
	ALCdevice* device = alcOpenDevice(NULL);
	if (!device)
	{
		std::cout << "Cannot Initiliaze the Device." << std::endl;
		return 0;
	}

	ALCcontext* context = alcCreateContext(device, NULL);
	if (!context)
	{
		std::cout << "Cannot Initiliaze the Context." << std::endl;
		return 0;
	}

	alcMakeContextCurrent(context);

	go::SoundBuffer* buff = new go::SoundBuffer();
	buff->loadFromFile("sounds/canary.wav");
	go::SoundSource* sound = new go::SoundSource();
	sound->setSoundBuffer(*buff);

	sound->play();

	std::this_thread::sleep_for(std::chrono::milliseconds((int(1000))));

	delete buff;
	delete sound;


	alcDestroyContext(context);
	alcCloseDevice(device);


*/


/*
GOint m_channel, m_sample_rate, m_bps, m_size;
	char* m_data = loadWAV("sounds/ball.wav", m_channel, m_sample_rate, m_bps, m_size);

	ALCdevice* device = alcOpenDevice(NULL);
	if (!device)
	{
		std::cout << "Cannot Initiliaze the Device." << std::endl;
		return 0;
	}

	ALCcontext* context = alcCreateContext(device, NULL);
	if (!context)
	{
		std::cout << "Cannot Initiliaze the Context." << std::endl;
		return 0;
	}

	alcMakeContextCurrent(context);


	GOuint m_buffer, m_format;
	alGenBuffers(1, &m_buffer);
	if (m_channel == 1)
	{
		if (m_bps == 8)
			m_format = AL_FORMAT_MONO8;
		else
			m_format = AL_FORMAT_MONO16;
	}
	else
	{
		if (m_bps == 8)
			m_format = AL_FORMAT_STEREO8;
		else
			m_format = AL_FORMAT_STEREO16;
	}

	alBufferData(m_buffer, m_format, m_data, m_size, m_sample_rate);
	GOuint m_source;
	alGenSources(1, &m_source);
	alSourcei(m_source, AL_BUFFER, m_buffer);
	alSourcePlay(m_source);



	std::this_thread::sleep_for(std::chrono::milliseconds((int(5000))));

	alDeleteSources(1, &m_source);
	alDeleteBuffers(1, &m_buffer);

	alcDestroyContext(context);
	alcCloseDevice(device);
	delete[] m_data;

*/




/*
	go::Window window(go::Vec2ui(800, 600), "Window!!!");
	window.setColor(go::Vec3si(200, 50, 50));

	try
	{
		go::GUI::getInstance()->Init(window);
	}
	catch (std::exception e)
	{
		std::cout << e.what() <<std::endl;
	}

	int scale = 1;
	float sliderfloatX = 256;
	float sliderfloatY = 256;
	float angle = 0;

	GOuint FPS = 60;
	GOuint start, delta=1;
	float delay;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////4
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	go::Texture texture;
	texture.loadFromFile("assets/settings.png");
	go::Sprite sprite;
	sprite.setTexture(texture);

	sprite.setPosition(go::Vec2f(window.getWidth()/2, window.getHeight()/2));
	sprite.setSize(go::Vec2f(256, 256));
	sprite.setOrigin(go::Vec2f(sprite.getSize().x / 2, sprite.getSize().y / 2));
	go::Vec2f speed(0, 0);
	go::Vec2f acc(0, .095);


	go::Font font;
	font.loadFromFile("fonts/corbel.ttf");
	go::Text text(font);
	text.setPosition(go::Vec2f(0,200));
	text.setString("Merhaba bu bir yazidir.");
	text.setSize(go::Vec2f(16, 16));

	bool clicked = false;

	while (!window.isClose())
	{
		start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		/////////////////////////////////////////////////////////////////////
		window.pollEvent();


		angle += 0.01;
		sprite.setRotatiton(angle);
		sprite.setSize(go::Vec2f(sliderfloatX *scale, sliderfloatY*scale));
		sprite.setOrigin(go::Vec2f(sprite.getSize().x / 2, sprite.getSize().y / 2));

		sprite.setPosition(sprite.getPosition() + speed);
		speed = speed + acc;


		if (go::Mouse::isMousePressed(go::Mouse::MouseButton::Left))
		{
			clicked = true;
		}
		else
			clicked = false;

		if (clicked)
		{
			std::cout << "jump" << std::endl;
			speed.y = -2;
		}





		text.setRotatiton(angle);




		window.clear(50,50,50);
		window.render(sprite);
		//window.render(text);

		go::GUI::getInstance()->render();

		window.display();



		/////////////////////////////////////////////////////////////////////
		delay = (1000 / FPS) - delta;
		if (delay > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds((int(delay))));
			//std::cout << 1000 / delta << std::endl;
		}

		delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
	}





	return 0;
*/