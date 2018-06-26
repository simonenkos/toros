#ifndef TOROS_COMMANDS_REPORT_COMMAND_HPP
#define TOROS_COMMANDS_REPORT_COMMAND_HPP

#include <command.hpp>

struct report_command_t : public command_t
{
    static std::string const name;

    report_command_t() = default;

    report_command_t(report_command_t const &  other) = default;
    report_command_t(report_command_t       && other) = default;

    report_command_t & operator=(report_command_t const &  other) = default;
    report_command_t & operator=(report_command_t       && other) = default;

    ~report_command_t() override = default;

    void apply(std::istream & input, model_t & model) const override;
};

#endif // TOROS_COMMANDS_REPORT_COMMAND_HPP
