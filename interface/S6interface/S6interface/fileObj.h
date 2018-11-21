#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <vector>

class fileObj
{
public:
	fileObj();
	~fileObj();
	void charAdd(std::string car); //add character 'car' to the current cursor position
 	void charDel(); //deletes character at current cursor position
	void returnCarriage(); //adds a newline to the document


	void arrowUp(); //moves cursor up
	void arrowDown(); //moves cursor down
	void arrowLeft(); //moves cursor left
	void arrowRight(); //moves cursor right
	void endKey(); //moves cursor to the end of the line
	void homeKey(); //moves cursor to the beginning of the file


	std::string giveLine(int line); //gives content of the specified line of the text

	//must be moved to priv
	int col;
	int line;

	//getters
	int lineNumber(); //gets number of line

private:
	std::vector<std::string> text;
	
	
	
};

