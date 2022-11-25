#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Particle
{
public:
	Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed);
	Particle();
	~Particle();

	void update();
	void setColor(sf::Color _Color);
	bool outBounds(const sf::Vector2f _Area);
	void setPosition(sf::Vector2f _Position);

	void render(sf::RenderWindow* window);
private:
	sf::Vector2f velocity;
	bool constant;
	float density;

	sf::RectangleShape shape;

	void move();
};

