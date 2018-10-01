#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>



void prompt() { printf("db > "); }



enum MetaCommandResult
{
	META_COMMAND_EXIT,
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};

enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};

enum StatementType
{
	STATEMENT_INSERT,
	STATEMENT_SELECT
};

struct Statement
{
    StatementType type;
};



MetaCommandResult do_meta_command(const std::string& input_buffer)
{
	if (input_buffer == ".exit")
	{
		return META_COMMAND_EXIT;
	}
	else
	{
		return META_COMMAND_UNRECOGNIZED_COMMAND;
	}
}

PrepareResult prepare_statement(const std::string& input_buffer, Statement& statement)
{
	if (input_buffer == "insert")
	{
		statement.type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	}
	else if (input_buffer == "select")
	{
		statement.type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}
	else
		return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(const Statement& statement)
{
	switch (statement.type)
	{
		case (STATEMENT_INSERT):
			std::cout << "This is where we would do an insert." << std::endl;
			break;
		case (STATEMENT_SELECT):
			std::cout << "This is where we would do an select." << std::endl;
			break;
	}
}



int main(int argc, char* argv[])
{
	std::string input_buffer;

	std::malloc(100500);

	while (true)
	{
		prompt();

		std::getline(std::cin, input_buffer);

		if (input_buffer.at(0) == '.')
		{
			auto meta_command = do_meta_command(input_buffer);

			switch (meta_command)
			{
				case (META_COMMAND_EXIT):
					exit(EXIT_SUCCESS);
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED_COMMAND):
					std::cout << "Unrecognized command: " << input_buffer << std::endl;
					continue;
			}
		}

		Statement statement;
		auto prepare_result = prepare_statement(input_buffer, statement);

		switch (prepare_result)
		{
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				std::cout << "Unrecognized keyword at start of '" << input_buffer << "'." << std::endl;
				continue;
		}

		execute_statement(statement);

		std::cout << "Executed." << std::endl;
	}
}