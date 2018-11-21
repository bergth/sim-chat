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
	void charAdd(std::string car);
	void charDel();
	void arrowUp();
	void arrowDown();
	void arrowLeft();
	void arrowRight();
	void returnCarriage();
	std::string giveLine(int line);

	//must be moved to priv
	int col;
	int line;

	//getters
	int lineNumber();

private:
	std::vector<std::string> text;
	
	
	
};

