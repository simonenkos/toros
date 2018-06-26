#ifndef TOROS_COMMANDS_RIGHT_COMMAND_HPP
#define TOROS_COMMANDS_RIGHT_COMMAND_HPP

#include <command.hpp>

struct right_command_t : public command_t
{
    static std::string const name;

    right_command_t() = default;

    right_command_t(right_command_t const &  other) = default;
    right_command_t(right_command_t       && other) = default;

    right_command_t & operator=(right_command_t const &  other) = default;
    right_command_t & operator=(right_command_t       && other) = default;

    ~right_command_t() override = default;

    void apply(std::istream & input, model_t & model) const override;
};

#endif // TOROS_COMMANDS_RIGHT_COMMAND_HPP
