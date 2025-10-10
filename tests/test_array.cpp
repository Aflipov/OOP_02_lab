#include <gtest/gtest.h>
#include "array.h"

// Базовые проверки: создание, push, pop, clear, копирование, перемещение
TEST(ArraySuite, BasicOpsAndEdges) {
    Array arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    ASSERT_EQ(arr.len(), 3);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);

    // Проверка выброса при неверном разряде
    EXPECT_THROW(arr.push(4), std::invalid_argument);
    EXPECT_THROW(arr.push(255), std::invalid_argument);

    // Проверка удаления и очистки
    arr.pop(); // удалил 3
    ASSERT_EQ(arr.len(), 2);
    arr.clear();
    ASSERT_EQ(arr.len(), 0);

    // Проверка выброса при pop на пустом массиве
    EXPECT_THROW(arr.pop(), std::out_of_range);

    // Проверка конструктора из initializer_list
    Array arr2{0, 1, 2};
    ASSERT_EQ(arr2.len(), 3);
    EXPECT_EQ(arr2.get(2), 2);

    // Проверка конструктора из строки (с пробелами и нулями)
    Array arr3("0 3 2");
    ASSERT_EQ(arr3.len(), 3);
    EXPECT_EQ(arr3.get(0), 2);
    EXPECT_EQ(arr3.get(1), 3);
    EXPECT_EQ(arr3.get(2), 0);

    // Конструктор из строки с невалидным символом
    EXPECT_THROW(Array("4"), std::invalid_argument);
    EXPECT_THROW(Array("A2"), std::invalid_argument);

    // Копирование и перемещение
    Array arr4(arr3);
    ASSERT_EQ(arr4.len(), 3);
    Array arr5(std::move(arr4));
    ASSERT_EQ(arr5.len(), 3);

    // Проверка выброса при get вне диапазона
    EXPECT_THROW(arr5.get(10), std::out_of_range);

    // Конструктор из пустой строки
    Array arrEmpty("");
    ASSERT_EQ(arrEmpty.len(), 1);
    EXPECT_EQ(arrEmpty.get(0), 0);
}
