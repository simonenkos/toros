#include <iostream>
#include <algorithm>

#include <command_factory.hpp>

std::shared_ptr<command_t> command_factory_t::get_command(std::istream & input) const
{
    std::string command_name;
    std::shared_ptr<command_t> result;

    if (input >> command_name)
    {
        std::transform(command_name.begin(),
                       command_name.end(),
                       command_name.begin(), (int (*)(int))std::tolower);

        auto it = command_registry_.find(command_name);

        if (command_registry_.end() != it)
            result = it->second;
        else
            std::cerr << "unknown command: " << command_name << std::endl;
    }
    return result;
}