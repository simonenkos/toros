#ifndef TOROS_COMMAND_HPP
#define TOROS_COMMAND_HPP

#include <model.hpp>

struct command_t
{
    virtual ~command_t() = default;

    virtual void apply(std::istream & input,
                       model_t      & model) const = 0;
};

#endif //TOROS_COMMAND_HPP
