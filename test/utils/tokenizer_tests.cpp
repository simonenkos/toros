#include <utils/tokenizer.hpp>
#include <gtest/gtest.h>

TEST(TokenizerGetStringTest, TokenizerTests)
{
    tokenizer_t tokenizer { "test string:another test string", ':' };

    auto fst = tokenizer.get<std::string>();
    auto snd = tokenizer.get<std::string>();

    EXPECT_TRUE(fst.has_value());
    EXPECT_TRUE(snd.has_value());

    EXPECT_EQ(fst.value(), "test string");
    EXPECT_EQ(snd.value(), "another test string");
}

TEST(TokenizerGetIntTest, TokenizerTests)
{
    tokenizer_t tokenizer { "102345;100;0000;12;", ';' };

    auto i1 = tokenizer.get<int>();
    auto i2 = tokenizer.get<int>();
    auto i3 = tokenizer.get<int>();
    auto i4 = tokenizer.get<int>();

    EXPECT_TRUE(i1.has_value());
    EXPECT_TRUE(i2.has_value());
    EXPECT_TRUE(i3.has_value());
    EXPECT_TRUE(i4.has_value());

    EXPECT_EQ(i1.value(), 102345);
    EXPECT_EQ(i2.value(), 100);
    EXPECT_EQ(i3.value(), 0);
    EXPECT_EQ(i4.value(), 12);
}

TEST(TokenizerGetNegativeIntTest, TokenizerTests)
{
    tokenizer_t tokenizer { "9;-9", ';' };

    auto i1 = tokenizer.get<int>();
    auto i2 = tokenizer.get<int>();

    EXPECT_TRUE(i1.has_value());
    EXPECT_FALSE(i2.has_value());
}

TEST(TokenizerGetInvalidIntTest, TokenizerTests)
{
    tokenizer_t tokenizer { "123,321,12abc", ',' };

    auto i1 = tokenizer.get<int>();
    auto i2 = tokenizer.get<int>();
    auto i3 = tokenizer.get<int>();

    EXPECT_TRUE(i1.has_value());
    EXPECT_TRUE(i2.has_value());
    EXPECT_FALSE(i3.has_value());
}

TEST(TokenizerDifferentDelimiterTest, TokenizerTests)
{
    tokenizer_t tokenizer { "abc,12;123", ';' };

    auto s1 = tokenizer.get<std::string>();
    auto i1 = tokenizer.get<int>();
    auto i2 = tokenizer.get<int>();

    EXPECT_TRUE(s1.has_value());
    EXPECT_TRUE(i1.has_value());
    EXPECT_FALSE(i2.has_value());

    EXPECT_EQ(s1.value(), "abc,12");
    EXPECT_EQ(i1.value(), 123);
}
