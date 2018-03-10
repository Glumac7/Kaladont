#include <iostream>
#include <string>

class Player1 final
{
private:
	std::string player1_input_string;

public:
	std::string get_player1_input() const;
	std::string get_winner(std::string&, std::string&);

	static std::string player2_last_two;
	static std::string player1_last_two;
	static std::string player2_first_two;
	static std::string player1_first_two;

};

class Player2 final
{ 
private:
	std::string player2_input_string;

public:
	static bool flag;
	static bool not_the_first_time;
	static bool wrong_beginning;
	static bool kaladont;
	std::string get_player2_input() const;

};