#ifndef TOROS_COMMANDS_MOVE_COMMAND_HPP
#define TOROS_COMMANDS_MOVE_COMMAND_HPP

#include <command.hpp>

struct move_command_t : public command_t
{
    static std::string const name;

    move_command_t() = default;

    move_command_t(move_command_t const &  other) = default;
    move_command_t(move_command_t       && other) = default;

    move_command_t & operator=(move_command_t const &  other) = default;
    move_command_t & operator=(move_command_t       && other) = default;

    ~move_command_t() override = default;

    void apply(std::istream & input, model_t & model) const override;
};

#endif // TOROS_COMMANDS_MOVE_COMMAND_HPP
