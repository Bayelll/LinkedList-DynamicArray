#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class LinkedListIndexError : public exception
{
private:
    string error;

public:
    LinkedListIndexError(const string& error) : error(error) {}

    const char* what() const noexcept override
    {
        return error.c_str();
    }
};

template <typename T>
class Object
{
public:
    T data;
    shared_ptr<Object<T>> next;
    shared_ptr<Object<T>> prev;

    Object(T data) : data(data), next(nullptr), prev(nullptr) {}

    T get_data() const { return data; }
    shared_ptr<Object<T>> get_next() const { return next; }
    shared_ptr<Object<T>> get_prev() const { return prev; }
};

template <typename T>
class LinkedList
{
private:
    int size;

public:
    shared_ptr<Object<T>> head;
    shared_ptr<Object<T>> tail;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    shared_ptr<Object<T>> push_back(T data)
    {
        shared_ptr<Object<T>> obj = make_shared<Object<T>>(data);
        if (!head)
        {
            head = tail = obj;
        }
        else
        {
            tail->next = obj;
            obj->prev = tail;
            tail = obj;
        }
        size++;
        return obj;
    }

    shared_ptr<Object<T>> push_front(T data)
    {
        shared_ptr<Object<T>> obj = make_shared<Object<T>>(data);
        if (!head)
        {
            head = tail = obj;
        }
        else
        {
            head->prev = obj;
            obj->next = head;
            head = obj;
        }
        size++;
        return obj;
    }

    void pop_back()
    {
        if (!head) return;

        if (head->next == nullptr)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        size--;
    }

    void pop_front()
    {
        if (!head) return;

        if (head->next == nullptr)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        size--;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw LinkedListIndexError("Invalid element index.");
        }

        shared_ptr<Object<T>> obj = head;
        int n = 0;
        while (n != index)
        {
            obj = obj->next;
            n++;
        }

        if (obj == head)
        {
            pop_front();
            return;
        }

        if (obj == tail)
        {
            pop_back();
            return;
        }

        shared_ptr<Object<T>> left = obj->prev;
        shared_ptr<Object<T>> right = obj->next;

        left->next = right;
        right->prev = left;

        size--;
    }

    void insert(int index, T data)
    {
        if (index < 0 || index > size)
        {
            throw LinkedListIndexError("Invalid element index.");
        }

        if (index == 0)
        {
            push_front(data);
            return;
        }

        shared_ptr<Object<T>> obj = head;
        int n = 0;
        while (obj && n < index)
        {
            obj = obj->next;
            n++;
        }

        shared_ptr<Object<T>> newObj = make_shared<Object<T>>(data);
        newObj->prev = obj->prev;
        newObj->next = obj;

        if (obj->prev)
        {
            obj->prev->next = newObj;
        }

        obj->prev = newObj;
        size++;
    }

    int get_size() const { return size; }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw LinkedListIndexError("Invalid element index.");
        }

        shared_ptr<Object<T>> obj = head;
        int n = 0;
        while (n != index)
        {
            obj = obj->next;
            n++;
        }

        return obj->data;
    }

    shared_ptr<Object<T>> get_tail() const { return tail; }

    shared_ptr<Object<T>> get_head() const { return head; }
};