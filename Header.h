#pragma once

Player1::player1_last_two = player1_input.at(player1_input.size() - 2);
Player1::player1_last_two += player1_input.at(player1_input.size() - 1);

if (Player1::player1_last_two == "ka")
{
	return("Igrac 2 je pobedio!");
}

Player1::player2_first_two = player2_input.at(0);
Player1::player2_first_two += player2_input.at(1);

if (Player1::player2_first_two != Player1::player1_last_two)
{
	return("Igrac 1 je pobedio! Igrac 2 je uneo / la los pocetak.");
}

Player1::player2_last_two = player2_input.at(player2_input.size() - 2);
Player1::player2_last_two += player2_input.at(player2_input.size() - 1);

if (Player1::player2_last_two == "ka")
{
	return("Igrac 1 je pobedio!");
}