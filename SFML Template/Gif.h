#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class Gif
{
public:
	/// <param name="_Format">> Put a # wherever the frame count will be (Ex: frame (#))</param>
	Gif(const std::string _Folder, const std::string _Format, const std::string _FileExtension, const int _FrameCount, const int _StartFrame);
	Gif();
	~Gif();

	sf::Time getFrameTime() const;

	void setFrameTime(sf::Time time);
	void setCurrentFrame(const int _Frame);

	sf::Vector2f getSize() const;
	void update(sf::RectangleShape& shape);

	Gif& operator=(const Gif& right);

private:
	int frames;
	int currentFrame;
	int startFrame;
	std::unique_ptr<sf::Texture> texture;
	sf::Time time;
	std::string folder;
	std::string fileExtension;
	std::string format;
	sf::Clock frameClock;

	//Replaces # with the frame number
	std::string getFrame();
};

