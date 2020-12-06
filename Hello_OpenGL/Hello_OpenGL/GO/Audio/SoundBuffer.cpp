#include "SoundBuffer.h"
#include "Utils/Utils.h"
#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"


namespace go
{
	SoundBuffer::SoundBuffer()
	{
		alGenBuffers(1, &m_buffer);
	}

	SoundBuffer::SoundBuffer(GOcchar* file_path)
	{
		alGenBuffers(1, &m_buffer);
		loadFromFile(file_path);
	}

	SoundBuffer::~SoundBuffer()
	{
		alDeleteBuffers(1, &m_buffer);
		delete[] m_data;
	}

	void SoundBuffer::loadFromFile(GOcchar* file_path)
	{
		m_data = go::utils::loadWAV(file_path, m_channel, m_sample_rate, m_bps, m_size);	
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
		std::cout << m_channel << std::endl;
		std::cout << m_sample_rate << std::endl;
		std::cout << m_bps << std::endl;
		std::cout << m_size << std::endl;
		alBufferData(m_buffer, m_format, m_data, m_size, m_sample_rate);
	}
}