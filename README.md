# Двусвязный-список 
## Методы

____

### push_back() - добавляет элемент в конец списка, сложность данного алгоритма o(1) - Если добавляемый элемент первый в списке то head и tail будут ссылться на первый элемент, иначе указатель (next) последнего узла(tail) будет ссылаться на новый узел, а указатель prev нового узла на узел tail, и в конце операцией присваивание tail передвигаем на новый узел, что бы tail обратно указывал на последний узел. В конце увеличиваем размер списка.
