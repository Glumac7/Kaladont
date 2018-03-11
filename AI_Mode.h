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
	
	std::ifstream tekst_fajl; 
	std::vector<std::string> vector_reci_iz_fajla;
	std::string poslednja_dva_karaktera;
	
public:
	static bool da_li_je_vrednost_validna;
	static std::string ai_poslednja_dva_karaktera;

	std::string ai_kalkulacija(const std::string&);
	void get_ai_izlaz(const std::string&) const;
};

/*------USER CLASS------*/
class USER final
{
private:
	bool flag;

public:
	std::string get_ulaz_korisnika();
	USER()
		: flag(false)
	{}
};