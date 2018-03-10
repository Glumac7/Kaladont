/*------Libraries------*/
#include "AI_Mode.h"
#include "PVP_Mode.h"

/*------Main Function------*/
int main() 
{
	int game_mode;

	std::cout << "Dobro dosli u KALADONT!\nIzaberite mode za igramnje\n\n1) PVP\n2) AI\n\n: ";
	std::cin >> game_mode;

	if (game_mode == 1)
	{
		system("cls");
		std::cout << "Dobro dosli u PVP mode!\n\n";

		Player1 player1;
		Player2 player2;

		char end = 's';
		do
		{
			std::string player1_input = player1.get_player1_input();
			std::string player2_input = player2.get_player2_input();

			std::string get_winner = player1.get_winner(player1_input, player2_input);

			if (get_winner == "Igrac 2 je pobedio!" || get_winner == "Igrac 1 je pobedio! Igrac 2 je uneo / la los pocetak." || get_winner == "Igrac 1 je pobedio!" || get_winner == "Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.")
			{
				std::cout << get_winner << "\n";
				end = 'n';
			}

		} while (end != 'n');

		system("pause");
		return 0;
	}

	if (game_mode == 2)
	{
		system("cls");
		std::cout << "Dobro dosli u AI mode!\n\n";

		AI ai;
		USER user;

		char end = 's';
		do
		{
			std::string user_input = user.get_user_input();
			std::string ai_calculation_return = ai.ai_calculation(user_input);

			ai.get_ai_output(ai_calculation_return);

			if (ai_calculation_return == "Pobedio si! :( Ne znam rec!" || ai_calculation_return == "Pobedio si! :(" || ai_calculation_return == "Pobedio sam! :D" || ai_calculation_return == "Pobedio sam!:D Uneo / la si pogresan pocetak!")
			{
				end = 'n';
			}

		} while (end != 'n');

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