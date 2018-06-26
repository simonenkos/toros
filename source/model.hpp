#ifndef TOROS_MODEL_HPP
#define TOROS_MODEL_HPP

#include <string>
#include <optional>

struct model_t
{
    struct direction_t
    {
        static direction_t north;
        static direction_t south;
        static direction_t west;
        static direction_t east;

        static std::optional<direction_t> make(std::string const & name);

        int x_;
        int y_;

        std::string name_;

        direction_t(int x, int y, std::string name) : x_ { x },
                                                      y_ { y }, name_ { std::move(name) }
        { }

        direction_t(direction_t const &  other) = default;
        direction_t(direction_t       && other) = default;

        direction_t & operator=(direction_t const  & other) = default;
        direction_t & operator=(direction_t       && other) = default;

        ~direction_t() = default;

        std::string const & to_string() const;
    };

private:
    int const size_;

    bool is_placed_ { false };

    int position_x_ { 0 };
    int position_y_ { 0 };

    direction_t dir_;

public:
    explicit model_t(int size);

    model_t(model_t const &  other) = delete;
    model_t(model_t       && other) = delete;

    model_t & operator=(model_t const  & other) = delete;
    model_t & operator=(model_t       && other) = delete;

    ~model_t() = default;

    bool place(int x, int y, direction_t const & dir);
    bool move();
    bool rotate(direction_t dir);

    int get_position_x() const;
    int get_position_y() const;

    direction_t const & get_direction() const;
};

inline int model_t::get_position_x() const
{
    return position_x_;
}

inline int model_t::get_position_y() const
{
    return position_y_;
}

inline model_t::direction_t const & model_t::get_direction() const
{
    return dir_;
}

#endif //TOROS_MODEL_HPP
