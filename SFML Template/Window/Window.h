#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Gif.h"
#include "../Snow.h"

class Window
{
public:
	Window();
	//Free memory
	virtual ~Window();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void initWindow();
	
	sf::Clock dtClock;
	double dt;

	sf::RenderWindow* window;
	sf::Event event;

	sf::Music song;

	sf::RectangleShape shape;
	Gif gif;
	Snow snow;

	float wind;
};

