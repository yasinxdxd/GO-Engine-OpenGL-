#include "SoundSource.h"
#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

namespace go
{

	SoundSource::SoundSource()
	{
		m_SoundBuffer = nullptr;
		alGenSources(1, &m_source);
		alSourcef(m_source, AL_GAIN, 1.f);
		alSourcef(m_source, AL_PITCH, 1.f);
		alSource3f(m_source, AL_POSITION, 0, 0, 0);
	}

	SoundSource::SoundSource(go::SoundBuffer& soundBuffer)
	{
		m_SoundBuffer = nullptr;
		alGenSources(1, &m_source);
		alSourcef(m_source, AL_GAIN, 1.f);
		alSourcef(m_source, AL_PITCH, 1.f);
		alSource3f(m_source, AL_POSITION, 0, 0, 0);
		setSoundBuffer(soundBuffer);
	}

	SoundSource::~SoundSource()
	{
		alDeleteSources(1, &m_source);
		//delete m_SoundBuffer;
	}

	void SoundSource::setSoundBuffer(go::SoundBuffer& soundBuffer)
	{
		m_SoundBuffer = &soundBuffer;
		alSourcei(m_source, AL_BUFFER, m_SoundBuffer->m_buffer);
	}

	void SoundSource::play()
	{
		alSourcePlay(m_source);
	}

	void SoundSource::stop()
	{
		alSourceStop(m_source);
	}

	SoundBuffer SoundSource::getSoundBuffer() const
	{
		return *m_SoundBuffer;
	}
}