#include <gtest/gtest.h>

#include <command_factory.hpp>
#include <commands/report_command.hpp>

TEST(CommandFactoryValidRegisterAndGetTest, CommandFactoryTests)
{
    command_factory_t factory;
    std::istringstream input("REPORT");

    EXPECT_TRUE(factory.register_command<report_command_t>());
    EXPECT_NE(nullptr, factory.get_command(input));
}

TEST(CommandFactoryDoubleRegisterTest, CommandFactoryTests)
{
    command_factory_t factory;

    EXPECT_TRUE( factory.register_command<report_command_t>());
    EXPECT_FALSE(factory.register_command<report_command_t>());
}

TEST(CommandFactoryInvlidGetTest, CommandFactoryTests)
{
    command_factory_t factory;
    std::istringstream input("abcd");

    EXPECT_TRUE(factory.register_command<report_command_t>());
    EXPECT_EQ(nullptr, factory.get_command(input));
}