#include "password_generator.h"

int main()
{
	std::cout << "Hello in Password Generator!\n\n";
	password_generator pass_gen;
	std::cout << pass_gen.start_password_generator();

	return 0;
}