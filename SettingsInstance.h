#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Screen.h"

class Screen;


struct Setting
{
	 std::string settingName;
	 std::vector<std::string> settingPossibleValues;
	 std::string settingValue;
};

//Overall SettingsInstance is quite innefficient as a whole, possiblly find ways to speed it up

class SettingsInstance
{
public:
	std::vector<Setting> settinglist;
	Setting* find(std::string settingname);
	void set(std::string settingname);
	SettingsInstance(Screen* curscreen);
	~SettingsInstance(void);

private:
	Screen* screen;
	//Warning: Doesnt check that value is included in the possible 
	//value list so check on your own
	void setValNoCheck(std::string name, std::string value);
};

