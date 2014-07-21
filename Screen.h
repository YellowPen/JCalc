#pragma once

#include <iostream>
#include <string>

//Used to abstract displaying contents to the screen
//Note: Path is not a literal file path but rather
//a symbolic internal path to allow the user to know
//what part of the program hes currently in

class Screen
{
public:
	void addpath(std::string pathName);
	void deletePath();
	void toDefPath();

	void printCurPath();
	void print(std::string input);
	std::string getInput();

	Screen(void);
	~Screen(void);

private:
	std::string defpath;
	std::string currentpath;
};

