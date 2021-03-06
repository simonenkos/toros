#include <commands/right_command.hpp>

#include <iostream>

std::string const right_command_t::name { "right" };

void right_command_t::apply(std::istream & input, model_t & model) const
{
    model_t::direction_t dir = model.get_direction();

    if      (dir == model_t::direction_t::north) dir = model_t::direction_t::east;
    else if (dir == model_t::direction_t::west)  dir = model_t::direction_t::south;
    else if (dir == model_t::direction_t::south) dir = model_t::direction_t::west;
    else if (dir == model_t::direction_t::east)  dir = model_t::direction_t::north;

    if (!model.rotate(dir))
    {
        std::cerr << "cannot rotate right" << std::endl;
    }
}