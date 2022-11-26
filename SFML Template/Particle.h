#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Particle
{
public:
	Particle(const float _Density, const bool _Constant, const sf::Vector2f _Start_Speed);
	Particle();
	~Particle();

	void setPosition(sf::Vector2f _Position);
	sf::Vector2f getPosition() const { return shape.getPosition(); }

	void update();
	void setColor(sf::Color _Color);
	void setMinMaxGlitter(sf::Color _Min_Shimmer_Color, sf::Color _Max_Shimmer_Color);
	void setGlitter(const bool _Glitter);
	bool outBounds(const sf::Vector2f _Area);
	void move(sf::Vector2f _Velocity);

	void render(sf::RenderWindow* window);
private:
	sf::Vector2f velocity;
	bool constant;
	bool glitter;
	float density;
	sf::Color glitterMin, glitterMax;

	sf::RectangleShape shape;

	sf::Color randomGlitterValue();
	void move();
};

