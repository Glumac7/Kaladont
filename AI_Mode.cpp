#include "AI_Mode.h"

std::string AI::ai_last_two;
bool AI::is_the_value_invalid = false;

std::string USER::get_user_input()
{
	bool is_the_value_invalid = false;

	std::string user_input;

	std::cout << "Tvoj red: ";
	std::cin >> user_input;

	if (!flag)
	{
		flag = true;
	}
	else
	{
		std::string user_first_two;

		user_first_two = user_input.at(0);
		user_first_two += user_input.at(1);

		if(AI::ai_last_two == user_first_two)
		{ }
		else
		{
			is_the_value_invalid = true;
		}
	}

	AI::is_the_value_invalid = is_the_value_invalid;

	return (user_input);
}

void AI::get_ai_output(const std::string& ai_output) const
{
	std::cout << "AI kaze: " << ai_output << std::endl;

	Sleep(2000);
}

std::string AI::ai_calculation(const std::string& user_input)
{
	

	file.open("AI.txt", std::ifstream::in);

	if (AI::file.is_open())
	{
		last_two_chars = user_input.at(user_input.size() - 2);
		last_two_chars += user_input.at(user_input.size() - 1);

		if (last_two_chars == "ka")
		{
			return("Pobedio sam! :D");
		}

		std::string file_string;

		while (file >> file_string)
		{
			words_from_the_file.push_back(file_string);
		}
		file.close();
	}

	
	std::vector<std::string> chosen_words;
	unsigned int i;
	int counter = 0;

	for (i = 0; i != words_from_the_file.size() - 1; i++)
	{

		std::string a_word_form_the_file = words_from_the_file.at(i);

		if (a_word_form_the_file.size() >= 2)
		{
			if (a_word_form_the_file.at(0) == last_two_chars.at(0) && a_word_form_the_file.at(1) == last_two_chars.at(1))
			{
				chosen_words.push_back(a_word_form_the_file);
			}
			else
			{
				counter++;
			}
			
		}
		else
		{
			counter++;
		}

		srand(time(NULL));
	}
	
	if (i == counter)
	{
		return("Pobedio si! :( Ne znam rec!");
	}

	std::string chosen_word = chosen_words.at(rand() % chosen_words.size());

	if ((chosen_word.at(chosen_word.size() - 2) == 'k') && (chosen_word.at(chosen_word.size() - 1) == 'a'))
	{
		AI::get_ai_output(chosen_word);
		
		return("Pobedio si! :(");
	}

	AI::ai_last_two = chosen_word.at(chosen_word.size() - 2);
	AI::ai_last_two += chosen_word.at(chosen_word.size() - 1);

	if (AI::is_the_value_invalid == true)
	{
		return("Pobedio sam!:D Uneo / la si pogresan pocetak!");
	}

	return(chosen_word);
}