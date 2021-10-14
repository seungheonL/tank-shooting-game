#include "TankShootingGame.h"

bool gameOver = false;
int num_died = 0;
int weaponLevel = 1;
int count = 1;
int temp_count = 0;
int temp_num_died = 0;
float temp_dx = 0;
float t = 0.0f;

void jm::Tank::draw()
{
	beginTransformation();
	{
		translate(center);
		drawFilledBox(Colors::black, 0.25f, 0.1f); // body
		beginTransformation();

		translate(-0.1f, -0.075f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		endTransformation();

		translate(-0.02f, 0.11f);
		//drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
		drawFilledBox(Colors::black, 0.15f, 0.09);
		//translate(0.15f, 0.0f);

		translate(0.16f, 0.0f);
		//drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
		drawFilledBox(Colors::gray, 0.15f, 0.03f);
	}
	endTransformation();

	// gold face

	//beginTransformation();
	//{
	//	translate(center);
	//	{
	//		beginTransformation();
	//		translate(0.0f, 0.12f);
	//		drawFilledCircle(Colors::gold, 0.08f);
	//		translate(0.05f, 0.03f);
	//		drawFilledCircle(Colors::white, 0.01f); // while eye

	//		endTransformation();

			//// red body
			//beginTransformation();
			//scale(1.0f, 2.0f);
			//translate(0.0f, -0.1f);
			//drawFilledBox(Colors::red, 0.13f, 0.2f);
			//endTransformation();

			//// yellow arm
			//beginTransformation();
			//rotate(sin(t*5.0f) * 30.0f);					// animation!
			//scale(1.0f, 2.0f);
			//translate(0.0f, -0.1f);
			//drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			//endTransformation();

			//// green leg
			//beginTransformation();
			//translate(0.0f, -0.6f);
			//translate(0.0f, 0.2f);
			//rotate(sinf(t*5.0f + 3.141592f) * 30.0f);	// animation!
			//translate(0.0f, -0.2f);
			//drawFilledBox(Colors::green, 0.1f, 0.4f);
			//endTransformation();
		/*}
		
	}
	endTransformation();

	t += 0.01f;*/



}

void jm::Tank::shoot(std::vector<Bullet*>& bullets)
{
	if (weaponLevel == 1)
	{
		Bullet* bullet = new Bullet;

		bullet->center = center;
		bullet->center.x += 0.2f;
		bullet->center.y += 0.1f;
		bullet->velocity = vec2(8.0f, 0.0f);

		bullets.push_back(bullet);
	}

	if (weaponLevel == 2)
	{
		Bullet* myBullets[2] = { new Bullet, new Bullet };

		for (int i = 0; i < 2; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
		}

		myBullets[0]->velocity = vec2(8.0f, 0.25f);
		myBullets[1]->velocity = vec2(8.0f, -0.25f);

		for (int i = 0; i < 2; i++)
		{
			bullets.push_back(myBullets[i]);
		}
	}

	if (weaponLevel == 3)
	{
		Bullet* myBullets[3] = { new Bullet, new Bullet, new Bullet };

		for (int i = 0; i < 3; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
		}

		myBullets[0]->velocity = vec2(8.0f, 0.25f);
		myBullets[1]->velocity = vec2(8.0f, 0.0f);
		myBullets[2]->velocity = vec2(8.0f, -0.25f);

		for (int i = 0; i < 3; i++)
		{
			bullets.push_back(myBullets[i]);
		}
	}

	if (weaponLevel == 4)
	{
		Bullet* myBullets[4] = { new Bullet, new Bullet, new Bullet, new Bullet };

		for (int i = 0; i < 4; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
		}
		myBullets[0]->velocity = vec2(8.0f, 0.35f);
		myBullets[1]->velocity = vec2(8.0f, 0.15f);
		myBullets[2]->velocity = vec2(8.0f, -0.15f);
		myBullets[3]->velocity = vec2(8.0f, -0.35f);

		for (int i = 0; i < 4; i++)
		{
			bullets.push_back(myBullets[i]);
		}
	}

	if (weaponLevel == 5)
	{
		Bullet** myBullets = new Bullet*[5];

		for (int i = 0; i < 5; i++)
		{
			myBullets[i] = new Bullet;
		}

		for (int i = 0; i < 5; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
			myBullets[i]->velocity = vec2(8.0f, -0.5f + i * 0.25f);
		}

		for (int i = 0; i < 5; i++)
		{
			bullets.push_back(myBullets[i]);
		}
	}

	if (weaponLevel == 6)
	{
		Bullet** myBullets = new Bullet*[6];

		for (int i = 0; i < 6; i++)
		{
			myBullets[i] = new Bullet;
		}

		for (int i = 0; i < 6; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
			myBullets[i]->velocity = vec2(8.0f, -0.6f + i * 0.2f);
		}

		for (int i = 0; i < 6; i++)
		{
			bullets.push_back(myBullets[i]);
		}
	}

	if (weaponLevel >= 7)
	{
		Bullet** myBullets = new Bullet*[7];

		for (int i = 0; i < 7; i++)
		{
			myBullets[i] = new Bullet;
		}

		for (int i = 0; i < 6; i++)
		{
			myBullets[i]->center = center;
			myBullets[i]->center.x += 0.2f;
			myBullets[i]->center.y += 0.1f;
			myBullets[i]->velocity = vec2(8.0f, -0.7f + i * 0.23f);
		}
		myBullets[6]->center = center;
		myBullets[6]->center.x += 0.2f;
		myBullets[6]->center.y += 0.1f;
		myBullets[6]->velocity = vec2(8.0f, 0.0f);

		for (int i = 0; i < 7; i++)
		{
			bullets.push_back(myBullets[i]);
		}

	}
}

void jm::Bullet::draw()
{
	beginTransformation();
	translate(center);
	drawFilledRegularConvexPolygon(Colors::red, 0.015f, 8);
	drawWiredRegularConvexPolygon(Colors::silver, 0.015f, 8);
	endTransformation();
}

void jm::Bullet::update(const float& dt)
{
	center += velocity * dt;
}

void jm::Item::draw()
{
	beginTransformation();
	{
		translate(center);
		drawFilledStar(Colors::gold, 0.1f, 0.05f);
	}
	endTransformation();
}

bool jm::Item::isGotten(const Tank* tank)
{
	if (tank->center.x <= center.x + 0.15f && tank->center.x >= center.x - 0.15f
		&& tank->center.y <= center.y + 0.15f && tank->center.y >= center.y - 0.15f)
	{
		return true;
	}
	return false;
}

void jm::Monster::setCurve()
{
	/*if (num_died <= 50)
	{
		center.x -= 0.015f * getTimeStep() * pow(1.25, ((temp_num_died + 50) / 10));
		temp_dx = getTimeStep();
	}*/

	//center.x -= 0.015f * getTimeStep() * pow(1.25, ((num_died + 50) / 10));
	center.x -= 0.02f * getTimeStep() * pow(1.25, (num_died + 50) / 10);


	if (start_point == 0.6f)
	{
		center.y = 0.7f * std::cos(center.x * 4.0f);
	}
	else if (start_point == 0.0f)
	{
		center.y = 0.7f * std::sin(center.x * 4.0f);

	}
	else if (start_point == -0.6f)
	{
		center.y = -0.7f * std::cos(center.x * 4.0f);
	}
}

void jm::Monster::draw()
{
	//if (hp >= 5)
	//{
	//	beginTransformation();
	//	{
	//		//¸öÃ¼
	//		translate(center.x, center.y);
	//		drawFilledCircle(Colors::gray, 0.2f);

	//		//´«
	//		beginTransformation();
	//		{
	//			translate(-0.1f, 0.05f);
	//			drawFilledBox(Colors::black, 0.08f, 0.05f);
	//			translate(0.2f, 0.0f);
	//			drawFilledBox(Colors::black, 0.08f, 0.05f);
	//		}
	//		endTransformation();

	//		//ÀÔ
	//		beginTransformation();
	//		{
	//			translate(0.0f, -0.075f);
	//			drawFilledCircle(Colors::black, 0.05f);
	//		}
	//		endTransformation();

	//		//Ã¼·Â
	//		translate(0.0f, 0.25f);
	//		drawHP(hp - 1);
	//	}
	//	endTransformation();
	//}

	//else if (hp < 5)
	//{
	//	beginTransformation();
	//	{
	//		//¸öÃ¼
	//		translate(center.x, center.y);
	//		drawFilledCircle(Colors::gray, 0.2f);

	//		//´«
	//		beginTransformation();
	//		{
	//			translate(-0.1f, 0.05f);

	//			beginTransformation();
	//			{
	//				rotate(45);
	//				drawFilledBox(Colors::black, 0.1f, 0.03f);
	//				rotate(-90);
	//				drawFilledBox(Colors::black, 0.1f, 0.03f);
	//			}
	//			endTransformation();

	//			translate(0.2f, 0.0f);
	//			rotate(45);
	//			drawFilledBox(Colors::black, 0.1f, 0.03f);
	//			rotate(-90);
	//			drawFilledBox(Colors::black, 0.1f, 0.03f);
	//		}
	//		endTransformation();

	//		//ÀÔ
	//		beginTransformation();
	//		{
	//			translate(0.0f, -0.075f);
	//			drawFilledCircle(Colors::black, 0.05f);
	//		}
	//		endTransformation();

	//		//Ã¼·Â
	//		translate(0.0f, 0.25f);
	//		drawHP(hp - 1);
	//	}
	//	endTransformation();
	//}

	beginTransformation();
	{
		scale(1.05f, 1.05f);
		translate(center);
		drawFilledBox(Colors::green, 0.25f, 0.1f); // body
		beginTransformation();

		translate(-0.1f, -0.075f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		translate(0.065f, 0.0f);
		drawFilledCircle(Colors::gray, 0.02f);
		endTransformation();

		translate(0.01f, 0.11f);
		//drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
		drawFilledBox(Colors::black, 0.15f, 0.09);
		//translate(0.15f, 0.0f);

		translate(-0.155f, 0.0f);
		//drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
		drawFilledBox(Colors::gray, 0.15f, 0.03f);

		translate(0.0f, 0.25f);
		drawHP(hp - 1);
	}
	endTransformation();

}

void jm::Monster::drawHP(const int & count)
{
	translate(0.15f, -0.1f);
	if (count < 10)
	{
		beginTransformation();
		translate(-0.04f * (10 - hp) / 2, 0.0f);
		drawFilledBox(Colors::red, 0.4f - 0.04f * (10 - hp), 0.05);
		translate((0.4f - 0.04f * (10 - hp)) / 2 + 0.04f * (10 - hp) / 2, 0.0f);
		drawFilledBox(Colors::black, 0.04f * (10 - hp), 0.05);
		endTransformation();
	}
}

bool jm::Monster::isAttacted(const Bullet* bullet)
{
	if (bullet != nullptr && (bullet->center.x >= center.x - 0.3f &&
		bullet->center.x <= center.x + 0.3f) &&
		(bullet->center.y >= center.y - 0.3f && bullet->center.y <= center.y + 0.3f))
	{
		return true;
	}
	return false;
}

void jm::generateMonsters(std::vector<Monster*>& monsters, RegenTimer& monsterRegenTimer)
{
	if (weaponLevel < 3)
	{
		monsterRegenTimer.setDelayTime(1.2f);
		if (num_died % 3 == 0) monsters.push_back(new Monster(-0.6f));
		if (num_died % 3 == 1) monsters.push_back(new Monster(0.0f));
		if (num_died % 3 == 2) monsters.push_back(new Monster(0.6f));

	}
	else if (weaponLevel < 5)
	{
		monsterRegenTimer.setDelayTime(1.0f);

		if (num_died % 3 == 0) { monsters.push_back(new Monster(-0.6f)); monsters.push_back(new Monster(0.0f)); }
		if (num_died % 3 == 1) { monsters.push_back(new Monster(0.0f)); monsters.push_back(new Monster(0.6f)); }
		if (num_died % 3 == 2) { monsters.push_back(new Monster(0.6f)); monsters.push_back(new Monster(-0.6f)); }
	}
	else if (weaponLevel < 7)
	{
		//monsterRegenTimer.setDelayTime(1.0f);

		monsters.push_back(new Monster(-0.6f));
		monsters.push_back(new Monster(0.0f));
		monsters.push_back(new Monster(0.6f));
	}
	else if (weaponLevel >= 7)
	{
		monsters.push_back(new Monster(-0.6f));
		monsters.push_back(new Monster(0.0f));
		monsters.push_back(new Monster(0.6f));
	}
}

void jm::Laser::draw()
{
	beginTransformation();
	{
		translate(center);
		drawFilledCircle(Colors::blue, 0.015f);
	}
	endTransformation();
}

void jm::Laser::update(const float & dt)
{
	center += velocity * dt;
}

void jm::DeadScreen::draw()
{
	beginTransformation();
	{
		beginTransformation();
		translate(-0.625f, 0.25f);
		drawLine(Colors::black, vec2(-0.75f, 0.25f), Colors::black, vec2(-0.5f, 0.25f));
		drawLine(Colors::black, vec2(-0.75f, 0.25f), Colors::black, vec2(-0.75f, -0.25f));
		drawLine(Colors::black, vec2(-0.75f, -0.25f), Colors::black, vec2(-0.5f, -0.25f));
		drawLine(Colors::black, vec2(-0.5f, -0.25f), Colors::black, vec2(-0.5f, -0.0f));
		drawLine(Colors::black, vec2(-0.5f, -0.0f), Colors::black, vec2(-0.625f, -0.0f));

		beginTransformation();
		translate(0.05f, 0.0f);
		drawLine(Colors::black, vec2(-0.375f, 0.25f), Colors::black, vec2(-0.5f, -0.25f));
		drawLine(Colors::black, vec2(-0.375f, 0.25f), Colors::black, vec2(-0.25f, -0.25f));
		drawLine(Colors::black, vec2(-0.4375f, 0.0f), Colors::black, vec2(-0.3125f, -0.0f));
		endTransformation();

		beginTransformation();
		translate(0.1f, 0.0f);
		drawLine(Colors::black, vec2(-0.25f, 0.25f), Colors::black, vec2(-0.25f, -0.25f));
		drawLine(Colors::black, vec2(-0.25f, 0.25f), Colors::black, vec2(-0.125f, -0.0f));
		drawLine(Colors::black, vec2(-0.125f, -0.0f), Colors::black, vec2(0.0f, 0.25f));
		drawLine(Colors::black, vec2(0.0f, 0.25f), Colors::black, vec2(0.0f, -0.25f));
		endTransformation();

		beginTransformation();
		translate(0.15f, 0.0f);
		drawLine(Colors::black, vec2(0.0f, 0.25f), Colors::black, vec2(0.25f, 0.25f));
		drawLine(Colors::black, vec2(0.0f, 0.0f), Colors::black, vec2(0.25f, 0.0f));
		drawLine(Colors::black, vec2(0.0f, -0.25f), Colors::black, vec2(0.25f, -0.25f));
		drawLine(Colors::black, vec2(0.0f, 0.25f), Colors::black, vec2(0.0f, -0.25f));
		endTransformation();

		endTransformation();

		beginTransformation();
		translate(0.1f, 0.25f);
		drawLine(Colors::black, vec2(0.25f, 0.25f), Colors::black, vec2(0.5f, 0.25f));
		drawLine(Colors::black, vec2(0.5f, 0.25f), Colors::black, vec2(0.5f, -0.25f));
		drawLine(Colors::black, vec2(0.5f, -0.25f), Colors::black, vec2(0.25f, -0.25f));
		drawLine(Colors::black, vec2(0.25f, -0.25f), Colors::black, vec2(0.25f, 0.25f));

		beginTransformation();
		translate(0.05f, 0.0f);
		drawLine(Colors::black, vec2(0.5f, 0.25f), Colors::black, vec2(0.625f, -0.25f));
		drawLine(Colors::black, vec2(0.625f, -0.25f), Colors::black, vec2(0.75f, 0.25f));
		endTransformation();

		beginTransformation();
		translate(0.1f, 0.0f);
		drawLine(Colors::black, vec2(0.75f, 0.25f), Colors::black, vec2(1.0f, 0.25f));
		drawLine(Colors::black, vec2(0.75f, 0.0f), Colors::black, vec2(1.0f, 0.0f));
		drawLine(Colors::black, vec2(0.75f, -0.25f), Colors::black, vec2(1.0f, -0.25f));
		drawLine(Colors::black, vec2(0.75f, 0.25f), Colors::black, vec2(0.75f, -0.25f));
		endTransformation();

		beginTransformation();
		translate(0.15f, 0.0f);
		drawLine(Colors::black, vec2(1.0f, 0.25f), Colors::black, vec2(1.25f, 0.25f));
		drawLine(Colors::black, vec2(1.25f, 0.25f), Colors::black, vec2(1.25f, 0.0f));
		drawLine(Colors::black, vec2(1.25f, 0.0f), Colors::black, vec2(1.0f, 0.0f));
		drawLine(Colors::black, vec2(1.0f, 0.25f), Colors::black, vec2(1.0f, -0.25f));
		drawLine(Colors::black, vec2(1.0f, 0.0f), Colors::black, vec2(1.25f, -0.25f));
		endTransformation();

		endTransformation();

		beginTransformation();

		translate(0.0f, 0.25f);
		translate(0.0f, -0.75f);

		drawWiredBox(Colors::black, 1.375f, 0.4f);
		endTransformation();

		translate(0.0f, 0.25f);

		translate(-0.375f, -0.75f);

		beginTransformation();
		translate(0.05f, 0.0f);
		drawLine(Colors::black, vec2(-0.5f, 0.0f) * 0.5f, Colors::black, vec2(-0.25f, 0.0f) * 0.5f);
		drawLine(Colors::black, vec2(-0.25f, 0.0f) * 0.5f, Colors::black, vec2(-0.25f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(-0.25f, 0.25f) * 0.5f, Colors::black, vec2(-0.5f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(-0.5f, 0.25f) * 0.5f, Colors::black, vec2(-0.5f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(-0.5f, 0.0f) * 0.5f, Colors::black, vec2(-0.25f, -0.25f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.1f, 0.0f);
		drawLine(Colors::black, vec2(-0.25f, 0.25f) * 0.5f, Colors::black, vec2(0.0f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(-0.25f, 0.0f) * 0.5f, Colors::black, vec2(0.0f, 0.0f) * 0.5f);
		drawLine(Colors::black, vec2(-0.25f, -0.25f) * 0.5f, Colors::black, vec2(0.0f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(-0.25f, 0.25f) * 0.5f, Colors::black, vec2(-0.25f, -0.25f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.15f, 0.0f);
		drawLine(Colors::black, vec2(0.25f, 0.25f) * 0.5f, Colors::black, vec2(0.0f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.0f, 0.25f) * 0.5f, Colors::black, vec2(0.0f, 0.0f) * 0.5f);
		drawLine(Colors::black, vec2(0.0f, 0.0f) * 0.5f, Colors::black, vec2(0.25f, 0.0f) * 0.5f);
		drawLine(Colors::black, vec2(0.25f, 0.0f) * 0.5f, Colors::black, vec2(0.25f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.25f, -0.25f) * 0.5f, Colors::black, vec2(0.0f, -0.25f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.2f, 0.0f);
		drawLine(Colors::black, vec2(0.25f, 0.25f) * 0.5f, Colors::black, vec2(0.5f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.375f, 0.25f) * 0.5f, Colors::black, vec2(0.375f, -0.25f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.25f, 0.0f);
		drawLine(Colors::black, vec2(0.625f, 0.25f) * 0.5f, Colors::black, vec2(0.5f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.625f, 0.25f) * 0.5f, Colors::black, vec2(0.75f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.5625f, 0.0f) * 0.5f, Colors::black, vec2(0.6875f, 0.0f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.3f, 0.0f);
		drawLine(Colors::black, vec2(0.75f, 0.0f) * 0.5f, Colors::black, vec2(1.0f, 0.0f) * 0.5f);
		drawLine(Colors::black, vec2(1.0f, 0.0f) * 0.5f, Colors::black, vec2(1.0f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(1.0f, 0.25f) * 0.5f, Colors::black, vec2(0.75f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.75f, 0.25f) * 0.5f, Colors::black, vec2(0.75f, -0.25f) * 0.5f);
		drawLine(Colors::black, vec2(0.75f, 0.0f) * 0.5f, Colors::black, vec2(1.0f, -0.25f) * 0.5f);
		endTransformation();

		beginTransformation();
		translate(0.35f, 0.0f);
		drawLine(Colors::black, vec2(1.0f, 0.25f) * 0.5f, Colors::black, vec2(1.25f, 0.25f) * 0.5f);
		drawLine(Colors::black, vec2(1.125f, 0.25f) * 0.5f, Colors::black, vec2(1.125f, -0.25f) * 0.5f);
		endTransformation();
	}
	endTransformation();
}
