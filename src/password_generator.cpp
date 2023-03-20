#include "password_generator.h"
#include <cstdlib>
#include <conio.h>
#include <ctime>

string password_generator::start_password_generator()
{
	set_password_length();
	if (whether_to_add_symbols() == true)
	{
		generate_password_with_symbols();
	}
	else
	{
		generate_password_without_symbols();
	}
	return password_;
}

void password_generator::set_password_length()
{
	bool end_loop = false;
	std::cout << "Set password length. MIN password length = 8. MAX password length = 64.\n";
	do
	{
		std::cin >> password_length_;
		if ((min_password_length_ <= password_length_) && (password_length_ <= max_password_length_))
		{
			end_loop = true;
		}
		else
		{
			system("cls");
			std::cout << "Try again!\n";
			std::cout << "Set password length. MIN password length = 8. MAX password length = 64.\n";
		}
	} while (end_loop != true);
}

bool password_generator::whether_to_add_symbols()
{
	std::cout << "Whether add symbols to password?" << "\n" << R"(Press 'y' or 'n')";
	do
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const int choose = _getch();
		if (choose == 'y' || choose == 'Y')
		{
			return true;
		}
		else if (choose == 'n' || choose == 'N')
		{
			return false;
		}
		else
		{
			system("cls");
			std::cout << "That answer doesn't exist! Please try again.\n";
			std::cout << "Whether add symbols to password?" << R"(Press 'y' or 'n')";
		}
	} while (true);
}

void password_generator::generate_password_with_symbols()
{

}

void password_generator::generate_password_without_symbols()
{

}