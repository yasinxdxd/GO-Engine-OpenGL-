#include "SoundSource.h"

namespace go
{

	SoundSource::SoundSource()
	{
		alGenSources(8, &m_source);
		alSourcef(m_source, AL_GAIN, 1.f);
		alSourcef(m_source, AL_PITCH, 2.f);
		alSource3f(m_source, AL_POSITION, 0, 0, 0);
	}

	SoundSource::SoundSource(go::SoundBuffer& soundBuffer)
	{
		alGenSources(8, &m_source);
		alSourcef(m_source, AL_GAIN, 1.f);
		alSourcef(m_source, AL_PITCH, 2.f);
		alSource3f(m_source, AL_POSITION, 0, 0, 0);
		setSoundBuffer(soundBuffer);
	}

	SoundSource::~SoundSource()
	{
		alDeleteSources(8, &m_source);
	}

	void SoundSource::setSoundBuffer(go::SoundBuffer& soundBuffer)
	{
		m_SoundBuffer = &soundBuffer;
	}

	SoundBuffer SoundSource::getSoundBuffer() const
	{
		return *m_SoundBuffer;
	}
}