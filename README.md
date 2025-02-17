# Двусвязный-список - list
## Методы

____

+ PUSH_BACK() 
#### Добавляет элемент в конец списка, сложность данного алгоритма o(1) - Проверяем если добавляемый элемент первый в списке то head и tail будут ссылться на первый элемент, иначе указатель (next) последнего узла(tail) будет ссылаться на новый узел, а указатель prev нового узла на узел tail, и в конце операцией присваивания tail передвигаем на новый узел, что бы tail обратно указывал на последний узел. И в конце увеличиваем размер списка.

+ PUSH_FRONT()
#### Добавляет элемент на начало списка, сложность данного алгоритма o(1) -  Проверяем если добавляемый элемент первый в списке то head и tail будут ссылться на первый элемент, иначе указатель (prev) первого элемента будет ссылаться на новый узел, а указатель (next) нового узла на первый элемент, и в конце операцией присваивания head передвигаем на новый узел, что бы head обратно указывал на первый узел. И в конце увеличиваем размер списка.

+ INSERT()
#### Добавляет элемент в произвольное место списка, сложность такого алгоритма o(n) - потому что нужно искать (left, right) узлы а сама вставка o(1), перед тем как добавить новый элемент, необходимо проверить индекс под новым узлом, так что бы она была в диапазоне (> 0 && < size - 1), иначе делаем исключение. Если индекс допустим, проверяем что если индекс равен нулю, то вызваем метод PUSH_FRONT(), иначе создаем новый узел, указателю (prev) нового узла инициализируем left (prev), a указателю (next) нового узла инициализируем left.next. И в конце увеличиваем размер списка.

+ POP_PACK()
#### Удаляет последний элемент в двусвязном списке, сложность такого алгоритма o(1) - потому что каждый узел хранит указатель на предыдущий  узел, в отличии от односвязного где такая операция была бы со сложность o(n). Если список пуст то нечего удалять, если всего одни елемент то его и удаляем, иначе tail передвигаем на tail (prev) а tail (next) указываем на nullptr. И в конце уменьшаем размер списка.

+ POP_FRONT()
#### Удаляет первый элемент в в двусвязном списке, сложность такого алгоритма o(1) - Если список пуст то нечего удалять, если всего одни елемент то его и удаляем, иначе head передвигаем на head (next) а head (prev) указываем на nullptr. И в конце уменьшаем размер списка.

+ REMOVE()
#### Удаляет элемент в произвольное место списка, сложность такого алгоритма o(n) - потому что нужно искать (left, right) узлы а сама вставка o(1), перед тем как добавить новый элемент, необходимо проверить индекс под новым узлом, так что бы она была в диапазоне (> 0 && < size - 1), иначе делаем исключение. Если индекс допустим, проверяем что если индекс равен нулю, то вызваем метод POP_FRONT(), если удаляемый элемент последний вызываем метод POP_BACK(), иначе left(next) инициализируем right, а right(prev) инициализируем left. И в конце уменьшаем размер списка.

+ GET_SIZE
#### Возвращает количество узлов.

+ GET_TAIL()
#### Возвращает указатель на tail.

+ GET_HEAD()
#### Возвращает указатель на head.


# Динамический-массив - vector
## Методы

____

+ RESIZE()
#### Изменяет размер внутреннего массива, сложность данного алгоритма O(n) Создаёт новый массив с заданной ёмкостью newCapacity, копирует в него все элементы из старого массива, затем удаляет старый массив и обновляет указатель ptr, а также ёмкость Capacity.

+ PUSH_BACK()
#### Добавляет элемент в конец вектора, сложность O(1) (амортизированная)Если вектор заполнен, то увеличивает его размер вдвое (resize(Capacity * 2)) а сложность становится o(n). Добавляет новый элемент в конец массива и увеличивает length.

+ PUSH_FRONT()
#### Добавляет элемент в начало вектора, сложность O(n)Если вектор заполнен, увеличивает его размер вдвое.Сдвигает все элементы вправо на одну позицию, вставляет новый элемент в ptr[0] и увеличивает length.

+ INSERT()
#### Вставляет элемент по индексу, сложность O(n) Проверяет корректность индекса, при необходимости увеличивает размер массива. Сдвигает элементы вправо, вставляет новый элемент на указанное место и увеличивает length.

+ POP_PACK()
#### Удаляет последний элемент вектора, сложность O(1) Если вектор пуст, выбрасывает исключение.Уменьшает length на 1.

+ POP_FRONT()
#### Удаляет первый элемент вектора, сложность O(n) Если вектор пуст, выбрасывает исключение.Сдвигает все элементы влево, уменьшая length на 1.

+ REMOVE()
#### Удаляет элемент по индексу, сложность O(n) Проверяет корректность индекса. Сдвигает все элементы влево, уменьшая length.

# Usage

____

```
// Для динамического массива
int main()
{
  Vector <int> arr;

  return 0;
}
```

```
// Для двусвязного списка
int main()
{
  LinkedList <int> list;

  return 0;
}
```
## Usage Vector

```
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

int main()
{
  Vector <int> v; // Создаем динамический массив

  v.push_back(1); // Добавление элемента в конец

  v.pop_back(); // Удаляем элемент с конца

  v.print(); // Вывод всех элементов массива

  return 0;
}
```

#### Для использование классов необходимо в любой функции, обьявить обьект нужного класса, с определением типа в (<>) скобках. Так как классы реализованы на основе шаблонов, структуры данных могут хранить любые типы данных. 
____

# Заключение

____

#### В C++ большинство структур данных имеют схожие методы, однако суть структур данных заключается в способе хранения информации в памяти компьютера. Например, элементы списка могут находиться в разных ячейках памяти, тогда как в массиве все элементы расположены в непрерывной области. Представьте, что у вас есть задача: добавлять все новые данные в начало, а извлекать — с конца. Если использовать массив, то при заполнении всей доступной памяти (когда логический размер массива равен физическому) придется выделять новую область памяти, копировать туда все элементы (со сложностью O(n)), а затем сдвигать их вправо, чтобы вставить новый элемент под индексом 0. Разве это эффективно? Конечно, нет. Хотя компьютер — не живое существо, обработка таких операций может быть для него затратной. В такой ситуации список был бы более удобным решением. Однако у него тоже есть недостатки по сравнению с массивом. Например, для доступа к элементу в массиве можно использовать индексацию, что выполняется за O(1). В списке же индексация недоступна, поэтому, чтобы найти нужный узел, придется создать итератор, начать с головы списка и перебирать элементы, пока не будет найден нужный (со сложностью O(n)). В зависимости от поставленной задачи, программист сам должен выбирать более эффективный способ хранение данных в памяти компьютера!

