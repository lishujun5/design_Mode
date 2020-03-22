#pragma once
template <typename T>
class type_traist
{
    public:
        typedef T value_type;
        typedef T* point;
        typedef T& reference;
};

template <typename T>
class type_traist<T*>
{
    public:
        typedef T value_type;
        typedef T* point;
        typedef T& reference;
};

template < typename T>
class type_traist<const T*>
{
    public:
        typedef T value_type;
        typedef T* point;
        typedef T& reference;
};