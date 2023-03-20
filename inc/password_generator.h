#pragma once

#include <iostream>

using std::string;

class password_generator
{
public:
	string start_password_generator();
	string start_password_generator(const int length, const bool symbols);

private:
	int password_length_ = 0;
	const int min_password_length_ = 8;
	const int max_password_length_ = 64;
	const int tab_char_size_[4] = { 26, 26, 10, 31 };
	string tab_char_[4] = { {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, {"abcdefghijklmnoprstuvwxyz"}, {"0123456789"}, {"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}"} };
	string password_;

	void set_password_length();
	bool password_length_verification() const;  // NOLINT(modernize-use-nodiscard)
	static bool whether_to_add_symbols();
	void generate_password_with_symbols();
	void generate_password_without_symbols();
};