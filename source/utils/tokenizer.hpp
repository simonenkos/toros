#ifndef TOROS_UTILS_TOKENIZER_HPP
#define TOROS_UTILS_TOKENIZER_HPP

#include <string>
#include <istream>
#include <optional>

class tokenizer_t
{
    char           delimiter_;
    std::istream & input_;

public:
    tokenizer_t(std::istream & input, char delimiter);

    tokenizer_t(tokenizer_t const &  other) = delete;
    tokenizer_t(tokenizer_t       && other) = delete;

    tokenizer_t & operator=(tokenizer_t const &  other) = delete;
    tokenizer_t & operator=(tokenizer_t       && other) = delete;

    ~tokenizer_t() = default;

    template <class input_type_t> std::optional<input_type_t> get();

private:
    std::optional<std::string> extract_arguments();
};

#endif // TOROS_UTILS_TOKENIZER_HPP
