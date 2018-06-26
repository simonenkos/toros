#include <commands/move_command.hpp>

#include <iostream>

std::string const move_command_t::name { "move" };

void move_command_t::apply(std::istream & input, model_t & model) const
{
    if (!model.move())
    {
        std::cerr << "cannot move further" << std::endl;
    }
}