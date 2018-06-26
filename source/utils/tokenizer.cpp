#include <utils/tokenizer.hpp>

#include <algorithm>
#include <iostream>

tokenizer_t::tokenizer_t(std::string const & str, char delimiter)
: input_     { str }
, delimiter_ { delimiter }
{ }

template <> std::optional<std::string> tokenizer_t::get()
{
    return extract_arguments();
}

template <> std::optional<int> tokenizer_t::get()
{
    auto args = extract_arguments();

    if (args.has_value())
    {
        auto value = args.value();

        if (value.end() == std::find_if_not(value.cbegin(),
                                            value.cend(),
                                            [](char ch) { return std::isdigit(ch); }))
        {
            return std::optional<int> { std::stoi(value) };
        }
    }

    return std::optional<int> {};
}

std::optional<std::string> tokenizer_t::extract_arguments()
{
    std::string                value;
    std::optional<std::string> return_value;

    if (std::getline(input_, value, delimiter_))
    {
        return_value = value;
    }
    return return_value;
}