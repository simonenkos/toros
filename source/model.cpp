#include <model.hpp>

#include <exception>

model_t::direction_t model_t::direction_t::north = model_t::direction_t {  0,  1, "NORTH" };
model_t::direction_t model_t::direction_t::south = model_t::direction_t {  0, -1, "SOUTH" };
model_t::direction_t model_t::direction_t::west  = model_t::direction_t { -1,  0, "WEST"  };
model_t::direction_t model_t::direction_t::east  = model_t::direction_t {  1,  0, "EAST" };

std::optional<model_t::direction_t> model_t::direction_t::make(std::string const & name)
{
    if (name == north.to_string()) return std::optional<direction_t> { north };
    if (name == south.to_string()) return std::optional<direction_t> { south };
    if (name == west.to_string())  return std::optional<direction_t> { west  };
    if (name == east.to_string())  return std::optional<direction_t> { east  };

    return std::optional<direction_t> {};
}

std::string const & model_t::direction_t::to_string() const
{
    return name_;
}

bool model_t::direction_t::operator==(model_t::direction_t const & other) const
{
    return (x_ == other.x_) &&
           (y_ == other.y_);
}

model_t::model_t(int size) : size_ { size }, dir_ { 0, 0, "nowhere" }
{ }

bool model_t::place(int x, int y, model_t::direction_t const & dir)
{
    if (x < 0 || x >= size_ || y < 0 || y >= size_)
        return false;

    position_x_ = x;
    position_y_ = y;
    dir_        = dir;

    is_placed_ = true;
    return true;
}

bool model_t::move()
{
    if (!is_placed_) return false;

    int new_position_x = position_x_ + dir_.x_;
    int new_position_y = position_y_ + dir_.y_;

    return place(new_position_x, new_position_y, dir_);
}

bool model_t::rotate(model_t::direction_t dir)
{
    if (!is_placed_) return false;

    dir_ = dir;
    return true;
}

