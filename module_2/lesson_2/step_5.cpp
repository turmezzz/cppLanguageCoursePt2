#include <iostream>
#include <utility>

template <class T>
struct Array {
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0);

    Array(Array const& a);

    Array& operator=(Array const& a);

    ~Array();

    size_t size() const;

    T& operator[](size_t i);

    T const& operator[](size_t i) const;

    // реализуйте перемещающий конструктор

    // реализуйте перемещающий оператор присваивания

    Array(Array&& other)  noexcept {
        std::swap(other.data_, data_);
        std::swap(other.size_, size_);
    }

    Array& operator=(Array&& other) noexcept {
        std::swap(other.data_, data_);
        std::swap(other.size_, size_);
        return *this;
    }

private:
    size_t size_ = 0;
    T* data_ = nullptr;
};