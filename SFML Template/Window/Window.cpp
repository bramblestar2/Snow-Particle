#include "Window.h"

Window::Window()
{
	initWindow();

	//GIF
	gif = Gif("gif/protogen/", "frame (#)", ".png", 59, 1);
	sf::Time gifTime(sf::seconds(.05f));
	gif.setFrameTime(&gifTime);

	shape.setSize(sf::Vector2f(300,300));

	//Snow
	sf::Time snowTime(sf::seconds(0.01));
	snow = Snow(&snowTime, {1,1}, false);
	snow.randomizeDensity(true, 2, 5);
	snow.setSpawnArea(sf::Vector2f(window->getSize()));
	snow.setLimit(500);
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();

	window->draw(shape);

	snow.render(window);

	window->display();
}

void Window::update()
{
	gif.update(shape);

	snow.update();
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
		}
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "TITLE", sf::Style::Default);
	window->setFramerateLimit(60);
}
