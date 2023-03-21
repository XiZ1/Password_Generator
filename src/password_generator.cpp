// ReSharper disable CppClangTidyConcurrencyMtUnsafe
// ReSharper disable CppInitializedValueIsAlwaysRewritten
#include "password_generator.h"
#include <cstdlib>
#include <conio.h>
#include <ctime>

string password_generator::start_password_generator()
{
	password_ = "";
	set_password_length();
	if (whether_to_add_symbols() == true)
	{
		generate_password(4);
	}
	else
	{
		generate_password(3);
	}
	std::cout << "PASSWORD: ";
	return password_;
}

string password_generator::start_password_generator(const int length, const bool symbols)
{
	password_ = "";
	password_length_ = length;
	if (password_length_verification() == false)
	{
		system("cls");
		return "Password length incorrect! Please Try Again!\n";
	}
	if (symbols == true)
	{
		generate_password(4);
	}
	else
	{
		generate_password(3);
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
		if (min_password_length_ <= password_length_ && password_length_ <= max_password_length_)
		{
			system("cls");
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

bool password_generator::password_length_verification() const
{
	if (min_password_length_ <= password_length_ && password_length_ <= max_password_length_)
	{
		return true;
	}
	return false;
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
			system("cls");
			return true;
		}
		else if (choose == 'n' || choose == 'N')
		{
			system("cls");
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

void password_generator::generate_password(const int symbols)
{
	// ReSharper disable once CppZeroConstantCanBeReplacedWithNullptr
	srand(time(NULL));  // NOLINT(clang-diagnostic-shorten-64-to-32, cert-msc51-cpp)
	int drawn_number_of_table = 0;
	int drawn_number_of_char = 0;
	for (int i = 0; i < password_length_; i++)
	{
		drawn_number_of_table = std::rand() % symbols;
		drawn_number_of_char = std::rand() % tab_char_size_[drawn_number_of_table];
		password_ += tab_char_[drawn_number_of_table][drawn_number_of_char];
	}
}
