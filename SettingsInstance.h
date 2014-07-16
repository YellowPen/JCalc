#pragma once

#include <string>
#include <vector>

struct Setting
{
	 std::string settingName;
	 std::string value;
};

class SettingsInstance
{
public:
	std::vector<Setting> settinglist;
	Setting* find(std::string settingname);
	SettingsInstance(void);
	~SettingsInstance(void);
};

