#include <gtest/gtest.h>

#include <model.hpp>

TEST(ModelDirectionConstructionAndComparsionTest, ModelTests)
{
    model_t::direction_t dir { 0, 1, "name" };

    EXPECT_EQ("name", dir.to_string());
    EXPECT_EQ(dir, model_t::direction_t::north);
}

TEST(ModelDirectionMakeTest, ModelTests)
{
    auto north = model_t::direction_t::make("NORTH");
    auto south = model_t::direction_t::make("SOUTH");
    auto west  = model_t::direction_t::make("WEST");
    auto east  = model_t::direction_t::make("EAST");

    EXPECT_TRUE(north.has_value());
    EXPECT_TRUE(south.has_value());
    EXPECT_TRUE(west.has_value());
    EXPECT_TRUE(east.has_value());

    EXPECT_EQ(north, model_t::direction_t::north);
    EXPECT_EQ(south, model_t::direction_t::south);
    EXPECT_EQ(west,  model_t::direction_t::west);
    EXPECT_EQ(east,  model_t::direction_t::east);
}

TEST(ModelDirectionMakeInvalidTest, ModelTests)
{
    auto north = model_t::direction_t::make("north");
    auto other = model_t::direction_t::make("abcde");

    EXPECT_FALSE(north.has_value());
    EXPECT_FALSE(other.has_value());
}

TEST(ModelPlaceTest, ModelTests)
{
    model_t model { 10 };

    EXPECT_TRUE(model.place(1, 2, model_t::direction_t::north));
    EXPECT_TRUE(model.is_placed());

    EXPECT_EQ(1,                           model.get_position_x());
    EXPECT_EQ(2,                           model.get_position_y());
    EXPECT_EQ(model_t::direction_t::north, model.get_direction());
}

TEST(ModelInvalidPlaceTest, ModelTests)
{
    model_t model { 10 };

    EXPECT_FALSE(model.place(11, 11, model_t::direction_t::north));
    EXPECT_FALSE(model.is_placed());
}

TEST(ModelValidMoveAndRotateTest, ModelTests)
{
    model_t model { 10 };

    model.place(1, 2, model_t::direction_t::north);

    EXPECT_TRUE(model.move());

    EXPECT_EQ(1,                           model.get_position_x());
    EXPECT_EQ(3,                           model.get_position_y());
    EXPECT_EQ(model_t::direction_t::north, model.get_direction());

    EXPECT_TRUE(model.rotate(model_t::direction_t::west));

    EXPECT_EQ(1,                          model.get_position_x());
    EXPECT_EQ(3,                          model.get_position_y());
    EXPECT_EQ(model_t::direction_t::west, model.get_direction());

    EXPECT_TRUE(model.move());

    EXPECT_EQ(0,                          model.get_position_x());
    EXPECT_EQ(3,                          model.get_position_y());
    EXPECT_EQ(model_t::direction_t::west, model.get_direction());
}

TEST(ModelMoveAndRotateWithNoPlaceTest, ModelTests)
{
    model_t model { 10 };

    EXPECT_FALSE(model.is_placed());
    EXPECT_FALSE(model.move());
    EXPECT_FALSE(model.rotate(model_t::direction_t::north));
    EXPECT_FALSE(model.rotate(model_t::direction_t::south));
    EXPECT_FALSE(model.rotate(model_t::direction_t::west));
    EXPECT_FALSE(model.rotate(model_t::direction_t::east));
}

TEST(ModelInvalidMoveTest, ModelTests)
{
    model_t model { 4 };

    model.place(1, 1, model_t::direction_t::north);

    EXPECT_TRUE(model.move());
    EXPECT_TRUE(model.move());

    EXPECT_EQ(1,                           model.get_position_x());
    EXPECT_EQ(3,                           model.get_position_y());
    EXPECT_EQ(model_t::direction_t::north, model.get_direction());

    EXPECT_FALSE(model.move());
}