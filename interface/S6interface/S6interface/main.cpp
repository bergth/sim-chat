#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include "fileObj.h"
#include "sfHandler.h"

using namespace std;
int main()
{
	sfHandler window;
	while (window.frame())
	{}
	return 0;
}