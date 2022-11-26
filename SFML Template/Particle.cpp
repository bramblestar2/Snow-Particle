#include "Particle.h"

Particle::Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed)
{
	density = _Density;
	constant = _Constant;
	velocity = _Start_Speed;
	glitter = false;
	
	shape.setSize(sf::Vector2f(density, density));
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
}

Particle::Particle()
{
	density = 0;
	constant = 0;
	glitter = false;
}

Particle::~Particle()
{
}

void Particle::update()
{
	move();

	if (glitter)
	{
		shape.setFillColor(randomGlitterValue());
	}
}

void Particle::setColor(sf::Color _Color)
{
	shape.setFillColor(_Color);
}

void Particle::setMinMaxGlitter(sf::Color _Min_Glitter_Color, sf::Color _Max_Glitter_Color)
{
	glitterMin = _Min_Glitter_Color;
	glitterMax = _Max_Glitter_Color;
}

void Particle::setGlitter(const bool _Glitter)
{
	glitter = _Glitter;
}

bool Particle::outBounds(const sf::Vector2f _Area)
{
	sf::Vector2f pos = shape.getPosition();

	if (pos.x < -100 || pos.y < -100 || pos.x > _Area.x + 100 || pos.y > _Area.y + 100)
		return true;

	return false;
}

void Particle::setPosition(sf::Vector2f _Position)
{
	shape.setPosition(_Position);
}

void Particle::move(sf::Vector2f _Velocity)
{
	shape.move(_Velocity.x * (density * 0.5), _Velocity.y * (density * 0.5));
}

void Particle::render(sf::RenderWindow* window)
{
	window->draw(shape);
}

sf::Color Particle::randomGlitterValue()
{
	sf::Color colorShimmer;
	colorShimmer.r = glitterMax.r > glitterMin.r ?
		fmod(rand(), glitterMax.r - glitterMin.r) + glitterMin.r : 
		fmod(rand(), glitterMin.r - glitterMax.r) + glitterMax.r;

	colorShimmer.g = colorShimmer.r;
	colorShimmer.b = colorShimmer.r;
	colorShimmer.a = colorShimmer.r;

	//colorShimmer.g = glitterMax.g > glitterMin.g ?
	//	fmod(rand(), glitterMax.g - glitterMin.g) + glitterMin.g :
	//	fmod(rand(), glitterMin.g - glitterMax.g) + glitterMax.g;
	//
	//colorShimmer.r = glitterMax.b > glitterMin.b ?
	//	fmod(rand(), glitterMax.b - glitterMin.b) + glitterMin.b :
	//	fmod(rand(), glitterMin.b - glitterMax.b) + glitterMax.b;

	return colorShimmer;
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
