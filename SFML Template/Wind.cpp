#include "Wind.h"

Wind::Wind(sf::FloatRect _Area, sf::Vector2f _Velocity)
{
	setArea(_Area);
	setVelocity(_Velocity);
}

Wind::Wind()
{
}

Wind::~Wind()
{
}

void Wind::setArea(sf::FloatRect _Area)
{
	area = _Area;
}

void Wind::setVelocity(sf::Vector2f _Velocity)
{
	velocity = _Velocity;
}

sf::FloatRect Wind::getArea() const
{
	return area;
}

sf::Vector2f Wind::getVelocity() const
{
	return velocity;
}

bool Wind::inArea(sf::Vector2f _Point)
{
	return area.contains(_Point);
}
