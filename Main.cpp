/*------Libraries------*/
#include "AI_Mode.h"
#include "PVP_Mode.h"

/*------Main Function------*/
int main() 
{
	int mod;

	std::cout << "Dobro dosli u KALADONT!\nIzaberite mode za igramnje\n\n1) PVP\n2) AI\n\n: ";
	std::cin >> mod;

	if (mod == 1)
	{
		system("cls");
		std::cout << "Dobro dosli u PVP mode!\n\n";

		Igrac1 igrac1;
		Igrac2 player2;

		char kraj = 's';
		do
		{
			std::string igrac1_ulaz = igrac1.get_igrac1_ulaz();
			std::string player2_ulaz = player2.get_igrac2_ulaz();

			std::string get_pobednik = igrac1.get_pobednik(igrac1_ulaz, player2_ulaz);

			if (get_pobednik == "Igrac 2 je pobedio!" || get_pobednik == "Igrac 1 je pobedio! Igrac 2 je uneo / la los pocetak." || get_pobednik == "Igrac 1 je pobedio!" || get_pobednik == "Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.")
			{
				std::cout << get_pobednik << "\n";
				kraj = 'n';
			}

		} while (kraj != 'n');

		system("pause");
		return 0;
	}

	if (mod == 2)
	{
		system("cls");
		std::cout << "Dobro dosli u AI mode!\n\n";

		AI ai;
		USER user;

		char kraj = 's';
		do
		{
			std::string user_ulaz = user.get_ulaz_korisnika();
			std::string ai_calculation_return = ai.ai_kalkulacija(user_ulaz);

			ai.get_ai_izlaz(ai_calculation_return);

			if (ai_calculation_return == "Pobedio si! :( Ne znam rec!" || ai_calculation_return == "Pobedio si! :(" || ai_calculation_return == "Pobedio sam! :D" || ai_calculation_return == "Pobedio sam!:D Uneo / la si pogresan pocetak!")
			{
				kraj = 'n';
			}

		} while (kraj != 'n');

		return 0;
	}
	else
	{
		system("cls");

		std::cout << "Niste uneli dobar broj!\n";

		system("pause");

		return 0;
	}

	std::cin.get();
}