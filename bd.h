#ifndef BD_H
#define BD_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#pragma once

class bd {
public:
	bd();
	void _select();
	void _keys();
	void _set();
	void _get();
	void _del();
	void _flushall();
	void _save();
	~bd();
private:
	std::vector<std::map<std::string, std::string>> _v;
};

#endif // !BD_H
