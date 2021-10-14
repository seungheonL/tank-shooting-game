#pragma once
#include "fmod.hpp"

namespace jm
{
	class BackgroundSoundMaker
	{
	private:
		FMOD::System* system = nullptr;
		FMOD::Sound* sound = nullptr;
		FMOD::Channel* channel = nullptr;
		FMOD_RESULT result;
		unsigned int version;
		void* extradriverdata = nullptr;

	public:
		BackgroundSoundMaker()
		{
			result = FMOD::System_Create(&system);
			result = system->getVersion(&version);
			result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		}
		void setSound()
		{
			result = system->createSound("backgroundMusic.mp3", FMOD_LOOP_NORMAL, 0, &sound);
		}
		void playSound()
		{
			result = system->playSound(sound, 0, false, &channel);
			result = system->update();
		}
	};
}