#include "PVP_Mode.h"

#define Define_igrac1_prva_dva Igrac1::igrac1_prva_dva = igrac1_ulaz.at(0);Igrac1::igrac1_prva_dva += igrac1_ulaz.at(1);
#define Define_igrac1_poslednja_dva Igrac1::igrac1_poslednja_dva = igrac1_ulaz.at(igrac1_ulaz.size() - 2); Igrac1::igrac1_poslednja_dva += igrac1_ulaz.at(igrac1_ulaz.size() - 1);

#define	Define_igrac2_prva_dva Igrac2::igrac2_prva_dva = igrac2_ulaz.at(0);Igrac2::igrac2_prva_dva += igrac2_ulaz.at(1);
#define Define_igrac2_poslednja_dva Igrac2::igrac2_poslednja_dva = igrac2_ulaz.at(igrac2_ulaz.size() - 2);Igrac2::igrac2_poslednja_dva += igrac2_ulaz.at(igrac2_ulaz.size() - 1);


bool Igrac2::prvi_put = true;
bool Igrac2::los_pocetak = false;
bool Igrac2::flag = false;
bool Igrac2::kaladont = false;

std::string Igrac1::igrac1_prva_dva = "";
std::string Igrac2::igrac2_poslednja_dva = "";
std::string Igrac1::igrac1_poslednja_dva = "";
std::string Igrac2::igrac2_prva_dva = "";


std::string Igrac1::get_igrac1_ulaz() const
{
	std::cout << "Igrac 1: ";

	std::string igrac1;

	std::cin >> igrac1;

	if (!Igrac2::prvi_put)
	{
		std::string *prva_dva = new std::string;

		*prva_dva = igrac1.at(0);
		*prva_dva += igrac1.at(1);

		if (*prva_dva != Igrac2::igrac2_poslednja_dva)
		{
			Igrac2::los_pocetak = true;
		}

		delete prva_dva;

		std::string poslednja_dva;

		poslednja_dva = igrac1.at(igrac1.size() - 2);
		poslednja_dva += igrac1.at(igrac1.size() - 1);

		if (poslednja_dva == "ka")
		{
			Igrac2::kaladont = true;
		}
	}
	else
	{
		Igrac2::prvi_put = false;
	}

	return (igrac1);
}

std::string Igrac2::get_igrac2_ulaz() const
{
	if (Igrac2::los_pocetak)
	{
		return ("Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.");
	}

	if (Igrac2::kaladont)
	{
		return ("Igrac 2 je pobedio!");
	}

	std::cout << "Igrac 2: ";

	std::string igrac2;

	std::cin >> igrac2;

	return (igrac2);
}

std::string Igrac1::get_pobednik(std::string& igrac1_ulaz, std::string& igrac2_ulaz)
{
	if (!Igrac2::flag)
	{
		Define_igrac1_poslednja_dva;

		if (Igrac1::igrac1_poslednja_dva == "ka")
		{ 
			return("Igrac 2 je pobedio!"); 
		}

		Define_igrac2_prva_dva;

		if (Igrac2::igrac2_prva_dva != Igrac1::igrac1_poslednja_dva) 
		{ 
			return("Igrac 1 je pobedio! Igrac 2 je uneo / la los pocetak."); 
		}

		Define_igrac2_poslednja_dva;

		if (Igrac2::igrac2_poslednja_dva == "ka") 
		{ 
			return("Igrac 1 je pobedio!"); 
		}
	
		Igrac2::flag = true;
	}

	else
	{
		Define_igrac1_prva_dva;

		if (Igrac2::igrac2_poslednja_dva != Igrac1::igrac1_prva_dva)
		{
			return("Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.");
		}

		Define_igrac1_poslednja_dva;

		if (Igrac1::igrac1_poslednja_dva == "ka")
		{
			return("Igrac 2 je pobedio!");
		}

		Define_igrac2_prva_dva;

		if (Igrac2::igrac2_prva_dva != Igrac1::igrac1_poslednja_dva)
		{
			return("Igrac 1 je pobedio! Igrac 2 je uneo / la los pocetak.");
		}

		Define_igrac2_poslednja_dva;

		if (Igrac2::igrac2_poslednja_dva == "ka")
		{
			return("Igrac 1 je pobedio!");
		}
	}
	return ("");
}