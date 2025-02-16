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


# Заключение

____

![Обьяснение] (https://www.google.com/search?client=ubuntu-sn&hs=gP5&sca_esv=1cdd3e2116a3bced&channel=fs&sxsrf=AHTn8zqD0N66yEjmfw4Fi65Hr_uqUfod0Q:1739717747791&q=%D0%B8%D1%82%D0%BE%D0%B3&udm=2&fbs=ABzOT_C00qMmca6NP6oNBSkAWbHahhle7N5JgRr9GCdnUIT_l3dBM-4uNWA2CgIQtnKBfOhYp-F1fIJylo8sfVXhJF2tq5LQO2TgM6w-cgt21B88lCFAc9Pe0VTtgsf86SPtmVkAw77FRU68I44jXK2QtiA6YS1_PuW-_fgsC-vrOlRLfHDKv3H33sJWZrTh2K7piamH_Ky4gLloetaDHhhbKC_2J8_Atw&sa=X&ved=2ahUKEwjShvfSuciLAxXaHxAIHcBxNWkQtKgLegQIHBAB&biw=1850&bih=968&dpr=1#vhid=cihAEWFp8yGhcM&vssid=mosaic)

