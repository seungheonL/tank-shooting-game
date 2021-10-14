#pragma once

namespace jm
{
	class RegenTimer
	{
	public:
		float delayTime;
		float currentTime = 0.0f;

	public:
		RegenTimer(const float& delayTime)
		{
			this->delayTime = delayTime;
		}

		void setDelayTime(const float& delaytime)
		{
			this->delayTime = delaytime;
		}

		void update(const float& dt)
		{
			currentTime += dt;
		}

		bool isdelayed()
		{
			if (currentTime >= delayTime)
			{
				currentTime = 0.0f;
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}