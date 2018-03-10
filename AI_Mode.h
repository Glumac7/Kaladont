/*------Libraries------*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#pragma once

/*------AI CLASS------*/
class AI final
{
private:
	/*------Variable Declaration------*/
	
	std::ifstream file; 
	std::vector<std::string> words_from_the_file;
	std::string last_two_chars;
	
public:
	static bool is_the_value_invalid;
	static std::string ai_last_two;

	std::string ai_calculation(const std::string&);
	void get_ai_output(const std::string&) const;
};

/*------USER CLASS------*/
class USER final
{
private:
	bool flag;

public:
	std::string get_user_input();
	USER()
		: flag(false)
	{}
};