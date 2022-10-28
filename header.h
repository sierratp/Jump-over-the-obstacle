#pragma once

#ifndef MAINHEADER_H
#define MAINHEADER_H



#include <stdio.h>
#include <iostream>  
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <sstream>

#include "menu.h"


#pragma warning(disable : 4996) // I get errors (" sf::Text::setColor was deprecated") without this



using std::cin;
using std::cout;
using std::endl;
using std::string;



struct Position 
{
	int x, y; // for player placement
};



#endif

