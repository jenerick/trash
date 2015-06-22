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
	bool		arm = true;
	int		emphasis = 0;
	std::string	input;

	const char *msg =
		"trash: version 0.1 alpha\n"
		"\n"
		"Usage: trash <input>\n"
		"  If input is given interactive mode is disabled.\n";

	if ( argc >= 2 ) {
		input = argv[1];
	}

	std::cout << "is it garbage, or is it trash?\n";
	while ( arm ) {
		if ( argc < 2 ) {
			std::cout << "?>";
			std::cin >> input;
		}

		if ( argc >= 2 ) {
			arm = false;
		}

		std::cout << '\n' << "synopsis: ";
		emphasis	= str_to_int(input) % 128;

		switch ( str_to_int(input) % 4 ) {
			case 0:
			if ( emphasis <= 32 )
				std::cout << "sort of ";
			else if ( emphasis <= 32*2 )
				std::cout << "forgivable ";
			else if ( emphasis <= 32*3 )
				std::cout << "undeniable ";
			else if ( emphasis <= 32*4 )
				std::cout << "unforgivable ";
			std::cout << "trash\n";
			break;
			case 1:
			if ( emphasis <= 32 )
				std::cout << "kind of ";
			else if ( emphasis <= 32*2 )
				std::cout << "probably ";
			else if ( emphasis <= 32*3 )
				std::cout << "definitely ";
			else if ( emphasis <= 32*4 )
				std::cout << "flaming ";
			std::cout << "garbage\n";
			break;
			case 2:
			std::cout << "vape ";
			if ( emphasis <= 32 )
				std::cout << "pen\n";
			else if ( emphasis <= 32*4 )
				std::cout << "smoke\n";
			break;
			case 3:
			std::cout << "rubbish\n";
			break;
		}

		std::cout << "emphasis: " << emphasis << " out of 128\n";
	}

	return	0;
}
