#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>



void prompt() { printf("db > "); }



int main(int argc, char* argv[])
{
	std::string input_buffer;

	std::malloc(100500);

	while (true)
	{
		prompt();

		std::getline(std::cin, input_buffer);

		if (input_buffer == ".exit")
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			std::cout << "Unrecognized command: " << input_buffer << std::endl;
		}
	}
}