#include <iostream>
#include <fstream>

#include <model.hpp>
#include <command_factory.hpp>
#include <commands/place_command.hpp>
#include <commands/report_command.hpp>

const int TABLE_SIZE = 5;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "please specify the path to the input file" << std::endl;
        return -1;
    }

    std::ifstream input { argv[1] };

    if (!input.is_open())
    {
        std::cerr << "cannot open '" << argv[1] << "' file to process commands" << std::endl;
        return -1;
    }

    command_factory_t command_factory;

    command_factory.register_command<place_command_t>();
    command_factory.register_command<report_command_t>();

    model_t robot_model(TABLE_SIZE);

    while (!input.eof())
    {
        auto cmd_ptr = command_factory.get_command(input);

        if (nullptr != cmd_ptr)
        {
            cmd_ptr->apply(input, robot_model);
        }
    }
    return 0;
}