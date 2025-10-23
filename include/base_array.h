#pragma once
#include <iostream>

template<typename T>
class BaseArray {
private:
    T* data;          // указатель на элементы
    size_t m_size;         // количество элементов
    size_t m_capacity;     // ёмкость (макс. количество без перевыделения)

    // перевыделение памяти при полном заполнении массива
    void expand();

public:
    // конструктор без аргументов
    BaseArray();

    // конструктор (массив из n элементов value)
    BaseArray(const size_t& n, const T& value);

    // конструктор (копирование)
    BaseArray(const BaseArray& other);

    // конструктор (перемещение)
    BaseArray(BaseArray&& other) noexcept;

    // деструктор
    ~BaseArray();

    // добавление элемента в конец массива
    void push_back(const T& value);
    
    // удаление элемента из конца массива
    void pop_back();

    // доступ к элементу по индексу через []
    T& operator[](size_t index);

    // доступ к элементу по индексу через [] (const версия)
    const T& operator[](size_t index) const;

    // количество элементов массива
    int size() const;

    // true если массив пустой, false если нет
    bool empty() const;

    // очистка массива
    void clear();
};

#include "base_array.tpp"
