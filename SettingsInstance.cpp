#include "SettingsInstance.h"


SettingsInstance::SettingsInstance(void)
{
	Setting trigunit;
	trigunit.settingName = "Trignometric Unit";
	trigunit.value = "Degree";

	settinglist.push_back(trigunit);

}

Setting* SettingsInstance::find(std::string settingname)
{
	//Search for Function 
	for(unsigned int i = 0; i<settinglist.size(); i++)
	{
		if(settinglist[i].settingName == settingname)
		{
			return &settinglist[i];
		}
	}
	//Returns nullptr if cant be found
	return nullptr;
}

SettingsInstance::~SettingsInstance(void)
{
}
