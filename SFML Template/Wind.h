#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Wind
{
public:
	Wind(sf::FloatRect _Area, sf::Vector2f _Velocity);
	Wind();
	~Wind();

	void setArea(sf::FloatRect _Area);
	void setVelocity(sf::Vector2f _Velocity);

	sf::FloatRect getArea() const;
	sf::Vector2f getVelocity() const;

	bool inArea(sf::Vector2f _Point);

private:
	sf::Vector2f velocity;
	sf::FloatRect area;
};

