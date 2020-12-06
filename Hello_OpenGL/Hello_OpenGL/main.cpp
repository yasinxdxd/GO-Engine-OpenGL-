/*----------------------------------*//*
#include "Core/Definitions.h"
#include "Window/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"

#include "GUI/GUI.h"

#include <chrono>
#include <thread>
#include <exception>
*/

/*----------------------------------*/
#include "Core/Application.h"
//#include "Utils/Utils.h"
/*----------------------------------*/

struct MyApp : public go::Application
{

	go::Texture* texture;
	go::Sprite* sprite;
	go::SoundBuffer* buff;
	go::SoundSource* sound;
	go::Vec2f speed;
	go::Vec2f acc;
	float angle;

	ALCdevice* device;
	ALCcontext* context;

	void Start() override
	{
		device = alcOpenDevice(NULL);
		if (!device)
		{
			std::cout << "Cannot Initiliaze the Device." << std::endl;
			return;
		}

		context = alcCreateContext(device, NULL);
		if (!context)
		{
			std::cout << "Cannot Initiliaze the Context." << std::endl;
			return;
		}
		alcMakeContextCurrent(context);

		buff = new go::SoundBuffer();
		buff->loadFromFile("sounds/canary.wav");
		sound = new go::SoundSource();
		sound->setSoundBuffer(*buff);
		
		sound->play();

		//std::this_thread::sleep_for(std::chrono::milliseconds((int(1000))));

		window = new go::Window(go::Vec2ui(800,600),"MyApp");
		texture = new go::Texture();
		sprite = new go::Sprite();

		window->setColor(go::Vec3si(16,121,121));
		window->setFPS(60);

		texture->loadFromFile("assets/settings.png");
		
		sprite->setTexture(*texture);
		sprite->setPosition(go::Vec2f(window->getWidth() / 2, window->getHeight() / 2));
		sprite->setSize(go::Vec2f(256, 256));
		sprite->setOrigin(go::Vec2f(sprite->getSize().x / 2, sprite->getSize().y / 2));
		
		speed = go::Vec2f(0, 0);
		acc = go::Vec2f(0, .095);
		angle = 0;

	}

	void Update() override
	{
		angle += 0.01;
		sprite->setRotatiton(angle);
		sprite->setSize(go::Vec2f(256, 256));
		sprite->setOrigin(go::Vec2f(sprite->getSize().x / 2, sprite->getSize().y / 2));

		sprite->setPosition(sprite->getPosition() + speed);
		if (sprite->getPosition().y + sprite->getSize().y / 2 < window->getHeight())
		{
			speed = speed + acc;
			
		}
		else
		{
			speed = speed * -0.89454678;
			//sound->stop();
		}

		if (go::Mouse::isMousePressed(go::Mouse::MouseButton::Left))
		{
			std::cout << "jump" << std::endl;
			speed.y = -4;
		}
		
	}

	void Draw() override
	{
		window->render(*sprite);
	}

	void Destroy() override
	{
		delete window;
		delete texture;
		delete sprite;
		delete buff;
		delete sound;


		alcDestroyContext(context);
		alcCloseDevice(device);
	}
};


int main(int, char**)
{
	MyApp app;
	app.GO();
	
	

	//TO DO: data is going to be member of SoundBuffer. 

	return 0;
}


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