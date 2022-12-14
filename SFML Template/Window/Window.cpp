#include "Window.h"

Window::Window()
{
	initWindow();

	//GIF
	gif = Gif("gif/protogen/", "frame (#)", ".png", 59, 1);
	sf::Time gifTime(sf::seconds(.05f));
	gif.setFrameTime(gifTime);

	shape.setSize(sf::Vector2f(300,300));
	//shape.setScale(0.5, 0.5);
	shape.setSize(sf::Vector2f(gif.getSize().x / 2, gif.getSize().y / 2));
	shape.setOrigin(sf::Vector2f(shape.getSize().x/2, shape.getSize().y/2));
	shape.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	//Snow
	sf::Time snowTime(sf::seconds(0.05));
	snow = Snow(snowTime, {1,1}, false);
	snow.randomizeDensity(true, 2, 5);
	snow.setSpawnArea(sf::Vector2f(window->getSize()));
	snow.setLimit(1000);
	snow.setVelocity(sf::Vector2f(0, 0.3));
	snow.setGlitter(true);

	//snow.addWind(Wind(sf::FloatRect(sf::Vector2f(50, 100), sf::Vector2f(300, 500)), sf::Vector2f(0.1, 0.2)));

	//Song
	song.openFromFile("dancin.ogg");
	song.setLoop(true);

	songPosition.setSize(sf::Vector2f(window->getSize().x, 10));
	songPosition.setFillColor(sf::Color(255, 0, 0, 100));
	songPosition.setPosition(0, window->getSize().y - songPosition.getSize().y);

	songDuration.setSize(sf::Vector2f(window->getSize().x, 10));
	songDuration.setFillColor(sf::Color(100, 100, 100, 100));
	songDuration.setPosition(0, window->getSize().y - songPosition.getSize().y);

	wind = 0;
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	song.play();

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
	window->clear(sf::Color(25,25,25));

	window->draw(shape);

	snow.render(window);

	window->draw(songDuration);

	window->draw(songPosition);

	window->display();
}

void Window::update()
{
	gif.update(shape);

	snow.update();

	snow.forceMove(sf::Vector2f(sinf(wind+=0.01)/2, 0.1));

	songPosition.setScale(song.getPlayingOffset().asSeconds() / song.getDuration().asSeconds(), 1);
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
	window = new sf::RenderWindow(sf::VideoMode(600, 400), "Dancin", sf::Style::Default);
	window->setFramerateLimit(60);
}
