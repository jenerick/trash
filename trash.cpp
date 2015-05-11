#include <iostream>
#include <cstdlib>
#include <cstring>

unsigned long
str_to_int ( std::string str )
{
	const char	*datum = str.c_str();
	unsigned long	hash = 5381;
	int		c;

	while ( c = *datum++ )
		hash = ((hash << 5) + hash) + c;
	
	return	hash;
}

int
main ( int argc, char** argv )
{
	std::string	input;

	std::cout << "is it garbage, or is it trash?\n";
	while ( 1 ) {
		std::cout << "?>";
		std::cin >> input;
		std::cout << '\n' << "synopsis: ";

		switch ( str_to_int(input) % 4 ) {
			case 0:
			std::cout << "trash\n";
			break;
			case 1:
			std::cout << "garbage\n";
			break;
			case 2:
			std::cout << "vape\n";
			break;
			case 3:
			std::cout << "rubbish\n";
			break;
		}

		std::cout << "emphasis: " << str_to_int(input) % 128 << " out of 128\n";
	}

	return	0;
}
