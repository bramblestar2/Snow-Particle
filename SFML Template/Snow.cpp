#include "Snow.h"
#include <time.h>


Snow::Snow(sf::Time _Interval, const sf::Vector2f _StartVelocity, const bool _Constant_Velocity)
{
	interval	=	_Interval;
	constant	=	_Constant_Velocity;

	glitter		=	false;
	randomize	=	false;
	density		=	NULL;
	min			=	NULL;
	max			=	NULL;
	limit		=	0;

	srand(time(NULL));
}

Snow::Snow()
{
	interval	=	sf::Time();
	constant	=	false;

	glitter		=	false;
	randomize	=	false;
	density		=	NULL;
	min			=	NULL;
	max			=	NULL;
	limit		=	0;
}

Snow::~Snow()
{
}

void Snow::setVelocity(sf::Vector2f _Velocity)
{
	velocity = _Velocity;
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

void Snow::setInterval(sf::Time _Interval)
{
	interval = _Interval;
}

void Snow::setGlitter(const bool _Glitter)
{
	glitter = _Glitter;
}

void Snow::addWind(Wind _Wind)
{
	windyAreas.push_back(_Wind);
}

void Snow::forceMove(sf::Vector2f _Velocity)
{
	for (int i = 0; i < snowParticles.size(); i++)
	{
		snowParticles.at(i).move(_Velocity);
	}
}

void Snow::update()
{
	for (int i = 0; i < snowParticles.size(); i++)
	{
		snowParticles.at(i).update();

		for (int k = 0; k < windyAreas.size(); k++)
		{
			if (windyAreas.at(k).inArea(snowParticles.at(i).getPosition()))
			{
				//Calculate velocity depending on distance between
				//the center position of the particles and the center
				//positions of the wind areas

				//Closer to the center is faster speed
				//center of wind
				sf::Vector2f windCenter;
				windCenter.x = windyAreas.at(k).getArea().width / 2;

				//center of particle
				sf::Vector2f particleCenter = snowParticles.at(i).getPosition();
				
				sf::Vector2f tempVelocity;
				

				snowParticles.at(i).move(windyAreas.at(k).getVelocity());
			}
		}

		if (snowParticles.at(i).outBounds(spawnArea))
			snowParticles.erase(snowParticles.begin() + i);
	}

	if (spawnClock.getElapsedTime().asSeconds() > interval.asSeconds())
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
		snowParticles.push_back(Particle(tempDensity, constant, velocity)); //0.01, 0.1

		sf::Color color;
		float brightness = 255 * (tempDensity / max);

		snowParticles.at(it)
			.setColor(sf::Color(brightness, brightness, brightness, brightness));

		snowParticles.at(it)
			.setPosition(sf::Vector2f(fmod(rand(), spawnArea.x), 0));

		if (glitter)
		{
			snowParticles.at(it).setGlitter(true);
			snowParticles.at(it).setMinMaxGlitter(sf::Color(255,255,255), sf::Color(50,50,50));
		}

		//Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed);
	}
}
