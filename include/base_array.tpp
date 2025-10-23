#pragma once

template<typename T>
BaseArray<T>::BaseArray() : data(nullptr), m_size(0), m_capacity(0) {}

template<typename T>
BaseArray<T>::BaseArray(const size_t& n, const T& value) : m_size(0), m_capacity(0) {
    data = new T[m_capacity];
    for (size_t i = 0; i < n; ++i) {
        data[i] = value;
    }
}

template<typename T>
BaseArray<T>::BaseArray(const BaseArray& other) : m_size(other.m_size), m_capacity(other.m_size), data(new T[other.m_size]) {
    for (size_t i = 0; i < m_size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
BaseArray<T>:: BaseArray(BaseArray&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), data(other.data) {
    other.data = nullptr;
    other.m_size = 0;
}

template<typename T>
BaseArray<T>::~BaseArray() {
    delete[] data;
}

template<typename T>
void BaseArray<T>::expand() {
    int new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    T* new_data = new T[new_capacity];
    for (int i = 0; i < m_size; ++i)
        new_data[i] = data[i];
    delete[] data;
    data = new_data;
    m_capacity = new_capacity;
}

template<typename T>
void BaseArray<T>::push_back(const T& value) {
    if (m_size == m_capacity)
        expand();
    data[m_size++] = value;
}

template<typename T>
void BaseArray<T>::pop_back() {
    if (m_size > 0)
        m_size--;
}

template<typename T>
T& BaseArray<T>::operator[](size_t index) {
    if (index >= m_size) {
         throw std::out_of_range("index out of range");
        exit(1);
    }
    return data[index];
}

template<typename T>
const T& BaseArray<T>::operator[](size_t index) const {
    if (index >= m_size) {
         throw std::out_of_range("index out of range");
        exit(1);
    }
    return data[index];
}

template<typename T>
int BaseArray<T>::size() const {
    return m_size;
}

template<typename T>
bool BaseArray<T>::empty() const {
    return m_size == 0;
}

template<typename T>
void BaseArray<T>::clear() {
    m_size = 0;
}
