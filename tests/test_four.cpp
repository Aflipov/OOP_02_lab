#include <gtest/gtest.h>
#include "four.h"

// Проверка создания и базовых функций
TEST(FourSuite, CreationAndBasicOps)
{
    Four x("321");
    Four y{1, 2, 3};

    ASSERT_EQ(x.len(), 3);
    ASSERT_EQ(y.len(), 3);

    EXPECT_EQ(x.to_string(), "3 2 1");
    EXPECT_EQ(y.to_string(), "3 2 1");

    Four single("2");
    ASSERT_EQ(single.len(), 1);
    EXPECT_EQ(single.to_string(), "2");

    Four zeros("0003");
    EXPECT_EQ(zeros.to_string(), "3");

    Four spaced("  1   3  "); // пробелы
    EXPECT_EQ(spaced.to_string(), "1 3");

    // Проверка сравнения
    EXPECT_TRUE(Four::equals(x, y));
    EXPECT_FALSE(Four::notequals(x, y));
    EXPECT_TRUE(Four::greater(x, single));
    EXPECT_TRUE(Four::less(single, x));
    EXPECT_TRUE(Four::equalsless(single, x));
    EXPECT_TRUE(Four::equalsgreater(x, y));
}

// Проверка арифметики
TEST(FourSuite, AddAndSub)
{
    Four a("123"), b("11");
    Four sum = Four::add4(a, b);
    Four diff = Four::sub4(a, b);

    EXPECT_EQ(sum.to_string(), "2 0 0");
    EXPECT_EQ(diff.to_string(), "1 1 2");
}

// Тестирование ошибок и граничных случаев
TEST(FourSuite, EdgeCases)
{
    EXPECT_THROW((Four{4}), std::invalid_argument);
    EXPECT_THROW(Four("7"), std::invalid_argument);

    Four empty_str("");
    EXPECT_EQ(empty_str.to_string(), "0");

    Four a("3"), b("3");
    Four s = Four::add4(a, b);
    EXPECT_EQ(s.to_string(), "1 2");

    Four small("1"), big("3");
    EXPECT_THROW(Four::sub4(small, big), std::invalid_argument);

    Four x("2"), y("2");
    EXPECT_TRUE(Four::equals(x, y));
    EXPECT_FALSE(Four::greater(x, y));
    EXPECT_FALSE(Four::less(x, y));
}
