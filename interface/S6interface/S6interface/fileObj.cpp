#include "fileObj.h"


using namespace std;

//public methods

fileObj::fileObj()
{
	col = 0;
	line = 0;
	string initString;
	text.push_back(initString);
}


fileObj::~fileObj()
{
}

void fileObj::charAdd(string car)
{

	if(text[line].size() > col)
	{
		text[line].insert(col, car);
	}
	else
	{
		text[line] += car;
	}

	col++;
}

void fileObj::charDel()
{
	if (col > 0)
	{
		col--;
		text[line].erase(text[line].begin()+ col);
	}
	else if (line > 0)
	{
		col = (text[line-1].size());
		text[line - 1] += text[line];
		text.erase(text.begin() + line);
		line--;
	}	
}


void fileObj::arrowUp()
{
	if (line > 0)
	{
		line--;
	}

	if (col > text[line].size())
	{
		col = text[line].size();
	}

}

void fileObj::arrowDown()
{
	if (line < text.size() - 1)
	{
		line++;
	}
	if (col > text[line].size())
	{
		col = text[line].size();
	}
}

void fileObj::arrowLeft()
{
	if (col > 0)
	{
		col--;
	}
	else if (line > 0)
	{
		line--;

		col = (text[line].size());
	}
}

void fileObj::arrowRight()
{
	if (col < (text[line].size()))
	{
		col++;
	}
	else if (line < text.size() - 1)
	{
		line++;
		col = 0;
	}
}

void fileObj::returnCarriage()
{
	string newString;
	
	if (col == text[line].size())
	{
		text.insert(text.begin() + line + 1, newString);
		line++;
		col = 0;
	}
	else
	{
		newString += text[line].substr(col);
		text[line].erase(text[line].begin() + col, text[line].end());
		text.insert(text.begin() + line + 1, newString);
		line++;
		col = 0;
	}
	
}

string fileObj::giveLine(int askedLine)
{
	string displayString;
	displayString += text[askedLine];
	if (line == askedLine)
	{
		if (displayString.size() > col)
		{
			displayString.insert(col, "|");
		}
		else
		{
			displayString += "|";
		}
	}

	return displayString;
}

int fileObj::lineNumber()
{
	return text.size();
}

void fileObj::endKey()
{
	col = text[line].size();
}

void fileObj::homeKey()
{
	col = 0;
	line = 0;
}