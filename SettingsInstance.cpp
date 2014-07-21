#include "SettingsInstance.h"


SettingsInstance::SettingsInstance(Screen* curscreen)
{

	screen = curscreen;

	//Set possible values for all settings here
	Setting trigunit;
	trigunit.settingName = "Trignometric Unit";
	trigunit.settingPossibleValues.push_back("Degree");
	trigunit.settingPossibleValues.push_back("Radian");
	trigunit.settingValue = "Degree";

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

//Note:This could be sped up a lot
void SettingsInstance::set(std::string settingname)
{
	//Search for setting
	for(unsigned int i = 0; i<settinglist.size(); i++)
	{
		//Find setting
		if(settinglist[i].settingName == settingname)
		{
			screen->print(settinglist[i].settingName + ": ");
			//Loop through all possible values of setting
			std::map<int, std::string> setting_cache;
			for(int a = 0; a<settinglist[i].settingPossibleValues.size(); a++)
			{
				//Print possible values while stroing a pointer to them in above map
				screen->print("\n" + std::to_string(a + 1) + ":" + settinglist[i].settingPossibleValues[a]);
				setting_cache[a] = settinglist[i].settingPossibleValues[a];
			}
			

			bool found = false;

			//Loop through until we find the users setting
			while(found == false)
			{
				screen->print("\n Select a setting Number: ");
				int input;
				std::cin>>input;
				input--;
				if(setting_cache.find(input) == setting_cache.end())
				{
					screen->print("Does not exist, please try again");
					found = false;
				}

				for (auto it = setting_cache.begin(); it!=setting_cache.end(); ++it)
				{
					if(it->first == input)
					{
						setValNoCheck(settinglist[i].settingName, setting_cache[i]);
						found =true;
						return;
					}
				}
			}
		}
	}
	//Returns nullptr if cant be found
	screen->print("Could not find specified setting");
}

void SettingsInstance::setValNoCheck(std::string name, std::string value)
{
	//Search for setting
	for(unsigned int i = 0; i<settinglist.size(); i++)
	{
		//Find setting
		if(settinglist[i].settingName == name)
		{
			settinglist[i].settingValue = value;
		}

	}
}

SettingsInstance::~SettingsInstance(void)
{
}
