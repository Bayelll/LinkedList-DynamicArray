#include <iostream>
#include <stdexcept>

using namespace std;

class VectorIndexError : public exception
{
private:
    string error;

public:
    explicit VectorIndexError(const string &error) : error(error) {}

    const char* what() const noexcept override { return error.c_str(); }
};

template <typename T>
class Vector
{
private:
    T* ptr;
    size_t length;
    size_t Capacity;

    void resize(size_t newCapacity)
    {
        T* newPtr = new T[newCapacity];
        for (size_t i = 0; i < length; ++i)
        {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
        Capacity = newCapacity;
    }

public:
    Vector() : ptr(new T[8]), length(0), Capacity(8) {}

    Vector(const Vector &other) : ptr(new T[other.Capacity]), length(other.length), Capacity(other.Capacity)
    {
        for (size_t i = 0; i < length; ++i)
        {
            ptr[i] = other.ptr[i];
        }
    }

    Vector& operator=(const Vector &other)
    {
        if (this == &other) return *this;

        delete[] ptr;

        Capacity = other.Capacity;
        length = other.length;
        ptr = new T[Capacity];
        for (size_t i = 0; i < length; ++i)
        {
            ptr[i] = other.ptr[i];
        }

        return *this;
    }

    void push_back(const T& value)
    {
        if (length == Capacity)
        {
            resize(Capacity * 2);
        }
        ptr[length++] = value;
    }

    void push_front(const T& value)
    {
        if (length == Capacity)
        {
            resize(Capacity * 2);
        }
        for (size_t i = length; i > 0; --i)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[0] = value;
        ++length;
    }

    void pop_back()
    {
        if (length == 0)
            throw VectorIndexError("Vector is empty.");
        --length;
    }

    void pop_front()
    {
        if (length == 0)
            throw VectorIndexError("Vector is empty.");
        for (size_t i = 1; i < length; ++i)
        {
            ptr[i - 1] = ptr[i];
        }
        --length;
    }

    void insert(size_t index, const T& value)
    {
        if (index < 0 || index > length)
            throw VectorIndexError("Invalid element index.");

        if (length == Capacity)
        {
            resize(Capacity * 2);
        }

        for (size_t i = length; i > index; --i)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = value;
        ++length;
    }

    void remove(size_t index)
    {
        if (index < 0 || index >= length)
            throw VectorIndexError("Invalid element index.");

        for (size_t i = index; i < length - 1; ++i)
        {
            ptr[i] = ptr[i + 1];
        }
        --length;
    }

    Vector& operator+=(const Vector& other)
    {
        if (length + other.length > Capacity)
        {
            resize(length + other.length);
        }
        for (size_t i = 0; i < other.length; ++i)
        {
            ptr[length++] = other.ptr[i];
        }
        return *this;
    }

    Vector operator+(const Vector& right) const
    {
        Vector result = *this;
        result += right;
        return result;
    }

    T& operator[](size_t index)
    {
        if (index >= length)
        {
            throw VectorIndexError("Invalid element index.");
        }
        return ptr[index];
    }

    const T& operator[](size_t index) const
    {
        if (index >= length)
        {
            throw VectorIndexError("Invalid element index.");
        }
        return ptr[index];
    }

    bool empty() const
    {
        return length == 0;
    }

    void clear()
    {
        delete[] ptr;
        ptr = new T[Capacity];
        length = 0;
    }

    size_t size() const { return length; }
    size_t capacity() const { return Capacity; }

    void print() const
    {
        for (size_t i = 0; i < length; ++i)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~Vector()
    {
        delete[] ptr;
    }
};