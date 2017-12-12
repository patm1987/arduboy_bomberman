#ifndef _UNORDERED_FIXED_SIZE_LIST_H
#define _UNORDERED_FIXED_SIZE_LIST_H

#include <stddef.h>

template <typename T, int CAPACITY = 8>
class UnorderedFixedSizeList
{
  public:
    bool add(const T &element);
    T &operator[](int index);
    bool remove(int index);
    size_t length() const;

    T *begin();
    T *end();
    const T *begin() const;
    const T *end() const;

  private:
    size_t _length;
    T _elements[CAPACITY];
};

template <typename T, int CAPACITY>
bool UnorderedFixedSizeList<T, CAPACITY>::add(const T &element)
{
    if (_length < CAPACITY)
    {
        _elements[_length++] = element;
        return true;
    }
    return false;
}

template <typename T, int CAPACITY>
T &UnorderedFixedSizeList<T, CAPACITY>::operator[](int index)
{
    return _elements[index];
}

template <typename T, int CAPACITY>
bool UnorderedFixedSizeList<T, CAPACITY>::remove(int index)
{
    if (index == _length - 1)
    {
        _length--;
        return true;
    }
    else if (index >= 0 && index < _length)
    {
        _elements[index] = _elements[_length - 1];
        _length--;
        return true;
    }
    return false;
}

template <typename T, int CAPACITY>
size_t UnorderedFixedSizeList<T, CAPACITY>::length() const
{
    return _length;
}

template <typename T, int CAPACITY>
T *UnorderedFixedSizeList<T, CAPACITY>::begin()
{
    return _elements;
}

template <typename T, int CAPACITY>
T *UnorderedFixedSizeList<T, CAPACITY>::end()
{
    return _elements + _length;
}

template <typename T, int CAPACITY>
const T *UnorderedFixedSizeList<T, CAPACITY>::begin() const
{
    return _elements;
}

template <typename T, int CAPACITY>
const T *UnorderedFixedSizeList<T, CAPACITY>::end() const
{
    return _elements + _length;
}

#endif //_UNORDERED_FIXED_SIZE_LIST_H