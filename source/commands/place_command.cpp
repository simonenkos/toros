#include <commands/place_command.hpp>
#include <utils/tokenizer.hpp>
#include <command_factory.hpp>

#include <iostream>
#include <sstream>
#include <algorithm>

std::string const place_command_t::name { "place" };

void place_command_t::apply(std::istream & input, model_t & model) const
{
    std::string arguments;

    if (!std::getline(input, arguments))
    {
        std::cerr << "no arguments provided for 'PLACE' command" << std::endl;
        return;
    }

    auto it = std::remove_if(arguments.begin(),
                             arguments.end(),
                             [](char ch) { return std::isspace(ch); });
    if (arguments.end() != it)
    {
        arguments.erase(it, arguments.end());
    }

    tokenizer_t tokenizer { arguments, ',' };

    auto pos_x = tokenizer.get<int>();
    auto pos_y = tokenizer.get<int>();
    auto dir   = tokenizer.get<std::string>();

    if (!pos_x.has_value() || !pos_y.has_value() || !dir.has_value())
    {
        std::cerr << "cannot get arguments for 'PLACE' command" << std::endl;
        return;
    }

    auto direction = model_t::direction_t::make(dir.value());

    if (!direction.has_value())
    {
        std::cerr << "unknown direction: " << dir.value() << std::endl;
        return;
    }
    if (!model.place(pos_x.value(), pos_y.value(), direction.value()))
    {
        std::cerr << "cannot apply 'PLACE' command with the specified arguments: "
                  << pos_x.value() << "," << pos_y.value() << "," << dir.value() << std::endl;
        return;
    }
}

