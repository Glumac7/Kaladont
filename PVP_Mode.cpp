#include "PVP_Mode.h"

bool Player2::not_the_first_time = false;
bool Player2::wrong_beginning = false;
bool Player2::flag = false;
bool Player2::kaladont = false;

std::string Player1::player1_first_two = "";
std::string Player1::player2_last_two = "";
std::string Player1::player1_last_two = "";
std::string Player1::player2_first_two = "";


std::string Player1::get_player1_input() const
{
	std::cout << "Igrac 1: ";

	std::string player1;

	std::cin >> player1;

	if (Player2::not_the_first_time)
	{
		std::string first;
		first = player1.at(0);
		first += player1.at(1);

		if (first != Player1::player2_last_two)
		{
			Player2::wrong_beginning = true;
		}
		
		first = player1.at(player1.size() - 2);
		first += player1.at(player1.size() - 1);

		if (first == "ka")
		{
			Player2::kaladont = true;
		}

	}
	else
	{
		Player2::not_the_first_time = true;
	}

	return (player1);
}

std::string Player2::get_player2_input() const
{
	if (Player2::wrong_beginning)
	{
		return ("Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.");
	}

	if (Player2::kaladont)
	{
		return ("Igrac 2 je pobedio!");
	}

	std::cout << "Igrac 2: ";

	std::string player2;

	std::cin >> player2;

	return (player2);
}

std::string Player1::get_winner(std::string& player1_input, std::string& player2_input)
{
	#include "Header.h"

	if (!Player2::flag)
	{
		Player2::flag = true;
	}

	else
	{
		Player1::player1_first_two = player1_input.at(0);
		Player1::player1_first_two += player1_input.at(1);

		if (Player1::player2_last_two != Player1::player1_first_two)
		{
			return("Igrac 2 je pobedio! Igrac 1 je uneo / la los pocetak.");
		}
	}
	return ("");
}