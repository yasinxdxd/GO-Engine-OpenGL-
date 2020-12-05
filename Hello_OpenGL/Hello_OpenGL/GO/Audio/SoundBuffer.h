#ifndef GO_SOUNDBUFFER_H
#define GO_SOUNDBUFFER_H

#include <AL/al.h>
#include <AL/alc.h>
#include "Core/Definitions.h"

namespace go
{

	class SoundBuffer
	{
	public:
		SoundBuffer();
		SoundBuffer(GOcchar* file_path);
		~SoundBuffer();
	public:
		void loadFromFile(GOcchar* file_path);
	private:
		GOuint m_buffer;
	};
}


#endif // GO_SOUNDBUFFER_H