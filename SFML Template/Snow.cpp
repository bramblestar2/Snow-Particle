#include "Snow.h"
#include <time.h>


Snow::Snow(sf::Time* _Interval, const sf::Vector2f _StartVelocity, const bool _Constant_Velocity)
{
	interval	=	_Interval;
	constant	=	_Constant_Velocity;

	randomize	=	false;
	density		=	NULL;
	min			=	NULL;
	max			=	NULL;

	srand(time(NULL));
}

Snow::Snow()
{
	interval	=	nullptr;
	constant	=	false;

	randomize	=	false;
	density		=	NULL;
	min			=	NULL;
	max			=	NULL;
}

Snow::~Snow()
{
}

void Snow::setLimit(const int _Count)
{
	limit = _Count;
}

void Snow::setSpawnArea(sf::Vector2f _Spawn_Area)
{
	spawnArea = _Spawn_Area;
}

void Snow::setDensity(float _Density)
{
	density = _Density;
}

void Snow::randomizeDensity(const bool _Random, const float _Min, const float _Max)
{
	randomize	=	_Random;
	min			=	_Min;
	max			=	_Max;
}

void Snow::setInterval(sf::Time* _Interval)
{
	interval = _Interval;
}

void Snow::update()
{
	for (int i = 0; i < snowParticles.size(); i++)
	{
		snowParticles.at(i).update();

		if (snowParticles.at(i).outBounds(spawnArea))
			snowParticles.erase(snowParticles.begin() + i);
	}

	if (spawnClock.getElapsedTime().asSeconds() > interval->asSeconds())
	{
		spawnParticle();

		spawnClock.restart();
	}
}

void Snow::render(sf::RenderWindow* window)
{
	for (int i = 0; i < snowParticles.size(); i++)
	{
		snowParticles.at(i).render(window);
	}
}

void Snow::spawnParticle()
{
	if (snowParticles.size() < limit)
	{
		float tempDensity;

		if (randomize)
			tempDensity = fmod(rand(), max-min) + min;
		else
			tempDensity = density;

		int it = snowParticles.size();
		snowParticles.push_back(Particle(tempDensity, constant, { 0.01, 0.1 }));

		sf::Color color;
		float brightness = 255 * (tempDensity / max);

		snowParticles.at(it)
			.setColor(sf::Color(brightness, brightness, brightness, brightness));

		snowParticles.at(it)
			.setPosition(sf::Vector2f(fmod(rand(), spawnArea.x), 0));

		//Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed);
	}
}
