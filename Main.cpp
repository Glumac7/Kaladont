/*------Libraries------*/
#include "Class.h"

/*------Main Function------*/
int main() 
{
	AI ai;
	USER user;

	char end = 's';
	do
	{
		std::string user_input = user.get_user_input();
		std::string ai_calculation_return = ai.get_ai_calculation(user_input);

		ai.get_ai_output(ai_calculation_return);
		if (ai_calculation_return == "Pobedio si! :( Ne znam rec!" || ai_calculation_return == "Pobedio si! :(" || ai_calculation_return == "Pobedio sam! :D" || ai_calculation_return == "Pobedio sam!:D Uneo / la si pogresan pocetak!")
		{
			end = 'n';
		}
	} while (end != 'n');

	std::cin.get();
}