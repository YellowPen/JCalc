#include "Screen.h"

void Screen::addpath(std::string pathName)
{
	currentpath.append(pathName);
	currentpath.append(">");
}

void Screen::deletePath()
{
	unsigned lastPathComp = currentpath.find_last_of(">");
	currentpath = currentpath.substr(0, lastPathComp);
}

void Screen::toDefPath()
{
	currentpath = defpath;
}

void Screen::printCurPath()
{
	std::cout<<"\n"<<currentpath<<">>";
}

void Screen::print(std::string input)
{
	std::cout<<input;
}

std::string Screen::getInput()
{
	std::string tempstr;
	std::getline(std::cin, tempstr);
	return tempstr;
}


Screen::Screen(void)
{
	defpath = "JcpuMain>";
	currentpath = defpath;
}


Screen::~Screen(void)
{
}
