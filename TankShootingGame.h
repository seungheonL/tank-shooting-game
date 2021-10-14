#pragma once

#include "Game2D.h"
#include "GunSoundMaker.h"
#include "MonsterSoundMaker.h"
#include "ItemSoundMaker.h"
#include "RegenTimer.h"
#include "BackgroundSoundMaker.h"
#include <cmath>	

extern bool gameOver;
extern int num_died;
extern int weaponLevel;
extern int count;
extern int temp_count;
extern int temp_num_died;
extern float temp_dx;

namespace jm
{
	class DeadScreen
	{
	public:
		void draw();
	};

	class Bullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		void draw();
		void update(const float& dt);
	};

	class Tank
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);

		void draw();
		void shoot(std::vector<Bullet*>& bullets);
	};

	class Item
	{
	public:
		int level = 0;
		vec2 center = vec2(2.0f, 0.0f);
		bool isExisting = true;

		void draw();
		bool isGotten(const Tank* tank);
	};

	class Laser
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);
		vec2 center_bomb = vec2(0.0f, 0.0f);

		Laser() {};

		Laser(const vec2& v)
		{
			center = v;
			center_bomb = v;
		}

		void draw();
		void update(const float& dt);

		void drawBomb()
		{
			beginTransformation();
			translate(center_bomb);
			drawFilledCircle(Colors::red, 0.05f);
			endTransformation();
		}
	};

	class Bomb
	{
	public:
		vec2 center;

		void draw()
		{
			translate(center);
			drawFilledCircle(Colors::red, 0.02f);
		}
	};

	class Monster : public Game2D, public Laser
	{
	public:
		vec2 center;
		int hp = 10;
		bool isAlive = true;
		float start_point;

		RegenTimer laserRegenTimer = RegenTimer(3.0f);

		Monster() {}
		Monster(const float& y)
		{
			center.x = 2.5f;
			center.y = y;
			start_point = y;
		}

		void setCurve();
		void draw();
		void drawHP(const int& count);
		bool isAttacted(const Bullet* bullet);
	};

	void generateMonsters(std::vector<Monster*>& monsters, RegenTimer& monsterRegenTimer);

	class TankShootingGame : public Game2D
	{
	public:
		Tank tank;
		std::vector<Bullet*> bullets;
		std::vector<Monster*> monsters = { new Monster(-0.6f), new Monster(0.0f), new Monster(0.6f) };
		std::vector<Laser*> lasers;
		std::vector<Item*> items = { new Item };

		std::vector<Bomb*> bombs;

		RegenTimer monsterRegenTimer = RegenTimer(1.5f);
		RegenTimer bulletRegenTimer = RegenTimer(0.1f);
		//RegenTimer laserRegenTimer = RegenTimer(1.0f);
		RegenTimer laserRegenTimer = RegenTimer(1.0f);

		GunSoundMaker gunSoundMaker;
		MonsterSoundMaker hitMonsterSoundMaker;
		MonsterSoundMaker deadMonsterSoundmaker;
		MonsterSoundMaker attackSoundMaker;

		ItemSoundMaker itemSoundmaker;
		BackgroundSoundMaker backgroundSoundMaker;

		DeadScreen deadscreen;

		TankShootingGame()
			: Game2D("Tank Shooting Game", 1800, 768, false, 2)
		{
			gunSoundMaker.setSound();
			hitMonsterSoundMaker.setHitSound();
			deadMonsterSoundmaker.setDeadSound();
			attackSoundMaker.setLaserSound();

			itemSoundmaker.setSound();
			backgroundSoundMaker.setSound();

			backgroundSoundMaker.playSound();
		}

		~TankShootingGame()
		{
			for (auto& bullet : bullets)
			{
				if (bullet != nullptr) delete bullet;
			}

			for (auto& monster : monsters)
			{
				if (monster != nullptr) delete monster;
			}

			for (auto& item : items)
			{
				if (item != nullptr) delete item;
			}
		}

		void update() override
		{
			const vec2 mouse_pos = getCursorPos();

			if (!gameOver)
			{
				monsterRegenTimer.update(getTimeStep());
				bulletRegenTimer.update(getTimeStep());
				laserRegenTimer.update(getTimeStep());

				for (auto& laser : lasers)
				{
					if (laser != nullptr) 
						laser->update(getTimeStep());
				}

				for (auto& laser : lasers)
				{
					if (laser != nullptr)
					{
						laser->draw();
						//laser->drawBomb();
					}
				}

				for (auto& laser : lasers)
				{
					if (tank.center.x <= laser->center.x + 0.15f && tank.center.x >= laser->center.x - 0.15f
						&& tank.center.y <= laser->center.y + 0.15f && tank.center.y >= laser->center.y - 0.15f)
					{
						gameOver = true;
					}
				}

				for (auto& monster : monsters)
				{
					monster->laserRegenTimer.update(getTimeStep());
				}

				for (int i = 0; i < lasers.size(); i++)
				{
					if (lasers[i]->center.x < -2.25f || lasers[i]->center.y > 1.0f)
					{
						if (lasers[i] != nullptr)
						{
							delete lasers[i];
							lasers.erase(lasers.begin() + i);
							break;
						}
					}
				}

				if (laserRegenTimer.isdelayed())
				{
					attackSoundMaker.playSound();
					for (auto& monster : monsters)
					{
						Laser* laser = new Laser;
						laser->center = monster->center + vec2(-0.2, 0.1f);
						vec2 direc_vec = (tank.center - monster->center);
						laser->velocity = direc_vec / sqrt(direc_vec.x * direc_vec.x + direc_vec.y * direc_vec.y) * 2.5f * (weaponLevel  + 4) * 0.3;
						
						laser->center_bomb = monster->center + vec2(-0.2f, 0.1f);
						lasers.push_back(laser);

						/*Bomb* bomb = new Bomb;
						bomb->center = monster->center + vec2(-0.2f, 0.1f);
						bombs.push_back(bomb);*/
					}
				}

				/*for (auto& bomb : bombs)
				{
					if(bomb != nullptr)
						bomb->draw();
				}*/

				if (monsterRegenTimer.isdelayed())
				{
					generateMonsters(monsters, monsterRegenTimer);
				}

				if (isKeyPressed(GLFW_KEY_LEFT))
					if (tank.center.x > -2.25f)		tank.center.x -= 1.5f * getTimeStep();

				if (isKeyPressed(GLFW_KEY_RIGHT))
					if (tank.center.x < 2.25f)		tank.center.x += 1.5f * getTimeStep();

				if (isKeyPressed(GLFW_KEY_UP))
					if (tank.center.y < 1.0f)		tank.center.y += 1.5f * getTimeStep();

				if (isKeyPressed(GLFW_KEY_DOWN))
					if (tank.center.y > -1.0f)		tank.center.y -= 1.5f * getTimeStep();

				if (isKeyPressed(GLFW_KEY_SPACE))
				{
					if (bulletRegenTimer.isdelayed())
					{
						gunSoundMaker.playSound();
						tank.shoot(bullets);
					}
				}

				for (int i = 0; i < items.size(); i++)
				{
					if (items[i]->isGotten(&tank))
					{
						itemSoundmaker.playSound();
						weaponLevel++;
						delete items[i];
						items.erase(items.begin() + i);
						break;
					}
				}

				for (int i = 0; i < monsters.size(); i++)
				{
					for (int j = 0; j < bullets.size(); j++)
					{
						if (monsters[i]->isAttacted(bullets[j]))
						{
							hitMonsterSoundMaker.playSound();

							delete bullets[j];
							bullets[j] = nullptr;
							monsters[i]->hp--;

							if (monsters[i]->hp <= 0)
							{
								deadMonsterSoundmaker.playSound();
								temp_count++;

								if (monsters[i] != nullptr)
								{
									if (temp_count % (10 * count) == 0)
									{
										count++;
										temp_count = 0;

										items.push_back(new Item);
									}

									monsters[i]->isAlive = false;
									delete monsters[i];
									monsters.erase(monsters.begin() + i);
									num_died++;

									if (num_died <= 50)
									{
										temp_num_died++;
									}

									break;
								}
							}
						}
					}
				}

				for (auto& bullet : bullets)
				{
					if (bullet != nullptr)
					{
						bullet->update(getTimeStep());
					}
				}

				// rendering

				tank.draw();

				for (auto& monster : monsters)
				{
					if (monster->isAlive && monster != nullptr)
					{
						monster->setCurve();
						monster->draw();
					}
				}

				for (auto& bullet : bullets)
				{
					if (bullet != nullptr)
					{
						bullet->draw();
					}
				}

				for (auto& item : items)
				{
					if (item->isExisting && item != nullptr)
					{
						item->center.x -= 0.5f * getTimeStep();
						item->center.y = 0.7f * std::sin(item->center.x * 4.0f);
						item->draw();
					}
				}

				for (auto& monster : monsters)
				{
					if (monster->center.x <= -2.0f)
					{
						gameOver = true;
					}
				}

			}
			
			else if (gameOver)
			{
				deadscreen.draw();
				drawPoint(Colors::black, mouse_pos, 10.0f);

				if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
				{
					if (mouse_pos.x <= 1.375f * 0.5f && mouse_pos.x >= -1.375f * 0.5f && mouse_pos.y <= -0.55f + 0.25f
						&& mouse_pos.y >= -0.95f + 0.25f)
					{
						gameOver = false;
						num_died = 0;
						weaponLevel = 1;
						count = 1;
						temp_count = 0;
						temp_num_died = 0;
						temp_dx = 0;

						tank.center = vec2(0.0f, 0.0f);
						bullets.clear();
						monsters.clear(); monsters = { new Monster(-0.6f), new Monster(0.0f), new Monster(0.6f) };
						lasers.clear();
						items.clear(); items = { new Item };
					}
				}
			}
		}
	};
}