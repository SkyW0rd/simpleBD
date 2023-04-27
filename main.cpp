#include "bd.h"

int main()
{
	std::ifstream in("bd.txt");
	std::string s;
	if (in) {
		while (in) {
			getline(in, s);
			std::cout << s << std::endl;
		}
	}
	else
	{
		std::cout << "file is not open" << std::endl;
	}
	in.close();
	/*std::string str = "hello";
	std::string buf;
	for (int i = 0; i < str.length(); i++)
	{
		buf += toupper(str[i]);
	}
	std::cout << buf << std::endl << str.length();*/
	return 0;
}