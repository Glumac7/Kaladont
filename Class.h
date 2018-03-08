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
	std::string get_ai_calculation(const std::string&);
	void get_ai_output(const std::string&) const;
};

/*------USER CLASS------*/
class USER final
{
private:
	bool if_last_two_chars;

public:
	std::string get_user_input();
	USER()
		: if_last_two_chars(false)
	{}
};