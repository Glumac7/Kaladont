#include <iostream>
#include <string>

class Igrac1 final
{
private:
	std::string igrac1_ulaz_string;

public:
	std::string get_igrac1_ulaz() const;
	std::string get_pobednik(std::string&, std::string&);
	
	static std::string igrac1_prva_dva;
	static std::string igrac1_poslednja_dva;
};

class Igrac2 final
{ 
private:
	std::string igrac2_ulaz_string;

public:
	static bool flag;
	static bool prvi_put;
	static bool los_pocetak;
	static bool kaladont;

	static std::string igrac2_prva_dva;
	static std::string igrac2_poslednja_dva;
	std::string get_igrac2_ulaz() const;

};