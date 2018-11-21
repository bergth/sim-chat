#include "sfHandler.h"

using namespace std;

sfHandler::sfHandler()
{
	window.create(sf::VideoMode(600, 600), "A basic text editor", sf::Style::Default);

	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "FATAL : unable to load font" << endl;
	}
	text.setFont(font);
	text.setCharacterSize(12);

	text.setFillColor(sf::Color::White);

	window.clear();
	window.display();
}

sfHandler::~sfHandler()
{
}

bool sfHandler::frame()
{
	if (window.isOpen())
	{
		



		while (window.pollEvent(event))
		{
			//move arround file with arrows
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				ioObject.arrowLeft();
				textInBuff = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				ioObject.arrowRight();
				textInBuff = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				ioObject.arrowUp();
				textInBuff = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				ioObject.arrowDown();
				textInBuff = true;
			}

			cout << "cursor in" << ioObject.col << ":" << ioObject.line << endl;

			//get text from user
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 256)
				{
					if (event.text.unicode == 13)
					{
						ioObject.returnCarriage();
					}
					else if (event.text.unicode == 8)
					{
						cout << "calling delete" << endl;
						ioObject.charDel();
					}
					else
					{
						kbInput << static_cast<char>(event.text.unicode);
						ioObject.charAdd(kbInput.str());
						kbInput.str("");

					}

					//log
					cout << "kb: " << kbInput.str() << endl;

					textInBuff = true;

				}
			}

			//updating window rendered text
			else if (textInBuff)
			{
				textInBuff = false;
				cout << "rendering Text" << endl;
				for (int i = 0; i < ioObject.lineNumber(); i++)
				{
					printBuff += ioObject.giveLine(i);
					printBuff += "\n";
				}

				text.setString(printBuff);
				printBuff.clear();
				window.clear();
				window.draw(text);
				window.display();
			}

			//closing window
			else if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}








