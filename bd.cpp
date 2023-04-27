#include "bd.h"
bd::bd(std::string path)
{
	_path = path;
	_page = "0";
	std::ifstream in(_path);
	std::string str;
	std::string section;
	if (in)
	{
		while (getline(in, str))
		{
			if (str.find('[') < str.length())
			{
				section = "";
				for (int i = str.find('[') + 1; i < str.find(']'); i++)
				{
					section += str[i];
				}
				_data[section];
			}
			else if (str.find('=') < str.length() && str.find('=') != str.length() - 1)
			{
				std::string key = "";
				for (int i = 0; i < str.find('=') - 1; i++)
				{
					key += str[i];
				}
				std::string value = "";
				for (int i = str.find('=') + 2; i < str.length(); i++)
				{
					value += str[i];
				}
				_data[section][key] = value;
			}
		}
	}
	in.close();
}
void bd::_select(std::string section)
{
	_page = section;
}
void bd::_keys(std::string key)
{
	if (key == "*")
	{
		for (auto val : _data[_page])
		{
			std::cout << val.first << " = " << val.second << std::endl;
		}
	}
	else if (key.find(':') < key.length() - 1)
	{
		bool flag = false;
		std::string word = "";
		for (int i = 0; i < key.find(':'); i++)
		{
			word += key[i];
		}
		for (auto keys : _data[_page])
		{
			if (!keys.first.find(word))
			{
				std::cout << keys.first << " = " << keys.second << std::endl;
				flag = true;
			}
		}
		if (flag == false)
		{
			std::cout << "no value in table" << std::endl;
		}
	}
	else if (key.find('*') < key.length() - 1)
	{
		bool flag = false;
		std::string word = "";
		for (int i = key.find('*') + 1; i < key.length() - 1; i++)
		{
			word += key[i];
		}
		for (auto keys : _data[_page])
		{
			size_t pos = keys.first.find(word);
			if (pos != std::string::npos)
			{
				std::cout << keys.first << " = " << keys.second << std::endl;
				flag = true;
			}
			if (flag == false)
			{
				std::cout << "no value in table" << std::endl;
			}
		}
	}
}
void bd::_set(std::string key, std::string value)
{
	_data[_page][key] = value;
}
std::string bd::_get(std::string key)
{
	for (auto val : _data[_page])
	{
		if (val.first == key)
		{
			return val.second;
		}
	}
	return "null";
}
bool bd::_del(std::string key)
{
	for (auto keys : _data[_page])
	{
		if (keys.first == key)
		{
			_data[_page].erase(key);
			return 1;
		}
	}
	return 0;
	//if (_data[_page].find(key) != _data[_page].end())
	//{
	//	_data[_page].erase(key);
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}
}
void bd::_flushall()
{
	_data.clear();
	_save();
}
void bd::_save()
{
	std::ofstream out(_path, std::ios::out | std::ios::trunc);
	out.seekp(0);
	for (auto sections : _data)
	{
		out << '[' << sections.first << ']' << std::endl;
		for (auto val : sections.second)
		{
			out << val.first << " = " << val.second << std::endl;
		}
	}
	out.close();
}
bd::~bd()
{
	_save();
	_data.clear();
}