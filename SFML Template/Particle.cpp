#include "Particle.h"

Particle::Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed)
{
	density = _Density;
	constant = _Constant;
	velocity = _Start_Speed;
	
	shape.setSize(sf::Vector2f(density, density));
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
}

Particle::Particle()
{
	density = 0;
	constant = 0;
}

Particle::~Particle()
{
}

void Particle::update()
{
	move();
}

void Particle::setColor(sf::Color _Color)
{
	shape.setFillColor(_Color);
}

bool Particle::outBounds(const sf::Vector2f _Area)
{
	sf::Vector2f pos = shape.getPosition();

	if (pos.x < 0 || pos.y < 0 || pos.x > _Area.x || pos.y > _Area.y)
		return true;

	return false;
}

void Particle::setPosition(sf::Vector2f _Position)
{
	shape.setPosition(_Position);
}

void Particle::render(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Particle::move()
{
	if (!constant)
	{
		//if (velocity.x < 50)
		//	velocity.x += velocity.x * 0.01;
		if (velocity.y < 50)
			velocity.y += velocity.y * 0.005;
	}

	shape.move(velocity.x * (density * 0.5), velocity.y * (density * 0.5));
}
