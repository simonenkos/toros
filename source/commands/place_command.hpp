#ifndef TOROS_COMMANDS_PLACE_COMMAND_HPP
#define TOROS_COMMANDS_PLACE_COMMAND_HPP

#include <command.hpp>

struct place_command_t : public command_t
{
    static std::string const name;

    place_command_t() = default;

    place_command_t(place_command_t const &  other) = default;
    place_command_t(place_command_t       && other) = default;

    place_command_t & operator=(place_command_t const &  other) = default;
    place_command_t & operator=(place_command_t       && other) = default;

    ~place_command_t() override = default;

    void apply(std::istream & input, model_t & model) const override;
};

#endif // TOROS_COMMANDS_PLACE_COMMAND_HPP
