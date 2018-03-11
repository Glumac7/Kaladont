#include "AI_Mode.h"

std::string AI::ai_poslednja_dva_karaktera;
bool AI::da_li_je_vrednost_validna = false;

std::string USER::get_ulaz_korisnika()
{
	bool da_li_je_vrednost_validna = false;

	std::string ulaz_korisnika;

	std::cout << "Tvoj red: ";
	std::cin >> ulaz_korisnika;

	if (!flag)
	{
		flag = true;
	}
	else
	{
		std::string user_first_two;

		user_first_two = ulaz_korisnika.at(0);
		user_first_two += ulaz_korisnika.at(1);

		if(AI::ai_poslednja_dva_karaktera == user_first_two)
		{ }
		else
		{
			da_li_je_vrednost_validna = true;
		}
	}

	AI::da_li_je_vrednost_validna = da_li_je_vrednost_validna;

	return (ulaz_korisnika);
}

void AI::get_ai_izlaz(const std::string& ai_izlaz) const
{
	std::cout << "AI kaze: " << ai_izlaz << std::endl;

	Sleep(2000);
}

std::string AI::ai_kalkulacija(const std::string& ulaz_korisnika)
{
	tekst_fajl.open("AI.txt", std::ifstream::in);

	if (AI::tekst_fajl.is_open())
	{
		poslednja_dva_karaktera = ulaz_korisnika.at(ulaz_korisnika.size() - 2);
		poslednja_dva_karaktera += ulaz_korisnika.at(ulaz_korisnika.size() - 1);

		if (poslednja_dva_karaktera == "ka")
		{
			return("Pobedio sam! :D");
		}

		std::string rec_iz_fajla;

		while (tekst_fajl >> rec_iz_fajla)
		{
			vector_reci_iz_fajla.push_back(rec_iz_fajla);
		}
		tekst_fajl.close();
	}
	
	std::vector<std::string> izabrane_reci;
	unsigned int i;
	int brojac = 0;

	for (i = 0; i != vector_reci_iz_fajla.size() - 1; i++)
	{
		std::string rec_iz_fajla = vector_reci_iz_fajla.at(i);

		if (rec_iz_fajla.size() >= 2)
		{
			if (rec_iz_fajla.at(0) == poslednja_dva_karaktera.at(0) && rec_iz_fajla.at(1) == poslednja_dva_karaktera.at(1))
			{
				izabrane_reci.push_back(rec_iz_fajla);
			}
			else
			{
				brojac++;
			}
		}
		else
		{
			brojac++;
		}

		srand(time(NULL));
	}
	
	if (i == brojac)
	{
		return("Pobedio si! :( Ne znam rec!");
	}

	std::string izabrana_rec = izabrane_reci.at(rand() % izabrane_reci.size());

	if ((izabrana_rec.at(izabrana_rec.size() - 2) == 'k') && (izabrana_rec.at(izabrana_rec.size() - 1) == 'a'))
	{
		AI::get_ai_izlaz(izabrana_rec);
		
		return("Pobedio si! :(");
	}

	AI::ai_poslednja_dva_karaktera = izabrana_rec.at(izabrana_rec.size() - 2);
	AI::ai_poslednja_dva_karaktera += izabrana_rec.at(izabrana_rec.size() - 1);

	if (AI::da_li_je_vrednost_validna == true)
	{
		return("Pobedio sam!:D Uneo / la si pogresan pocetak!");
	}

	return(izabrana_rec);
}