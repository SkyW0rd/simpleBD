#include "bd.h"

int main()
{
	bd *a = new bd("bd.txt");
	std::string s;
	std::map<std::string, int> mapping;
	mapping["SELECT"] = 0;
	mapping["KEYS"] = 1;
	mapping["SET"] = 2;
	mapping["GET"] = 3;
	mapping["DEL"] = 4;
	mapping["FLUSHALL"] = 5;
	getline(std::cin, s);
	while (s != "exit")
	{
		std::string word = "";
		std::string value = "";
		std::string setVal = "";
		if (s.find(' ') < s.length() - 1) {
			for (int i = 0; i < s.find(' '); i++)
			{
				word += toupper(s[i]);
			}
			if (word == "SET")
			{
				bool flag = false;
				for (int i = s.find(' ') + 1; i < s.length(); i++)
				{
					if (s[i] == ' ')
					{
						flag = true;
					}
					else if (flag == false)
					{
						value += s[i];
					}
					else if (flag == true)
					{
						setVal += s[i];
					}
				}
			}
			else
			{
				for (int i = s.find(' ') + 1; i < s.length(); i++)
				{
					value += s[i];
				}
			}
		}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				word += toupper(s[i]);
			}
		}
		switch (mapping[word])
		{
			case 0:
				a->_select(value);
				a->_save();
				break;
			case 1:
				a->_keys(value);
				a->_save();
				break;
			case 2:
				a->_set(value, setVal);
				a->_save();
				break;
			case 3:
				a->_get(value);
				a->_save();
				break;
			case 4:
				a->_del(value);
				a->_save();
				break;
			case 5:
				a->_flushall();
				a->_save();
				break;
		}
		getline(std::cin, s);
	}














	//std::string str = a->_get("tri");
	//a->_set("val", "33");
	//a->_keys("*val*");
	//std::cout << a->_del("val") << std::endl;
	//a->_save();
	/*std::ifstream in("bd.txt");
	std::string str;
	if (in)
	{
		while (getline(in, str))
		{
			if (str.find('[') < str.length())
			{
				int section = 0;
				for (int i = str.find('[') + 1; i < str.find(']'); i++)
				{
					section = str[i] - '0';
				}
				std::cout << section << std::endl;
			}
		}
	}
	in.close();*/
	/*std::string str = "hello";
	std::string buf;
	for (int i = 0; i < str.length(); i++)
	{
		buf += toupper(str[i]);
	}
	std::cout << buf << std::endl << str.length();*/
	return 0;
}