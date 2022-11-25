#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Gif
{
public:

	/// <param name="_Format">> Put a # wherever the frame count will be (Ex: frame (#))</param>
	Gif(const std::string _Folder, const std::string _Format, const std::string _FileExtension, const int _FrameCount, const int _StartFrame);
	Gif();
	~Gif();

	void setFrameTime(sf::Time* time);
	void setCurrentFrame(const int _Frame);

	void update(sf::RectangleShape& shape);

private:
	int frames;
	int currentFrame;
	int startFrame;
	sf::Texture* texture;
	sf::Time* time;
	std::string folder;
	std::string fileExtension;
	std::string format;
	sf::Clock frameClock;

	//Replaces # with the frame number
	std::string getFrame();
};

