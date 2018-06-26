#ifndef TOROS_COMMANDS_LEFT_COMMAND_HPP
#define TOROS_COMMANDS_LEFT_COMMAND_HPP

#include <command.hpp>

struct left_command_t : public command_t
{
    static std::string const name;

    left_command_t() = default;

    left_command_t(left_command_t const &  other) = default;
    left_command_t(left_command_t       && other) = default;

    left_command_t & operator=(left_command_t const &  other) = default;
    left_command_t & operator=(left_command_t       && other) = default;

    ~left_command_t() override = default;

    void apply(std::istream & input, model_t & model) const override;
};

#endif // TOROS_COMMANDS_LEFT_COMMAND_HPP
