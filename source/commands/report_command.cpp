#include <commands/report_command.hpp>
#include <command_factory.hpp>

std::string const report_command_t::name { "report" };

void report_command_t::apply(std::istream & input, model_t & model) const
{
    std::cout << "Output: "
              << model.get_position_x() << ","
              << model.get_position_y() << ","
              << model.get_direction().to_string() << std::endl;
}