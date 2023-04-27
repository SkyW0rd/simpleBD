#ifndef BD_H
#define BD_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#pragma once

class bd {
public:
	bd(std::string path);
	void _select(std::string section);
	void _keys(std::string key);
	void _set(std::string key, std::string value);
	std::string _get(std::string key);
	bool _del(std::string key);
	void _flushall();
	void _save();
	~bd();
private:
	std::map<std::string, std::map<std::string, std::string>> _data;
	std::string _path;
	std::string _page;
};

#endif // !BD_H
