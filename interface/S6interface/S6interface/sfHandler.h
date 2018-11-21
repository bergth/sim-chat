#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include "fileObj.h"

class sfHandler
{
public:
	sfHandler();
	~sfHandler();

	bool frame();

private:
	bool textInBuff;

	fileObj ioObject;

	sf::Text text;
	sf::Font font;
	sf::Event event;

	sf::RenderWindow window;

	std::stringstream kbInput;
	std::string printBuff;
};

