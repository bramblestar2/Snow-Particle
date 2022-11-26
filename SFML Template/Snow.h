#pragma once
#include <vector>
#include "Particle.h"
#include "Wind.h"

class Snow
{
public:
	/// <param name="_Interval">Snow particle spawn rate</param>
	Snow(sf::Time _Interval, const sf::Vector2f _Start_Velocity, const bool _Constant_Velocity);
	Snow();
	~Snow();

	void setVelocity(sf::Vector2f _Velocity);
	void setLimit(const int _Count);
	void setSpawnArea(sf::Vector2f _Spawn_Area);
	void setDensity(float _Density);
	void setInterval(sf::Time _Interval);
	void setGlitter(const bool _Glitter);
	void addWind(Wind _Wind);

	void randomizeDensity(const bool _Random, const float _Min, const float _Max);
	void forceMove(sf::Vector2f _Velocity);

	void update();

	void render(sf::RenderWindow* window);

private:
	void spawnParticle();

	sf::Vector2f velocity;
	sf::Vector2f spawnArea;
	sf::Clock spawnClock;
	sf::Time interval;
	int limit;
	bool glitter;
	bool randomize;
	bool constant;
	float density;
	float min, max;

	std::vector<Particle> snowParticles;
	std::vector<Wind> windyAreas;
};

