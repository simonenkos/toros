#ifndef TOROS_COMMAND_FACTORY_HPP
#define TOROS_COMMAND_FACTORY_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <memory>

#include <command.hpp>

class command_factory_t
{
    std::unordered_map<std::string,
                       std::shared_ptr<command_t>> command_registry_;

public:
    command_factory_t() = default;

    command_factory_t(command_factory_t const &  other) = delete;
    command_factory_t(command_factory_t       && other) = delete;

    command_factory_t & operator=(command_factory_t const &  other) = delete;
    command_factory_t & operator=(command_factory_t       && other) = delete;

    ~command_factory_t() = default;

    template <class cmd_t> bool register_command();

    std::shared_ptr<command_t> get_command(std::istream & input) const;
};

template <class cmd_t> bool command_factory_t::register_command()
{
    auto res = command_registry_.emplace(cmd_t::name,
                                         std::make_shared<cmd_t>());
    if (!res.second)
    {
        std::cerr << "command was not registered: " << cmd_t::name << std::endl;
        return false;
    }
    return true;
}

#endif //TOROS_COMMAND_FACTORY_HPP
