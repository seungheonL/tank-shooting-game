#pragma once
#include "fmod.hpp"

namespace jm
{
	class MonsterSoundMaker
	{
	private:
		FMOD::System* system = nullptr;
		FMOD::Sound* sound = nullptr;
		FMOD::Channel* channel = nullptr;
		FMOD_RESULT result;
		unsigned int version;
		void* extradriverdata = nullptr;

	public:
		MonsterSoundMaker()
		{
			result = FMOD::System_Create(&system);
			result = system->getVersion(&version);
			result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		}
		void setHitSound()
		{
			result = system->createSound("monsterSound3.wav", FMOD_LOOP_OFF, 0, &sound);
		}
		void setDeadSound()
		{
			result = system->createSound("deadMonsterSound.wav", FMOD_LOOP_OFF, 0, &sound);
		}

		void setLaserSound()
		{
			result = system->createSound("bomb.mp3", FMOD_LOOP_OFF, 0, &sound);

		}
		void playSound()
		{
			result = system->playSound(sound, 0, false, &channel);
			result = system->update();
		}
	};
}