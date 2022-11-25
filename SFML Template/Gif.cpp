#include "Gif.h"
#include <string>

Gif::Gif(const std::string _Folder, const std::string _Format, const std::string _FileExtension, const int _FrameCount, const int _StartFrame)
{
	this->folder		=	_Folder;
	this->format		=	_Format;
	this->fileExtension =	_FileExtension;
	this->frames		=	_FrameCount;
	this->startFrame	=	_StartFrame;
	this->currentFrame	=	_StartFrame;
	
	this->texture		=	new sf::Texture();

	this->texture->loadFromFile(this->folder + getFrame());
}

Gif::Gif()
{
	this->folder		=	"";
	this->format		=	"";
	this->fileExtension =	"";
	this->frames		=	NULL;
	this->startFrame	=	NULL;

	this->texture		=	nullptr;
}

Gif::~Gif()
{
	//if (texture != nullptr)
	//	delete texture;
}

void Gif::setFrameTime(sf::Time* _Time)
{
	this->time = _Time;
}

void Gif::setCurrentFrame(const int _Frame)
{
	currentFrame = _Frame;
}

sf::Vector2f Gif::getSize() const
{
	return sf::Vector2f(texture->getSize());
}

void Gif::update(sf::RectangleShape& shape)
{
	if (this->frameClock.getElapsedTime().asSeconds() > this->time->asSeconds())
	{
		this->texture->loadFromFile(this->folder + getFrame());

		currentFrame = currentFrame < frames ? currentFrame + 1 : startFrame;

		shape.setTexture(texture, true);

		this->frameClock.restart();
	}
}

std::string Gif::getFrame()
{
	std::string temp = format;
	size_t found = temp.find('#');

	if (found != std::string::npos)
	{
		temp = temp.replace(found, 1, std::to_string(currentFrame)) + fileExtension;
		return temp;
	}

	return std::string("NULL");
}
